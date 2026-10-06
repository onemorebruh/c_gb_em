#pragma once

#define FLAG_CARRY 			0b00010000;
#define FLAG_HALF_CARRY 	0b00100000;
#define FLAG_SUBSTRACTION 	0b01000000;
#define FLAG_ZERO			0b10000000;

class Registers{
	public:

		struct {
			union {
				struct {
					unsigned char a;
					unsigned char f;
				};
				unsigned short af;
			};
		};

		struct {
			union {
				struct {
					unsigned char b;
					unsigned char c;
				};
				unsigned short bc;
			};
		};

		struct {
			union {
				struct {
					unsigned char d;
					unsigned char e;
				};
				unsigned short de;
			};
		};

		struct {
			union {
				struct {
					unsigned char h;
					unsigned char l;
				};
				unsigned short hl;
			};
		};
		//bit 7: zero
		//bit 6: substraction
		//bit 5: half carry
		//bit 4: carry
		unsigned char flags;
		unsigned short sp;
		unsigned short pc;

		

		static Registers& getInstance(){
			static Registers instance; // Создается один раз при первом вызове
        	return instance;
		};

		void carry_turn_on(){
			this->flags |= FLAG_CARRY;
			return;
		}
		void carry_turn_off(){
			this->flags &= ~FLAG_CARRY;//NOTE ~
			return;
		}
		void half_carry_turn_on(){
			this->flags |= FLAG_HALF_CARRY;
			return;
		}
		void half_carry_turn_off(){
			this->flags &= ~FLAG_HALF_CARRY;
			return;
		}
		void substraction_turn_on(){
			this->flags |= FLAG_SUBSTRACTION;
			return;
		}
		void substraction_turn_off(){
			this->flags &= ~FLAG_SUBSTRACTION;
			return;
		}
		void zero_turn_on(){
			this->flags |= FLAG_ZERO;
			return;
		}
		void zero_turn_off(){
			this->flags &= ~FLAG_ZERO;
			return;
		}
		void clear_flags(){
			this->flags = 0;
			return;
		}

	private:
		Registers() {};
		Registers(const Registers&) = delete;
		Registers& operator=(const Registers&) = delete;
} ;