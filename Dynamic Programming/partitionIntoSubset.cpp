#include <iostream>
#include <vector>
using namespace std;
void solve(int n, int k)
{
    if (k == 1 || k == n)
    {
        cout << "1\n";
        return;
    }
    if (n < k || n == 0 || k == 0)
    {
        cout << "0\n";
        return;
    }
    vector<vector<long>> dp(k + 1, vector<long>(n + 1, 0));
    for (int i = 1; i <= k; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (j < i)
                dp[i][j] = 0;
            else if (i == j)
                dp[i][j] = 1;
            else
            {
                dp[i][j] = i * dp[i][j - 1] + dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[k][n] << "\n";
}
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    solve(n, k);
}