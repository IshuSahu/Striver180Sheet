#include <bits/stdc++.h>
/*
parents has to distribute the Cookies to there child greed >= size of cookies
*/
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l=0, r=0;
        sort(g.begin(),g.end());
        sort(s.begin(), s.end());

        while(r<s.size() && l<g.size()){
            if(g[l]<=s[r]){
                l++;
            }
            r++;
        }
        return l; 
    }
};
int main() {
    vector<int> g = {1,2}; // child as per there Greed
    vector<int> s = {1,2,3}; // cookies as per size
    Solution so;
    cout<<so.findContentChildren(g,s);

    return 0;
}