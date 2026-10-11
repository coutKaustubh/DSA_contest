class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());

        q.push({beginWord,1});

        while(!q.empty()){
            string top = q.front().first;
            int level = q.front().second;
            q.pop();

            for(int i=0;i<top.size();i++){
                char original = top[i];
                for(char ch='a';ch<='z';ch++){
                    top[i] = ch;
                    string formed = top;
                    if(st.find(formed) != st.end()){
                        if(formed == endWord)return level+1;
                        q.push({formed,level+1});
                        st.erase(formed);
                    }
                    top[i] = original;
                }
            }
        }
        return 0;
    }
};