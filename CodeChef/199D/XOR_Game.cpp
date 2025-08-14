#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        int nxt[2];
        int cnt;
        Node() { nxt[0] = nxt[1] = -1; cnt = 0; }
    };
    static const int B = 30; 
    vector<Node> t;
    Trie() { t.reserve(1); t.push_back(Node()); }

    void clear(size_t reserve_nodes) {
        t.clear(); t.reserve(reserve_nodes); t.push_back(Node());
    }

    void add(int x, int delta) {
        int v = 0; t[v].cnt += delta;
        for (int b = B; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (t[v].nxt[bit] == -1) {
                t[v].nxt[bit] = (int)t.size();
                t.push_back(Node());
            }
            v = t[v].nxt[bit];
            t[v].cnt += delta;
        }
    }

    
    pair<int,int> queryMin(int target) const {
        int v = 0, res = 0, val = 0;
        for (int b = B; b >= 0; --b) {
            int bit = (target >> b) & 1;
            int pref = t[v].nxt[bit];
            int alt  = t[v].nxt[bit ^ 1];
            if (pref != -1 && t[pref].cnt > 0) {
                v = pref;
                val |= (bit << b);
            } else {
                v = alt;
                res |= (1 << b);
                val |= ((bit ^ 1) << b);
            }
        }
        return {res, val};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N);
        int S = 0;
        for (int i = 0; i < N; ++i) { cin >> A[i]; S ^= A[i]; }

        
        unordered_map<int,int> freq;
        freq.reserve(N * 2);
        for (int x : A) ++freq[x];
        vector<int> distinct; distinct.reserve(freq.size());
        for (auto &p : freq) distinct.push_back(p.first);

        
        Trie trie;
        trie.clear((distinct.size() + 5) * 32);
        for (auto &p : freq) trie.add(p.first, p.second);

        
        pair<int,int> top1 = {-1, -1}; 
        pair<int,int> top2 = {-1, -1};
        for (int v : distinct) {
            int sc = S ^ v;
            if (sc > top1.first) { top2 = top1; top1 = {sc, v}; }
            else if (sc > top2.first) { top2 = {sc, v}; }
        }

        int answer = 0;
        
        for (int a : distinct) {
            int Tgt = S ^ a;

            auto q1 = trie.queryMin(Tgt);
            int m1 = q1.first;       
            int bstar = q1.second;   
            int c = freq[bstar];

            
            int best_not_b = -1;
            if (top1.second != bstar) best_not_b = top1.first;
            else if (top2.first != -1) best_not_b = top2.first;

            int r1 = (best_not_b == -1) ? -1 : min(m1, best_not_b);

            
            int m2prime;
            if (c >= 2) {
                m2prime = m1; 
            } else {
                trie.add(bstar, -1);
                auto q2 = trie.queryMin(Tgt);
                m2prime = q2.first;   
                trie.add(bstar, +1);
            }
            int r2 = min(S ^ bstar, m2prime);

            int val_a = max(r1, r2);
            answer = max(answer, val_a);
        }

        cout << answer << '\n';
    }
    return 0;
}
