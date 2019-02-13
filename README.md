
## 排序

[排序算法](./C%2B%2B/sort/main.cpp)

## 字符串

[3.longest_substring_without_repeating_characters](./C%2B%2B/string/3.longest_substring_without_repeating_characters.cpp)<br>
[5.Longest Palindromic Substring](./C%2B%2B/string/5.Longest Palindromic Substring.cpp)<br>
[8.String to Integer (atoi)](./C%2B%2B/string/8.String to Integer (atoi).cpp)<br>
[20.Valid Parentheses](./C%2B%2B/string/20.Valid Parentheses.cpp)<br>
[22.Generate Parentheses](./C%2B%2B/string/22.Generate Parentheses.cpp)<br>
[28.Implement strStr()](./C%2B%2B/string/28.Implement strStr().cpp)<br>
[91.Decode Ways](./C%2B%2B/string/91.Decode Ways.cpp)<br>
[125.Valid Palindrome](./C%2B%2B/string/125.Valid Palindrome.cpp)<br>
[151.Reverse Words in a String](./C%2B%2B/string/151.Reverse Words in a String.cpp)<br>
## 数组

[1.two_sum](./C%2B%2B/array/1.two_sum.cpp)<br>
[4.Median of Two Sorted Arrays](./C%2B%2B/array/4.Median of Two Sorted Arrays.cpp)<br>
[153.Find Minimum in Rotated Sorted Array](./C%2B%2B/array/153.Find Minimum in Rotated Sorted Array.cpp)<br>
[33.Search in Rotated Sorted Array](./C%2B%2B/array/33.Search in Rotated Sorted Array.cpp)<br>
[find num in yang array](./C%2B%2B/array/find num in yang array.cpp)<br>
[169.Majority Element](./C%2B%2B/array/169.Majority Element.cpp)<br>
[215.Kth Largest Element in an Array](./C%2B%2B/array/215.Kth Largest Element in an Array.cpp)<br>
[Find specific num count in Orderly array](./C%2B%2B/array/Find specific num count in Orderly array.cpp)<br>
[15.3Sum](./C%2B%2B/array/15.3Sum.cpp)<br>
[49.Group Anagrams](./C%2B%2B/array/49.Group Anagrams.cpp)<br>
[73.Set Matrix Zeroes](./C%2B%2B/array/73.Set Matrix Zeroes.cpp)<br>
[79.Word Search](./C%2B%2B/array/79.Word Search.cpp)<br>
[724.Find Pivot Index](./C%2B%2B/array/724.Find Pivot Index.cpp)<br>
[747.Largest Number At Least Twice of Others](./C%2B%2B/array/747.Largest Number At Least Twice of Others.cpp)<br>
[498.Diagonal Traverse](./C%2B%2B/array/498.Diagonal Traverse.cpp)<br>
[54. Spiral Matrix](./C%2B%2B/array/54. Spiral Matrix.cpp)<br>

### 双指针技巧
其基本思想是将第一个元素和末尾进行交换，再向前移动，直到到达中间位置。使用场景比如，翻转字符串等等.<br><br>
[344.Reverse String](./C%2B%2B/array/344.Reverse String.cpp)<br>
[561.Array Partition I](./C%2B%2B/array/561.Array Partition I.cpp)<br><br>
双指针技巧二:使用快慢指针,解决给定一个数组和一个值，原地删除该值的所有实例并返回新的长度。
<pre><code>
int removeElement(vector<int>& nums, int val) {
    int k = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            ++k;
        }
    }
    return k;
}
</code></pre>
在上面的例子中，我们使用两个指针，一个快指针 i 和一个慢指针 k 。i 每次移动一步，而 k 只在添加新的被需要的值时才移动一步。

[27.Remove Element](./C%2B%2B/array/27.Remove Element.cpp)<br>
[485.Max Consecutive Ones](./C%2B%2B/array/485.Max Consecutive Ones.cpp)<br>
[209. Minimum Size Subarray Sum](./C%2B%2B/array/209. Minimum Size Subarray Sum.cpp)<br>
[189.Rotate Array](./C%2B%2B/array/189.Rotate Array.cpp)

## 链表
链表相关的问题:

* 双指针技巧
	* 是否存在环
	* 环的长度
	* 是否相交
	* 移除倒数第N个节点

[双指针技巧](./C%2B%2B/list/list_double_pointer.cpp)<br>
[19.Remove Nth Node From End of List](./C%2B%2B/list/19.Remove Nth Node From End of List.cpp)<br>
[21.Merge Two Sorted Lists](./C%2B%2B/list/21.Merge Two Sorted Lists.cpp)<br>
[23.Merge k Sorted Lists](./C%2B%2B/list/23.Merge k Sorted Lists.cpp)<br>
[61.Rotate List](./C%2B%2B/list/61.Rotate List.cpp)<br>
[82.Remove Duplicates from Sorted List II](./C%2B%2B/list/82.Remove Duplicates from Sorted List II.cpp)<br>
[206.Reverse Linked List](./C%2B%2B/list/206.Reverse Linked List.cpp)<br>
[234.Palindrome Linked List](./C%2B%2B/list/234.Palindrome Linked List.cpp)<br>
## 树
* 前序遍历（首先访问根节点，然后遍历左子树，最后遍历右子树）
* 中序遍历 (先遍历左子树，然后访问根节点，然后遍历右子树。)
* 后序遍历 (先遍历左子树，然后遍历右子树，最后访问树的根节点)


[先序中序后序层级遍历](./C%2B%2B/tree/orderTraversal.cpp)

## 算法

[算法](./C%2B%2B/algorithm)

### 分治

有点类似“大事化小、小事化了”的思想，经典的归并排序和快速排序都用到这种思想，可以看看 Search a 2D Matrix II 来理解这种思想。

### 动态规划

有点类似数学中的归纳总结法，找出状态转移方程，然后逐步求解。 309. Best Time to Buy and Sell Stock with Cooldown 是理解动态规划的一个不错的例子

### 贪心算法

有时候只顾局部利益，最终也会有最好的全局收益。122. Best Time to Buy and Sell Stock II 看看该如何“贪心”。

### 搜索算法(深度优先，广度优化,二分查找)

在有限的解空间中找出满足条件的解，深度和广度通常比较费时间，二分搜索每次可以将问题规模缩小一半，所以比较高效。

### 回溯

不断地去试错，同时要注意回头是岸，走不通就换条路，最终也能找到解决问题方法或者知道问题无解，可以看看 131. Palindrome Partitioning。
