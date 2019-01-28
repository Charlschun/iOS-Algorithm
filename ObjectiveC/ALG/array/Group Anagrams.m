//
//  Group Anagrams.m
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Group Anagrams.h"

@implementation Group_Anagrams

+(NSArray *)groupAnagrames:(NSArray *)groups{
    NSMutableDictionary *map = @{}.mutableCopy;
    for (int i = 0; i < groups.count; i ++) {
        NSString *str = groups[i];
        NSString * sortstr = [[[str pathComponents]sortedArrayUsingComparator:^NSComparisonResult(id  _Nonnull obj1, id  _Nonnull obj2) {
            return  obj1 >= obj2;
        }]componentsJoinedByString:@""];
        
        if ([map objectForKey:sortstr]) {
            [[map objectForKey:sortstr]addObject:str];
        }else{
            NSMutableArray * array = @[].mutableCopy;
            [array addObject:str];
            [map setObject:array forKey:sortstr];
        }
    }
    return map.allValues;
    
    
}

@end
