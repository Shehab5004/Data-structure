
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_SEATS 50
#define MAX_NAME_LENGTH 50

// Define structs
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int seat;
} Passenger;

// Define global variables
Passenger passengers[MAX_SEATS];
int numPassengers = 0;

// Function prototypes
void displayMenu();
void bookTicket();
void cancelTicket();
void displayPassengers();
int getNextId();

int main() {
    // Display menu and handle user input
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                cancelTicket();
                break;
            case 3:
                displayPassengers();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Display the main menu
void displayMenu() {
    printf("\nWelcome to the Bus Ticket Management System!\n");
    printf("1. Book a ticket\n");
    printf("2. Cancel a ticket\n");
    printf("3. Display passengers\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
}

// Book a ticket
void bookTicket() {
    // Check if all seats are taken
    if (numPassengers == MAX_SEATS) {
        printf("Sorry, all seats are taken.\n");
        return;
    }

    // Get passenger details
    Passenger newPassenger;
    newPassenger.id = getNextId();
    printf("Please enter the passenger's name: ");
    scanf("%s", newPassenger.name);

    // Assign a seat
    int i;
    for (i = 0; i < MAX_SEATS; i++) {
        if (passengers[i].id == 0) {
            newPassenger.seat = i + 1;
            passengers[i] = newPassenger;
            numPassengers++;
            printf("Ticket booked successfully! Passenger ID: %d, Seat number: %d\n", newPassenger.id, newPassenger.seat);
            return;
        }
    }
}

// Cancel a ticket
void cancelTicket() {
    // Get passenger ID to cancel
    int cancelId;
    printf("Please enter the passenger ID to cancel: ");
    scanf("%d", &cancelId);

    // Find the passenger and remove them from the list
    int i;
    for (i = 0; i < MAX_SEATS; i++) {
        if (passengers[i].id == cancelId) {
            passengers[i].id = 0;
            passengers[i].name[0] = '\0';
            passengers[i].seat = 0;
            numPassengers--;
            printf("Ticket cancelled successfully!\n");
            return;
        }
    }

    // If the passenger ID is not found, display an error message
    printf("Passenger ID %d not found.\n", cancelId);
}

// Display a list of all passengers
void displayPassengers() {
    printf("Passenger ID\tPassenger name\tSeat number\n");
    int i;
    for (i = 0; i < MAX_SEATS; i++) {
        if (passengers[i].id != 0) {
            printf("%d\t\t%s\t\t%d\n", passengers[i].id, passengers[i].name, passengers[i].seat);
}
}
}

// Get the next available passenger ID
int getNextId() {
int i;
for (i = 1; i <= MAX_SEATS; i++) {
int idTaken = 0;
int j;
for (j = 0; j < MAX_SEATS; j++) {
if (passengers[j].id == i) {
idTaken = 1;
break;
}
}
if (!idTaken) {
return i;
}
}
return -1;
}

