#include<iostream>
#include "string"
using namespace std;


struct Node
{
    int item;
    Node * next;
};

struct List
{
    Node * pBegin = NULL;
    
    void add(int item)
    {
        Node * node = new Node;
        if (pBegin == NULL) {
            pBegin = node;
        }
        else {
            Node * pLast = pBegin;
            while (pLast->next != NULL) {
                pLast = pLast->next;
            }
            pLast->next = node;
        }
        node->item = item;
        node->next = NULL;
    }

    int size()
    {
        if (pBegin == NULL) {
            return 0;
        }
        int size = 1;
        Node * pNow = pBegin;
        while (pNow->next != NULL)
        {
            pNow = pNow->next;
            size++;
        }
        return size;
    }

    int get(int id)
    {
        if (pBegin == NULL) {
            throw (string)"Index out of range";
        }
        Node * pNow = pBegin;
        while (pNow->next != NULL && id > 0){
            pNow = pNow->next;
            id--;
        }
        if (id > 0){
            throw (string)"Index out of range";
        }
        return pNow->item;
    }

    void printAll()
    {
        if (pBegin == NULL) {
            cout << "List is empty";
            return;
        }
        Node * pNow = pBegin;
        while (pNow->next != NULL) {
            cout << pNow->item << " ";
        }
    }
};

int main()
{
    // List * lst = new List;

    // lst->add(5);
    // lst->add(2);
    // lst->add(7);
    // lst->add(159);

    // cout << lst->size() << endl;
    // try{
    //     cout << lst->get(5);
    // }catch (string s){
    //     cout << s << endl;
    // }
    // cout << lst->get(2);
}