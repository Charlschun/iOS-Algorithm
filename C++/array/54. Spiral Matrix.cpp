//
//  main.cpp
//  LeetCode
//
//  Created by junl on 2019/1/21.
//  Copyright © 2019 junl. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
using namespace std;
/*
 https://leetcode-cn.com/problems/spiral-matrix/
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 
 Example 1:
 
 Input:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 Output: [1,2,3,6,9,8,7,4,5]
 Example 2:
 
 Input:
 [
 [1, 2, 3, 4],
 [5, 6, 7, 8],
 [9,10,11,12]
 ]
 Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */
vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    if (matrix.empty()) {
        return {};
    }
    int top,bottom,left,right;
    top = left = 0;
    bottom = matrix.size() - 1;
    right = matrix[0].size() - 1;
    
    vector<int> results;
    //顺序总是向右，向下，向左，向上
    int direction = 0;
    while (true) {
        if (direction == 0) {//向右
            for (int i = left; i <= right; i++) {
                results.push_back(matrix[top][i]);
            }
            top++;
        }else if (direction == 1){//向下
            for (int i = top; i <= bottom; i++) {
                results.push_back(matrix[i][right]);
            }
            right--;
        }else if (direction == 2){//向左
            for (int i = right; i >= left; i--) {
                results.push_back(matrix[bottom][i]);
            }
            bottom--;
        }else{//向上
            for (int i = bottom; i >= top; i--) {
                results.push_back(matrix[i][left]);
            }
            left++;
        }
        if (left > right || top > bottom) {
            return results;
        }
        direction = (direction + 1)%4;
    }
    return results;
}
int main(int argc, const char * argv[]) {
    vector<int> a = spiralOrder({{1,2,3},{4,5,6},{7,8,9}});
    return 0;
}
