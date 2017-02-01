//
//  LUNCHBOX.cpp
//  ProblemSolving
//
//  Created by mindol on 2017. 2. 1..
//  Copyright © 2017년 mindol. All rights reserved.
//

/*
 
 2
 3
 2 2 2
 2 2 2
 3
 1 2 3
 1 2 
 
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparison(pair<int, int> &left, pair<int, int> &right) {
    if (left.first > right.first) return true;
    if (left.first == right.first) return left.second < right.second;
    return false;
}

void solve(vector<int> &ovenTime, vector<int> &eatTime) {
    int len = ovenTime.size();
    vector<pair<int, int>> V;
    
    for (int i=0; i<len; i++) {
        V.push_back(make_pair(eatTime[i], ovenTime[i]));
    }
    
    sort(V.begin(), V.end(), comparison);
    
    int x = 0, solve = 0;
    
    for (int i=0; i<len; i++) {
        int f = V[i].first;
        int s = V[i].second;
        
        x += s;
        
        if (x + f > solve) {
            solve = x + f;
        }
    }
    printf("%d\n", solve);
}

int main(void) {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N;
        vector<int> ovenTime;
        vector<int> eatTime;
        
        scanf("%d", &N);
        
        for (int i=0; i<N; i++) {
            int temp;
            scanf("%d", &temp);
            ovenTime.push_back(temp);
        }
        
        for (int i=0; i<N; i++) {
            int temp;
            scanf("%d", &temp);
            eatTime.push_back(temp);
        }
        
        solve(ovenTime, eatTime);
    }
}
