//
//  11053.cpp
//  AlgorithmStudy
//
//  Created by mindol on 2017. 3. 13..
//  Copyright © 2017년 mindol. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;
vector<int> DP;

int solve(int N) {
    int ans = 0;
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<i; j++) {
            if (A[i] > A[j]) {
                DP[i] = max(DP[i], DP[j]);
            }
        }
        
        DP[i] = DP[i] + 1;
        ans = max(ans, DP[i]);
    }
    
    return ans;
}

int main(void) {
    int N;
    scanf("%d", &N);
    
    A.assign(N+1, 0);
    DP.assign(N+1, 0);
    
    for (int i=1; i<=N; i++) {
        int temp;
        scanf("%d", &temp);
        A[i] = temp;
    }
    
    printf("%d\n", solve(N));
    return 0;
}
