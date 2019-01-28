//
//  Roman To  Int.m
//  ALG
//
//  Created by junlongj on 2017/10/16.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Roman To  Int.h"

@implementation Roman_To__Int

+(NSInteger)romanToInt:(NSString *)roman {
    NSDictionary *romanMap = @{@"I":@1,@"V":@5,@"X":@10,@"L":@50,@"C":@100,@"D":@500,@"M":@1000};
    NSInteger result = 0;
    NSString *ctKey = [roman substringWithRange:NSMakeRange(0, 1)];
    NSInteger ctV = [romanMap[ctKey] integerValue];
    result = ctV;
    for (int  i = 1; i < roman.length; i ++) {
       NSString *ctKey = [roman substringWithRange:NSMakeRange(i, 1)];
       NSString *preKey= [roman substringWithRange:NSMakeRange(i-1, 1)];
        NSInteger ctV = [romanMap[ctKey] integerValue];
        NSInteger preV = [romanMap[preKey] integerValue];
        if (ctV < preV) {
            result +=ctV;
        }else{
            //因为上一次已经加了prev,所以需要减出去
            result = result - 2 *preV + ctV;
        }
    }
    return result;
}

@end
