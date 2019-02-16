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
 https://leetcode-cn.com/problems/diagonal-traverse/
 https://www.cnblogs.com/yuzhenzero/p/9550938.html
 
 Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
 
 
 
 Example:
 
 Input:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 
 Output:  [1,2,4,7,5,3,6,8,9]
 
 */
vector<int> findDiagonalOrder(const vector<vector<int>>& matrix) {
    int M = matrix.size();
    int N = matrix[0].size();
    vector<int> r(M*N);
    int i=0,j=0;
    for (int k = 0; k < r.size(); k++) {
        r[k] = matrix[i][j];
        if ((i+j)%2==0) {
            //如果和为偶数的话，如果在第一行的话，向右，在最后一列向下，其他向右上
            if (j == N -1){
                i++;
            }else if (i == 0 ) {
                j++;
            }else{
                //+(-1,1)
                i--;
                j++;
            }
        }else{
            //如果为奇数的话，如果在第一列向下，r如果在最后一行向右，其他左下
            if (i == M -1){
                j++;
            }else if (j == 0) {
                i++;
            }else{
                i++;
                j--;
            }
        }
    }
    return r;
}
int main(int argc, const char * argv[]) {
    vector<int> r = findDiagonalOrder({{1,2},{3,4}});
    return 0;
}

