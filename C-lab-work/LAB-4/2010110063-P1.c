//Program written in C
//Name: Akshat Sabavat Roll numnber: 2010110063
//I have not copied from anyone or any source

#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
}*alpha,*Calpha;

void PrintList(struct node* head){
    struct node* pointer;
    pointer = head;
    while(pointer != NULL){
        printf(" %d -> ",pointer -> data);
        pointer = pointer -> next;
    }
}

void PrintCircular(struct node* rear){
    struct node* current = NULL;
    if(rear != NULL){
        current = rear -> next;
        do
        {
            printf(" %d -> ",current -> data);
            current = current -> next;
        } while (current != rear -> next);
        
    }
}


struct node* CreateNode(int x){
    struct node* temp = malloc(sizeof(struct node));
    temp -> next = NULL;
    temp -> data = x;
    return temp;
}


void CreateList(){
    int lenght;
    struct node* pointer = NULL;
    struct node* insert_node = NULL;

    FILE * filepointer1 = fopen("linking.txt","r");
    fscanf(filepointer1,"%d",&lenght);  //lenght here describes how many times ill be looping through the file to get a set of linked list elements 


    for ( int i = 0; i < lenght; i++)
    {
        insert_node = malloc(sizeof(struct node));
        fscanf(filepointer1,"%d",&(insert_node -> data));
        insert_node -> next = NULL;

        if(alpha == NULL){
            alpha = insert_node;
        }else {
            pointer = alpha;
            while(pointer-> next != NULL){
                 pointer = pointer -> next;
            }
             pointer -> next = insert_node;
        }
    }

    printf("List was created\n");    
}

void ADDatRear(struct node** head,int value){
    struct node* ptr = *head;
    struct node* nodeAtRear;
    nodeAtRear = CreateNode(value);
    while (ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }

    ptr -> next = nodeAtRear;
}

void DeleteBackandForth(struct node** head){
    struct node* temp1 = NULL;
    struct node* temp2 = NULL;
    struct node* ptr = *head;

    while (ptr -> next -> next != NULL)
    {
        ptr = ptr -> next;
    }

    //Deleting last node
    temp1 = ptr -> next;
    ptr -> next = NULL;
    free(temp1);
    
    //Deleting first node
    temp2 = *head;
    *head = (*head) -> next;
    free(temp2);
}

void CreateCircular(struct node** head){
    struct node* ptr = *head;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }
    Calpha = ptr;
    Calpha -> next = *head;
}

void AddatRear_Circular(struct node** rear,int value){
    struct node* NewRear = CreateNode(value);

    NewRear -> next = (*rear) -> next;
    (*rear) -> next = NewRear;
    *rear = NewRear;
}

void sub10Everywhere(){
    struct node* circularPointer = NULL;
    if(Calpha != NULL){
        circularPointer = Calpha -> next;
        do{
            circularPointer -> data = circularPointer -> data - 10;
            circularPointer = circularPointer -> next;
        }while(circularPointer != Calpha -> next);
    }

    printf("\n");
    PrintCircular(Calpha);
}

void FindSmallest(){
      struct node* circularPointer = NULL;
      int smallest;
    if(Calpha != NULL){
        circularPointer = Calpha -> next;
        smallest = Calpha -> next -> data;
        do{
            if(smallest > circularPointer -> data){
                smallest = circularPointer -> data;
            }
            circularPointer = circularPointer -> next;
        }while(circularPointer != Calpha -> next);
    }

    printf("\n");
    printf("The smallest value is = %d",smallest);
}

void MainAct(){
    CreateList();
    PrintList(alpha);
    ADDatRear(&alpha,200);
    ADDatRear(&alpha,340);
    printf("\n");
    PrintList(alpha);
    DeleteBackandForth(&alpha);
    printf("\n");
    PrintList(alpha);
    CreateCircular(&alpha);
    AddatRear_Circular(&Calpha,300);
    printf("\n");
    PrintCircular(Calpha);
    sub10Everywhere();
    FindSmallest();
}

int main(){
    MainAct();
}