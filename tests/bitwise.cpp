#include "../lib/bitwise.c"
#include <iostream>
//init registers
using namespace std;



//run each inctruction

int main(){

    
    cout<<"BITWISE"<<endl;

    cout<<"get 0x01: ";
    if(get_bit_via_mask(0b00000001, 0b00000001)){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

    
    cout<<"get 0xF0: ";
    if(get_bit_via_mask(0b10000001, 0b10000000)){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

}