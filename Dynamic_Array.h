#include <iostream>

class Dynamic_Array
{
private:
    int *array;
    int size = 0;
    const int INITIAL_VOLUME = 10; //initial volume of array
    int volume = INITIAL_VOLUME;   //current volume of array
    const int GROWTH_FACTOR = 2;   //determines how the volume of the array will increase (new value of volume = volume*GROWTH_FACTOR;

    //resizing up array volume(doubles it)
    void resize_up();

    //reduces the volume of the array (volume/growth_factory)
    void resize_down();

    void copy(int *array_from, int *array_to, int size);

public:
    Dynamic_Array();

    ~Dynamic_Array();

    int getSize();

    void swap(int position1, int position2);

    void insert(int number, int position);

    void append(int number);

    void appendAt(int number, int position);

    void deleteAt(int position);

    int getNumber(int position);

    void print();
};
