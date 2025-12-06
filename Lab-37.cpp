#include <iostream>
using namespace std;

int sum_ascii(const string &s) {
    int total = 0;
    for (char c : s) {
        total += (int)c;
    }
    return total;
}

int main() {
    string test = "hello";

    cout << "Sum ASCII of \"" << test << "\" = "
         << sum_ascii(test) << endl;

    return 0;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
