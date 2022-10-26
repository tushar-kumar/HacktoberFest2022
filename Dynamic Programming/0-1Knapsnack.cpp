#include <bits/stdc++.h>
using namespace std;
int maximum(int a, int b)
{
    return a > b ? a : b;
}
// 0-1 knapsack me repetition is not allowed so it is similar to target sum subset and 2d dp is used
void knapSnack(int n, int weight[], int value[], int capacity)
{
    // int dp[n + 1][capacity + 1]={0};
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    int take = 0;
    int notTake = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            notTake = dp[i - 1][j];
            if (j >= weight[i - 1])
                take = value[i - 1] + dp[i - 1][j - weight[i - 1]];
            else
                take = 0;
            dp[i][j] = maximum(take, notTake);
        }
    }
    cout << dp[n][capacity] << "\n";
}
// unbounded knapsack can be solved like coin change (both combination and permuation logic give same answer here)
void unboundedKnapSack1(int n, int value[], int weight[], int capacity)
{
    // combination wala logic
    vector<int> dp(capacity + 1, 0);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (weight[i] <= j)
            {
                dp[j] = maximum(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[capacity] << "\n";
}
void unboundedKnapSack2(int n, int value[], int weight[], int capacity)
{
    // permutation wala logic
    vector<int> dp(capacity + 1, 0);
    dp[0] = 0;
    for (int cap = 1; cap <= capacity; cap++)
    {
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            if (weight[i] <= cap)
            {
                int remaining_cap = cap - weight[i];
                int remaining_value = dp[remaining_cap];
                int total_value = remaining_value + value[i];

                if (total_value > max)
                {
                    max = total_value;
                }
            }
        }
        dp[cap] = max;
    }
    cout << dp[capacity] << "\n";
}
/*
Fractional knapsack : Can be solved using greedy.
Approach:
The basic idea of the greedy approach is to calculate the ratio value/weight for each item and sort the item on the basis of this ratio. Then take the item with the highest ratio and add them until we can’t add the next item as a whole and at the end add the next item as much as we can. Which will always be the optimal solution to this problem.
*/