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
    int key;
    cout << "Enter hash index to search for: ";
    cin >> key;

    auto it = hash_table.find(key);
    if (it == hash_table.end()) {
        cout << "Key " << key << " not found in table." << endl;
    } else {
        cout << "Key " << key << " found. Codes: ";
        for (const string &s : it->second) {
            cout << s << " ";
        }
        cout << endl;
    }
}

void add_key(map<int, list<string>> &hash_table) {
    int key;
    string code;

    cout << "Enter new hash index (int): ";
    cin >> key;
    cout << "Enter a code string to store at that key: ";
    cin >> code;

    hash_table[key].push_back(code);
    cout << "Added code \"" << code << "\" at key " << key << "." << endl;
}

void remove_key(map<int, list<string>> &hash_table) {
    int key;
    cout << "Enter hash index to remove: ";
    cin >> key;

    auto it = hash_table.find(key);
    if (it == hash_table.end()) {
        cout << "Key " << key << " not found; nothing removed." << endl;
    } else {
        hash_table.erase(it);
        cout << "Key " << key << " and all its codes were removed." << endl;
    }
}

void modify_key(map<int, list<string>> & hash_table) {
    int old_key;
    int new_key;
    cout << "Enter existing hash index to modify: ";
    cin >> old_key;
    cout << "Enter new hash index value: ";
    cin >> new_key;

    auto it = hash_table.find(old_key);
    if (it == hash_table.end()) {
        cout << "Key " << old_key << " not found; cannot modify." << endl;
        return;
    }

    // copy the list of codes from old key
    list<string> codes = it->second;
    // remove old key
    hash_table.erase(it);
    // moves codes to new key
    for (const string &s : codes) {
        hash_table[new_key].push_back(s);
    }
    cout << "Moved codes from key " << old_key << " to key " << new_key << "." << endl;
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
    int choice = 0;
    do {
        cout << "\n==== Lab 38 Menu ====\n";
        cout << "1. Print first 100 entries\n";
        cout << "2. Search for a key\n";
        cout << "3. Add a key\n";
        cout << "4. Remove a key\n";
        cout << "5. Modify a key\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                print_first_100(hash_table);
                break;
            case 2:
                search_key(hash_table);
                break;
            case 3:
                add_key(hash_table);
                break;
            case 4:
                remove_key(hash_table);
                break;
            case 5:
                modify_key(hash_table);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
