//
//  BinarySearch.h
//  ALG
//
//  Created by junlongj on 2017/9/22.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
//http://www.cnblogs.com/luoxn28/p/5767571.html
@interface BinarySearch : NSObject

/**
 就是将目标值和数组的中间值作比较，如果小于那么在左子数组中查找
 */
+ (NSInteger)binarySearch:(NSMutableArray*)array target:(NSInteger) target;

+ (NSInteger)binarySearchFindFirstEqual:(NSMutableArray*)array target:(NSInteger)target ;
@end
