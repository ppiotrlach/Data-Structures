#include "Dynamic_Array.h"

using namespace std;

//increases the volume of the array (volume*growth_factory)
void Dynamic_Array::resize_up(){
    // cout << "resizing array up: old value of volume = " << volume << " ,new value = " << volume * GROWTH_FACTOR << endl;
    volume *= GROWTH_FACTOR;
    int *temporary_array = new int[volume]; //creating an temporary array
    copy(array, temporary_array, size); //copy array to temporary array
    delete[] array; //remove unnecessary array
    array = temporary_array; //new array with GROWTH_FACTOR times greater volume
}

//reduces the volume of the array (volume/growth_factory), similar logic to above function
void Dynamic_Array::resize_down()
{
    // cout << "resizing array down: old value of volume = " << volume << " ,new value = " << volume / GROWTH_FACTOR << endl;
    volume /= GROWTH_FACTOR;
    int *temporary_array = new int[volume];
    copy(array, temporary_array, size);
    delete[] array;
    array = temporary_array;
}

void Dynamic_Array::copy(int *array_from, int *array_to, int size) //simple copy method
{
    // cout << "copying numbers..." << endl;
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

    if (size == volume) //check if size is equal to volume of array
    {
        resize_up(); //if so resize up the volume of array
    }
    //move numbers up in an array to create a place to new number, we don't want to override the old one like in insert function
    for (int i = size; i > position; i--)
    {
        array[i] = array[i - 1];
    }
    size++;
    array[position] = number;
}

void Dynamic_Array::deleteFirstNumber(){ //delete first number of array (position 0)
    deleteAt(0);
}

void Dynamic_Array::deleteLastNumber(){//delete last number of array (position size-1)
    deleteAt(size-1);
}

void Dynamic_Array::deleteNumber(int number){ //delete number, first from the beggining if the numbers in the array are reapeted

    for (size_t i = 0; i < size; i++)
    {
        if(array[i] == number){
            deleteAt(i);
            return;
        }
    }
    cout<< "there is no number "<<number<<" in array"<<endl;
    
}

void Dynamic_Array::deleteAt(int position) //delete number at given position
{
    if(size==0){
        cout << "array is empty" <<endl;
        return;
    }

    if (position < 0 || position >= size)
    { //check that the given position is within the range
        cout << "invalid position" << endl;
        return;
    }

    if (size <= volume / GROWTH_FACTOR && volume > INITIAL_VOLUME) //decrease if large array capacity is not used 
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

