// https://leetcode.com/problems/word-ladder/
// word ladder 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // here we use the bfs 
        // so first of we create the queue 

        queue<pair<string,int >> q;

        unordered_set <string> st(wordList.begin(), wordList.end());

        q.push({beginWord , 1});


        while(!q.empty()){
            auto frontNode = q.front();
            // bhai tu har bar pop karna bhul jata hai 
            q.pop();

            string CurrString = frontNode.first;
            int Count = frontNode.second;

            // check that 

            if(CurrString == endWord){
                return Count;
            }

            for(int index = 0 ; index < CurrString.size() ; index++){

                char OrignalChar = CurrString[index];

                for(int ch = 'a' ; ch <= 'z' ; ch++){
                    CurrString[index] = ch;
                    if(st.find(CurrString) != st.end()){
                        q.push({CurrString,Count+1});
                        st.erase(CurrString);
                    }

                }

                CurrString[index] = OrignalChar;
            }

        }

        return 0 ;
    }
};