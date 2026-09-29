#include "../Registers.hpp"
#include "../lib/Instructions_lib.c"
#include <iostream>
//init registers
using namespace std;



//run each inctruction

int main(){

    //init registers
    Registers& registers_test = Registers::getInstance();
    
    cout<<"FLAGS"<<endl;

    cout<<"FLAG_CARRY"<<endl;
    cout<<"TURN ON:    ";
    registers_test.flags = 0x0;
    registers_test.carry_turn_on();
    if(registers_test.flags ^ 0b00010000){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

    cout<<"TURN OFF:   ";
    registers_test.flags = 0x0;
    registers_test.carry_turn_off();
    if(registers_test.flags ^ 0b00000000){
        cout<<"FAILED"<<endl;
    } else{
        cout<<"PASSED"<<endl;
    }

    cout << "FLAG_SUBTRACTION" << endl;
    cout << "TURN ON:    ";
    registers_test.flags = 0x0;
    registers_test.substraction_turn_on();

    if (registers_test.flags ^ 0b01000000) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "TURN OFF:   ";
    registers_test.flags = 0x0;
    registers_test.substraction_turn_off();

    if (registers_test.flags ^ 0b00000000) {
        cout << "FAILED" << endl;
    } else {
        cout << "PASSED" << endl;
    }


    cout << "FLAG_HALFCARRY" << endl;

    cout << "TURN ON:    ";
    registers_test.flags = 0x0;
    registers_test.half_carry_turn_on();

    if (registers_test.flags ^ 0b00100000) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "TURN OFF:   ";
    registers_test.flags = 0x0;
    registers_test.half_carry_turn_off();

    if (registers_test.flags ^ 0b00000000) {
        cout << "FAILED" << endl;
    } else {
        cout << "PASSED" << endl;
    }


    cout << "FLAG_ZERO" << endl;

    cout << "TURN ON:    ";
    registers_test.flags = 0x0;
    registers_test.zero_turn_on();

    if (registers_test.flags ^ 0b10000000) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "TURN OFF:   ";
    registers_test.flags = 0x0;
    registers_test.zero_turn_off();

    if (registers_test.flags ^ 0b00000000) {
        cout << "FAILED" << endl;
    } else {
        cout << "PASSED" << endl;
    }

    cout << "CLEAR ALL:  ";
    registers_test.flags = 0b11110000;
    registers_test.clear_flags();

    if (registers_test.flags ^ 0b00000000) {
        cout << "FAILED" << endl;
    } else {
        cout << "PASSED" << endl;
    }    

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
    registers_test.bc = 0x00;
    registers_test.a = 0x1;
    LD_BCP_A();
    if(registers_test.bc == registers_test.a){
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
    if(registers_test.bc == 0x0){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

    

    cout<<"LD_B_N:     ";
    registers_test.bc = 0x0;
    LD_B_N(0x1);
    if(registers_test.bc == 0x1){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }



    cout << "RLCA" << endl;

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
}