//
//  Word Search.m
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Word Search.h"
char map[3][4]  =
{
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
};
@implementation Word_Search

+ (BOOL)isWordSearch:(NSString *)word;
{
    /*
     For examp=
     
     [
     ['A','B','C','E'],
     ['S','F','C','S'],
     ['A','D','E','E']
     ]
     word = "ABCCED", -> returns true,
     word = "SEE", -> returns true,
     word = "ABCB", -> returns false.le,
     Given board
     */
    int M = 3;
    int N = 4;
    
    for (int i= 0 ; i < M ; i++) {
        for (int j = 0; j < N; j++) {
            if ([self isSearch:i j:j word:word index:0]) {
                return true;
            }
        }
    }
    return false;
}

+ (BOOL)isSearch:(NSInteger)i j:(NSInteger)j word:(NSString *)word index:(NSInteger)index{
    if (index == word.length) {
        return true;
    }
    if (i>=3 || j>=4 || i<0 ||j< 0 || map[i][j] != [word characterAtIndex:index]) {
        return false;
    }
    index++;
    return [self isSearch:i j:j+1 word:word index:index] || [self isSearch:i j:j-1 word:word index:index]|| [self isSearch:i-1 j:j word:word index:index]||[self isSearch:i+1 j:j word:word index:index];
    
}


//+(BOOL)isWordSearch:(NSString *)word {
//    char map[3][4]  =
//    {
//        {'A','B','C','E'},
//        {'S','F','C','S'},
//        {'A','D','E','E'}
//    };
//
//    //首先我们先定位i，j的位置
//    unichar fC = [word characterAtIndex:0];
//    int firstCharI,firstCharJ;
//    firstCharI = firstCharJ = -1;
//    for ( int i = 0; i < 3; i ++) {
//        for (int j = 0; j < 4; j ++) {
//            if (map[i][j] == fC) {
//                firstCharJ = j;
//                firstCharI = i;
//
//
//                int ct = 1;
//                while (ct < word.length) {
//                    unichar c  = [word characterAtIndex:ct];
//                    //判断c是否满足条件
//                    BOOL state1 =  map[firstCharI][firstCharJ-1] == c;
//                    BOOL state2 = map[firstCharI][firstCharJ+1] == c;
//                    bool state3 = map[firstCharI-1][firstCharJ]  == c;
//                    bool state4 =  map[firstCharI+1][firstCharJ] == c;
//                    if (state1) {
//                       firstCharJ = firstCharJ-1;
//                    }
//                    if (state2) {
//                        firstCharJ = firstCharJ+1;
//                    }
//                    if (state3) {
//                        firstCharI = firstCharI-1;
//                    }
//                    if (state4) {
//                        firstCharI = firstCharI+1;
//                    }
//                    if (state1 || state2 || state3 || state4) {
//                    }else{
//                        return false;
//                    }
//
//
//                    ct++;
//                }
//
//            }
//            return true;
//        }
//    }
//    if (firstCharI == -1 || firstCharI == -1) {
//        return false;
//    }
//
//    return true;
//}



@end
