#include <bits/stdc++.h>

using namespace std;
struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    
    bool static comparator(Item item1, Item item2){
        double val1 = double(item1.value/item1.weight);
        double val2 = double(item2.value/item2.weight);
        return val1<val2;
    }
    double fractionalKnapsack(int capacity, Item *arr, int n)
    {
        double ans =0;
        sort(arr, arr+n, comparator);
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i].value<<" "<<arr[i].weight<<endl;
        }
        for (int i = 0; i < n; i++)
        {
            if(arr[i].weight<=capacity){
                ans+=arr[i].value;
                capacity -= arr[i].weight;
            }
            else{
                ans+= double((arr[i].value/arr[i].weight)*capacity);
                break;
            }
        }
        
        
        return ans;
    }
};
int main()
{
    int n = 4, weight = 50;
    Item arr[n] = {{100, 20}, {60, 10}, {120, 30},{150,40}};
    Solution obj;
    double ans = obj.fractionalKnapsack(weight, arr, n);
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    return 0;
}