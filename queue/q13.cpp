// sum of min/max element of subArray of size k 

// #####################################################

// galti kaya kari ismai tumene 

/*

galti yahi thi tumhari ki tum window jab tak k ka ban nahi jata tab tak min max nahi nikal rahe the 

per hame usse pahele hi nikal na hai min max and jab naya max dale usse pahel jitane bhi min hai usse remove kar do 




*/

// ######################################################

#include <bits/stdc++.h> 
using namespace std;

long long sumOfMaxAndMin(vector<int> &a, int n, int k) {
    // Write your code here.
    int i = 0;
    int j = 0;
    deque<int> mn;
    deque<int> mx;
    long long ans = 0;

    while (j < n) {
        // Remove elements not within the window for min
        while (!mn.empty() && mn.back() > a[j]) {
            mn.pop_back();
        }
        mn.push_back(a[j]);

        // Remove elements not within the window for max
        while (!mx.empty() && mx.back() < a[j]) {
            mx.pop_back();
        }
        mx.push_back(a[j]);

        // If window size is less than k, just increase the end pointer
        if (j - i + 1 < k) {
            j++;
        } 
        // When we have a window of size k
        else if (j - i + 1 == k) {
            // Add the min and max of the current window to ans
            ans += mn.front();
            ans += mx.front();

            // Remove the elements which are out of this window
            if (!mn.empty() && mn.front() == a[i]) {
                mn.pop_front();
            }
            if (!mx.empty() && mx.front() == a[i]) {
                mx.pop_front();
            }

            // Slide the window
            i++;
            j++;
        }
    }
    return ans;
}
