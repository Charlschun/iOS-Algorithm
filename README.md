
## 排序

[排序算法](./C%2B%2B/sort/main.cpp)

## 字符串

[3.longest_substring_without_repeating_characters](./C%2B%2B/string/3.longest_substring_without_repeating_characters.cpp)<br>
[5.Longest Palindromic Substring](./C%2B%2B/string/5.Longest_Palindromic_Substring.cpp)<br>
[8.String to Integer (atoi)](./C%2B%2B/string/8.String_to_Integer.cpp)<br>
[20.Valid Parentheses](./C%2B%2B/string/20.Valid_Parentheses.cpp)<br>
[22.Generate Parentheses](./C%2B%2B/string/22.Generate_parentheses.cpp)<br>
[28.Implement strStr()](./C%2B%2B/string/28.Implement_strStr.cpp)<br>
[91.Decode Ways](./C%2B%2B/string/91.Decode_Ways.cpp)<br>
[125.Valid Palindrome](./C%2B%2B/string/125.Valid_Palindrome.cpp)<br>
[151.Reverse Words in a String](./C%2B%2B/string/151.Reverse_Words_in_a_String.cpp)<br>
[13.Roman to Integer](./C%2B%2B/string/13.Roman_to_Integer.cpp)<br>
[387.first-unique-character-in-a-string](./C%2B%2B/string/387.first-unique-character-in-a-string.cpp)
## 数组

[1.two_sum](./C%2B%2B/array/1.two_sum.cpp)<br>
[4.Median of Two Sorted Arrays](./C%2B%2B/array/4.Median_of_Two_Sorted_Arrays.cpp)<br>
[153.Find Minimum in Rotated Sorted Array](./C%2B%2B/array/153.Find_Minimum_in_Rotated_Sorted_Array.cpp)<br>
[33.Search in Rotated Sorted Array](./C%2B%2B/array/33.Search_in_Rotated_Sorted_Array.cpp)<br>
[find num in yang array](./C%2B%2B/array/find_num_in_yang_array.cpp)<br>
[169.Majority Element](./C%2B%2B/array/169.Majority_Element.cpp)<br>
[215.Kth Largest Element in an Array](./C%2B%2B/array/215.Kth_Largest_Element_in_an_Array.cpp)<br>
[Find specific num count in Orderly array](./C%2B%2B/array/Find_specific_num_count_in_Orderly_array.cpp)<br>
[15.3Sum](./C%2B%2B/array/15.3Sum.cpp)<br>
[49.Group Anagrams](./C%2B%2B/array/49.Group_Anagrams.cpp)<br>
[73.Set Matrix Zeroes](./C%2B%2B/array/73.Set_Matrix_Zeroes.cpp)<br>
[79.Word Search](./C%2B%2B/array/79.Word_Search.cpp)<br>
[724.Find Pivot Index](./C%2B%2B/array/724.Find_Pivot_Index.cpp)<br>
[747.Largest Number At Least Twice of Others](./C%2B%2B/array/747.Largest_Number_At_Least_Twice_of_Others.cpp)<br>
[498.Diagonal Traverse](./C%2B%2B/array/498.Diagonal_Traverse.cpp)<br>
[54. Spiral Matrix](./C%2B%2B/array/54.Spiral_Matrix.cpp)<br>
[136.single-number](./C%2B%2B/array/136.single-number.cpp)<br>
[350.intersection-of-two-arrays-ii](./C%2B%2B/array/350.intersection-of-two-arrays-ii.cpp)<br>
[217.contains-duplicate](./C%2B%2B/array/217.contains-duplicate.cpp)<br>
[66.plus-one](./C%2B%2B/array/66.plus-one.cpp)<br>
[283.move-zeroes](./C%2B%2B/array/283.move-zeroes.cpp)

### 双指针技巧
其基本思想是将第一个元素和末尾进行交换，再向前移动，直到到达中间位置。使用场景比如，翻转字符串等等.<br><br>
[344.Reverse String](./C%2B%2B/array/344.Reverse_String.cpp)<br>
[561.Array Partition I](./C%2B%2B/array/561.Array_Partition_I.cpp)<br><br>
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

[27.Remove Element](./C%2B%2B/array/27.Remove_Element.cpp)<br>
[485.Max Consecutive Ones](./C%2B%2B/array/485.Max_Consecutive_Ones.cpp)<br>
[209. Minimum Size Subarray Sum](./C%2B%2B/array/209.Minimum_Size_Subarray_Sum.cpp)<br>
[189.Rotate Array](./C%2B%2B/array/189.Rotate_Array.cpp)

## 链表
链表相关的问题:

* 双指针技巧
	* 是否存在环
	* 环的长度
	* 是否相交
	* 移除倒数第N个节点

[双指针技巧](./C%2B%2B/list/list_double_pointer.cpp)<br>
[19.Remove Nth Node From End of List](./C%2B%2B/list/19.Remove_Nth_Node_From_End_of_List.cpp)<br>
[21.Merge Two Sorted Lists](./C%2B%2B/list/21.Merge_Two_Sorted_Lists.cpp)<br>
[23.Merge k Sorted Lists](./C%2B%2B/list/23.Merge_k_Sorted_Lists.cpp)<br>
[61.Rotate List](./C%2B%2B/list/61.Rotate_List.cpp)<br>
[82.Remove Duplicates from Sorted List II](./C%2B%2B/list/82.Remove_Duplicates_from_Sorted_List_II.cpp)<br>
[206.Reverse Linked List](./C%2B%2B/list/206.Reverse_Linked_List.cpp)<br>
[234.Palindrome Linked List](./C%2B%2B/list/234.Palindrome_Linked_List.cpp)<br>
## 树
* 前序遍历（首先访问根节点，然后遍历左子树，最后遍历右子树）
* 中序遍历 (先遍历左子树，然后访问根节点，然后遍历右子树。)
* 后序遍历 (先遍历左子树，然后遍历右子树，最后访问树的根节点)


[先序中序后序层级遍历](./C%2B%2B/tree/orderTraversal.cpp)

运用递归来解决树的问题,通常我们可以通过自顶向下或者自底向上的递归来解决树的问题.<br>
对于某个节点来说，如果我们可以通过某节点的答案，知道它子节点的答案的话，那么可以使用自顶向下递归，反之如此.

[递归解决问题](./C%2B%2B/tree/maximum_depth_of_binary_tree.cpp)<br>
[101.symmetric_tree](./C%2B%2B/tree/101.symmetric_tree.cpp)<br>
[112.Path_Sum](./C%2B%2B/tree/112.Path_Sum.cpp)<br>
[106.Construct_Binary_Tree_from_Inorder_and_Postorder Traversal](./C%2B%2B/tree/106.Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp)<br>
[105.construct-binary-tree-from-preorder-and-inorder-traversal](./C%2B%2B/tree/105.construct-binary-tree-from-preorder-and-inorder-traversal.cpp)

## 算法

[算法](./C%2B%2B/algorithm)

### 分治

有点类似“大事化小、小事化了”的思想，经典的归并排序和快速排序都用到这种思想.<br><br>
[4.Median of Two Sorted Arrays](./C%2B%2B/array/4.Median_of_Two_Sorted_Arrays.cpp)<br>
[23.Merge k Sorted Lists](./C%2B%2B/list/23.Merge_k_Sorted_Lists.cpp)<br>
[169.Majority Element](./C%2B%2B/array/169.Majority_Element.cpp)<br>


### 动态规划

[算法-动态规划 Dynamic Programming--从菜鸟到老鸟](https://blog.csdn.net/u013309870/article/details/75193592)<br>

动态规划的核心是记住已经解决过的子问题的解，然后通过子问题推导出问题的解.比如说Fibonacci数列

<pre><code>
int Fibonacci2(int n){
    int s[n+1];
    s[0]=1;
    s[1]=1;
    int i = 2;
    while (i<=n) {
        s[i]=s[i-1]+s[i-2];
        i++;
    }
    return s[n];
};
</code></pre>

有点类似数学中的归纳总结法，找出状态转移方程，然后逐步求解。 

[切割钢筋](./C%2B%2B/dp/cut-Rebar.cpp)<br>
[53.maximum-subarray](./C%2B%2B/dp/53.maximum-subarray.cpp)<br>
[70.climbing-stairs](./C%2B%2B/dp/70.climbing-stairs.cpp)<br>
[121.best-time-to-buy-and-sell-stock](./C%2B%2B/dp/121.best-time-to-buy-and-sell-stock.cpp)<br>
[62.unique-paths](./C%2B%2B/dp/62.unique-paths.cpp)<br>
[78.subsets](./C%2B%2B/dp/78.subsets.cpp)<br>
[198.house-robber](./C%2B%2B/dp/198.house-robber.cpp)<br>
[55.jump-game](./C%2B%2B/dp/55.jump-game.cpp)<br>
[322.coin-change](./C%2B%2B/dp/322.coin-change.cpp)<br>
[300.longest-increasing-subsequence](./C%2B%2B/dp/300.longest-increasing-subsequence.cpp)

上面的题都有一个规律就是:题目中类似都有一个排列组合，然后求出最优解或者共有多少种排列方式。这种题目，如果能求出子问题的解并且能够通过子问题推导出问题的解，那么优先考虑DP.

### 贪心算法

有时候只顾局部利益，最终也会有最好的全局收益。122. Best Time to Buy and Sell Stock II 看看该如何“贪心”。

[122.best-time-to-buy-and-sell-stock-ii](./C%2B%2B/dp/122.best-time-to-buy-and-sell-stock-ii.cpp)<br>

### 搜索算法(深度优先，广度优化,二分查找)

在有限的解空间中找出满足条件的解，深度和广度通常比较费时间，二分搜索每次可以将问题规模缩小一半，所以比较高效。

[33.Search in Rotated Sorted Array](./C%2B%2B/array/33.Search_in_Rotated_Sorted_Array.cpp)<br>
[148.sort-list](./C%2B%2B/search/148.sort-list.cpp)<br>
[215.Kth Largest Element in an Array](./C%2B%2B/array/215.Kth_Largest_Element_in_an_Array.cpp)<br>
[124.binary-tree-maximum-path-sum](./C%2B%2B/search/124.binary-tree-maximum-path-sum.cpp)


### 回溯

不断地去试错，同时要注意回头是岸，走不通就换条路，最终也能找到解决问题方法或者知道问题无解，可以看看 131. Palindrome Partitioning。
