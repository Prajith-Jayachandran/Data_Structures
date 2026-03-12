#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 50
int stack[MAX],top=-1;

int push(int n){
    int value;
    if(top==MAX-1)
    printf("stack overflow\n");
    else{
        for(int i=0;i<n;i++){
            printf("Enter the element %d: ",i);
            scanf("%d",&value);
            stack[++top]=value;
            printf("%d pushed into the stack\n",value);
        }
    }
    return 0;
}
int pop(){
    if(top==-1)
    printf("Stack underflow\n");
    else{
        printf("Popped elemnet: %d\n",stack[top]);
        top--;
    }
    return 0;
}
int display(){
    if(top==-1)
    printf("stack underflow\n");
    else{
        printf("stack elements: \n");
        for(int i=top;i>=0;i--)
        printf("%d\n",stack[i]);
        printf("\n");
    }
    return 0;
}
int peek(){
    printf("The peek element of the stack is: %d\n",stack[top]);
    return 0;
}

int main(){
    int opt,con=1,n;
    while(con){
        printf("Welcome to the stack implementation(Array_based)\n");
        printf("Enter the options\n1.Push\n2.pop\n3.display\n4.peek\n5.exit\n");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("Enter the no of values (max:50): ");
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
                printf("Invalid option");
                break;
        }
    }
    getch();
    return 0;
}