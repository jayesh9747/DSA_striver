#include <bits/stdc++.h>
using namespace std;


// using recursion 

int f(int n){
    if(n <= 1) return n;
    return f(n-1)+ f(n-2);
}


//memoisation 
int mem(int n){
    if
}


int main(){
    int n ;
    cin >> n ;
    int t  = f(n);
    cout << t<<endl;
}