//
//  SortHandle.h
//  ALG
//
//  Created by junlongj on 2017/9/19.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>

//希尔排序 > 堆排序,二叉树排序,快速排序 > 插入排序 , 简单选择排序 , 冒泡
@interface SortHandle : NSObject

/**
 o(n2)
 冒泡

 @param array <#array description#>
 */
+ (void)bubbleSortWithArray:(NSMutableArray<NSNumber *> *)array;

/**
 o(n2)
 简单选择排序
 步骤:两层for循环 找出最小数的下标然后和i交换.性能比冒泡好一些

 @param array <#array description#>
 */
+ (void)simpleSelectSortWithArray:(NSMutableArray<NSNumber *> *)array;


/**
  o(n2)
 插入排序
 步骤：
 1.在数组里挑出temp = a[i] ，然后将它与i之前的所有元素(a[i-1,i-2.....])比较，直到找出比他小的位置 j，然后插入到j的位置，其他依次向右移
 
 @param array <#array description#>
 */
+ (void)insertSortWithArray:(NSMutableArray <NSNumber *> *)array;
/**
 快速排序 
 步骤：
 1.先在数列中挑出一个元素，作为标准，
 2.然后从两头开始遍历，右边j--一直找到比target小的，然后放在左边a[i]
 3.然后左边i++一直找到比target大的，然后放在右边a[j]
 4.一直循环遍历完一圈，然后把target放在最中间的位置
 5。这样左右的都是比target小和大的数了，在对两个序列排序

 @param array <#array description#>
 */
+ (void)quickSortWithArray:(NSMutableArray<NSNumber *> *)array;

//http://upload-images.jianshu.io/upload_images/1170656-8f8fe207ea0d0609.gif?imageMogr2/auto-orient/strip



/**
 二分插值
 步骤和上面差不多，区别在于比较temp的时候采用的是二分比较

 @param array <#array description#>
 */
+ (void)binaryinsertSortWithArray:(NSMutableArray <NSNumber *> *)array;



/**
 归并排序
 步骤：
 会把数组砍成很多一小块的数组，然后合并数组到一个大的数组.

 */
+(void)mergeSortWithArray:(NSMutableArray<NSNumber *> *)array;


/**
 堆的定义：具有以下性质的完全二叉树:每个节点的值都大于（小于）或等于左右孩子节点的值
 堆排序
 堆排序的基本思想是：将待排序序列构造成一个大顶堆，此时，整个序列的最大值就是堆顶的根节点。将其与末尾元素进行交换，此时末尾就为最大值。然后将剩余n-1个元素重新构造成一个堆，这样会得到n个元素的次小值。如此反复执行，便能得到一个有序序列了
 步骤:
 1.初始化堆序列，让其满足条件`````父节点始终>(<)左、右子节点.`````
     1.数组逆序从从子树开始整理树，让其满足条件.
 2.依次将跟节点与最后的叶子节点交换，从而达到了排序的结果

 @param array <#array description#>
 */
+ (void)heapSort:(NSMutableArray *)array;


/**
 O(n2)
 http://www.cnblogs.com/chengxiao/p/6104371.html
 数组按照gap分为N组，然后别别对每个小组进行排序,直至gap/2 = 1循环退出

 @param array <#array description#>
 */
+ (void)shellSort:(NSMutableArray *)array;
@end
