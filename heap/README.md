# Heap

The file `heap.h` is a header file which you can include in your C++ program and use heap data structure.

## Usage

Firstly include the header file. Make sure that the header file is in the same folder of your program.

```c++
#include "heap.h"
```

How to use?

```c++
// Max Heap
// By default the heap is a max heap with size of 10

heap<int> h;

// Min Heap

heap<int> h(true);

// To customise the size of the heap

heap<int> h(false, 100);// Max heap

heap<int> h(true, 100); // Min heap

```

## Methods on Heap

The following are the methods available on the heap object.

1. **push (data)**: Pushing the data into heap.
2. **pop ()**: Remove the top element.
3. **top ()**: Returns the top element.
4. **isEmpty ()**: Checks if the heap is empty or not.
