#include <stdio.h>
#include <string.h>
#include "malloc.h"
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *last = NULL;


//check to see if the list is empty, if the head node is null it returns true else it returns false
bool isEmpty() {
    return head == NULL;
}

int length() {
    int length = 0;
    struct node *current;

    for(current = head; current != NULL; current = current->next){
        length++;
    }

    return length;
}

//display the list in from first to last
void display() {

    //start from the beginning
    struct node *ptr = head;

    //navigate till the end of the list
    printf("\n[ ");

    while(ptr != NULL) {
        printf("(%d)",ptr->data);
        ptr = ptr->next;
    }

    printf(" ]");
}



//insert link at the first location
void insertFirst(int data) {

    //create a link
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;

    if(isEmpty()) {
        //make it the last link
        last = link;
    }

    //point it to old first link
    link->next = head;

    //point first to new first link
    head = link;
}

//insert link at the tail
void insertLast(int data) {
    //create a node
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    last->next = temp;
    last = temp;
}

//insert a node after the node containing the value passed in
bool insertAfter(int value) {
    struct node *current = head;// so you can go through list from head to tail
    //if list is empty
    if (head == NULL) {
        return false;
    }
    //navigate through list
    while (current->data != value) {

        //if it is last node
        if (current->next == NULL) {
            return false;
        } else {
            //move to next node
            current = current->next;
        }
    }
    struct node *newLink = (struct node*) malloc(sizeof(struct node));
    newLink->data = 13;
    if(current == last) {
        newLink->next = NULL;
        last = newLink;
    } else {
        newLink->next = current->next;
    }

    current->next = newLink;
    return true;
}

void delete(int data) {

//start from the first link
struct node* current = head;
//if list is empty
if(head == NULL) {
return;
}

//navigate through list
while(current->next->data != data) {
//if it is last node

if(current->next == NULL) {
return;
} else {
current = current->next;
}
}

//found a match, update the link
if(current == head) {
//change first to point to next link
head = head->next;
} else {
//bypass the current link
current->next = current->next->next;
}
}


void main() {
    insertFirst(1);
    insertFirst(2);
    insertFirst(3);
    insertFirst(4);
    insertFirst(5);
    insertFirst(6);

    printf("First to Last");
    display();

    printf("\nInsert in middle");
    insertAfter(3);
    display();

    printf("\n Insert at head:");
    insertFirst(45);
    display();

    printf("\n Insert at tail:");
    insertLast(10);
    display();

    printf("\n Delete the node with value 13");
    delete(13);
    display();
}