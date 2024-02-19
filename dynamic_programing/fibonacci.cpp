#include <bits/stdc++.h>
using namespace std;


// using recursion 

int f(int n){
    if(n <= 1) return n;
    return f(n-1)+ f(n-2);
}


//memoisation 
int mem(int n){
    if(n <= 1) return n;
    vector<int>dp(n+1,-1);

    if(dp[n] != -1) return dp[n];

    return dp[n] = mem(n-1)+ mem(n-2);
}

// tabulation 
int tab(int n){
    vector<int>dp(n+1, 0);
    dp[0]= 0;
    dp[1]= 1;

    for(int i = 2 ; i<= n ; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}

//optimized tabulation 
int otab(int n){
    if( n <= 1 ) return n;
    int prev2 = 0;
    int prev =1;

    for(int i = 2 ; i< n ; i++){
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main(){
    int n ;
    cin >> n ;
    int t  = f(n);
    cout << t<<endl;
}