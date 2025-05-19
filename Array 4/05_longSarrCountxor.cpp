#include <bits/stdc++.h>
using namespace std;
/*Example 1:
Input Format:
 A = [4, 2, 2, 6, 4] , k = 6
Result:
 4
Explanation:
 The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
 */

// int subarraysWithXorK(vector<int> a, int k) {
//     int n = a.size();
//     int cnt = 0;
//     for(int i=0; i< n ;i++){
//         for(int j =i; j< n ;j++){
//             int xr =0;
//             for(int k =i;k<=j;k++){
//                 xr = xr ^ a[k];
//             }
//             if (xr==k) cnt++;
//         }
//     }
//     return cnt;
// }

// // optimize to O(n*n)
// int subarraysWithXorK(vector<int> a, int k) {
//     int n = a.size();
//     int cnt = 0;
//     for(int i=0; i< n ;i++){
//             int xr =0;
//         for(int j =i; j< n ;j++){
//             xr = xr ^ a[j];
//             if (xr==k) cnt++;
//         }
//     }
//     return cnt;
// }

//O(N) or O(N*logN) 
int subarraysWithXorK3(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}


int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK3(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

