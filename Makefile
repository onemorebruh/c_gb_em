test:
	g++ -o tests_registers ./tests/registers.cpp 
	./tests_registers
	g++ -o tests_memory ./tests/memory.cpp
	./tests_memory
	g++ -o tests_instructions ./tests/instructions.cpp
	./tests_instructions