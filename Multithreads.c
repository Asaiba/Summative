#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 10

typedef struct {
    int *arr;
    int start;
    int end;
    long long partial_sum;
} ThreadData;

void* compute_sum(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    data->partial_sum = 0;
    
    for (int i = data->start; i < data->end; i++) {
        data->partial_sum += data->arr[i];
    }
    
    pthread_exit(NULL);
}

int main() {
    int n;
    printf("Enter the number of elements (n > 1000): ");
    scanf("%d", &n);

    if (n <= 1000) {
        printf("Error: n must be greater than 1000.\n");
        return 1;
    }

    int *arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Fill array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random numbers between 0-99
    }

    pthread_t threads[THREAD_COUNT];
    ThreadData thread_data[THREAD_COUNT];
    int chunk_size = n / THREAD_COUNT;
    
    // Create threads to compute partial sums
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_data[i].arr = arr;
        thread_data[i].start = i * chunk_size;
        thread_data[i].end = (i == THREAD_COUNT - 1) ? n : (i + 1) * chunk_size;

        pthread_create(&threads[i], NULL, compute_sum, &thread_data[i]);
    }

    // Wait for all threads to finish
    long long total_sum = 0;
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
        total_sum += thread_data[i].partial_sum;
    }

    printf("Total Sum: %lld\n", total_sum);

    free(arr);
    return 0;
}
