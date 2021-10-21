#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
}Stack;

//Content of the menu
int menu(){
    int ch;
    printf("\nStack Operations\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nYour Choice : ");
    scanf("%d",&ch);
    return (ch);
}
bool isEmpty(Stack *ptr)
{
    if(ptr->top== -1)
        return 1;
    else 
       return 0;
}

bool isFull(Stack *ptr)
{
    if(ptr->top==ptr->size-1)
        return 1;
    else
        return 0;
}

void push(Stack *ptr,int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=value;
        printf("%d Pushed Successfully!\n",value);
    }
}

void pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top--;
        printf("%d popped out of stack\n",val);
    }
}

int peek(Stack *sp,int i)
{
    int arrInd=sp->top-i;
    if (arrInd < 0)
    {
        printf("Invalid Index\n");
        return -1;
    }
    else
        return sp->arr[arrInd];
}

void traverse(Stack *sp)
{
    for (int i = 0; i <=sp->top; i++)
    {
        printf(" %d ",peek(sp,i));
    }
    
}

int main()
{
    Stack* s = (Stack *) malloc(sizeof(Stack));
    
    s->size=10;
    s->top=-1;
    s->arr=(int*)malloc(s->size * sizeof(int));
    int choice, element;
        
    do{
        choice=menu();
        switch(choice){
            case 1:if(isFull(s)) //Push
                     printf("\nStack is Full. Can not add the elements");
                    else{
                        printf("\nEnter the element : ");
                        scanf("%d",&element);
                        push(s,element);
                    
                    }
                    break;
            case 2:if(isEmpty(s)) //Pop
                     printf("\nStack is Empty. Can not add the elements");
                    else{
                        pop(s);
                        
                    }
                    break;
            case 3:if(isEmpty(s)) //Peek
                     printf("\nStack is Empty.");
                    else{
                        int n;
                        printf("\nEnter the position : ");
                        scanf("%d",&n);
                        printf("%d",peek(s,n));
                    
                    }
                    break;        
            case 4:if(isEmpty(s)) //insert at position
                     printf("\nStack is Empty");
                    else{
                        traverse(s);
                    }
                    break;        
            
            case 5:printf("\nBye"); //breaking point
        }
    }while(choice<5);
    return 0;
}
