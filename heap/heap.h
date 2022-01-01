#include <vector>
using namespace std;

template <typename T>
class heap
{
    // vector<T> h;
    // minHeap = true || maxHeap = false
    bool heapType;

    bool compare(T left, T ind)
    {
        if (heapType)
            return left < ind;
        else
            return left > ind;
    }

    // Heapify max heap
    void heapify(int index)
    {
        int len = h.size();
        int left = 2 * index, right = (2 * index) + 1, maxInd = index;
        // Base case
        if (left < len and compare(h[left], h[index]))
        {
            maxInd = left;
        }
        if (right < len and compare(h[right], h[maxInd]))
        {
            maxInd = right;
        }
        if (maxInd != index)
        {
            swap(h[index], h[maxInd]);
            heapify(maxInd);
        }
    }

public:
    vector<T> h;

    heap(bool minHeap = false, int size = 10)
    {
        h.reserve(size);
        // To have 1 indexing, we block 0 index
        h.push_back(-1);
        this->heapType = minHeap;
    }

    // Inserting into maxheap
    // Time Complexity      O(logN)
    // Space Complexity     O(1)
    void push(T data)
    {
        // Add data to end of the array
        h.push_back(data);
        int index = h.size() - 1;
        int parent = index / 2;
        // Putting the element in right place
        while (index > 1 and compare(h[index], h[parent]))
        {
            swap(h[index], h[parent]);
            index = parent;
            parent = parent / 2;
        }
    }

    // Return max element
    // Time Complexity      O(1)
    // Space Complexity     O(1)
    T top()
    {
        if (!isEmpty())
            return h[1];
        return -1;
    }

    // Removes the top element
    // Time Complexity      O(logN)
    // Space Complexity     O(1)
    void pop()
    {
        int len = h.size() - 1;
        int top = 1;
        // Sqap top element (to be popped) with the last element
        swap(h[top], h[len]);
        // Removing the last element now
        h.pop_back();
        // Heapify to re arrange
        heapify(1);
    }

    // Heap empty or not
    // Time Complexity      O(1)
    // Space Complexity     O(1)
    bool isEmpty()
    {
        return h.size() == 1;
    }
};