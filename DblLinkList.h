#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include "DblNode.h"  // 引入结点类

class DoublyLinkedList
{
public:
    DblNode *head;  // 链表的头指针
    int length;     // 链表的长度

public:
    // 构造函数
    DoublyLinkedList();  // 默认构造函数
    DoublyLinkedList(int arr[], int n);
    ~DoublyLinkedList();  // 析构函数

    // 判断链表是否为空
    [[nodiscard]] bool isEmpty() const;

    // 返回链表的长度
    [[nodiscard]] int getLength() const;

    // 删除链表
    void DeleteNode(DblNode *node);

    // 在某个节点前/后插入一个新节点
    void InsertBefore(DblNode *node, int value);
    void InsertAfter(DblNode *node, int value);
};

#endif  // __DOUBLY_LINKED_LIST_H__