#include <stdio.h>
#define SIZE 50

// Queue structure
int queue[SIZE];
int front = -1, rear = -1;

// Function to add a customer to queue
void enqueue(int customer) {
    if (rear == SIZE - 1) {
        printf("Queue is full! No more customers can join.\n");
        return;
    }
    if (front == -1) front = 0;

    rear++;
    queue[rear] = customer;
    printf("Customer %d joined the queue.\n", customer);
}

// Function to serve (book ticket)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("No customers in queue.\n");
        return;
    }
    printf("Customer %d booked ticket and left.\n", queue[front]);
    front++;
}

// Display all customers waiting
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Customers waiting in queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, customerID = 1;

    while (1) {
        printf("\n--- Ticket Booking System Simulation ---\n");
        printf("1. Add Customer to Queue\n");
        printf("2. Book Ticket (Serve Customer)\n");
        printf("3. Display Waiting Customers\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(customerID++);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting system...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
