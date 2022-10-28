#include <bits/stdc++.h>
using namespace std;
// method1 : using recursion
void printTargetSumSubset(int arr[], int n, int idx, string set, int sos, int target)
{
    if (sos > target)
    {
        return;
    }
    if (idx == n)
    {
        if (sos == target)
        {
            cout << set << "\n";
        }
        return;
    }
    printTargetSumSubset(arr, n, idx + 1, set + to_string(arr[idx]) + ", ", sos + arr[idx], target);
    printTargetSumSubset(arr, n, idx + 1, set, sos, target);
}
// memoization utility function
bool func(int ind, int target, int arr[], vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return (arr[0] == target);
    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }
    bool notTake = func(ind - 1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target)
        take = func(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = take | notTake;
}
// memoization
bool targetSumMemo(int arr[], int n, int index, int target, vector<vector<int>> &dp)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return func(n - 1, target, arr, dp);
}
// method 3: using dp (this function returns true if it is possible to obtain the target)
// tabulation function 1
void targetSumDp(int arr[], int n, int target)
{
    bool dp[n + 1][target + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j == 0)
            {
                dp[i][j] = true;
            }
            else
            {
                if (dp[i - 1][j] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    int val = arr[i - 1];
                    if (j >= val)
                    {
                        if (dp[i - 1][j - val] == true)
                        {
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
    }
    cout << dp[n][target] << "\n";
}
// tabulation function 2
bool targetSumTab(int n, int target, int ind, int arr[])
{
    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= target)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = take | notTake;
        }
    }
    return dp[n - 1][target];
}
// space optimisation
bool targetSumTabSo(int n, int target, int ind, int arr[])
{
    vector<bool> prev(target + 1, 0), curr(target + 1, 0);
    prev[0] = curr[0] = 1;
    prev[arr[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];
            curr[target] = take | notTake;
        }
        prev = curr;
    }
    return prev[target];
}
int main()
{
    int arr[] = {4, 2, 7, 1, 3};
    int a[] = {10, 20, 30, 40, 50};
    int n = 5;
    targetSumDp(arr, n, 10);
    targetSumDp(a, 5, 70);
    vector<vector<int>> dp;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << targetSumMemo(arr, n, 4, 10, dp);
    return 0;
}