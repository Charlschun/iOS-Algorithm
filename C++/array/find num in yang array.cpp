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
using namespace std;

/*
  题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */
const int N = 3;
const int M = 3;

bool findNum(int nums[N][M], int target){
    //从左到右递增.
    //从上到下递增.
    
    //我们选择左下角作为起始点
    int i = N - 1;
    int j = 0;
    while (i >= 0 && j < M) {
        if (nums[i][j] == target) {
            return true;
        }else if (nums[i][j] < target){
            j++;
        }else{
            i--;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    //1,2,3
    //4,5,6
    //7,8,9
    int nums[N][M] = {{1,2,3},{4,5,6},{7,8,9}};
    cout << findNum(nums, 5) << endl;
    return 0;
}
