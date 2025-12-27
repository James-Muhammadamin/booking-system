Booking System Overbooking – Critical Section (in C)

*Project Description*

This project demonstrates the "overbooking problem" caused by a "race condition" in a booking system and shows how to prevent it using "synchronization (mutex)"

The example is based on a simplified airline booking scenario where multiple users try to book a limited number of seats at the same time.


Project Structure
booking-system
│
├── backend
│ ├── booking_without_lock.c Overbooking happens
│ └── booking_with_lock.c Overbooking prevented using mutex
│
├── README.md
└── REPORT.pdf




--Technologies Used--

1) Programming Language: C
2) Concurrency: POSIX Threads (pthread)
3) Synchronization: Mutex (pthread_mutex)


Case 1: Without Synchronization (Race Condition)

File: booking_without_lock.c

1) Multiple threads access a shared resource (available_seats)
2) No protection on the critical section
3) Results in overbooking
4) Demonstrates a read/write conflict


Case 2: With Synchronization (Mutex Protection)

File: booking_with_lock.c

1) Critical section protected using "pthread_mutex_lock"
2) Only one thread can book at a time
3) Overbooking is successfully prevented


How to Compile and Run

Navigate to the backend directory first:

bash
cd backend


