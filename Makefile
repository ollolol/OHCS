CC=g++
STD=-std=c++14
main: OCSS.o argv.o main.o bigint.o
	${CC} ${STD} -o ohcs main/argv.o main/OCSS.o main/main.o \
bigint/BigIntegerAlgorithms.o \
bigint/BigInteger.o \
bigint/BigIntegerUtils.o \
bigint/BigUnsignedInABase.o \
bigint/BigUnsigned.o  -lm
clean:
	rm -f main/argv.o main/main.o ./ohcs  main/OCSS.o
	./compile/cleanBigint.sh
OCSS.o:
	${CC} ${STD} -c -o main/OCSS.o main/OCSS.cpp
argv.o:
	${CC} ${STD} -c -o main/argv.o main/argv.cpp
main.o:
	${CC} ${STD} -c -o main/main.o main/main.cpp
bigint.o:
	./compile/compileBigint.sh
