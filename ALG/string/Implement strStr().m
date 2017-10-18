//
//  Implement strStr().m
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Implement strStr().h"

@implementation Implement_strStr__
+ (NSInteger)subRangeInString:(NSString *)string subString:(NSString *)subString;{
    NSInteger j = 0;
    //i和j中间为匹配到的长度.
    while (j < string.length) {
        NSInteger k = 0;
        while (k < subString.length) {
            if ([string characterAtIndex:j] != [subString characterAtIndex:k]) {
                //第一个字符都不匹配跳出循环.
                j++;
                break;
            }else{
                if (k == subString.length-1) {
                    //find
                    return j;
                }
                //继续匹配后续的字符
                j++;
                k++;
            }
        }
        
    }
    return -1;
}
@end
