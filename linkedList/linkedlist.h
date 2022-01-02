using namespace std;

template <typename T>
class list;

// Node class
template <typename T>
class Node
{
    T data;

public:
    Node *next;

    // Constructor
    Node(T d) : data(d), next(NULL){};

    // Getter for data
    T get_data()
    {
        return data;
    }

    // To share screts if any with List class
    friend class list<T>;

    // Recursively deleting all the nodes
    ~Node()
    {
        if (next != NULL)
            delete next;
    }
};

template <typename T>
class list
{
    Node<T> *head;
    Node<T> *tail;
    int recursiveSearchHelper(Node<T> *start, int data)
    {
        if (start == NULL)
            return -1;

        if (start->data == data)
            return 1;

        int pos = recursiveSearchHelper(start->next, data);
        if (pos == -1)
            return -1;
        return 1 + pos;
    }

public:
    // Constructor
    list() : head(NULL), tail(NULL) {}

    // Rturn head pointer
    Node<T> *begin()
    {
        return head;
    }

    // Pushing at the front of linked list
    // Time Complexity      O(1)
    // Space Complexity     O(1)
    void push_front(int data)
    {
        Node<T> *n = new Node<T>(data);
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
    }

    // Pushing at the end of into linked list
    // Time Complexity      O(1) (as we are maintaining tail as well)
    // Space Complexity     O(1)
    void push_back(int data)
    {
        Node<T> *n = new Node<T>(data);
        if (tail == NULL)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    }

    // Inserting into linkedin list at given position
    // Time Complexity      O(N)
    // Space Complexity     O(1)
    // Return Type          1 if successful || -1 if unsuccessfull
    int insert(int data, int position)
    {
        if (position == 0)
        {
            push_front(data);
            return 1;
        }

        Node<T> *itr = head;
        Node<T> *n = new Node<T>(data);

        for (int i = 1; i < position; i++)
        {
            if (itr->next == NULL)
                return -1;
            itr = itr->next;
        }
        n->next = itr->next;
        itr->next = n;

        if (itr == tail)
        {
            tail = n;
        }

        return 1;
    }

    // Searching linked list
    // Time Complexity      O(N)
    // Space Complexity     O(1)
    // Return Type          Position of data is exists || -1 if absent
    int search(int data)
    {
        Node<T> *itr = head;
        int pos = 0;
        while (itr != NULL && itr->data != data)
        {
            itr = itr->next;
            pos++;
        }
        if (itr == NULL)
            return -1;
        return pos;
    }

    // Recursive search of linked list
    // Time Complexity      O(N)
    // Space Complexity     O(N) (stack space)
    int recursive_search(int data)
    {
        return recursiveSearchHelper(head, data);
    }

    // Removing from the front
    // Time Complexity      O(1)
    // Space Complexity     O(1)
    void pop_front()
    {
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // Removing from the end
    // Time Complexity      O(1)
    // Space Complexity     O(1)
    void pop_back()
    {
        Node<T> *itr = head;
        Node<T> *temp;
        // Only Head
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            head = tail = NULL;
            return;
        }
        while (itr->next->next != NULL)
        {
            itr = itr->next;
        }
        temp = tail;
        tail = itr;
        itr->next = NULL;
        temp->next = NULL;
        delete temp;
    }

    // Removing from a given position
    // Time Complexity      O(N)
    // Space Complexity     O(1)
    int remove(int position)
    {
        Node<T> *itr = head;
        Node<T> *temp;

        if (position == 0)
        {
            temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

        for (int i = 1; i < position; i++)
        {
            if (itr->next == NULL)
            {
                return -1;
            }
            itr = itr->next;
        }
        if (itr->next == NULL)
            return -1;
        temp = itr->next;
        itr->next = itr->next->next;
        temp->next = NULL;
        if (temp == tail)
        {
            tail = itr;
        }
        delete temp;
        return 1;
    }
    // Reversisng the linked list
    // Time Complexity      O(N)
    // Space Complexity     O(1)
    void reverse()
    {
        Node<T> *prev = NULL;
        Node<T> *curr = head;
        Node<T> *next = curr->next;

        while (next != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }

        curr->next = prev;
        head = curr;
    }

    // Destructor: Recursively deleting all the nodes
    ~list()
    {
        if (head != NULL)
            delete head;
    }
};