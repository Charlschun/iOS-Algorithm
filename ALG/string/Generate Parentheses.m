//
//  Generate Parentheses.m
//  ALG
//
//  Created by junlongj on 2017/10/16.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Generate Parentheses.h"

@implementation Generate_Parentheses

+ (NSArray *)generateParenthses:(NSInteger)count{
    NSMutableArray *result =@[].mutableCopy;
    [self _generateParenthses:count right:count outString:@"" saveArray:result];
    return result.copy;
}

/**
 <#Description#>

 @param leftParenthses 表示剩余左括号数量
 @param rightParenthses 表示剩余右括号数量
 @param outString 输入字符串
 */
+ (void)_generateParenthses:(NSInteger)leftParenthses right:(NSInteger)rightParenthses outString:(NSString *)outString saveArray:(NSMutableArray *)save{
    //如果left>right意思就是右括号比左括号多
    if (leftParenthses < 0 || rightParenthses < 0 || leftParenthses > rightParenthses ){
        return ;
    }
    if (leftParenthses == 0 && rightParenthses == 0) {
        [save addObject:outString];
    }
    [self _generateParenthses:leftParenthses -1 right:rightParenthses outString:[outString  stringByAppendingString:@"("] saveArray:save];
    [self _generateParenthses:leftParenthses  right:rightParenthses-1 outString:[outString  stringByAppendingString:@")"] saveArray:save];
}

@end
