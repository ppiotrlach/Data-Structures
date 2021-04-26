#pragma once

#include <iostream>

#include "Dynamic_Array.cpp"


class Heap
{
private:
    Dynamic_Array heap;

    static int parent(int i)
    {
        return (i - 1) / 2;
    }

    static int leftChild(int i)
    {
        return i * 2 + 1;
    }

    static int rightChild(int i)
    {
        return i * 2 + 2;
    }

    void heapify(int parent);

public:
    Heap();

    int getSize();

    int getRoot();

    void append(int n);

    void addAndHeapify(int n);

    void doHeapify();

    void deleteMax();

    void print();
};

