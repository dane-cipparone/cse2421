# Author: Sean O'Donnell

all: lab3

lab3: lab3main.o parser.o prompter.o addBook.o avgProfit.o inStock.o investment.o outStock.o profit.o removeBook.o revenue.o sales.o wholesaleCost.o
	gcc lab3main.o parser.o prompter.o addBook.o avgProfit.o inStock.o investment.o outStock.o profit.o removeBook.o revenue.o sales.o wholesaleCost.o -o lab3

lab3main.o: lab3main.c lab3.h
	gcc -ansi -pedantic -g -c lab3main.c

parser.o: parser.c lab3.h
	gcc -ansi -pedantic -g -c parser.c

prompter.o: prompter.c lab3.h
	gcc -ansi -pedantic -g -c prompter.c

addBook.o: addBook.c lab3.h
	gcc -ansi -pedantic -g -c addBook.c

avgProfit.o: avgProfit.c lab3.h
	gcc -ansi -pedantic -g -c avgProfit.c

inStock.o: inStock.c lab3.h
	gcc -ansi -pedantic -g -c inStock.c

investment.o: investment.c lab3.h
	gcc -ansi -pedantic -g -c investment.c

outStock.o: outStock.c lab3.h
	gcc -ansi -pedantic -g -c outStock.c

profit.o: profit.c lab3.h
	gcc -ansi -pedantic -g -c profit.c

removeBook.o: removeBook.c lab3.h
	gcc -ansi -pedantic -g -c removeBook.c

revenue.o: revenue.c lab3.h
	gcc -ansi -pedantic -g -c revenue.c

sales.o: sales.c lab3.h
	gcc -ansi -pedantic -g -c sales.c

wholesaleCost.o: wholesaleCost.c lab3.h
	gcc -ansi -pedantic -g -c wholesaleCost.c

clean:
	rm -rf *.o lab3
