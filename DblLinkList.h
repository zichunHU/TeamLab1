#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include "DblNode.h"  // ��������

class DoublyLinkedList
{
public:
    DblNode *head;  // �����ͷָ��
    int length;     // ����ĳ���

public:
    // ���캯��
    DoublyLinkedList();  // Ĭ�Ϲ��캯��
    DoublyLinkedList(int arr[], int n);
    ~DoublyLinkedList();  // ��������

    // �ж������Ƿ�Ϊ��
    [[nodiscard]] bool isEmpty() const;

    // ��������ĳ���
    [[nodiscard]] int getLength() const;

    // ɾ������
    void DeleteNode(DblNode *node);

    // ��ĳ���ڵ�ǰ/�����һ���½ڵ�
    void InsertBefore(DblNode *node, int value);
    void InsertAfter(DblNode *node, int value);
};

#endif  // __DOUBLY_LINKED_LIST_H__