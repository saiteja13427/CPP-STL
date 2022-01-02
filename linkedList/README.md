# Linked List

The file `linkedlist.h` is a header file which you can include in your C++ program and use linked list data structure.

## Usage

Firstly include the header file. Make sure that the header file is in the same folder of your program.

```c++
#include "linkedlist.h"
```

How to use?

```c++

// For integer

list<int> l;

```

## Methods on Linked List

The following are the methods available on the linked list object.

1. **push_front (data)**: Pushing the data at the head of linked list.
1. **push_back (data)**: Pushing the data at the tail of linked list.
1. **insert (data, int position)**: Insert the data at the given position of linked list.
1. **pop_front ()**: Remove the head node.
1. **pop_back ()**: Remove the tail node.
1. **remove (data)**: Remove the node at given position.
1. **begin ()**: Returns the head pointer.
1. **search (data)**: Searches and returns the position of data.
1. **recursive_search (data)**: Recursively searches and returns the position of data.
1. **reverse ()**: Reverses the linked list.

# Iterating the Linked List

```c++

Node<int>* itr = l.begin();

while(itr!=NULL){
    cout<<itr->get_data()<<endl;
}

```
