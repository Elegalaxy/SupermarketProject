main: Terminal.h Player.h menu.cpp map.cpp
	g++ -o main Terminal.h Player.h menu.cpp map.cpp -lncurses
	./main
	
test: Product.h test.cpp
	g++ -o test Product.h test.cpp -lncurses
	./test