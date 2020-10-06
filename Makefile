main: Terminal.h Draw.h Player.h menu.cpp map.cpp
	g++ -o main Terminal.h Draw.h Player.h menu.cpp map.cpp -lncurses
	./main
	clear
	
test: Terminal.h Draw.h Player.h test.cpp
	g++ -o test Terminal.h Draw.h Player.h test.cpp -lncurses
	./test
	clear