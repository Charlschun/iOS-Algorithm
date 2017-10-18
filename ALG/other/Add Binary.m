//
//  Add Binary.m
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Add Binary.h"

@implementation Add_Binary

+ (NSString *)addBinary:(NSString *)b1 b2:(NSString *)b2;{
    //11
    //1
    NSString *result = [NSString string];
    NSString *minLengthStr = b1.length < b2.length ? b1 : b2;
    NSInteger i = 0;
    while (i < abs(b1.length - b2.length)) {
        minLengthStr =  [@"0" stringByAppendingString:minLengthStr];
        i++;
    }
    if (b1.length < b2.length) {
       b1 = minLengthStr ;
    }else{
        b2 = minLengthStr;
    }
    //现在两个字符串长度一样了
    i = b1.length;
    NSInteger moveup = 0;
    while (--i >=0) {
        NSInteger n1,n2;
         n1 = [b1 characterAtIndex:i] - '0';
         n2 = [b2 characterAtIndex:i] - '0';
        result = [[NSString stringWithFormat:@"%zd",(n1+n2+moveup)%2] stringByAppendingString:result];
        moveup = (moveup + n1 + n2 )/2;
    }
    if (moveup == 1) {
        result = [@"1" stringByAppendingString:result];
    }
    return result;
}

@end
