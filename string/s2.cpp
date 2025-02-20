

/**
 * Title : Reverse Words in a String
 *
 * Input: s = "the sky is blue"
 *  Output: "blue is sky the"
 */

class Solution
{
public:
    string reverseWords(string str)
    {
        stack<string> st;
        string tmp;
        str += " ";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != ' ')
            {
                tmp += str[i];
            }
            else
            {
                if (!tmp.empty())
                {
                    st.push(tmp);
                    tmp.clear();
                }
                else
                {
                    continue;
                }
            }
        }
        string ans;
        while (!st.empty())
        {
            ans += st.top();
            ans += ' ';
            st.pop();
        }
        int n = ans.size();
        return ans.substr(0, n - 1);
    }
};