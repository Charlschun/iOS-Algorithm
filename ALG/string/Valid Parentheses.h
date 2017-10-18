//
//  Valid Parentheses.h
//  ALG
//
//  Created by junlongj on 2017/10/16.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
@interface Valid_Parentheses : NSObject

/**
 使用压栈的方式解决，
 我们对字符串S中的每一个字符C，如果C不是右括号，就压入栈stack中。
 如果C是右括号，判断stack是不是空的，空则说明没有左括号，直接返回not valid，非空就取出栈顶的字符pre来对比，如果是匹配
 的，就弹出栈顶的字符，继续取S中的下一个字符；如果不匹配，说明不是valid的，直接返回。当我们遍历了一次字符串S后，注意
 这里还有一种情况，就是stack中还有残留的字符没有得到匹配，即此时stack不是空的，这时说明S不是valid的，因为只要valid，一

 @param str <#str description#>
 @return <#return value description#>
 */
+ (BOOL)validParentheses:(NSString *)str;

@end
