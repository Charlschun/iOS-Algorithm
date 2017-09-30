//
//  main.c
//  StackQueue
//
//  Created by junlongj on 2017/9/22.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#include <stdio.h>


typedef struct BTNode *Position;
typedef Position BTree;
struct BTNode
{
    char data;
    Position lChild, rChild;
};

BTree CreateBTree()
{
    BTree bt = NULL;
    char ch;
    scanf("%c", &ch);
    if (ch != '#')
    {
        bt =  BTNode();
        bt->data = ch;
        bt->lChild = CreateBTree();
        bt->rChild = CreateBTree();
    }
    return bt;
}
int main()
{
    BTree bt;
    bt = CreateBTree();
    
    return 0;
}
//struct queue{
//    int data[1000];
//    int head;//头指针
//    int tail;//尾指针
//};
//struct stack{
//    int data[10];
//    int top;
//};
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//
//    struct queue q1,q2;
//    struct stack s;
//    //初始化q1,q2,
//    q1.head = 1;q1.tail = 1;
//    q2.head = 1;q2.tail = 1;
//    s.top = 0;
//    int q1data[1000] = { 2,4,1,2,5,6 };
//    int q2data[1000] = {3,1,3,5,6,4};
//    for (int i = 0; i<6; i++) {
//        //读入一个数到
//        q1.data[q1.tail++] = q1data[i];
//        q2.data[q2.tail++] = q2data[i];
//    }
//    while (q1.head<q1.tail && q2.head < q2.tail) {
//        //小哼先打出第一张牌
//        int t = q1.data[q1.head];
//        int  flag = 0;
//        for (int i= 0 ; i < s.top; i++) {
//            if (t == s.data[i]) {
//                flag = 1;
//                break;
//            }
//        }
//        if (flag==0) {
//            //没有应到拍
//            //从小哼手里出队列
//            q1.head++;
//            //放进桌面
//            s.top++;
//            s.data[s.top] = t;
//        }else{
//            //出牌了
//            q1.head++;
//            //把出的牌放在末尾
//            q1.data[q1.tail] = t;
//            q1.tail++;
//            //赢得牌
//            while (s.data[s.top] != t) {
//                q1.data[q1.tail] = s.data[s.top];
//                q1.tail ++;
//                s.top -- ;
//            }
//
//        }
//        //小哈开始打牌
//        int t2 = q2.data[q2.head];
//        int  flag2 = 0;
//        for (int i= 0 ; i < s.top; i++) {
//            if (t2 == s.data[i]) {
//                flag2 = 1;
//                break;
//            }
//        }
//        if (flag2==0) {
//            //没有应到拍
//            //从小哼手里出队列
//            q2.head++;
//            //放进桌面
//            s.top++;
//            s.data[s.top] = t2;
//        }else{
//            //出牌了
//            q2.head++;
//            //把出的牌放在末尾
//            q2.data[q2.tail] = t2;
//            q2.tail++;
//            //赢得牌
//            while (s.data[s.top] != t2) {
//                q2.data[q2.tail] = s.data[s.top];
//                q2.tail ++;
//                s.top -- ;
//            }
//
//        }
//    }
//
//    if (q2.head == q2.tail) {
//        printf("小哼win\n");
//        printf("小哼当前的牌是");
//        for (int i = q1.head; i<=q1.tail - 1; i++) {
//            printf("%d  ",q1.data[i]);
//        }
//        if (s.top > 0) {
//            printf("\n左面的牌是:");
//            for (int i= 0 ; i <=s.top; i ++) {
//                printf("%d  ",s.data[i]);
//            }
//        }else{
//            printf("\n左面没有牌");
//
//        }
//    }else{
//        printf("小哈win\n");
//        printf("小哈当前的牌是");
//        for (int i = q2.head; i<=q2.tail - 1; i++) {
//            printf("%d  ",q2.data[i]);
//        }
//        if (s.top > 0) {
//            printf("\n左面的牌是:");
//            for (int i= 0 ; i <=s.top; i ++) {
//                printf("%d  ",s.data[i]);
//            }
//        }else{
//            printf("\n左面没有牌");
//
//        }
//    }
//
//    return 0;
//}

