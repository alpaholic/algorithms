/*
    https://www.acmicpc.net/problem/1509
*/
#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<int> dp;
vector<vector<int>> cache;
string input;

int isPalin(int i, int j) {
    if (i == j)
        return 1;
    else if ( (i+1) == j) {
        if (input[i-1] == input[j-1])
            return 1;
        else
            return 0;
    }
    
    int &ret = cache[i][j];
    if (ret != -1) return ret;
    if (input[i-1] != input[j-1]) return ret = 0;
    else return ret = isPalin(i+1, j-1);
}

int solve(int N) {
    dp[0] = 0;
    for (int i=1; i<=N; i++) {
        dp[i] = -1;
        for (int j=1; j<=i; j++) {
            if (isPalin(j, i)) {
                if (dp[i] == -1 || dp[i] > dp[j-1] + 1) {
                    dp[i] = dp[j-1] + 1;
                }
            }
        }
    }
    
    return dp[N];
}

int main(void) {
    cin >> input;
    dp.assign(input.length()+1, 0);
    cache.assign(input.length()+1, vector<int>(input.length()+1, -1));
    
    printf("%d\n", solve(input.length()));
    return 0;
}
