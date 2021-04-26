#include <iostream>
#include <fstream>

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

#include "Bidirectional_List.cpp"
#include "Heap.cpp" //plus heap includes Dynamic_Array.cpp

using namespace std;

static int getAmountOfData(string fileName)
{
    ifstream file(fileName);
    string line;

    int arraySize = 0;

    if (file.is_open())
    {
        getline(file, line);
        arraySize = stoi(line);
    }
    else
        cout << "cant open file" << endl;
    file.close();

    return arraySize;
}

int main()
{

    string fileName = "test_data/2m/tdata3.txt";

    int amountOfData = getAmountOfData(fileName);

    cout << endl
         << endl;

    ifstream file(fileName);
    string line;

    int lineCounter = 0;
    int array[amountOfData];

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (lineCounter > 0)
            {
                array[lineCounter - 1] = stoi(line);
            }
            lineCounter++;
        }
    }
    else
        cout << "cant open file" << endl;
    file.close();

    //--------MEASURING TIME OF OPERATION----------
    Dynamic_Array dynamic_array;
    Bidirectional_List bidi;
    Heap heap;

    struct timeval start, end;

    long mtime, seconds, useconds;

    //---------------DYNAMIC_ARRAY
    int randomNumber = (rand() % amountOfData) + 1;

     gettimeofday(&start, NULL);

    for (int x : array)
    {
        dynamic_array.append(x);
    }

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds)*1000 + useconds / 1000.0) + 0.5;

    printf("dynamic array: %ld milliseconds\n", mtime);

    //---------------BIDI_LIST

     gettimeofday(&start, NULL);

    for (int x : array)
    {
        bidi.add(x);
    }

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds)*1000 + useconds / 1000.0) + 0.5;

    printf("bidirectional list: %ld milliseconds\n", mtime);

    // ---------------HEAP

    gettimeofday(&start, NULL);

    for (int x : array)
    {
        heap.addAndHeapify(x);
    }

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds)*1000 + useconds / 1000.0) + 0.5;

    printf("heap : %ld milliseconds\n", mtime);

    return 0;
}