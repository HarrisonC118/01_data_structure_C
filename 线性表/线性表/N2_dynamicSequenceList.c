/*****************************************************************//**
 * \file   N2_dynamicSequenceList.c
 * \brief  C������ʹ��malloc�������ڴ�ռ䣬ʹ��free���ͷ��ڴ�ռ�
 * malloc������һ���������ڴ棬�����ڴ濪ͷ�ĵ�ַָ�롣
 * 
 * \author hatcherCheung
 * \date   June 2022
 *********************************************************************/
#include "stdio.h"
#include "stdlib.h"
// ��ʼ���̶�
#define InitSize 10
typedef struct SeqList {
    // ��ǰ��ŵ�����-��������ʽ(����Ҫͳһ)
    // ����ָ������̬�����ڴ�
    int *data;
    // �������
    int maxSize;
    // ��ǰ˳��������ݵ�����
    int length;
};
// ��ʼ��˳���
void InitList(struct SeqList *L) {
    // ����Ĭ�ϵ��ڴ�ռ䣬�ռ���׵�ַ����data���ռ�Ĵ�СΪint�Ĵ�С��int������
    L->data = (int *)malloc(sizeof(int) * InitSize);
    L->length = 0;
    L->maxSize = InitSize;
}
/**
 * ����˳�����
 * @param L Ҫ������˳���ָ��
 * @param len Ҫ���Ӷ೤
 */
void IncreaseSize(struct SeqList *L, int len) {
    // �����¿ռ䣬Ȼ�����ǰ�������ƹ�ȥ
    int* newList;
    newList = (int *)malloc(sizeof(int) * (L->maxSize + len));
    for (int i = 0; i < L->length; i++) {
        newList[i] = L->data[i];
    }
    // �����������
    L->maxSize = L->maxSize + len;
    // �ͷž��ڴ棬��������ָ���µ�ַ
    free(L->data);
    L->data = newList;
}
int main() {
    struct SeqList seqList;
    InitList(&seqList);
    IncreaseSize(&seqList,20);
    int* a;
    int b = 10;
    a = &b;
    printf("a��ֵΪ%p\n", a);
    printf("*a��ֵΪ%d\n", *a);
    return 0;
}