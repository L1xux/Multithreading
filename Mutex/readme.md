## Description

This repository contains two multithreaded programs demonstrating the use of mutexes in C.

1. **`mutex_example_with_mutex.c`**: This program uses mutexes to synchronize access to an array shared by multiple threads.
2. **`mutex_example_without_mutex.c`**: This program does not use mutexes, leading to potential race conditions when accessing a shared array.

## Compiling and Running the Programs
### Step 1: Compile the Programs
1. Open a terminal and navigate to the directory where the `compile.sh` script is located.
2. Run the following command to compile the programs:
   ```sh
   sh compile.sh
   ```

This will compile the programs and generate two executable files: `mutex_example_with_mutex.exe` and `mutex_example_without_mutex.exe`.

### Step 2: Run the Programs
1. Once the compilation is complete, run the following command to execute the program:

To run the program which mutex:
```sh
    ./mutex_example_with_mutex.exe
```

To run the program without mutex:
```sh 
    ./mutex_example_without_mutex.exe
```



