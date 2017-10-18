//
//  Group Anagrams.h
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
 Given an array of strings, group anagrams together.
 
 For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 Return:
 
 [
 ["ate", "eat","tea"],
 ["nat","tan"],
 ["bat"]
 ]
 */
@interface Group_Anagrams : NSObject

+ (NSArray *)groupAnagrames:(NSArray *)groups;

@end
