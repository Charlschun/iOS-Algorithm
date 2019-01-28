//
//  ShellSort.h
//  ALG
//
//  Created by junlongj on 2017/9/21.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ShellSort : NSObject
/*
 http://www.cnblogs.com/chengxiao/p/6104371.html
 数组按照gap分为N组，然后别别对每个小组进行排序,直至gap/2 = 1循环退出
 
 */
+ (void)shellSort:(NSMutableArray *)array;
@end
