class Solution
{
public:
    int sloveusingRec(vector<int> arr, map<pair<int, int>, int> &mp, int left, int right)
    {

        if (left == right)
        {
            return 0;
        }

        int ans = INT_MAX;
        for (int i = left; i < right; i++)
        {
            ans = min(ans, mp[{left, i}] * mp[{i + 1, right}] +
                               sloveusingRec(arr, mp, left, i) +
                               sloveusingRec(arr, mp, i + 1, right));
        }

        return ans;
    }

    int solveusingMem(vector<int> arr, map<pair<int, int>, int> &mp, int left, int right, vector<vector<int>> &dp)
    {

        if (left == right)
        {
            return 0;
        }

        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        int ans = INT_MAX;
        for (int i = left; i < right; i++)
        {
            ans = min(ans, mp[{left, i}] * mp[{i + 1, right}] +
                               solveusingMem(arr, mp, left, i, dp) +
                               solveusingMem(arr, mp, i + 1, right, dp));
        }

        dp[left][right] = ans;

        return dp[left][right];
    }

    int sloveusingTab(vector<int> arr, map<pair<int, int>, int> &mp)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int left = n - 1; left >= 0; left--)
        {
            for (int right = 0; right <= n; right++)
            {

                if (left >= right)
                {
                    continue;
                }

                int ans = INT_MAX;
                for (int i_index = left; i_index < right; i_index++)
                {
                    ans = min(ans, mp[{left, i_index}] * mp[{i_index + 1, right}] + dp[left][i_index] + dp[i_index + 1][right]);
                }

                dp[left][right] = ans;
            }
        }

        return dp[0][n - 1];
    }

    int mctFromLeafValues(vector<int> &arr)
    {

        map<pair<int, int>, int> mp;

        for (int i = 0; i < arr.size(); i++)
        {
            mp[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
            {
                mp[{i, j}] = max(mp[{i, j - 1}], arr[j]);
            }
        }
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // int ans = sloveusingRec(arr , mp , 0 , n-1);

        // int ans = solveusingMem(arr , mp , 0 , n-1,dp);

        int ans = sloveusingTab(arr, mp);
        return ans;
    }
};