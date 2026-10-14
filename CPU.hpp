#pragma once

class CPU {
    public:
		static CPU& getInstance(){
			static CPU instance; // Создается один раз при первом вызове
        	return instance;
		};

        bool stopped = false;
    
	private:
		CPU() {};
		CPU(const CPU&) = delete;
		CPU& operator=(const CPU&) = delete;
};