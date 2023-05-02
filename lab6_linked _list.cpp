#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Stack {
private:
    Node* top_val;

public:
    Stack() {
        top_val = NULL;
    }

    bool isEmpty() {
        return (top_val == NULL);
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return top_val->data;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top_val;
        top_val = newNode;
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        Node* temp = top_val;
        top_val = top_val->next;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            return;
        }
        cout << "Stack_linkedlist: ";
        Node* temp = top_val;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    clock_t time_req;
    Stack s;
    time_req = clock();
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    time_req = clock() - time_req; 
    cout << "Time taken is: " << (float)time_req/CLOCKS_PER_SEC << " seconds\n" << endl;

    return 0;
}
