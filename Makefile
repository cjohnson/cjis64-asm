main: bin/main.o
	mkdir -p bin/
	gcc -o bin/cjis64-asm bin/main.o

bin/main.o: src/main.c
	mkdir -p bin/
	gcc -o bin/main.o -c src/main.c

.PHONY: clean
clean:
	rm -rf bin/
