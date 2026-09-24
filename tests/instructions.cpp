#include "../Registers.hpp"
#include "../lib/Instructions_lib.c"
#include <iostream>
//init registers
using namespace std;



//run each inctruction

int main(){
    //init registers
    Registers& registers_test = Registers::getInstance();

    cout<<"LD_BC_NN: ";
    registers_test.bc = 0x00;
    LD_BC_NN(0x01);//changed value of bc
    if(registers_test.bc == 0x01){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

    cout<<"LD_BCP_A: ";
    registers_test.bc = 0x00;
    registers_test.a = 0x1;
    LD_BCP_A();
    if(registers_test.bc == registers_test.a){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

}