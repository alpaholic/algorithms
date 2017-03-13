/*
    https://www.acmicpc.net/problem/1912 (연속합을 구하는 문제)
    <algorithm>
        - DP[N]: 현재의 위치에서 연속되는 수의 최대합
        - DP[N] = max(DP[N-1]+A[N], A[N]): 이전의 연속되는 수의 최대합과 현재의 값을 더한 수와, 현재 값만 더했을 때 (즉, 연속을 꺠버린다는 뜻) 최대 값을 저장
        - A[N]이 max값이 되는 경우는 이전의 값이 -인 경우가 된다고 생각하자.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> DP;
vector<int> A;

int solve(int N) {
    DP[0] = A[0];
    for (int i=1; i<N; i++) {
        DP[i] = max(DP[i-1] + A[i], A[i]);
    }
    
    int ans = DP[0];
    for (int i=1; i<N; i++) {
        ans = max(ans, DP[i]);
    }
    
    return ans;
}

int main(void) {
    int T;
    scanf("%d", &T);
    
    DP.assign(T, 0);
    A.assign(T, 0);
    
    for (int i=0; i<T; i++) {
        int temp;
        scanf("%d", &temp);
        A[i] = temp;
    }
    printf("%d\n", solve(T));
    return 0;
}
