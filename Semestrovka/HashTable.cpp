#include "iostream"
#include "list"
#include "string"


using namespace std;


struct HashTable
{
    int max_size = 1;
    int size = 0;
    list<string> * arr = new list<string>[max_size];

    int hash(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            hash += key[i];
        }
        hash = abs(hash * size) % max_size;
        return hash;
    }

    void rehash() {
        list<string> * old_arr = arr;
        int old_size = max_size;
        max_size *= 2;
        arr = new list<string>[max_size];
        for (int i = 0; i < old_size; i++) {
            if (old_arr[i].size() > 0) {
                for (list<string>::iterator it = old_arr[i].begin(); it != old_arr[i].end(); it++) {
                    int idx = hash(*it);
                    arr[idx].push_back(*it);
                }
            }
        }
    }

    void append(string str) {
        if (size >= max_size * 0.8) {
            rehash();
        }
        int idx = hash(str);
        bool flag = true;
        for (list<string>::iterator it = arr[idx].begin(); it != arr[idx].end(); it++) {
            if (*it == str) {
                flag = false;
                break;
            }
        }
        if (flag) {
            arr[idx].push_back(str);
            size++;
        }
    }

    bool find(string str) {
        int idx = hash(str);
        bool flag = false;
        for (list<string>::iterator it = arr[idx].begin(); it != arr[idx].end(); it++) {
            if (*it == str) {
                flag = true;
                break;
            }
        }
        return flag;
    }

    void del(string str) { 
        int idx = hash(str);
        for (list<string>::iterator it = arr[idx].begin(); it != arr[idx].end(); it++) {
            if (*it == str) {
                arr[idx].erase(it);
                break;
            }
        }
    }
};