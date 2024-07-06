bin/cjis64-asm: bin/main.o
	mkdir -p bin/
	gcc -o bin/cjis64-asm bin/main.o

bin/main.o: src/main.c
	mkdir -p bin/
	gcc -o bin/main.o -c src/main.c

.PHONY: run
run: bin/cjis64-asm
	./bin/cjis64-asm

.PHONY: clean
clean:
	rm -rf bin/
