#include "../Registers.hpp"
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
    if(!(registers_test.flags ^ 0b00010000)){
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

    if (!(registers_test.flags ^ 0b01000000)) {
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

    if (!(registers_test.flags ^ 0b00100000)) {
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

    if (!(registers_test.flags ^ 0b10000000)) {
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
}