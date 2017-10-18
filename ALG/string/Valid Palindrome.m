//
//  Valid Palindrome.m
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Valid Palindrome.h"

@implementation Valid_Palindrome
+ (BOOL)isValidPalindrome:(NSString *)str{
    if (str.length == 0) {
        return true;
    }
    str = str.uppercaseString;
    NSInteger i = 0;
    NSInteger j = str.length - 1;
    while (i <= j) {
        unichar first = [str characterAtIndex:i];
        unichar last = [str characterAtIndex:j];
        bool isValid1 = (first>='A'&& first<='z' ) || (first>='0'&&first<='9');
        bool isValid2 = (last>='A'&& last<='z' ) || (last>='0'&&last<='9');
        if (!isValid1) {
             i++;
        }
        if (!isValid2) {
            j--;
        }
        if (isValid1 && isValid2) {
            if (last != first) {
                return false;
            }
            i+=1;
            j-=1;
        }
    }
    return true;
}

@end
