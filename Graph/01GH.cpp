#include<bits/stdc++.h>
using namespace std;

//  Graph representation using the adjacency matrix 

int main(){

    int n;

    cout << "Enter the Number of nodes:"<<endl;
    cin>> n ;
    vector<vector<int>> adj(n , vector<int>(n, 0));
    int e ;
    cout << "Enter the Number of Edges:" <<endl;
    cin>> e;


    for(int i = 0 ; i < n ; i++){
        int u , v;
        cin>> u >> v;
        //mark 1
        adj[u][v]=1;
    }

    //printing

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << adj[i][j]<<" ";
        }
        cout << endl;
    }

    cout << endl;

}