#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
private:
    int capacity;
    int size;
    int *heap;

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    int leftChild(int index)
    {
        return (2 * index + 1);
    }

    int rightChild(int index)
    {
        return (2 * index + 2);
    }

public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->heap = new int[this->capacity];
    }

    void Push(int key)
    {
        if (this->size == this->capacity)
            return;
        this->size++;
        int index = this->size - 1;
        this->heap[index] = key;

        while (index != 0 && this->heap[index] < this->heap[parent(index)])
        {
            swap(this->heap[index], this->heap[parent(index)]);
            index = parent(index);
        }
    }

    // O(1)
    int top() {
        if (this->size == 0) 
            return -1;
        return this->heap[0];
    }

    void Pop() {
        if (this->size == 0)
            return;
        if (this->size == 1) 
            this->size--;
        else {
            // general case
            this->heap[0] = this->heap[this->size - 1];
            this->size--;
            minHeapify(0);
        }
    }

    void minHeapify(int index) {
        int l = leftChild(index);
        int r = rightChild(index);
        int smallest = index;

        if (l < this->size && this->heap[l] < this->heap[smallest]) {
            smallest = l;
        }

        if (r < this->size && this->heap[r] < this->heap[smallest]) {
            smallest = r;
        }

        if( smallest != index) {
            swap(this->heap[index], this->heap[smallest]);
            minHeapify(smallest);
        }
    }

};

int main()
{

}