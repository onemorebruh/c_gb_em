//#include "Registers.h";
#include "Instructions_map.c"
#include "lib/Enum_Instructions.c"

class CPU{

    public:
        void exec(Instructions Instruction){
         
        }
        void step(){
            //read by pc value;
            //interprete it as an innstruction
            this->exec();
            //update pc value
        }
}