//
//  SRM453.cpp
//  ProblemSolving
//
//  Created by mindol on 2017. 1. 3..
//  Copyright © 2017년 mindol. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;



class MazeMaker {
public:
    int longestPath(vector <string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol);
};

int MazeMaker::longestPath(vector <string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol) {
    vector<vector<bool>> visited;
    vector<vector<int>> weight;
    queue<pair<int, int>> Q;
    
    int row = maze.size();
    int col = maze[0].size();
    
    visited.assign(row, vector<bool>(col, false));
    weight.assign(row, vector<int>(col, 99999));

    visited[startRow][startCol] = true;
    weight[startRow][startCol] = 0;
    Q.push(make_pair(startRow, startCol));
    
    while (!Q.empty()) {
        int hereRow = Q.front().first;
        int hereCol = Q.front().second;
        int nMove = moveRow.size();
        
        for (int i=0; i<nMove; i++) {
            int thereRow = hereRow + moveRow[i];
            int thereCol = hereCol + moveCol[i];
            
            if (thereRow < 0 || thereCol < 0 || thereRow >= maze.size() || thereCol >= maze[0].size())
                continue;
            
            if (maze[thereRow][thereCol] == '.' && !visited[thereRow][thereCol]) {
                Q.push(make_pair(thereRow, thereCol));
                visited[thereRow][thereCol] = true;
                weight[thereRow][thereCol] = min(weight[thereRow][thereCol], weight[hereRow][hereCol]+1);
            }
        }
        Q.pop();
    }
    
    int ans = 0;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (maze[i][j] == '.') {
                if (weight[i][j] == 99999) {
                    ans = -1;
                    break;
                }
                ans = max(ans, weight[i][j]);
            }
        }
        if (ans == -1)
            break;
    }
    
    return ans;
}

int main(void) {
    MazeMaker m;
    vector <string> maze = {
        ".XXXXX."
    };
    int startRow = 0;
    int startCol = 0;
    vector<int> moveRow = {1, 0, 1, 0, 1, 0};
    vector<int> moveCol = {0, 1, 0, 1, 0, 1};
    
    cout << m.longestPath(maze, startRow, startCol, moveRow, moveCol) << endl;
    
    return 0;
}
