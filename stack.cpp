#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int stackArr[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) return;
    stackArr[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stackArr[top--];
}

int peek() {
    if (top == -1) return -1;
    return stackArr[top];
}

void display() {
    for (int i = top; i >= 0; i--) cout << stackArr[i] << " ";
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    cout << pop() << endl;
    display();
    cout << peek() << endl;
}
