#include <stdio.h>
#define MAX 100

int arr[MAX];
int size = 0;

void create()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n > MAX)
    {
        printf("Exceeds maximum size\n");
        return;
    }
    size = n;
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void display()
{
    if(size == 0)
        printf("List is empty\n");
    else
    {
        for(int i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

void insert()
{
    int pos, val;
    printf("Enter position and value: ");
    scanf("%d%d", &pos, &val);
    if(size >= MAX)
        printf("List is full\n");
    else if(pos < 0 || pos > size)
        printf("Invalid position\n");
    else
    {
        for(int i = size; i > pos; i--)
            arr[i] = arr[i-1];
        arr[pos] = val;
        size++;
    }
}

void search()
{
    int val, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &val);
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == val)
        {
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
    }
    if(found == 0)
        printf("Element not found\n");
}

void delete_pos()
{
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if(size == 0)
        printf("List is empty\n");
    else if(pos < 0 || pos >= size)
        printf("Invalid position\n");
    else
    {
        for(int i = pos; i < size-1; i++)
            arr[i] = arr[i+1];
        size--;
    }
}

void delete_val()
{
    int val, pos = -1;
    printf("Enter value to delete: ");
    scanf("%d", &val);
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == val)
        {
            pos = i;
            break;
        }
    }
    if(pos == -1)
        printf("Element not found\n");
    else
    {
        for(int i = pos; i < size-1; i++)
            arr[i] = arr[i+1];
        size--;
    }
}

int main()
{
    int choice, del_choice;
    while(1)
    {
        printf("\n1.Create\n2.Display\n3.Insert\n4.Search\n5.Delete\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                search();
                break;
            case 5:
                printf("1.Delete by Position\n2.Delete by Value\n");
                scanf("%d", &del_choice);
                if(del_choice == 1)
                    delete_pos();
                else if(del_choice == 2)
                    delete_val();
                else
                    printf("Invalid choice\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}