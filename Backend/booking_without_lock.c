#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int available_seats = 1;

void* book_seat(void* arg) {
    if (available_seats > 0) {
        sleep(1);
        available_seats--;
        printf("Seat booked! Remaining seats: %d\n", available_seats);
    } else {
        printf("No seats available\n");
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    printf("WITHOUT synchronization (Overbooking happens)\n");

    pthread_create(&t1, NULL, book_seat, NULL);
    pthread_create(&t2, NULL, book_seat, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
