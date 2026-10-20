class DisjointSet {
public:
    vector<int> parent, rank, size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        //step 1 jisme apan saare 1's ke group ko jodd denge
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    for(int ind=0;ind<4;ind++){
                        int nrow = i + delrow[ind];
                        int ncol = j + delcol[ind];
                        int nodeNo = i*n+j;
                        int NnodeNo = nrow*n + ncol;
                        if(nrow>=0&&ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol] == 1){
                            ds.unionBySize(nodeNo,NnodeNo);
                        }
                    }
                }
            }
        }
        // step 2 isme hm 0's ko 1 sath jod ke unke parents ko ek set me store krenge duplicate se bchne ke liye 
        /*
        [111
         101
         111]
         ab isme jb 0 pr honge toh nrow ncol har bar 1 dega toh hm 4 baar add kr denge size isiliye hm chaaro side ke parents ko set me store krenge end me sbka max lenge
        */
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)continue;
                set<int>parents;
                for(int ind =0 ;ind<4;ind++){
                    int nrow = i+delrow[ind];
                    int ncol = j+delcol[ind];
                    int nodeNo = i*n+j;
                    int NnodeNo = nrow*n + ncol;
                    if(nrow>=0&&ncol>=0 && nrow<n&&ncol<n && grid[nrow][ncol] == 1){
                        parents.insert(ds.findUPar(NnodeNo));
                    }
                }
                //jaise hi ek component ke chaaro side ho gye ab set me chaaro side ke unique prents stored h
                int sizetotal=0;
                for(auto it:parents){
                    sizetotal += ds.size[it]; //saare parents ke size ka sum liye
                    /*
                        agat visualize krna h toh dekho
                        1 1 0 1 1
                        1 1 0 1 1
                        1 1 0 1 1
                        0 0 1 0 0
                        0 0 1 1 1
                        0 0 1 1 1
                        toh ab 1st row me 0 ke neighbours set me store honge kuch aise
                        parents = 0,3
                        bcz left side ke componnets ka prent 1 and right ka 3
                        toh ab 1 ka size + 3 ka size
                    */
                }
                mx = max(mx,sizetotal+1);  //sbka max store kiye (+1 kiya for 0 itself, means ye h ki 111
                      //101
                      //111)
                // toh ab isme 1's ka size th ajayega from size[] but 0 ko bhi explicitly add kiya
            }
        }
        for(int cellNo=0;cellNo<n*n;cellNo++){
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        // ab end me pure n*n nodes pr traverse and saare parents ka size ka max le liya for edge case ki lets say sb initally 1 tha toh us case ko krne ke liye
    return mx;
    }
};