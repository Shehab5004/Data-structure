
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 10
#define MAX_SEATS 50

// Structure for holding bus information
typedef struct {
    int id;
    char name[20];
    int seats[MAX_SEATS];
    int num_seats;
} Bus;

// Array of buses
Bus buses[MAX_BUSES];

// Number of buses in the system
int num_buses = 0;

// Helper function to find a bus by ID
int find_bus(int id) {
    for (int i = 0; i < num_buses; i++) {
        if (buses[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Helper function to reserve a seat on a bus
int reserve_seat(int bus_index, int seat_num) {
    if (seat_num < 1 || seat_num > MAX_SEATS) {
        return 0;
    }
    if (buses[bus_index].seats[seat_num-1] == 0) {
        buses[bus_index].seats[seat_num-1] = 1;
        buses[bus_index].num_seats++;
        return 1;
    } else {
        return 0;
    }
}

// Helper function to print the list of available seats on a bus
void print_available_seats(int bus_index) {
    printf("Available seats for bus %d (%s):\n", buses[bus_index].id, buses[bus_index].name);
    for (int i = 0; i < MAX_SEATS; i++) {
        if (buses[bus_index].seats[i] == 0) {
            printf("%d ", i+1);
        }
    }
    printf("\n");
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("1. Add bus\n");
        printf("2. Reserve seat\n");
        printf("3. Print available seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (num_buses >= MAX_BUSES) {
                    printf("Error: Maximum number of buses reached.\n");
                } else {
                    printf("Enter bus ID: ");
                    scanf("%d", &buses[num_buses].id);
                    printf("Enter bus name: ");
                    scanf("%s", buses[num_buses].name);
                    buses[num_buses].num_seats = 0;
                    memset(buses[num_buses].seats, 0, sizeof(buses[num_buses].seats));
                    num_buses++;
                }
                break;
            case 2:
                printf("Enter bus ID: ");
                int bus_id;
                scanf("%d", &bus_id);
                int bus_index = find_bus(bus_id);
                if (bus_index == -1) {
                    printf("Error: Bus not found.\n");
                } else {
                    print_available_seats(bus_index);
                    printf("Enter seat number to reserve: ");
                    int seat_num;
                    scanf("%d", &seat_num);
                    if (reserve_seat(bus_index, seat_num)) {
                        printf("Seat reserved.\n");
                    } else {
                        printf("Error: Seat not available.\n");
                    }
                }
                break;
            case 3:
                printf("Enter bus ID: ");
                scanf("%d", &bus_id);
                bus_index = find_bus(bus_id);
                if (bus_index == -1) {
                        printf("Error: Bus not found.\n");
} else {
printf("Available seats for bus %d (%s):\n", buses[bus_index].id, buses[bus_index].name);
for (int i = 0; i < MAX_SEATS; i++) {
if (buses[bus_index].seats[i] == 0) {
printf("%d ", i+1);
}
}
printf("\n");
}
break;
case 4:
printf("Exiting program.\n");
exit(0);
default:
printf("Error: Invalid choice.\n");
}
}
return 0;
}






