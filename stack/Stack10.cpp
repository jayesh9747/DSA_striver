// Remove Redundant  Brackets

// link:  https://www.naukri.com/code360/problems/redundant-brackets_975473

#include <bits/stdc++.h>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> St;

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            St.push(s[i]);
        }
        else
        {

            if (s[i] == ')')
            {

                bool res = true;

                while (St.top() != '(')
                {

                    char top = St.top();

                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        res = false;
                    }
                    St.pop();
                }
                if (res == true)
                    return true;
                St.pop();
            }
        }
    }
    return false;
}
