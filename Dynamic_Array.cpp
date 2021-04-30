#include "Dynamic_Array.h"
#include <iostream>
using namespace std;


Dynamic_Array::Dynamic_Array()
{
    array = nullptr;
}

Dynamic_Array::~Dynamic_Array()
{
    delete[] array;
}

void Dynamic_Array::copy(int *array_from, int *array_to, int size) //simple copy method
{
    // cout << "copying numbers..." << endl;
    for (size_t i = 0; i < size; i++)
    {
        array_to[i] = array_from[i];
    }
}

int Dynamic_Array::getSize()
{
    return size;
}

void Dynamic_Array::swap(int position1, int position2) //swap method, useful in operations on the heap
{
    if (position1 < 0 || position1 > size - 1 || position2 < 0 || position2 > size - 1)
    { //check that the given position is within the range
        cout << "invalid position" << endl;
        return;
    }
    // cout << "swapping " << array[position1] << " with " << array[position2] << endl;
    int buffor = array[position1];
    array[position1] = array[position2];
    array[position2] = buffor;
}

void Dynamic_Array::insert(int number, int position) //replace the old number on the given position
{
    if (position < 0 || position >= size)
    { //check that the given position is within the range
        cout << "invalid position" << endl;
        return;
    }
    array[position] = number;
}

void Dynamic_Array::append(int number) //append number on last position
{
    appendAt(number, size);
}

void Dynamic_Array::appendAt(int number, int position) //append number on given position
{

    if (position < 0 || position > size)
    { //check that the given position is within the range
        cout << "invalid position" << endl;
        return;
    }

    if (size == 0) //check if size is equal to volume of array
    {
        size++;
        array = new int[size];
    }
    else
    {
        size++;
        //below code resizes up the array
        int *temporary_array = new int[size+1]; //creating an temporary array
        copy(array, temporary_array, size);       //copy array to temporary array
        delete[] array;                           //remove unnecessary array
        array = temporary_array;      
           
        for (int i = size; i > position; i--)
        { //move numbers up in an array to create a place to new number, we don't want to override the old one like in insert function
            array[i] = array[i - 1];
        }
    }

    array[position] = number;
}

void Dynamic_Array::deleteFirstNumber()
{ //delete first number of array (position 0)
    deleteAt(0);
}

void Dynamic_Array::deleteLastNumber()
{ //delete last number of array (position size-1)
    deleteAt(size - 1);
}

void Dynamic_Array::deleteNumber(int number)
{ //delete number, first from the beggining if the numbers in the array are reapeted

    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == number)
        {
            deleteAt(i);
            return;
        }
    }
    cout << "there is no number " << number << " in array" << endl;
}

void Dynamic_Array::deleteAt(int position) //delete number at given position
{
    if (position < 0 || position >= size)
    { //check that the given position is within the range
        cout << "invalid position" << endl;
        return;
    }

    if (size == 0)
    {
        cout << "array is empty" << endl;
        return;
    }
    else if (size == 1)
    {
        size = 0;
        delete[] array;
        array = nullptr;
        return;
    }

    for (int i = position; i < size; i++)
    {
        array[i] = array[i + 1];
    }

    size--;
    
    //below code resizes down array
    int *temporary_array = new int[size];
    copy(array, temporary_array, size);
    delete[] array;
    array = temporary_array;

    //move the numbers to fill the empty space
}

int Dynamic_Array::getNumber(int position)
{
    return array[position];
}

int Dynamic_Array::findNumber(int number)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == number)
        {
            return i;
        }
    }
    cout << "there is no number " << number << endl;
    ;
    return -1;
}

void Dynamic_Array::print()
{
    if (size == 0)
    {
        cout << "array is empty" << endl;
        return;
    }

    cout << "array_size = " << size << endl
         << "[";
    for (size_t i = 0; i < size - 1; i++)
    {
        cout << array[i] << " ";
    }
    cout << array[size - 1] << "]" << endl
         << endl;
}

// int main()
// {
//     Dynamic_Array ar;

//     for (size_t i = 0; i < 100; i++)
//     {
//         ar.append(i);
//     }
//     ar.print();

//     ar.deleteFirstNumber();
//     ar.print();

//     return 0;
// }