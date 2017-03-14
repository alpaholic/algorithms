/*
    - O(1) palindrome
    - dp[i][j] => A[i] ~ A[j]의 palindrome 여부
    - 길이가 1 => O
    - 길이가 2 => A[i] == A[i+1] => O
                else => X
    - 길이가 3이상 => 두 가지 조건을 만족하면 palindrome
                => 1. A[i] == A[j]
                   2. DP[i+1][j-1]이 palindrome 인경우
 
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> A;
vector<vector<int>> dp;

int isPalin(int i, int j) {
    if (i==j) {
        return 1;
    } else if ((i+1) == j) {
        if (A[i] == A[j])
            return 1;
        else
            return 0;
    }
    
    int &ret = dp[i][j];
    if (ret != -1)
        return ret;
    
    if (A[i] != A[j]) return ret = 0;
    else return ret = isPalin(i+1, j-1);
}
