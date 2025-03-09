all:
	g++ main.cpp -std=c++11 -static -pthread -s -O3 -DLINUX -o bin/GAMELIFE
	chmod +x bin/GAMELIFE

win64:
	x86_64-w64-mingw32-g++ main.cpp -std=c++11 -static -pthread -s -O3 -o bin/GAMELIFE-64.exe

win32:
	i686-w64-mingw32-g++ main.cpp -std=c++11 -static -pthread -s -o -O3 bin/GAMELIFE-32.exe

clean:
	rm -f GAMELIFE
	rm -f GAMELIFE-32.exe
	rm -f GAMELIFE-64.exe