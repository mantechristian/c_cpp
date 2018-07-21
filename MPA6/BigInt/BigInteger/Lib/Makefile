all : libbigint.so copy link

libbigint.so : bigint.o
	g++ -shared -Wl,-soname,libbigint.so.1 -o libbigint.so.1.0 bigint.o

bigint.o :
	g++ -Wall -fPIC -c bigint.cpp

clean :
	rm -f *.o *.so.1.0 ../Test/*.so.1.0 ../Test/*.so ../Test/*.so.1 ../Test/bigint.h

copy :
	cp -f libbigint.so.1.0 bigint.h ../Test/

link :
	ln -sf ../Test/libbigint.so.1.0 ../Test/libbigint.so
	ln -sf ../Test/libbigint.so.1.0 ../Test/libbigint.so.1