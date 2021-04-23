#include <iostream>
#include <assert.h>

using namespace std;

//TODO
//add & delete - at any position 


class Dynamic_Array{
    private:
    int *array;
    int size = 0;
    const int INITIAL_VOLUME = 10; //initial volume of array
    int volume = INITIAL_VOLUME; //current volume of array
    const int GROWTH_FACTOR = 2; //determines how the volume of the array will increase (new value of volume = volume*GROWTH_FACTOR;

    //resizing up array volume(doubles it)
    void resize_up(){
        cout<<"resizing array up: old value of volume = "<<volume << " ,new value = " <<volume*GROWTH_FACTOR << endl;
        volume *= GROWTH_FACTOR;
        int *temporary_array = new int[volume];
        copy(array, temporary_array,size);
        delete [] array;
        array = temporary_array;
    }

    //reduces the volume of the array (volume/growth_factory)
    void resize_down(){
        cout<<"resizing array down: old value of volume = "<<volume << " ,new value = " <<volume/GROWTH_FACTOR << endl;
        volume /= GROWTH_FACTOR;
        int *temporary_array = new int[volume];
        copy(array, temporary_array,size);
        delete [] array;
        array = temporary_array;
    }

    void copy(int *array_from, int *array_to, int size){
        cout<< "copying numbers..." << endl;
        for (size_t i = 0; i < size; i++)
        {
            array_to[i] = array_from[i];
        }
    }

    public:
    Dynamic_Array(){
        array = new int[INITIAL_VOLUME];
    }
    
    
    ~Dynamic_Array() {
        delete[] array;
    }
    
    void swap(int position1, int position2){
        if(position1 <0 || position1>size-1 || position2 <0 || position2>size-1){//check that the given position is within the range 
            cout<<"invalid position"<<endl;
            return;
        }
        cout<< "swapping " << array[position1]<< " with " << array[position2]<<endl;
        int buffor = array[position1];
        array[position1] = array[position2];
        array[position2] = buffor;
    }


    void insert(int number, int position){
        if(position <=0 || position>size){//check that the given position is within the range 
            cout<<"invalid position"<<endl;
            return;
        }
        array[position] = number;
    }

    void append(int number){
        appendAt(number,size);
        // cout<<size;
    }

    void appendAt(int number, int position){
        
        if(position <0 || position>size){//check that the given position is within the range 
            cout<<"invalid position"<<endl;
            return;
        }

        if (size==volume){
            resize_up();
        }
        //move numbers up in an array to create a place to new number, we don't want to override the old one
        for(int i = size; i > position; i--) {
            array[i] = array[i-1];
        }
        size++;
        array[position] = number;
    }

      void deleteAt(int position){
        assert(position >=0 && position<=size); //check that the given position is within the range

        if(size <= volume/2 && volume > INITIAL_VOLUME){
            resize_down();
        }

        //move the numbers to fill the empty space 
        for(int i = position; i < size; i++) {
            array[i] = array[i+1];
        }
        size--;

    }

    int get_number(int position){
        return *array + position;
    }

    void print(){
        if(size==0){
            cout<<"array is empty"<<endl;
            return;
        }

        cout << "array_size = " << size << " array_volume = " << volume << endl << "[";
        for (size_t i = 0; i < size -1; i++)
        {
            cout << array[i] << " ";
        }
        cout << array [size -1] << "]"<<endl<<endl;
        
    }
};


int main(){

    Dynamic_Array dynamic_array;
    dynamic_array.append(1);
    dynamic_array.append(2);
    
    dynamic_array.print();

    dynamic_array.swap(0,1);

    dynamic_array.print();

    return 0;
}