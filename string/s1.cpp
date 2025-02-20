#include <bits/stdc++.h>
using namespace std;

/**
 *
 * Remove outermost Parenthesis
 *
 *
 */

string removeOuterParentheses(string s)
{
    string ans;
    int open = 0;
    for (char c : s)
    {
        if (c == '(')
            open++;
        if (c == ')')
            open--;

        if (open > 1 && c == '(')
        {
            ans.push_back(c);
        }
        else if (open > 0 && c == ')')
        {
            ans.push_back(c);
        }
    }
    return ans;
}

int main()
{
}