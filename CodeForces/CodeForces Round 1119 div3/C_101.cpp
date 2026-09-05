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

void solve()
{
    ll n;
    cin >> n;
    iv(a, n);
    vector<int> ones;
    for (int i = 0; i < n; i++)
{
        if (a[i] == 1)
            ones.push_back(i);
    }

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            ans[i] = 1;
    }

    if (ones.empty())
    {

        int first = -1;
        int last = -1;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1)
            {
                first = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == -1)
            {
                last = i;
                break;
            }
        }

        if (first == -1)
        {
        }

        else if (first == last)
        {
            ans[first] = 1;
        }

        else
        {
            ans[first] = 1;
            ans[last] = 1;
        }

        for (int x : ans)
            cout << x << " ";

        cout << "\n";
        return;
    }

    int bestL = -1;
    int bestR = -1;
    int bestLen = 0;

    for (int i = 0; i + 1 < (int)ones.size(); i++)
    {

        int l = ones[i];
        int r = ones[i + 1];

        int len = r - l + 1;

        if (len > bestLen)
        {
            bestLen = len;
            bestL = l;
            bestR = r;
        }
    }

    int firstOne = ones.front();

    for (int i = 0; i < firstOne; i++)
    {
        if (a[i] == -1)
        {
            int len = firstOne - i + 1;

            if (len > bestLen)
            {
                bestLen = len;
                bestL = i;
                bestR = firstOne;
            }

            break;
        }
    }

    int lastOne = ones.back();

    for (int i = n - 1; i > lastOne; i--)
    {
        if (a[i] == -1)
        {
            int len = i - lastOne + 1;

            if (len > bestLen)
            {
                bestLen = len;
                bestL = lastOne;
                bestR = i;
            }

            break;
        }
    }

    if (bestL != -1)
    {

        ans[bestL] = 1;
        ans[bestR] = 1;

        for (int i = bestL + 1; i < bestR; i++)
        {
            ans[i] = 0;
        }
    }

    for (int x : ans)
        cout << x << " ";

    cout << "\n";
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