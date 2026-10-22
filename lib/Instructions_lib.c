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

//0x0a
void LD_A_BCP(void) {
    registers.a = memory.readByte(registers.bc);
}

//0x0b
void DEC_BC(void){
    registers.bc--;
}

//0x0c
void INC_C (void){
    //inc()
    registers.c++;
}

//0x0d
void DEC_C(void){
    //dec()
    registers.c--;
}

//0x0e
void LD_C_N(unsigned char operand){
    registers.c = operand;
}

//0x0f
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

//0x1a
void LD_A_DEP(void) {
    registers.a = memory.readByte(registers.de);
}

//0x1b
void DEC_DE(void){
    registers.de--;
}

//0x1c
void INC_E(void) {
    registers.e++;
    //inc();
}

//0x1d
void DEC_E(void) {
    registers.e--;
    //dec();
}

//0x1e
void LD_E_N(unsigned char operand){
    registers.e = operand;
}

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