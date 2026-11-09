#pragma once

#include <iostream>
#include "../Registers.hpp"
#include "../Memory.hpp"
#include "../CPU.hpp"

Registers& registers = Registers::getInstance();
Memory& memory = Memory::getInstance();
CPU& cpu = CPU::getInstance();

//0x00
void NOP(){
    return;
}
//0x01
void LD_BC_NN(unsigned short operand) { registers.bc = operand;}

//0x02
void LD_BCP_A(void) { memory.writeByte(registers.bc, registers.a);}

//0x03
void INC_BC(void) { registers.bc++; }

//0x04
void INC_B(void) { registers.b++; }

//0x05
void DEC_B(void) { registers.b--; }

//0x06
void LD_B_N(unsigned char operand) { registers.b = operand; }

//0x07
void RLCA(void){
    unsigned char carry = (registers.a & 0x80) >> 7;
    if(carry) {
        registers.carry_turn_on();
    } else{
        registers.carry_turn_off();
    }

    registers.a <<=1;
    registers.a += carry;

    //registers.clear_flags();
}

//0x08
void LD_NNP_SP(unsigned short operand) {
    memory.writeShort(operand, registers.sp);
}

//0x09
void ADD_HL_BC(void){
    //add2()
    registers.hl = registers.hl + registers.bc;
}

//0x0A
void LD_A_BCP(void) {
    registers.a = memory.readByte(registers.bc);
}

//0x0B
void DEC_BC(void){
    registers.bc--;
}

//0x0C
void INC_C (void){
    //inc()
    registers.c++;
}

//0x0D
void DEC_C(void){
    //dec()
    registers.c--;
}

//0x0E
void LD_C_N(unsigned char operand){
    registers.c = operand;
}

//0x0F
void RRCA(void){
    unsigned char carry = (registers.a & 0x01);
    if(carry) {
        registers.carry_turn_on();
    } else{
        registers.carry_turn_off();
    }

    registers.a >>=1;
    if(carry){
        registers.a |= 0x80;
    }

    //registers.clear_flags();
    
}

//0x10
void STOP(void){
    cpu.stopped = true;
}

//0x11
void LD_DE_NN(unsigned short operand) {
    registers.de = operand;
}
//0x12
void LD_DEP_A(void){
    memory.writeShort(registers.de, registers.a);
}

//0x13
void INC_DE(void) {
    registers.de++;
}

//0x14
void INC_D(void){
    //inc();
    registers.d++;
}

//0x15
void DEC_D(void){
    //dec();
    registers.d--;
}

//0x16
void LD_D_N(unsigned char operand){
    registers.d = operand;
}

//0x17
void RLA(void){
    int carry = registers.get_carry();

    if(registers.a & 0b10000000){
        registers.carry_turn_on();
    } else {
        registers.carry_turn_off();
    }

    registers.a <<= 1;
    registers.a += carry;

    //registers.clear_flags();
}

//0x18
void JR_N(unsigned char operand){
    registers.pc += (signed char) operand;
    //debugJump();
}

//0x19
void ADD_HL_DE(void) {
    registers.hl += registers.de;
    //add2(&registers.hl, registers.de);
}

//0x1A
void LD_A_DEP(void) {
    registers.a = memory.readByte(registers.de);
}

//0x1B
void DEC_DE(void){
    registers.de--;
}

//0x1C
void INC_E(void) {
    registers.e++;
    //inc();
}

//0x1D
void DEC_E(void) {
    registers.e--;
    //dec();
}

//0x1E
void LD_E_N(unsigned char operand){
    registers.e = operand;
}

//0x1F
void RRA(void){
    int carry = registers.get_carry();
    if(registers.a & 0b00000001){
        registers.carry_turn_on();
    } else{
        registers.carry_turn_off();
    }

    registers.a >>= 1;
    registers.a += carry;

    //registers.clear_flags();
}

//0x20
void JR_NZ_N(unsigned char operand){
    if(registers.get_zero()){
        cpu.ticks_add(8);
    } else {
        registers.pc += (signed char)operand;

        cpu.ticks_add(12);
    }
}

//0x21
void LD_HL_NN(unsigned short operand) {
    registers.hl = operand;
}

//0x22
void LDI_HLP_A(void){
    memory.writeByte(registers.hl++, registers.a);
}

//0x23
void INC_HL(void){
    registers.hl++;
}

//0x24
void INC_H(void){
    registers.hl++;//inc
}


//0x25
void DEC_H(void){
    registers.hl--;//dec
}

//0x26
void LD_H_N(unsigned char operand){
    registers.h = operand;
}

//0x27
void DAA(void){
    unsigned short s = registers.a;

    if(registers.get_substraction()){
        if(registers.get_half_carry()){
            s = (s - 0x06)&0xFF;
        }

        if(registers.get_carry()){
            s -= 0x60;
        }
    } else {//todo check for stack overflow
        if(registers.get_half_carry() || (s & 0xF)>9){
            s += 0x06;
        }

        if(registers.get_carry() || s > 0x9F){
            s += 0x60;
        }
    }

    registers.a = s;
    registers.half_carry_turn_off();

    if(registers.a){
        registers.zero_turn_off();
    } else{
        registers.zero_turn_on();
    }

    if(s >= 0x100){
        registers.carry_turn_on();
    }
}

//0x28
void JR_Z_N(unsigned char operand){
    if(registers.get_zero()){
        registers.pc += (signed char) operand;

        cpu.ticks_add(12);
    } else{
        cpu.ticks_add(8);
    }
}

//0x29
void ADD_HL_HL(void){
    //add2(&registers.hl, registers.hl);
}

//0x2A
void LDI_A_HLP(void){
    registers.a = memory.readByte(registers.hl++);
}

//0x2B
void DEC_HL(void) {
    registers.hl--;
}

//0x2C
void INC_L(void){
    registers.l++;//inc()
}

//0x2D
void DEC_L(void){
    registers.l--;// dec() 
}

//0x2E
void LD_L_N(unsigned char operand){
    registers.l = operand;
}

//0x2F
void CPL(void){
    registers.a = ~registers.a;
    registers.half_carry_turn_on();
    registers.substraction_turn_on();
}