//
//  GreedyALG.m
//  ALG
//
//  Created by junlongj on 2017/10/9.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "GreedyALG.h"

@implementation GreedyALG

+ (void)greedy{
    int s[12] = {0,1,3,0,5,3,5,6,8,8,2,12};  //活动开始时间，为了方便计算加入第0个活动，不影响
    
    int f[12] = {0,4,5,6,7,9,9,10,11,12,14,16}; //活动结束时间
    NSLog(@"贪心算法结果:%@",RAS(s, f, 0, 11));
}
 static NSString* RAS(int* startList,int* finalList,int k,int n)//k为从第k个活动到第n个活动选出最优活动

{
    
    int m = k + 1;
    
    while (m <= n && startList[m] < finalList[k])
    {
        m = m + 1;
    }
    
    if (m <= n)
        
    {
        NSString *string = [NSString stringWithFormat:@"%i,%@",m,RAS(startList, finalList, m, n)];
        return string;
    }
    else
    return @"";
    
    
}

@end
