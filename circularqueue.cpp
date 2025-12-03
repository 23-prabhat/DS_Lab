#include <bits/stdc++.h>
using namespace std;

#define MAX 5

class CircularQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
            cout << "Full\n";
            return;
        }
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;
        arr[rear] = x;
    }

    int dequeue() {
        if (front == -1) return -1;
        int x = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
        return x;
    }

    int peek() {
        if (front == -1) return -1;
        return arr[front];
    }

    void display() {
        if (front == -1) return;
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << q.dequeue() << endl;
    q.enqueue(40);
    q.enqueue(50);
    q.display();
}





// python:
// class CircularQueue:
//     def __init__(self, size):
//         self.size = size
//         self.q = [None] * size
//         self.front = -1
//         self.rear = -1

//     def enqueue(self, x):
//         if (self.front == 0 and self.rear == self.size-1) or ((self.rear + 1) % self.size == self.front):
//             return
//         if self.front == -1:
//             self.front = self.rear = 0
//         else:
//             self.rear = (self.rear + 1) % self.size
//         self.q[self.rear] = x

//     def dequeue(self):
//         if self.front == -1:
//             return None
//         x = self.q[self.front]
//         if self.front == self.rear:
//             self.front = self.rear = -1
//         else:
//             self.front = (self.front + 1) % self.size
//         return x

//     def display(self):
//         if self.front == -1:
//             return
//         i = self.front
//         while True:
//             print(self.q[i], end=" ")
//             if i == self.rear:
//                 break
//             i = (i + 1) % self.size
//         print()


// c = CircularQueue(5)
// c.enqueue(10)
// c.enqueue(20)
// c.enqueue(30)
// c.display()
// c.dequeue()
// c.enqueue(40)
// c.enqueue(50)
// c.display()
