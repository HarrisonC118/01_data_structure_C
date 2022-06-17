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
    if(L->data != NULL) {
        for (int i = 0; i < InitSize; i++) {
            L->data[i] = 0;
        }
        L->length = 0;
        L->maxSize = InitSize;
    }

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
    // �鿴�ڴ�ռ��Ƿ�ɹ�����
    if (newList != NULL && L->data != NULL) {
        // ȷ��ԭ���ĳ��ȱ�����չ�Ŀռ�С
        if (L->length < sizeof(*newList)/sizeof(int)) {
            for (int i = 0; i < L->length; i++) {
                newList[i] = L->data[i];
            }
            // �����������
            L->maxSize = L->maxSize + len;
            // �ͷž��ڴ棬��������ָ���µ�ַ
            free(L->data);
            L->data = newList;
        }
    }
}
/**
 * �ڹ涨��λ�ò���һ��Ԫ��.
 * 
 * \param L �������ı�
 * \param i ���ĸ�λ��(��0��ʼ)
 * \param element Ҫ�����Ԫ��
 */
void ListInsert(struct SeqList* L, int i, int element) {
    // ��Ҫ����λ���Լ������Ԫ����������Ų
    // �жϱ��Ƿ��Ѿ�����
    if (L->length == L->maxSize) {
        printf("����ʧ�ܣ����Ѿ�����");
    }
    // �����λ�ñ����еĿռ��
    if (i >= L->maxSize) {
        printf("λ���������");
    }
    else {
        // �������ڿյ��������0��λ�ò���Ԫ�أ���Ϊû��-1λ�����Իᱨ��
        if (i != 0 || L->length != 0) {
            // �Ȱ����λ���Լ������Ԫ��������һλ
            // i�ӵ�ǰ���λ�õĺ�һ����ʼ
            for (int currentIndex = L->length; currentIndex >= i; currentIndex--)
            {
                // �ѵ�ǰλ��ǰ���Ԫ�طŹ���
                L->data[currentIndex] = L->data[currentIndex - 1];
            }
        }
        // ��Ԫ�طŽ�Ҫ�ŵ�λ��
        L->data[i] = element;
        L->length++;
    }

}
/**
 * ��ӡ���е���������.
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