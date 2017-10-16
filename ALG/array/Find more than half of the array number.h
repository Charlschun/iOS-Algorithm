//
//  Find more than half of the array number.h
//  ALG
//
//  Created by junlongj on 2017/10/13.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 数组中出现次数超过一半的数字
 */
//https://bestswifter.com/arrayoccurmorethanhalf/
@interface Find_more_than_half_of_the_array_number : NSObject

/*
 
 对于任意数组A，去掉A中任意两个相邻但不相等的数，得到数组A',总有H(A) = H(A')
 
 结论很好证明：设H(A) = p,去掉的两个数中最多有一个p，由于p原来出现的次数大于n/2，现在p-1自然一定大于(n-2)/2。所以H（A'）= p。
 
 只要对于数组中的每一个元素，如果栈为空或这个元素与栈顶元素相同，则这个元素入栈，否则栈顶元素出栈即可。这样一来，不相同的数即使不相邻，迟早也会一起出栈（可以把用来和栈顶做比较元素想象为先入栈再出栈）。
 */
+ (NSInteger)findInArray:(NSArray *)array;
@end
