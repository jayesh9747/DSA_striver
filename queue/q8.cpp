// First Non repeating character in Stream

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here

        vector<int> v(26, 0);

        queue<char> q;
        string ans = "";

        for (int i = 0; i < A.size(); i++)
        {
            char ch = A[i];

            v[ch - 'a']++;

            if (v[ch - 'a'] == 1)
            {
                q.push(ch);
            }

            while (!q.empty() && v[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            if (!q.empty())
            {
                ans.push_back(q.front());
            }
            else
            {
                ans.push_back('#');
            }
        }

        return ans;
    }
};

int main()
{
}