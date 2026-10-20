class Solution {
public:
    void dfs(string src, map<vector<string>, int>& mp,unordered_map<string, vector<string>>& adjls,vector<string>& ans) {
        for (auto it : adjls[src]) {
            string desti = it;
            if (mp[{src, desti}] == 0) continue;
            mp[{src, desti}]--;
            dfs(desti, mp, adjls, ans);
        }
        ans.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<vector<string>, int> mp;
        unordered_map<string, vector<string>> adjls;
        for (auto it : tickets) {
            string source = it[0];
            string destination = it[1];
            mp[{source, destination}]++;
            adjls[source].push_back(destination);
        }

        // Sort destinations in lexicographical order
        for (auto& it : adjls) {
            sort(it.second.begin(), it.second.end());
        }
        vector<string> ans;
        dfs("JFK", mp, adjls, ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};