CHAIN=arm-none-eabi
CFLAGS=-std=c99 -Wall
IPATH=-Iinc/
SRC=src/
OBJ=obj/
BIN=bin/

all: app

app: start.o main.o 
	$(CHAIN)-ld $(OBJ)start.o $(OBJ)main.o -T $(SRC)memmap.ld -o $(OBJ)main.elf
	$(CHAIN)-objcopy $(OBJ)main.elf $(BIN)spl.boot -O binary
	cp $(BIN)spl.boot /tftpboot/app.bin

start.o: $(SRC)start.s
	$(CHAIN)-as $(IPATH) $(SRC)start.s -o $(OBJ)start.o

main.o: $(SRC)main.c
	$(CHAIN)-gcc $(CFLAGS) $(IPATH) -c $(SRC)main.c -o $(OBJ)main.o
                                        
copy:
	cp $(BIN)spl.boot /tftpboot/app.bin

clean:
	rm -rf $(OBJ)*.o
	rm -rf $(OBJ)*.elf
	rm -rf $(BIN)*.boot

dump:
	$(CHAIN)-objdump -D $(OBJ)main.elf
