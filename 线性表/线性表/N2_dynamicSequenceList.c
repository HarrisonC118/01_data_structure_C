/*****************************************************************//**
 * \file   N2_dynamicSequenceList.c
 * \brief  C语言中使用malloc来申请内存空间，使用free来释放内存空间
 * malloc：分配一块连续的内存，返回内存开头的地址指针。
 * 
 * \author hatcherCheung
 * \date   June 2022
 *********************************************************************/
#include "stdio.h"
#include "stdlib.h"
// 初始化程度
#define InitSize 10
typedef struct SeqList {
    // 当前存放的数据-以数组形式(类型要统一)
    // 利用指针来动态分配内存
    int *data;
    // 最大容量
    int maxSize;
    // 当前顺序表存放数据的数量
    int length;
};
// 初始化顺序表
void InitList(struct SeqList *L) {
    // 申请默认的内存空间，空间的首地址给了data，空间的大小为int的大小乘int的数量
    L->data = (int *)malloc(sizeof(int) * InitSize);
    if(L->data != NULL) {
        for (int i = 0; i < InitSize; i++) {
            L->data[i] = 0;
        }
        L->length = 0;
        L->maxSize = InitSize;
    }

}
/**
 * 增加顺序表长度
 * @param L 要操作的顺序表指针
 * @param len 要增加多长
 */
void IncreaseSize(struct SeqList *L, int len) {
    // 开辟新空间，然后把以前的数据移过去
    int* newList;
    newList = (int *)malloc(sizeof(int) * (L->maxSize + len));
    // 查看内存空间是否成功分配
    if (newList != NULL && L->data != NULL) {
        // 确保原来的长度比新扩展的空间小
        if (L->length < sizeof(*newList)/sizeof(int)) {
            for (int i = 0; i < L->length; i++) {
                newList[i] = L->data[i];
            }
            // 增加最大容量
            L->maxSize = L->maxSize + len;
            // 释放旧内存，并把数据指向新地址
            free(L->data);
            L->data = newList;
        }
    }
}
/**
 * 在规定的位置插入一个元素.
 * 
 * \param L 被操作的表
 * \param i 在哪个位置(从0开始)
 * \param element 要插入的元素
 */
void ListInsert(struct SeqList* L, int i, int element) {
    // 把要插入位置以及后面的元素依次往后挪
    // 判断表是否已经满了
    if (L->length == L->maxSize) {
        printf("插入失败，表已经满了");
    }
    // 输入的位置比已有的空间大
    if (i >= L->maxSize) {
        printf("位置输入错误");
    }
    else {
        // 解决如果在空的情况下在0的位置插入元素，因为没有-1位置所以会报错
        if (i != 0 || L->length != 0) {
            // 先把这个位置以及后面的元素往后移一位
            // i从当前存放位置的后一个开始
            for (int currentIndex = L->length; currentIndex >= i; currentIndex--)
            {
                // 把当前位置前面的元素放过来
                L->data[currentIndex] = L->data[currentIndex - 1];
            }
        }
        // 把元素放进要放的位置
        L->data[i] = element;
        L->length++;
    }

}
/**
 * 打印表中的所有数据.
 * 
 * \param seqList
 */
void displaySeqList(struct SeqList seqList) {
    for (int i = 0; i < seqList.length ; i++) {
        printf("data[%d]=%d\n", i, seqList.data[i]);
    }
}
int main() {
    struct SeqList seqList;
    InitList(&seqList);
    ListInsert(&seqList, 0, 0);
    ListInsert(&seqList, 1, 1);
    ListInsert(&seqList, 2, 2);
    ListInsert(&seqList, 3, 3);
    ListInsert(&seqList, 4, 4);
    ListInsert(&seqList, 1, 8);
    displaySeqList(seqList);
    return 0;
}