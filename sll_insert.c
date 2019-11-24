#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE insert_front(int item,NODE head);
NODE insert_end(NODE head,int item);
NODE insert_pos(NODE head,int item,int pos);
NODE getnode();
void display(NODE head);
NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf("memory could not be allocated\n");
		exit(0);
	}
}
NODE insert_front(int item,NODE head)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
}
NODE insert_end(NODE head,int item)
{
	NODE p,q;
	q=getnode();
	q->data=item;
	q->next=NULL;
	if(head==NULL)
		return q;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	return head;
	
}
NODE insert_pos(NODE head,int item,int pos)
{
	NODE curr,prev,newn;
	prev=NULL;
	int count=1;
	newn=getnode();
	newn->data=item;
	newn->next=NULL;
	if(head==NULL)
	{
		if(pos==1)
			return newn;
		else
		{
			printf("Invalid position\n");
			return head;
		}
	}
	if(pos==1)
	{
		newn->next=head;
		head=newn;
		return head;
	}
	else
	{
		curr=head;
		while(curr!=NULL && count!=pos)
		{
			prev=curr;
			curr=curr->next;
			count++;
		}
		if(count==pos)
		{
			prev->next=newn;
			newn->next=curr;
			return head;
		}
	}
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("list is empty\n");
		exit(0);
	}
	p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
int main()
{
	NODE head=NULL;
	int ch,item,pos;
	printf("enter\n1.insert front\n2.insert at a position\n3.insert end\n4.display\n-1.exit\n");
	scanf("%d",&ch);
	while(ch!=-1)
	{
		switch(ch)
		{
			case 1:printf("enter the item\n");
				scanf("%d",&item);
				head=insert_front(item,head);
				break;
			case 2:printf("enter the item\n");
				scanf("%d",&item);
				printf("enter the position\n");
				scanf("%d",&pos);
				head=insert_pos(head,item,pos);
				break;
			case 3:printf("enter the item\n");
				scanf("%d",&item);
				head=insert_end(head,item);
				break;
			case 4:display(head);
				break;
			default:printf("invalid input\n");
		}
		printf("enter next choice or -1 to exit\n");
		scanf("%d",&ch);
	}
	return 0;
}