// First Negative Number in Array window of size k 


#include<bits/stdc++.h>
using namespace std;


vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k) {
    int i = 0, j = 0;
    vector<long long> ans;
    queue<long long> q;

    while (j < n) {
        // If the current element is negative, add it to the queue
        if (a[j] < 0) {
            q.push(a[j]);
        }

        // If the current window size is less than k, increase the end pointer
        if (j - i + 1 < k) {
            j++;
        }
        // If the current window size is exactly k
        else if (j - i + 1 == k) {
            // If there are negative numbers in the current window, add the first one to the result
            if (!q.empty()) {
                ans.push_back(q.front());
            } else {
                ans.push_back(0); // Otherwise, add 0 to the result
            }

            // Remove the element going out of the window from the queue if it is negative
            if (!q.empty() && a[i] == q.front()) {
                q.pop();
            }

            // Slide the window forward
            i++;
            j++;
        }
    }

    return ans;
};

int main(){


}