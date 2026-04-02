#include<stdio.h>
#include<conio.h>
#define Max 100

int queue[Max];
int front=-1,rear=-1;

int is_Full(){
    if((front==rear+1)||(front==0 && rear==Max-1))
    return 1;
    return 0;
}
int is_Empty(){
    if(front==-1)
    return 1;
    return 0;
}
int enqueue(int element){
    if(is_Full()){
        printf("Queue is Full!\n");
        return 1;
    }
    else{
        if(front==-1)
        front=0;
        rear=(rear+1)%Max;
        queue[rear]=element;
        printf("Inserted->%d\n",element);
    }
}
int dequeue(){
    int element;
    if(is_Empty()){
        printf("Queue is empty!\n");
        return (-1);
    }
    else{
        element=queue[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else
        front=(front+1)%Max;
        return (element);
    }
}
int display(){
  int i;
  if (is_Empty()) {
    printf("Queue is empty!\n");
  } else {
    printf("Front index -> %d\n", front);
    printf("Items -> ");
    
    // Loop from front to rear circularly
    for (i = front; i != rear; i = (i + 1) % Max) {
      printf("%d ", queue[i]);
    }
    
    printf("%d\n", queue[i]);
    printf("Rear index -> %d\n", rear);
  }
}
int peek(){
    if(is_Empty()){
        printf("Queue is empty!\n");
        return -1;
    }
    return queue[front];
}

int main(){
    int opt,value,n,con=1;
    printf("Welcome to the queue(array based)");
    while(con){
        printf("Enter the options\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\n");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            printf("Enter the no of elements(max 100): ");\
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                printf("Enter the element %d",i);
                scanf("%d",&value);
                enqueue(value);
            }
            break;
        case 2:
            dequeue();
            printf("The dequeued element is: %d",dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            printf("The peek element is: %d",peek());
            break;
        case 5:
            con=0;
            break;
        default:
            printf("Invalid option");
            break;
        }
    }
}