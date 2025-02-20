// longest subarray with sum k

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    vector<ll> vec = {1, 1, 1, 2, 3, 4, 5};
    ll k = 5;

    ll maxi = 0;
    ll n = vec.size();
    ll i = 0, j = 0;
    ll sum = 0;

    while (j < n)
    {
        sum += vec[j];

        while (i < j && sum > k)
        {
            sum -= vec[i];
            i++;
        }
        if (sum == k)
        {
            maxi = max(maxi, j - i + 1);
        }
        j++;
    }

    cout << maxi << endl;
}