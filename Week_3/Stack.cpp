#include "iostream"

using namespace std;


struct Node
{
    int item;
    Node * next = NULL;
};

struct Stack
{
    Node * pHead = NULL;

    void Push(int a) {
        Node * node = new Node;
        node->item = a;
        node->next = pHead;
        pHead = node;
    }

    int Pop() {
        if (!pHead) {
            throw 1;
        }
        else {
            Node * temp = pHead;
            pHead = temp->next;
            int x = temp->item;
            delete temp;
            return x;
        }
    }

    void printAll() {
        if (pHead == NULL) {
            cout << "Stack is empty.";
        }
        else {
            Node * pNow = pHead;
            while (pNow->next != NULL) {
                cout << pNow->item << " ";
                pNow = pNow->next;
            }
            cout << pNow->item;
        }
    }

};




int main() {
    // Stack * stack = new Stack;

    // stack->Push(1);
    // stack->Push(2);
    // stack->Push(5);

    // cout << stack->Pop();

    // stack->Push(3);

    // cout << stack->Pop() << endl;

    // stack->findAll();

    return 0;
}