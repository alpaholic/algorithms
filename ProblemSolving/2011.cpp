
/*
    https://www.acmicpc.net/problem/2011 (암호코드 문제)
    <algorithm>
        - DP[N]: N번째 자리에서 만들 수 있는 최대 암호의 수
        - DP[N] = DP[N-1] + DP[N-2], 기본 점화식을 사용하지만, 예외 케이스에 대해서 처리해야 한다.
        - 예외 케이스 1) 마지막 끝나는 자리수가 0인 경우 (10, 20)
        -             DP[i] += DP[i-2] 처리, 만약 10, 20이 아닌 다른 수의 경우는 0으로 리턴한다. (일어날 수 없는 암호)
        - 예외 케이스 2) 두자리수가 암호가 안되는 경우 ( 즉, 11 <= X <= 26 이 아닌 경우)
        -             DP[i] += DP[i-2] 처리를 안한다.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int mod = 1000000;
vector<int> DP;

int solve(string N) {
    int sLength = N.size();
    
    if (sLength == 1 && stoi(N) == 0)
        return 0;
    
    DP.assign(sLength+1, 0);
    DP[0] = 1;
    DP[1] = 1;
    
    for (int i=2; i<=sLength; i++) {
        int firstValue = stoi(N.substr(i-1, 1));
        if (firstValue == 0) {
            int secondValue = stoi(N.substr(i-2, 2));
            if (secondValue == 10 || secondValue == 20) {
                DP[i] += DP[i-2];
                DP[i] %= mod;
            } else {
                return 0;
            }
        } else {
            DP[i] += DP[i-1];
            DP[i] %= mod;
            
            int secondValue = stoi(N.substr(i-2, 2));
            if (secondValue >= 11 && secondValue <= 26) {
                DP[i] += DP[i-2];
                DP[i] %= mod;
            }
        }
    }
    
    return DP[sLength] % mod;
}


int main(void) {
    string N;
    cin >> N;
    printf("%d\n", solve(N));
    return 0;
}
