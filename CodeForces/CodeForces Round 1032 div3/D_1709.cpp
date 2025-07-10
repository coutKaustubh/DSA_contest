#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]

#define create_matrix(mat, n, m) vector<vector<ll>> mat(n, vector<ll>(m));
#define input_matrix(mat, n, m) f(i, n) f(j, m) cin >> mat[i][j];

#define MOD (1000000007)
#define INF 1000000000000000000LL 
#define mp make_pair
#define nline '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 && a[j] < a[j - 1]) {
            swap(a[j], a[j - 1]); 
            j--;
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    iv(a, n);
    iv(b, n);
    ll c =0;
    vector<pair<ll,ll>>op;
    bool swapped;
      do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                op.push_back({1,i+1});
                swap(a[i], a[i + 1]);
                c++;
                swapped = true;
            }
        }
    } while (swapped);

       do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (b[i] > b[i + 1]) {
                op.push_back({2,i+1});
                swap(b[i], b[i + 1]);
                c++;
                swapped = true;
            }
        }
    } while (swapped);

    f(i,n){
        if(a[i]>b[i]){
            op.push_back({3,i+1});
            swap(a[i],b[i]);
            c++;
        }
    }
    cout<<c<<endl;
    for (auto p : op) {
        cout<< p.first << " "<< p.second<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}