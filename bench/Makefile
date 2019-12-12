include ../Makefile

CXXFLAGS_BENCH+= $(shell pkg-config --cflags benchmark)
CXXFLAGS+=$(CXXFLAGS_BENCH)
CXXFLAGS+= -march=native
LDFLAGS_BENCH+= $(shell pkg-config --libs benchmark)
BIN_LDFLAGS+= $(LDFLAGS_BENCH) -lpthread

all: clean bench

clean:
	rm -f bench *.o *.so *.dylib *.asm perf.data*

libdso.$(DSO_EXT): dso.cpp
	$(CC) --shared -fpic ${CXXFLAGS} $(LDFLAGS_BENCH) dso.cpp -o libdso.$(DSO_EXT)
	objdump -S $@ >dso.asm

bench.o: bench.cpp
	$(CC) -c ${CXXFLAGS} bench.cpp -o bench.o

bench: libdso.$(DSO_EXT) bench.o
	$(CC)  bench.o -L. -Wl,-rpath,. -ldso $(BIN_LDFLAGS) -o bench
	objdump -S $@ >main.asm
