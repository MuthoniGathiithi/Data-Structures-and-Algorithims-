#include <iostream>
using namespace std;

int main() {
    int marks[4] = {85, 76, 90, 67};

    // Print the second student's mark
    cout << "Second student's mark: " << marks[1] << endl;

    // Print all marks using a loop
    cout << "All student marks:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << marks[i] << endl;
    }

    return 0;
}
