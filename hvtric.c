#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 100

// Structure to represent a ticket
typedef struct {
    int ticketNumber;
    char eventName[100];
    char eventDate[100];
    int availableSeats;
} Ticket;

// Function to display available tickets
void displayTickets(Ticket tickets[], int numTickets) {
    printf("Available Tickets:\n");
    printf("-------------------\n");
    for (int i = 0; i < numTickets; i++) {
        if (tickets[i].availableSeats > 0) {
            printf("Ticket Number: %d\n", tickets[i].ticketNumber);
            printf("Event Name: %s\n", tickets[i].eventName);
            printf("Event Date: %s\n", tickets[i].eventDate);
            printf("Available Seats: %d\n", tickets[i].availableSeats);
            printf("-------------------\n");
        }
    }
}

// Function to book a ticket
void bookTicket(Ticket tickets[], int numTickets, int ticketNumber) {
    for (int i = 0; i < numTickets; i++) {
        if (tickets[i].ticketNumber == ticketNumber) {
            if (tickets[i].availableSeats > 0) {
                tickets[i].availableSeats--;
                printf("Ticket booked successfully!\n");
            } else {
                printf("No available seats for this ticket.\n");
            }
            return;
        }
    }
    printf("Invalid ticket number.\n");
}

int main() {
    Ticket tickets[MAX_TICKETS];
    int numTickets;
    int choice;

    printf("Enter the total number of tickets: ");
    scanf("%d", &numTickets);

    // Initialize tickets
    for (int i = 0; i < numTickets; i++) {
        tickets[i].ticketNumber = i + 1;
        printf("Enter the event name for ticket %d: ", i + 1);
        scanf("%s", tickets[i].eventName);
        printf("Enter the event date for ticket %d: ", i + 1);
        scanf("%s", tickets[i].eventDate);
        printf("Enter the available seats for ticket %d: ", i + 1);
        scanf("%d", &tickets[i].availableSeats);
    }

    do {
        printf("\nOnline Ticket Booking System\n");
        printf("---------------------------\n");
        printf("1. Display available tickets\n");
        printf("2. Book a ticket\n");
        printf("3. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTickets(tickets, numTickets);
                break;
            case 2: {
                int ticketNumber;
                printf("Enter the ticket number: ");
                scanf("%d", &ticketNumber);
                bookTicket(tickets, numTickets, ticketNumber);
                break;
            }
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
