//made by ������
#pragma GCC optimize(2) //O2�Ż�������ʵ��ûɶ��
#include "myhead.h"
//����ǰ������GBK
int board[ROW][COL] = { 0 }; //�������������
int newboard[ROW][COL] = { 0 }; //�����ڷų�ȥ������
//��Ҫ��ֹ�����Ĺ�����֣������޺���
//���ڻ����ڵ�bug��
//1.�������ȶȸ��ڻ���
//2.��ʱ��������������
//�ڴ���2�������bug����£����õ�wcg�����ĳɼ���bug�ȴ���copy�ĺ��˸İɣ��Ҳ����ˡ�
//�ڴ���������������Ч
//�ڸ߷��������У���������������͵ģ�ֻ������
//���ڴ���һ����������㷨���ܹ����㾪ϲ����ʲô��ǿ�ȵ������嶼�л���Ӯһ��
//�����������õ����ļ�
#include "gameboard.c"
#include "check.c"
#include "assist.c"
#include "p2c_chimp.c"
#include "find_2345.c"
#include "forbid.c"

int main() {
    printf("Loading...\n");
    Game();
    return 0;
}
