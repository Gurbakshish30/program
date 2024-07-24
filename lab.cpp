#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class Stack{
public:

Node* top;

Stack()
{top=NULL;}

void push(int data)
{
    Node* temp=new Node(data);

    if(!temp)
    {
        cout<<"stack overflow"<<endl;
        return;
    }
    temp->next=top;
    top=temp;
}

void pop()
{
    if(top == NULL)
    {
        cout<<"empty stack"<<endl;
        return;
    }
    Node* temp=top;
    top=top->next;
    temp->next=NULL;
}
 void display()
 {
     Node* temp=top;
     while(temp != NULL)
     {
         cout<<temp->data<<" ";
         temp=temp->next;
     }
     cout<<endl;
 }
Node* temp1=top;
Node* temp2=temp1->next;

 void Sort()
 {
       //assuming stack is not empty
       if(temp1->next != NULL)
       {
           if(temp2->next != NULL)
           {
                    if(temp1->data > temp2->data )
                    {
                        int rev=temp1->data;
                        temp1->data=temp2->data;
                        temp2->data=rev;
                    }
                    else
                    {
                            temp2=temp2->next;
                            Sort();
                    }

           }
           temp1=temp1->next;
           temp2=temp1->next;
           Sort();
       }
       return;
 }
};







int main()
{
    Stack* stk=new Stack();
    cout<<"enter stack elements (-1 to stop)"<<endl;
    int n;
    while(true)
   {    cin>>n;
    if(n!=-1)
    {
        stk->push(n);
    }
    else break;

   }
   stk->display();
   cout<<"after sorting"<<endl;
   stk->Sort();
   stk->display();

}
