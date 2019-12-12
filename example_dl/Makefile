include ../Makefile

all: clean main

clean:
	rm -f ex_dl *.o *.so *.dylib *.asm

main.o: main.cpp
	$(CC) -c ${CXXFLAGS} $< -o $@

dso.o: dso.cpp
	$(CC) -fpic -c ${CXXFLAGS} $< -o $@

libdso.$(DSO_EXT): dso.o
	$(CC) --shared -fpic $(LDFLAGS) $< -o libdso.$(DSO_EXT)
	objdump -S $@ >dso.asm

main: main.o libdso.$(DSO_EXT)
	$(CC)  $(BIN_LDFLAGS) -o $@ $< -rdynamic -ldl
	objdump -S $@ >bin.asm
