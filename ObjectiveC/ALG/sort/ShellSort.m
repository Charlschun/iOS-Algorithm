//
//  ShellSort.m
//  ALG
//
//  Created by junlongj on 2017/9/21.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "ShellSort.h"

@implementation ShellSort

+ (void)shellSort:(NSMutableArray *)array{
    /*
     http://www.cnblogs.com/chengxiao/p/6104371.html
     数组按照gap分为N组，然后别别对每个小组进行排序,直至gap/2 = 1循环退出
     
     */
    NSLog(@"shell:%@",array);
    NSInteger gap = array.count / 2;
    while (gap>=1) {
        //每一组的元素之间的增量为gap
        for (NSInteger i = gap ; i<array.count; i++) {
            //找出这个组里面之前的元素
            NSInteger j = i;
            //[....,i-2*gap,i-gap,i]
            while (j - gap >= 0) {
                if ([array[j] integerValue] < [array[j - gap] integerValue]) {
                    //swap
                    [array exchangeObjectAtIndex:j withObjectAtIndex:j-gap];
                }
                j = j - gap;
            }
        }
         NSLog(@"gap=%zd,shell:%@",gap,array);
        //缩小分组间距直至为1
        gap/=2;
    }
    
}

@end
