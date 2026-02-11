#include <bits/stdtr1c++.h>
using namespace std;
int tree[100];
int build_seg(int arr[], int l, int r, int v = 1)
{
    if (l == r)
    {
        tree[v] = arr[l];
        return tree[v];
    }
    int left = build_seg(arr, l, (l + r) / 2, 2 * v);
    int right = build_seg(arr, (l + r) / 2 + 1, r, 2 * v + 1);
    tree[v] = left + right;
    return tree[v];
}

int sum(int tl, int tr, int l, int r, int v = 1)
{
    if (l <= tl and r >= tr)
    {
        return tree[v];
    }
    if (r < tl or l > tr)
        return 0;
    int left = sum(tl, (tl + tr) / 2, l, r, 2 * v);
    int right = sum((tl + tr) / 2 + 1, tr, l, r, 2 * v + 1);
    return left + right;
}

void update(int tl, int tr, int pos, int new_val, int v = 1)
{
    if (tl == tr)
    {
        tree[v] = new_val;
        return;
    }
    int mid = (tl + tr) / 2;
    if (tl <= pos and pos <= mid)
        update(tl, mid, pos, new_val, 2 * v);
    else
        update(mid + 1, tr, pos, new_val, 2 * v + 1);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build_seg(arr, 0, n - 1);
    for (int i = 0; i < 4 * n; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    cout << sum(0, n - 1, 1, 3);
    update(0, n - 1, 1, 50, 1);
    cout << sum(0, n - 1, 1, 1) << endl;
}