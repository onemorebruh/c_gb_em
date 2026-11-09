#include "../Registers.hpp"
#include "../CPU.hpp"
#include "../Memory.hpp"
#include "../lib/Instructions_lib.c"
#include <iostream>
//init registers
using namespace std;



//run each inctruction

int main(){

    //init registers
    Registers& registers_test = Registers::getInstance(); 
    Memory& memory_test = Memory::getInstance();
    CPU& cpu_test = CPU::getInstance();

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
        cout << "PASSED" << endl;  
    } else {
        cout << "FAILED" << endl;
        cout<<" value have not been rotated successfully";
    }


    cout << "SMALL VALUE:   ";
    registers_test.a = 0b00110110;
    registers_test.flags = 0x00;
    RLCA();
    if (registers_test.a == 0b01101100){
        cout << "PASSED" << endl;   
    } else {
        cout << "FAILED" << endl;
        cout<<" value have not been rotated successfully";
    }

    cout << "LD_NNP_SP:   ";
    registers_test.sp = 0xAFFF;
    LD_NNP_SP(0xAFFF);
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
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        cout << "value have not been rotated successfully" << endl;
    }


    cout << "SMALL VALUE:";
    registers_test.a = 0b00110110;
    registers_test.flags = 0x00;
    RRCA();
    if(registers_test.a == 0b00011011){
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        cout << "value have not been rotated successfully" << endl;
    }


    cout << "RRCA CARRY: ";
    registers_test.a = 0b00000001;
    registers_test.flags = 0x00;
    RRCA();
    if(registers_test.a == 0b10000000){
            cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        cout << "carry bit was not rotated to bit 7" << endl;
    }

    cout << "STOP:       ";
    cpu_test.stopped = false;
    STOP();
    if (cpu_test.stopped == true) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }


    cout << "LD_DE_NN:   ";
    registers_test.de = 0x0000;
    LD_DE_NN(0x1234);
    if (registers_test.de == 0x1234) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }


    cout << "LD_DEP_A:   ";
    registers_test.de = 0xA001;
    registers_test.a = 0xFF;
    LD_DEP_A();
    if (memory_test.readByte(registers_test.de) == registers_test.a) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }


    cout << "INC_DE:     ";
    registers_test.de = 0x0000;
    INC_DE();
    if (registers_test.de == 0x0001) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }


    cout << "INC_D:      ";
    registers_test.d = 0x00;
    INC_D();
    if (registers_test.d == 0x01) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }


    cout << "DEC_D:      ";
    registers_test.d = 0x01;
    DEC_D();
    if (registers_test.d == 0x00) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }


    cout << "LD_D_N:     ";
    registers_test.d = 0x00;
    LD_D_N(0x42);
    if (registers_test.d == 0x42) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "RLA:        ";
    registers_test.a = 0x80;
    registers_test.carry_turn_off();
    RLA();
    if (registers_test.a == 0x00 ) {
        if(registers_test.get_carry() == 1){
            cout << "PASSED" << endl;
        } else{
            cout << "FAILED" << endl;
            cout << "wrong carry" << endl;

        }

    } else {
        cout << "FAILED" << endl;
        cout << "wrong rotation" << endl;
    }

    cout << "RLA (carry):";
    registers_test.a = 0x00;
    registers_test.carry_turn_on();
    RLA();
    if (registers_test.a == 0x01 && registers_test.get_carry() == 0) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "JR_N (+):   ";
    registers_test.pc = 0x0100;
    JR_N(0x05);
    if (registers_test.pc == 0x0105) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "JR_N (-):   ";
    registers_test.pc = 0x0100;
    JR_N(0xFC); // -4 as signed char
    if (registers_test.pc == 0x00FC) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "ADD_HL_DE:  ";
    registers_test.hl = 0x1000;
    registers_test.de = 0x0100;
    ADD_HL_DE();
    if (registers_test.hl == 0x1100) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "LD_A_DEP:   ";
    registers_test.de = 0xA001;
    memory_test.writeByte(0xA001, 0x42);
    registers_test.a = 0x00;
    LD_A_DEP();
    if (registers_test.a == 0x42) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED";
    }

    cout << "DEC_DE:     ";
    registers_test.de = 0x0001;
    DEC_DE();
    if (registers_test.de == 0x0000) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "DEC_DE (0): ";
    registers_test.de = 0x0000;
    DEC_DE();
    if (registers_test.de == 0xFFFF) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "INC_E:      ";
    registers_test.e = 0x0F;
    INC_E();
    if (registers_test.e == 0x10) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "INC_E (FF): ";
    registers_test.e = 0xFF;
    INC_E();
    if (registers_test.e == 0x00) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "DEC_E:      ";
    registers_test.e = 0x01;
    DEC_E();
    if (registers_test.e == 0x00) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "DEC_E (0):  ";
    registers_test.e = 0x00;
    DEC_E();
    if (registers_test.e == 0xFF) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "LD_E_N:     ";
    registers_test.e = 0x00;
    LD_E_N(0x42);
    if (registers_test.e == 0x42) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }

    cout << "RRA (big):  ";
    registers_test.a = 0b10010110;
    registers_test.flags = 0x00;
    RRA();
    if (registers_test.a == 0b01001011) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        cout << "value have not been rotated successfully" << endl;
    }

    cout << "RRA (small):";
    registers_test.a = 0b00000001;
    registers_test.flags = 0x00;
    RRA();
    if (registers_test.a == 0b00000000) {
        if (registers_test.get_carry() == 1){
            cout << "PASSED" << endl;
        }
    } else {
        cout << "FAILED" << endl;
        cout << "value have not been rotated successfully" << endl;
    }

    cout << "JR_NZ_N (not taken):  ";
    registers_test.pc = 0x0100;
    registers_test.flags = 0x80;        // Z=1
    cpu_test.ticks_set(0);
    JR_NZ_N(0x05);
    if (registers_test.pc == 0x0100 && cpu_test.ticks_get() == 8) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (pc=0x" << hex << registers_test.pc 
            << ", ticks=" << dec << cpu_test.ticks_get() << ")" << endl;
    }

    // Переход выполняется вперёд (Z=0, +5): PC += 5, ticks += 12
    cout << "JR_NZ_N (taken +):    ";
    registers_test.pc = 0x0100;
    registers_test.flags = 0x00;        // Z=0
    cpu_test.ticks_set(0);
    JR_NZ_N(0x05);
    if (registers_test.pc == 0x0105 && cpu_test.ticks_get() == 12) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (pc=0x" << hex << registers_test.pc 
            << ", ticks=" << dec << cpu_test.ticks_get() << ")" << endl;
    }

    // Переход выполняется назад (Z=0, -4): PC -= 4
    cout << "JR_NZ_N (taken -):    ";
    registers_test.pc = 0x0100;
    registers_test.flags = 0x00;
    cpu_test.ticks_set(0);
    JR_NZ_N(0xFC);                      // -4 как signed char
    if (registers_test.pc == 0x00FC && cpu_test.ticks_get() == 12) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (pc=0x" << hex << registers_test.pc << ")" << endl;
    }

    cout << "LD_HL_NN:             ";
    registers_test.hl = 0x0000;
    LD_HL_NN(0x1234);
    if (registers_test.hl == 0x1234) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (hl=0x" << hex << registers_test.hl << ")" << endl;
    }

    // Пишет A по адресу HL и увеличивает HL
    cout << "LDI_HLP_A:            ";
    registers_test.hl = 0xC000;
    registers_test.a = 0x42;
    LDI_HLP_A();
    if (memory_test.readByte(0xC000) == 0x42 && registers_test.hl == 0xC001) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (mem=0x" << hex << (int)memory_test.readByte(0xC000)
            << ", hl=0x" << registers_test.hl << ")" << endl;
    }

    cout << "INC_HL:               ";
    registers_test.hl = 0x1234;
    INC_HL();
    if (registers_test.hl == 0x1235) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (hl=0x" << hex << registers_test.hl << ")" << endl;
    }

    // Проверка переполнения: 0xFFFF → 0x0000
    cout << "INC_HL (wrap):        ";
    registers_test.hl = 0xFFFF;
    INC_HL();
    if (registers_test.hl == 0x0000) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (hl=0x" << hex << registers_test.hl << ")" << endl;
    }

    cout << "INC_H (spec):         ";
    registers_test.hl = 0x1200;
    registers_test.flags = 0x00;
    INC_H();
    if (registers_test.h == 0x13 && registers_test.l == 0x00) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        cout << "  Expected H=0x13, L=0x00. Got H=0x" << hex << (int)registers_test.h
            << " L=0x" << (int)registers_test.l << endl;
        cout << "  BUG: INC_H increments HL pair instead of just H register" << endl;
    }

    cout << "DEC_H (spec):         ";
    registers_test.hl = 0x1200;
    registers_test.flags = 0x00;
    DEC_H();
    if (registers_test.h == 0x11 && registers_test.l == 0x00) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        cout << "  Expected H=0x11, L=0x00. Got H=0x" << hex << (int)registers_test.h
            << " L=0x" << (int)registers_test.l << endl;
        cout << "  BUG: DEC_H decrements HL pair instead of just H register" << endl;
    }

    cout << "LD_H_N:               ";
    registers_test.h = 0x00;
    LD_H_N(0x42);
    if (registers_test.h == 0x42) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (h=0x" << hex << (int)registers_test.h << ")" << endl;
    }

    // ---------- 0x27 DAA ----------
    // Кейс 1: A=0x45 (валидный BCD, флаги чистые) → без изменений
    cout << "DAA (no change):      ";
    registers_test.a = 0x45;
    registers_test.flags = 0x00;
    DAA();
    if (registers_test.a == 0x45) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (a=0x" << hex << (int)registers_test.a << ")" << endl;
    }

    // Кейс 2: A=0x1A, младшая тетрада > 9 → +0x06 → 0x20
    cout << "DAA (low nibble>9):   ";
    registers_test.a = 0x1A;
    registers_test.flags = 0x00;
    DAA();
    if (registers_test.a == 0x20) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (a=0x" << hex << (int)registers_test.a << ")" << endl;
    }

    // Кейс 3: A=0x11, half-carry=1 (после 0x08+0x09) → +0x06 → 0x17 (BCD 8+9=17)
    cout << "DAA (half-carry):     ";
    registers_test.a = 0x11;
    registers_test.flags = 0x00;
    registers_test.half_carry_turn_on();
    DAA();
    if (registers_test.a == 0x17) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (a=0x" << hex << (int)registers_test.a << ")" << endl;
    }

    // Кейс 4: A=0x9A → +6 = 0xA0 → +0x60 = 0x100 → A=0x00, C=1, Z=1
    cout << "DAA (overflow):       ";
    registers_test.a = 0x9A;
    registers_test.flags = 0x00;
    DAA();
    if (registers_test.a == 0x00 
        && registers_test.get_carry() == 1 
        && registers_test.get_zero()  == 1) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (a=0x" << hex << (int)registers_test.a
            << ", C=" << (int)registers_test.get_carry()
            << ", Z=" << (int)registers_test.get_zero() << ")" << endl;
    }

    // Кейс 5: вычитание с half-carry: A=0x1F, sub=1, hc=1 → 0x1F - 0x06 = 0x19 (BCD 20-1)
    cout << "DAA (sub half-carry): ";
    registers_test.a = 0x1F;
    registers_test.flags = 0x00;
    registers_test.substraction_turn_on();
    registers_test.half_carry_turn_on();
    DAA();
    if (registers_test.a == 0x19) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (a=0x" << hex << (int)registers_test.a << ")" << endl;
    }

    // Кейс 6: вычитание без borrow: A=0x09, sub=1, hc=0, c=0 → без изменений
    cout << "DAA (sub no change):  ";
    registers_test.a = 0x09;
    registers_test.flags = 0x00;
    registers_test.substraction_turn_on();
    DAA();
    if (registers_test.a == 0x09) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (a=0x" << hex << (int)registers_test.a << ")" << endl;
    }

        // ============================================================
    //  ТЕСТЫ ДЛЯ 0x28–0x2F
    // ============================================================

    // ---------- 0x28 JR_Z_N ----------
    // Переход НЕ выполняется (Z=0): PC не меняется, ticks += 8
    cout << "JR_Z_N (not taken):   ";
    registers_test.pc = 0x0100;
    registers_test.flags = 0x00;        // Z=0
    cpu_test.ticks_set(0);
    JR_Z_N(0x05);
    if (registers_test.pc == 0x0100 && cpu_test.ticks_get() == 8) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (pc=0x" << hex << registers_test.pc
             << ", ticks=" << dec << cpu_test.ticks_get() << ")" << endl;
    }

    // Переход выполняется вперёд (Z=1, +5): PC += 5, ticks += 12
    cout << "JR_Z_N (taken +):     ";
    registers_test.pc = 0x0100;
    registers_test.flags = 0x00;
    registers_test.zero_turn_on();      // Z=1
    cpu_test.ticks_set(0);
    JR_Z_N(0x05);
    if (registers_test.pc == 0x0105 && cpu_test.ticks_get() == 12) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (pc=0x" << hex << registers_test.pc
             << ", ticks=" << dec << cpu_test.ticks_get() << ")" << endl;
    }

    // Переход выполняется назад (Z=1, -4): PC -= 4
    cout << "JR_Z_N (taken -):     ";
    registers_test.pc = 0x0100;
    registers_test.flags = 0x00;
    registers_test.zero_turn_on();
    cpu_test.ticks_set(0);
    JR_Z_N(0xFC);                       // -4 как signed char
    if (registers_test.pc == 0x00FC && cpu_test.ticks_get() == 12) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (pc=0x" << hex << registers_test.pc << ")" << endl;
    }

    // ---------- 0x29 ADD_HL_HL ----------
    // HL = HL + HL; проверяем и флаг carry при переполнении
    cout << "ADD_HL_HL:            ";
    registers_test.hl = 0x1234;
    registers_test.flags = 0x00;
    ADD_HL_HL();
    if (registers_test.hl == 0x2468 && registers_test.get_carry() == 0) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (hl=0x" << hex << registers_test.hl
             << ", C=" << (int)registers_test.get_carry() << ")" << endl;
    }

    // Переполнение: 0x8000 + 0x8000 = 0x10000 → HL=0x0000, C=1
    cout << "ADD_HL_HL (overflow): ";
    registers_test.hl = 0x8000;
    registers_test.flags = 0x00;
    ADD_HL_HL();
    if (registers_test.hl == 0x0000 && registers_test.get_carry() == 1) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (hl=0x" << hex << registers_test.hl
             << ", C=" << (int)registers_test.get_carry() << ")" << endl;
    }

    // ---------- 0x2A LDI_A_HLP ----------
    // A = [HL], HL++
    cout << "LDI_A_HLP:            ";
    registers_test.hl = 0xC000;
    memory_test.writeByte(0xC000, 0x5A);
    registers_test.a = 0x00;
    LDI_A_HLP();
    if (registers_test.a == 0x5A && registers_test.hl == 0xC001) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (a=0x" << hex << (int)registers_test.a
             << ", hl=0x" << registers_test.hl << ")" << endl;
    }

    // ---------- 0x2B DEC_HL ----------
    cout << "DEC_HL:               ";
    registers_test.hl = 0x1234;
    DEC_HL();
    if (registers_test.hl == 0x1233) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (hl=0x" << hex << registers_test.hl << ")" << endl;
    }

    // Переполнение вниз: 0x0000 → 0xFFFF
    cout << "DEC_HL (wrap):        ";
    registers_test.hl = 0x0000;
    DEC_HL();
    if (registers_test.hl == 0xFFFF) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (hl=0x" << hex << registers_test.hl << ")" << endl;
    }

    // ---------- 0x2C INC_L (⚠️ СОДЕРЖИТ БАГ) ----------
    // По спецификации: L = L + 1, обновляются флаги Z/H/N.
    // В текущем коде: registers.l++ — флаги НЕ обновляются!
    cout << "INC_L (value):        ";
    registers_test.l = 0x12;
    INC_L();
    if (registers_test.l == 0x13) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (l=0x" << hex << (int)registers_test.l << ")" << endl;
    }

    // Проверка флага Z: 0xFF + 1 = 0x00 → Z=1
    cout << "INC_L (Z flag):       ";
    registers_test.l = 0xFF;
    registers_test.flags = 0x00;
    INC_L();
    if (registers_test.l == 0x00 && registers_test.get_zero() == 1) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (l=0x" << hex << (int)registers_test.l
             << ", Z=" << (int)registers_test.get_zero() << ")" << endl;
        cout << "  BUG: INC_L doesn't update flags (Z should be 1)" << endl;
    }

    // Проверка флага H: 0x0F + 1 = 0x10 → H=1
    cout << "INC_L (H flag):       ";
    registers_test.l = 0x0F;
    registers_test.flags = 0x00;
    INC_L();
    if (registers_test.l == 0x10 && registers_test.get_half_carry() == 1) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (l=0x" << hex << (int)registers_test.l
             << ", H=" << (int)registers_test.get_half_carry() << ")" << endl;
        cout << "  BUG: INC_L doesn't update flags (H should be 1)" << endl;
    }

    // Проверка флага N: после INC N должен быть 0 (сбрасываться)
    cout << "INC_L (N flag):       ";
    registers_test.l = 0x12;
    registers_test.flags = 0x00;
    registers_test.substraction_turn_on();  // ставим N=1
    INC_L();
    if (registers_test.get_substraction() == 0) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (N=" << (int)registers_test.get_substraction() << ")" << endl;
        cout << "  BUG: INC_L doesn't clear N flag" << endl;
    }

    // ---------- 0x2D DEC_L (⚠️ СОДЕРЖИТ БАГ) ----------
    // По спецификации: L = L - 1, обновляются флаги Z/H/N.
    // В текущем коде: registers.l-- — флаги НЕ обновляются!
    cout << "DEC_L (value):        ";
    registers_test.l = 0x12;
    DEC_L();
    if (registers_test.l == 0x11) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (l=0x" << hex << (int)registers_test.l << ")" << endl;
    }

    // Проверка флага Z: 0x01 - 1 = 0x00 → Z=1
    cout << "DEC_L (Z flag):       ";
    registers_test.l = 0x01;
    registers_test.flags = 0x00;
    DEC_L();
    if (registers_test.l == 0x00 && registers_test.get_zero() == 1) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (l=0x" << hex << (int)registers_test.l
             << ", Z=" << (int)registers_test.get_zero() << ")" << endl;
        cout << "  BUG: DEC_L doesn't update flags (Z should be 1)" << endl;
    }

    // Проверка флага H: 0x10 - 1 = 0x0F → H=1 (заимствование из младшей тетрады)
    cout << "DEC_L (H flag):       ";
    registers_test.l = 0x10;
    registers_test.flags = 0x00;
    DEC_L();
    if (registers_test.l == 0x0F && registers_test.get_half_carry() == 1) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (l=0x" << hex << (int)registers_test.l
             << ", H=" << (int)registers_test.get_half_carry() << ")" << endl;
        cout << "  BUG: DEC_L doesn't update flags (H should be 1)" << endl;
    }

    // Проверка флага N: после DEC N должен быть 1
    cout << "DEC_L (N flag):       ";
    registers_test.l = 0x12;
    registers_test.flags = 0x00;
    DEC_L();
    if (registers_test.get_substraction() == 1) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (N=" << (int)registers_test.get_substraction() << ")" << endl;
        cout << "  BUG: DEC_L doesn't set N flag" << endl;
    }

    // Переполнение вниз: 0x00 - 1 = 0xFF
    cout << "DEC_L (wrap):         ";
    registers_test.l = 0x00;
    registers_test.flags = 0x00;
    DEC_L();
    if (registers_test.l == 0xFF) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (l=0x" << hex << (int)registers_test.l << ")" << endl;
    }

    // ---------- 0x2E LD_L_N ----------
    cout << "LD_L_N:               ";
    registers_test.l = 0x00;
    LD_L_N(0x42);
    if (registers_test.l == 0x42) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (l=0x" << hex << (int)registers_test.l << ")" << endl;
    }

    // ---------- 0x2F CPL (⚠️ СОДЕРЖИТ БАГИ) ----------
    // По спецификации: A = ~A; N=1, H=1; Z НЕ МЕНЯЕТСЯ.
    // В текущем коде: zero_turn_on без скобок (возможно, макрос),
    // и Z устанавливается, хотя не должен.
    cout << "CPL (invert):         ";
    registers_test.a = 0xAA;
    registers_test.flags = 0x00;
    CPL();
    if (registers_test.a == 0x55) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (a=0x" << hex << (int)registers_test.a << ")" << endl;
    }

    // Проверка N=1 и H=1
    cout << "CPL (N,H flags):      ";
    registers_test.a = 0x00;
    registers_test.flags = 0x00;
    CPL();
    if (registers_test.get_substraction() == 1
        && registers_test.get_half_carry() == 1) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (N=" << (int)registers_test.get_substraction()
             << ", H=" << (int)registers_test.get_half_carry() << ")" << endl;
        cout << "  BUG: CPL must set N=1 and H=1" << endl;
    }

    // Проверка: Z НЕ должен меняться (был 0 — остался 0)
    cout << "CPL (Z unchanged 0):  ";
    registers_test.a = 0x00;
    registers_test.flags = 0x00;        // Z=0
    CPL();
    if (registers_test.get_zero() == 0) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (Z=" << (int)registers_test.get_zero() << ")" << endl;
        cout << "  BUG: CPL must NOT modify Z flag (was 0, should stay 0)" << endl;
    }

    // Проверка: Z НЕ должен меняться (был 1 — остался 1)
    cout << "CPL (Z unchanged 1):  ";
    registers_test.a = 0xFF;
    registers_test.flags = 0x00;
    registers_test.zero_turn_on();      // Z=1
    CPL();
    if (registers_test.a == 0x00 && registers_test.get_zero() == 1) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED (a=0x" << hex << (int)registers_test.a
             << ", Z=" << (int)registers_test.get_zero() << ")" << endl;
        cout << "  BUG: CPL must NOT modify Z flag (was 1, should stay 1)" << endl;
    }
}

