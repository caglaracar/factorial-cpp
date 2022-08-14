all:derle bagla calistir
derle:
	g++  -c -I "./include" ./src/ArrayList.cpp -o ./lib/ArrayList.o
	g++  -c -I "./include" ./src/factorial.cpp -o ./lib/factorial.o
	g++  -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++  ./lib/ArrayList.o ./lib/factorial.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program	 