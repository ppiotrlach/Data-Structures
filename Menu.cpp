#include <iostream>

#include "Bidirectional_List.h"
#include "Dynamic_Array.h"
#include "Heap.h" 


using namespace std;

static int getInputFromUser()
{

    bool isInputCorrect = false;
    bool minus = false;
    string input;

    while (!isInputCorrect)
    {
        isInputCorrect = true;
        cin >> input;
        for (char const &c : input)
        {
            if (std::isdigit(c) == 0)
            {
                if(c == '-' && !minus){
                    minus = true;
                }
                else{
                    isInputCorrect = false;
                    cout << "incorrect input, try again" << endl
                    << ">";
                break;
                }
                
            }
        }
    }

    return stoi(input); //parse string to int
}

static void mainMenu()
{
    cout << endl;
    cout << "SELECT THE NUMBER OF THE DATA STRUCTURE YOU ARE INTERESTED IN" << endl;
    cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl
         << endl;

    cout << "1. Dynamic array" << endl;
    cout << "2. Bidirectional List" << endl;
    cout << "3. Heap" << endl;
    cout << "4. End the program" << endl;
    cout << endl;
}

static void arrayMenu()
{
    cout << endl;
    cout << "SELECT THE NUMBER OF OPERATION ON ARRAY" << endl;
    cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl
         << endl;

    cout << "1. Append number" << endl;
    cout << "2. Append number in a specific position " << endl;
    cout << "3. Insert number in a specific position (replace the older one)" << endl;
    cout << "4. Delete the first number of array" << endl;
    cout << "5. Delete the last number of array" << endl;
    cout << "6. Delete the number from a specific position" << endl;
    cout << "7. Delete the specific number" << endl;
    cout << "8. Exit to the main menu " << endl;
    cout << endl;
}

static void listMenu(){
    cout << endl;
    cout << "SELECT THE NUMBER OF OPERATION ON BIDIRECTIONAL LIST" << endl;
    cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl
         << endl;

    cout << "1. Append number" << endl;
    cout << "2. Append number after specific number" << endl;
    cout << "3. Append number before specific number" << endl;
    cout << "4. Delete specific number" << endl;
    cout << "5. Delete first number (head)" << endl;
    cout << "6. Delete last number (tail)" << endl;
    cout << "7. Delete number after specific number" << endl;
    cout << "8. Delete number before specific number" << endl;
    cout << "9. Exit to the main menu " << endl;
    cout << endl;
}

static void heapMenu(){
    cout << endl;
    cout << "SELECT THE NUMBER OF OPERATION ON HEAP" << endl;
    cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl
         << endl;

    cout << "1. Append number (without heapify)" << endl;
    cout << "2. Add number (with heapify)" << endl;
    cout << "3. Delete root" << endl;
    cout << "4. Heapify" << endl;
    cout << "5. Exit to the main menu " << endl;
    cout << endl;
}

int main()
{
    Dynamic_Array dynamic_array;
    Bidirectional_List bidi_list;
    Heap heap;

    int choice, choice2;
    bool stayInLoop;

    while (true)
    {
        stayInLoop = true;

        mainMenu();
        choice = getInputFromUser();
        switch (choice)
        {
        case 1:
            while(stayInLoop){
                arrayMenu();
                dynamic_array.print();
                choice = getInputFromUser();
                switch(choice){
                    case 1:
                        cout<<"Enter number to append"<<endl<<">";
                        choice = getInputFromUser();
                        dynamic_array.append(choice);
                        break;
                    case 2:
                        cout<<"Enter number to append"<<endl<<">";
                        choice = getInputFromUser();
                        cout<<"Enter position of array"<<endl<<">";
                        choice2 = getInputFromUser();
                        dynamic_array.appendAt(choice, choice2);
                        break;
                    case 3:
                        cout<<"Enter number to insert"<<endl<<">";
                        choice = getInputFromUser();
                        cout<<"Enter position of array"<<endl<<">";
                        choice2 = getInputFromUser();
                        dynamic_array.insert(choice, choice2);
                        break;
                    case 4:
                        dynamic_array.deleteFirstNumber();
                        break;
                    case 5:
                        dynamic_array.deleteLastNumber();
                        break;
                    case 6:
                        cout<<"Enter position of array to delete number"<<endl<<">";
                        choice = getInputFromUser();
                        dynamic_array.deleteAt(choice);
                        break;
                    case 7:
                        cout<<"Enter number to delete"<<endl<<">";
                        choice = getInputFromUser();
                        dynamic_array.deleteNumber(choice);
                        break;
                    case 8:
                        stayInLoop = false;
                        break;
                    default:
                        cout << "incorrect input, enter a number from 1 to 8" << endl;
                        break;
                }
            }
            break;

        case 2:
            while(stayInLoop){
                listMenu();
                bidi_list.print();
                cout <<"in reverse order (from tail):"<<endl;
                bidi_list.printFromTail();
                choice = getInputFromUser();
                switch(choice){
                    case 1:
                        cout<<"Enter number to append"<<endl<<">";
                        choice = getInputFromUser();
                        bidi_list.add(choice);
                        break;
                    case 2:
                        cout<<"Enter number for which the next one should be appended after"<<endl<<">";
                        choice = getInputFromUser();
                        cout<<"Enter appended number"<<endl<<">";
                        choice2 = getInputFromUser();
                        bidi_list.addAfter(choice, choice2);
                        break;
                    case 3:
                        cout<<"Enter number for which the next one should be appended before"<<endl<<">";
                        choice = getInputFromUser();
                        cout<<"Enter appended array"<<endl<<">";
                        choice2 = getInputFromUser();
                        bidi_list.addBefore(choice, choice2);
                        break;
                    case 4:
                        cout<<"Enter number to delete"<<endl<<">";
                        choice = getInputFromUser();
                        bidi_list.deleteNumber(choice);
                        break;
                    case 5:
                        bidi_list.deleteHead();
                        break;
                    case 6:
                        bidi_list.deleteTail();
                        break;
                    case 7:
                        cout<<"Enter number for which the next one should be deleted after"<<endl<<">";
                        choice = getInputFromUser();
                        bidi_list.deleteAfter(choice);
                        break;
                    case 8:
                        cout<<"Enter number for which the next one should be deleted before"<<endl<<">";
                        choice = getInputFromUser();
                        bidi_list.deleteBefore(choice);
                        break;
                    case 9:
                        stayInLoop = false;
                        break;
                    default:
                        cout << "incorrect input, enter a number from 1 to 9" << endl;
                        break;
                }
            }
            break;

        case 3:
            while(stayInLoop){
                heapMenu();
                heap.print();
                choice = getInputFromUser();
                switch(choice){
                    case 1:
                        cout<<"Enter number to append"<<endl<<">";
                        choice = getInputFromUser();
                        heap.append(choice);
                        break;
                    case 2:
                        cout <<"Enter number to add"<<endl<<">";
                        choice = getInputFromUser();
                        heap.addAndHeapify(choice);
                        break;
                    case 3:
                        heap.deleteMax();
                        break;
                    case 4:
                        heap.doHeapify();
                        break;
                    case 5:
                        stayInLoop = false;
                        break;
                    default:
                        cout << "incorrect input, enter a number from 1 to 5" << endl;
                        break;
                }
            }
            break;

        case 4:
            return 0;
            break;

        default:
            cout << "incorrect input, enter a number from 1 to 4" << endl;
            break;
        }
    }

    return 0;
}