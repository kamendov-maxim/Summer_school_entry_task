PROGRAM_NAME = bmp_header_reader

$(PROGRAM_NAME): main.c
	gcc main.c -o $(PROGRAM_NAME)

cross-build: main.c
	riscv64-linux-gnu-gcc -static main.c -o $(PROGRAM_NAME)
