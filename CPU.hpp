#pragma once

class CPU {
	private:
		CPU() {};
		CPU(const CPU&) = delete;
		CPU& operator=(const CPU&) = delete;

		unsigned long ticks = 0;

    public:
		static CPU& getInstance(){
			static CPU instance; // Создается один раз при первом вызове
        	return instance;
		};

        bool stopped = false;

		unsigned long ticks_get(){
			return this->ticks;
		}

		//modify existing value
		void ticks_add(char operand){
			this->ticks += operand;
		}

		//force set value
		void ticks_set(unsigned long value){
			this->ticks = value;
		}

    
};