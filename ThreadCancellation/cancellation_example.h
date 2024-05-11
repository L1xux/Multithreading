#include <pthread.h>

typedef struct  {
    int id;
    pthread_t thread;
    int cancel_state;
    int cancel_type; 
} thread_t;

thread_t *thread_create(thread_t *thread, int id);

void memory_cleanup_handler(void *arg);
void file_cleanup_handler(void *arg);
void *write_into_file(void *arg);