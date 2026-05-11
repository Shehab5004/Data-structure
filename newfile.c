#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 10 // Maximum number of seats on the bus
#define MAX_NAME_LEN 20 // Maximum length of passenger name

// Struct representing a passenger
typedef struct {
    char name[MAX_NAME_LEN];
    int seat_number;
} Passenger;

// Array of passengers currently on the bus
Passenger passengers[MAX_SEATS];

// Function to display the menu options
void display_menu() {
    printf("\n1. Reserve a seat\n");
    printf("2. Cancel a reservation\n");
    printf("3. View passenger list\n");
    printf("4. Exit\n");
}

// Function to reserve a seat
void reserve_seat() {
    // Check if all seats are already reserved
    if (passengers[MAX_SEATS - 1].seat_number != 0) {
        printf("\nSorry, all seats are already reserved.\n");
        return;
    }

    // Get passenger name
    char name[MAX_NAME_LEN];
    printf("\nEnter passenger name: ");
    scanf("%s", name);

    // Find the first available seat
    int seat_number = 0;
    while (passengers[seat_number].seat_number != 0) {
        seat_number++;
    }

    // Reserve the seat for the passenger
    strcpy(passengers[seat_number].name, name);
    passengers[seat_number].seat_number = seat_number + 1;

    printf("\nSeat %d reserved for %s.\n", passengers[seat_number].seat_number, passengers[seat_number].name);
}

// Function to cancel a reservation
void cancel_reservation() {
    // Get passenger name
    char name[MAX_NAME_LEN];
    printf("\nEnter passenger name: ");
    scanf("%s", name);

    // Find the passenger and free up their seat
    int i;
    for (i = 0; i < MAX_SEATS; i++) {
        if (strcmp(passengers[i].name, name) == 0) {
            printf("\nReservation for %s on seat %d cancelled.\n", passengers[i].name, passengers[i].seat_number);
            strcpy(passengers[i].name, "");
            passengers[i].seat_number = 0;
            return;
        }
    }

    // If passenger not found, display error message
    printf("\nNo reservation found for passenger %s.\n", name);
}

// Function to view the list of passengers
void view_passenger_list() {
    printf("\nPassenger list:\n");
    int i;
    for (i = 0; i < MAX_SEATS; i++) {
        if (passengers[i].seat_number != 0) {
            printf("%d. %s\n", passengers[i].seat_number, passengers[i].name);
        }
    }
}

// Main function
int main() {
    int choice;
    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                reserve_seat();
                break;
            case 2:
                cancel_reservation();
                break;
            case 3:
                view_passenger_list();
                break;
            case 4:
                printf("\nExiting the program.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}
