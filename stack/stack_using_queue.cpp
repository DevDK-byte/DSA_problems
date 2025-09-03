#include<iostream>
#include<queue>
using namespace std;

class stack_queue {
    queue<int> q;

public:
    void push(int n) {
        int s = q.size();
        q.push(n);

        // Rotate the previous elements behind the new one
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int element = q.front();
        q.pop();
        return element;
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        queue<int> temp = q; // copy the queue
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    stack_queue sq;
    sq.push(20);
    sq.push(509);
    sq.push(99);

    cout << "Stack elements: ";
    sq.display();   // prints 99 509 20  (LIFO order)

    cout << "Top element: " << sq.top() << endl; // prints 99

    sq.pop();
    cout << "After one pop: ";
    sq.display();   // prints 509 20
}
