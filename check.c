#include "myhead.h"



int check(int this_board[][COL],const int row,const int col)
{
    int check_ans=0;//0是没有结束棋局，1是player1胜利，2是player2胜利
    //及时返回，减少计算量
    //注意，长连禁手在这里判断的
    check_ans=check_diagonal_left(this_board,row,col);
    if(check_ans)return check_ans;
    check_ans=check_diagonal_right(this_board,row,col);
    if(check_ans)return check_ans;
    check_ans=check_vertical(this_board,row,col);
    if(check_ans)return check_ans;
    check_ans=check_horizontal(this_board,row,col);
    if(check_ans)return check_ans;
    return 0;
}

int check_diagonal_left(int this_board[][COL],const int row,const int col)
{
    int i,j,num_pl1=0,num_pl2=0,pattern=0,pl1_max=0,pl2_max=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(!(i+j<row))continue;
            if(this_board[i+j][j]==1)
            {
                num_pl2=0;
                if(pattern==PLAYER1 || !num_pl1)
                {
                    num_pl1++;
                    pl1_max=max(pl1_max,num_pl1);
                    
                }
                else
                {
                    num_pl1=0;
                }
                pattern=PLAYER1;
            }
            else if(this_board[i+j][j]==2)
            {
                num_pl1=0;
                if(pattern==PLAYER2 || !num_pl2)
                {
                    num_pl2++;
                    pl2_max=max(pl2_max,num_pl2);
                    
                }
                else
                {
                    num_pl2=0;
                }
                pattern=PLAYER2;
            }
            else
            {
                pattern=0;
                num_pl1=0;
                num_pl2=0;
            }
        }
        num_pl1=0;
        num_pl2=0;
        pattern=0;
    }
    if(pl2_max>=5)return PLAYER2;
    else if((!isforbid && pl1_max>5) || pl1_max==5)return PLAYER1;
    else if(isforbid && pl1_max>5)return PLAYER2; 
    return 0;
}
//下面是考虑四个方向的函数，基本重合，只是方向不同
int check_diagonal_right(int this_board[][COL],const int row,const int col)
{
    int i,j,num_pl1=0,num_pl2=0,pattern=0,pl1_max=0,pl2_max=0;
    for(i=row-1;i>=0;i--)
    {
        for(j=0;j<col;j++)
        {
            if(i-j<0)continue;
            if(this_board[i-j][j]==1)
            {
                num_pl2=0;
                if(pattern==PLAYER1 || !num_pl1)
                {
                    num_pl1++;
                    pl1_max=max(pl1_max,num_pl1);
                    
                }
                else
                {
                    num_pl1=0;
                }
                pattern=PLAYER1;
            }
            else if(this_board[i-j][j]==2)
            {
                num_pl1=0;
                if(pattern==PLAYER2 || !num_pl2)
                {
                    num_pl2++;
                    pl2_max=max(pl2_max,num_pl2);
                    
                }
                else
                {
                    num_pl2=0;
                }
                pattern=PLAYER2;
            }
            else
            {
                pattern=0;
                num_pl1=0;
                num_pl2=0;
            }
        }
        num_pl1=0;
        num_pl2=0;
        pattern=0;
    }

    if(pl2_max>=5)return PLAYER2;
    else if((!isforbid && pl1_max>=5) || pl1_max==5)return PLAYER1;
    else if(isforbid && pl1_max>5)return PLAYER2; 
    return 0;
}

int check_vertical(int this_board[][COL],const int row,const int col)
{
    int i,j,num_pl1=0,num_pl2=0,pattern=0,pl1_max=0,pl2_max=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(this_board[i][j]==1)
            {
                num_pl2=0;
                if(pattern==PLAYER1 || !num_pl1)
                {
                    num_pl1++;
                    pl1_max=max(pl1_max,num_pl1);
                    
                }
                else
                {
                    num_pl1=0;
                }
                pattern=PLAYER1;
            }
            else if(this_board[i][j]==2)
            {
                num_pl1=0;
                if(pattern==PLAYER2 || !num_pl2)
                {
                    num_pl2++;
                    pl2_max=max(pl2_max,num_pl2);
                    
                }
                else
                {
                    num_pl2=0;
                }
                pattern=PLAYER2;
            }
            else
            {
                pattern=0;
                num_pl1=0;
                num_pl2=0;
            }
        }
        num_pl1=0;
        num_pl2=0;
        pattern=0;
    }

    if(pl2_max>=5)return PLAYER2;
    else if((!isforbid && pl1_max>=5) || pl1_max==5)return PLAYER1;
    else if(isforbid && pl1_max>5)return PLAYER2; 
    return 0;
}


int check_horizontal(int this_board[][COL],const int row,const int col)
{
    int i,j,num_pl1=0,num_pl2=0,pattern=0,pl1_max=0,pl2_max=0;
    for(j=0;j<col;j++)
    {
        for(i=0;i<row;i++)
        {
            if(this_board[i][j]==1)
            {
                num_pl2=0;
                if(pattern==PLAYER1 || !num_pl1)
                {
                    num_pl1++;
                    pl1_max=max(pl1_max,num_pl1);
                    
                }
                else
                {
                    num_pl1=0;
                }
                pattern=PLAYER1;
            }
            else if(this_board[i][j]==2)
            {
                num_pl1=0;
                if(pattern==PLAYER2 || !num_pl2)
                {
                    num_pl2++;
                    pl2_max=max(pl2_max,num_pl2);
                    
                }
                else
                {
                    num_pl2=0;
                }
                pattern=PLAYER2;
            }
            else
            {
                pattern=0;
                num_pl1=0;
                num_pl2=0;
            }
        }
        num_pl1=0;
        num_pl2=0;
        pattern=0;
    }

    if(pl2_max>=5)return PLAYER2;
    else if((!isforbid && pl1_max>=5) || pl1_max==5)return PLAYER1;
    else if(isforbid && pl1_max>5)return PLAYER2; 
    return 0;
}