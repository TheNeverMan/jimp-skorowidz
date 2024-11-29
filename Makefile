all: main.c ./data/stack.c ./print/print.c ./read/read.c ./search/search.c
	gcc -ansi -pedantic -Wall -o skorowidz main.c ./data/stack.c ./print/print.c ./read/read.c ./search/search.c
clean:
	rm -f skorowidz
	rm -f skorowidz-test
	rm -f ./test/skorowidz-test
skorowidz-test: ./test/test.c
	gcc -ansi -pedantic -Wall -o ./test/skorowidz-test ./data/stack.c ./print/print.c ./read/read.c ./search/search.c ./test/test.c
