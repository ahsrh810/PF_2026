#include <stdio.h>

struct Flight {
    char flightNumber[20];
    char departureCity[50];
    char destinationCity[50];
    char date[20];
    int availableSeats;
};

int main() {
    struct Flight f1 = {"231", "Karachi", "Lahore", "20-11-2026", 2};
    int choice;

    while (1) {
        printf("\n1. Display Flight Details\n2. Book a Seat\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Flight Number   : %s\n", f1.flightNumber);
            printf("Departure City  : %s\n", f1.departureCity);
            printf("Destination City: %s\n", f1.destinationCity);
            printf("Date            : %s\n", f1.date);
            printf("Available Seats : %d\n", f1.availableSeats);
        } else if (choice == 2) {
            if (f1.availableSeats > 0) {
                f1.availableSeats--;
                printf("\nSeat booked successfully! Remaining seats: %d\n", f1.availableSeats);
            } else {
                printf("\nSorry, no seats available on this flight.\n");
            }
        } else if (choice == 3) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}