#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Function prototypes
void *thread_function1(void *args);
void *thread_function2(void *args);

int main() {
    pthread_t a_thread1; // Declare thread 1
    pthread_t a_thread2; // Declare thread 2

    // Create thread 1
    pthread_create(&a_thread1, NULL, &thread_function1, NULL);
    
    // Create thread 2
    pthread_create(&a_thread2, NULL, &thread_function2, NULL);

    printf("Inside the main function after creating threads \n");

    for (int i = 10; i < 15; i++) {
        printf("Inside Main: %d\n", i);
        sleep(1);
    }

    // Wait for threads to finish execution
    pthread_join(a_thread1, NULL);
    pthread_join(a_thread2, NULL);

    return 0; // Ensure main function returns 0
}

// Thread function 1
void *thread_function1(void *args) {
    printf("Thread1 started\n");
    for (int i = 0; i < 5; i++) {
        printf("Inside Thread1: %d\n", i);
        sleep(1);
    }
    return NULL; // Ensure the thread function returns NULL
}

// Thread function 2
void *thread_function2(void *args) {
    printf("Thread2 started\n");
    for (int i = 6; i < 10; i++) {
        printf("Inside Thread2: %d\n", i);
        sleep(1);
    }
    return NULL; // Ensure the thread function returns NULL
}

