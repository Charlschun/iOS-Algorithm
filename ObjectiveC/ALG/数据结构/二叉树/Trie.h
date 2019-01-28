//
//  Trie.h
//  ALG
//
//  Created by junlongj on 2017/9/27.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 字典树
 
 （1）根节点不包含字符，除根节点意外每个节点只包含一个字符。
 （2）从根节点到某一个节点，路径上经过的字符连接起来，为该节点对应的字符串。
 （3）每个节点的所有子节点包含的字符串不相同。
 
 Trie的核心思想是空间换时间。利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。
 
 比如下面这个英文二叉树
 */

@interface TrieNode:NSObject
{
    @public
    TrieNode * nexts[26];
}
@property (nonatomic, assign)int count;

@property (nonatomic ,assign)BOOL exist;// 标记该结点处是否构成单词

+ (instancetype)creat;
@end

@interface Trie : NSObject


@property (nonatomic ,strong)TrieNode *root;

+(instancetype)creat;

/**
 对于一个单词，从根开始，沿着单词的各个字母所对应的树中的节点分支向下走，直到单词遍历完，将最后的节点标记为红色，表示该单词已插入Trie树。

 @param str <#str description#>
 */
- (NSInteger)insert:(NSString *)str;

/**
 同样的，从根开始按照单词的字母顺序向下遍历trie树，一旦发现某个节点标记不存在或者单词遍历完成而最后的节点未标记为红色，则表示该单词不存在，若最后的节点标记为红色，表示该单词存在。

 @param str <#str description#>
 @return <#return value description#>
 */
- (int)search:(NSString *)str;
@end
