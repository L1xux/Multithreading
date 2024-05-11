/*
 * ===================================================================================== 
 *
 *    Description: This program creates five threads, each writing its ID and a message to a unique file in an 
 *                 infinite loop. it sends a specific cancellation request to the specific thread identified by the number 
 *                 provided by a user.
 *   
 *        Created:  2024.05.11
 *       Compiler:  gcc
 *
 *         Author:  Ui Jin Lee, mr938363@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include "cancellation_example.h"

#define N_THREADS 5


thread_t* thread_create(thread_t* thread, int id){
    if(!thread){
        thread = calloc(1, sizeof(thread_t));
    }

    thread->id = id;
    thread->cancel_state = PTHREAD_CANCEL_ENABLE;
    thread->cancel_type = PTHREAD_CANCEL_ASYNCHRONOUS;


    return thread;
}

void memory_cleanup_handler(void *arg) {
    free(arg);
}


void file_cleanup_handler(void *arg) {
    FILE* ptr = (FILE*)arg;
    fclose(ptr);
}


void *write_into_file(void *arg) {
    thread_t* thread = (thread_t *)arg;
    char file_name[64];
    
    sprintf(file_name, "thread_%d.txt", thread->id);
    FILE *fptr = fopen(file_name, "w");
    
    if(!fptr) {
       printf("Error opening file. Error NUM: %d\n", errno); 
       return 0;
    }

    // cleanup functions will be stored in a stack.
    pthread_cleanup_push(memory_cleanup_handler, arg);
    pthread_cleanup_push(file_cleanup_handler, fptr);
    
    int cnt = 0;
    char input_text[64];
    
    while(1) {        
        
        pthread_setcancelstate(thread->cancel_state, NULL);
        pthread_setcanceltype(thread->cancel_type, NULL);

        int len = sprintf(input_text, "%d: I'm a (%d) thread\n", cnt, thread->id);

        fwrite(input_text, sizeof(char), len, fptr);
        fflush(fptr);
        
        cnt++;
        
        sleep(1);
        pthread_testcancel(); 
        
    }    

    pthread_cleanup_pop(0); 
    pthread_cleanup_pop(0);

    return 0;
}

int main(int argc, char **argv){
    int i;

    thread_t* threads[N_THREADS];
    
    for( i = 0; i < N_THREADS; i++){
        threads[i] = thread_create(0, i);
        pthread_create(&threads[i]->thread, 0, write_into_file, threads[i]);
    }
    
    int thread_num, option;

    while(1) {   
        printf("Enter a type of cancellation (0: async, 1: deffered)\nChoose: ");
        scanf("%d", &option);
        
        printf("Enter slave thread id [0-%d] :", N_THREADS - 1);
        scanf("%d", &thread_num);
        
        if(thread_num < 0 || thread_num >= N_THREADS) {
            printf("Invalid Thread id\n");
            exit(0);
        }

        switch(option){
            case 0:
                pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
                pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
                break;
            case 1:
                pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
                pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
                break;
            default:
                printf("Invalid Operation ID\n");
                exit(0);
        }
        
        pthread_cancel(threads[thread_num]->thread);
    }

    return 0;
}




