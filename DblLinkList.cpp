#include "DblLinkList.h"

// 双向链表类的实现部分
void DoublyLinkedList::InsertAfter(DblNode *node, int value)
{
    if (node == nullptr) return;  // 如果节点为空，直接返回

    DblNode *newNode = new DblNode(value);  // 创建新节点，并将值赋为传入的参数

    DblNode *nextNode = node->next;  // 获取当前节点的后继节点

    node->next = newNode;  // 当前节点的next指向新节点
    newNode->prior = node; // 新节点的prior指向当前节点

    newNode->next = nextNode;  // 新节点的next指向当前节点的后继
    nextNode->prior = newNode; // 当前节点的后继的prior指向新节点

    length++;  // 插入节点后，链表长度增加1
}

void DoublyLinkedList::InsertBefore(DblNode *node, int value)
{
    if (node == nullptr || isEmpty()) return;  // 如果节点为空或链表为空，直接返回

    // 创建新节点
    DblNode *newNode = new DblNode(value);

    // 获取当前节点的前驱节点
    DblNode *prevNode = node->prior;

    // 将新节点插入到当前节点之前
    prevNode->next = newNode;  // 前驱节点的next指向新节点
    newNode->prior = prevNode; // 新节点的prior指向前驱节点
    newNode->next = node;      // 新节点的next指向当前节点
    node->prior = newNode;     // 当前节点的prior指向新节点

    // 如果插入的节点是头节点之前的节点，更新头节点指针
    if (node == head) {
        head = newNode;  // 更新头节点为新节点
    }

    length++;  // 插入节点后链表长度加一
}

DoublyLinkedList::DoublyLinkedList(int arr[], int n)
{
    if (n <= 0) return;  // 如果数组长度为0，返回空链表

    DblNode *newNode, *lastNode;
    head = new DblNode(arr[0]);  // 创建头节点
    lastNode = head;  // 初始化lastNode为头节点

    for (int i = 1; i < n; ++i)
    {
        newNode = new DblNode(arr[i]);  // 创建新节点
        lastNode->next = newNode;  // 将上一个节点的next指向新节点
        newNode->prior = lastNode; // 将新节点的prior指向上一个节点
        lastNode = newNode;        // 更新lastNode为新节点
    }

    // 完成循环链表的连接
    lastNode->next = head;    // 最后一个节点的next指向头节点
    head->prior = lastNode;   // 头节点的prior指向最后一个节点

    length = n;  // 设置链表长度
}

void DoublyLinkedList::DeleteNode(DblNode *node)
{
    if (node == nullptr || isEmpty()) return;  // 如果节点为空或者链表为空，直接返回

    DblNode *prevNode = node->prior;  // 获取前驱节点
    DblNode *nextNode = node->next;   // 获取后继节点

    prevNode->next = nextNode;  // 前驱节点的后继指向当前节点的后继
    nextNode->prior = prevNode; // 后继节点的前驱指向当前节点的前驱

    delete node;  // 删除当前节点
    length--;  // 删除结点后链表长度减一
}

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;  // 初始化头指针为空
    length = 0;      // 初始化链表长度为0
}

DoublyLinkedList::~DoublyLinkedList()
{
    if (isEmpty()) return;  // 如果链表为空，直接返回

    DblNode* current = head;
    DblNode* nextNode = nullptr;

    // 遍历链表并删除每个节点，直到回到头节点
    do {
        nextNode = current->next;  // 保存下一个节点的指针
        delete current;            // 删除当前节点
        current = nextNode;        // 移动到下一个节点
    } while (current != head);    // 如果回到头节点，则停止

    head = nullptr;  // 销毁链表后，将头指针置为空
    length = 0;      // 重置链表长度
}

bool DoublyLinkedList::isEmpty() const
{
    return length == 0;  // 如果长度为0，说明链表为空
}

int DoublyLinkedList::getLength() const
{
    return length;  // 返回链表长度
}