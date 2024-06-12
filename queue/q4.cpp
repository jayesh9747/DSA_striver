// reverse the code using the recursion

#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q)
{

    if (q.empty())
    {
        return;
    }

    int t = q.front();
    q.pop();
    reverseQueue(q);
    q.push(t);
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

    reverseQueue(q);

    while (!q.empty())
    {
        cout << q.front()<<" ";
        q.pop();
    }
    
}
