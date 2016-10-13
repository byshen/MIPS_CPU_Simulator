all:
	make -C build
cmake:
	cd build; cmake ..; cd ..
clean:
	make -C build clean
