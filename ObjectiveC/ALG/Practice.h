//
//  Practice.h
//  ALG
//
//  Created by junlongj on 2017/9/22.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Practice : NSObject

/**
 这是一个加密数据，现在需要解密，解密方式:每次从最前面拿到2个数，第一个扔掉 ，第2个放在尾部。所有扔掉的数为最后的qq号.
 */
+ (void)decodeQQ;
@end
