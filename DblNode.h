#ifndef __DBL_NODE_H__
#define __DBL_NODE_H__

// ˫����������
struct DblNode
{
// ���ݳ�Ա:
	int data;				// ������
	DblNode *prior;	// ָ��ǰ������ָ����
	DblNode *next;	// ָ���̽���ָ����

// ���캯��:
	DblNode();						// �����ݵĹ��캯��
	DblNode(int item,DblNode *priorlink = nullptr,DblNode *nextlink = nullptr);// ��֪�������ָ�������ṹ

};

#endif
