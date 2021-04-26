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

    string fileName = "test_data/2m/tdata5.txt";

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

    for (int x : array)
    {
        dynamic_array.append(x);
    }

    gettimeofday(&start, NULL);

    dynamic_array.deleteFirstNumber();

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds)*1000 + useconds / 1000.0) + 0.5;

    printf("dynamic array 1st element delete time: %ld milliseconds\n", mtime);

    gettimeofday(&start, NULL);

    dynamic_array.deleteLastNumber();

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds)*1000 + useconds / 1000.0) + 0.5;

    printf("dynamic array last element delete time: %ld milliseconds\n", mtime);

    gettimeofday(&start, NULL);

    dynamic_array.deleteNumber(dynamic_array.getSize() / 2);

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds)*1000 + useconds / 1000.0) + 0.5;

    printf("dynamic array middle element delete time: %ld milliseconds\n", mtime);

    //---------------BIDI_LIST

    for (int x : array)
    {
        bidi.add(x);
    }

    gettimeofday(&start, NULL);

    bidi.deleteHead();

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds)*1000 + useconds / 1000.0) + 0.5;

    printf("bidi head delete time: %ld milliseconds\n", mtime);

    gettimeofday(&start, NULL);

    bidi.deleteTail();

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds)*1000 + useconds / 1000.0) + 0.5;

    printf("bidi tail delete time: %ld milliseconds\n", mtime);

    gettimeofday(&start, NULL);

    bidi.deleteNumber(array[amountOfData / 2]);

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds)*1000 + useconds / 1000.0) + 0.5;

    printf("bidi middle element delete time: %ld milliseconds\n", mtime);

    //---------------HEAP

    for (int x : array)
    {
        heap.addAndHeapify(x);
    }

    gettimeofday(&start, NULL);
    heap.deleteMax();

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds)*1000 + useconds / 1000.0) + 0.5;

    printf("heap delete max time: %ld milliseconds\n", mtime);

    return 0;
}