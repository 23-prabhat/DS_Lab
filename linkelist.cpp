#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

Node* createNode(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;
    return n;
}

void insertFront(int x) {
    Node* n = createNode(x);
    n->next = head;
    head = n;
}

void insertEnd(int x) {
    Node* n = createNode(x);
    if (head == NULL) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

void deleteFront() {
    if (head == NULL) return;
    Node* t = head;
    head = head->next;
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
}
