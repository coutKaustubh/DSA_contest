class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Path Compression
    int findUPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    // Check whether u and v belong to the same component
    bool find(int u, int v) {
        return findUPar(u) == findUPar(v);
    }

    // Union by Rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by Size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unionBySize(i,mp[mail]);
                }
                
            }
        }
        //now we have map which has 0-m1,0-m2,1-m3,1-m4,2-m6 ...etc m1,m2 are mail1 mail2
        //and also a Disjoint set jisme union ho chuka h 
        // now ek int - vector<String>bnani h jaise 0 - {m1,m2} , 1-(m3,m4,m7) like 3 ka ultimate parent agar 1 h so mp me agar 3 - m7 h toh ye m7 should be inside 1  etc 
        // and usko sorted krna bcz question me kaha
        //and fir return krna ek nye vector<vector<stgring>> me daal ke

        unordered_map<int,vector<string>>mergedMails;
        for(auto it:mp){
            string mail = it.first;
            // int node = it.second; //aise nhi hoga //we will find ultimate parent
            int node = ds.findUPar(it.second);
            mergedMails[node].push_back(mail);
        }

        //now just answer dena h
        vector<vector<string>>ans;
        for(auto it:mergedMails){
            int node = it.first;
            vector<string>mail = it.second;
            sort(mail.begin(),mail.end());
            mail.insert(mail.begin(),accounts[node][0]);
            ans.push_back(mail);
        }
        return ans;
    }
};