//�������ȫ�ֱ������궨�壬����������
#ifndef _MY_HEAD_H_
#define _MY_HEAD_H_
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <ctype.h>
    #include <time.h>//����ˢ�����������

    #define ROW 15    //����
    #define COL 15    //����
    #define PLAYER1 1 //������������ϵ�����
    #define PLAYER2 2
    #define PLAYER1_new 3//��������������ϵ�����
    #define PLAYER2_new 4
    #define INFTY 0x3f3f3f3f//�����
    //���涨���˸������͵�ֵ���ǵö�β��Ժ��޸�
    #define val_win 50000
    #define val_huosi 20000
    #define val_tiaosi 3000
    #define val_chongsi 2400
    #define val_huosan 1800
    #define val_tiaohuosan 1750
    #define val_chongsan 70
    #define val_huoer 80
    #define val_tiaohuoer 80
    #define val_ri 50
    #define val_round 20
    #define val_tiaochongsi 1700
    #define val_fakehuosan 1700//�ٻ����ǲ���ɽ��ֵĻ���
    //������һЩϵ��
    const double COEFF=0.3;//��n+1����ֵ�Ե�n���Ĺ��ף������������ȣ�������ܴ�
    const double SCALE=0.995;//�ɳڻ�ϵ�����ڲ�ͬ�߷��������������������ѡ��һ��
    const int MAX_STEP=2;//��������������������д��3�ͻ������
    
    //struct
    struct node//FOR p2c_chimp
    {
        int x,y;
        int value;
    };



    //check.c
    int max(const int a,const int b){return a>b?a:b;}
    int min(const int a,const int b){return a<b?a:b;}
    int check(int board[][COL],const int row,const int col);//���ڼ�������е����Ƿ�ʤ���ĺ���
    int check_diagonal_left(int board[][COL],const int row,const int col);
    int check_diagonal_right(int board[][COL],const int row,const int col);
    int check_vertical(int board[][COL],const int row,const int col);
    int check_horizontal(int board[][COL],const int row,const int col);

    //gameboard.c
    const char playername[2][8]={{"Player1"},{"Player2"}};
    const char putchess[5][4]={{"."},{"��"},{"��"},{"��"},{"��"}};//������ʽ
    void scanf_position(char *ch, int *position);
    void Game();//��Ϸ������
    void Game_clear();//��Ϸ��ʼ��
    void ShowBoard(int board[][COL], const int row, const int col);//��ӡ����
    void Invalid_input();//�Ƿ�����ʱ������һ����
    void Game_p2p();//���˶�ս������
    void Game_p2c();//�˻���ս������


    //assist.c
    char *mygetline();//������ȡһ���ַ����ĺ���


    //p2c_chimp.c
    struct node ai_player1(int this_board[][COL],int step,int sum_step);//����ai
    struct node ai_player2(int this_board[][COL],int step,int sum_step);//����ai
    void add_domain(bool domain[][COL],int x,int y,int len);//�������һ�����Ӱ�췶Χ
    int round_score(int this_board[][COL],int x,int y,int color);//�������һ������һ�ܵ���Ĺ���ֵ



    bool useful_domain[ROW][COL];//������������ӵ���ЧӰ�췶Χ

    //find_2345.c
    void find_2345_clear();//�Ѵ�����͸����ı�������
    void find_2345(int this_board[][COL],const int row,const int col);//Ѱ����������
    void find_huosan(int this_board[][COL],const int row,const int col);
    void find_tiaohuosan(int this_board[][COL],const int row,const int col);
    void find_chongsan(int this_board[][COL],const int row,const int col);
    void find_huosi(int this_board[][COL],const int row,const int col);
    void find_chongsi(int this_board[][COL],const int row,const int col);
    void find_tiaosi(int this_board[][COL],const int row,const int col);
    void find_huoer(int this_board[][COL],const int row,const int col);
    void find_tiaohuoer(int this_board[][COL],const int row,const int col);
    void find_fakehuosan(int this_board[][COL],const int row,const int col);
    bool isforbidwin(int this_board[][COL],const int x,const int y);//�ж�����һ���Ƿ������������߳���

    //���������С����ѧ�������ϻ�����С��û��Ҫ
    int huosan[2][105][7][2];//���ĵ�������Ƿ��ص㣬�������߸����Ǽ�ӷ��ص�
    int tiaohuosan[2][105][6][2];//���ĸ����������ǲ�,������������Ǽ�ӷ��ص�
    int chongsan[2][105][4][2];//���ĸ����Ƕ������
    int huoer[2][105][2][2];
    int tiaohuoer[2][105][2][2];
    int chongsi[2][105][6][2];//��������Ƕ������,���������Ƿ��ص�
    int tiaosi[2][105][5][2];//��������������ǲ�
    int huosi[2][105][6][2];//������������Ƿ��ص�
    int fakehuosan[2][105][5][2];//���ĵ�������Ƿ��ص㡣���ǲ�������ֵĻ���
    int tiaochongsi[2][105][7][2];//��������������ǲ�,���������ǳ���ǲ������߸�����ܳ塣�����ķֱ���Ч��ֹ��Ч�ʽ�����
    int num_huosan_1,num_tiaohuosan_1,num_chongsan_1,num_huoer_1,num_tiaohuoer_1,num_chongsi_1,num_tiaosi_1,num_huosi_1;
    int num_huosan_2,num_tiaohuosan_2,num_chongsan_2,num_huoer_2,num_tiaohuoer_2,num_chongsi_2,num_tiaosi_2,num_huosi_2;
    int num_ri_1,num_ri_2;
    int num_fakehuosan_1,num_fakehuosan_2;
    int num_tiaochongsi_1,num_tiaochongsi_2;


    //forbid.c
    bool isforbid34(int this_board[][COL],int player);//�ж��Ƿ����Ľ���

    bool sanflag[ROW+1][COL+1] = { 0 }; //���Ľ��ֱ��
    bool siflag[ROW+1][COL+1] = { 0 };  //�ĵĽ��ֱ��
    int iswin[ROW+1][COL+1] = { 0 };    //�Ƿ�Ӯ����
#endif