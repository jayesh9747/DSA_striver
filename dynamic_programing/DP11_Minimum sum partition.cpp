

// PS :

/*
Given an array arr of size n containing non-negative integers,
the task is to divide it into two sets S1 and S2 such that the
absolute difference between their sums is minimum and find the minimum difference

Input: N = 4, arr[] = {1, 6, 11, 5}
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11

Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation:
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4

*/

#include <vector>
#include <climits>
using namespace std;

vector<int> subsetsum(int arr[], int N, int sum)
{
    int n = N;

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true; // A sum of 0 is always possible
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    vector<int> ans;

    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[n][i])
        {
            ans.push_back(i);
        }
    }

    return ans;
}

int minDifference(int arr[], int n)
{
    int range = 0;

    for (int i = 0; i < n; i++)
    {
        range += arr[i];
    }

    vector<int> possible = subsetsum(arr, n, range);

    int mini = INT_MAX;

    for (int i = 0; i < possible.size(); i++)
    {
        mini = min(mini, range - 2 * possible[i]);
    }

    return mini;
}
