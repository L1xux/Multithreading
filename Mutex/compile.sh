rm *exe

gcc -g -c mutex_example_without_mutex.c -o mutex_example_without_mutex.o
gcc -g mutex_example_without_mutex.o -o mutex_example_without_mutex.exe -lpthread

gcc -g -c mutex_example_with_mutex.c -o mutex_example_with_mutex.o
gcc -g mutex_example_with_mutex.o -o mutex_example_with_mutex.exe -lpthread

rm *o