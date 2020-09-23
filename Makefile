test: Terminal.h Player.h menu.cpp map.cpp
	g++ -o test Terminal.h Player.h menu.cpp map.cpp -lncurses
	./test