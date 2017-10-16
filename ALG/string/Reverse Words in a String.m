//
//  Reverse Words in a String.m
//  ALG
//
//  Created by junlongj on 2017/10/11.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Reverse Words in a String.h"

@implementation Reverse_Words_in_a_String

+(NSString *)reverse:(NSString *)str{
    return  [[str componentsSeparatedByString:@" "].reverseObjectEnumerator.allObjects componentsJoinedByString:@" "];
}

@end
