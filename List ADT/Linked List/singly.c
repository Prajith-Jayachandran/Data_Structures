#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

int Createlist(int n){
    struct node *nn,*temp;
    int value;
    for(int i=1;i<=n;i++){
        nn=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element %d ",i);
        scanf("%d",&value);
        nn->data=value;
        nn->next = NULL;
        if(head==NULL){
            head=nn;
            temp=head;
        }
        else{
            temp->next=nn;
            temp=nn;
        }
    }
    printf("Linked list created\n");
    return 0;
}

int Displaylist(){
    struct node *temp=head;
    if(head==NULL){
        printf("The list is empty");
        return 1;
    }
    printf("The elements in the list are: ");
    while(temp!=NULL){
    printf("%d-> ",temp->data);
    temp=temp->next;
    }
    printf("NULL\n");
    return 0;
}

int InsertionBegin(){
    struct node *nn;
    int val;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&val);
    nn->data=val;
    nn->next=NULL;
    if(head==NULL){
        head=nn;
        return 1;
    }
        nn->next=head;
        head=nn;
        printf("Inserted at the beginning successfully");
    return 0;
}

int InsertionMiddle(){
    struct node *nn,*temp=head;
    int value,pos;
    printf("Enter the value: ");
    scanf("%d",&value);
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=value;
    nn->next=NULL;
    printf("Enter the position to insert: ");
    scanf("%d",&pos);

    for(int i=1;i<pos-1;i++){
        if(temp==NULL){
            printf("Invalid position");
            free(nn);
            return 1;
        }
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Invalid position");
        free(nn);
        return 1;
    }
    nn->next=temp->next;
    temp->next=nn;
    printf("Inserted at the given position successfully");
    return 0;
}

int InsertionEnd(){
    int value;
    struct node *nn,*temp=head;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&value);
    nn->data=value;
    nn->next=NULL;

    if(head==NULL){
        head=nn;
        return 1;
    }
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=nn;
        temp=nn;
    }
    printf("Inserted at the end successfully");
    return 0;
}
int DeletionBegin(){
    struct node *temp=head;
    if(head==NULL){
        printf("Deletion not possible");
        return 1;
    }
    head=head->next;
    free(temp);
    printf("Deleted at the beginning successfully");
}
int DeletionMiddle(){
    struct node *temp=head,*prev=NULL;
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d",&pos);
    for(int i=1;i<pos;i++){
        if(head==NULL){
            printf("List not created\n");
            return 1;
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }
    if(temp==NULL){
        printf("Deletion not possible at the given position");
        return 1;
    }
    prev->next=temp->next;
    free(temp);
    printf("Deleted at the given position successfully");
    return 0;
}
int DeletionEnd(){
    struct node *temp=head,*prev=NULL;
    if(head==NULL){
        printf("List not created\n");
        return 1;
    }
    else{
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
        printf("Deleted at the end successfully");
    }
}

int main(){
    int n,opt,con=1;
    while(con){
    printf("\nEnter the options:\n1.Create\n2.Display\n3.Insertion(Beginning)\n4.Insertion(Middle)\n5.Insertion(End)\n6.Deletion(Beginning)\n7.Deletion(Middle)\n8.Deletion(End)\n9.exit: ");
    scanf("%d",&opt);
    switch (opt)
    {
    case 1:
        printf("Enter the no of nodes:");
        scanf("%d",&n);
        Createlist(n);
        break;
    case 2:
        Displaylist();
        break;
    case 3:
        InsertionBegin();
        break;
    case 4:
        InsertionMiddle();
        break;
    case 5:
        InsertionEnd();
        break;
    case 6:
        DeletionBegin();
        break;
    case 7:
        DeletionMiddle();
        break;
    case 8:
        DeletionEnd();
        break;
    case 9:
        con=0;
        break;
    default:
        printf("Invalid option to select");
        break;
    }}
    getch();
    return 0;
}