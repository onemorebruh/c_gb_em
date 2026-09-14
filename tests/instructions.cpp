#include "../registers.h"
#include "../instructions_lib.c"
#include <iostream>
//init registers
using namespace std;

struct registers registers_test;


//run each inctruction

int main(){
    char l = 'a';
    char r = 'b';
    LD(&l, &r);
}