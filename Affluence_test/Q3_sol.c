#include<stdio.h> 
#include<stdlib.h> 
  
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
void insertAtTheBegin(struct Node **start_ref, int data); 
  
void bubbleSort(struct Node *start); 

void sort(struct Node *start, int lastSymbol);
  
void swap(struct Node *a, struct Node *b); 
  
void printList(struct Node *start); 
  
int main() 
{ 
    int list_size, i;
    printf("Enter no. of symbol: "); scanf("%d",&list_size);
    
    int arr[list_size];// = {1,9,2,8,3,7,4,6,5}; 
    printf("\nEnter all symbols: ");
    for(i=0;i<list_size;i++) scanf("%d",&arr[i]);
  
    /* start with empty linked list */
    struct Node *start = NULL; 
  
    /* Create linked list from the array arr[]. */
    for (i = 0; i< list_size; i++) 
        insertAtTheBegin(&start, arr[i]); 
  
    /* sort the linked list */
    bubbleSort(start); 
    /* print list after sorting */
    printf("\n Linked list after sorting "); 
    printList(start); 
    printf("\n");
    
    int symbol1, symbol2;
    
    printf("Pick symbol1: ");scanf("%d",&symbol1);
    printf("Pich symbol2: ");scanf("%d",&symbol2);
    
    /* sort in descending order between symbols */
    struct Node *temp = start; 
    while(temp!=NULL && temp->data!=symbol1 && temp->data!=symbol2) temp = temp->next;
    if(temp!=NULL){
        if(temp->data==symbol1 && temp->next !=NULL) sort(temp->next,symbol2);
        else if(temp->data==symbol2 && temp->next !=NULL) sort(temp->next,symbol1);
    }
  
    /* print list after sorting */
    printf("\n Linked list after picking symbols, sorted in descending order between symbols rest in ascending order "); 
    printList(start); 
  
    getchar(); 
    return 0; 
} 
  
  
/* Function to insert a node at the beginning of a linked list */
void insertAtTheBegin(struct Node **start_ref, int data) 
{ 
    struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node)); 
    ptr1->data = data; 
    ptr1->next = *start_ref; 
    *start_ref = ptr1; 
} 
  
/* Function to print nodes in a given linked list */
void printList(struct Node *start) 
{ 
    struct Node *temp = start; 
    printf("\n"); 
    while (temp!=NULL) 
    { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
} 
  
/* Bubble sort the given linked list */
void bubbleSort(struct Node *start) 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data > ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

/* Bubble sort the given linked list in reverse from a starting to given end*/
void sort(struct Node *start, int lastSymbol) 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr && ptr1->next->data!=lastSymbol)
        { 
            if (ptr1->data < ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  
/* function to swap data of two nodes a and b*/
void swap(struct Node *a, struct Node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 
