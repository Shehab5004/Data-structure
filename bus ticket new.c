#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the bus ticket
struct bus_ticket {
    char name[30];
    char from[30];
    char destination[30];
    int seat_no;
};

// Define the main function
int main() {
    // Initialize the variables
    int choice, i, n = 0;
    struct bus_ticket ticket[100];

    // Loop through the program
    do { printf("\t\tWelcome to sas travels\t(dhaka~satkhira)\n");
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
        switch(choice) {
            case 1: // Book Ticket
                printf("\nEnter the passenger name: ");
                scanf("%s", ticket[n].name);

                printf("Enter the from: ");
                scanf("%s", ticket[n].from);

                printf("Enter the destination: ");
                scanf("%s", ticket[n].destination);

                printf("Enter the seat number: ");
                scanf("%d", &ticket[n].seat_no);

                printf("\nTicket booked successfully!\n");
                n++; // Increase the ticket count
                break;

            case 2: // Cancel Ticket
                printf("\nEnter the seat number of the ticket to be cancelled: ");
                scanf("%d", &i);

                if (i >= 45) {
                    printf("Invalid seat number!\n");
                } else {
                    // Shift the tickets to fill the gap
                    for (int j = i; j < n - 1; j++) {
                        ticket[j] = ticket[j + 1];
                    }

                    n--; // Decrease the ticket count
                    printf("\nTicket cancelled successfully!\n");
                }
                break;

            case 3: // View All Tickets
                printf("\n%-30s%-30s%-30s%s\n", "Passenger Name", "from", "Destination", "Seat Number");
                for (int j = 0; j < n; j++) {
                    printf("%-30s%-30s%-30s%d\n", ticket[j].name, ticket[j].from, ticket[j].destination, ticket[j].seat_no);
                }
                break;
            case 4: //view seat plan
                printf("\n                       ");
                printf("\ndoor   engine   driver ");
                printf("\n                       ");
                printf("\n 1  2      a      3  4 ");
                printf("\n 5  6      b      7  8 ");
                printf("\n 9 10      c     11 12 ");
                printf("\n13 14      d     15 16 ");
                printf("\n17 18      e     19 20 ");
                printf("\n21 22      f     23 24 ");
                printf("\n25 26      g     27 28 ");
                printf("\n29 30      h     31 32 ");
                printf("\n33 34      i     35 36 ");
                printf("\n37 38 39   j  40 41 42 ");

            case 5: // Exit
                printf("\nExiting program...");
                break;

            default: // Invalid choice
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

