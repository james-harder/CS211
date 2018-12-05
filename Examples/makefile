# [OUTPUT] : [FILES NEEDED]
# 		[STEPS TO MAKE OUTPUT]

classy : moneyExample.cpp Money.o
	g++ -Wall -o classy moneyExample.cpp Money.o

Money.o : Money.hpp Money.cpp
	g++ -Wall -c Money.cpp

clean :
	rm -f *.o classy