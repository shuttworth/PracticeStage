cc:=g++
OBJS1:=tcp_client.cc 
OBJS2:=TestConnection.cc

# all:client server

client:$(OBJS1)
	$(cc) $^ -o $@

# server:$(OBJS2)
# 	$(cc) $^ -o $@

clean:
	rm -rf client server
