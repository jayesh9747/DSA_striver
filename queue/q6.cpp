// interleave First and Second Half of queue

#include <bits/stdc++.h>
using namespace std;

void InterleaveElements(queue<int> &q)
{

    int n = q.size();
    int k = n /2;

    queue <int> newq;

    int count = 0 ;

    //half part separation
    while(!q.empty()){
        int t = q.front();
        q.pop();
        count++;
        newq.push(t);

        if(count == k){
            break;
        }
    }

    

    // interleave

    while(!q.empty() && !newq.empty()){
        q.push(newq.front());
        newq.pop();
        int t = q.front();
        q.pop();
        q.push(t);
    }

    if(n&1){
        q.push(q.front());
        q.pop();
    }

}

int main()
{

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);

    InterleaveElements(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}