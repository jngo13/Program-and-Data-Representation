/*
 Justin Ngo
 jmn4fms
 4/9/20
 linkedlist.c
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev, *next;
    int data;
};

struct list{
    struct node *head;
    struct node *tail;
    int size;
};

int main(){
    //Read in an integer, n
    int n = 0;
    printf("Enter how many values to input: ");
    scanf("%d",&n);
    
    //Read in n more ints, and put those into a linked list
    //Linked list must be dynamically allocated
    int num, i;
    struct node *newnode;
    
    struct list *list = (struct list *) malloc(sizeof(struct list));
    
    list->size = 0;
    list->head = NULL;
    
    for(i = 1; i <= n; i++){
        printf("Enter value ");
        printf("%d",i);
        printf(": ");
        scanf("%d",&num);
        newnode =(struct node *) malloc(sizeof(struct node));
        newnode->data = num;
        
        if (list->head==NULL) {
            newnode->next = NULL;
            list->head = newnode;
    }
        else {
            newnode->next = list->head;
            list->head = newnode;
        }
    list->size++;
    }

    //Print out that linked list
    int itr;
    struct node *s=list->head;
    
    for(itr = 0; itr < list->size; itr++){
        printf("%d\n",s->data);
        s = s->next;
    }
    
    free(newnode); //Properly deallocate the linked list

    free(list);

    return 0;
}
