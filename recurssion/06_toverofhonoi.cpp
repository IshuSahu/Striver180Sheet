/*
The Tower of Hanoi is solved using recursion:

Base case:
If n == 1, move the single disk from A to C.

Recursive case:
Move n-1 disks from A to B (using C as helper).
Move the nth (largest) disk from A to C.
Move the n-1 disks from B to C (using A as helper).
*/

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disk 1 from " << A << " to " << C << endl;
        return;
    }
    towerOfHanoi(n - 1, A, C, B);
    cout << "Move disk " << n << " from " << A << " to " << C << endl;
    towerOfHanoi(n - 1, B, A, C);
}

int main() {
    int n = 4;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
