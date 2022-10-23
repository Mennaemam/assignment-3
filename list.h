#include <iostream>
struct node
{
    int num;
    node *next=NULL;
    int count;
};
class list
{
public:
    list()
    {
        header=NULL;
        mirror=header;
    }
    node *header;
    node *mirror;
    node *temp;
    void AddNode(int x, int c);
    list link(std::vector<int> &vect, int s);
    void RemoveNode(int x);
    void Print ();
    
    int SumOfNodes();
};

