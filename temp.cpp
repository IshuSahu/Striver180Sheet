#include<bits/stdc++.h>

using namespace std;
bool checkPallindrome(string str){
    int left =0, right = str.length()-1;
    while (left<=right)
    {
        if(str[left++] != str[right--]){
            return false;
        }
    }
    return true;
    
}
int main(){
    string str ="JavaJ";
    bool result = checkPallindrome(str);
    if(result){
        cout<<"Pallindrome";
    }
    else{
        cout<<"Not Pallindrome";
    }
    return 0;
}