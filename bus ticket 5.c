#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSSES 100
#define MAX_TICKETS_PER_BUS 50

// Struct to represent a ticket
typedef struct {
    int id;
    char name[50];
    int age;
    char source[50];
    char destination[50];
    int bus_id;
} Ticket;

// Struct to represent a bus
typedef struct {
    int id;
    char name[50];
    char source[50];
    char destination[50];
    int num_tickets;
    Ticket tickets[MAX_TICKETS_PER_BUS];
} Bus;

// Global array to store all the buses
Bus buses[MAX_BUSSES];
int num_buses = 0;

// Function to add a new bus to the system
void add_bus() {
    Bus new_bus;
    printf("Enter bus name: ");
    scanf("%s", new_bus.name);
    printf("Enter source: ");
    scanf("%s", new_bus.source);
    printf("Enter destination: ");
    scanf("%s", new_bus.destination);
    new_bus.id = num_buses + 1;
    new_bus.num_tickets = 0;
    buses[num_buses] = new_bus;
    num_buses++;
    printf("Bus added successfully!\n");
}

// Function to display all the buses in the system
void display_buses() {
    printf("Buses:\n");
    for (int i = 0; i < num_buses; i++) {
        printf("%d. %s (%s to %s)\n", buses[i].id, buses[i].name, buses[i].source, buses[i].destination);
    }
}

// Function to book a ticket on a bus
void book_ticket() {
    int bus_id;
    printf("Enter bus id: ");
    scanf("%d", &bus_id);
    if (bus_id < 1 || bus_id > num_buses) {
        printf("Invalid bus id!\n");
        return;
    }
    Bus *bus = &buses[bus_id - 1];
    if (bus->num_tickets >= MAX_TICKETS_PER_BUS) {
        printf("No more tickets available for this bus!\n");
        return;
    }
    Ticket new_ticket;
    printf("Enter name: ");
    scanf("%s", new_ticket.name);
    printf("Enter age: ");
    scanf("%d", &new_ticket.age);
    printf("Enter source: ");
    scanf("%s", new_ticket.source);
    printf("Enter destination: ");
    scanf("%s", new_ticket.destination);
    new_ticket.id = bus->num_tickets + 1;
    new_ticket.bus_id = bus_id;
    bus->tickets[bus->num_tickets] = new_ticket;
    bus->num_tickets++;
    printf("Ticket booked successfully!\n");
}

// Function to display all the tickets for a bus
void display_tickets() {
    int bus_id;
    printf("Enter bus id: ");
    scanf("%d", &bus_id);
    if (bus_id < 1 || bus_id > num_buses) {
        printf("Invalid bus id!\n");
        return;
    }
    Bus *bus = &buses[bus_id - 1];
    printf("Tickets for %s (%s to %s):\n", bus->name, bus->source, bus->destination);
    for (int i = 0; i < bus->num_tickets; i++) {
        Ticket ticket = bus->tickets[i];
        printf("%d. %s (%d) %s to %s\n", ticket.id, ticket.name, ticket.age,ticket.source, ticket.destination);
}
}

// Function to display a menu and handle user input
void menu() {
int choice;
do {
printf("\n1. Add bus\n");
printf("2. Display buses\n");
printf("3. Book ticket\n");
printf("4. Display tickets\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
add_bus();
break;
case 2:
display_buses();
break;
case 3:
book_ticket();
break;
case 4:
display_tickets();
break;
case 5:
printf("Exiting...\n");
break;
default:
printf("Invalid choice!\n");
}
} while (choice != 5);
}

int main() {
menu();
return 0;
}







