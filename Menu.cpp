#include <iostream>

#include "Bidirectional_List.cpp"
#include "Heap.cpp" //plus heap includes Dynamic_Array.cpp

using namespace std;

static void mainMenu()
{
    cout << endl;
    cout << "SELECT THE NUMBER OF THE DATA STRUCTURE YOU ARE INTERESTED IN" << endl;
    cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl
         << endl;
    ;
    cout << "1. Dynamic array" << endl;
    cout << "2. Bidirectional List" << endl;
    cout << "3. Heap" << endl;
    cout << "4. End the program" << endl;
    cout << endl;
}

static int getInputFromUser()
{   
    
    bool isInputCorrect = false;
    string input;

    while (!isInputCorrect)
    {   
        isInputCorrect = true;
        cin >> input;
        for(char const &c : input)
        {
            if (std::isdigit(c) == 0)
            {
                isInputCorrect = false;
                cout << "incorrect input, try again"<<endl<<">";
            }
        }
    }

    return stoi(input);
}

int main()
{
    Dynamic_Array dynamic_array;
    Bidirectional_List bidi_list;
    Heap heap;

    int choice;

    mainMenu();
    choice = getInputFromUser();


    // while(true){
    //     switch(choice){

    //     }
    // }

    return 0;
}