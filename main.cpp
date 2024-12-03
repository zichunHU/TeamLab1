#include "DblNode.h"
#include "DblLinkList.h"
#include <iostream>

using namespace std;

void Task1(DoublyLinkedList &resumes, int K, int M) {
    DblNode *X = resumes.head;   // X 的起始位置
    DblNode *Y = resumes.head->prior; // Y 的起始位置

    while (resumes.getLength() > 0) {
        // X 按逆时针方向移动 K 步
        for (int i = 0; i < K - 1; i++) {
            X = X->next;
        }

        // Y 按顺时针方向移动 M 步
        for (int i = 0; i < M - 1; i++) {
            Y = Y->prior;
        }

        DblNode* nextX = X->next;    //保存X下一个节点，防止指针空挂
        DblNode* priorY = Y->prior;  //保存Y上一个节点，防止指针空挂
        if (X == Y)
        {
            cout << X->data; // 输出简历编号
        }
        else
        {
            cout << X->data << ", " << Y->data;
            /*
             * 判断X和Y是否存在相邻情况
             *
             * 为什么不能相邻？
             * 在接下来的操作中，我们要执行的操作是删除X和Y原本的节点，并且向后/前移动。
             * 如果两个节点相邻，那么会造成指针空挂。
             *
             * 怎么解决这个问题？
             * 对nextX和priorY后移/前移，使其脱离相邻节点。
             *
             * 为什么我多往后移动了一个，但是前面的逻辑不用更改？
             * 这是一个很简单的问题，不多做赘述。
             */

            if (nextX == Y){
                nextX = nextX->next;
                priorY = priorY->prior;
            }

            resumes.DeleteNode(Y);
        }
        resumes.DeleteNode(X);

        /*
         * 这里是关键实现逻辑。
         */
        X = nextX;
        Y = priorY;

        if (resumes.getLength() > 0) cout << "; "; // 格式化输出
    }

    cout << endl;
}

void Task2(DoublyLinkedList &resumes, int K, int M, int N) {
    DblNode *X = resumes.head;   // X 的起始位置
    DblNode *Y = resumes.head->prior; // Y 的起始位置

    while (resumes.getLength() > 0) {
        // X 按逆时针方向移动 K 步
        for (int i = 0; i < K - 1; i++) {
            X = X->next;
        }

        // Y 按顺时针方向移动 M 步
        for (int i = 0; i < M - 1; i++) {
            Y = Y->prior;
        }

        DblNode* priorY = Y->prior;  //保存Y上一个节点，防止指针空挂
        if (X == Y)
        {
            cout << X->data; // 输出简历编号
            resumes.DeleteNode(X);
        }
        else
        {
            cout << X->data << ", " << Y->data;

            if(resumes.getLength()>2) resumes.InsertAfter(X,++N);

            DblNode *nextX = X->next; //保存X下一个节点，防止指针空挂

            resumes.DeleteNode(X);
            resumes.DeleteNode(Y);

            X = nextX;
        }

        Y = priorY;

        if (resumes.getLength() > 0) cout << "; "; // 格式化输出
    }

    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "请选择题目[1/2]:";
        cin >> choice;

        if (choice != 1 && choice != 2) {
            cout << "无效的选择，请输入 1 或 2" << endl;
        }
    } while (choice != 1 && choice != 2);

    int N, K, M;
    cout << "请输入简历数N，X的步长K，Y的步长M：" << endl;
    cin >> N >> K >> M;

    // 初始化双向循环链表，填入简历编号
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
            cout << "没有这道题目" ;
    }
    
    system("PAUSE");
    return 0;
}

