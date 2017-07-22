CC=gcc
main: main/argv.o main/main.o main/bigunsigned.o
        ${CC} -o ohcs main/argv.o main/bigunsigned.o main/main.o -lm
clean:
        rm -f main/argv.o main/main.o main/bigunsigned.o ./ohcs
