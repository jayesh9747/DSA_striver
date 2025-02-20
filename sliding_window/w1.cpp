#include <bits/stdc++.h>
using namespace std;

// maximum sum of subarray sum of size k
/*

array : [-1 ,2 , 3 ,4,5];

k = 2

 */

int main()
{

    vector<int> vec = {-1, 2, 3, 4, 5};
    int k = 2;

    int n = vec.size();
    int j = 0, i = 0;
    int sum = 0;
    int maxi = INT_MIN;

    while (j < n)
    {
        sum += vec[j];

        if (j - i + 1 < k)
        {
            j++;
        }

        else if (j - i + 1 == k)
        {
            maxi = max(maxi, sum);
            sum -= vec[i];
            i++;
            j++;
        }
    }

    cout << maxi << endl;
}