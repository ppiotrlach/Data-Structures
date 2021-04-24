#include <iostream>
#include "Dynamic_Array.h"

using namespace std;


void Dynamic_Array::resize_up(){
    cout << "resizing array up: old value of volume = " << volume << " ,new value = " << volume * GROWTH_FACTOR << endl;
    volume *= GROWTH_FACTOR;
    int *temporary_array = new int[volume];
    copy(array, temporary_array, size);
    delete[] array;
    array = temporary_array;
}

//reduces the volume of the array (volume/growth_factory)
void Dynamic_Array::resize_down()
{
    cout << "resizing array down: old value of volume = " << volume << " ,new value = " << volume / GROWTH_FACTOR << endl;
    volume /= GROWTH_FACTOR;
    int *temporary_array = new int[volume];
    copy(array, temporary_array, size);
    delete[] array;
    array = temporary_array;
}

void Dynamic_Array::copy(int *array_from, int *array_to, int size)
{
    cout << "copying numbers..." << endl;
    for (size_t i = 0; i < size; i++)
    {
        array_to[i] = array_from[i];
    }
}

Dynamic_Array::Dynamic_Array()
{
    array = new int[INITIAL_VOLUME];
}

Dynamic_Array::~Dynamic_Array()
{
    delete[] array;
}

int Dynamic_Array::getSize()
{
    return size;
}

void Dynamic_Array::swap(int position1, int position2)
{
    if (position1 < 0 || position1 > size - 1 || position2 < 0 || position2 > size - 1)
    { //check that the given position is within the range
        cout << "invalid position" << endl;
        return;
    }
    cout << "swapping " << array[position1] << " with " << array[position2] << endl;
    int buffor = array[position1];
    array[position1] = array[position2];
    array[position2] = buffor;
}

void Dynamic_Array::insert(int number, int position)
{
    if (position < 0 || position >= size)
    { //check that the given position is within the range
        cout << "invalid position" << endl;
        return;
    }
    array[position] = number;
}

void Dynamic_Array::append(int number)
{
    appendAt(number, size);
    // cout<<size;
}

void Dynamic_Array::appendAt(int number, int position)
{

    if (position < 0 || position > size)
    { //check that the given position is within the range
        cout << "invalid position" << endl;
        return;
    }

    if (size == volume)
    {
        resize_up();
    }
    //move numbers up in an array to create a place to new number, we don't want to override the old one
    for (int i = size; i > position; i--)
    {
        array[i] = array[i - 1];
    }
    size++;
    array[position] = number;
}

void Dynamic_Array::deleteAt(int position)
{
    if (position >= 0 && position <= size)
    { //check that the given position is within the range
        cout << "invalid position" << endl;
        return;
    }

    if (size <= volume / 2 && volume > INITIAL_VOLUME)
    {
        resize_down();
    }

    //move the numbers to fill the empty space
    for (int i = position; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    size--;
}

int Dynamic_Array::getNumber(int position)
{
    return array[position];
}

void Dynamic_Array::print()
{
    if (size == 0)
    {
        cout << "array is empty" << endl;
        return;
    }

    cout << "array_size = " << size << " array_volume = " << volume << endl
         << "[";
    for (size_t i = 0; i < size - 1; i++)
    {
        cout << array[i] << " ";
    }
    cout << array[size - 1] << "]" << endl
         << endl;
}

// int main(){

//     Dynamic_Array dynamic_array;
//     dynamic_array.append(1);
//     dynamic_array.append(2);
//     dynamic_array.append(3);
//     dynamic_array.append(4);
//     dynamic_array.append(5);
//     dynamic_array.append(6);

//     dynamic_array.print();

//     dynamic_array.swap(0,5);

//     dynamic_array.print();

//     return 0;
// }