#include <iostream>

struct Node
{
    int data;

    Node *previous;
    Node *next;

    ~Node(){
        delete previous;
        delete next;
    }
};

class Bidirectional_List
{
private:
    Node *head;
    Node *tail;

public:
    Bidirectional_List();

    Node* getHead(){
        return head;
    }

    Node* getTail(){
        return tail;
    }

    Node* findNode(int data);

    //n = number, data of Node

    void addAfter(int nodeValue, int newNodeValue);

    void addBefore(int nodeValue, int newNodeValue);

    void deleteAfter(int nodeValue);

    void deleteBefore(int nodeValue);

    void add(int n);

    void deleteHead();

    // void deleteTail();

    void deleteNumber(int n);

    void print();
};
