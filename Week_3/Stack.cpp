#include "iostream"

using namespace std;


struct Cell
{
    int item;
    Cell * next;
};

struct Stack
{
    Cell * pHead;

    void Push(int a) {
        Cell * cell = new Cell;
        cell->item = a;
        cell->next = pHead;
        pHead = cell;
    }

    int Pop() {
        if (!pHead) {
            throw 1;
        }
        else {
            Cell * temp = pHead;
            pHead = temp->next;
            int x = temp->item;
            delete temp;
            return x;
        }
    }

};




int main() {
    Stack * stack = new Stack;

    stack->Push(1);
    stack->Push(2);
    stack->Push(5);

    cout << stack->Pop();

    stack->Push(3);

    cout << stack->Pop();

    return 0;
}