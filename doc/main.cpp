#include <iostream>
#include <memory>
using namespace std;


struct Node {
    Node(int _datum):next(nullptr),datum(_datum)
    {

    }

    ~Node()
    {
        delete next;
    }

    Node* next;
    int datum;
};

struct simpleList {
    simpleList():head(nullptr){}
    ~simpleList()
    {
        if(head != nullptr)
        {
            delete head;
        }
    }
    void append(int datum)
    {
        if(head == nullptr){
            head = new Node(datum);
            return;
        }
        Node* w = head;
        while(w->next != nullptr)
        {
            w = w->next;
        }
        w->next = new Node(datum);
    }
    void erase(int idx)
    {
      
    }
    Node* head;
};

int main(int argc, const char *argv[])
{
    simpleList l;
    l.append(2);
    cout << "Hello Valgrind World" << endl;    
    return 0;
}
