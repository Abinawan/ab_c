#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};

struct node *head=NULL;

struct node *temp= NULL;
void ins_beg(int data)
{
	struct node *newnode;
	newnode= ( struct node*)malloc(sizeof (struct node)); 
	newnode->info=data;
	

	
		newnode->next=head;
		head=newnode;
	
    printf("\nInserted data: %d", data);
}
void ins_end(int data)
{
	struct node *newnode;
	struct node *ptr= NULL;
	newnode= ( struct node*)malloc(sizeof (struct node)); 
	newnode->info=data;
	newnode->next=NULL;
	
	
	
		ptr=head;
		while(ptr->next !=NULL)
		{
			ptr=ptr->next;
			
		}
		
		ptr->next=newnode;
	
	printf("\nInserted data: %d", data);
}
void ins_pos(int data)
{struct node *newnode;
	struct node *ptr= NULL;
	int pos, i;
	newnode= ( struct node*)malloc(sizeof (struct node));
	newnode->info=data;
	printf("\nEnter the position of node: ");
	scanf("%d", &pos);
	ptr=head;
	for(i=0; i<pos-1; i++)
	{
	
		if(ptr==NULL)
		{
			printf("\nPosition not found");
			exit(0);		}
		
		
			ptr=ptr->next;
		
	}
	newnode->next=ptr->next;
	        ptr->next=newnode;
	
}
void display()
{struct node *newnode;
	struct node *ptr= NULL;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		printf("\nElements of list:");
		while(ptr!=NULL)
		{
			printf("\n%d", ptr->info);
			ptr=ptr->next;
		}
	}
}
void del_beg()
{
	struct node *ptr;
	ptr=head;
	if(head==NULL)
	{
		printf("\nLIst is empty");
		exit(0);
	}
	else
	{
		head=head->next;
		
	}
	printf("\nDeleted element: %d",ptr->info);
	free(ptr);
}
void del_end()
{
    
	struct node *ptr;
	ptr=head;
	if(head==NULL)
	{
		printf("\nLIst is empty");
		exit(0);
	}
	if(head->next==NULL)
		{
			ptr=head;
			head=NULL;
			printf("\nDeleted element= %d", ptr->info);
			free(ptr);
		}
	else
		{
			ptr=head;
			while(ptr->next!=NULL)
			{
				temp=ptr;
				ptr=ptr->next;
				
			}
			temp->next=NULL;
			printf("\nDeleted element= %d", ptr->info);
			free(ptr);
		}
}
void del_pos()
{struct node *newnode;
	struct node *ptr= NULL;
	int pos, i;
	if(head==NULL)
	{
		printf("\nList is empty");
		//exit(0);
	}
	else
	{
		printf("\nEnter the position: ");
		scanf("%d", &pos);
		if(pos==0)
		{
			ptr=head;
			head=head->next;
			printf("\nDeleted element: %d", ptr->info);
			free(ptr);
		}
		else
		{
			ptr=head;
			for(i=0; i<pos; i++)
			{
				temp=ptr;
				ptr=ptr->next;
				if(ptr==NULL)
				{
					printf("\nPosition not found");
				}
				else
				{
					temp->next=ptr->next;
					free(ptr);
				}
			}
		}
	}
}
int main()
{
	ins_beg(6);
	ins_end(9);
	ins_pos(10);
	display();
	del_beg();
	del_end();
	del_pos();
	return (0);
}
