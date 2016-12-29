//
//  LargestPrime.cpp
//  ProblemSolving
//
//  - 가장 큰 소인수 요소 값 구하기
//  Key Idea..
//  1. 소수 값에서 숫자 2만 짝수이다.
//  2. 어떤 소수로 값이 나뉘면 다음 소수 판별을 위해 해당 값으로 나뉘지 않을 때 까지 계속 나눈다.
//  3. 소수 리스트중에 2만 짝수이므로, 다음 소수를 찾을 때는 3부터 +2씩 계산한다.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n = 600851475143;
    long long lastFactor;
    // 우선 주어진 값을 2로 나누는 과정
    if ( n % 2 == 0) {
        lastFactor = 2;
        n /= 2;
        while (n % 2 == 0) {
            n /= 2;
        }
    } else {
        lastFactor = 1;
    }
    
    // 3부터 시작
    long long factor = 3;
    while (n > 1) {
        if ( n % factor == 0) {
            lastFactor = factor;
            n /= factor;
            // 해당 factor로 나뉘지 않을 때까지 계속 나눈다.
            while (n % factor == 0) {
                n /= factor;
            }
        }
        factor = factor + 2;
    }
    
    cout << lastFactor << endl;
    return 0;
}
