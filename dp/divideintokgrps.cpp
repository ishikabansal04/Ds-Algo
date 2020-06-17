
#include <iostream>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

using namespace std;

int divideInKGroups(int n, int k)
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[i][j] += dp[i - 1][j - 1] + dp[i][j - 1] * i;
        }
    }
    return dp[k][n];
}

int main(){
    cout<<divideInKGroups(5,2);
}