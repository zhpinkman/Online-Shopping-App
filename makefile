



build/user.o: src/user.hpp src/user.cpp
	g++ -c -o build/user.o src/user.cpp






clean: clear directory


clear: 
	rm -rf build/*.o


directory:
	mkdir -p build