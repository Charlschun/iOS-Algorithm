//
//  Decode Ways.m
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Decode Ways.h"

@implementation Decode_Ways

+ (NSInteger)numDecodings:(NSString *)str{
    NSInteger count = [self _numDecodeings:str startLocation:1];
    return count;
}

+ (NSInteger)_numDecodeings:(NSString *)str startLocation:(NSInteger)startLocation {
    if (startLocation >=str.length) {
        return 1;
    }
   unichar ct = [str characterAtIndex:startLocation];
   unichar pre = [str characterAtIndex:startLocation-1];
  
    if ((pre - '0') * 10 + (ct - '0') > 26) {
       return  [self _numDecodeings:str startLocation:startLocation+1 ];
    }else{
       return  [self _numDecodeings:str startLocation:startLocation+1 ] + 1;
    }
}

@end
