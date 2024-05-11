rm *.o
rm *exe
gcc -g -c cancellation_example.c -o cancellation_example.o
gcc -g cancellation_example.o -o cancellation_example.exe -lpthread