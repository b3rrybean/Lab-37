#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(const string &s) {
    int total = 0;
    for (char c : s) {
        total += (int)c;
    }
    return total;
}

void print_first_100(const map<int, list<string>> &hash_table) {
    
    // PASTED FROM MAIN PREVIOUSLY

    int shown = 0;
    for (auto &entry : hash_table) {
        if (shown >= 100) break;

        int hash_index = entry.first;
        const list<string> &codes = entry.second;

        cout << "Hash index: " << hash_index << " -> ";
        for (const string &s : codes) {
            cout << s << " ";
        }
        cout << endl;

        shown++;
    }
}

void search_key(const map<int, list<string>> &hash_table) {
    

}

void add_key(map<int, list<string>> &hash_table) {


}

void remove_key(map<int, list<string>> &hash_table) {


}

void modify_key(map<int, list<string>> & hash_table) {


}


int main() {
    ifstream fin("lab-37-data-3.txt");

    if (!fin) {
        cerr << "ERROR: Could not open lab-37-data-3.txt" << endl;
        return 1;
    }

    // hash table
    map<int, list<string>> hash_table;

    string code;

    while (fin >> code) {
        int index = gen_hash_index(code);
        hash_table[index].push_back(code);
    }

    // interactive menu loop


    return 0;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
