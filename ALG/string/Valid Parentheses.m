//
//  Valid Parentheses.m
//  ALG
//
//  Created by junlongj on 2017/10/16.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Valid Parentheses.h"


@implementation Valid_Parentheses

+(BOOL)validParentheses:(NSString *)str{
    // '(', ')', '{', '}', '[' and ']'
    NSMutableArray *stack = @[].mutableCopy;
    NSInteger i = 0;
    while (i<str.length) {
        NSString* c = [str substringWithRange:NSMakeRange(i, 1)];
        //如果是做括号就压入栈
        if ([c isEqualToString:@"("]||[c isEqualToString:@"{"] || [c  isEqualToString:@"["]) {
            [stack addObject:c];
        }else{
            //说明当前是右括号
            //判断之前的元素与当前对不对应.
            if (stack.count == 0) {
                return false;
            }
                NSString *pre = stack.lastObject;
                if ([c isEqualToString:@")"]) {
                    if (![pre isEqualToString:@"("]) {
                        return false;
                    }else{
                        [stack removeLastObject];
                    }
                }else  if ([c isEqualToString:@"}"]) {
                    if (![pre isEqualToString:@"{"]) {
                        return false;
                    }else{
                        [stack removeLastObject];
                    }
                }else if ([c isEqualToString:@"]"]) {
                    if (![pre isEqualToString:@"["]) {
             
                        return false;
                    }else{
                        [stack removeLastObject];
                    }
                }
            
        }
        i++;
    }
    if (stack.count != 0) {
        return false;
    }
    return true;
}

@end
