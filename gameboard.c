#include "myhead.h"


char ch[1005];//用来存储输入的字符串
int whoseturn;//用来标记当前是哪个玩家
bool isforbid;//用来储存是否需要计算禁手
bool p2who;//用来储存玩家选择是人人对战还是人机对战


inline void Invalid_input()//非法输入的时候输出
{
    printf("Invalid input, please input again.\n");
}

void scanf_position(char *ch, int *position)//输入位置
{
    bool flag = false;
    position[0] = 0;
    position[1] = 0;
    int chtemp=0;
    while (isspace(ch[chtemp]) && ch[chtemp] != '\0' && chtemp<=1000)
    {
        chtemp++;
    }
    if(chtemp>1000)
    {
        position[0] = -1;
        position[1] = -1;
        return;
    }
    if (ch[chtemp] >= 'A' && ch[chtemp] <= 'Z')
    {
        position[0] = ch[chtemp] - 'A';
    }
    else if (ch[chtemp] >= 'a' && ch[chtemp] <= 'z')
    {
        position[0] = ch[chtemp] - 'a';
    }
    else 
    {
        flag = true;
    }
    chtemp++;
    while ((ch[chtemp] != '\0') && !flag)
    {
        if(!isdigit(ch[chtemp]))
        {
            flag = true;
            break;
        }
        position[1] *= 10;
        position[1] += ch[chtemp] - '0';
        chtemp++;
    }
    if(position[1] >15 || position[1] < 1)
    {
        flag = true;
    }
    position[1]--;
    if(flag)
    {
        position[0] = -1;
        position[1] = -1;
        return;
    }

}

void Game()
{
    while(1)
    {
        Game_clear();
        if(p2who)
        {
            Game_p2c();
        }
        else
        {
            Game_p2p();
        }
        system("pause");
    }
}
void Game_p2p()//人人对战
{
    static int check_ans=0;
    static int position[2];
    check_ans=0;
    printf("请输入%s的落子位置，如C4\n", playername[whoseturn-1]);
    while(scanf("%s",ch))
    {
        int chtemp=0;
        while(isspace(ch[chtemp]))
        {
            chtemp++;
        }
        if(ch[chtemp]=='q' && ch[chtemp+1]=='u' && ch[chtemp+2]=='i' && ch[chtemp+3]=='t')
        {
            printf("Bye!\n");
            exit(0);
        }
        //printf("%s\n", ch);
        scanf_position(ch, position);
        if(board[position[0]][position[1]] != 0 || position[0] == -1 || position[1] == -1)
        {
            Invalid_input();
            continue;
        }
        if(whoseturn==PLAYER1)
        {
            board[position[0]][position[1]] = PLAYER1;
            newboard[position[0]][position[1]] = PLAYER1_new;
            ShowBoard(newboard, ROW, COL);
            newboard[position[0]][position[1]] = PLAYER1;
            whoseturn = PLAYER2;
        }
        else
        {
            board[position[0]][position[1]] = PLAYER2;
            newboard[position[0]][position[1]] = PLAYER2_new;
            ShowBoard(newboard, ROW, COL);
            newboard[position[0]][position[1]] = PLAYER2;
            whoseturn = PLAYER1;
        }
        
        check_ans=check(board, ROW, COL);
        if(isforbid)
        {
            if(isforbid34(board, PLAYER1))
            {
                printf("禁手！%s win!\n", playername[whoseturn-1]);
                system("pause");
                Game_clear();
            }
        }
        if(check_ans)
        {
            printf("%s win!\n", playername[check_ans-1]);
            system("pause");
            Game_clear();
        }
        printf("请输入%s的落子位置，如C4\n", playername[whoseturn-1]);
    }
}

void Game_clear()//初始化游戏
{
    char c;
    printf("\033c");
    //下面是三个归零
    memset(board, 0, sizeof(board));
    memset(newboard, 0, sizeof(newboard));
    memset(useful_domain, false, sizeof(useful_domain));
    whoseturn=PLAYER1;
    ShowBoard(board, ROW, COL);
    printf("press any key to start\n");
    mygetline();
    printf("人人对战请输入1，人机对战请输入2\n");
    while(scanf("%c", &c))
    {
        if(c=='1')
        {
            p2who=false;
            break;
        }
        else if(c=='2')
        {
            p2who=true;
            break;
        }
        else 
        {
            Invalid_input();
        }
    }
    getchar();//吞掉一个回车，很重要
    printf("是否开启黑方禁手？(y/n)\n");
    while(scanf("%c", &c))
    {
        if(c=='y' || c=='Y')
        {
            isforbid=true;
            return;
        }
        else if(c=='n' || c=='N')
        {
            isforbid=false;
            return;
        }
        else 
        {
            Invalid_input();
        }
    }
}


void ShowBoard(int board[][COL], const int row, const int col)
{
    //printf("\033c");	//清屏命令，使棋盘只有一个，每次下棋自动更新棋盘。如果不想保留之前的棋盘就把注释恢复。
    		//使列号对应 点
    printf("work of 张欣培\n");
    int i, j;
    
    for (i = row-1; i >=0; i--)
    {
        printf("%3d", i+1);//从1开始打印行数
        for (j = 0; j < col; j++)
        {
            putchar(' ');
            printf("%s", putchess[board[j][i]]);//打印棋盘
            putchar(' ');
        }
        printf("\n");
    }
    printf("   ");
    for (i = 0; i < col; i++)
    {
        printf(" %c ", i+'A'); //打印列号
    }
    printf("\n");
}

