#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size(); // size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            // add pages to current student
            pagesStudent += arr[i];
        }
        else
        {
            // add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    // book allocation impossible:
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

/*
Example:
Books (pages): arr = {10, 20, 30, 40}
Students: m = 2

You have to split these books contiguously among 2 students.

Option 1:
Student 1: 10 + 20 + 30 = 60 pages

Student 2: 40 pages
Max pages any student gets: 60

Option 2:
Student 1: 10 + 20 = 30 pages

Student 2: 30 + 40 = 70 pages
Max pages any student gets: 70

Option 3:
Student 1: 10 pages

Student 2: 20 + 30 + 40 = 90 pages
Max pages any student gets: 90

✅ Best Option:
Option 1 is the best because the student with the most pages only has to read 60, which is the minimum possible maximum.
*/