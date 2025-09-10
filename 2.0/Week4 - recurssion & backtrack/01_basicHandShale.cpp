#include <iostream>
using namespace std;

int main()
{
    int N;
    cout << "Enter the number of people: ";
    cin >> N;

    if (N < 2)
    {
        cout << "At least 2 people are required for a handshake." << endl;
    }
    else if (N < 4)
    {
        cout << "At least 4 people are required for crossing handshakes." << endl;
    }
    else
    {
        // Calculate the number of handshakes using the combination formula: N * (N-1) / 2
        int handshakes = (N * (N - 1)) / 2;
        cout << "The number of possible handshakes is: " << handshakes << endl;

        // Calculate the number of crossing handshakes using the formula: N * (N-1) * (N-2) * (N-3) / 24
        long long crossingHandshakes = (N * (N - 1) * (N - 2) * (N - 3)) / 24;

        // Output the result
        cout << "The number of crossing handshakes is: " << crossingHandshakes << endl;
    }

    return 0;
}
