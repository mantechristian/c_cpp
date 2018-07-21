all : libMake testMake
	cp -f ./Test/test .

libMake :
	make -C ./Lib

testMake :
	make -C ./Test

clean : testClean libClean
	rm -f test

libClean : 
	make -C ./Lib clean

testClean :
	make -C ./Test clean