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
    int makeConnected(int n, vector<vector<int>>& adj) {
        DisjointSet ds(n);
        int cntExtras=0;  

        for(int i = 0; i < adj.size(); i++){
            int u = adj[i][0];
            int v = adj[i][1];

            if(ds.findUPar(u) == ds.findUPar(v)){
                cntExtras++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(ds.findUPar(i) == i)cnt++;
        }
        cnt=cnt-1;
        return cntExtras>=cnt?cnt:-1;
    }
};