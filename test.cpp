#include <bits/stdc++.h>
#define ll long long
#define inf 998244353
#define nl endl
using namespace std;
#define print_array(arr)   \
    for (auto value : arr) \
        cout << value << ' ';
#define input_array(arr)    \
    for (auto &value : arr) \
        cin >> value;
#define test cout << "test" << nl
bool isPowerTwo(ll x)
{
    return (x * 1LL && !(x * 1LL & (x - 1)));
}
ll digit_count(ll n)
{
    ll cnt = 0;
    while (n > 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}
vector<pair<ll, bool>> v[200005];
ll vis[200005];
ll pos;
ll neg;
ll p[200005];

void dfs(int ver)
{
    vis[ver] = 1;
    for (auto child : v[ver])
    {
        if (vis[child.first])
            continue;
        ll uu = ver;
        ll vv = child.first;
        bool shift = child.second;
        if (shift)
        {
            if (p[uu] != 10000000)
            {
                if (vv > uu)
                {
                    p[vv] = neg;
                    neg--;
                }
                else
                {
                    pos++;
                }
            }
            else
            {
                if (vv > uu)
                {
                    p[uu] = pos;
                    pos++;
                }
                else
                {
                    p[uu] = neg;
                    neg--;
                }
            }
        }
        else
        {
            if (p[uu] != 10000000)
            {
                if (vv < uu)
                {
                    p[vv] = neg;
                    neg--;
                }
                else
                {
                    p[vv] = pos;
                    pos++;
                }
            }
            else
            {
                if (vv < uu)
                {
                    p[uu] = pos;
                    pos++;
                }
                else
                {
                    p[uu] = neg;
                    neg--;
                }
            }
        }
        dfs(vv);
    }
}
vector<ll> generate(ll n)
{
    vector<ll> ans;
    for (ll i = n; i >= 0; i -= 2)
    {

        ans.push_back(i);
    }
    return ans;
}
ll calc_dist(int x1, int y1, int x2, int y2, int d1, int d2)
{
    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << d1 << " " << d2 << nl;
    return max(max(abs(d1 - x1), abs(d2 - y1)), max(abs(d1 - x2), abs(d2 - y2)));
}
bool f(int i, int k, string s)
{
    k--;
    for (int ii = i - 1; ii >= 0 and ii >= i - k; ii--)
    {

        if (s[ii] == '1')
        {
            return 0;
        }
    }
    return 1;
}
void solve()
{
    int n = 150;
    for (int i = 1; i <= n; i++)
    {
        if ((i ^ n) <= n and (i + (i ^ n)) > n)
            cout << i << ' ' << (i ^ n) << ' ' << (i + (i ^ n)) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    // init_fibo();
    // expo_init();

    while (t--)
    {
        solve();
    }

    return 0;
}

// 1 1 2 2 3 3 4 4
//   1   2   3   4