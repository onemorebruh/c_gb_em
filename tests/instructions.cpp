#include "../Registers.hpp"
#include "../lib/Instructions_lib.c"
#include <iostream>
//init registers
using namespace std;



//run each inctruction

int main(){

    //init registers
    Registers& registers_test = Registers::getInstance(); 
    Memory& memory_test = Memory::getInstance();

    cout<<"INSTRUCTIONS"<<endl;

    cout<<"LD_BC_NN:   ";
    registers_test.bc = 0x00;
    LD_BC_NN(0x01);//changed value of bc
    if(registers_test.bc == 0x01){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

    cout<<"LD_BCP_A:   ";
    registers_test.bc = 0xA001;
    registers_test.a = 0xFF;
    LD_BCP_A();
    if(memory_test.readByte(registers_test.bc) == registers_test.a){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }


    cout<<"INC_BC:     ";
    registers_test.bc = 0x00;
    INC_BC();
    if(registers_test.bc == 0x01){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

    

    cout<<"INC_B:      ";
    registers_test.b = 0x0;
    INC_B();
    if(registers_test.b == 0x1){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

    

    cout<<"DEC_B:      ";
    registers_test.b = 0x1;
    DEC_B();
    if(registers_test.b == 0x0){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

    

    cout<<"LD_B_N:     ";
    registers_test.b = 0x0;
    LD_B_N(0x1);
    if(registers_test.b == 0x1){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }



    cout << "RLCA" << endl;//NOTE possible bug here

    cout << "BIG VALUE:     ";
    registers_test.a = 0b10010110;
    registers_test.flags = 0x00;
    RLCA();
    if (registers_test.a == 0b00101101) {
        if(!(registers_test.flags ^ 0b00000000)){
            cout << "PASSED" << endl;   
        } else {
            cout<<"FAILED"<<endl;
            cout<<"flags have not been cleared"<<endl;
        }
    } else {
        cout << "FAILED" << endl;
        cout<<" value have not been rotated successfully";
    }


    cout << "SMALL VALUE:   ";
    registers_test.a = 0b00110110;
    registers_test.flags = 0x00;
    RLCA();
    if (registers_test.a == 0b01101100){
        if(!(registers_test.flags ^ 0b00000000)){
            cout << "PASSED" << endl;   
        } else {
            cout<<"FAILED"<<endl;
            cout<<"flags have not been cleared"<<endl;
        }
    } else {
        cout << "FAILED" << endl;
        cout<<" value have not been rotated successfully";
    }

    cout << "LD_NNP_SP:   ";
    registers_test.sp = 0xAFFF;
    LD_NNP_SP(0xFF);
    if(memory_test.readByte(registers_test.sp) == 0xFF){
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "ADD_HL_BC:  ";
    registers_test.hl = 0x1000;
    registers_test.bc = 0x0100;
    ADD_HL_BC();
    if(registers_test.hl == 0x1100){
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }


    cout << "LD_A_BCP:   ";
    registers_test.bc = 0xA001;
    registers_test.a = 0xFF;
    LD_BCP_A();
    registers_test.a = 0x00;
    LD_A_BCP();
    if(registers_test.a == 0xFF){
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }


    cout << "DEC_BC:     ";
    registers_test.bc = 0x0001;
    DEC_BC();
    if(registers_test.bc == 0x0000){
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }


    cout << "INC_C:      ";
    registers_test.c = 0x00;
    INC_C();
    if(registers_test.c == 0x01){
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }


    cout << "DEC_C:      ";
    registers_test.c = 0x01;
    DEC_C();
    if(registers_test.c == 0x00){
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }


    cout << "LD_C_N:     ";
    registers_test.c = 0x00;
    LD_C_N(0x42);
    if(registers_test.c == 0x42){
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }


    cout << "RRCA" << endl;
    cout << "BIG VALUE:  ";
    registers_test.a = 0b10010110;
    registers_test.flags = 0x00;
    RRCA();
    if(registers_test.a == 0b01001011){
        if(registers_test.flags == 0x00){
            cout << "PASSED" << endl;
        } else {
            cout << "FAILED" << endl;
            cout << "flags have not been cleared" << endl;
        }
    } else {
        cout << "FAILED" << endl;
        cout << "value have not been rotated successfully" << endl;
    }


    cout << "SMALL VALUE:";
    registers_test.a = 0b00110110;
    registers_test.flags = 0x00;
    RRCA();
    if(registers_test.a == 0b00011011){
        if(registers_test.flags == 0x00){
            cout << "PASSED" << endl;
        } else {
            cout << "FAILED" << endl;
            cout << "flags have not been cleared" << endl;
        }
    } else {
        cout << "FAILED" << endl;
        cout << "value have not been rotated successfully" << endl;
    }


    cout << "RRCA CARRY: ";
    registers_test.a = 0b00000001;
    registers_test.flags = 0x00;
    RRCA();
    if(registers_test.a == 0b10000000){
        if(registers_test.flags == 0x00){
            cout << "PASSED" << endl;
        } else {
            cout << "FAILED" << endl;
            cout << "flags have not been cleared" << endl;
        }
    } else {
        cout << "FAILED" << endl;
        cout << "carry bit was not rotated to bit 7" << endl;
    }
}