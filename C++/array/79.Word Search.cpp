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
 https://leetcode-cn.com/problems/word-search/
 Given a 2D board and a word, find if the word exists in the grid.
 
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 
 Example:
 
 board =
 [
 ['A','B','C','E'],
 ['S','F','C','S'],
 ['A','D','E','E']
 ]
 
 Given word = "ABCCED", return true.
 Given word = "SEE", return true.
 Given word = "ABCB", return false.
 
 思路:从中心点发散去找,朝着四个方向。
 为了不往回走，我们使用了一个state的矩阵来保存使用过的点.
 */

vector<vector<char>> board{
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
};
//vector<vector<char>> board{{'a','a'}};
bool exist(vector<vector<char>>& board, vector<vector<bool>>state, string word,int i, int j , int ct_index);
bool exist(vector<vector<char>>& board, string word) {
    
    vector<bool> s(board[0].size(),false);
    vector<vector<bool>> useState(board.size(),s);
    for (int i = 0; i < board.size(); i++) {
        for (int j= 0; j < board[0].size(); j++) {
            //从上下左右发散出去.
            if (exist(board,useState, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

bool exist(vector<vector<char>>& board, vector<vector<bool>>state, string word,int i, int j , int ct_index){
    if (ct_index == word.size()) {
        return true;
    }
    if (i >= board.size() ||
        j >= board[0].size() ||
        i < 0 ||
        j < 0 ||
        board[i][j] != word[ct_index]||
        state[i][j]) {
        return false;
    }
    state[i][j] = true;
    bool result = exist(board,state, word, i+1, j, ct_index+1) ||
    exist(board,state, word, i-1, j, ct_index+1) ||
    exist(board,state, word, i, j+1, ct_index+1) ||
    exist(board,state, word, i, j-1, ct_index+1);
    state[i][j] = false;
    return result;
}
int main(int argc, const char * argv[]) {
    cout << exist(board, "SEE");
    return 0;
}
