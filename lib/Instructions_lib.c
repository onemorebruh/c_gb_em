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