#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

Node* createNode(int x) {
    Node* n = new Node;
    n->data = x;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void insertFront(int x) {
    Node* n = createNode(x);
    if (head != NULL) head->prev = n;
    n->next = head;
    head = n;
}

void insertEnd(int x) {
    Node* n = createNode(x);
    if (head == NULL) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void deleteFront() {
    if (head == NULL) return;
    Node* t = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete t;
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) { delete head; head = NULL; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->prev->next = NULL;
    delete t;
}

void display() {
    Node* t = head;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    insertFront(20);
    insertEnd(30);
    insertFront(10);
    display();
    deleteFront();
    display();
    deleteEnd();
    display();
}




// python
// class Node:
//     def __init__(self, x):
//         self.data = x
//         self.prev = None
//         self.next = None

// head = None

// def insert_front(x):
//     global head
//     n = Node(x)
//     if head is None:
//         head = n
//         return
//     n.next = head
//     head.prev = n
//     head = n

// def insert_end(x):
//     global head
//     n = Node(x)
//     if head is None:
//         head = n
//         return
//     t = head
//     while t.next:
//         t = t.next
//     t.next = n
//     n.prev = t

// def delete_front():
//     global head
//     if head is None:
//         return
//     if head.next is None:
//         head = None
//         return
//     head = head.next
//     head.prev = None

// def delete_end():
//     global head
//     if head is None:
//         return
//     if head.next is None:
//         head = None
//         return
//     t = head
//     while t.next:
//         t = t.next
//     t.prev.next = None

// def display():
//     t = head
//     while t:
//         print(t.data, end=" ")
//         t = t.next
//     print()

// insert_front(20)
// insert_end(30)
// insert_front(10)
// display()
// delete_front()
// display()
// delete_end()
// display()
