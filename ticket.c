
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 42

// Define the structure for the bus ticket
struct bus_ticket {
    char name[30];
    char from[30];
    char destination[30];
    int seat_no;
};

// Function to book a ticket
void bookTicket(struct bus_ticket tickets[], int *numTickets) {
    if (*numTickets >= 42) {
        printf("No more tickets can be booked.\n");
        return;
    }

    printf("\nEnter the passenger name: ");
    scanf("%s", tickets[*numTickets].name);

    printf("Enter the start point: ");
    scanf("%s", tickets[*numTickets].from);

    printf("Enter the destination: ");
    scanf("%s", tickets[*numTickets].destination);

    printf("Enter the seat number: ");
    scanf("%d", &tickets[*numTickets].seat_no);

    printf("\nTicket booked successfully!\n");
    (*numTickets)++;
}

// Function to cancel a ticket
void cancelTicket(struct bus_ticket tickets[], int *numTickets) {
    int seatNo;
    printf("\nEnter the seat number of the ticket to be cancelled: ");
    scanf("%d", &seatNo);

    for (int i = 0; i < *numTickets; i++) {
        if (tickets[i].seat_no == seatNo) {
            // Shift the tickets to fill the gap
            for (int j = i; j < (*numTickets) - 1; j++) {
                tickets[j] = tickets[j + 1];
            }

            (*numTickets)--; // Decrease the ticket count
            printf("\nTicket cancelled successfully!\n");
            return;
        }
    }

    printf("Ticket not found.\n");
}

// Function to view all tickets
void viewAllTickets(struct bus_ticket tickets[], int numTickets) {
    printf("\n%-30s%-30s%-30s%s\n", "Passenger Name", "From", "Destination", "Seat Number");
    for (int i = 0; i < numTickets; i++) {
        printf("%-30s%-30s%-30s%d\n", tickets[i].name, tickets[i].from, tickets[i].destination, tickets[i].seat_no);
    }
}

// Function to display the seat plan
void displaySeatPlan() {
    printf("\nSeat Plan:");
    printf("\n--------------------");
    printf("\n|door  engine   driver|");
    printf("\n| 1  2     a      3  4|");
    printf("\n| 5  6     b      7  8|");
    printf("\n| 9  10    c     11 12|");
    printf("\n| 13 14    d     15 16|");
    printf("\n| 17 18    e     19 20|");
    printf("\n| 21 22    f     23 24|");
    printf("\n| 25 26    g     27 28|");
    printf("\n| 29 30    h     31 32|");
    printf("\n| 33 34    f     35 36|");
    printf("\n| 37 38 39 j  40 41 42|");
    printf("\n--------------------\n");
}

int main() {
    struct bus_ticket tickets[42];
    int numTickets = 0;
    int choice;

    // Loop through the program
    do {
        printf("\n\t\tWelcome to Star Travels (Dhaka~Satkhira)\n");
        printf("\tPayment: bkash/nagad/rocket:01569160000 (1000 tk)\n");
        printf("\tNote: Please mention your seat no in reference while payment\n");

        // Display the menu
        printf("\n1. Book Ticket");
        printf("\n2. Cancel Ticket");
        printf("\n3. View All Tickets");
        printf("\n4. Seat Plan");
        printf("\n5. Exit");
        printf("\n\nEnter your choice: ");

        // Read the user's choice
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1: // Book Ticket
                bookTicket(tickets, &numTickets);
                break;

            case 2: // Cancel Ticket
                cancelTicket(tickets, &numTickets);
                break;

            case 3: // View All Tickets
                viewAllTickets(tickets, numTickets);
                break;

            case 4: // Display Seat Plan
                displaySeatPlan();
                break;

            case 5: // Exit
                printf("\nExiting program...\n");
                break;

            default: // Invalid choice
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

