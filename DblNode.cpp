#include "DblNode.h"

// 双向链表结点类的实现部分
DblNode::DblNode()
// 操作结果：构造指针域为空的结点
{
    prior = nullptr;
    next = nullptr;
}

DblNode::DblNode(int item,
                 DblNode *priorlink,
                 DblNode *nextlink)
// 操作结果：构造一个数据域为item、prior指针域为priorlink和next指针域为nextlink的结点
{
    data = item;
    prior = priorlink;
    next = nextlink;
}