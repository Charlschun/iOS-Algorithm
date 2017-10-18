//
//  Decode Ways.h
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
 A message containing letters from A-Z is being encoded to numbers using the following mapping:
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.
 
 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 
 The number of ways decoding "12" is 2.
 */
@interface Decode_Ways : NSObject

+ (NSInteger)numDecodings:(NSString *)str;
@end
