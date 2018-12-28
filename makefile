EXEC= lecture test_lecture

all: $(EXEC) 

lecture : lecture_bmp.cpp
	g++ -Wall -o lecture lecture_bmp.cpp

test_lecture : test.cpp
	g++ -Wall -o test_lecture test.cpp

clean:
	rm -rf *.o *~

vclean:
	rm -rf $(EXEC)
