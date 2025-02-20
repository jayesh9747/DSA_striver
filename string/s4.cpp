/**
 *
 * Isomorphic Strings
 *
 * Input: s = "egg", t = "add"
 *
 * Output: true
 *
 */

class Solution
{
public:
    bool isIsomorphic(string str1, string str2)
    {
        map<char, char> mp;
        map<char, char> mp1;
        bool ans1 = true;
        bool ans2 = true;
        for (int i = 0; i < max(str1.size(), str2.size()); i++)
        {
            char ch = str1[i];
            if (mp.find(ch) != mp.end())
            {
                if (str2[i] != mp[str1[i]])
                {
                    ans1 = false;
                    break;
                }
            }
            else
            {
                mp[str1[i]] = str2[i];
            }
        }
        for (int i = 0; i < max(str1.size(), str2.size()); i++)
        {
            char ch = str2[i];
            if (mp1.find(ch) != mp1.end())
            {
                if (str1[i] != mp1[str2[i]])
                {
                    ans2 = false;
                    break;
                }
            }
            else
            {
                mp1[str2[i]] = str1[i];
            }
        }
        //    cout<< ans1 <<" * " << ans2;
        return ans1 && ans2;
    }
};