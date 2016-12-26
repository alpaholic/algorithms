//
//  2346.cpp
//  ProblemSolving
//
//  Created by mindol on 2016. 12. 26..
//  Copyright © 2016년 mindol. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(void) {
    list<pair<int, int>> balloon; // 풍선 값 저장
    list<pair<int, int>>::iterator iter;
    vector<int> result; // 결과 값 출력 용
    
    int N, inValue;
    int indexing;
    
    cin >> N;
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        balloon.push_back(make_pair(i+1, temp));
    }
    
    iter = balloon.begin();
    while (true) {
        inValue = (*iter).second;
        result.push_back((*iter).first);
        
        iter = balloon.erase(iter);
        N--;
        
        if (N==0) {
            break;
        }
        
        if (inValue > 0) {
            // 이전에 삭제한 요소가 원형 큐의 마지막 요소였으면, 다시 처음으로
            if (iter == balloon.end()) {
                iter = balloon.begin();
            }
            
            // 원형 큐의 이동 횟수를 계산 (나머지 연산을 하므로 inValue가 상수 시간 안에 진행될 수 있다.
            indexing = (inValue - 1) % N;
            for (int i=0; i<indexing; i++) {
                advance(iter, 1);
                if (iter == balloon.end()) { // 앞으로 이동하다가 끝에 오면 다시 처음으로
                    iter = balloon.begin();
                }
            }
            
        } else {
            // 이전에 삭제한 요소가 원형 큐의 첫 요소였으면, 마지막으로
            if (iter == balloon.begin()) {
                iter = balloon.end();
            }
            advance(iter, -1); // iter 가 오른쪽으로 증가됐기 때문에, 왼쪽으로 이동 시킨다.
            
            indexing = (inValue + 1) % N;
            indexing = abs(indexing);
            for (int i=0; i<indexing; i++) {
                if (iter == balloon.begin()) { // 뒤로 이동하다가 처음으로 오면 다시 맨 뒤로
                    iter = balloon.end();
                }
                advance(iter, -1);
            }
        }
        
    }
    for (auto x : result) {
        cout << x << " ";
    }
    
    cout << endl;
    return 0;
}
