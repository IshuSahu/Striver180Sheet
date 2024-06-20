/*
M1: sorting;
M2: This problem is a variation of the popular Dutch National flag algorithm. 


*/
#include<bits/stdc++.h>

using namespace std;
void sortArray(vector<int> &arr, int n){

    int i=0;
    int j= n-1;
    int k = 0;

    while (k<=j)
    {
        if(arr[k]==0){
            swap(arr[k++],arr[i++]);
        }
        else if(arr[k]==1){
            k++;
        }
        else{
            swap(arr[k],arr[j--]);
        }
    }
    
}
int main(){
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}