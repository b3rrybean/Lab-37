#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int sum_ascii(const string &s) {
    int total = 0;
    for (char c : s) {
        total += (int)c;
    }
    return total;
}

int main() {
    ifstream fiin("lab-37-data.txt");

    if (!fin) {
        cerr << "ERROR: Could not open lab-37-data.txt" << endl;
        return 1;
    }

    string code;
    long long totality = 0

    while (fin >> code) {
        totality += sum_ascii(code);
    }

    cout << "Totality ASCII = " << totality << endl;

    return 0;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
