//Program written in C
//Name: Akshat Sabavat Roll numnber: 2010110063
//I have not copied from anyone or any source

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
}*alpha,*beta, *delta;

void PrintList(struct node* head){
    struct node* pointer;
    pointer = head;
    while(pointer != NULL){
        printf(" %d ,",pointer -> data);
        pointer = pointer -> next;
    }
}


void CreateList(){
    int lenght;
    struct node* pointer = NULL;
    struct node* insert_node = NULL;

    FILE * filepointer1 = fopen("linking.txt","r");
    fscanf(filepointer1,"%d",&lenght);


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

struct node* CreateList_Delta(struct node* head,int x){
    struct node* pointer = NULL;
    struct node* insert_node = NULL;


        insert_node = malloc(sizeof(struct node));
        insert_node -> data = x;
        insert_node -> next = NULL;

        if(head == NULL){
            head = insert_node;
        }else {
            pointer = head;
            while(pointer-> next != NULL){
                 pointer = pointer -> next;
            }
             pointer -> next = insert_node;
        }
    

    return head;
}

void Copy(){
 struct node* temp = alpha;
    while (temp!= NULL)
    {
        struct node* ptr;
        struct node* new1 = (struct node *) malloc(sizeof(struct node));
        new1->data = temp->data;
        new1->next = NULL;
        if(beta == NULL)
        {
            beta = new1;
        }
        else
        {
            ptr = beta;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
        ptr-> next = new1;
        }
    temp = temp->next;
    }
}

void front600(){
    struct node* temp = malloc(sizeof(struct node));
    temp -> data = 600;
    temp -> next = NULL;
    
    Copy();

    //inserting 600

    if(beta == NULL){
        beta = temp;
    }else {
        temp -> next = beta;
        beta = temp;
    }

    printf("\n");
    PrintList(beta);
}

int count(){
    int counter = 0;
    struct node* pointer = NULL;
    pointer = beta;
    while(pointer != NULL){
        pointer = pointer -> next;
        counter++;
    }

    return counter;
}


void print_alternate(){
    struct node* pointer = NULL;
    pointer = alpha;
    while(pointer != NULL){
        printf(" %d, ",pointer -> data);
        pointer = pointer -> next -> next;
    }
}

void join(){
    struct node* pointer_beta = NULL;
    delta = CreateList_Delta(delta,100);
    delta = CreateList_Delta(delta,200);
    delta = CreateList_Delta(delta,300);
    pointer_beta = beta;
    while(pointer_beta -> next != NULL){
        pointer_beta = pointer_beta -> next;
    }

    pointer_beta -> next = delta;
    printf("\n");
    PrintList(beta);

}

void sub5(){
    struct node* pointer_to_first = NULL;
    struct node* pointer_to_last = NULL;

    pointer_to_first = alpha;
    pointer_to_last = alpha;

    while (pointer_to_last -> next != NULL)
    {
        pointer_to_last = pointer_to_last -> next;
    }

    pointer_to_first -> data = pointer_to_first -> data - 5;
    pointer_to_last -> data = pointer_to_last -> data - 5;

    printf("\n");

    PrintList(alpha);
    
}

void mainFunction(){
    CreateList();
    PrintList(alpha);
    front600();
    printf("\n");
    printf("Number of nodes in beta = %d",count());
    join();
    sub5();
}


int main(){
    mainFunction();
}


/*    alpha = CreateList();
    PrintList(alpha);
    printf("\n");
    PrintList_alternate(alpha);
    printf("\n");
    beta = front600(alpha);
    PrintList(beta);
    printf("\n");
    count(beta);

front600();
    printf("\n");
    PrintList(alpha);
       printf("\n");
    printf("Number of nodes in beta = %d",count());
    printf("\n");
    print_alternate();
    join();
    sub5();
    
    */