#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;


struct node
{
	string name, number;
	string address, email;
	node *next;	
};


node *head=NULL, *newnode, *temp;
int len=0;


//Function to create the node
void Create_node()
{
	newnode= new node;
	cout<<"Enter Name: "<<endl;
	cin>>newnode->name;
	cout<<"Enter Number: "<<endl;
	cin>>newnode->number;
	cout<<"Enter Address: "<<endl;
	cin>>newnode->address;
	cout<<"Enter E-mail: "<<endl;
	cin>>newnode->email;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		temp=newnode;
	}
	else
	{
		temp->next=newnode;
		temp=newnode;
	}
}


//Function to display all the elemnets of the linked list or all the contents of te phone directory
void display()
{
	if(head==NULL)
	{
		cout<<"Contact list is empty"<<endl;
	}
	else
	{
		node *trav=head;
		while(trav!= NULL)
		{
			cout<<"Full Name: "<<trav->name<<endl;
			cout<<"Phone Number: "<<trav->number<<endl;
			cout<<"Address: "<<trav->address<<endl;
			cout<<"Email: "<<trav->email<<endl;
			temp=trav->next;
			len++;
		}
		cout<<"Total contacts in the list: "<<len<<endl;
	}
}


//Function to search a contact on the basis of the given name, phone number, address or email
void search_contact()
{
	node *search_node=head;
	string srch;
	int count=1;
	cout<<"Entered your desired contact you want to search: "<<endl;
	cin>>srch;
	bool found=true;
	if(head==NULL)
	{
		cout<<"List is Empty"<<endl;
	}
	else
	{
		while(search_node!=NULL)
		{
			if(srch==search_node->name || srch == search_node->number || srch == search_node->address || srch == search_node->email)
			{
				cout<<"Full Name: "<<search_node->name<<endl;
				cout<<"Phone Number: "<<search_node->number<<endl;
				cout<<"Address: "<<search_node->address<<endl;
				cout<<"Email: "<<search_node->email<<endl;
				found=true;
				break;
			}
			search_node= search_node->next;
			count++;
		}
	}
	if(found==true)
	{
		cout<<"Index of the contact= "<<count<<endl;
	}
	else
	{
		cout<<"Desired contact not found"<<endl;
	}
}


//Function to delete a contact from the given postion
void deletion_at_given_Pos()
{
	int position;
	node *next_node;
	temp=head;
	cout<<"Enter our desired position where you want to delete contact"<<endl;
	cin>>position;
	if(head==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else if(position>len)
	{
		cout<<"Invalid Position"<<endl;
	}
	else if(position==0)
	{
		temp=head;
		head=head->next;
		delete temp;
		cout<<"Contact has been deleted"<<endl;
	}
	else
	{
		for(int i=1; i<position; i++)
		{
			temp=temp->next;
		}
		next_node=temp->next;
		temp->next=next_node->next;
		delete next_node;
		cout<<"Contact has been deleted"<<endl;
	}
}


//Function to delete the contacts from the directory all at once
void clear_all()
{
	if(head==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		temp=head;
		while(head!=NULL)
		{
			head=head->next;
			delete temp;
		}
		cout<<"Contact List has been DELETED"<<endl;
	}
}


//Function to show the menu
void menu()
{
	cout<<"Select the option from the given MENU"<<endl;
	cout<<"1. Add contact"<<endl;
	cout<<"2. Display all contacts"<<endl;
	cout<<"3. Search Contact"<<endl;
	cout<<"4. Delete Contact"<<endl;
	cout<<"5. Clear all List"<<endl;
}


int main()
{
	cout<<"***********************"<<endl;
	cout<<"TELEPHONE DIRECTORY"<<endl;
	cout<<"***********************"<<endl;
	int op;
	while(true)
	{
		menu();
		cin>>op;
		switch(op)
		{
			case 1:
				Create_node();
				break;
			case 2:
				len=0;
				display();
				break;
			case 3:
				search_contact();
				break;
			case 4:
				deletion_at_given_Pos();
				break;
			case 5:
				clear_all();
				break;
			default:
				cout<<"Invalid Option"<<endl;
		}
	}
	return 0;
}
