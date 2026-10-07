#include "../Memory.hpp"
#include "../Registers.hpp"
#include <iostream>
//init registers
using namespace std;



//run each inctruction

int main(){

    //init 
    Memory& memory_test = Memory::getInstance();

    
    cout<<"MEMORY"<<endl;
    
    cout<<"SRAM:        ";
    memory_test.writeByte(0xA001, 0xFF);
    if(memory_test.readByte(0xA001) == 0xFF){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

    
    cout<<"VRAM:        ";
    memory_test.writeByte(0x8001, 0xFF);
    if(memory_test.readByte(0x8001) == 0xFF){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

    
    cout<<"WRAM:        ";
    memory_test.writeByte(0xC001, 0xFF);
    if(memory_test.readByte(0xC001) == 0xFF){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }

    
    cout<<"WRAM MIRROR: ";
    memory_test.writeByte(0xE001, 0xFF);
    if(memory_test.readByte(0xE001) == 0xFF){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }
     
    
    cout<<"OAM:         ";
    memory_test.writeByte(0xFE01, 0xFF);
    if(memory_test.readByte(0xFE01) == 0xFF){
        cout<<"PASSED"<<endl;
    } else{
        cout<<"FAILED"<<endl;
    }
}