hs:=$(wildcard *.c)

wow:=$(patsubst %.c,%.o,$(hs) )
CC:=gcc
CFLAGS:=-g
m:=main
$(m):$(wow)
	gcc $(wow) -o $@
clean:
	rm -rf $(wow) $(m)



