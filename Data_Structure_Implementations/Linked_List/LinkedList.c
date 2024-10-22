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
        scanf("%s", p->y);  //dont need to put & here (for some reason idk)
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

int main(){
    
    display(create_list());

}