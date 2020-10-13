map: 
	g++ -c Terminal.h Terminal.cpp
	g++ -c Player.h Player.cpp
	g++ -c Block.h Block.cpp
	g++ -c Rack.h Rack.cpp
	g++ -c menu.cpp
	g++ -c map.cpp
	g++ -c Product.h Product.cpp
	g++ -o main Terminal.o Player.o Block.o Rack.o Product.o menu.o map.o -lncurses
	
test: Terminal.h Terminal.cpp test.cpp
	g++ -o test Terminal.h Terminal.cpp test.cpp -lncurses
	./test
	clear