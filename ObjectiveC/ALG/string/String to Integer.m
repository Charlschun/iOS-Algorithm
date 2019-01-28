//
//  String to Integer.m
//  ALG
//
//  Created by junlongj on 2017/10/11.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "String to Integer.h"

@implementation String_to_Integer

+ (NSInteger)tranformToNumberWithStr:(NSString *)str{
    //如果包含除了0,1,2,3,4,5,6,7,8,9之外的数子的话，转换失败
    //然后乘以对应的单位就行了
    if (!str.length) {
        return 0;
    }
    
    bool negative = [str hasPrefix:@"-"];
    if ([str hasPrefix:@"-"]|| [str hasPrefix:@"+"]) {
        str = [str substringFromIndex:1];
    }
    
    //字符有效
    NSInteger result = 0;
    NSInteger i = 0;
    while (i < str.length) {
       unichar c = [str characterAtIndex:i];
        if (!(c >= '0' && c<='9')){
            return 0;
        }
        result += ( c - '0') * pow(10, (str.length - 1 - i));
        i++;
    }
    
    if (negative) {
        result *=-1;
    }
    if (result > NSIntegerMax) {
        result = NSIntegerMax;
    }
    if (result < NSIntegerMin) {
        result = NSIntegerMin;
    }
    return result;
}

@end
