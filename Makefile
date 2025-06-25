BIN=bin
TARGET=GAMELIFE
OPTIMIZATION=-std=c++11 -static -pthread -s -O3


.PHONY: all build-linux build-win32 build-win64


all: clean build-linux

build-linux: bin/
	g++ main.cpp $(OPTIMIZATION) -DLINUX -o bin/$(TARGET)

build-win64: bin/
	x86_64-w64-mingw32-g++ main.cpp $(OPTIMIZATION) -o $(BIN)/$(TARGET)-64.exe

build-win32: bin/
	i686-w64-mingw32-g++ main.cpp $(OPTIMIZATION) -o  $(BIN)/$(TARGET)-32.exe

clean: bin/
	rm -rf bin/*


bin/:
	mkdir bin