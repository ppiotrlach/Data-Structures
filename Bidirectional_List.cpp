#include "Bidirectional_List.h"

using namespace std;

//TODO DELETE AFTER, DELETE BEFORE NODE


Bidirectional_List::Bidirectional_List()
{
    head = NULL;
    tail = NULL;
}

Node *Bidirectional_List::findNode(int n)
{
    if (head == NULL)
    {
        cout << "there is empty list" << endl;
        return NULL;
    }
    if( tail->data ==n){
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

void Bidirectional_List::addAfter(int nodeValue, int newNodeValue)
{
    Node *temp = findNode(nodeValue);
    if (temp != NULL){
        
        Node* addedNode = new Node;
        
        addedNode->data = newNodeValue;
        addedNode->previous = temp;
        addedNode->next = temp ->next;
        temp->next = addedNode;

        if(temp == tail){
            tail = addedNode;
        }
        
    }
}

void Bidirectional_List::deleteAfter(int nodeValue){
    Node *temp = findNode(nodeValue);
    if(temp==tail){
        cout<<"there is nothing after tail"<<endl;
        return;
    }
    if (temp != NULL){
        if(temp->next == tail){
            tail = temp;
            tail->next = NULL;
            return;
        }
        Node *temp2 = temp;
        temp2= temp2->next->next;
        temp->next = temp2;
        temp -> next = NULL;
    }
}

void Bidirectional_List::deleteBefore(int nodeValue){
    Node *temp = findNode(nodeValue);
    if(temp==head){
        cout<<"there is nothing before head"<<endl;
        return;
    }
    if(temp->previous==head){
        head = head->next;
        head->previous = NULL;
        return;
    }
    if (temp != NULL){
        Node *temp2 = temp;
        
    }
}

void Bidirectional_List::addBefore(int nodeValue, int newNodeValue)
{
    Node *temp = findNode(nodeValue);
    if (temp != NULL){
        Node* addedNode = new Node;
        
        addedNode->data = newNodeValue;
        addedNode->next = temp;
        addedNode->previous = temp ->previous;
        temp->previous = addedNode;

        if(temp == head){
            head = addedNode;
        }
    }
}

void Bidirectional_List::add(int n) //adds a number behind the tail
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
}

void Bidirectional_List::deleteHead()
{
    if (head == NULL)
    {
        cout << "there is empty list" << endl;
        return;
    }

    deleteNumber(head->data); //deleteNumber method looks for the item to delete from head - therefore it can be done this way
}

// void Bidirectional_List::deleteTail(){

//     if(head == NULL){
//         cout<<"there is empty list"<<endl;
//         return;
//     }
//     Node* temp;
//     temp = tail;
//     tail = tail->previous;
//     tail->next = NULL;
//     free(temp);
//     cout << "number deleted from tail"<<endl;
//     return;
// }

void Bidirectional_List::deleteNumber(int n)
{ //removes the first number from head with provided value

    if (head == NULL)
    {
        cout << "there is empty list" << endl;
        return;
    }

    Node *temp = head;
    Node *temp2;

    if (head->data == n)
    {
        if (head->next == NULL)
        {
            head = NULL;
            free(head);
        }
        temp = head;
        head = head->next;
        head->previous = NULL;
        free(temp);
        cout << "number " << n << " deleted from head" << endl;
        return;
    }
    // else if(tail->data ==n){
    //     temp = tail;
    //     tail = tail->previous;
    //     tail->next = NULL;
    //     free(temp);
    //     cout << "number " << n << " deleted from tail"<<endl;
    //     return;
    // }
    else
    {
        while (temp->next->next != NULL)
        {
            if (temp->next->data == n)
            {
                free(temp->next);

                temp2 = temp->next->next;
                temp->next = temp2;
                temp2->previous = temp;

                cout << "number " << n << " deleted" << endl;
                return;
            }
            temp = temp->next;
        }
    }

    cout << "there is no number " << n << endl;
}

void Bidirectional_List::print()
{
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }

    // cout << "head = " << head->data << " tail = " << tail->data << endl;

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

int main()
{
    Bidirectional_List a;

    a.deleteHead();

    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);
    a.add(6);
    a.add(7);
    a.print();

    cout<< "tail = "<<a.getTail()->data <<endl;
    a.addAfter(7,77);
    cout<< "tail = "<<a.getTail()->data <<endl;

    a.print();


    cout<< "head = "<<a.getHead()->data <<endl;
    a.addBefore(1,11);
    cout<< "head = "<<a.getHead()->data <<endl;


    a.print();


    

    return 0;
}