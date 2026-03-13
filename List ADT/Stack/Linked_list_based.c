#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;

int push(int n){
    int value;
    struct node *nn;
    for(int i=1;i<=n;i++){
        nn=(struct node*)malloc(sizeof(struct node));
        if(nn==NULL){
            printf("Heap Overflow! Out of memory\n");
            return 1;
        }
        printf("Enter the element %d: ",i);
        scanf("%d",&value);
        nn->data=value;
        nn->next=top;
        top=nn;
        printf("%d pushed in the stack\n",value);
    }
}
int pop(){
    if(top==NULL){
        printf("Stack underflow!\n");
        return 1;
    }
    struct node *temp=top;
    top=top->next;
    printf("The popped element is: %d\n",temp->data);
    free(temp);
}
int display(){
    if(top==NULL){
        printf("stack underflow\n");
        return 1;
    }
    else{
        struct node *temp=top;
        printf("The stack elememts:");
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
int peek(){
    if(top==NULL){
        printf("Stack underflow\n");
        return 1;
    }
    struct node *temp=top;
    printf("The peek element on the stack is: %d\n",temp->data);
}

int main(){
    int opt,n,con=1;
    while(con){
        printf("Welcome to the stack(Linked list based)!");
        printf("Enter the options:\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");
        scanf("%d",&opt);
        switch(opt){
            case 1:
               printf("Enter the no of nodes in the stack: ");
               scanf("%d",&n);
               push(n);
               break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                con=0;
                break;
            default:
                printf("Invalid option!");
                break;
        }
    }
    getch();
    return 0;
}