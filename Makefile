map: 
	g++ -c Terminal.h Terminal.cpp
	g++ -c Player.h Player.cpp
	g++ -c Product.h Product.cpp
	g++ -c Block.h Block.cpp
	g++ -c Rack.h Rack.cpp
	g++ -c Bin.h Bin.cpp
	g++ -c menu.cpp
	g++ -c map.cpp
	g++ -o main Terminal.o Player.o Product.o Block.o Rack.o Bin.o menu.o map.o -lncurses
	
test: Terminal.h Terminal.cpp test.cpp
	g++ -o test Terminal.h Terminal.cpp test.cpp -lncurses
	./test
	clear
	
test2: Terminal.h Terminal.cpp Player.h Player.cpp Product.h Product.cpp Block.h Block.cpp Rack.h Rack.cpp test2.cpp
	g++ -o test Terminal.h Terminal.cpp Player.h Player.cpp Product.h Product.cpp Block.h Block.cpp Rack.h Rack.cpp test2.cpp -lncurses
	./test
	clear