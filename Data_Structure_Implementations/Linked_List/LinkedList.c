#include<stdio.h>
#include<stdlib.h>


//basic struct for linked list node
struct s{
    int x;
    char y[10];
    struct s *next;
};

typedef struct s node;
node *head;


//function for creating the linked list
node *create_list(){

    int n;
    node *p, *head;

    printf("How many elements to enter?\n");
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        if(i==0){
            head = (node *)malloc(sizeof(node));
            p = head;
        }else{
            p->next = (node *)malloc(sizeof(node));
            p = p->next;        
        }

        printf("Enter number :");
        scanf("%d", &p->x);

        printf("Enter string(upto 10) :");
        scanf("%s", p->y);  //dont need to put & here (because p->y is already a pointer(?))
    }
    p->next = NULL;
    return(head);
}



//function for traversing and displaying each node
void display(node *head){
    int count = 1;
    node *p;

    p=head;

    while(p!=NULL){
        printf("Node %d : %d %s \n", count,p->x,p->y);
        count++;
        p=p->next;
    }
}



//function to insert node at beginning
void insertAtbeginning(node **head){

    node *new = (node *)malloc(sizeof(node));

    printf("What data to insert at beginning?\n");
    printf("Enter number :");
    scanf("%d", &new->x);

    printf("Enter string(upto 10) :");
    scanf("%s", new->y);

    new->next = *head;
    *head = new;
}



//function to insert node at end
void insertAtend(node *head){
    node *new = (node*)malloc(sizeof(node));

    printf("What data to insert at end?\n");
    printf("Enter number :");
    scanf("%d", &new->x);

    printf("Enter string(upto 10) :");
    scanf("%s", new->y);    

    node *p = head;

    while(p->next != NULL){
        p = p->next;
    }

    p->next = new;
    new->next = NULL;
}


//function for inserting node before a given target node
void insertBefore(node **head){
    int target;

    printf("Enter target (int here) to insert before");
    scanf("%d", &target);

    node *new = (node *)malloc(sizeof(node));
    
    printf("What data to insert before target?\n");
    printf("Enter number :");
    scanf("%d", &new->x);

    printf("Enter string(upto 10) :");
    scanf("%s", new->y);

    node *p = *head;

    while(p->next!=NULL && p->next->x != target){
        p = p->next;
    }

    if(p->next!=NULL){
        new->next = p->next;
        p->next = new;
    }else{
        printf("Target node not found");
        free(new);
    }
}


void main(){
    
    node *x = create_list();

    display(x);

    insertAtbeginning(&x);

    display(x);

    insertAtend(x);

    display(x);
    
    insertBefore(&x);

    display(x);

    free(x);
}