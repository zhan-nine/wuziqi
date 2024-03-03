//用来存放全局变量，宏定义，函数声明等
#ifndef _MY_HEAD_H_
#define _MY_HEAD_H_
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <ctype.h>
    #include <time.h>//用来刷新随机数种子

    #define ROW 15    //行数
    #define COL 15    //列数
    #define PLAYER1 1 //用来标记棋盘上的棋子
    #define PLAYER2 2
    #define PLAYER1_new 3//用来标记新棋盘上的棋子
    #define PLAYER2_new 4
    #define INFTY 0x3f3f3f3f//无穷大
    //下面定义了各种棋型的值，记得多次测试后修改
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
    #define val_fakehuosan 1700//假活三是不造成禁手的活三
    //下面是一些系数
    const double COEFF=0.3;//第n+1步数值对第n步的贡献，用来防守优先，不建议很大
    const double SCALE=0.995;//松弛化系数。在不同走法中若相差不大，则在其中随机选择一个
    const int MAX_STEP=2;//搜索的最大步数。现在如果写到3就会很慢。
    
    //struct
    struct node//FOR p2c_chimp
    {
        int x,y;
        int value;
    };



    //check.c
    int max(const int a,const int b){return a>b?a:b;}
    int min(const int a,const int b){return a<b?a:b;}
    int check(int board[][COL],const int row,const int col);//关于检查棋盘中的子是否胜负的函数
    int check_diagonal_left(int board[][COL],const int row,const int col);
    int check_diagonal_right(int board[][COL],const int row,const int col);
    int check_vertical(int board[][COL],const int row,const int col);
    int check_horizontal(int board[][COL],const int row,const int col);

    //gameboard.c
    const char playername[2][8]={{"Player1"},{"Player2"}};
    const char putchess[5][4]={{"."},{"●"},{"○"},{"▲"},{"△"}};//棋子样式
    void scanf_position(char *ch, int *position);
    void Game();//游戏主函数
    void Game_clear();//游戏初始化
    void ShowBoard(int board[][COL], const int row, const int col);//打印棋盘
    void Invalid_input();//非法输入时弹出的一行字
    void Game_p2p();//人人对战主函数
    void Game_p2c();//人机对战主函数


    //assist.c
    char *mygetline();//用来读取一行字符串的函数


    //p2c_chimp.c
    struct node ai_player1(int this_board[][COL],int step,int sum_step);//黑棋ai
    struct node ai_player2(int this_board[][COL],int step,int sum_step);//白棋ai
    void add_domain(bool domain[][COL],int x,int y,int len);//用来添加一个点的影响范围
    int round_score(int this_board[][COL],int x,int y,int color);//用来检测一个棋子一周的棋的贡献值



    bool useful_domain[ROW][COL];//存放棋盘上棋子的有效影响范围

    //find_2345.c
    void find_2345_clear();//把存放棋型个数的变量归零
    void find_2345(int this_board[][COL],const int row,const int col);//寻找下述棋型
    void find_huosan(int this_board[][COL],const int row,const int col);
    void find_tiaohuosan(int this_board[][COL],const int row,const int col);
    void find_chongsan(int this_board[][COL],const int row,const int col);
    void find_huosi(int this_board[][COL],const int row,const int col);
    void find_chongsi(int this_board[][COL],const int row,const int col);
    void find_tiaosi(int this_board[][COL],const int row,const int col);
    void find_huoer(int this_board[][COL],const int row,const int col);
    void find_tiaohuoer(int this_board[][COL],const int row,const int col);
    void find_fakehuosan(int this_board[][COL],const int row,const int col);
    bool isforbidwin(int this_board[][COL],const int x,const int y);//判断走这一步是否会产生五连或者长连

    //关于数组大小是玄学，理论上还能缩小但没必要
    int huosan[2][105][7][2];//第四第五个点是防守点，第六第七个点是间接防守点
    int tiaohuosan[2][105][6][2];//第四个点是跳的那步,第五第六个点是间接防守点
    int chongsan[2][105][4][2];//第四个点是对面的子
    int huoer[2][105][2][2];
    int tiaohuoer[2][105][2][2];
    int chongsi[2][105][6][2];//第五个点是对面的子,第六个点是防守点
    int tiaosi[2][105][5][2];//第五个点是跳的那步
    int huosi[2][105][6][2];//第五第六个点是防守点
    int fakehuosan[2][105][5][2];//第四第五个点是防守点。这是不计入禁手的活三
    int tiaochongsi[2][105][7][2];//第五个点是跳的那步,第六个点是冲的那步，第七个点可能冲。跳冲四分辨有效防止低效率进攻。
    int num_huosan_1,num_tiaohuosan_1,num_chongsan_1,num_huoer_1,num_tiaohuoer_1,num_chongsi_1,num_tiaosi_1,num_huosi_1;
    int num_huosan_2,num_tiaohuosan_2,num_chongsan_2,num_huoer_2,num_tiaohuoer_2,num_chongsi_2,num_tiaosi_2,num_huosi_2;
    int num_ri_1,num_ri_2;
    int num_fakehuosan_1,num_fakehuosan_2;
    int num_tiaochongsi_1,num_tiaochongsi_2;


    //forbid.c
    bool isforbid34(int this_board[][COL],int player);//判断是否三四禁手

    bool sanflag[ROW+1][COL+1] = { 0 }; //三的禁手标记
    bool siflag[ROW+1][COL+1] = { 0 };  //四的禁手标记
    int iswin[ROW+1][COL+1] = { 0 };    //是否赢棋标记
#endif