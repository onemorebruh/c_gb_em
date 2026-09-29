#pragma once

#include <iostream>
#include "../Registers.hpp"


Registers& registers = Registers::getInstance();

//0x00
void NOP(){
    return;
}
//0x01
void LD_BC_NN(unsigned short operand) { registers.bc = operand;}

//0x02
void LD_BCP_A(void) { registers.bc = registers.a;}

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

    registers.clear_flags();
}