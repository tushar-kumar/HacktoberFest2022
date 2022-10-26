// Count Palindromic Substrings in a given String
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int countPS(string str)
    {
        int n = str.length();
        long long mod = 1000000007;
        vector<vector<int>> dp(n, vector<int>(n + 1, 1));
        long long count = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n; j >= i; j--)
            {
                if (dp[i + 1][j - 1] == 1)
                {
                    if (str[i] == str[j - 1])
                    {
                        count = (count + 1) % mod;
                    }
                    else
                        dp[i][j] = 0;
                }
            }
        }
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout << ans << endl;
    }
}
