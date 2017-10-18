//
//  Word Search.m
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Word Search.h"

@implementation Word_Search


+(BOOL)isWordSearch:(NSString *)word {
    char map[3][4]  =
    {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    //首先我们先定位i，j的位置
    unichar fC = [word characterAtIndex:0];
    int firstCharI,firstCharJ;
    firstCharI = firstCharJ = -1;
    for ( int i = 0; i < 3; i ++) {
        for (int j = 0; j < 4; j ++) {
            if (map[i][j] == fC) {
                firstCharJ = j;
                firstCharI = i;
                
                
                int ct = 1;
                while (ct < word.length) {
                    unichar c  = [word characterAtIndex:ct];
                    //判断c是否满足条件
                    BOOL state1 =  map[firstCharI][firstCharJ-1] == c;
                    BOOL state2 = map[firstCharI][firstCharJ+1] == c;
                    bool state3 = map[firstCharI-1][firstCharJ]  == c;
                    bool state4 =  map[firstCharI+1][firstCharJ] == c;
                    if (state1) {
                       firstCharJ = firstCharJ-1;
                    }
                    if (state2) {
                        firstCharJ = firstCharJ+1;
                    }
                    if (state3) {
                        firstCharI = firstCharI-1;
                    }
                    if (state4) {
                        firstCharI = firstCharI+1;
                    }
                    if (state1 || state2 || state3 || state4) {
                    }else{
                        return false;
                    }
                    

                    ct++;
                }
                
            }
            return true;
        }
    }
    if (firstCharI == -1 || firstCharI == -1) {
        return false;
    }
    
    return true;
}



@end
