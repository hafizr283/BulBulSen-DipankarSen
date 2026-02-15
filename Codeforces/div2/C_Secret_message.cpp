#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pb push_back
using namespace std;
bool check(vector<vector<int>> &freq, int d, int start_col, int col, int value)
{
    for (int i = start_col; i < col; i += d)
    {
        if (freq[i][value])
        {
        }
        else
            return false;
    }
    return true;
}
bool can_find_answer(int d, vector<string> &matrix, vector<vector<int>> &freq, int row, int col)
{
    int ok_count = 0;
    for (int col_id = 0; col_id < d; col_id++)
    {
        bool f=1;
        for (int i = 0; i < 26; i++)
        {
            if (freq[col_id][i] and check(freq, d, col_id, col, i))
            {
                f=0;

                ok_count++;
                break;
            }
        }
        if(f) break;
    }
    return ok_count == d;
}
void solve()
{
    int row, col;
    cin >> col >> row;
    vector<string> matrix;
    vector<vector<int>> freq(col + 1, vector<int>(26, 0));
    for (int i = 0; i < row; i++)
    {
        string temp;
        cin >> temp;
        matrix.push_back(temp);
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            freq[j][matrix[i][j] - 'a'] = 1;
        }
    }
    int ans_d = col;
    for (int d = 1; d <= col; d++)
    {
        if (col%d==0 and can_find_answer(d, matrix, freq, row, col))
        {
            ans_d = d;
            break;
        }
    }
    // cout << ans_d << nl;
    string s;
    for (int i = 0; i < ans_d; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (freq[i][j] and check(freq, ans_d, i, col, j))
            {
                s.push_back(j + 'a');
                break;
            }
        }
    }
    // cout<<s<<nl;

    for(int i=0;i<col/s.size();i++){
        cout<<s;
    }
    cout<<nl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}