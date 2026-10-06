#pragma once

class Memory{
	public:

        writeByte(unsigned short address, unsigned char value){
            if((0xA000 < address)&&(address < 0xBFFF)){
                //sram
            } else if ((0x8000 < address)&&(address < 0x9FFF)){
                //vram
            } else if ((0xC000 < address)&&(address < 0xDFFF)){
                //wram
            } else if ((0xE000 < address)&&(address < 0xFDFF)){
                //wram mirror
            } else if ((0xFE00 < address)&&(address < 0xFEFF)){
                //oam
            } else if ((0xFF80 < address)&&(address < 0xFFFE)){
                //hram
            } else if ((0xFF40 == address)){
                //GPU controll
            } else if ((0xFF42 == address)){
                //GPU scroll Y
            } else if ((0xFF43 == address)){
                //GPU scroll X
            } else if ((0xFF46 == address)){
                //OAM DMA
            } else if ((0xFF47 == address)){
                //background palette
            } else if ((0xFF48 == address)){
                //sprite palette 0
            } else if ((0xFF49 == address)){
                //sprite palette 1
            } else if ((0xFF00 < address)&&(address < 0xFF7F)){
                //I/O
            } else if ((0xFF0F == address)){
                //interrupt flags
            } else if ((0xFFFF == address)){
                //interrupt emable
            }
	private:
		Memory() {};
		Memory(const Memory&) = delete;
		Memory& operator=(const Memory&) = delete;
} ;