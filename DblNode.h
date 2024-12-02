#ifndef __DBL_NODE_H__
#define __DBL_NODE_H__

// 双向链表结点类
struct DblNode
{
// 数据成员:
	int data;				// 数据域
	DblNode *prior;	// 指向前驱结点的指针域
	DblNode *next;	// 指向后继结点的指针域

// 构造函数:
	DblNode();						// 无数据的构造函数
	DblNode(int item,DblNode *priorlink = nullptr,DblNode *nextlink = nullptr);// 已知数据域和指针域建立结构

};

#endif
