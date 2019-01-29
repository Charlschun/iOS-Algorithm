###冒泡算法o(n2)
<pre><code>
    void bubbleSort(vector<int> vi){
        for (int i = 0; i < vi.size(); i++) {
            for (int j = i+1; j < vi.size(); j++) {
                if (vi[i] > vi[j]) {
                    //swap
                    swap(vi[i], vi[j]);
                }
            }
        }
        _print(vi,"冒泡排序o(n2)");
    }
</code></pre>

###选择排序o(n2)
找到i后面的最小数，然后和i交互
<pre><code>
    void sampleSelectSort(vector<int> vi){
        for (int i = 0; i < vi.size(); i++) {
            int min_index = i;
            for (int j = i+1; j < vi.size(); j++) {
                if (vi[min_index] > vi[j]) {
                    min_index = j;
                }
            }
            if (vi[i] > vi[min_index]) {
                swap(vi[i], vi[min_index]);
            }
        }
        _print(vi,"简单选择排序o(n2)");
    }
</code></pre>

###插入排序o(n2)

![](https://images2015.cnblogs.com/blog/1024555/201611/1024555-20161126000335346-416319390.png)
将当前数a[i]插入到i之前的有序子数组中,依次循环把a[i]插入合适的位置.
<pre><code>
    void insertSort(vector<int> vi){
        for (int i = 1; i < vi.size(); i++) {
            int j = i;
            //1,5 比如现在4
            while (j > 0 && vi[j] < vi[j-1])  {
                swap(vi[j], vi[j-1]);
                j--;
            }
        }
        _print(vi, "直接插入排序o(n2)");
    }
</code></pre>
