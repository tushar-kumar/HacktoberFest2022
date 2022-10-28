#include <iostream>
using namespace std;

void coinChangeCombination(int dimensions[], int n, int amt)
{
    int dp[amt + 1] = {0};
    dp[0] = 1; // there's one way to get zero amount irrespective of the coin dimensions
    for (int i = 0; i < n; i++)
    {
        for (int j = dimensions[i]; j <= amt; j++)
        {
            dp[j] += dp[j - dimensions[i]];
        }
    }
    cout << "No.of ways to pay the amount using giving dimensions: " << dp[amt] << "\n";
}
void coinChangePermutation(int coins[], int n, int target)
{
    int dp[target + 1] = {0};
    dp[0] = 1;
    for(int amt = 1; amt<= target; amt++){
        for(int i = 0; i<n; i++){
            int coin = coins[i];
            if(coin <= amt){
                int remaining_amt = amt - coin;
                dp[amt] += dp[remaining_amt];
            }
        }
    }
    cout << "Total Permutations: " << dp[target] << "\n";
}
int main()
{
    int n;
    cout << "Enter the no.of coins: ";
    cin >> n;
    int *dimensions = new int[n];
    cout << "Enter dimensions of the coins: ";
    for (int i = 0; i < n; i++)
    {
        cin >> dimensions[i];
    }
    int amt;
    cout << "Enter the amount: ";
    cin >> amt;
    coinChangeCombination(dimensions, n, amt);
    coinChangePermutation(dimensions, n, amt);
    return 0;
}
// difference between this and target sum subset is that here duplicacy of coins is allowed 