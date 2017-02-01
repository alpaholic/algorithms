//
//  MATCHORDER.cpp
//  ProblemSolving
//
//  Created by mindol on 2017. 2. 1..
//  Copyright © 2017년 mindol. All rights reserved.
//

/*
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int C, N;
vector<int> russian;
list<int> korean;

void solve() {
    int sol = 0;
    
    for (int i=0; i<N; i++) {
        int x = russian[i];
        bool isFind = false;
        
        for (auto it=korean.begin(); it != korean.end(); it++) {
            if (*it >= x) {
                korean.erase(it);
                sol++;
                isFind = true;
                break;
            }
        }
        
        if (!isFind) {
            korean.erase(korean.begin());
        }
    }
    printf("%d\n", sol);
}

int main(void) {
    
    scanf("%d", &C);
    while (C--) {
        scanf("%d", &N);
        russian.clear();
        korean.clear();
        
        for (int i=0; i<N; i++) {
            int temp;
            scanf("%d", &temp);
            russian.push_back(temp);
        }
        
        for (int i=0; i<N; i++) {
            int temp;
            scanf("%d", &temp);
            korean.push_back(temp);
        }
        
        korean.sort();
        solve();
    }
    
    return 0;
}
*/
