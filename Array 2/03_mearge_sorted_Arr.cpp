#include<bits/stdc++.h>

using namespace std;
void merge(int arr1[], int arr2[], int n, int m) {
    int high = n-1;
    int low = 0;

    while (high>=0 && low<m)
    {
        if(arr1[high]>arr2[low]){
            swap(arr1[high--],arr2[low++]);
        }
        else{
            break;
        }
    }
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
    
}
int main(){
    
    int arr1[] = {1, 4, 8, 10};
    int arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
    return 0;
}