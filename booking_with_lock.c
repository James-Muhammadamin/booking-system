#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int available_seats = 1;
pthread_mutex_t lock;

void* book_seat(void* arg) {
    pthread_mutex_lock(&lock);

    if (available_seats > 0) {
        sleep(1);
        available_seats--;
        printf("Seat booked safely! Remaining seats: %d\n", available_seats);
    } else {
        printf("No seats available\n");
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);

    printf("WITH synchronization (No overbooking)\n");

    pthread_create(&t1, NULL, book_seat, NULL);
    pthread_create(&t2, NULL, book_seat, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
