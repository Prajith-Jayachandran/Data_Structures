#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    long int data;
    struct node* next;
    struct node* prev;  
};
struct node *head = NULL;

int Createlist(int n);
int DisplaylistF();
int DisplaylistB();
int InsertBegin();
int InsertMiddle();
int InsertEnd();
int DeleteBegin();
int DeleteMiddle();
int DeleteEnd();
int main(){
    int opt,n,con=1;
    printf("Welcome to the doubly-linked list\n");
    while(con){
        printf("Enter the options\n1.Create\n2.Display(forward)\n3.Display(backward)\n4.Insert(begin)\n5.Insert(Middle)\n6.Insert(End)\n7.Delete(begin)\n8.Delete(Middle)\n9.Delete(End)\n10.Exit: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("Enter the no.of nodes: ");
                scanf("%d",&n);
                Createlist(n);
                break;
            case 2:
                DisplaylistF();
                break;
            case 3:
                DisplaylistB();
                break;
            case 4:
                InsertBegin();
                break;
            case 5:
                InsertMiddle();
                break;
            case 6:
                InsertEnd();
                break;
            case 7:
                DeleteBegin();
                break;
            case 8:
                DeleteMiddle();
                break;
            case 9:
                DeleteEnd();
                break;
            case 10:
                con=0;
                break;
            default:
                printf("Invalid option");
                break;
        }
    }
    getch();
    return 0;
}
int Createlist(int n){
    struct node *nn,*temp;
    long int value;
    for(int i=1;i<=n;i++){
        nn=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element %d: ",i);
        scanf("%ld",&value);
        nn->data=value;
        nn->next=NULL;
        nn->prev=NULL;

        if(head==NULL){
            head=nn;
            temp=head;
        }
        else{
            temp->next=nn;
            nn->prev=temp;
            temp=nn;
        }
    }
    printf("Doubly linked list created!\n");
    return 0;
}

int DisplaylistF(){
    struct node *temp=head;
    if(head==NULL){
        printf("List is empty\n");
        return 1;
    }
    while(temp!=NULL){
        printf("%d <->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int DisplaylistB(){
    struct node *temp=head;
    if(head==NULL){
        printf("List is empty\n");
        return 1;
    }
    while(temp->next!=NULL)
    temp=temp->next;
    while(temp!=NULL){
        printf("%d<->",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
    return 0;
}

int InsertBegin(){
    struct node *nn,*temp=head;
    int value;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to inserted: ");
    scanf("%d",&value);
    nn->data=value;
    nn->prev=NULL;
    nn->next=NULL;
    
    if(head==NULL){
        head=nn;
        return 1;
    }
    else{
        nn->next=temp;
        temp->prev=nn;
        head=nn;
    }
    printf("Inserted the element successfully at the beginning!\n");
    return 0;
}

int InsertMiddle(){
    struct node *nn,*temp_2=head,*temp_1=NULL;
    int value,n;
    printf("Enter the value and the positon to insert: ");
    scanf("%d%d",&value,&n);
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=value;
    nn->prev=NULL;
    nn->next=NULL;

    for(int i=1;i<n-1;i++){
        if(temp_2==NULL){
            printf("Invalid position");
            free(nn);
            return 1;
        }
        temp_1=temp_2;
        temp_2=temp_2->next;
    }
    if(temp_1==NULL||temp_2==NULL){
        printf("Invalid position");
        return 0;
    }
    temp_2->prev=nn;
    nn->next=temp_2;
    nn->prev=temp_1;
    temp_1->next=nn;

    printf("Inserted at the middle succesfully!\n");
    return 0;
}

int InsertEnd(){
    struct node *nn,*temp=head;
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=value;
    nn->next=NULL;
    nn->prev=NULL;
    if(head==NULL){
        head=nn;
        return 1;
    }
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        nn->prev=temp;
        temp->next=nn;
        temp=nn;
    }
}

int DeleteBegin(){
    struct node *temp=head;
    if(head==NULL){
        printf("List is empty\n");
        return 1;
    }
    head=temp->next;
    if(head!=NULL)
        head->prev=NULL;
    free(temp);
    printf("Deleted the first element successfully!\n");
    return 0;
}
int DeleteMiddle(){
    int pos;
    printf("Enter the position to be deleted: ");
    scanf("%d",&pos);
    
    if(pos==1){
        struct node *temp=head;
        head=head->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        free(temp);
        printf("Deleted at the position %d sucessfully");
        return 1;    
    }
    struct node *curr=head;
    for(int i=1;i<pos;i++){
        if(curr==NULL){
            printf("Invalid position\n");
            return 1;
        }
        curr=curr->next;
    }
    if(curr==NULL){
        printf("Invalid position\n");
        return 1;
    }
    if(curr->next!=NULL)
    curr->next->prev=curr->prev;
    if(curr->prev!=NULL)
    curr->prev->next=curr->next;

    printf("Deleted at the given positon %d successfully!");
    return 0;
}

int DeleteEnd(){
    struct node *temp=head;
    if(temp==NULL){
        printf("list is empty\n");
        return 1;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->prev!=NULL)
    temp->prev->next=NULL;
    if(temp->prev!=NULL)
    temp->prev=NULL;
    free(temp);
    printf("Deleted at the end successfully\n");
    return 0;
}
