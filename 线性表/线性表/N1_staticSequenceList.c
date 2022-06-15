/*****************************************************************//**
 * \file   N1_staticSequenceList.c
 * \brief  固定长度的顺序表(利用数组实现，数据在内存中连续存放)
 * 
 * \author hatcherCheung
 * \date   June 2022
 *********************************************************************/
#include "stdio.h"
#define MaxSize 10

typedef struct SqList {
	// 当前存放的数据-以数组形式(类型要统一)
	int data[MaxSize];
	// 当前顺序表存放数据的数量
	int length;
};
/**
 * 初始化列表
 *
 * @param L 要初始化的SqList结构体类型的地址
 */
void InitList(struct SqList* L) {
	// 把数组内容设置默认值，防止系统分配给数组的内存在之前有遗留的数据
	for (int i = 0; i < MaxSize; i++) {
		L->data[i] = 0;
	}
	// 默认数量为0
	L->length = 0;
}
int main() {
	struct SqList sqList;
	InitList(&sqList);
	return 0;
}