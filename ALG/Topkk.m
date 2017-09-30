//
//  Topkk.m
//  ALG
//
//  Created by junlongj on 2017/9/28.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Topkk.h"
#import "Trie.h"

@interface HeapNode : NSObject

@property (nonatomic ,strong) NSString *key;
@property (nonatomic ,assign) int count;
@end

@implementation HeapNode

@end


@implementation Topkk


+(NSMutableArray *)topkUsingHeapWithKeyNumber:(NSInteger)keyNumber
{
    NSDate *before = [NSDate date];
    NSArray *words = [self _getWordArray];
//    words = [words subarrayWithRange:NSMakeRange(0, 24)];
    NSMutableArray<HeapNode*> *targets = [NSMutableArray arrayWithCapacity:keyNumber];
    //创建字典树
    Trie *trie = [Trie creat];
    for (int i = 0 ; i < words.count - 1; i ++ ) {
        NSString *str = [words[i] lowercaseString];
        //求出每个str的次数
        NSInteger count = [trie insert:str];
        HeapNode *heapNode = [HeapNode new];
        heapNode.count = (int)count;
        heapNode.key = str;
        if (i < keyNumber) {
            //加入到小顶堆里面
            //堆的个数++
            [targets addObject:heapNode];
        }else if (i == keyNumber) {
            //创建对结构
            [self _creatHeap:targets];
            for (int i = 0 ; i < targets.count; i ++) {
                NSLog(@"target key :%@ .count:%zd",targets[i].key,targets[i].count);
            }
        }else{
            //跳转位置
            [self _adjustSmallHeap:targets insertNode:heapNode];
        }
        
    }
    //首先trip求出每一个str出现的count
    NSLog(@"topk排序过后");
    for (int i = 0 ; i < targets.count; i ++) {
        NSLog(@"target key :%@ .count:%zd",targets[i].key,targets[i].count);
    }
    NSTimeInterval expenseTime = [[NSDate date] timeIntervalSinceDate:before];
    NSLog(@"字典树+堆排序结果花费时间:%f",expenseTime);
    return targets;
}

#pragma mark - sort

+ (void)_adjustSmallHeap:(NSMutableArray<HeapNode*> *)heap insertNode:(HeapNode *)node{
    
    HeapNode *first = heap.firstObject;
    //当数据大于根结点的时候，替换根节点，并进行更新堆
    if (first.count > node.count) {
        return;
    }
    
    BOOL find = false;
    for (int i = 0 ; i < heap.count; i ++) {
        if (heap[i].key == node.key) {
            heap[i].count = node.count;
            find = true;
            break;
        }
    }
    
    if (find) {
        return;
    }
    heap[0] = node;
    //把a[0]沉下去，保持堆的结构
    [self _adjustSmallHeap:heap index:0 size:heap.count];

}

+ (void)_creatHeap:(NSMutableArray<HeapNode*> *)heap
{
    //创建大顶推，最大的数在最顶端
    for (NSInteger i = heap.count / 2 - 1; i >=0; i -- ) {
        [self _adjustSmallHeap:heap index:i size:heap.count];
    }
//    //然后依次沉到数组底部，再次_adjust第二大的数又在最顶端
}

+ (void)_adjustSmallHeap:(NSMutableArray<HeapNode*> *)heap index:(NSInteger)index size:(NSInteger )size{

    //小顶堆
//    heap[index] > max(left,right)
    NSInteger l  ;
    l = index * 2 + 1;
    
    HeapNode *target = heap[index];
    NSInteger minIndex = 0;
    while (l < size) {
        if (l >= size- 1 ||   heap[l].count < heap[l+1].count) {
            minIndex = l;
        }else{
            minIndex = l + 1;
        }
        HeapNode *minSon = heap[minIndex];
        if (minSon.count >= target.count ) {
            break;
        }
        //子节点比根节点小,
        heap[index] = minSon;
        index = minIndex;
        l = 2 *l + 1;
    }
    heap[index] = target;
    
}


+(NSMutableArray *)topkUsingQuickSortWithKeyNumber:(NSInteger)keyNumber
{
    
    NSDate *before = [NSDate date];

    NSArray *words = [self _getWordArray];
    //    words = [words subarrayWithRange:NSMakeRange(0, 24)];
    NSMutableArray<HeapNode*> *targets = [NSMutableArray arrayWithCapacity:keyNumber];
    //创建字典树
    Trie *trie = [Trie creat];
    for (int i = 0 ; i < words.count - 1; i ++ ) {
        NSString *str = [words[i] lowercaseString];
        //求出每个str的次数
        NSInteger count = [trie insert:str];
        HeapNode *heapNode = [HeapNode new];
        heapNode.count = (int)count;
        heapNode.key = str;
        if (i < keyNumber) {
            //加入到小顶堆里面
            //堆的个数++
            [targets addObject:heapNode];
        }else if (i == keyNumber) {
            [self _quickSort:targets];
            for (int i = 0 ; i < targets.count; i ++) {
                NSLog(@"qick target key :%@ .count:%zd",targets[i].key,targets[i].count);
            }
        }else{
            [self _adjustQuickSort:targets insertNode:heapNode];
        }
        
    }
    //首先trip求出每一个str出现的count
    NSLog(@"qick 排序过后");
    for (int i = 0 ; i < targets.count; i ++) {
        NSLog(@"qick target key :%@ .count:%zd",targets[i].key,targets[i].count);
    }
    NSTimeInterval expenseTime = [[NSDate date] timeIntervalSinceDate:before];
    NSLog(@"字典树+quick排序结果花费时间:%f",expenseTime);
    return targets;
}

+ (void)_adjustQuickSort:(NSMutableArray<HeapNode *> *)heap insertNode:(HeapNode *)node{
    HeapNode *first = heap.firstObject;
    //当数据大于根结点的时候，替换根节点，并进行更新堆
    if (first.count >= node.count) {
        return;
    }
    
    BOOL find = false;
    for (int i = 0 ; i < heap.count; i ++) {
        if (heap[i].key == node.key) {
            heap[i].count = node.count;
            find = true;
            break;
        }
    }
    
    if (find) {
        return;
    }
    //先移除最小的
    [heap removeObjectAtIndex:0];
    
    //二分查找
    
    NSInteger left = 0;
    NSInteger right = heap.count - 1;
    NSInteger mid ;
    while (left<=right) {
        mid = left + (right - left) / 2;
        if (node.count > heap[mid].count) {
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    
    //0---left ----heapcount
//    NSInteger j = heap.count;
//    while (j > left) {
//        heap[j] = heap[j-1];
//        j++;
//    }
//    heap[left] = node;
    [heap insertObject:node atIndex:left];
}

+ (void)_quickSort:(NSMutableArray<HeapNode *> *)arrays
             {
    [self _quickSort:arrays left:0 right:arrays.count - 1];
}
+ (void)_quickSort:(NSMutableArray<HeapNode *> *)arrays
             left:(NSInteger)left
            right:(NSInteger)right{
    
    if (left >= right) {
        return;
    }
    HeapNode *target = arrays[left];
    NSInteger i ,j ;
    i = left;
    j = right;
    
    while (true) {
        //找到了arrays[j]比他小的了.
        while (i< j &&  arrays[j].count >= target.count) {
            j-=1;
        }
        //找到了arrays[i]比他大的了.
        while (i < j && arrays[i].count <= target.count) {
            i+=1;
        }
        if (i < j ) {
            //swap
            [arrays exchangeObjectAtIndex:i  withObjectAtIndex:j];
        }else{
            break;
        }
    }
    
    [arrays exchangeObjectAtIndex:left withObjectAtIndex:i];
    [self _quickSort:arrays left:left right:i - 1];
    [self _quickSort:arrays left:i + 1 right:right];

}


#pragma mark - private method
+ (NSArray *)_getWordArray
{
    NSString *txtStrings = [self _getWordData];
    NSCharacterSet *characterSet = [NSCharacterSet characterSetWithCharactersInString:@", . ; ( ) : — \n-"];
    NSArray *originalWordArray = [txtStrings componentsSeparatedByCharactersInSet:characterSet];
    NSArray *noBlankArray = [originalWordArray filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"self <> ''"]];
    return noBlankArray;
}

+ (NSString *)_getStringFrom:(NSString *)filePath
{
    NSString *txtStrings = nil;
    NSFileHandle *fileHandle = [NSFileHandle fileHandleForReadingAtPath:filePath];
    if (fileHandle != nil) {
        NSData *wordData = fileHandle.availableData;
        txtStrings = [[NSString alloc] initWithData:wordData encoding:NSUTF8StringEncoding];
    }
    [fileHandle closeFile];
    return txtStrings;
}
+ (NSString *)_getWordData
{
    NSFileManager *manager = [NSFileManager defaultManager];
    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"word" ofType:@"txt"];
    
    if ([manager fileExistsAtPath:filePath]) {
        NSString *str = [self _getStringFrom:filePath];
        return str;
    } else {
        [NSException raise:NSGenericException format:@"word.txt did not exist in filePath"];
        return nil;
    }
}

@end
