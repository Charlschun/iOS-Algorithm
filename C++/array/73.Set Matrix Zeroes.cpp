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
using namespace std;
/*
 https://leetcode-cn.com/problems/set-matrix-zeroes/
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 
 Example 1:
 
 Input:
 [
 [1,1,1],
 [1,0,1],
 [1,1,1]
 ]
 Output:
 [
 [1,0,1],
 [0,0,0],
 [1,0,1]
 ]
 Example 2:
 
 Input:
 [
 [0,1,2,0],
 [3,4,5,2],
 [1,3,1,5]
 ]
 Output:
 [
 [0,0,0,0],
 [0,4,5,0],
 [0,3,1,0]
 ]
 */
void setZeroes(vector<vector<int>>& matrix) {
    
    bool rowHasZero = false;
    bool columnHasZero = false;
    //第一行是否需要归零
    for (int i = 0; i < matrix[0].size(); i++) {
        if (matrix[0][i] == 0) {
            rowHasZero = true;
            break;
        }
    }
    
    for ( int i = 0; i < matrix.size(); i++) {
        if (matrix[i][0] == 0) {
            columnHasZero = true;
            break;
        }
    }
    
    //除了第一行第一列的信息保存到第一行/第一列中
    for (int i = 1;  i < matrix.size(); i ++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    //如果存在，则将对应位置置为0
    for (int i = 1;  i < matrix.size(); i ++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    if (rowHasZero) {
        for (int i = 0; i < matrix[0].size(); i++) {
            matrix[0][i] = 0;
        }
    }
    if (columnHasZero) {
        for ( int i = 0; i < matrix.size(); i++) {
            matrix[i][0] = 0;
        }
    }
}
int main(int argc, const char * argv[]) {
    return 0;
}
