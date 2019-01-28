//
//  Pow(x, n).m
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Pow(x, n).h"



@implementation Pow_x__n_


+(void)load{
    NSInteger min = [self minRMBCount:11];
    NSLog(@"min:%zd",min);
}
+ (NSInteger)minRMBCount:(NSInteger)money{
    NSArray *unit = @[@1,@3,@5];
    //min[0] = 0
    //min[1] = 1
    //min[2] = min[2-1] + 1
    //min[3] = min[3-1] + 1 // min[3] = min[3-3] + 1
    NSMutableArray *min = @[].mutableCopy;
    min[0] = @0;
    for (NSInteger j = 1; j <= money; j ++) {
        min[j] = @([min[j-1] integerValue]+1);
        for (NSInteger i = 0; i< unit.count; i ++) {
            NSInteger _u = [unit[i] integerValue];
            if (j >= _u && [min[j-_u] integerValue]+1<[min[j] integerValue]) {
                min[j] = @([min[j-_u] integerValue]+1);
            }
        }
    }
    return [min.lastObject integerValue];
}

@end

double power(double x , int a){
    if (a == 0) {
        return 1;
    }
    double v = power(x, a / 2);
    if (a % 2 == 0) {
        return v * v;
    }else{
        return v * v * x;
    }
}

double myPow(double x , int a){
    if (a < 0) {
        return 1.0 / (power(x, -a));
    }else{
        return power(x , a);
    }
}
