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
