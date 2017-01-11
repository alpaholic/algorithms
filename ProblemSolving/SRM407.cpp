//
//  SRM407.cpp
//  ProblemSolving
//
//  Created by mindol on 2017. 1. 11..
//  Copyright © 2017년 mindol. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class CorporationSalary {
    vector<long long> cache;
    long long process(const vector<string> &relations, int N) {
        long long &ret = cache[N];
        // 이미 계산된 값이면 바로 리턴
        if (ret != -1)
            return ret;
        
        ret = 0;
        for (int i=0; i<relations.size(); i++) {
            if (relations[N][i] == 'Y') {
                // 매니저 관계가 있으면 재귀 호출
                ret += process(relations, i);
            }
        }
        
        return ret;
    }
public:
    long long totalSalary(vector<string> relations) {
        int nLen = relations.size();
        long long ans = 0;
        // 메모리제이션용 변수 초기화
        cache.assign(nLen, -1);
        
        for (int i=0; i<nLen; i++) {
            bool isAllN = true;
            for (int j=0; j<nLen; j++) {
                if (relations[i][j] == 'Y') {
                    isAllN = false;
                    break;
                }
            }
            if (isAllN) { // 부하가 없는 직원들에 대해 봉급을 1로 설정
                cache[i] = 1;
            }
        }
        
        for (int i=0; i<nLen; i++) {
            ans += process(relations, i);
        }
        
        return ans;
    }
};

int main(void)
{
    CorporationSalary c;
    vector<string> relations = {
        "NNNN",
        "NNNN",
        "NNNN",
        "NNNN"
    };
    cout << c.totalSalary(relations) << endl;
    
    return 0;
}
