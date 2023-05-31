// Implementation of Circular Queue
#include<stdio.h>
#include<stdlib.h>

typedef struct QUEUE
{
    int *array;
    int rear; 
    int front;
    int size; 
    int max_size;
} myQueue; 

myQueue* init_Queue(int max_size);
void enQueue(myQueue * q, int x);
int deQueue(myQueue *q);
void show_queue(myQueue *q);

int main()
{
    
int main()
{
    myQueue *q;
    int choice=0, x, max_size;
    scanf("%d", &max_size);
    q = init_Queue(int max_size);
    while(1)
    {   
        scanf("%d", &choice);
        //printf("Choice=%d\n", choice);
        if(choice==0)
        {
               q = init_Queue(int max_size);
        }
        else if(choice==1)
        {     
               // printf("Enter the elements to be inserted \n");
                scanf("%d", &x);
                enQueue(myQueue * q, int x);
             
        }
        else if(choice==2)
        {
                // Delete element
                x = deQueue(myQueue *q);
                printf("%d\n", x);
               
        }
        else if(choice ==3)
        {
            printf("%d\n", q->size);
        }
        else if(choice==4)
        {
                // print queue items
                show_queue(myQueue *q);
                
        }
        else
            break;
    }
    return 0;
}


myQueue* init_Queue(int max_size)
{
    myQueue *q;
    q = malloc(sizeof(myQueue));
    if(q==NULL)
        return NULL;
    q->array = malloc(sizeof(int) * max_size);
    if(q->array ==NULL)
    {
        free(q);
        return NULL;
    }
    q->max_size = max_size;
    q->size = 0;
    q->rear=-1;
    q->front=-1;

    return q;
}

// fill your code here! 
void enQueue(myQueue * q, int x)
{
    if(q->front==-1 && q->rear==-1)   // condition to check queue is empty  
    {  
        q->front=0;  
        q->rear=0;  
        q->array[q->rear]=x;  
    }  
    else if((q->rear+1)%q->max_size==q->front)  // condition to check queue is full  
    {  
        printf("OVERFLOW");  
    }  
    else  
    {  
        q->rear=(q->rear+1)%q->max_size;       // rear is incremented  
        q->array[q->rear]=x;     // assigning a value to the queue at the rear position.  
    }  
}

// fill your code here
int deQueue(myQueue *q)
{
    if((q->front==-1) && (q->rear==-1))  // condition to check queue is empty  
    {  
        return -9999;
    }  
    else if(q->front==q->rear)  
    {  
        return (q->array[q->front]);  
        q->front=-1;  
        q->rear=-1;  
    }   
    else  
    {  
        return (q->array[q->front]); 
        q->front=(q->front+1)%q->max_size;  
    }  
    
}


void show_queue(myQueue *q)
{
    int i=q->front;  
    if(q->front==-1 && q->rear==-1)  
    {  
        printf("\n");  
    }  
    else  
    {  
        while(i<=q->rear)  
        {  
            printf("%d,", q->array[i]);  
            i=(i+1)%q->max_size;  
        }  
    }  
    
    
}
