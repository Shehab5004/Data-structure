#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
void insert(struct Node** head, int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = *head;
*head = newNode;
}
struct Node* search(struct Node* head, int value) {
struct Node* current = head;
while (current != NULL) {
if (current->data == value) {
return current;
}
current = current->next;
}
return NULL;
}
void display(struct Node* head) {
struct Node* current = head;
if (current == NULL) {
printf("Linked list is empty.\n");
return;
}
printf("Linked list: ");
while (current != NULL) {
printf("%d ", current->data);
current = current->next;
}
printf("\n");
}
int main() {
struct Node* head = NULL;
int value, target, numNodes;
printf("Enter the number of nodes in the linked list: ");
scanf("%d", &numNodes);
for (int i = 0; i < numNodes; i++) {
printf("Enter the value for node %d: ", i + 1);
scanf("%d", &value);
insert(&head, value);
}
display(head);
printf("Enter the value to search for: ");
scanf("%d", &target);
struct Node* result = search(head, target);
if (result != NULL) {
printf("Value %d found in the linked list.\n", target);
} else {
printf("Value %d not found in the linked list.\n", target);
}
return 0;
}

