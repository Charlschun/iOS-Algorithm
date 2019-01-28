//
//  Palindrome Partitioning.m
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Palindrome Partitioning.h"

@implementation Palindrome_Partitioning

+ (NSArray *)partition:(NSString *)str{
    NSMutableArray *save = @[].mutableCopy;
    [self partition:str ctStr:@"" startLocation:0 save:save];
    return save.copy;
}
+ (void)partition:(NSString *)str ctStr:(NSString *)ctStr startLocation:(NSInteger)startLocation save:(NSMutableArray *)save{
    NSLog(@"____%@",ctStr);
    if (ctStr.length!= 0 && [self isPalidromic:ctStr] ) {
        [save addObject:ctStr];
    }else{
        for (NSInteger i = startLocation; i < str.length; i ++) {
            ctStr = [ctStr stringByAppendingString:[str substringWithRange:NSMakeRange(i, 1)]];
            [self partition:str ctStr:ctStr startLocation:startLocation+1 save:save];
//            ctStr = [ctStr substringToIndex:ctStr.length-1];
            ctStr = @"";
        }
    }
}
+ (BOOL)isPalidromic:(NSString *)str{
    NSInteger mid = str.length / 2;
    NSString *str1 = [str substringToIndex:mid];
    NSString *str2 = [str substringFromIndex:mid];
    //说明str的length为单数，中间一位我们可以忽略
    if (str2.length != str1.length) {
        str2 = [str2 substringFromIndex:1];
    }
    NSInteger i ,j ;
    i = 0;
    j = str2.length-1;
    while (i < str1.length) {
        if (![[str1 substringWithRange:NSMakeRange(i, 1)] isEqualToString:[str2 substringWithRange:NSMakeRange(j , 1)]]) {
            return false;
        }
        i++;
        j--;
    }
    
    return  true;
}
@end
