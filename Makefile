all: 
	gcc bpwsgen.c -o bpwsgen
	./bpwsgen

clean: 
	rm bpwsgen
