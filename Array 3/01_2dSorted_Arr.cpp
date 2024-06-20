#include<bits/stdc++.h>

using namespace std;
// Method 1 by using 2loops Search
// Method 2
bool BinarySerch(vector<int> &nums, int Target){
    int n = nums.size();
    int low =0, high = n-1;

    while (low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid] == Target){
            cout<<nums[mid];
            return true;
        } 
        else if(nums[mid]<Target) low = mid+1;
        else high = mid -1;
    }
    return false;
    

}


// by the intution to Flatten the 2d in to 1D array 
// O(log m*n)
bool searchMatrix1(vector<vector<int>> &matrix, int Target){
    int low =0;
    int n = matrix.size();
    int m = matrix[0].size();
    int high = (m*n) -1;
    while (low<=high)
    {
        int mid = (low+high) /2;
        int row = mid / m;
        int col = mid % m;

        if(matrix[row][col] == Target){
            return true;
        }
        else if(matrix[row][col]<Target) low = mid +1;
        else high = mid-1;
    }
    return false;
    
    
}
bool searchMatrix(vector<vector<int>> &matrix, int Target){

    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        if(matrix[i][0]<= Target && Target<=matrix[i][m-1]){
            return BinarySerch(matrix[i], Target);
        }
    }
    return false;
    
}
int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // searchMatrix(matrix, 12) == true ? cout << "true\n" : cout << "false\n";
    searchMatrix1(matrix, 12) == true ? cout << "true\n" : cout << "false\n";
}