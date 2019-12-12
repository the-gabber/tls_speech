include ../Makefile

all: clean main

clean:
	rm -f main *.o *.so *.dylib *.asm

main.o: main.cpp
	$(CC) -c ${CXXFLAGS} $< -o $@

mod.o: mod.cpp
	$(CC) -c ${CXXFLAGS} $< -o $@

main: main.o mod.o
	$(CC)  $(BIN_LDFLAGS) -o $@ $^
	objdump -S $@ >main.asm
