//
//  Trie.m
//  ALG
//
//  Created by junlongj on 2017/9/27.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Trie.h"
#import <malloc/malloc.h>
@implementation TrieNode

+(instancetype)creat{
    TrieNode *node = TrieNode.new;
    node.count = 0;
    node.exist = false;
    memset(node->nexts , 0 , sizeof(node->nexts));    // 初始化为空指针

    return node;
}
@end


@implementation Trie

+(instancetype)creat{
    Trie *tree = Trie.new;
    tree.root = [TrieNode creat];
    return tree;
}


-(NSInteger)insert:(NSString *)str{
    TrieNode *node = self.root;
    int j = 0;
    while (j < str.length) {
        unichar p = [str characterAtIndex:j];
        j+=1;
        int location = p - 'a';
        //如果节点不存在
        if (node->nexts[location] == 0) {
            node->nexts[location] = [TrieNode creat];
        }
        node = node->nexts[location];// 每插入一步，相当于有一个新串经过，指针向下移动
        node.count +=1;
    }
    node.exist = true;// 单词结束的地方标记此处可以构成一个单词
    
    return node.count;
}

- (int)search:(NSString *)str{
    TrieNode *node = self.root;
    int j = 0;
    while (j < str.length) {
        unichar p = [str characterAtIndex:j];
        j+=1;
        int location = p - 'a';
        //如果节点不存在
        if (node->nexts[location] == 0) {
            return 0;
        }
        node = node->nexts[location];
    }
    return node.count;
}
@end
