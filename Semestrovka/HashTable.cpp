#include "iostream"
#include "list"
#include "string"
#include "fstream"
#include "ctime"


using namespace std;


struct HashTable
{
    int max_size = 1;
    int size = 0;
    list<string> * lst = new list<string>[max_size];

    int hash(string str) {
        int hash = 0;
        for (int i = 0; i < str.length(); i++) {
            hash += str[i];
        }
        hash = abs(hash * size) % max_size;
        // if (size > 944900) cout << "hash: " << hash << endl;
        return hash;
    }

    void rehash() {
        list<string> * old_lst = lst;
        int old_size = max_size;
        max_size *= 2;
        lst = new list<string>[max_size];
        for (int i = 0; i < old_size; i++) {
            if (old_lst[i].size() > 0) {
                for (list<string>::iterator it = old_lst[i].begin(); it != old_lst[i].end(); it++) {
                    int key = hash(*it);
                    lst[key].push_back(*it);
                }
            }
        }
    }

    void append(string str) {
        if (size >= max_size * 0.8) {
            rehash();
        }
        int key = hash(str);
        bool flag = true;
        for (list<string>::iterator it = lst[key].begin(); it != lst[key].end(); it++) {
            if (*it == str) {
                flag = false;
                break;
            }
        }
        if (flag) {
            lst[key].push_back(str);
            size++;
            // if (size > 944900) {
            //     cout << "size: " << size << " " << max_size << " " << str << endl;
            // }
        }
    }

    bool find(string str) {
        int key = hash(str);
        bool flag = false;
        for (list<string>::iterator it = lst[key].begin(); it != lst[key].end(); it++) {
            if (*it == str) {
                flag = true;
                break;
            }
        }
        return flag;
    }

    void del(string str) { 
        int key = hash(str);
        for (list<string>::iterator it = lst[key].begin(); it != lst[key].end(); it++) {
            if (*it == str) {
                lst[key].erase(it);
                break;
            }
        }
    }

};


int test(int fileNum, int filesAmount, string fileName) {
    ofstream fout;
    cout << "file: " << fileNum + 1 << "/" << filesAmount << endl;
    ifstream fin;
    HashTable * words = new HashTable;
    int averageTime = -1;
    string strAmount;
    int start, end;

    fin.open("test_data\\data" + to_string(fileNum) + ".txt");
    if (fin.is_open()) {
        fin >> strAmount;
        int wordsAmount = stoi(strAmount);
        start = clock();
        while (!fin.eof()) {
            string word;
            fin >> word;
            words->append(word);
        }
        end = clock();
        fin.close();

        // int times;
        // for (int i = 0; i < TESTS_AMOUNT; i++) {
        //     int start = clock();
        //     words->append("hereWego!");
        //     int end = clock();
        //     times += end - start;
        // }
        // averageTime = times / TESTS_AMOUNT;
    }
    else {
        cout << "OPEN ERROR!";
        return 999;
    }

    fout.open("" + fileName, ios::app);
    cout << end- start << endl;
    fout << strAmount << ';' << to_string(end - start) << '\n';
    fout.close();
    delete words;
    return 0;
}



int main() {
    const int FILES_AMOUNT = 101;
    const string FILENAME = "test3.csv";
    ofstream fout;
    // fout.open("Semestrovka\\" + FILENAME);
    // if (fout.is_open()) {
    //     fout << "amount;time\n";
    // }
    int fileNum;
    cin >> fileNum;
    test(fileNum, FILES_AMOUNT, FILENAME);
    // for (int fileNum = 0; fileNum < FILES_AMOUNT; fileNum++) {
    //     if (test(fileNum, FILES_AMOUNT, FILENAME) != 0) {
    //         return 999;
    //     }
    // }
}