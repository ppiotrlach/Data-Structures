#include <iostream>
#include "Heap.h"

using namespace std;





    void Heap::heapify(int heapSize, int parent)
    {
        int largestIndex = parent; // initializing parent as the largest number
        int leftChildIndex = leftChild(largestIndex);
        int rightChildIndex = rightChild(largestIndex);

        // if left child is larger than parent overwrite largestIndex
        if (leftChildIndex < heapSize && heap.getNumber(leftChildIndex) > heap.getNumber(largestIndex))
        {
            largestIndex = leftChildIndex;
        }

        // if right child is larger than largest overwrite largestIndex
        if (rightChildIndex < heapSize && heap.getNumber(rightChildIndex) > heap.getNumber(largestIndex))
        {
            largestIndex = rightChildIndex;
        }

        // if largest is not initial parent:
        if (largestIndex != parent)
        {
            // - swap numbers
            heap.swap(parent, largestIndex);

            // - recursively heapify substree of swapped child
            heapify(heapSize, largestIndex);
        }
    }

    Heap::Heap()
    {
    }

    int Heap::getSize()
    {
        return heap.getSize();
    }

    int Heap::getRoot()
    {
        return heap.getNumber(0);
    }

    void Heap::add(int n)
    {
        heap.append(n);
        //    doHeapify();
    }

    void Heap::doHeapify()
    {
        int heapSize = heap.getSize();
        int youngestParent = heapSize / 2 - 1;

        for (int i = youngestParent; i >= 0; i--)
        {
            heapify(heapSize, i);
        }
    }

    void Heap::deleteMax()
    {
    }

    void Heap::print()
    {
        heap.print();
        cout << endl;

        int pow_of_two = 1;
        for (size_t i = 0; i < heap.getSize(); i++)
        {
            int buff = pow_of_two;
            while (i < heap.getSize())
            {
                cout << heap.getNumber(i) << " ";
                pow_of_two--;
                if (pow_of_two == 0)
                    break;
                i++;
            }
            cout << endl;

            pow_of_two = buff;
            pow_of_two *= 2;
        }
        cout << endl;
    }

int main()
{
    Heap h;
    // cout << h.getRoot()<<endl;
    h.add(1);
    h.add(3);
    h.add(5);
    h.add(4);
    h.add(6);
    h.add(7);
    h.add(8);
    h.add(9);
    h.add(0);

    // h.add(4);
    // h.add(5);

    // h.add(3);

    cout << endl;
    h.print();

    h.doHeapify();
    h.print();
    // cout << h.getSize()<<endl;
}