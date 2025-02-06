#include <iostream>
using namespace std;
 
// Maximum size of array or Dequeue
#define MAX 100
 
// A structure to represent a Deque
class Deque {
    int arr[MAX];
    int front;
    int rear;
    int size;
 
public:
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }
 
    // Operations on Deque:
    void insertfront(int key);
    void insertrear(int key);
    void deletefront();
    void deleterear();
    bool isFull();
    bool isEmpty();
    int getFront();
    int getRear();
};
 
// Checks whether Deque is full or not.
bool Deque::isFull()
{
    return ((front == 0 && rear == size - 1)
            || front == rear + 1);
}
 
// Checks whether Deque is empty or not.
bool Deque::isEmpty() { return (front == -1); }
 
// Inserts an element at front
void Deque::insertfront(int key)
{
    // check whether Deque if  full or not
    if (isFull()) {
        cout << "Overflow\n" << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1) {
        front = 0;
        rear = 0;
    }
 
    // front is at first position of queue
    else if (front == 0)
        front = size - 1;
 
    else // decrement front end by '1'
        front = front - 1;
 
    // insert current element into Deque
    arr[front] = key;
}
 
// function to inset element at rear end
// of Deque.
void Deque ::insertrear(int key)
{
    if (isFull()) {
        cout << " Overflow\n " << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1) {
        front = 0;
        rear = 0;
    }
 
    // rear is at last position of queue
    else if (rear == size - 1)
        rear = 0;
 
    // increment rear end by '1'
    else
        rear = rear + 1;
 
    // insert current element into Deque
    arr[rear] = key;
}
 
// Deletes element at front end of Deque
void Deque ::deletefront()
{
    // check whether Deque is empty or not
    if (isEmpty()) {
        cout << "Queue Underflow\n" << endl;
        return;
    }
 
    // Deque has only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else
        // back to initial position
        if (front == size - 1)
        front = 0;
 
    else // increment front by '1' to remove current
        // front value from Deque
        front = front + 1;
}
 
// Delete element at rear end of Deque
void Deque::deleterear()
{
    if (isEmpty()) {
        cout << " Underflow\n" << endl;
        return;
    }
 
    // Deque has only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size - 1;
    else
        rear = rear - 1;
}
 
// Returns front element of Deque
int Deque::getFront()
{
    // check whether Deque is empty or not
    if (isEmpty()) {
        cout << " Underflow\n" << endl;
        return -1;
    }
    return arr[front];
}
 
// function return rear element of Deque
int Deque::getRear()
{
    // check whether Deque is empty or not
    if (isEmpty() || rear < 0) {
        cout << " Underflow\n" << endl;
        return -1;
    }
    return arr[rear];
}
 
// Driver code
int main()
{
    Deque dq(5);
   
      // Function calls
    cout << "Insert element at rear end  : 5 \n";
    dq.insertrear(5);
 
    cout << "insert element at rear end : 10 \n";
    dq.insertrear(10);
 
    cout << "get rear element "
         << " " << dq.getRear() << endl;
 
    dq.deleterear();
    cout << "After delete rear element new rear"
         << " become " << dq.getRear() << endl;
 
    cout << "inserting element at front end \n";
    dq.insertfront(15);
 
    cout << "get front element "
         << " " << dq.getFront() << endl;
 
    dq.deletefront();
 
    cout << "After delete front element new "
         << "front become " << dq.getFront() << endl;
    return 0;
}
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* prev;
    node* next;

    node(int a) {
        data = a;
        prev = nullptr;
        next = nullptr;
    }
};

class dequeue {
    node* front;
    node* rear;

public:
    dequeue() : front(nullptr), rear(nullptr) {}  // Constructor to initialize front and rear

    // pushfront
    void pushfront(int x) {
        node* temp = new node(x);  // Create the new node

        if (front == nullptr) {
            front = rear = temp;  // Deque is empty
        } else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
    }

    // PUSHBACK
    void pushback(int x) {
        node* temp = new node(x);

        if (rear == nullptr) { // Corrected: check rear for emptiness
            front = rear = temp;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }

    // POPFRONT
    int popfront() {
        if (front == nullptr) {
            return -1; // Or throw an exception: Deque is empty
        }

        node* temp = front;
        front = front->next;

        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr; // Deque is now empty
        }

        delete temp;
        return 1; // Or return the popped value
    }

    // POPBACK
    int popback() {
        if (rear == nullptr) {
            return -1; // Or throw an exception
        }

        node* temp = rear;
        rear = rear->prev;

        if (rear != nullptr) {
            rear->next = nullptr;
        } else {
            front = nullptr; // Deque is now empty
        }

        delete temp;
        return 1; // Or return the popped value
    }

    int getFront() {  // Renamed to be more descriptive and conventional
        if (front == nullptr) {
            return -1; // Or throw an exception
        } else {
            return front->data;
        }
    }

    int getRear() {  // Renamed to be more descriptive
        if (rear == nullptr) {
            return -1; // Or throw an exception
        } else {
            return rear->data;
        }
    }

    bool isEmpty() const { // Added isEmpty function
        return front == nullptr;
    }

    ~dequeue() { // Destructor to prevent memory leaks
        while (front != nullptr) {
            node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    dequeue dq;

    dq.pushfront(10);
    dq.pushback(20);
    dq.pushfront(5);

    cout << "Front: " << dq.getFront() << endl;  // Output: 5
    cout << "Rear: " << dq.getRear() << endl;    // Output: 20

    dq.popfront();
    cout << "Front after pop: " << dq.getFront() << endl; // Output: 10

    dq.popback();
    cout << "Rear after pop: " << dq.getRear() << endl;   // Output: 10

    return 0;
}
