#include <iostream>
#include <string>
#include <climits>      // INT_MAX, INT_MIN
#include <cfloat>       // FLT_MAX, DBL_MAX
#include <limits>       // numeric_limits
#include <cstdlib>      // RAND_MAX
#include <cstddef>      // NULL
#include <cstdio>       // EOF

using namespace std;

int main() {
    // 1. string::npos
    string s = "interview";
    size_t pos = s.find("code");
    if (pos == string::npos) {
        cout << "Not found using string::npos\n";
    }

    // 2. INT_MAX / INT_MIN
    int arr[] = {3, -2, 14, -10, 8};
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    for (int val : arr) {
        maxVal = max(maxVal, val);
        minVal = min(minVal, val);
    }
    cout << "Max: " << maxVal << ", Min: " << minVal << endl;

    // 3. numeric_limits
    cout << "Double Max: " << numeric_limits<double>::max() << endl;
    cout << "Long long Max: " << numeric_limits<long long>::max() << endl;

    // 4. NULL and nullptr
    int* ptr1 = NULL;
    int* ptr2 = nullptr;
    if (!ptr1 && !ptr2) {
        cout << "Both pointers are null.\n";
    }

    // 5. RAND_MAX
    cout << "RAND_MAX: " << RAND_MAX << ", Random Value: " << rand() << endl;

    // 6. EOF
    int ch;
    cout << "Enter a char (Ctrl+D or Ctrl+Z to simulate EOF): ";
    ch = getchar();
    if (ch == EOF) {
        cout << "\nYou reached EOF!\n";
    } else {
        cout << "You entered: " << (char)ch << endl;
    }

    return 0;
}

/*
| Constant/Macro       | Header      | Use Case                 |
| -------------------- | ----------- | ------------------------ |
| `string::npos`       | `<string>`  | String search failure    |
| `INT_MAX`, `INT_MIN` | `<climits>` | Min/max value of `int`   |
| `LLONG_MAX`          | `<climits>` | Max value of `long long` |
| `FLT_MAX`, `DBL_MAX` | `<cfloat>`  | Max float/double         |
| `numeric_limits<T>`  | `<limits>`  | Type-safe min/max        |
| `NULL`, `nullptr`    | `<cstddef>` | Null pointers            |
| `RAND_MAX`           | `<cstdlib>` | Random number generation |
| `EOF`                | `<cstdio>`  | End-of-file detection    |

*/