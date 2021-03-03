#include "iostream"
#include "string"

using namespace std;


struct Node
{
    int item;
    Node * next = NULL;
};

struct Queue
{
    Node * pFirst = NULL;
    Node * pLast = NULL;
    
    void Enqueue(int item) {
        Node * node = new Node;
        if (pFirst == NULL) {
            pFirst = node;
        }
        else {
            pLast->next = node;
        }
        node->item = item;
        pLast = node;
    }

    int Dequeue() {
        if (pFirst == NULL) {
            throw (string)"There is no elemnt in queue";
        }
        Node * temp = pFirst;
        int return_item = pFirst->item;
        pFirst = pFirst->next;
        delete temp;
        return return_item;
    }

    int size() {
        if (pFirst == NULL) {
            return 0;
        }
        Node * pNow = pFirst;
        int size = 1;
        while (pNow != pLast) {
            pNow = pNow->next;
            size++;
        }
        return size;
    }
};

int main()
{
    // Queue * q = new Queue;
    // q->Enqueue(1);
    // q->Enqueue(2);
    // q->Enqueue(6);
    // cout << "size = " << q->size() << endl;
    // cout << "deleted " << q->Dequeue() << endl;
    // cout << "size = " << q->size() << endl;
}