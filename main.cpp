#include <iostream>
#include <algorithm>
#include <vector>
#include "list.h"
using namespace std;

void list::AddNode(int x, int c)
{
    node *node1= new node;
    node1->num=x;
    node1->count = c;
    if(header==NULL)
    {
        header=node1;
    }
    else
    {
        mirror=header;
        while(mirror->next !=NULL)
        {
            mirror=mirror->next;
        }
       
        mirror->next=node1;
        node1->next=NULL;
    }
}
list list::link(vector<int> &vect, int s)
{
    int c=1;
    list l2;
    sort(vect.begin(),vect.end());
    int i=0;
    while(i!=vect.size())
    {
        while(vect[i]==vect[i+1])
        {
            c++;
            i++;
        }
        AddNode(vect[i], c);
        
        i++;
    }
    
        return l2;
}

void list::RemoveNode(int x)
{
    node *q;
    q=header;
    node *prev = nullptr;
    while((q->num!=x)&&(q!=NULL))
    {
        prev = q;
        q=q->next;
    }
    if(q==NULL)
    {
        cout<<"number not found"<<endl;
    }
    else
    {
        prev->next = q->next;
        delete q;
    }
}
void list::Print()
{
    mirror=header;
    if (header == NULL)
        cout << "nothing here" << endl;
    while(mirror!=NULL)
    {
        cout<<mirror->num<<endl;
        mirror=mirror->next;
    }
}
int list:: SumOfNodes()
{
    int sum=0;
    if(header->next==NULL)
    {
        return header->num;
    }
    else
    {
        while(mirror!=NULL)
        {
            sum=sum+mirror->num;
            mirror=mirror->next;
        }
    }
    cout<<"the sum of all nodes is: "<<'\t'<<sum<<endl;
    return sum;

}

void insertAfter(int firstvalue, int secondvalue, vector<int> &vect)
{
    for(int i=0; i<vect.size(); i++)
    {
        if(vect[i]==firstvalue)
        {
            vect.insert(vect.begin()+i+1,secondvalue);
        }
        
    }
    for(int i=0;i<vect.size();i++)
    {
        cout<<vect[i]<<endl;
    }
}
int main()
{
    node nodes;
    list l1;
    int size;
    cout<<"enter the size of the vector"<<endl;
    cin>>size;
    int integers;
    cout<<"enter the integers"<<endl;
    vector<int> V;
    for(int i=0; i<size;i++)
    {
            cin>>integers;
            V.push_back(integers);
   }
  cout<<"decide the first number"<<endl;
  int firstnum;
  cin>>firstnum;
   cout<<"decide the second number"<<endl;
  int secondnum;
   cin>>secondnum;

insertAfter(firstnum,secondnum,V);
    l1.link(V, size);
    l1.Print();
   l1.SumOfNodes();
}
