#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

struct node* creatnode();
void creatlink(struct node** head);
void display(struct node* head);

struct node* creatnode()
{
	struct node* creatnode=NULL;
	creatnode=(struct node*)malloc(sizeof(struct node));
	if(creatnode==NULL)
	{
		printf("Memory not allocate....!\n");
	}
	else
	{
		printf("\nEnter the data:\n");
		scanf("%d",&creatnode->data);
		creatnode->next=NULL;
		creatnode->prev=NULL;
		return creatnode;
	}
}

void creatlink(struct node** head)
{
	struct node* p=*head;
	struct node* temp=NULL;
	temp=creatnode();
	
		if(*head==NULL)
		{
			*head=temp;
		}
		else
		{
			while(p->next !=  NULL)
			{
				p=p->next;
			}
			p->next=temp;
			temp->prev=p;
		}
	
}

void display(struct node* head)
{
	struct node* p=head;
	while(p->next != NULL)
	{
		printf("%d-->",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
}

void armstronglink(struct node* head)
{
	int p,n,rem,i;
	printf("\nThe Armstrong numbers are :\n");
	while(head != NULL)
	{
		int count=0,c=0;
		p=n=head->data;
		while(p != 0)
		{
			p=p/10;
			count++;
		}
	
		while(n != 0)
		{
			int sum=1;
			rem=n%10;
			for(i=0;i<count;i++)
			{
				sum=sum*rem;
			}
			c=c+sum;
			n=n/10;
		}
		
		if(c==head->data)
		printf("%d\t",head->data);
		
		head=head->next;
	}
}


void main()
{
	int choice;
	struct node* first=NULL;
	do
	{
		printf("\n***********LINK LIST*************\n");
		printf("1.creatlinklisted\n2.display\n3.Armstrong numbers\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				creatlink(&first);
				printf("\nLink list created successfully...!\n");
				break;
			case 2:
				printf("\nGiven linklsted is:\n");
				display(first);
				break;
			case 3:
				armstronglink(first);
				break;
		}
	}while(choice != 4);
}