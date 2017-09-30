//
//  MergeSort.m
//  ALG
//
//  Created by junlongj on 2017/9/21.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "MergeSort.h"

@implementation MergeSort

+ (void)sort{
    NSMutableArray * a = @[@1,@3,@4,@5,@7,@8,@11,@33].mutableCopy;
    NSMutableArray * b = @[@2,@3,@4,@5,@11,@22,@43,@55].mutableCopy;
    NSMutableArray * c = @[].mutableCopy;
    int i,j,k;
    i = j  = k = 0;
    while (i < a.count && j < b.count) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        }else{
            c[k++] = b[j++];
        }
    }
    while (j < b.count) {
        c[k++] = b[j++];
    }
    while (i < a.count) {
        c[k++] = a[i++];
    }
    NSLog(@"---%@",c.description);
}

@end
