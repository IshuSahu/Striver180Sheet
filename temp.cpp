#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string getPermutation1(int n, int k)
    {
        int fact = 1;
        vector<int> number;
        k =k-1;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            number.push_back(i);
        }
        number.push_back(n);
        string ans= "";
        while (true)
        {
            ans  = ans +  to_string(number[k/fact]);
            number.erase(number.begin()+ k/fact);
            if(number.size()==0){
                break;
            }

            k = k%fact;
            fact = fact/number.size();
        }
        return ans;
        
    }
};
int main()
{
    int n = 4, k = 17;
    Solution obj;
    string ans = obj.getPermutation1(n, k);
    cout << "The Kth permutation sequence is " << ans << endl;

    return 0;
}