cc:=g++
OBJS1:=myTcp_client.cc 
OBJS2:=myTcp_server.cc

all:client server

client:$(OBJS1)
	$(cc) $^ -o $@

server:$(OBJS2)
	$(cc) $^ -o $@

clean:
	rm -rf client server
