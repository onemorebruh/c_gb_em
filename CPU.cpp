#include "Registers.h";
#include "Instructions_map.c"
#include "lib/Enum_Instructions.c"

class CPU{
    registers registers;

    public:
        exec(Instructions Instruction){
            switch (Instruction)
            {
            case Instructions::ADD:
                switch (target)
                {
                case ArithmeticTarget::C:
                    this->registers.a = this->registers.a + this->registers.c;
                    break;
                
                default:
                    break;
                }
                break;
            
            default:
                break;
            }
            //todo check for flags
        }

}