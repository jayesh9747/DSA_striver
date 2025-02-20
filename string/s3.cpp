/***
 *
 * Longest Common Prefix
 *
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 */

class Solution
{
public:
    string longestCommonPrefix(vector<string> &ar)
    {
        string s = "";
        for (int i = 0; i < ar[0].size(); i++)
        {

            char ch = ar[0][i];
            bool flag = 1;
            for (int j = 1; j < ar.size(); j++)
            {

                if (ch != ar[j][i] || ar[j].size() < i)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                s.push_back(ch);
            }
            else
            {
                break;
            }
        }
        return s;
    }
};