all: mklab3

mklab3: lab3main.o parser.o prompter.o addBook.o avgProfit.o inStock.o investment.o outStock.o profit.o removeBook.o revenue.o sales.o wholesaleCost.o
	gcc lab3main.o parser.o prompter.o addBook.o avgProfit.o inStock.o investment.o outStock.o profit.o removeBook.o revenue.o sales.o wholesaleCost.o -o mklab3

lab3main.o: lab3main.c lab3.h
	gcc -ansi -pedantic -c lab3main.c

parser.o: parser.c lab3.h
	gcc -ansi -pedantic -c parser.c

prompter.o: prompter.c lab3.h
	gcc -ansi -pedantic -c prompter.c

addBook.o: addBook.c lab3.h
	gcc -ansi -pedantic -c addBook.c

avgProfit.o: avgProfit.c lab3.h
	gcc -ansi -pedantic -c avgProfit.c

inStock.o: inStock.c lab3.h
	gcc -ansi -pedantic -c inStock.c

investment.o: investment.c lab3.h
	gcc -ansi -pedantic -c investment.c

outStock.o: outStock.c lab3.h
	gcc -ansi -pedantic -c outStock.c

profile.o: profile.c lab3.h
	gcc -ansi -pedantic -c profile.c

removeBook.o: removeBook.c lab3.h
	gcc -ansi -pedantic -c removeBook.c

revenue.o: revenue.c lab3.h
	gcc -ansi -pedantic -c revenue.c

sales.o: sales.c lab3.h
	gcc -ansi -pedantic -c sales.c

wholesaleCost.o: wholesaleCost.c lab3.h
	gcc -ansi -pedantic -c wholesaleCost.c

clean:
	rm -rf *.o mklab3
