#include "myhead.h"

// 三四禁手判断
// 长连禁手判断在check里面
bool isforbid34(int this_board[][COL],int player)
{
    memset(sanflag, 0, sizeof(sanflag));//归零
    memset(siflag,0,sizeof(siflag));
    memset(iswin,0,sizeof(iswin));
    player--;//输入1存0，输入2存1
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            iswin[i][j]=isforbidwin(this_board,i,j);//走这步后是否能赢
        }
    }
    //检查双活三
    for(int i=0;i<num_huosan_1;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(!sanflag[huosan[player][i][j][0]][huosan[player][i][j][1]])
            {
                sanflag[huosan[player][i][j][0]][huosan[player][i][j][1]]=true;
            }
            else if(!iswin[huosan[player][i][j][0]][huosan[player][i][j][1]])
            {
                return true;
            }
        }
    }
    for(int i=0;i<num_tiaohuosan_1;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(!sanflag[tiaohuosan[player][i][j][0]][tiaohuosan[player][i][j][1]])
            {
                sanflag[tiaohuosan[player][i][j][0]][tiaohuosan[player][i][j][1]]=true;
            }
            else if(!iswin[tiaohuosan[player][i][j][0]][tiaohuosan[player][i][j][1]])
            {
                return true;
            }
        }
    }
    //memset(sanflag, 0, sizeof(sanflag));
    //检查双四
    for(int i=0;i<num_huosi_1;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(!siflag[huosi[player][i][j][0]][huosi[player][i][j][1]])
            {
                siflag[huosi[player][i][j][0]][huosi[player][i][j][1]]=true;
            }
            else
            {
                return true;
            }
        }
    }
    
    for(int i=0;i<num_chongsi_1;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(!siflag[chongsi[player][i][j][0]][chongsi[player][i][j][1]])
            {
                siflag[chongsi[player][i][j][0]][chongsi[player][i][j][1]]=1;
            }
            else
            {
                return true;
            }
        }
    }
    for(int i=0;i<num_tiaosi_1;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(!siflag[tiaosi[player][i][j][0]][tiaosi[player][i][j][1]])
            {
                siflag[tiaosi[player][i][j][0]][tiaosi[player][i][j][1]]=1;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

bool isforbidwin(int this_board[][COL],const int x,const int y)
{
    if(this_board[x][y])    return false;
    this_board[x][y]=1;
    if(check(this_board,ROW,COL))
    {
        this_board[x][y]=0;
        return true;
    }
    this_board[x][y]=0;
    return false;

}
