driver : driver.cpp stackmachine.cpp instr.cpp stackmachine.h instr.h
	g++ -o $@ -O2 -g $^