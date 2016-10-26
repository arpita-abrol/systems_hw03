all:
	gcc randfile.c -o randfile

run: randfile
	./randfile

clean:
	rm *~
