#include "Bidirectional_List.h"

using namespace std;


Bidirectional_List::Bidirectional_List()
{
    head = NULL;
    tail = NULL;
}

void Bidirectional_List::add(int n) //adds a number behind the tail
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = NULL;

    if (head == NULL) //if its first added element
    {
        head = temp;
        tail = temp;
    }
    else //if its not first element
    {
        //assigning the right pointers
        tail->next = temp;
        temp->previous = tail;
        tail = tail->next;

        temp = head;
    }
}

Node *Bidirectional_List::findNode(int n) //method return the first found node from head with provided number 
{
    if (head == NULL)
    {
        cout << "there is empty list" << endl;
        return NULL;
    }
    if (tail->data == n)
    {
        return tail;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == n)
        {
            return temp;
        }
        temp = temp->next;
    }

    cout << "there is no number " << n << endl;
    return NULL;
}

void Bidirectional_List::addAfter(int nodeValue, int newNodeValue) //method adds number newNodeValue after provided nodeValue
{
    Node *temp = findNode(nodeValue); //in first order find interesting node
    if (temp != NULL)   
    {
        
        Node *addedNode = new Node;

        //playing with pointers, assigning the right pointers
        addedNode->data = newNodeValue;
        addedNode->previous = temp;
        addedNode->next = temp->next;
        temp->next = addedNode;

        if (temp == tail) //check if added node is a tail
        {
            tail = addedNode;
        }
    }
}


void Bidirectional_List::addBefore(int nodeValue, int newNodeValue) //method adds number newNodeValue before provided nodeValue
{
    Node *temp = findNode(nodeValue); //in first order find interesting node
    if (temp != NULL)
    {
        Node *addedNode = new Node;

        //playing with pointers, assigning the right pointers
        addedNode->data = newNodeValue;
        addedNode->next = temp;
        addedNode->previous = temp->previous;
        temp->previous = addedNode;

        if (temp == head) //check if added node is a head
        {
            head = addedNode;
        }
    }
}

void Bidirectional_List::deleteAfter(int nodeValue) //method deletes first number after provided nodeValue from head
{
    Node *temp = findNode(nodeValue); //in first order find interesting node
    if (temp == tail) //check if given number is not a tail
    {
        cout << "there is nothing after tail" << endl;
        return;
    }
    if (temp != NULL)
    {
        if (temp->next == tail)
        {
            tail = temp;
            tail->next = NULL;
            free(tail->next);
            return;
        }
        Node *temp2 = temp;
        temp2 = temp2->next->next;
        free(temp->next);
        temp->next = temp2;
        temp2->previous = temp;
    }
}

void Bidirectional_List::deleteBefore(int nodeValue) //method deletes first number before provided nodeValue from head
{
    Node *temp = findNode(nodeValue);
    if (temp == head)
    {
        cout << "there is nothing before head" << endl;
        return;
    }
    if (temp->previous == head)
    {
        head = head->next;
        head->previous = NULL;
        free(head->previous);
        return;
    }
    if (temp != NULL)
    {
        Node *temp2 = temp;
        temp2 = temp2->previous->previous;
        free(temp->previous);
        temp->previous = temp2;
        temp2->next = temp;
    }
}


void Bidirectional_List::deleteHead()
{
    if (head == NULL)
    {
        cout << "there is empty list" << endl;
        return;
    }
    if (head == tail)
    {
        head = NULL;
        free(head);
        return;
    }
    Node *temp;
    temp = head;
    head = head->next;
    head->previous = NULL;
    free(temp);
    cout << "number deleted from head" << endl;
    return;

    
}

void Bidirectional_List::deleteTail()
{

    if (head == NULL)
    {
        cout << "there is empty list" << endl;
        return;
    }
    if (head == tail)
    {
        head = NULL;
        free(head);
        return;
    }
    Node *temp;
    temp = tail;
    tail = tail->previous;
    tail->next = NULL;
    free(temp);
    cout << "number deleted from tail" << endl;
    return;
}

void Bidirectional_List::deleteNumber(int n)
{ //removes the first number from head with provided value

    Node *temp = findNode(n); //in first order find interesting node
    if(temp==NULL){
        return;
    }
    else if (temp == tail) //check if given number is not a tail
    {
        deleteTail();
        return;
    }
    else if(temp == head){ //check if given number is not a head
        deleteHead();
        return;
    }
    else if (temp != NULL)
    {
        Node *temp2 = temp;
        temp2 = temp2->previous;
        temp = temp ->next;
        free(temp2->next);
        temp2->next = temp;
        temp ->previous = temp2;
    }

    cout << "deleted number " <<n<<endl;
}

void Bidirectional_List::print() //methods print list from the head
{
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    Node *temp = head;

    cout << "NULL <> ";
    while (temp != NULL)
    {
        cout << temp->data << " <> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    delete temp;
}

void Bidirectional_List::printFromTail() //methods print list from the tail (reverse to print method)
{
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }

    Node *temp = tail;

    cout << "NULL <> ";
    while (temp != NULL)
    {
        cout << temp->data << " <> ";
        temp = temp->previous;
    }
    cout << "NULL" << endl;
    delete temp;
}