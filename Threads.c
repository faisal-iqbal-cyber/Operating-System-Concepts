#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Function prototypes
void *printFun1(void *args);
void *printFun2(void *args);
void *printFun3(void *args);
void *printFun4(void *args);
void *printFun5(void *args);

int main() {
    char *msg1 = "Thread 1";
    char *msg2 = "Thread 2";
    char *msg3 = "Thread 3";
    char *msg4 = "Thread 4";
    char *msg5 = "Thread 5";

    pthread_t a_thread1, a_thread2, a_thread3, a_thread4, a_thread5;

    // Create threads and check for errors
    if (pthread_create(&a_thread1, NULL, printFun1, (void *)msg1) != 0) {
        perror("Error creating Thread 1");
        return 1;
    }
    if (pthread_create(&a_thread2, NULL, printFun2, (void *)msg2) != 0) {
        perror("Error creating Thread 2");
        return 1;
    }
    if (pthread_create(&a_thread3, NULL, printFun3, (void *)msg3) != 0) {
        perror("Error creating Thread 3");
        return 1;
    }
    if (pthread_create(&a_thread4, NULL, printFun4, (void *)msg4) != 0) {
        perror("Error creating Thread 4");
        return 1;
    }
    if (pthread_create(&a_thread5, NULL, printFun5, (void *)msg5) != 0) {
        perror("Error creating Thread 5");
        return 1;
    }

    printf("Inside the main function after creating threads\n");

    // Wait for threads to finish execution
    pthread_join(a_thread1, NULL);
    pthread_join(a_thread2, NULL);
    pthread_join(a_thread3, NULL);
    pthread_join(a_thread4, NULL);
    pthread_join(a_thread5, NULL);

    return 0;
}

// Thread function 1 (Sum)
void *printFun1(void *args) {
    int sum = 0;
    printf("%s started\n", (char *)args);
    for (int i = 0; i < 5; i++) {
        sum += i;
        sleep(1);
    }
    printf("Sum is: %d\n", sum);
    pthread_exit(NULL);
}

// Thread function 2 (Multiplication)
void *printFun2(void *args) {
    int mul = 1;
    printf("%s started\n", (char *)args);
    for (int i = 1; i < 5; i++) {
        mul *= i;
        sleep(1);
    }
    printf("Multiplication is: %d\n", mul);
    pthread_exit(NULL);
}

// Thread function 3 (Modulus) - Fixed initialization
void *printFun3(void *args) {
    int mod = 11; // Avoid zeroing out immediately
    printf("%s started\n", (char *)args);
    for (int i = 1; i < 5; i++) {
        if (i != 0) mod %= i; // Added check
        sleep(1);
    }
    printf("Modulus is: %d\n", mod);
    pthread_exit(NULL);
}

// Thread function 4 (Division) - Added check
void *printFun4(void *args) {
    int div = 100;
    printf("%s started\n", (char *)args);
    for (int i = 1; i < 5; i++) {
        if (i != 0) div /= i; // Ensure no division by zero
        sleep(1);
    }
    printf("Division result is: %d\n", div);
    pthread_exit(NULL);
}

// Thread function 5 (Subtraction)
void *printFun5(void *args) {
    int sub = 0;
    printf("%s started\n", (char *)args);
    for (int i = 0; i < 5; i++) {
        sub -= i;
        sleep(1);
    }
    printf("Subtraction result is: %d\n", sub);
    pthread_exit(NULL);
}
