#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define max_sz 100

class Stack {
private:
    int arr[max_sz];
    int top_val;

public:
    Stack() {
        top_val = -1;
    }

    bool isFull() {
        return (top_val == max_sz - 1);
    }

    bool isEmpty() {
        return (top_val == -1);
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return arr[top_val];
    }

    void push(int val) {
        if (isFull()) {
            return;
        }
        top_val++;
        arr[top_val] = val;
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        top_val--;
    }

    void display() {
        if (isEmpty()) {
            return;
        }
        cout << "Stack_array: ";
        for (int i = top_val; i >= 0; i--)
            cout << arr[i] << " ";
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
