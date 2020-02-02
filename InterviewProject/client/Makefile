SRC:=$(wildcard *.c)
test:$(SRC)
	gcc $^ -o $@ -lcrypt -lssl -lcrypto -pthread
clean:
	rm test

