#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

Node* createNode(int x){
    Node* n = new Node;
    n->data = x;
    n->next = NULL;
    return n;
}

void insertEnd(int x){
    Node* n = createNode(x);
    if(head == NULL){
        head = n;
        n->next = head;
        return;
    }
    Node* t = head;
    while(t->next != head) t = t->next;
    t->next = n;
    n->next = head;
}

void insertFront(int x){
    Node* n = createNode(x);
    if(head == NULL){
        head = n;
        n->next = head;
        return;
    }
    Node* t = head;
    while(t->next != head) t = t->next;
    n->next = head;
    head = n;
    t->next = head;
}

void deleteFront(){
    if(head == NULL) return;
    if(head->next == head){
        delete head;
        head = NULL;
        return;
    }
    Node* t = head;
    while(t->next != head) t = t->next;
    Node* temp = head;
    head = head->next;
    t->next = head;
    delete temp;
}

void display(){
    if(head == NULL) return;
    Node* t = head;
    do{
        cout << t->data << " ";
        t = t->next;
    } while(t != head);
    cout << endl;
}

int main(){
    insertEnd(10);
    insertEnd(20);
    insertFront(5);
    display();
    deleteFront();
    display();
}
