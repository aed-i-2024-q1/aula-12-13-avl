CC = gcc -Wall -pedantic

build_dir:
	mkdir -p build

element: build_dir
	$(CC) -c -o build/element.o element.c

avl: element
	$(CC) -c -o build/avl.o avl.c

main: avl
	$(CC) -o build/main main.c build/avl.o build/element.o

clean:
	rm -rf build