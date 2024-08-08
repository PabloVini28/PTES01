CHAIN=$(CHAINPATH)arm-none-eabi
CFLAGS=-mcpu=cortex-a8 -mfpu=vfp -mfloat-abi=softfp
AFLAGS=-mfpu=neon -mcpu=cortex-a8
IPATH=-Iinc/
SRC=src/
OBJ=obj/
BIN=bin/
TFTPBOOT=/tftpboot/

all: app

app: start.o main.o pad.o
	$(CHAIN)-ld $(OBJ)start.o $(OBJ)main.o $(OBJ)pad.o -T $(SRC)memmap.ld -o $(OBJ)main.elf
	$(CHAIN)-objcopy $(OBJ)main.elf $(BIN)spl.boot -O binary
	cp $(BIN)spl.boot $(TFTPBOOT)app.bin

start.o: $(SRC)start.s
	$(CHAIN)-as $(AFLAGS) $(SRC)start.s -o $(OBJ)start.o

main.o: $(SRC)main.c
	$(CHAIN)-gcc $(CFLAGS) $(IPATH) -c $(SRC)main.c -o $(OBJ)main.o

pad.o: $(SRC)pad.c
	$(CHAIN)-gcc $(CFLAGS) $(IPATH) -c $(SRC)pad.c -o $(OBJ)pad.o
                                         
copy:
	cp $(BIN)spl.boot $(TFTPBOOT)app.bin

link:
	ln -f $(TFTPBOOT)app.bin $(TFTPBOOT)download.bin

clean:
	rm -rf $(OBJ)*.o
	rm -rf $(OBJ)*.elf
	rm -rf $(BIN)*.boot
	rm $(TFTPBOOT)download.bin
	rm $(TFTPBOOT)app.bin

dump:
	$(CHAIN)-objdump -D $(OBJ)main.elf
