#include <stdio.h>
#include <stdlib.h>

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
    printf("------------------------------\n");
    for (int i = 0; i < numTickets; i++) {
        printf("Ticket Number: %d\n", tickets[i].ticketNumber);
        printf("Event Name: %s\n", tickets[i].eventName);
        printf("Event Date: %s\n", tickets[i].eventDate);
        printf("Available Seats: %d\n", tickets[i].availableSeats);
        printf("------------------------------\n");
    }
}

// Function to buy a ticket
void buyTicket(Ticket tickets[], int numTickets, int ticketNumber) {
    for (int i = 0; i < numTickets; i++) {
        if (tickets[i].ticketNumber == ticketNumber) {
            if (tickets[i].availableSeats > 0) {
                tickets[i].availableSeats--;
                printf("Ticket purchased successfully!\n");
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
    int numTickets = 0;
    int choice;

    do {
        printf("\nTicket Buying System\n");
        printf("------------------------------\n");
        printf("1. Display available tickets\n");
        printf("2. Buy a ticket\n");
        printf("3. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTickets(tickets, numTickets);
                break;
            case 2:
                if (numTickets == 0) {
                    printf("No tickets available.\n");
                } else {
                    int ticketNumber;
                    printf("Enter the ticket number: ");
                    scanf("%d", &ticketNumber);
                    buyTicket(tickets, numTickets, ticketNumber);
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

