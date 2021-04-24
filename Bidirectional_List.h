#include <iostream>

struct Node
{
    int data;

    Node *previous;
    Node *next;
};

class Bidirectional_List
{
private:
    Node *head;
    Node *tail;

public:
    Bidirectional_List();

    void add(int n);

    void deleteHead();

    // void deleteTail();

    void deleteNumber(int n);

    void print();
};
