#include "Bidirectional_List.h"

using namespace std;





    Bidirectional_List::Bidirectional_List()
    {
        head = NULL;
        tail = NULL;
    }

    void Bidirectional_List::add(int n)
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
        // while()
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

    a.deleteHead();
    a.print();

    return 0;
}