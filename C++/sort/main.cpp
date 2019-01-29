//
//  main.cpp
//  LeetCode
//
//  Created by junl on 2019/1/21.
//  Copyright © 2019 junl. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//待排序的数组
vector<int> vi{5,2,4,6,4,2,9,0};
namespace Sort {
    void _print(vector<int> &vi,const string &msg="");
    void quickSort(vector<int> &vi,int start ,int end);
    void separatemergeSort(vector<int> &vi ,int left,int right);
    void heapSort(vector<int> &vi , size_t size , int index);
    /**
     冒泡排序
     */
#pragma mark - 冒泡排序
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
    
#pragma mark - 简单选择排序
    /**
     简单选择排序
     找出最小数的下标然后和i交互,性能比冒泡稍好
     */
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
#pragma mark - 插入排序
    /**
     把当前数a[i]插入到i之前的有序子数组中，依次循环判断，直到找到比a[i]小的.
     http://upload-images.jianshu.io/upload_images/1170656-8f8fe207ea0d0609.gif?imageMogr2/auto-orient/strip
     */
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
#pragma mark - 快速排序
    /**
     快速排序
     分治的思想，通过一趟排序将要排序的数据分隔成独立的两部分，其中的一部分比另外一部分都小.
     然后分别对这两部分数据分别进行快排,整个过程可以用递归来处理
     https://blog.csdn.net/MoreWindows/article/details/6684558
     具体做法：
     1. 选取第一个数作为目标数
     2. 先从后往前找到第一个比目标数小的,然后放入a[i]这个坑里  a[i] = a[j];这样a[j]就是一个新坑了
     3. 从前往后查找大的，然后放入a[j]这个坑里 ,a[j] = a[i] 这样a[i]又是一个新坑
     4. 循环，知道i,j相遇
     5. 把目标数赋值给a[i].这样目标数左边的s都比它小，后边的都比它大
     6. 分治处理目标数左右两边的子数组
     */
    void quickSort(vector<int> vi){
        quickSort(vi,0,(int)vi.size()-1);
        _print(vi,"快速排序o(nlogn)");
    }
    
    void quickSort(vector<int> &vi,int start ,int end){
        int temp = vi[start];//留下一个坑，可以放入后续的元素
        //找出两部分数据，一部分比temp大，一部分比temp小
        if (start >= end) {
            return;
        }
        int i = start,j = end;
        while (i < j) {
            while (i < j && vi[j] >= temp) {
                j--;
            }
            //从后往前找到了一个比temp小的数，放到坑里面
            if (i < j) {
                vi[i] = vi[j];//留下新的一个坑vi[j]
            }
            while (i < j && vi[i] <= temp)  {
                i++;
            }
            if (i < j) {
                vi[j] = vi[i];
            }
        }
        //相遇了
        vi[i] = temp;
        quickSort(vi, start, i-1);
        quickSort(vi, i+1,end);
    }
#pragma mark - 二分插入排序
    /**
     二分插入排序
     */
    void binaryInsertSort(vector<int> vi){
        for (int i = 1; i < vi.size(); i++) {
            int j = i;
            int temp = vi[i];
            if (vi[j] < vi[j-1]) {
                //需要插入到之间
                int left = 0;
                int right = j-1;
                int mid = left + (right-left)/2;
                while (left <= right) {
                    if (vi[mid] >= temp) {
                        right = mid - 1;
                    }else{
                        left = mid + 1;
                    }
                    mid = left + (right-left)/2;
                }
                //先将vi[i]移除
                vi.erase(vi.begin() + i);
                //然后在left位置处插入vi[i]
                vi.insert(vi.begin() + left, temp);
//                int k = i;
//                while (k > left) {
//                    vi[k] = vi[k-1];
//                    k--;
//                }
//                vi[left] = temp;

                
            }
        }
        _print(vi, "二分插入排序o(n*log2n)");
    }
    
#pragma mark - 归并排序
    
    /**
     归并排序
     1. 分解: 将当期区间一分为2
     2. 求解: 递归的对两个子区间做归并排序.递归的终止条件是子区间长度为1
     3. 合并: 将两个已排序的子区间合并
     */
    void mergeSort(vector<int> vi){
        /*
         [1,4,6]
         [2,5,8]
         */
        separatemergeSort(vi, 0, static_cast<int>(vi.size()) - 1);
        _print(vi, "归并排序o(n*logn)");
    }
    void mergeSort(vector<int> &vi,int left,int mid,int right){
        //创建temp数组，里面保存的是两个有序数组的合并结果.
        vector<int> vi_temp;
        int i = left,j = mid+1;
        while (i <= mid && j <= right) {
            if (vi[i] < vi[j]) {
                vi_temp.push_back(vi[i++]);
            }else{
                vi_temp.push_back(vi[j++]);
            }
        }
        while (i <= mid) {
            vi_temp.push_back(vi[i++]);
        }
        while (j <= right) {
            vi_temp.push_back(vi[j++]);
        }
        //然后对源数组left-right部分重新赋值
        int k = 0;
        while (left <= right) {
            vi[left++] = vi_temp[k++];
        }
    }
    void separatemergeSort(vector<int> &vi ,int left,int right){
        if (left < right) {
            int mid = left + (right-left)/2;
            separatemergeSort(vi, left, mid);
            separatemergeSort(vi, mid+1,right);
            //合并
            mergeSort(vi, left, mid, right);
        }
    }
#pragma mark - 堆排序
    
    /**
     1.初始化构建一个大顶堆,此时最大的元素在跟节点
     2.将跟节点和末尾元素交换。
     3.将剩余n-1个元素构建出大顶堆。
     4.交换...
     */
    void heapSort(vector<int> &vi){
        for (int i = static_cast<int>(vi.size())/2 - 1; i >=0; i--) {
            heapSort(vi, vi.size(), i);
        }
        int j = static_cast<int>(vi.size()) - 1;
        for (; j>0; j--) {
            swap(vi[j], vi[0]);
            heapSort(vi, j, 0);
        }
        _print(vi, "堆排序");
    }
    void heapSort(vector<int> &vi , size_t size , int index){
        //调整堆的结构
        int lc = 2 * index + 1;
        int target = vi[index];
        int ct = lc;
        for (; ct+1 <= size; ct = ct * 2 + 1) {
            //找到左右节点最大的值
            if (ct + 1 < size && vi[ct] < vi[ct + 1]) {
                ct++;
            }
            if (vi[ct] > target) {
                vi[index] = vi[ct];
                index = ct;
            }else{
                break;
            }
        }
        vi[index] = target;
    }
    void _print(vector<int> &vi,const string &msg){
        cout << msg << "  ";
        for_each(vi.begin(), vi.end(), [](int no){cout << no << ", ";});
        cout << endl;
    }
};

int main(int argc, const char * argv[]) {
    Sort::bubbleSort(vi);
    Sort::sampleSelectSort(vi);
    Sort::insertSort(vi);
    Sort::quickSort(vi);
    Sort::binaryInsertSort(vi);
    Sort::mergeSort(vi);
    Sort::heapSort(vi);
    return 0;
}
