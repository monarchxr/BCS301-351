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

//function to search for a target 
void searchtarget(node *head) {
    int target;

    printf("Enter target (int here) to search for: ");
    scanf("%d", &target);
    
    node *p = head;

    while (p != NULL && p->x != target) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Target not found\n");
        return;
    }

    printf("Target found\n");
    printf("Data in target node:\n");
    printf("Integer: %d\n", p->x);
    printf("String: %s\n", p->y);
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



//function to insert a node after a given target
void insertAfter(node **head) {
    int target;

    printf("Enter target (int here) to insert after: ");
    scanf("%d", &target);

    node *p = *head;
    node *q = NULL;

    
    while (p != NULL && p->x != target) {
        q = p;
        p = p->next;
    }

    if (p != NULL) { 
        node *new = (node*)malloc(sizeof(node));

        printf("Enter number: ");
        scanf("%d", &new->x);

        printf("Enter string (up to 10 characters): ");
        scanf("%s", new->y);

        
        new->next = p->next;
        p->next = new;

    } else {
        printf("Node not found\n");
    }
}


//function to delete node at beginning
void deleteAtBeginning(node **head){
    
    if(*head==NULL)return;

    node* temp = *head;

    *head = (*head)->next;

    free(temp);

    printf("Beginning node deleted\n");
}


//function to delete node at end
void deleteAtEnd(node **head){

    if(*head==NULL)return;

    if((*head)->next == NULL){
        free(*head);
        *head == NULL;
        return;
    }

    node *p = *head;

    while(p->next->next!=NULL){
        p=p->next;
    }

    free(p->next);
    p->next = NULL;

    printf("End node deleted\n");
}

//function to delete the node before a target
void deleteBefore(node** head) {
    int target;

    printf("Enter target (int here) to delete the node before: ");
    scanf("%d", &target);

    if (*head == NULL || (*head)->next == NULL) {
        printf("List has either 0 or 1 element\n");
        return;
    }

    node* prevPrev = NULL;
    node* prev = *head;
    node* curr = (*head)->next;


    while (curr != NULL && curr->x != target) {
        prevPrev = prev;
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Target node not found.\n");
        return;
    }

    if (prevPrev == NULL) {
        *head = (*head)->next;
        free(prev);
    } else {
        
        prevPrev->next = curr;
        free(prev);
    }
}


//function to delete node after a target 
void deleteAfter(node** head) {
    int target;

    printf("Enter target (int here) to delete the node after: ");
    scanf("%d", &target);

    node* p = *head;

    
    while (p != NULL && p->x != target) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Target node not found.\n");
        return;
    }

    if (p->next == NULL) {
        printf("No node exists after the target node.\n");
        return;
    }

    
    node* temp = p->next;
    p->next = temp->next; 
    free(temp); 
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

    insertAfter(&x);

    display(x);

    deleteAtBeginning(&x);

    display(x);

    deleteAtEnd(&x);

    display(x);

    deleteBefore(&x);

    display(x);

    deleteAfter(&x);

    display(x);
    
    free(x);
}