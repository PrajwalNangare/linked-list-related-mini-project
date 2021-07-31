#include<iostream>
using namespace std;
void create_li();
void display();
void insertfrombegining();
void insertfromend();
void insertfromspecificposition();
int deletefrombegining();
int deletefromend();
int deletefromanyposition();
void reverselinkedlist();
void search();
void sort();
struct Node
{
	public:
	int data;
	struct Node* next;
};
struct Node* first=NULL;
void create_li(int A[],int n)
{
	first=new Node;
	first->data=A[0];
	first->next=NULL;
	struct Node* last=first;
	for(int i=1;i<n;i++)
	{
		struct Node* temp=new Node;
		temp->data=A[i];
		temp->next=NULL;
		last->next=temp;
		last=temp;
	}
}
void display(struct Node* ptr)
{
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<endl;
}
void insertfrombegining(int data)
{
	struct Node* temp=new Node;
    temp->data=data;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
    }
    else
    {
        temp->next=first;
        first=temp;
    }
}
void insertfromend(int data)
{
	struct Node* temp=new Node;
    struct Node* ptr=new Node;
    temp->data=data;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
    }
    else
    {
        ptr=first;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void insertfromspecificposition(int pos,int data)
{
	struct Node* temp=new Node;
    temp->data=data;
    temp->next=NULL;
    if(pos==0)
    {
       temp->next=first;
       first=temp;
    }
    else
    { 
       struct Node* ptr=first;
       for(int i=0;i<pos-1;i++)
       {
           ptr=ptr->next;
       }
       if(ptr!=NULL)
       {
           temp->next=ptr->next;
           ptr->next=temp;
       }
       else 
       {
           cout<<"";
       }
   }
}
int deletefrombegining()
{
	int x=-1;
	struct Node* ptr=new Node;
	if(first==NULL)
	{
		cout<<"Linked list is empty";
		return -1;
	}
	else
	{
		ptr=first;
		first=first->next;
		x=ptr->data;
		delete(ptr);
	}
	return x;
}
int deletefromend()
{
	int x=-1;
	struct Node* ptr=new Node;
	struct Node* temp=new Node;
	if(first==NULL)
	{
		return -1;
	}
	else if(first->next==NULL)
	{
		ptr=first;
		ptr=NULL;
		x=ptr->data;
		delete(ptr);
	}
	else
	{
		ptr=first;
		while(ptr->next!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=NULL;
		x=ptr->data;
		delete(ptr);
	}
	return x;
}
int deletefromanyposition(int pos)
{
	struct Node *p,*q;
	p=first;
	q=NULL;
	int x=-1;
	if(pos==0)
	{
		first=first->next;
		x=p->data;
		delete(p);
		return x;
	}
	else
	{
		for(int i=0;i<pos-1&&p!=NULL;i++)
		{
			q=p;
			p=p->next;
		}
		if(p!=NULL)
		{
			q->next=p->next;
			x=p->data;
			delete(p);
			return x;		
		}
		else
		{
			return x;
		}
	}
}
void reverselinkedlist()
{
	struct Node* forward=first;
	struct Node* last=NULL;
	struct Node* mid=NULL;
	while(forward!=NULL)
	{
		mid=forward;
		forward=forward->next;
		mid->next=last;
		last=mid;
		first=mid;
	}
}
void search(int searchdata)
{
	struct Node* ptr=new Node;
	ptr=first;
	while(ptr!=NULL)
	{
		if(ptr->data==searchdata)
		{
			cout<<"the data is found"<<searchdata<<endl;
			break;
		}
		else
		{
			ptr=ptr->next;
		}
	}
}
void sort()
{
	struct Node* ptr=new Node;
	struct Node* temp=new Node;
	ptr=NULL;
	temp=NULL;
	int search;
	if(first==NULL)
	{
		cout<<"list is empty";
	}
	else
	{
		ptr=first;
		while(ptr!=NULL)
		{
			temp=ptr->next;
			while(temp!=NULL)
			{
				if(ptr->data>temp->data)
				{
					search=ptr->data;
					ptr->data=temp->data;
					temp->data=search;
				}
				temp=temp->next;
			}
			ptr=ptr->next;
		}
		cout<<"after sorting the elements are:";
		while(first!=NULL)
		{
			cout<<first->data<<"->";
			first=first->next;
		}
	}
}
int main()
{
	while(true)
	{
		cout<<"*******Welcome to the linked list project*******"<<endl;
		cout<<"Create linked list"<<endl;
		cout<<"display linked list operation"<<endl;
		cout<<"insert node at the begining position"<<endl;
		cout<<"insert node at the end position"<<endl;
		cout<<"insert node at the specified position"<<endl;
		cout<<"delete node at the begining position"<<endl;
		cout<<"delete node at the end position"<<endl;
		cout<<"delete node at the specified positin"<<endl;
		cout<<"reverse the linked list operation"<<endl;
		cout<<"search a node data in given linked list"<<endl;
		cout<<"sort a linked list operation"<<endl;
		cout<<"Exit"<<endl;
		cout<<"----------------------------"<<endl;
		cout<<"enter your choice is :";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				int n;
	            cout<<"enter the size of given linked list";
	            cin>>n;
				int A[n];
				for(int i=0;i<n;i++)
				{
					cin>>A[i];
				}
				create_li(A,sizeof(A)/sizeof(A[0]));
			}
			break;
			case 2:
			{
				cout<<"Updated created linked list";
				display(first);
			}
			break;
			case 3:
			{
				int data;
				cin>>data;
				insertfrombegining(data);
			}
			break;
			case 4:
			{
				int data;
				cin>>data;
				insertfromend(data);
			}
			break;
			case 5:
			{
				int position,value;
				cin>>position;
				cin>>value;
				insertfromspecificposition(position,value);
			}
			break;
			case 6:
			{
				deletefrombegining();
			}
			break;
			case 7:
			{
				deletefromend();
			}
			break;
			case 8:
			{
				int position;
				cin>>position;
				int x=deletefromanyposition(position);
			    if(x!=-1)
			    {
				  cout<<"this is deleted!!"<<endl;
			    }
			    else
			    {
				  cout<<"Invalid Pos!!"<<endl;
				  continue;
			    }
		    }
            break;
			case 9:
			{
				reverselinkedlist();
			}
			break;
			case 10:
			{
				int searchingdata;
				cin>>searchingdata;
				search(searchingdata);
			}
			break;
			case 11:
			{
				sort();
				cout<<endl;
			}
			break;
			default:
			{
				cout<<"wrong input";
				break;
			}
		}
	}
}
