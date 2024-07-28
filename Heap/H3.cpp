// kth smallest number -> using min heap & max heap   
// Kth greatest number -> using min heap & max heap
// is CBT valid heap or NOT ? 
// check CBT or NOT ?
// CBT + BST  convert into valid heap 




// kth smallest number 
#include<bits/stdc++.h>
using namespace std;


// using min heap space complexity n
int kthSmallestNumber(vector<int> v , int k){
    priority_queue<int,vector<int>,greater<int>> q;

    for(int i = 0 ; i < v.size(); i++){
        q.push(v[i]);
    }

    for(int i = 0; i < k-1 ; i++){
        q.pop();
    }

    return q.top();
}


//using max heap 

int KthSmallestNumberUsingMaxHeap(vector<int> v , int k){

    if(k > v.size()) return -1;

    priority_queue<int> q;
    
    for(int i = 0 ; i < k ; i++){
        q.push(v[i]);
        
    }

    for(int i = k ; i < v.size(); i++){
        if(q.top() > v[i]){
            q.pop();
            q.push(v[i]);
        }
    }

    return q.top();
}

int main(){

vector<int> v = {1,2,3,4,5,6,7,8,9};

int k = 4;

int ans = KthSmallestNumberUsingMaxHeap(v,k);

cout << "Kth smallest number is " << ans << endl;


}
