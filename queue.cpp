#include <bits/stdc++.h>
using namespace std;

#define MAX 100  

class Queue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;   
        arr[++rear] = x;
        cout << x << " inserted\n";
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int x = arr[front++];
        if (front > rear) front = rear = -1; 
        return x;
    }

    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue Empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Deleted: " << q.dequeue() << endl;
    cout << "Front Element: " << q.peek() << endl;

    q.display();

    return 0;
}





// python
// class Queue:
//     def __init__(self, size):
//         self.size = size
//         self.q = [None] * size
//         self.front = -1
//         self.rear = -1

//     def enqueue(self, x):
//         if self.rear == self.size - 1:
//             return
//         if self.front == -1:
//             self.front = 0
//         self.rear += 1
//         self.q[self.rear] = x

//     def dequeue(self):
//         if self.front == -1 or self.front > self.rear:
//             return None
//         x = self.q[self.front]
//         self.front += 1
//         if self.front > self.rear:
//             self.front = self.rear = -1
//         return x

//     def display(self):
//         if self.front == -1:
//             return
//         for i in range(self.front, self.rear + 1):
//             print(self.q[i], end=" ")
//         print()

// q = Queue(5)
// q.enqueue(10)
// q.enqueue(20)
// q.enqueue(30)
// q.display()
// q.dequeue()
// q.display()
