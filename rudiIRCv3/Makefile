all:
	# mkdir -p .groups
	mkdir -p .msg
	mkdir -p .keys
	# mkdir -p .files/naman .files/u3 .files/u2 .files/root .files/u1 .files/bu	 
	# mkdir -p Downloads/naman Downloads/u3 Downloads/u2 Downloads/root Downloads/u1 Downloads/bu	 
	touch .logged_in
	gcc server.c -o server -lm -w -lpthread -lcrypto -g
	# gcc server.c -o server -lm -lpthread -lcrypto -g
	gcc client.c -o client -lm -w -lpthread -lcrypto -g
	# gcc client.c -o client -lm -lpthread -lcrypto -g

clean:
	rm client server
