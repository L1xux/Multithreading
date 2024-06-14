/*
 * ===================================================================================== 
 *
 *    Description: This program creates two threads: one continuously sums an array's elements 
 *                 and another swaps its first and last elements. A third thread prints the array 
 *                 periodically. All threads use a mutex to synchronize access to the array.
 *
 *        Created:  2024.06.14
 *       Compiler:  gcc
 *
 *         Author:  Ui Jin Lee, mr938363@gmail.com
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>


pthread_mutex_t mutex;
int nums[] = { 1, 2, 3, 4, 5 };

void print_nums() {
    int size = sizeof(nums) / sizeof(nums[0]);
    
    
    pthread_mutex_lock(&mutex); 
    printf("nums = ");
    for(int i = 0 ; i < size ; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex); 
}

static void* thread_cb_sum(){
    int size = sizeof(nums) / sizeof(nums[0]);

    while(1){
        int sum = 0;

        pthread_mutex_lock(&mutex); 
        for(int i = 0 ; i < size ; i++){
            sum+=nums[i];
        }
        pthread_mutex_unlock(&mutex);
    }    
}

static void* thread_cb_swap() {
    int size = sizeof(nums) / sizeof(nums[0]);

    while(1){
        pthread_mutex_lock(&mutex);

        int temp = nums[size-1];
        nums[size-1] = nums[0];
        nums[0] = temp;

        pthread_mutex_unlock(&mutex);
    }
}


int main(int argc, char** argv){
    pthread_mutex_init(&mutex, NULL);
    
    pthread_t t_sum;
    pthread_t t_swap;

    pthread_attr_t attr_sum;
    pthread_attr_init(&attr_sum);

    pthread_attr_setdetachstate(&attr_sum, PTHREAD_CREATE_DETACHED);
    //pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    int rc_sum = pthread_create(&t_sum, &attr_sum, thread_cb_sum, NULL);

    if(rc_sum != 0){
        printf("Error occurred for sum\n");
        return 0;
    }


    int rc_swap = pthread_create(&t_swap, NULL, thread_cb_swap, NULL);
    if(rc_swap != 0){
        printf("Error occuered for swap\n");
        return 0;
    }

    while(1){
        print_nums(); 
        sleep(1); 
    }

    return 0;
}


