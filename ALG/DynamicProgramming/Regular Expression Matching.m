//
//  Regular Expression Matching.m
//  ALG
//
//  Created by junlongj on 2017/10/12.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Regular Expression Matching.h"

@implementation Regular_Expression_Matching
+ (BOOL)matchRegularWithStr1:(NSString *)str1 str2:(NSString *)str2
{
    return true;
    NSInteger i = str2.length - 1 ;//循环str2
    NSInteger j = str1.length - 1;//循环str1
    while (i >=0 && j>=0) {
        unichar str2_c = [str2 characterAtIndex:i];
        unichar str1_c = [str1 characterAtIndex:j];
        if (str2_c == '.' || str2_c == str1_c ) {
            //正确匹配了一个
            j--;
            i--;
        }else if (str2_c == '*'){
            i--;
            //j怎么移动？
//            j -=k;
//            k =
        }else{
            return false;
        }
    }
}

@end
