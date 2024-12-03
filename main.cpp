#include "DblNode.h"
#include "DblLinkList.h"
#include <iostream>

using namespace std;

void Task1(DoublyLinkedList &resumes, int K, int M) {
    DblNode *X = resumes.head;   // X ����ʼλ��
    DblNode *Y = resumes.head->prior; // Y ����ʼλ��

    while (resumes.getLength() > 0) {
        // X ����ʱ�뷽���ƶ� K ��
        for (int i = 0; i < K - 1; i++) {
            X = X->next;
        }

        // Y ��˳ʱ�뷽���ƶ� M ��
        for (int i = 0; i < M - 1; i++) {
            Y = Y->prior;
        }

        DblNode* nextX = X->next;    //����X��һ���ڵ㣬��ָֹ��չ�
        DblNode* priorY = Y->prior;  //����Y��һ���ڵ㣬��ָֹ��չ�
        if (X == Y)
        {
            cout << X->data; // ����������
        }
        else
        {
            cout << X->data << ", " << Y->data;
            /*
             * �ж�X��Y�Ƿ�����������
             *
             * Ϊʲô�������ڣ�
             * �ڽ������Ĳ����У�����Ҫִ�еĲ�����ɾ��X��Yԭ���Ľڵ㣬�������/ǰ�ƶ���
             * ��������ڵ����ڣ���ô�����ָ��չҡ�
             *
             * ��ô���������⣿
             * ��nextX��priorY����/ǰ�ƣ�ʹ���������ڽڵ㡣
             *
             * Ϊʲô�Ҷ������ƶ���һ��������ǰ����߼����ø��ģ�
             * ����һ���ܼ򵥵����⣬������׸����
             */

            if (nextX == Y){
                nextX = nextX->next;
                priorY = priorY->prior;
            }

            resumes.DeleteNode(Y);
        }
        resumes.DeleteNode(X);

        /*
         * �����ǹؼ�ʵ���߼���
         */
        X = nextX;
        Y = priorY;

        if (resumes.getLength() > 0) cout << "; "; // ��ʽ�����
    }

    cout << endl;
}

void Task2(DoublyLinkedList &resumes, int K, int M, int N) {
    DblNode *X = resumes.head;   // X ����ʼλ��
    DblNode *Y = resumes.head->prior; // Y ����ʼλ��

    while (resumes.getLength() > 0) {
        // X ����ʱ�뷽���ƶ� K ��
        for (int i = 0; i < K - 1; i++) {
            X = X->next;
        }

        // Y ��˳ʱ�뷽���ƶ� M ��
        for (int i = 0; i < M - 1; i++) {
            Y = Y->prior;
        }

        DblNode* priorY = Y->prior;  //����Y��һ���ڵ㣬��ָֹ��չ�
        if (X == Y)
        {
            cout << X->data; // ����������
            resumes.DeleteNode(X);
        }
        else
        {
            cout << X->data << ", " << Y->data;

            if(resumes.getLength()>2) resumes.InsertAfter(X,++N);

            DblNode *nextX = X->next; //����X��һ���ڵ㣬��ָֹ��չ�

            resumes.DeleteNode(X);
            resumes.DeleteNode(Y);

            X = nextX;
        }

        Y = priorY;

        if (resumes.getLength() > 0) cout << "; "; // ��ʽ�����
    }

    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "��ѡ����Ŀ[1/2]:";
        cin >> choice;

        if (choice != 1 && choice != 2) {
            cout << "��Ч��ѡ�������� 1 �� 2" << endl;
        }
    } while (choice != 1 && choice != 2);

    int N, K, M;
    cout << "�����������N��X�Ĳ���K��Y�Ĳ���M��" << endl;
    cin >> N >> K >> M;

    // ��ʼ��˫��ѭ����������������
    int *resumeArray = new int[N];
    for (int i = 0; i < N; i++) {
        resumeArray[i] = i + 1;
    }
    DoublyLinkedList resumes(resumeArray, N);
    delete[] resumeArray;

    cout << endl;
    switch (choice) {
        case 1:
            Task1(resumes, K, M);
            break;
        case 2:
            Task2(resumes, K, M, N);
            break;
        default:
            cout << "û�������Ŀ" ;
    }
    
    system("PAUSE");
    return 0;
}

