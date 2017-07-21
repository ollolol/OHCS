main: main/argv.o main/main.o
	gcc -o ohcs main/argv.o main/main.o -lm
