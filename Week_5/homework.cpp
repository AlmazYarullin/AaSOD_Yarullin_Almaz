#include "iostream"
#include "string"

using namespace std;

struct Node
{
    int item;
    Node * next = NULL;
};

struct SortedList
{
    Node * pBegin = NULL;
    
    void add(int item)
    {
        Node * node = new Node;
        node->item = item;
        if (pBegin == NULL || pBegin->item >= item) {
            if (pBegin != NULL) node->next = pBegin;
            pBegin = node;
            return;
        }
        Node * pNow = pBegin;
        while (pNow->next != NULL && pNow->next->item <= item) {
            pNow = pNow->next;
        }
        if (pNow->next == NULL) {
            if (item >= pNow->item) 
                pNow->next = node;
            else {
                pBegin = node;
                node->next = pNow;
            }
            return;
        }
        node->next = pNow->next;
        pNow->next = node;
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
            pNow = pNow->next;
        }
        cout << pNow->item;
    }

    void remove(int id)
    {
        Node * pNow = pBegin;
        if (id == 0) {
            pBegin = pNow->next;
        }
        else {
            while (id > 1) {
                pNow = pNow->next;
                id--;
            }
            Node * pDel = pNow->next;
            pNow->next = pDel->next;
            delete pDel; 
        }
    }

};

struct UniqueSortedList
{
    Node * pBegin = NULL;
    
    void add(int item)
    {
        Node * node = new Node;
        if (pBegin == NULL) {
            pBegin = node;
            node->item = item;
        }
        else {
            Node * pNow = pBegin;
            while (pNow->next != NULL && item > pNow->item) {
                pNow = pNow->next;
            }
            if (item == pNow->item) {
                delete node;
                return;
            }
            if (item < pNow->item) {
                int temp_item = pNow->item;
                pNow->item = item;
                item = temp_item;
                while (pNow->next != NULL) {
                    pNow = pNow->next;
                    temp_item = pNow->item;
                    pNow->item = item;
                    item = temp_item;
                }
            }
            pNow->next = node;
            node->item = item;
        }
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
            pNow = pNow->next;
        }
    }
};

SortedList * Intersect(SortedList * a, SortedList * b)
{
    UniqueSortedList * uList = new UniqueSortedList;
    SortedList * outList = new SortedList;
    for (int i = 0; i < a->size(); i++) {
        uList->add(a->get(i));
    }
    for (int i = 0; i < b->size(); i++) {
        uList->add(b->get(i));
    }
    for (int i = 0; i < uList->size(); i++) {
        outList->add(uList->get(i));
    }
    return outList;
}

SortedList * Union(SortedList * a, SortedList * b)
{
    SortedList * outList = new SortedList;
    for (int i = 0; i < a->size(); i++) {
        for (int j = 0; j < b->size(); j++) {
            if (a->get(i) == b->get(j)) {
                outList->add(a->get(i));
            }
        }
    }
    return outList;
}

SortedList * Difference(SortedList * a, SortedList * b)
{
    SortedList * outList = new SortedList;
    bool flag = true;
    for (int i = 0; i < a->size(); i++) {
        flag = true;
        for (int j = 0; j < b->size(); j++) {
            if (a->get(i) == b->get(j)) {
                flag = false;
                break;
            }
        }
        if (flag) outList->add(a->get(i));
    }
    return outList;
}

int main()
{
    // SortedList * list1 = new SortedList;
    // SortedList * list2 = new SortedList;
    // cout << "here\n";
    // list1->add(4);
    // list1->add(6);
    // list1->add(5);
    // list1->add(2);
    // list2->add(1);
    // list2->add(3);
    // list2->add(4);
    // list2->add(6);
    // list1->printAll();
    // cout << endl;
    // list2->printAll();
    // cout << endl;
    // SortedList * list = Difference(list1, list2);
    // list->printAll();
}