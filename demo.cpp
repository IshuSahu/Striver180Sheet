#include<bits/stdc++.h>

using namespace std;
double Pow(double n, int m){
    if(m==0){
        return 1;
    }
    else{
        return 2 * Pow(n,m-1);
    }
}
int main(){
    double n=2.00000;
    int m =10;
    double result =Pow(n,m);
    cout<<result;
    return 0;
}