#include<stdio.h>
#include<malloc.h>
typedef struct record{
	int priority;
	int info;
	struct record *next;
};
typedef struct record list;
list *start = NULL;
//TO INSERT BASED ON PRIORITY
void push(int value,int priority)
{
	list *temp,*q;
	temp =(list*)malloc(sizeof(list));
	temp->info = value;
	temp->priority = priority;
	if(start == NULL || priority > start->priority )
	{
		temp->next = start;
		start = temp;
	}
	else
	{
		q = start;
        while(q->next != NULL && q->next->priority >= priority )
            q=q->next;
            temp->next = q->next;
            q->next = temp;
	}
}
//TO DELETE ELEMENT WITH TOPMOST PRIORITY
void pop()
{
	list *temp;
	if(start == NULL)
		printf("Queue Underflow\n");
	else
	{
		temp = start;
		printf("Deleted item is %d\n",temp->info);
		start = start->next;
		free(temp);
	}
}
//TO PRINT THE QUEUE.
void display()
{
	list *ptr;
	ptr = start;
	if(start == NULL)
		printf("Queue is empty\n");
	else
	{
		printf("Queue is :\n");
		printf("Priority    --   Value\n");
		while(ptr != NULL)
		{
			printf("%5d        %5d\n",ptr->priority,ptr->info);
			ptr = ptr->next;
		}
	}
}
//MAINFUNC
int main()
{
	int choice,value,priority;
	do
	{
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Exit");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Input the value of the element to be added in the queue : ");
				scanf("%d",&value);
				printf("Enter its priority : ");
				scanf("%d",&priority);
				push(value,priority);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
             case 4:
			    exit(0);
                break;
            default :
				printf("Wrong choice\n");
		}
	}while(choice!=4);
	return 0;
}
