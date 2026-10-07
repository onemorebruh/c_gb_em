#pragma once

class Memory{
	private:
		Memory() {};
		Memory(const Memory&) = delete;
		Memory& operator=(const Memory&) = delete;

        unsigned char cart[0x8000];
        unsigned char sram[0x2000];
        unsigned char io[0x100];
        unsigned char vram[0x2000];
        unsigned char oam[0x100];
        unsigned char wram[0x2000];
        unsigned char hram[0x80];

	public:

    
		static Memory& getInstance(){
			static Memory instance; // Создается один раз при первом вызове
        	return instance;
		};

        void writeByte(unsigned short address, unsigned char value){
            if((0xA000 < address)&&(address < 0xBFFF)){
                //sram
                this->sram[address - 0xA000] = value;

            } else if ((0x8000 < address)&&(address < 0x9FFF)){
                //vram
                this->vram[address - 0x8000] = value;
                if(address <= 0x97FF){
                    //updateTile(address, value); TODO implement
                }

            } else if ((0xC000 < address)&&(address < 0xDFFF)){
                //wram
                this->wram[address - 0xC000] = value;

            } else if ((0xE000 < address)&&(address < 0xFDFF)){
                //wram mirror
                this->wram[address - 0xE000] = value;

            } else if ((0xFE00 < address)&&(address < 0xFEFF)){
                //oam
                this->oam[address - 0xFE00] = value;

            } else if ((0xFF80 < address)&&(address < 0xFFFE)){
                //hram
                this->hram[address - 0xFF80] = value;

            } else if ((0xFF40 == address)){
                //GPU controll
                //TODO implement
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
        }

        unsigned char readByte(unsigned short address){

            if(address <= 0x7FFF){
                //cart
                return this->cart[address];

            } else if((0xA000 < address)&&(address < 0xBFFF)){
                //sram
                return this->sram[address - 0xA000];

            } else if ((0x8000 < address)&&(address < 0x9FFF)){
                //vram
                return this->vram[address - 0x8000];

            } else if ((0xC000 < address)&&(address < 0xDFFF)){
                //wram
                return this->wram[address - 0xC000];

            } else if ((0xE000 < address)&&(address < 0xFDFF)){
                //wram mirror
                return this->wram[address - 0xE000];

            } else if ((0xFE00 < address)&&(address < 0xFEFF)){
                //oam
                return this->oam[address - 0xFE00];

            } else if ((0xFF80 < address)&&(address < 0xFFFE)){
                //hram
                return this->hram[address - 0xFF80];
            } else if ((0xFF00 < address)&&(address < 0xFF7f)){
                //i/o
                return this->io[address - 0xff00];
            }
            
            return 0;
        }

        
        void writeShort(unsigned short address, unsigned short value) {
            this->writeByte(address, (unsigned char)(value & 0x00ff));
            this->writeByte(address + 1, (unsigned char)((value & 0xff00) >> 8));
        }
} ;