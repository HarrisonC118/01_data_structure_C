/*****************************************************************//**
 * \file   N1_staticSequenceList.c
 * \brief  
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
	// 默认默认长度为0
	L->length = 0;
}

int main() {
	struct SqList sqList;
	InitList(&sqList);
	for (int i = 0; i < 10; i++) {
		printf("data[%d]=%d\n", i, sqList.data[i]);
	}
	return 0;
}