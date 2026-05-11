#include<stdio.h>
#include<stdlib.h>
void create();
void display();
struct node { int info; struct node *next; };
struct node *start=null;
int main()
{
    int choice;
    while(1)
    { printf("enter 1 to create\nenter 2 to display\nenter 3 to exit ");
    scanf("%d", &choice);
    switch(choice)
    { case 1: { create(); break; }
    case 2: { display(); break; }
        case 3: { exit(0); break;
        }
        }
        }
    return 0;
            }
    void create()
    { struct node *temp, *ptr;
    temp=(struct node *)
    malloc(sizeof(struct node));
    if(temp == null)
    { printf("out of memory space");
    exit(0);
    }
    printf("enter the data value for the node: ");
    scanf("%d", &temp->info);
    temp->next=null;
    if(start==null)
    { start=temp; }
    else { ptr=start;
    while(ptr->next!=null)
    { ptr=ptr->next;
    } ptr->next=temp;
    }
    }
    void display()
        { struct node *ptr;
        if(start == null)
    { printf("list is empty.\n");
     return;
      }
       else { ptr=start;
    printf("the list elements are: ");
     while(ptr!=null)
        {
             printf("%d \n",ptr->info);
     ptr=ptr->next;
     }
      } }
