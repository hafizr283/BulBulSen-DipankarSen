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

bool check(ll a0, ll a1, ll k)
{
    return (a1 - k) >= (a0 % k);
}

vector<ll> dj[18];
void init_pop()
{
    for (ll i = 0; i <= (1 << 16 - 1); i++)
    {

        dj[(__popcount(i))].push_back(i);
    }
    for (ll i = 0; i <= 17; i++)
    {
        sort(dj[i].begin(), dj[i].end());
    }
}

void spf()
{
    vector<ll> spf(200005, 0);
    for (ll i = 2; i <= 200000; i++)
    {
        if (spf[i] == 0)
        {
            for (ll j = i; j <= 200000; j += i)
            {
                if (spf[j] == 0)
                {
                    spf[j] = i;
                }
            }
        }
    }
    ll number;
    cin >> number;
    while (number > 1)
    {
        cout << spf[number] << " ";
        number /= spf[number];
    }
}
void primeFactorization(ll n)
{
    while (n % 2 == 0)
    {
        cout << "2 ";
        n /= 2;
    }
    for (ll i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            n /= i;
            cout << i << ' ';
        }
    }
    if (n != 1)
        cout << n << ' ' << nl;
}

ll binExp(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
bool isCrash(int arr[], vector<pair<int, int>> &v, int nth_operation, int max_val, int n)
{
    vector<int> brr;

    for (int i = 0; i < n; i++)
    {
        brr.push_back(arr[i]);
    }

    for (int i = nth_operation; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        brr[x - 1] += y;
        if (brr[x - 1] > max_val)
        {
            return true;
        }
    }
    return false;
}

int binaryMon(int arr[], vector<pair<int, int>> &op_v, int max_val, int n)
{
    int ans = -1;
    int left = 0, right = op_v.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (isCrash(arr, op_v, mid, max_val, n))
        {
            left = mid + 1;
        }
        else
        {
            ans = mid;
            right = mid - 1;
        }
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    ll temp = n;
    vector<ll> arr;
    ll mark = 10;
    for (int i = 0; i <= 10; i++)
    {
        arr.push_back(mark - 1);
        mark *= 10;
    }
    reverse(arr.begin(), arr.end());

    for (int i = 0; i <= 10; i++)
    {
        ll xx = (n / arr[i]);

        if (xx > 0 and xx <= 9)
            n -= xx * arr[i];

        // cout << "xx" << xx << " " << n << " " << arr[i] << nl;
    }
    if (n == 0)
        cout << 10 << nl;
    else
        cout << 0 << nl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // primeFactorization(100000000);
    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}

// 1 1 2 2 3 3 4 4
//   1   2   3   4