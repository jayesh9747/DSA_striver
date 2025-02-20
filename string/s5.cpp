/***
 *
 * Rotate String
 *
 * Input: s = "abcde", goal = "cdeab"
 * Output: true
 *
 */

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int k = 0;
        for (int k = 0; k < s.size(); k++)
        {
            reverse(s.begin(), s.end() - 1);
            reverse(s.begin(), s.end());
            if (s == goal)
                return true;
        }
        return false;
    }
};