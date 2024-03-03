#include "myhead.h"

//下面的234棋型判断基本上按照函数名写的，又臭又长基本全是if，在多次修改后应该没bug，保留了检查区可以测试还有没有bug

void find_2345_clear(){
    num_huosan_1=0;
    num_tiaohuosan_1=0;
    num_chongsan_1=0;
    num_huoer_1=0;
    num_tiaohuoer_1=0;
    num_chongsi_1=0;
    num_tiaosi_1=0;
    num_huosi_1=0;
    num_huosan_2=0;
    num_tiaohuosan_2=0;
    num_chongsan_2=0;
    num_huoer_2=0;
    num_tiaohuoer_2=0;
    num_chongsi_2=0;
    num_tiaosi_2=0;
    num_huosi_2=0;
    num_ri_1=0;
    num_ri_2=0;
    num_fakehuosan_1=0;
    num_fakehuosan_2=0;
    num_tiaochongsi_1=0;
    num_tiaochongsi_2=0;
}

void find_2345(int this_board[][COL],int row,const int col){
    find_2345_clear();
    memset(iswin,0,sizeof(iswin));
    if(isforbid)
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                iswin[i][j]=isforbidwin(this_board,i,j); 
            }
        }
    }
    find_tiaosi(this_board,row,col);
    /*
    //跳四测试区
    printf("PLAYER1跳四\n");
    for(int i=0;i<num_tiaosi_1;i++)
    {
        printf("%d %d,%d %d,%d %d,%d %d,%d %d\n",tiaosi[PLAYER1-1][i][0][0],tiaosi[PLAYER1-1][i][0][1],tiaosi[PLAYER1-1][i][1][0],tiaosi[PLAYER1-1][i][1][1],tiaosi[PLAYER1-1][i][2][0],tiaosi[PLAYER1-1][i][2][1],tiaosi[PLAYER1-1][i][3][0],tiaosi[PLAYER1-1][i][3][1],tiaosi[PLAYER1-1][i][4][0],tiaosi[PLAYER1-1][i][4][1]);
    }
    printf("PLAYER2跳四\n");
    for(int i=0;i<num_tiaosi_2;i++)
    {
        printf("%d %d,%d %d,%d %d,%d %d,%d %d\n",tiaosi[PLAYER2-1][i][0][0],tiaosi[PLAYER2-1][i][0][1],tiaosi[PLAYER2-1][i][1][0],tiaosi[PLAYER2-1][i][1][1],tiaosi[PLAYER2-1][i][2][0],tiaosi[PLAYER2-1][i][2][1],tiaosi[PLAYER2-1][i][3][0],tiaosi[PLAYER2-1][i][3][1],tiaosi[PLAYER2-1][i][4][0],tiaosi[PLAYER2-1][i][4][1]);
    }
    */
    find_huosi(this_board,row,col);
    /*
    //活四测试区
    for(int i=0;i<num_huosi_1;i++)
    {
        printf("%d %d,%d %d,%d %d,%d %d\n",huosi[PLAYER1-1][i][0][0],huosi[PLAYER1-1][i][0][1],huosi[PLAYER1-1][i][1][0],huosi[PLAYER1-1][i][1][1],huosi[PLAYER1-1][i][2][0],huosi[PLAYER1-1][i][2][1],huosi[PLAYER1-1][i][3][0],huosi[PLAYER1-1][i][3][1]);
    }
    for(int i=0;i<num_huosi_2;i++)
    {
        printf("%d %d,%d %d,%d %d,%d %d\n",huosi[PLAYER2-1][i][0][0],huosi[PLAYER2-1][i][0][1],huosi[PLAYER2-1][i][1][0],huosi[PLAYER2-1][i][1][1],huosi[PLAYER2-1][i][2][0],huosi[PLAYER2-1][i][2][1],huosi[PLAYER2-1][i][3][0],huosi[PLAYER2-1][i][3][1]);
    }
    */
    find_chongsi(this_board,row,col);
    /*
    //冲四测试区
    printf("PLAYER1冲四\n");
    for(int i=0;i<num_chongsi_1;i++)
    {
        printf("%d %d,%d %d,%d %d,%d %d,%d %d\n",chongsi[PLAYER1-1][i][0][0],chongsi[PLAYER1-1][i][0][1],chongsi[PLAYER1-1][i][1][0],chongsi[PLAYER1-1][i][1][1],chongsi[PLAYER1-1][i][2][0],chongsi[PLAYER1-1][i][2][1],chongsi[PLAYER1-1][i][3][0],chongsi[PLAYER1-1][i][3][1],chongsi[PLAYER1-1][i][4][0],chongsi[PLAYER1-1][i][4][1]);
    }
    printf("PLAYER2冲四\n");
    for(int i=0;i<num_chongsi_2;i++)
    {
        printf("%d %d,%d %d,%d %d,%d %d,%d %d\n",chongsi[PLAYER2-1][i][0][0],chongsi[PLAYER2-1][i][0][1],chongsi[PLAYER2-1][i][1][0],chongsi[PLAYER2-1][i][1][1],chongsi[PLAYER2-1][i][2][0],chongsi[PLAYER2-1][i][2][1],chongsi[PLAYER2-1][i][3][0],chongsi[PLAYER2-1][i][3][1],chongsi[PLAYER2-1][i][4][0],chongsi[PLAYER2-1][i][4][1]);
    }
    */
    find_huosan(this_board,row,col);
    /*
    //活三测试区
    for(int i=0;i<num_huosan_1;i++)
    {
        printf("%d %d,%d %d,%d %d\n",huosan[PLAYER1-1][i][0][0],huosan[PLAYER1-1][i][0][1],huosan[PLAYER1-1][i][1][0],huosan[PLAYER1-1][i][1][1],huosan[PLAYER1-1][i][2][0],huosan[PLAYER1-1][i][2][1]);
    }
    for(int i=0;i<num_huosan_2;i++)
    {
        printf("%d %d,%d %d,%d %d\n",huosan[PLAYER2-1][i][0][0],huosan[PLAYER2-1][i][0][1],huosan[PLAYER2-1][i][1][0],huosan[PLAYER2-1][i][1][1],huosan[PLAYER2-1][i][2][0],huosan[PLAYER2-1][i][2][1]);
    }
    */
   find_tiaohuosan(this_board,row,col);
    /*
    //跳活三测试区
    printf("PLAYER1跳活三\n");
    for(int i=0;i<num_tiaohuosan_1;i++)
    {
        printf("%d %d,%d %d,%d %d,%d %d\n",tiaohuosan[PLAYER1-1][i][0][0],tiaohuosan[PLAYER1-1][i][0][1],tiaohuosan[PLAYER1-1][i][1][0],tiaohuosan[PLAYER1-1][i][1][1],tiaohuosan[PLAYER1-1][i][2][0],tiaohuosan[PLAYER1-1][i][2][1],tiaohuosan[PLAYER1-1][i][3][0],tiaohuosan[PLAYER1-1][i][3][1]);
    }
    printf("PLAYER2跳活三\n");
    for(int i=0;i<num_tiaohuosan_2;i++)
    {
        printf("%d %d,%d %d,%d %d,%d %d\n",tiaohuosan[PLAYER2-1][i][0][0],tiaohuosan[PLAYER2-1][i][0][1],tiaohuosan[PLAYER2-1][i][1][0],tiaohuosan[PLAYER2-1][i][1][1],tiaohuosan[PLAYER2-1][i][2][0],tiaohuosan[PLAYER2-1][i][2][1],tiaohuosan[PLAYER2-1][i][3][0],tiaohuosan[PLAYER2-1][i][3][1]);
    }
    */
    find_chongsan(this_board,row,col);
    /*
    //冲三测试区
    printf("PLAYER1冲三\n");
    for(int i=0;i<num_chongsan_1;i++)
    {
        printf("%d %d,%d %d,%d %d,%d %d\n",chongsan[PLAYER1-1][i][0][0],chongsan[PLAYER1-1][i][0][1],chongsan[PLAYER1-1][i][1][0],chongsan[PLAYER1-1][i][1][1],chongsan[PLAYER1-1][i][2][0],chongsan[PLAYER1-1][i][2][1],chongsan[PLAYER1-1][i][3][0],chongsan[PLAYER1-1][i][3][1]);
    }
    printf("PLAYER2冲三\n");
    for(int i=0;i<num_chongsan_2;i++)
    {
        printf("%d %d,%d %d,%d %d,%d %d\n",chongsan[PLAYER2-1][i][0][0],chongsan[PLAYER2-1][i][0][1],chongsan[PLAYER2-1][i][1][0],chongsan[PLAYER2-1][i][1][1],chongsan[PLAYER2-1][i][2][0],chongsan[PLAYER2-1][i][2][1],chongsan[PLAYER2-1][i][3][0],chongsan[PLAYER2-1][i][3][1]);
    }
    */
    find_huoer(this_board,row,col);
    /*
    //活二测试区
    printf("PLAYER1活二\n");
    for(int i=0;i<num_huoer_1;i++)
    {
        printf("%d %d,%d %d\n",huoer[PLAYER1-1][i][0][0],huoer[PLAYER1-1][i][0][1],huoer[PLAYER1-1][i][1][0],huoer[PLAYER1-1][i][1][1]);
    }
    printf("PLAYER2活二\n");
    for(int i=0;i<num_huoer_2;i++)
    {
        printf("%d %d,%d %d\n",huoer[PLAYER2-1][i][0][0],huoer[PLAYER2-1][i][0][1],huoer[PLAYER2-1][i][1][0],huoer[PLAYER2-1][i][1][1]);
    }
    */
   find_tiaohuoer(this_board,row,col);
   /*
    //跳活二测试区
    printf("PLAYER1跳活二\n");
    for(int i=0;i<num_tiaohuoer_1;i++)
    {
        printf("%d %d,%d %d\n",tiaohuoer[PLAYER1-1][i][0][0],tiaohuoer[PLAYER1-1][i][0][1],tiaohuoer[PLAYER1-1][i][1][0],tiaohuoer[PLAYER1-1][i][1][1]);
    }
    printf("PLAYER2跳活二\n");
    for(int i=0;i<num_tiaohuoer_2;i++)
    {
        printf("%d %d,%d %d\n",tiaohuoer[PLAYER2-1][i][0][0],tiaohuoer[PLAYER2-1][i][0][1],tiaohuoer[PLAYER2-1][i][1][0],tiaohuoer[PLAYER2-1][i][1][1]);
    }
    */
    find_fakehuosan(this_board,row,col);
}

void find_huosan(int this_board[][COL],const int row,const int col)//已经修正了假活三，还要修正造成长连的活三
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //PLAYER1的活三
            if(j+4<col && this_board[i][j]==0 && this_board [i][j+1]==PLAYER1 && this_board[i][j+2]==PLAYER1 && this_board[i][j+3]==PLAYER1 && this_board[i][j+4]==0 && ((j-1>=0 && this_board[i][j-1]==0)&&( j+5<col && this_board[i][j+5]==0)))
            {   
                if((!iswin[i][j])&&(!iswin[i][j+4]))
                {
                    huosan[PLAYER1-1][num_huosan_1][0][0]=i;
                    huosan[PLAYER1-1][num_huosan_1][1][0]=i;
                    huosan[PLAYER1-1][num_huosan_1][2][0]=i;
                    huosan[PLAYER1-1][num_huosan_1][0][1]=j+1;
                    huosan[PLAYER1-1][num_huosan_1][1][1]=j+2;
                    huosan[PLAYER1-1][num_huosan_1][2][1]=j+3;
                    huosan[PLAYER1-1][num_huosan_1][3][0]=i;
                    huosan[PLAYER1-1][num_huosan_1][3][1]=j;
                    huosan[PLAYER1-1][num_huosan_1][4][0]=i;
                    huosan[PLAYER1-1][num_huosan_1][4][1]=j+4;
                    huosan[PLAYER1-1][num_huosan_1][5][0]=i;
                    huosan[PLAYER1-1][num_huosan_1][5][1]=j-1;
                    huosan[PLAYER1-1][num_huosan_1][6][0]=i;
                    huosan[PLAYER1-1][num_huosan_1][6][1]=j+5;
                    num_huosan_1++;
                }
                else if(!iswin[i][j])
                {
                    chongsan[PLAYER1-1][num_chongsan_1][0][0]=i;
                    chongsan[PLAYER1-1][num_chongsan_1][1][0]=i;
                    chongsan[PLAYER1-1][num_chongsan_1][2][0]=i;
                    chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                    chongsan[PLAYER1-1][num_chongsan_1][0][1]=j+1;
                    chongsan[PLAYER1-1][num_chongsan_1][1][1]=j+2;
                    chongsan[PLAYER1-1][num_chongsan_1][2][1]=j+3;
                    chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                    num_chongsan_1++;
                }
                else if(!iswin[i][j+4])
                {
                    chongsan[PLAYER1-1][num_chongsan_1][0][0]=i;
                    chongsan[PLAYER1-1][num_chongsan_1][1][0]=i;
                    chongsan[PLAYER1-1][num_chongsan_1][2][0]=i;
                    chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                    chongsan[PLAYER1-1][num_chongsan_1][0][1]=j+1;
                    chongsan[PLAYER1-1][num_chongsan_1][1][1]=j+2;
                    chongsan[PLAYER1-1][num_chongsan_1][2][1]=j+3;
                    chongsan[PLAYER1-1][num_chongsan_1][3][1]=j+4;
                    num_chongsan_1++;
                }
            }
            if(i+4<row && this_board[i][j]==0 && this_board[i+1][j]==PLAYER1 && this_board[i+2][j]==PLAYER1 && this_board[i+3][j]==PLAYER1 && this_board[i+4][j]==0 && ((i-1>=0 && this_board[i-1][j]==0)&&( i+5<row && this_board[i+5][j]==0)))
            {
                if(!iswin[i][j] && !iswin[i+4][j])
                {
                    huosan[PLAYER1-1][num_huosan_1][0][0]=i+1;
                    huosan[PLAYER1-1][num_huosan_1][1][0]=i+2;
                    huosan[PLAYER1-1][num_huosan_1][2][0]=i+3;
                    huosan[PLAYER1-1][num_huosan_1][0][1]=j;
                    huosan[PLAYER1-1][num_huosan_1][1][1]=j;
                    huosan[PLAYER1-1][num_huosan_1][2][1]=j;
                    huosan[PLAYER1-1][num_huosan_1][3][0]=i;
                    huosan[PLAYER1-1][num_huosan_1][3][1]=j;
                    huosan[PLAYER1-1][num_huosan_1][4][0]=i+4;
                    huosan[PLAYER1-1][num_huosan_1][4][1]=j;
                    huosan[PLAYER1-1][num_huosan_1][5][0]=i-1;
                    huosan[PLAYER1-1][num_huosan_1][5][1]=j;
                    huosan[PLAYER1-1][num_huosan_1][6][0]=i+5;
                    huosan[PLAYER1-1][num_huosan_1][6][1]=j;
                    num_huosan_1++;
                }
                else if(!iswin[i][j])
                {
                    chongsan[PLAYER1-1][num_chongsan_1][0][0]=i+1;
                    chongsan[PLAYER1-1][num_chongsan_1][1][0]=i+2;
                    chongsan[PLAYER1-1][num_chongsan_1][2][0]=i+3;
                    chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                    chongsan[PLAYER1-1][num_chongsan_1][0][1]=j;
                    chongsan[PLAYER1-1][num_chongsan_1][1][1]=j;
                    chongsan[PLAYER1-1][num_chongsan_1][2][1]=j;
                    chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                    num_chongsan_1++;
                }
                else if(!iswin[i+4][j])
                {
                    chongsan[PLAYER1-1][num_chongsan_1][0][0]=i+1;
                    chongsan[PLAYER1-1][num_chongsan_1][1][0]=i+2;
                    chongsan[PLAYER1-1][num_chongsan_1][2][0]=i+3;
                    chongsan[PLAYER1-1][num_chongsan_1][3][0]=i+4;
                    chongsan[PLAYER1-1][num_chongsan_1][0][1]=j;
                    chongsan[PLAYER1-1][num_chongsan_1][1][1]=j;
                    chongsan[PLAYER1-1][num_chongsan_1][2][1]=j;
                    chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                    num_chongsan_1++;
                }
            }
            if(i+4<row && j+4<col && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER1 && 
            this_board[i+2][j+2]==PLAYER1 && this_board[i+3][j+3]==PLAYER1 && this_board[i+4][j+4]==0 &&((i-1>=0 && j-1>=0 && this_board[i-1][j-1]==0)&&( i+5<row && j+5<row && this_board[i+5][j+5]==0)))
            {
                if(!iswin[i][j] && !iswin[i+4][j+4])
                {
                    huosan[PLAYER1-1][num_huosan_1][0][0]=i+1;
                    huosan[PLAYER1-1][num_huosan_1][1][0]=i+2;
                    huosan[PLAYER1-1][num_huosan_1][2][0]=i+3;
                    huosan[PLAYER1-1][num_huosan_1][0][1]=j+1;
                    huosan[PLAYER1-1][num_huosan_1][1][1]=j+2;
                    huosan[PLAYER1-1][num_huosan_1][2][1]=j+3;
                    huosan[PLAYER1-1][num_huosan_1][3][0]=i;
                    huosan[PLAYER1-1][num_huosan_1][3][1]=j;
                    huosan[PLAYER1-1][num_huosan_1][4][0]=i+4;
                    huosan[PLAYER1-1][num_huosan_1][4][1]=j+4;
                    huosan[PLAYER1-1][num_huosan_1][5][0]=i-1;
                    huosan[PLAYER1-1][num_huosan_1][5][1]=j-1;
                    huosan[PLAYER1-1][num_huosan_1][6][0]=i+5;
                    huosan[PLAYER1-1][num_huosan_1][6][1]=j+5;
                    num_huosan_1++;
                }
                else if(!iswin[i][j])
                {
                    chongsan[PLAYER1-1][num_chongsan_1][0][0]=i+1;
                    chongsan[PLAYER1-1][num_chongsan_1][1][0]=i+2;
                    chongsan[PLAYER1-1][num_chongsan_1][2][0]=i+3;
                    chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                    chongsan[PLAYER1-1][num_chongsan_1][0][1]=j+1;
                    chongsan[PLAYER1-1][num_chongsan_1][1][1]=j+2;
                    chongsan[PLAYER1-1][num_chongsan_1][2][1]=j+3;
                    chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                    num_chongsan_1++;
                }
                else if(!iswin[i+4][j+4])
                {
                    chongsan[PLAYER1-1][num_chongsan_1][0][0]=i+1;
                    chongsan[PLAYER1-1][num_chongsan_1][1][0]=i+2;
                    chongsan[PLAYER1-1][num_chongsan_1][2][0]=i+3;
                    chongsan[PLAYER1-1][num_chongsan_1][3][0]=i+4;
                    chongsan[PLAYER1-1][num_chongsan_1][0][1]=j+1;
                    chongsan[PLAYER1-1][num_chongsan_1][1][1]=j+2;
                    chongsan[PLAYER1-1][num_chongsan_1][2][1]=j+3;
                    chongsan[PLAYER1-1][num_chongsan_1][3][1]=j+4;
                    num_chongsan_1++;
                }
            }
            if(i-4>=0 && j+4<col && this_board[i][j]==0 && this_board[i-1][j+1]==PLAYER1 && 
            this_board[i-2][j+2]==PLAYER1 && this_board[i-3][j+3]==PLAYER1 && this_board[i-4][j+4]==0 && ((j-1>=0 && this_board[i+1][j-1]==0)&&( i-5>=0 && j+5<col && this_board[i-5][j+5]==0)))
            {
                if(!iswin[i][j] && !iswin[i-4][j+4])
                {
                    huosan[PLAYER1-1][num_huosan_1][0][0]=i-1;
                    huosan[PLAYER1-1][num_huosan_1][1][0]=i-2;
                    huosan[PLAYER1-1][num_huosan_1][2][0]=i-3;
                    huosan[PLAYER1-1][num_huosan_1][0][1]=j+1;
                    huosan[PLAYER1-1][num_huosan_1][1][1]=j+2;
                    huosan[PLAYER1-1][num_huosan_1][2][1]=j+3;
                    huosan[PLAYER1-1][num_huosan_1][3][0]=i;
                    huosan[PLAYER1-1][num_huosan_1][3][1]=j;
                    huosan[PLAYER1-1][num_huosan_1][4][0]=i-4;
                    huosan[PLAYER1-1][num_huosan_1][4][1]=j+4;
                    huosan[PLAYER1-1][num_huosan_1][5][0]=i+1;
                    huosan[PLAYER1-1][num_huosan_1][5][1]=j-1;
                    huosan[PLAYER1-1][num_huosan_1][6][0]=i-5;
                    huosan[PLAYER1-1][num_huosan_1][6][1]=j+5;
                    num_huosan_1++;
                }
                else if(!iswin[i][j])
                {
                    chongsan[PLAYER1-1][num_chongsan_1][0][0]=i-1;
                    chongsan[PLAYER1-1][num_chongsan_1][1][0]=i-2;
                    chongsan[PLAYER1-1][num_chongsan_1][2][0]=i-3;
                    chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                    chongsan[PLAYER1-1][num_chongsan_1][0][1]=j+1;
                    chongsan[PLAYER1-1][num_chongsan_1][1][1]=j+2;
                    chongsan[PLAYER1-1][num_chongsan_1][2][1]=j+3;
                    chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                    num_chongsan_1++;
                }
                else if(!iswin[i-4][j+4])
                {
                    chongsan[PLAYER1-1][num_chongsan_1][0][0]=i-1;
                    chongsan[PLAYER1-1][num_chongsan_1][1][0]=i-2;
                    chongsan[PLAYER1-1][num_chongsan_1][2][0]=i-3;
                    chongsan[PLAYER1-1][num_chongsan_1][3][0]=i-4;
                    chongsan[PLAYER1-1][num_chongsan_1][0][1]=j+1;
                    chongsan[PLAYER1-1][num_chongsan_1][1][1]=j+2;
                    chongsan[PLAYER1-1][num_chongsan_1][2][1]=j+3;
                    chongsan[PLAYER1-1][num_chongsan_1][3][1]=j+4;
                    num_chongsan_1++;
                }
            }
            //PLAYER2的活三
            if(j+4<col && this_board[i][j]==0 && this_board [i][j+1]==PLAYER2 && this_board[i][j+2]==PLAYER2 && this_board[i][j+3]==PLAYER2 && this_board[i][j+4]==0 && ((j-1>=0 && this_board[i][j-1]==0)&&( j+5<row && this_board[i][j+5]==0)))
            {
                huosan[PLAYER2-1][num_huosan_2][0][0]=i;
                huosan[PLAYER2-1][num_huosan_2][1][0]=i;
                huosan[PLAYER2-1][num_huosan_2][2][0]=i;
                huosan[PLAYER2-1][num_huosan_2][0][1]=j+1;
                huosan[PLAYER2-1][num_huosan_2][1][1]=j+2;
                huosan[PLAYER2-1][num_huosan_2][2][1]=j+3;
                huosan[PLAYER2-1][num_huosan_2][3][0]=i;
                huosan[PLAYER2-1][num_huosan_2][3][1]=j;
                huosan[PLAYER2-1][num_huosan_2][4][0]=i;
                huosan[PLAYER2-1][num_huosan_2][4][1]=j+4;
                huosan[PLAYER2-1][num_huosan_2][5][0]=i;
                huosan[PLAYER2-1][num_huosan_2][5][1]=j-1;
                huosan[PLAYER2-1][num_huosan_2][6][0]=i;
                huosan[PLAYER2-1][num_huosan_2][6][1]=j+5;
                num_huosan_2++;
            }
            if(i+4<row && this_board[i][j]==0 && this_board[i+1][j]==PLAYER2 && this_board[i+2][j]==PLAYER2 && this_board[i+3][j]==PLAYER2 && this_board[i+4][j]==0 && ((i-1>=0 && this_board[i-1][j]==0)&&( i+5<row && this_board[i+5][j]==0)))
            {
                huosan[PLAYER2-1][num_huosan_2][0][0]=i+1;
                huosan[PLAYER2-1][num_huosan_2][1][0]=i+2;
                huosan[PLAYER2-1][num_huosan_2][2][0]=i+3;
                huosan[PLAYER2-1][num_huosan_2][0][1]=j;
                huosan[PLAYER2-1][num_huosan_2][1][1]=j;
                huosan[PLAYER2-1][num_huosan_2][2][1]=j;
                huosan[PLAYER2-1][num_huosan_2][3][0]=i;
                huosan[PLAYER2-1][num_huosan_2][3][1]=j;
                huosan[PLAYER2-1][num_huosan_2][4][0]=i+4;
                huosan[PLAYER2-1][num_huosan_2][4][1]=j;
                huosan[PLAYER2-1][num_huosan_2][5][0]=i-1;
                huosan[PLAYER2-1][num_huosan_2][5][1]=j;
                huosan[PLAYER2-1][num_huosan_2][6][0]=i+5;
                huosan[PLAYER2-1][num_huosan_2][6][1]=j;
                num_huosan_2++;
            }
            if(i+4<row && j+4<col && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER2 && 
            this_board[i+2][j+2]==PLAYER2 && this_board[i+3][j+3]==PLAYER2 && this_board[i+4][j+4]==0 && ((i-1>=0 && j-1>=0 && this_board[i-1][j-1]==0)&&( i+5<row && j+5<row && this_board[i+5][j+5]==0)))
            {
                huosan[PLAYER2-1][num_huosan_2][0][0]=i+1;
                huosan[PLAYER2-1][num_huosan_2][1][0]=i+2;
                huosan[PLAYER2-1][num_huosan_2][2][0]=i+3;
                huosan[PLAYER2-1][num_huosan_2][0][1]=j+1;
                huosan[PLAYER2-1][num_huosan_2][1][1]=j+2;
                huosan[PLAYER2-1][num_huosan_2][2][1]=j+3;
                huosan[PLAYER2-1][num_huosan_2][3][0]=i;
                huosan[PLAYER2-1][num_huosan_2][3][1]=j;
                huosan[PLAYER2-1][num_huosan_2][4][0]=i+4;
                huosan[PLAYER2-1][num_huosan_2][4][1]=j+4;
                huosan[PLAYER2-1][num_huosan_2][5][0]=i-1;
                huosan[PLAYER2-1][num_huosan_2][5][1]=j-1;
                huosan[PLAYER2-1][num_huosan_2][6][0]=i+5;
                huosan[PLAYER2-1][num_huosan_2][6][1]=j+5;
                num_huosan_2++;
            }
            if(i-4>=0 && j+4<col && this_board[i][j]==0 && this_board[i-1][j+1]==PLAYER2 && 
            this_board[i-2][j+2]==PLAYER2 && this_board[i-3][j+3]==PLAYER2 && this_board[i-4][j+4]==0 && ((j-1>=0 && this_board[i+1][j-1]==0)&&( i-5>=0 && j+5<col && this_board[i-5][j+5]==0)))
            {
                huosan[PLAYER2-1][num_huosan_2][0][0]=i-1;
                huosan[PLAYER2-1][num_huosan_2][1][0]=i-2;
                huosan[PLAYER2-1][num_huosan_2][2][0]=i-3;
                huosan[PLAYER2-1][num_huosan_2][0][1]=j+1;
                huosan[PLAYER2-1][num_huosan_2][1][1]=j+2;
                huosan[PLAYER2-1][num_huosan_2][2][1]=j+3;
                huosan[PLAYER2-1][num_huosan_2][3][0]=i;
                huosan[PLAYER2-1][num_huosan_2][3][1]=j;
                huosan[PLAYER2-1][num_huosan_2][4][0]=i-4;
                huosan[PLAYER2-1][num_huosan_2][4][1]=j+4;
                huosan[PLAYER2-1][num_huosan_2][5][0]=i+1;
                huosan[PLAYER2-1][num_huosan_2][5][1]=j-1;
                huosan[PLAYER2-1][num_huosan_2][6][0]=i-5;
                huosan[PLAYER2-1][num_huosan_2][6][1]=j+5;
                num_huosan_2++;
            }

        
        }
    }
}

void find_tiaohuosan(int this_board[][COL],const int row,const int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //PLAYER1的跳活三
            if(j+5<col && !iswin[i][j+3] && !iswin[i][j] && !iswin[i][j+5] && this_board[i][j]==0 && this_board[i][j+1]==PLAYER1 && this_board[i][j+2]==PLAYER1 && this_board[i][j+3]==0 && this_board[i][j+4]==PLAYER1 && this_board[i][j+5]==0)
            {
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][1]=j+1;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][1]=j+2;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][1]=j+4;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][1]=j+3;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][1]=j+5;
                num_tiaohuosan_1++;
            }
            if(j+5<col && !iswin[i][j+2] && !iswin[i][j] && !iswin[i][j+5] && this_board[i][j]==0 && this_board[i][j+1]==PLAYER1 && this_board[i][j+2]==0 && this_board[i][j+3]==PLAYER1 && this_board[i][j+4]==PLAYER1 && this_board[i][j+5]==0)
            {
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][1]=j+1;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][1]=j+3;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][1]=j+4;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][1]=j+2;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][1]=j+5;
                num_tiaohuosan_1++;
            }
            if(i+5<col && !iswin[i+3][j] && !iswin[i][j] && !iswin[i+5][j] &&this_board[i][j]==0 && this_board[i+1][j]==PLAYER1 && this_board[i+2][j]==PLAYER1 && this_board[i+3][j]==0 && this_board[i+4][j]==PLAYER1 && this_board[i+5][j]==0)
            {
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][0]=i+1;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][0]=i+2;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][0]=i+4;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][0]=i+3;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][0]=i+5;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][1]=j;
                num_tiaohuosan_1++;
            }
            if(i+5<col && !iswin[i+2][j] && !iswin[i][j] && !iswin[i+5][j] && this_board[i][j]==0 && this_board[i+1][j]==PLAYER1 && this_board[i+2][j]==0 && this_board[i+3][j]==PLAYER1 && this_board[i+4][j]==PLAYER1 && this_board[i+5][j]==0)
            {
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][0]=i+1;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][0]=i+3;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][0]=i+4;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][0]=i+2;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][0]=i+5;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][1]=j;
                num_tiaohuosan_1++;
            }
            if(i+5<col && j+5<row && !iswin[i+3][j+3] && !iswin[i][j] && !iswin[i+5][j+5] && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER1 && this_board[i+2][j+2]==PLAYER1 && this_board[i+3][j+3]==0 && this_board[i+4][j+4]==PLAYER1 && this_board[i+5][j+5]==0)
            {
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][0]=i+1;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][0]=i+2;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][0]=i+4;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][0]=i+3;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][1]=j+1;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][1]=j+2;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][1]=j+4;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][1]=j+3;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][0]=i+5;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][1]=j+5;
                num_tiaohuosan_1++;
            }
            if(i+5<col && j+5<row && !iswin[i+2][j+2] && !iswin[i][j] && !iswin[i+5][j+5] && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER1 && this_board[i+2][j+2]==0 && this_board[i+3][j+3]==PLAYER1 && this_board[i+4][j+4]==PLAYER1 && this_board[i+5][j+5]==0)
            {
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][0]=i+1;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][0]=i+3;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][0]=i+4;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][0]=i+2;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][1]=j+1;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][1]=j+3;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][1]=j+4;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][1]=j+2;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][0]=i+5;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][1]=j+5;
                num_tiaohuosan_1++;
            }
            if(i+5<col && j-5>=0 && !iswin[i+3][j-3] && !iswin[i][j] && !iswin[i+5][j-5] && this_board[i][j]==0 && this_board[i+1][j-1]==PLAYER1 && this_board[i+2][j-2]==PLAYER1 && this_board[i+3][j-3]==0 && this_board[i+4][j-4]==PLAYER1 && this_board[i+5][j-5]==0)
            {
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][0]=i+1;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][0]=i+2;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][0]=i+4;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][0]=i+3;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][1]=j-1;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][1]=j-2;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][1]=j-4;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][1]=j-3;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][0]=i+5;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][1]=j-5;
                num_tiaohuosan_1++;
            }
            if(i+5<col && j-5>=0 && !iswin[i+2][j-2] && !iswin[i][j] && !iswin[i+5][j-5] && this_board[i][j]==0 && this_board[i+1][j-1]==PLAYER1 && this_board[i+2][j-2]==0 && this_board[i+3][j-3]==PLAYER1 && this_board[i+4][j-4]==PLAYER1 && this_board[i+5][j-5]==0)
            {
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][0]=i+1;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][0]=i+3;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][0]=i+4;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][0]=i+2;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][0][1]=j-1;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][1][1]=j-3;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][2][1]=j-4;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][3][1]=j-2;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][0]=i;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][4][1]=j;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][0]=i+5;
                tiaohuosan[PLAYER1-1][num_tiaohuosan_1][5][1]=j-5;
                num_tiaohuosan_1++;
            }
            //PLAYER2的跳活三
            if(j+5<col && this_board[i][j]==0 && this_board[i][j+1]==PLAYER2 && this_board[i][j+2]==PLAYER2 && this_board[i][j+3]==0 && this_board[i][j+4]==PLAYER2 && this_board[i][j+5]==0)
            {
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][1]=j+1;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][1]=j+2;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][1]=j+4;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][1]=j+3;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][1]=j+5;
                num_tiaohuosan_2++;
            }
            if(j+5<col && this_board[i][j]==0 && this_board[i][j+1]==PLAYER2 && this_board[i][j+2]==0 && this_board[i][j+3]==PLAYER2 && this_board[i][j+4]==PLAYER2 && this_board[i][j+5]==0)
            {
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][1]=j+1;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][1]=j+3;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][1]=j+4;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][1]=j+2;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][1]=j+5;
                num_tiaohuosan_2++;
            }
            if(i+5<col && this_board[i][j]==0 && this_board[i+1][j]==PLAYER2 && this_board[i+2][j]==PLAYER2 && this_board[i+3][j]==0 && this_board[i+4][j]==PLAYER2 && this_board[i+5][j]==0)
            {
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][0]=i+1;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][0]=i+2;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][0]=i+4;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][0]=i+3;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][0]=i+5;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][1]=j;
                num_tiaohuosan_2++;
            }
            if(i+5<col && this_board[i][j]==0 && this_board[i+1][j]==PLAYER2 && this_board[i+2][j]==0 && this_board[i+3][j]==PLAYER2 && this_board[i+4][j]==PLAYER2 && this_board[i+5][j]==0)
            {
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][0]=i+1;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][0]=i+3;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][0]=i+4;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][0]=i+2;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][0]=i+5;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][1]=j;
                num_tiaohuosan_2++;
            }
            if(i+5<col && j+5<row && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER2 && this_board[i+2][j+2]==PLAYER2 && this_board[i+3][j+3]==0 && this_board[i+4][j+4]==PLAYER2 && this_board[i+5][j+5]==0)
            {
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][0]=i+1;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][0]=i+2;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][0]=i+4;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][0]=i+3;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][1]=j+1;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][1]=j+2;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][1]=j+4;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][1]=j+3;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][0]=i+5;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][1]=j+5;
                num_tiaohuosan_2++;
            }
            if(i+5<col && j+5<row && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER2 && this_board[i+2][j+2]==0 && this_board[i+3][j+3]==PLAYER2 && this_board[i+4][j+4]==PLAYER2 && this_board[i+5][j+5]==0)
            {
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][0]=i+1;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][0]=i+3;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][0]=i+4;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][0]=i+2;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][1]=j+1;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][1]=j+3;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][1]=j+4;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][1]=j+2;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][0]=i+5;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][1]=j+5;
                num_tiaohuosan_2++;
            }
            if(i+5<col && j-5>=0 && this_board[i][j]==0 && this_board[i+1][j-1]==PLAYER2 && this_board[i+2][j-2]==PLAYER2 && this_board[i+3][j-3]==0 && this_board[i+4][j-4]==PLAYER2 && this_board[i+5][j-5]==0)
            {
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][0]=i+1;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][0]=i+2;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][0]=i+4;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][0]=i+3;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][1]=j-1;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][1]=j-2;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][1]=j-4;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][1]=j-3;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][0]=i+5;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][1]=j-5;
                num_tiaohuosan_2++;
            }
            if(i+5<col && j-5>=0 && this_board[i][j]==0 && this_board[i+1][j-1]==PLAYER2 && this_board[i+2][j-2]==0 && this_board[i+3][j-3]==PLAYER2 && this_board[i+4][j-4]==PLAYER2 && this_board[i+5][j-5]==0)
            {
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][0]=i+1;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][0]=i+3;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][0]=i+4;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][0]=i+2;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][0][1]=j-1;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][1][1]=j-3;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][2][1]=j-4;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][3][1]=j-2;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][0]=i;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][4][1]=j;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][0]=i+5;
                tiaohuosan[PLAYER2-1][num_tiaohuosan_2][5][1]=j-5;
                num_tiaohuosan_2++;
            }

        }
    }
}

void find_chongsan(int this_board[][COL],const int row,const int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //PLAYER1的冲三
            if(j+4<col && this_board[i][j]==PLAYER2 && this_board[i][j+1]==PLAYER1 && this_board[i][j+2]==PLAYER1 && this_board[i][j+3]==PLAYER1 && this_board[i][j+4]==0)
            {
                chongsan[PLAYER1-1][num_chongsan_1][0][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][1][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][2][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][0][1]=j+1;
                chongsan[PLAYER1-1][num_chongsan_1][1][1]=j+2;
                chongsan[PLAYER1-1][num_chongsan_1][2][1]=j+3;
                chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                num_chongsan_1++;
            }
            if(j-4>=0 && this_board[i][j]==PLAYER2 && this_board[i][j-1]==PLAYER1 && this_board[i][j-2]==PLAYER1 && this_board[i][j-3]==PLAYER1 && this_board[i][j-4]==0)
            {
                chongsan[PLAYER1-1][num_chongsan_1][0][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][1][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][2][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][0][1]=j-1;
                chongsan[PLAYER1-1][num_chongsan_1][1][1]=j-2;
                chongsan[PLAYER1-1][num_chongsan_1][2][1]=j-3;
                chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                num_chongsan_1++;
            }
            if(i+4<row && this_board[i][j]==PLAYER2 && this_board[i+1][j]==PLAYER1 && this_board[i+2][j]==PLAYER1 && this_board[i+3][j]==PLAYER1 && this_board[i+4][j]==0)
            {
                chongsan[PLAYER1-1][num_chongsan_1][0][0]=i+1;
                chongsan[PLAYER1-1][num_chongsan_1][1][0]=i+2;
                chongsan[PLAYER1-1][num_chongsan_1][2][0]=i+3;
                chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][0][1]=j;
                chongsan[PLAYER1-1][num_chongsan_1][1][1]=j;
                chongsan[PLAYER1-1][num_chongsan_1][2][1]=j;
                chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                num_chongsan_1++;
            }
            if(i-4>=0 && this_board[i][j]==PLAYER2 && this_board[i-1][j]==PLAYER1 && this_board[i-2][j]==PLAYER1 && this_board[i-3][j]==PLAYER1 && this_board[i-4][j]==0)
            {
                chongsan[PLAYER1-1][num_chongsan_1][0][0]=i-1;
                chongsan[PLAYER1-1][num_chongsan_1][1][0]=i-2;
                chongsan[PLAYER1-1][num_chongsan_1][2][0]=i-3;
                chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][0][1]=j;
                chongsan[PLAYER1-1][num_chongsan_1][1][1]=j;
                chongsan[PLAYER1-1][num_chongsan_1][2][1]=j;
                chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                num_chongsan_1++;
            }
            if(i+4<row && j+4<col && this_board[i][j]==PLAYER2 && this_board[i+1][j+1]==PLAYER1 && this_board[i+2][j+2]==PLAYER1 && this_board[i+3][j+3]==PLAYER1 && this_board[i+4][j+4]==0)
            {
                chongsan[PLAYER1-1][num_chongsan_1][0][0]=i+1;
                chongsan[PLAYER1-1][num_chongsan_1][1][0]=i+2;
                chongsan[PLAYER1-1][num_chongsan_1][2][0]=i+3;
                chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][0][1]=j+1;
                chongsan[PLAYER1-1][num_chongsan_1][1][1]=j+2;
                chongsan[PLAYER1-1][num_chongsan_1][2][1]=j+3;
                chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                num_chongsan_1++;
            }
            if(i+4<row && j-4>=0 && this_board[i][j]==PLAYER2 && this_board[i+1][j-1]==PLAYER1 && this_board[i+2][j-2]==PLAYER1 && this_board[i+3][j-3]==PLAYER1 && this_board[i+4][j-4]==0)
            {
                chongsan[PLAYER1-1][num_chongsan_1][0][0]=i+1;
                chongsan[PLAYER1-1][num_chongsan_1][1][0]=i+2;
                chongsan[PLAYER1-1][num_chongsan_1][2][0]=i+3;
                chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][0][1]=j-1;
                chongsan[PLAYER1-1][num_chongsan_1][1][1]=j-2;
                chongsan[PLAYER1-1][num_chongsan_1][2][1]=j-3;
                chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                num_chongsan_1++;
            }
            if(i-4>=0 && j-4>=0 && this_board[i][j]==PLAYER2 && this_board[i-1][j-1]==PLAYER1 && this_board[i-2][j-2]==PLAYER1 && this_board[i-3][j-3]==PLAYER1 && this_board[i-4][j-4]==0)
            {
                chongsan[PLAYER1-1][num_chongsan_1][0][0]=i-1;
                chongsan[PLAYER1-1][num_chongsan_1][1][0]=i-2;
                chongsan[PLAYER1-1][num_chongsan_1][2][0]=i-3;
                chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][0][1]=j-1;
                chongsan[PLAYER1-1][num_chongsan_1][1][1]=j-2;
                chongsan[PLAYER1-1][num_chongsan_1][2][1]=j-3;
                chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                num_chongsan_1++;
            }
            if(i-4>=0 && j+4<col && this_board[i][j]==PLAYER2 && this_board[i-1][j+1]==PLAYER1 && this_board[i-2][j+2]==PLAYER1 && this_board[i-3][j+3]==PLAYER1 && this_board[i-4][j+4]==0)
            {
                chongsan[PLAYER1-1][num_chongsan_1][0][0]=i-1;
                chongsan[PLAYER1-1][num_chongsan_1][1][0]=i-2;
                chongsan[PLAYER1-1][num_chongsan_1][2][0]=i-3;
                chongsan[PLAYER1-1][num_chongsan_1][3][0]=i;
                chongsan[PLAYER1-1][num_chongsan_1][0][1]=j+1;
                chongsan[PLAYER1-1][num_chongsan_1][1][1]=j+2;
                chongsan[PLAYER1-1][num_chongsan_1][2][1]=j+3;
                chongsan[PLAYER1-1][num_chongsan_1][3][1]=j;
                num_chongsan_1++;
            }
            //PLAYER2的冲三
            if(j+4<col && this_board[i][j]==PLAYER1 && this_board[i][j+1]==PLAYER2 && this_board[i][j+2]==PLAYER2 && this_board[i][j+3]==PLAYER2 && this_board[i][j+4]==0)
            {
                chongsan[PLAYER2-1][num_chongsan_2][0][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][1][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][2][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][3][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][0][1]=j+1;
                chongsan[PLAYER2-1][num_chongsan_2][1][1]=j+2;
                chongsan[PLAYER2-1][num_chongsan_2][2][1]=j+3;
                chongsan[PLAYER2-1][num_chongsan_2][3][1]=j;
                num_chongsan_2++;
            }
            if(j-4>=0 && this_board[i][j]==PLAYER1 && this_board[i][j-1]==PLAYER2 && this_board[i][j-2]==PLAYER2 && this_board[i][j-3]==PLAYER2 && this_board[i][j-4]==0)
            {
                chongsan[PLAYER2-1][num_chongsan_2][0][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][1][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][2][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][3][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][0][1]=j-1;
                chongsan[PLAYER2-1][num_chongsan_2][1][1]=j-2;
                chongsan[PLAYER2-1][num_chongsan_2][2][1]=j-3;
                chongsan[PLAYER2-1][num_chongsan_2][3][1]=j;
                num_chongsan_2++;
            }
            if(i+4<row && this_board[i][j]==PLAYER1 && this_board[i+1][j]==PLAYER2 && this_board[i+2][j]==PLAYER2 && this_board[i+3][j]==PLAYER2 && this_board[i+4][j]==0)
            {
                chongsan[PLAYER2-1][num_chongsan_2][0][0]=i+1;
                chongsan[PLAYER2-1][num_chongsan_2][1][0]=i+2;
                chongsan[PLAYER2-1][num_chongsan_2][2][0]=i+3;
                chongsan[PLAYER2-1][num_chongsan_2][3][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][0][1]=j;
                chongsan[PLAYER2-1][num_chongsan_2][1][1]=j;
                chongsan[PLAYER2-1][num_chongsan_2][2][1]=j;
                chongsan[PLAYER2-1][num_chongsan_2][3][1]=j;
                num_chongsan_2++;
            }
            if(i-4>=0 && this_board[i][j]==PLAYER1 && this_board[i-1][j]==PLAYER2 && this_board[i-2][j]==PLAYER2 && this_board[i-3][j]==PLAYER2 && this_board[i-4][j]==0)
            {
                chongsan[PLAYER2-1][num_chongsan_2][0][0]=i-1;
                chongsan[PLAYER2-1][num_chongsan_2][1][0]=i-2;
                chongsan[PLAYER2-1][num_chongsan_2][2][0]=i-3;
                chongsan[PLAYER2-1][num_chongsan_2][3][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][0][1]=j;
                chongsan[PLAYER2-1][num_chongsan_2][1][1]=j;
                chongsan[PLAYER2-1][num_chongsan_2][2][1]=j;
                chongsan[PLAYER2-1][num_chongsan_2][3][1]=j;
                num_chongsan_2++;
            }
            if(i+4<row && j+4<col && this_board[i][j]==PLAYER1 && this_board[i+1][j+1]==PLAYER2 && this_board[i+2][j+2]==PLAYER2 && this_board[i+3][j+3]==PLAYER2 && this_board[i+4][j+4]==0)
            {
                chongsan[PLAYER2-1][num_chongsan_2][0][0]=i+1;
                chongsan[PLAYER2-1][num_chongsan_2][1][0]=i+2;
                chongsan[PLAYER2-1][num_chongsan_2][2][0]=i+3;
                chongsan[PLAYER2-1][num_chongsan_2][3][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][0][1]=j+1;
                chongsan[PLAYER2-1][num_chongsan_2][1][1]=j+2;
                chongsan[PLAYER2-1][num_chongsan_2][2][1]=j+3;
                chongsan[PLAYER2-1][num_chongsan_2][3][1]=j;
                num_chongsan_2++;
            }
            if(i+4<row && j-4>=0 && this_board[i][j]==PLAYER1 && this_board[i+1][j-1]==PLAYER2 && this_board[i+2][j-2]==PLAYER2 && this_board[i+3][j-3]==PLAYER2 && this_board[i+4][j-4]==0)
            {
                chongsan[PLAYER2-1][num_chongsan_2][0][0]=i+1;
                chongsan[PLAYER2-1][num_chongsan_2][1][0]=i+2;
                chongsan[PLAYER2-1][num_chongsan_2][2][0]=i+3;
                chongsan[PLAYER2-1][num_chongsan_2][3][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][0][1]=j-1;
                chongsan[PLAYER2-1][num_chongsan_2][1][1]=j-2;
                chongsan[PLAYER2-1][num_chongsan_2][2][1]=j-3;
                chongsan[PLAYER2-1][num_chongsan_2][3][1]=j;
                num_chongsan_2++;
            }
            if(i-4>=0 && j-4>=0 && this_board[i][j]==PLAYER1 && this_board[i-1][j-1]==PLAYER2 && this_board[i-2][j-2]==PLAYER2 && this_board[i-3][j-3]==PLAYER2 && this_board[i-4][j-4]==0)
            {
                chongsan[PLAYER2-1][num_chongsan_2][0][0]=i-1;
                chongsan[PLAYER2-1][num_chongsan_2][1][0]=i-2;
                chongsan[PLAYER2-1][num_chongsan_2][2][0]=i-3;
                chongsan[PLAYER2-1][num_chongsan_2][3][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][0][1]=j-1;
                chongsan[PLAYER2-1][num_chongsan_2][1][1]=j-2;
                chongsan[PLAYER2-1][num_chongsan_2][2][1]=j-3;
                chongsan[PLAYER2-1][num_chongsan_2][3][1]=j;
                num_chongsan_2++;
            }
            if(i-4>=0 && j+4<col && this_board[i][j]==PLAYER1 && this_board[i-1][j+1]==PLAYER2 && this_board[i-2][j+2]==PLAYER2 && this_board[i-3][j+3]==PLAYER2 && this_board[i-4][j+4]==0)
            {
                chongsan[PLAYER2-1][num_chongsan_2][0][0]=i-1;
                chongsan[PLAYER2-1][num_chongsan_2][1][0]=i-2;
                chongsan[PLAYER2-1][num_chongsan_2][2][0]=i-3;
                chongsan[PLAYER2-1][num_chongsan_2][3][0]=i;
                chongsan[PLAYER2-1][num_chongsan_2][0][1]=j+1;
                chongsan[PLAYER2-1][num_chongsan_2][1][1]=j+2;
                chongsan[PLAYER2-1][num_chongsan_2][2][1]=j+3;
                chongsan[PLAYER2-1][num_chongsan_2][3][1]=j;
                num_chongsan_2++;
            }
        }
    }
}

void find_huosi(int this_board[][COL],const int row,const int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //PLAYER1的活四
            if(j+5<col && this_board[i][j]==0 && this_board[i][j+1]==PLAYER1 && this_board[i][j+2]==PLAYER1 && this_board[i][j+3]==PLAYER1 && this_board[i][j+4]==PLAYER1 && this_board[i][j+5]==0)
            {
                huosi[PLAYER1-1][num_huosi_1][0][0]=i;
                huosi[PLAYER1-1][num_huosi_1][1][0]=i;
                huosi[PLAYER1-1][num_huosi_1][2][0]=i;
                huosi[PLAYER1-1][num_huosi_1][3][0]=i;
                huosi[PLAYER1-1][num_huosi_1][0][1]=j+1;
                huosi[PLAYER1-1][num_huosi_1][1][1]=j+2;
                huosi[PLAYER1-1][num_huosi_1][2][1]=j+3;
                huosi[PLAYER1-1][num_huosi_1][3][1]=j+4;
                huosi[PLAYER1-1][num_huosi_1][4][0]=i;
                huosi[PLAYER1-1][num_huosi_1][5][0]=i;
                huosi[PLAYER1-1][num_huosi_1][4][1]=j;
                huosi[PLAYER1-1][num_huosi_1][5][1]=j+5;
                num_huosi_1++;
            }
            if(i+5<row && this_board[i][j]==0 && this_board[i+1][j]==PLAYER1 && this_board[i+2][j]==PLAYER1 && this_board[i+3][j]==PLAYER1 && this_board[i+4][j]==PLAYER1 && this_board[i+5][j]==0)
            {
                huosi[PLAYER1-1][num_huosi_1][0][0]=i+1;
                huosi[PLAYER1-1][num_huosi_1][1][0]=i+2;
                huosi[PLAYER1-1][num_huosi_1][2][0]=i+3;
                huosi[PLAYER1-1][num_huosi_1][3][0]=i+4;
                huosi[PLAYER1-1][num_huosi_1][0][1]=j;
                huosi[PLAYER1-1][num_huosi_1][1][1]=j;
                huosi[PLAYER1-1][num_huosi_1][2][1]=j;
                huosi[PLAYER1-1][num_huosi_1][3][1]=j;
                huosi[PLAYER1-1][num_huosi_1][4][0]=i;
                huosi[PLAYER1-1][num_huosi_1][5][0]=i+5;
                huosi[PLAYER1-1][num_huosi_1][4][1]=j;
                huosi[PLAYER1-1][num_huosi_1][5][1]=j;
                num_huosi_1++;
            }
            if(i+5<row && j+5<col && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER1 && this_board[i+2][j+2]==PLAYER1 && this_board[i+3][j+3]==PLAYER1 && this_board[i+4][j+4]==PLAYER1 && this_board[i+5][j+5]==0)
            {
                huosi[PLAYER1-1][num_huosi_1][0][0]=i+1;
                huosi[PLAYER1-1][num_huosi_1][1][0]=i+2;
                huosi[PLAYER1-1][num_huosi_1][2][0]=i+3;
                huosi[PLAYER1-1][num_huosi_1][3][0]=i+4;
                huosi[PLAYER1-1][num_huosi_1][0][1]=j+1;
                huosi[PLAYER1-1][num_huosi_1][1][1]=j+2;
                huosi[PLAYER1-1][num_huosi_1][2][1]=j+3;
                huosi[PLAYER1-1][num_huosi_1][3][1]=j+4;
                huosi[PLAYER1-1][num_huosi_1][4][0]=i;
                huosi[PLAYER1-1][num_huosi_1][5][0]=i+5;
                huosi[PLAYER1-1][num_huosi_1][4][1]=j;
                huosi[PLAYER1-1][num_huosi_1][5][1]=j+5;
                num_huosi_1++;
            }
            if(i+5<row && j-5>=0 && this_board[i][j]==0 && this_board[i+1][j-1]==PLAYER1 && this_board[i+2][j-2]==PLAYER1 && this_board[i+3][j-3]==PLAYER1 && this_board[i+4][j-4]==PLAYER1 && this_board[i+5][j-5]==0)
            {
                huosi[PLAYER1-1][num_huosi_1][0][0]=i+1;
                huosi[PLAYER1-1][num_huosi_1][1][0]=i+2;
                huosi[PLAYER1-1][num_huosi_1][2][0]=i+3;
                huosi[PLAYER1-1][num_huosi_1][3][0]=i+4;
                huosi[PLAYER1-1][num_huosi_1][0][1]=j-1;
                huosi[PLAYER1-1][num_huosi_1][1][1]=j-2;
                huosi[PLAYER1-1][num_huosi_1][2][1]=j-3;
                huosi[PLAYER1-1][num_huosi_1][3][1]=j-4;
                huosi[PLAYER1-1][num_huosi_1][4][0]=i;
                huosi[PLAYER1-1][num_huosi_1][5][0]=i+5;
                huosi[PLAYER1-1][num_huosi_1][4][1]=j;
                huosi[PLAYER1-1][num_huosi_1][5][1]=j-5;
                num_huosi_1++;
            }
            //PLAYER2的活四
            if(j+5<col && this_board[i][j]==0 && this_board[i][j+1]==PLAYER2 && this_board[i][j+2]==PLAYER2 && this_board[i][j+3]==PLAYER2 && this_board[i][j+4]==PLAYER2 && this_board[i][j+5]==0)
            {
                huosi[PLAYER2-1][num_huosi_2][0][0]=i;
                huosi[PLAYER2-1][num_huosi_2][1][0]=i;
                huosi[PLAYER2-1][num_huosi_2][2][0]=i;
                huosi[PLAYER2-1][num_huosi_2][3][0]=i;
                huosi[PLAYER2-1][num_huosi_2][0][1]=j+1;
                huosi[PLAYER2-1][num_huosi_2][1][1]=j+2;
                huosi[PLAYER2-1][num_huosi_2][2][1]=j+3;
                huosi[PLAYER2-1][num_huosi_2][3][1]=j+4;
                huosi[PLAYER2-1][num_huosi_2][4][0]=i;
                huosi[PLAYER2-1][num_huosi_2][5][0]=i;
                huosi[PLAYER2-1][num_huosi_2][4][1]=j;
                huosi[PLAYER2-1][num_huosi_2][5][1]=j+5;
                num_huosi_2++;
            }
            if(i+5<row && this_board[i][j]==0 && this_board[i+1][j]==PLAYER2 && this_board[i+2][j]==PLAYER2 && this_board[i+3][j]==PLAYER2 && this_board[i+4][j]==PLAYER2 && this_board[i+5][j]==0)
            {
                huosi[PLAYER2-1][num_huosi_2][0][0]=i+1;
                huosi[PLAYER2-1][num_huosi_2][1][0]=i+2;
                huosi[PLAYER2-1][num_huosi_2][2][0]=i+3;
                huosi[PLAYER2-1][num_huosi_2][3][0]=i+4;
                huosi[PLAYER2-1][num_huosi_2][0][1]=j;
                huosi[PLAYER2-1][num_huosi_2][1][1]=j;
                huosi[PLAYER2-1][num_huosi_2][2][1]=j;
                huosi[PLAYER2-1][num_huosi_2][3][1]=j;
                huosi[PLAYER2-1][num_huosi_2][4][0]=i;
                huosi[PLAYER2-1][num_huosi_2][5][0]=i+5;
                huosi[PLAYER2-1][num_huosi_2][4][1]=j;
                huosi[PLAYER2-1][num_huosi_2][5][1]=j;
                num_huosi_2++;
            }
            if(i+5<row && j+5<col && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER2 && this_board[i+2][j+2]==PLAYER2 && this_board[i+3][j+3]==PLAYER2 && this_board[i+4][j+4]==PLAYER2 && this_board[i+5][j+5]==0)
            {
                huosi[PLAYER2-1][num_huosi_2][0][0]=i+1;
                huosi[PLAYER2-1][num_huosi_2][1][0]=i+2;
                huosi[PLAYER2-1][num_huosi_2][2][0]=i+3;
                huosi[PLAYER2-1][num_huosi_2][3][0]=i+4;
                huosi[PLAYER2-1][num_huosi_2][0][1]=j+1;
                huosi[PLAYER2-1][num_huosi_2][1][1]=j+2;
                huosi[PLAYER2-1][num_huosi_2][2][1]=j+3;
                huosi[PLAYER2-1][num_huosi_2][3][1]=j+4;
                huosi[PLAYER2-1][num_huosi_2][4][0]=i;
                huosi[PLAYER2-1][num_huosi_2][5][0]=i+5;
                huosi[PLAYER2-1][num_huosi_2][4][1]=j;
                huosi[PLAYER2-1][num_huosi_2][5][1]=j+5;
                num_huosi_2++;
            }
            if(i+5<row && j-5>=0 && this_board[i][j]==0 && this_board[i+1][j-1]==PLAYER2 && this_board[i+2][j-2]==PLAYER2 && this_board[i+3][j-3]==PLAYER2 && this_board[i+4][j-4]==PLAYER2 && this_board[i+5][j-5]==0)
            {
                huosi[PLAYER2-1][num_huosi_2][0][0]=i+1;
                huosi[PLAYER2-1][num_huosi_2][1][0]=i+2;
                huosi[PLAYER2-1][num_huosi_2][2][0]=i+3;
                huosi[PLAYER2-1][num_huosi_2][3][0]=i+4;
                huosi[PLAYER2-1][num_huosi_2][0][1]=j-1;
                huosi[PLAYER2-1][num_huosi_2][1][1]=j-2;
                huosi[PLAYER2-1][num_huosi_2][2][1]=j-3;
                huosi[PLAYER2-1][num_huosi_2][3][1]=j-4;
                huosi[PLAYER2-1][num_huosi_2][4][0]=i;
                huosi[PLAYER2-1][num_huosi_2][5][0]=i+5;
                huosi[PLAYER2-1][num_huosi_2][4][1]=j;
                huosi[PLAYER2-1][num_huosi_2][5][1]=j-5;
                num_huosi_2++;
            }

        }
    }
}

void find_chongsi(int this_board[][COL],const int row,const int col)//这里要加入很多是冲四的情况，懒了by1.7。修复了边界冲四by1.18
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //PLAYER1的冲四
            if(i==0 && this_board[i][j]==PLAYER1 &&this_board[i+1][j]==PLAYER1 && this_board[i+2][j]==PLAYER1 && this_board[i+3][j]==PLAYER1 && this_board[i+4][j]==0)
            {
                chongsi[PLAYER1-1][num_chongsi_1][0][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][1][0]=i+1;
                chongsi[PLAYER1-1][num_chongsi_1][2][0]=i+2;
                chongsi[PLAYER1-1][num_chongsi_1][3][0]=i+3;
                chongsi[PLAYER1-1][num_chongsi_1][0][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][1][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][2][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][3][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][4][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][5][0]=i+4;
                chongsi[PLAYER1-1][num_chongsi_1][4][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][5][1]=j;
                num_chongsi_1++;
            }
            if(i==row-1 && this_board[i][j]==PLAYER1 &&this_board[i-1][j]==PLAYER1 && this_board[i-2][j]==PLAYER1 && this_board[i-3][j]==PLAYER1 && this_board[i-4][j]==0)
            {
                chongsi[PLAYER1-1][num_chongsi_1][0][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][1][0]=i-1;
                chongsi[PLAYER1-1][num_chongsi_1][2][0]=i-2;
                chongsi[PLAYER1-1][num_chongsi_1][3][0]=i-3;
                chongsi[PLAYER1-1][num_chongsi_1][0][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][1][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][2][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][3][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][4][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][5][0]=i-4;
                chongsi[PLAYER1-1][num_chongsi_1][4][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][5][1]=j;
                num_chongsi_1++;
            }
            if(j==0 && this_board[i][j]==PLAYER1 &&this_board[i][j+1]==PLAYER1 && this_board[i][j+2]==PLAYER1 && this_board[i][j+3]==PLAYER1 && this_board[i][j+4]==0)
            {
                chongsi[PLAYER1-1][num_chongsi_1][0][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][1][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][2][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][3][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][0][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][1][1]=j+1;
                chongsi[PLAYER1-1][num_chongsi_1][2][1]=j+2;
                chongsi[PLAYER1-1][num_chongsi_1][3][1]=j+3;
                chongsi[PLAYER1-1][num_chongsi_1][4][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][5][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][4][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][5][1]=j+4;
                num_chongsi_1++;
            }
            if(j==col-1 && this_board[i][j]==PLAYER1 &&this_board[i][j-1]==PLAYER1 && this_board[i][j-2]==PLAYER1 && this_board[i][j-3]==PLAYER1 && this_board[i][j-4]==0)
            {
                chongsi[PLAYER1-1][num_chongsi_1][0][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][1][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][2][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][3][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][0][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][1][1]=j-1;
                chongsi[PLAYER1-1][num_chongsi_1][2][1]=j-2;
                chongsi[PLAYER1-1][num_chongsi_1][3][1]=j-3;
                chongsi[PLAYER1-1][num_chongsi_1][4][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][5][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][4][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][5][1]=j-4;
                num_chongsi_1++;
            }
            if(j+5<col && this_board[i][j]==PLAYER2 && this_board[i][j+1]==PLAYER1 && this_board[i][j+2]==PLAYER1 && this_board[i][j+3]==PLAYER1 && this_board[i][j+4]==PLAYER1 && this_board[i][j+5]==0)
            {
                chongsi[PLAYER1-1][num_chongsi_1][0][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][1][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][2][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][3][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][4][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][0][1]=j+1;
                chongsi[PLAYER1-1][num_chongsi_1][1][1]=j+2;
                chongsi[PLAYER1-1][num_chongsi_1][2][1]=j+3;
                chongsi[PLAYER1-1][num_chongsi_1][3][1]=j+4;
                chongsi[PLAYER1-1][num_chongsi_1][4][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][5][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][5][1]=j+5;
                num_chongsi_1++;
            }
            if(j-5>=0 && this_board[i][j]==PLAYER2 && this_board[i][j-1]==PLAYER1 && this_board[i][j-2]==PLAYER1 && this_board[i][j-3]==PLAYER1 && this_board[i][j-4]==PLAYER1 && this_board[i][j-5]==0)
            {
                chongsi[PLAYER1-1][num_chongsi_1][0][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][1][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][2][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][3][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][4][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][0][1]=j-1;
                chongsi[PLAYER1-1][num_chongsi_1][1][1]=j-2;
                chongsi[PLAYER1-1][num_chongsi_1][2][1]=j-3;
                chongsi[PLAYER1-1][num_chongsi_1][3][1]=j-4;
                chongsi[PLAYER1-1][num_chongsi_1][4][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][5][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][5][1]=j-5;
                num_chongsi_1++;
            }
            if(i+5<row && this_board[i][j]==PLAYER2 && this_board[i+1][j]==PLAYER1 && this_board[i+2][j]==PLAYER1 && this_board[i+3][j]==PLAYER1 && this_board[i+4][j]==PLAYER1 && this_board[i+5][j]==0)
            {
                chongsi[PLAYER1-1][num_chongsi_1][0][0]=i+1;
                chongsi[PLAYER1-1][num_chongsi_1][1][0]=i+2;
                chongsi[PLAYER1-1][num_chongsi_1][2][0]=i+3;
                chongsi[PLAYER1-1][num_chongsi_1][3][0]=i+4;
                chongsi[PLAYER1-1][num_chongsi_1][4][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][0][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][1][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][2][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][3][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][4][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][5][0]=i+5;
                chongsi[PLAYER1-1][num_chongsi_1][5][1]=j;
                num_chongsi_1++;
            }
            if(i-5>=0 && this_board[i][j]==PLAYER2 && this_board[i-1][j]==PLAYER1 && this_board[i-2][j]==PLAYER1 && this_board[i-3][j]==PLAYER1 && this_board[i-4][j]==PLAYER1 && this_board[i-5][j]==0)
            {
                chongsi[PLAYER1-1][num_chongsi_1][0][0]=i-1;
                chongsi[PLAYER1-1][num_chongsi_1][1][0]=i-2;
                chongsi[PLAYER1-1][num_chongsi_1][2][0]=i-3;
                chongsi[PLAYER1-1][num_chongsi_1][3][0]=i-4;
                chongsi[PLAYER1-1][num_chongsi_1][4][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][0][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][1][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][2][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][3][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][4][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][5][0]=i-5;
                chongsi[PLAYER1-1][num_chongsi_1][5][1]=j;
                num_chongsi_1++;
            }
            if(i+5<row && j+5<col && this_board[i][j]==PLAYER2 && this_board[i+1][j+1]==PLAYER1 && this_board[i+2][j+2]==PLAYER1 && this_board[i+3][j+3]==PLAYER1 && this_board[i+4][j+4]==PLAYER1 && this_board[i+5][j+5]==0)
            {
                chongsi[PLAYER1-1][num_chongsi_1][0][0]=i+1;
                chongsi[PLAYER1-1][num_chongsi_1][1][0]=i+2;
                chongsi[PLAYER1-1][num_chongsi_1][2][0]=i+3;
                chongsi[PLAYER1-1][num_chongsi_1][3][0]=i+4;
                chongsi[PLAYER1-1][num_chongsi_1][4][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][0][1]=j+1;
                chongsi[PLAYER1-1][num_chongsi_1][1][1]=j+2;
                chongsi[PLAYER1-1][num_chongsi_1][2][1]=j+3;
                chongsi[PLAYER1-1][num_chongsi_1][3][1]=j+4;
                chongsi[PLAYER1-1][num_chongsi_1][4][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][5][0]=i+5;
                chongsi[PLAYER1-1][num_chongsi_1][5][1]=j+5;
                num_chongsi_1++;
            }
            if(i+5<row && j-5>=0 && this_board[i][j]==PLAYER2 && this_board[i+1][j-1]==PLAYER1 && this_board[i+2][j-2]==PLAYER1 && this_board[i+3][j-3]==PLAYER1 && this_board[i+4][j-4]==PLAYER1 && this_board[i+5][j-5]==0)
            {
                chongsi[PLAYER1-1][num_chongsi_1][0][0]=i+1;
                chongsi[PLAYER1-1][num_chongsi_1][1][0]=i+2;
                chongsi[PLAYER1-1][num_chongsi_1][2][0]=i+3;
                chongsi[PLAYER1-1][num_chongsi_1][3][0]=i+4;
                chongsi[PLAYER1-1][num_chongsi_1][4][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][0][1]=j-1;
                chongsi[PLAYER1-1][num_chongsi_1][1][1]=j-2;
                chongsi[PLAYER1-1][num_chongsi_1][2][1]=j-3;
                chongsi[PLAYER1-1][num_chongsi_1][3][1]=j-4;
                chongsi[PLAYER1-1][num_chongsi_1][4][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][5][0]=i+5;
                chongsi[PLAYER1-1][num_chongsi_1][5][1]=j-5;
                num_chongsi_1++;
            }
            if(i-5>=0 && j-5>=0 && this_board[i][j]==PLAYER2 && this_board[i-1][j-1]==PLAYER1 && this_board[i-2][j-2]==PLAYER1 && this_board[i-3][j-3]==PLAYER1 && this_board[i-4][j-4]==PLAYER1 && this_board[i-5][j-5]==0)
            {
                chongsi[PLAYER1-1][num_chongsi_1][0][0]=i-1;
                chongsi[PLAYER1-1][num_chongsi_1][1][0]=i-2;
                chongsi[PLAYER1-1][num_chongsi_1][2][0]=i-3;
                chongsi[PLAYER1-1][num_chongsi_1][3][0]=i-4;
                chongsi[PLAYER1-1][num_chongsi_1][4][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][0][1]=j-1;
                chongsi[PLAYER1-1][num_chongsi_1][1][1]=j-2;
                chongsi[PLAYER1-1][num_chongsi_1][2][1]=j-3;
                chongsi[PLAYER1-1][num_chongsi_1][3][1]=j-4;
                chongsi[PLAYER1-1][num_chongsi_1][4][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][5][0]=i-5;
                chongsi[PLAYER1-1][num_chongsi_1][5][1]=j-5;
                num_chongsi_1++;
            }
            if(i-5>=0 && j+5<col && this_board[i][j]==PLAYER2 && this_board[i-1][j+1]==PLAYER1 && this_board[i-2][j+2]==PLAYER1 && this_board[i-3][j+3]==PLAYER1 && this_board[i-4][j+4]==PLAYER1 && this_board[i-5][j+5]==0)
            {
                chongsi[PLAYER1-1][num_chongsi_1][0][0]=i-1;
                chongsi[PLAYER1-1][num_chongsi_1][1][0]=i-2;
                chongsi[PLAYER1-1][num_chongsi_1][2][0]=i-3;
                chongsi[PLAYER1-1][num_chongsi_1][3][0]=i-4;
                chongsi[PLAYER1-1][num_chongsi_1][4][0]=i;
                chongsi[PLAYER1-1][num_chongsi_1][0][1]=j+1;
                chongsi[PLAYER1-1][num_chongsi_1][1][1]=j+2;
                chongsi[PLAYER1-1][num_chongsi_1][2][1]=j+3;
                chongsi[PLAYER1-1][num_chongsi_1][3][1]=j+4;
                chongsi[PLAYER1-1][num_chongsi_1][4][1]=j;
                chongsi[PLAYER1-1][num_chongsi_1][5][0]=i-5;
                chongsi[PLAYER1-1][num_chongsi_1][5][1]=j+5;
                num_chongsi_1++;
            }
            //PLAYER2的冲四
                        if(i==0 && this_board[i][j]==PLAYER2 &&this_board[i+1][j]==PLAYER2 && this_board[i+2][j]==PLAYER2 && this_board[i+3][j]==PLAYER2 && this_board[i+4][j]==0)
            {
                chongsi[PLAYER2-1][num_chongsi_2][0][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][1][0]=i+1;
                chongsi[PLAYER2-1][num_chongsi_2][2][0]=i+2;
                chongsi[PLAYER2-1][num_chongsi_2][3][0]=i+3;
                chongsi[PLAYER2-1][num_chongsi_2][0][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][1][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][2][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][3][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][4][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][5][0]=i+4;
                chongsi[PLAYER2-1][num_chongsi_2][4][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][5][1]=j;
                num_chongsi_2++;
            }
            if(i==row-1 && this_board[i][j]==PLAYER2 &&this_board[i-1][j]==PLAYER2 && this_board[i-2][j]==PLAYER2 && this_board[i-3][j]==PLAYER2 && this_board[i-4][j]==0)
            {
                chongsi[PLAYER2-1][num_chongsi_2][0][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][1][0]=i-1;
                chongsi[PLAYER2-1][num_chongsi_2][2][0]=i-2;
                chongsi[PLAYER2-1][num_chongsi_2][3][0]=i-3;
                chongsi[PLAYER2-1][num_chongsi_2][0][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][1][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][2][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][3][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][4][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][5][0]=i-4;
                chongsi[PLAYER2-1][num_chongsi_2][4][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][5][1]=j;
                num_chongsi_2++;
            }
            if(j==0 && this_board[i][j]==PLAYER2 &&this_board[i][j+1]==PLAYER2 && this_board[i][j+2]==PLAYER2 && this_board[i][j+3]==PLAYER2 && this_board[i][j+4]==0)
            {
                chongsi[PLAYER2-1][num_chongsi_2][0][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][1][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][2][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][3][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][0][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][1][1]=j+1;
                chongsi[PLAYER2-1][num_chongsi_2][2][1]=j+2;
                chongsi[PLAYER2-1][num_chongsi_2][3][1]=j+3;
                chongsi[PLAYER2-1][num_chongsi_2][4][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][5][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][4][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][5][1]=j+4;
                num_chongsi_2++;
            }
            if(j==col-1 && this_board[i][j]==PLAYER2 &&this_board[i][j-1]==PLAYER2 && this_board[i][j-2]==PLAYER2 && this_board[i][j-3]==PLAYER2 && this_board[i][j-4]==0)
            {
                chongsi[PLAYER2-1][num_chongsi_2][0][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][1][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][2][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][3][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][0][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][1][1]=j-1;
                chongsi[PLAYER2-1][num_chongsi_2][2][1]=j-2;
                chongsi[PLAYER2-1][num_chongsi_2][3][1]=j-3;
                chongsi[PLAYER2-1][num_chongsi_2][4][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][5][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][4][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][5][1]=j-4;
                num_chongsi_2++;
            }
            if(j+5<col && this_board[i][j]==PLAYER1 && this_board[i][j+1]==PLAYER2 && this_board[i][j+2]==PLAYER2 && this_board[i][j+3]==PLAYER2 && this_board[i][j+4]==PLAYER2 && this_board[i][j+5]==0)
            {
                chongsi[PLAYER2-1][num_chongsi_2][0][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][1][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][2][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][3][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][4][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][0][1]=j+1;
                chongsi[PLAYER2-1][num_chongsi_2][1][1]=j+2;
                chongsi[PLAYER2-1][num_chongsi_2][2][1]=j+3;
                chongsi[PLAYER2-1][num_chongsi_2][3][1]=j+4;
                chongsi[PLAYER2-1][num_chongsi_2][4][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][5][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][5][1]=j+5;
                num_chongsi_2++;
            }
            if(j-5>=0 && this_board[i][j]==PLAYER1 && this_board[i][j-1]==PLAYER2 && this_board[i][j-2]==PLAYER2 && this_board[i][j-3]==PLAYER2 && this_board[i][j-4]==PLAYER2 && this_board[i][j-5]==0)
            {
                chongsi[PLAYER2-1][num_chongsi_2][0][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][1][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][2][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][3][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][4][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][0][1]=j-1;
                chongsi[PLAYER2-1][num_chongsi_2][1][1]=j-2;
                chongsi[PLAYER2-1][num_chongsi_2][2][1]=j-3;
                chongsi[PLAYER2-1][num_chongsi_2][3][1]=j-4;
                chongsi[PLAYER2-1][num_chongsi_2][4][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][5][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][5][1]=j-5;
                num_chongsi_2++;
            }
            if(i+5<row && this_board[i][j]==PLAYER1 && this_board[i+1][j]==PLAYER2 && this_board[i+2][j]==PLAYER2 && this_board[i+3][j]==PLAYER2 && this_board[i+4][j]==PLAYER2 && this_board[i+5][j]==0)
            {
                chongsi[PLAYER2-1][num_chongsi_2][0][0]=i+1;
                chongsi[PLAYER2-1][num_chongsi_2][1][0]=i+2;
                chongsi[PLAYER2-1][num_chongsi_2][2][0]=i+3;
                chongsi[PLAYER2-1][num_chongsi_2][3][0]=i+4;
                chongsi[PLAYER2-1][num_chongsi_2][4][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][0][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][1][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][2][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][3][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][4][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][5][0]=i+5;
                chongsi[PLAYER2-1][num_chongsi_2][5][1]=j;
                num_chongsi_2++;
            }
            if(i-5>=0 && this_board[i][j]==PLAYER1 && this_board[i-1][j]==PLAYER2 && this_board[i-2][j]==PLAYER2 && this_board[i-3][j]==PLAYER2 && this_board[i-4][j]==PLAYER2 && this_board[i-5][j]==0)
            {
                chongsi[PLAYER2-1][num_chongsi_2][0][0]=i-1;
                chongsi[PLAYER2-1][num_chongsi_2][1][0]=i-2;
                chongsi[PLAYER2-1][num_chongsi_2][2][0]=i-3;
                chongsi[PLAYER2-1][num_chongsi_2][3][0]=i-4;
                chongsi[PLAYER2-1][num_chongsi_2][4][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][0][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][1][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][2][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][3][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][4][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][5][0]=i-5;
                chongsi[PLAYER2-1][num_chongsi_2][5][1]=j;
                num_chongsi_2++;
            }
            if(i+5<row && j+5<col && this_board[i][j]==PLAYER1 && this_board[i+1][j+1]==PLAYER2 && this_board[i+2][j+2]==PLAYER2 && this_board[i+3][j+3]==PLAYER2 && this_board[i+4][j+4]==PLAYER2 && this_board[i+5][j+5]==0)
            {
                chongsi[PLAYER2-1][num_chongsi_2][0][0]=i+1;
                chongsi[PLAYER2-1][num_chongsi_2][1][0]=i+2;
                chongsi[PLAYER2-1][num_chongsi_2][2][0]=i+3;
                chongsi[PLAYER2-1][num_chongsi_2][3][0]=i+4;
                chongsi[PLAYER2-1][num_chongsi_2][4][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][0][1]=j+1;
                chongsi[PLAYER2-1][num_chongsi_2][1][1]=j+2;
                chongsi[PLAYER2-1][num_chongsi_2][2][1]=j+3;
                chongsi[PLAYER2-1][num_chongsi_2][3][1]=j+4;
                chongsi[PLAYER2-1][num_chongsi_2][4][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][5][0]=i+5;
                chongsi[PLAYER2-1][num_chongsi_2][5][1]=j+5;
                num_chongsi_2++;
            }
            if(i+5<row && j-5>=0 && this_board[i][j]==PLAYER1 && this_board[i+1][j-1]==PLAYER2 && this_board[i+2][j-2]==PLAYER2 && this_board[i+3][j-3]==PLAYER2 && this_board[i+4][j-4]==PLAYER2 && this_board[i+5][j-5]==0)
            {
                chongsi[PLAYER2-1][num_chongsi_2][0][0]=i+1;
                chongsi[PLAYER2-1][num_chongsi_2][1][0]=i+2;
                chongsi[PLAYER2-1][num_chongsi_2][2][0]=i+3;
                chongsi[PLAYER2-1][num_chongsi_2][3][0]=i+4;
                chongsi[PLAYER2-1][num_chongsi_2][4][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][0][1]=j-1;
                chongsi[PLAYER2-1][num_chongsi_2][1][1]=j-2;
                chongsi[PLAYER2-1][num_chongsi_2][2][1]=j-3;
                chongsi[PLAYER2-1][num_chongsi_2][3][1]=j-4;
                chongsi[PLAYER2-1][num_chongsi_2][4][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][5][0]=i+5;
                chongsi[PLAYER2-1][num_chongsi_2][5][1]=j-5;
                num_chongsi_2++;
            }
            if(i-5>=0 && j-5>=0 && this_board[i][j]==PLAYER1 && this_board[i-1][j-1]==PLAYER2 && this_board[i-2][j-2]==PLAYER2 && this_board[i-3][j-3]==PLAYER2 && this_board[i-4][j-4]==PLAYER2 && this_board[i-5][j-5]==0)
            {
                chongsi[PLAYER2-1][num_chongsi_2][0][0]=i-1;
                chongsi[PLAYER2-1][num_chongsi_2][1][0]=i-2;
                chongsi[PLAYER2-1][num_chongsi_2][2][0]=i-3;
                chongsi[PLAYER2-1][num_chongsi_2][3][0]=i-4;
                chongsi[PLAYER2-1][num_chongsi_2][4][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][0][1]=j-1;
                chongsi[PLAYER2-1][num_chongsi_2][1][1]=j-2;
                chongsi[PLAYER2-1][num_chongsi_2][2][1]=j-3;
                chongsi[PLAYER2-1][num_chongsi_2][3][1]=j-4;
                chongsi[PLAYER2-1][num_chongsi_2][4][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][5][0]=i-5;
                chongsi[PLAYER2-1][num_chongsi_2][5][1]=j-5;
                num_chongsi_2++;
            }
            if(i-5>=0 && j+5<col && this_board[i][j]==PLAYER1 && this_board[i-1][j+1]==PLAYER2 && this_board[i-2][j+2]==PLAYER2 && this_board[i-3][j+3]==PLAYER2 && this_board[i-4][j+4]==PLAYER2 && this_board[i-5][j+5]==0)
            {
                chongsi[PLAYER2-1][num_chongsi_2][0][0]=i-1;
                chongsi[PLAYER2-1][num_chongsi_2][1][0]=i-2;
                chongsi[PLAYER2-1][num_chongsi_2][2][0]=i-3;
                chongsi[PLAYER2-1][num_chongsi_2][3][0]=i-4;
                chongsi[PLAYER2-1][num_chongsi_2][4][0]=i;
                chongsi[PLAYER2-1][num_chongsi_2][0][1]=j+1;
                chongsi[PLAYER2-1][num_chongsi_2][1][1]=j+2;
                chongsi[PLAYER2-1][num_chongsi_2][2][1]=j+3;
                chongsi[PLAYER2-1][num_chongsi_2][3][1]=j+4;
                chongsi[PLAYER2-1][num_chongsi_2][4][1]=j;
                chongsi[PLAYER2-1][num_chongsi_2][5][0]=i-5;
                chongsi[PLAYER2-1][num_chongsi_2][5][1]=j+5;
                num_chongsi_2++;
            }

        }
    }
}

void find_tiaosi(int this_board[][COL],const int row,const int col)
{
    //十二个if*2
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //PLAYER1的跳四
            if(j+4<col && this_board[i][j]==PLAYER1 && this_board[i][j+1]==0 && this_board[i][j+2]==PLAYER1 && this_board[i][j+3]==PLAYER1 && this_board[i][j+4]==PLAYER1)
            {
                if(j-1>=0 && j+5<col && this_board[i][j-1]==0 && this_board[i][j+5]==0)
                {
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j+1;
                    num_tiaosi_1++;
                }
                else 
                {
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][1]=j+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][1]=j+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][1]=j+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][1]=j+1;
                    num_tiaochongsi_1++;
                    if(j-1>=0 && this_board[i][j-1]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][0]=i;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][1]=j-1;
                    }
                    if(j+5<col && this_board[i][j+5]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][0]=i;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][1]=j+5;
                    }
                }
            }
            if(j+4<col && this_board[i][j]==PLAYER1 && this_board[i][j+1]==PLAYER1 && this_board[i][j+2]==0 && this_board[i][j+3]==PLAYER1 && this_board[i][j+4]==PLAYER1)
            {
                if(j-1>=0 && j+5<col && this_board[i][j-1]==0 && this_board[i][j+5]==0)
                {
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j+2;
                    num_tiaosi_1++;
                }
                else 
                {
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][1]=j+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][1]=j+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][1]=j+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][1]=j+2;
                    num_tiaochongsi_1++;
                    if(j-1>=0 && this_board[i][j-1]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][0]=i;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][1]=j-1;
                    }
                    if(j+5<col && this_board[i][j+5]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][0]=i;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][1]=j+5;
                    }
                }
            }
            if(j+4<col && this_board[i][j]==PLAYER1 && this_board[i][j+1]==PLAYER1 && this_board[i][j+2]==PLAYER1 && this_board[i][j+3]==0 && this_board[i][j+4]==PLAYER1)
            {
                if(j-1>=0 && j+5<col && this_board[i][j-1]==0 && this_board[i][j+5]==0)
                {
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j+3;
                    num_tiaosi_1++;
                }
                else 
                {
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][1]=j+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][1]=j+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][1]=j+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][1]=j+3;
                    num_tiaochongsi_1++;
                    if(j-1>=0 && this_board[i][j-1]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][0]=i;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][1]=j-1;
                    }
                    if(j+5<col && this_board[i][j+5]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][0]=i;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][1]=j+5;
                    }
                }
            }
            if(i+4<row && this_board[i][j]==PLAYER1 && this_board[i+1][j]==0 && this_board[i+2][j]==PLAYER1 && this_board[i+3][j]==PLAYER1 && this_board[i+4][j]==PLAYER1)
            {
                if(i-1>=0 && i+5<row && this_board[i-1][j]==0 && this_board[i+5][j]==0)
                {
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j;
                    num_tiaosi_1++;
                }
                else
                {
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][0]=i+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][0]=i+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][0]=i+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][0]=i+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][1]=j;
                    num_tiaochongsi_1++;
                    if(i-1>=0 && this_board[i-1][j]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][0]=i-1;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][1]=j;
                    }
                    if(i+5<row && this_board[i+5][j]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][0]=i+5;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][1]=j;
                    }
                }
            }
            if(i+4<row && this_board[i][j]==PLAYER1 && this_board[i+1][j]==PLAYER1 && this_board[i+2][j]==0 && this_board[i+3][j]==PLAYER1 && this_board[i+4][j]==PLAYER1)
            {
                tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i+1;
                tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i+3;
                tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i+4;
                tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i+2;
                tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j;
                tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j;
                tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j;
                tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j;
                num_tiaosi_1++;
                if(i-1>=0 && i+5<row && this_board[i-1][j]==0 && this_board[i+5][j]==0)
                {
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j;
                    num_tiaosi_1++;
                }
                else
                {
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][0]=i+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][0]=i+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][0]=i+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][0]=i+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][1]=j;
                    num_tiaochongsi_1++;
                    if(i-1>=0 && this_board[i-1][j]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][0]=i-1;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][1]=j;
                    }
                    if(i+5<row && this_board[i+5][j]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][0]=i+5;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][1]=j;
                    }
                }
            }
            if(i+4<row && this_board[i][j]==PLAYER1 && this_board[i+1][j]==PLAYER1 && this_board[i+2][j]==PLAYER1 && this_board[i+3][j]==0 && this_board[i+4][j]==PLAYER1)
            {
                if(i-1>=0 && i+5<row && this_board[i-1][j]==0 && this_board[i+5][j]==0)
                {
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j;
                    num_tiaosi_1++;
                }
                else
                {
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][0]=i+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][0]=i+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][0]=i+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][0]=i+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][1]=j;
                    num_tiaochongsi_1++;
                    if(i-1>=0 && this_board[i-1][j]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][0]=i-1;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][1]=j;
                    }
                    if(i+5<row && this_board[i+5][j]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][0]=i+5;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][1]=j;
                    }
                }
            }
            if(i+4<row && j+4<col && this_board[i][j]==PLAYER1 && this_board[i+1][j+1]==0 && this_board[i+2][j+2]==PLAYER1 && this_board[i+3][j+3]==PLAYER1 && this_board[i+4][j+4]==PLAYER1)
            {
                if(i-1>=0 && j-1>=0 && i+5<row && j+5<col && this_board[i-1][j-1]==0 && this_board[i+5][j+5]==0)
                {
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j+1;
                    num_tiaosi_1++;
                }
                else
                {
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][0]=i+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][0]=i+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][0]=i+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][0]=i+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][1]=j+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][1]=j+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][1]=j+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][1]=j+1;
                    num_tiaochongsi_1++;
                    if(i-1>=0 && j-1>=0 && this_board[i-1][j-1]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][0]=i-1;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][1]=j-1;
                    }
                    if(i+5<row && j+5<col && this_board[i+5][j+5]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][0]=i+5;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][1]=j+5;
                    }
                }
            }
            if(i+4<row && j+4<col && this_board[i][j]==PLAYER1 && this_board[i+1][j+1]==PLAYER1 && this_board[i+2][j+2]==0 && this_board[i+3][j+3]==PLAYER1 && this_board[i+4][j+4]==PLAYER1)
            {
                if(i-1>=0 && j-1>=0 && i+5<row && j+5<col && this_board[i-1][j-1]==0 && this_board[i+5][j+5]==0)
                {
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j+2;
                    num_tiaosi_1++;
                }
                else
                {
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][0]=i+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][0]=i+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][0]=i+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][0]=i+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][1]=j+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][1]=j+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][1]=j+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][1]=j+2;
                    num_tiaochongsi_1++;
                    if(i-1>=0 && j-1>=0 && this_board[i-1][j-1]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][0]=i-1;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][1]=j-1;
                    }
                    if(i+5<row && j+5<col && this_board[i+5][j+5]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][0]=i+5;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][1]=j+5;
                    }
                }
            }
            if(i+4<row && j+4<col && this_board[i][j]==PLAYER1 && this_board[i+1][j+1]==PLAYER1 && this_board[i+2][j+2]==PLAYER1 && this_board[i+3][j+3]==0 && this_board[i+4][j+4]==PLAYER1)
            {
                if(i-1>=0 && j-1>=0 && i+5<row && j+5<col && this_board[i-1][j-1]==0 && this_board[i+5][j+5]==0)
                {
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j+3;
                    num_tiaosi_1++;
                }
                else
                {
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][0]=i+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][0]=i+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][0]=i+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][0]=i+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][1]=j+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][1]=j+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][1]=j+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][1]=j+3;
                    num_tiaochongsi_1++;
                    if(i-1>=0 && j-1>=0 && this_board[i-1][j-1]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][0]=i-1;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][1]=j-1;
                    }
                    if(i+5<row && j+5<col && this_board[i+5][j+5]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][0]=i+5;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][1]=j+5;
                    }
                }
            }
            if(i+4<row && j-4>=0 && this_board[i][j]==PLAYER1 && this_board[i+1][j-1]==0 && this_board[i+2][j-2]==PLAYER1 && this_board[i+3][j-3]==PLAYER1 && this_board[i+4][j-4]==PLAYER1)
            {
                if(i-1>=0 && j+5<col && i+5<row && j-1>=0 && this_board[i-1][j+5]==0 && this_board[i+5][j-1]==0)
                {
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j-2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j-3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j-4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j-1;
                    num_tiaosi_1++;
                }
                else
                {
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][0]=i+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][0]=i+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][0]=i+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][0]=i+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][1]=j-2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][1]=j-3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][1]=j-4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][1]=j-1;
                    num_tiaochongsi_1++;
                    if(i-1>=0 && j+5<col && this_board[i-1][j+5]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][0]=i-1;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][1]=j+5;
                    }
                    if(i+5<row && j-1>=0 && this_board[i+5][j-1]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][0]=i+5;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][1]=j-1;
                    }
                }
            }
            if(i+4<row && j-4>=0 && this_board[i][j]==PLAYER1 && this_board[i+1][j-1]==PLAYER1 && this_board[i+2][j-2]==0 && this_board[i+3][j-3]==PLAYER1 && this_board[i+4][j-4]==PLAYER1)
            {
                if(i-1>=0 && j+5<col && i+5<row && j-1>=0 && this_board[i-1][j+5]==0 && this_board[i+5][j-1]==0)
                {
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j-1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j-3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j-4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j-2;
                    num_tiaosi_1++;
                }
                else
                {
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][0]=i+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][0]=i+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][0]=i+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][0]=i+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][1]=j-1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][1]=j-3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][1]=j-4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][1]=j-2;
                    num_tiaochongsi_1++;
                    if(i-1>=0 && j+5<col && this_board[i-1][j+5]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][0]=i-1;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][1]=j+5;
                    }
                    if(i+5<row && j-1>=0 && this_board[i+5][j-1]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][0]=i+5;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][1]=j-1;
                    }
                }
            }
            if(i+4<row && j-4>=0 && this_board[i][j]==PLAYER1 && this_board[i+1][j-1]==PLAYER1 && this_board[i+2][j-2]==PLAYER1 && this_board[i+3][j-3]==0 && this_board[i+4][j-4]==PLAYER1)
            {
                if(i-1>=0 && j+5<col && i+5<row && j-1>=0 && this_board[i-1][j+5]==0 && this_board[i+5][j-1]==0)
                {
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][0]=i;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][0]=i+1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][0]=i+2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][0]=i+4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][0]=i+3;
                    tiaosi[PLAYER1-1][num_tiaosi_1][0][1]=j;
                    tiaosi[PLAYER1-1][num_tiaosi_1][1][1]=j-1;
                    tiaosi[PLAYER1-1][num_tiaosi_1][2][1]=j-2;
                    tiaosi[PLAYER1-1][num_tiaosi_1][3][1]=j-4;
                    tiaosi[PLAYER1-1][num_tiaosi_1][4][1]=j-3;
                    num_tiaosi_1++;
                }
                else
                {
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][0]=i;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][0]=i+1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][0]=i+2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][0]=i+4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][0]=i+3;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][0][1]=j;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][1][1]=j-1;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][2][1]=j-2;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][3][1]=j-4;
                    tiaochongsi[PLAYER1-1][num_tiaochongsi_1][4][1]=j-3;
                    num_tiaochongsi_1++;
                    if(i-1>=0 && j+5<col && this_board[i-1][j+5]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][0]=i-1;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][5][1]=j+5;
                    }
                    if(i+5<row && j-1>=0 && this_board[i+5][j-1]==0)
                    {
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][0]=i+5;
                        tiaochongsi[PLAYER1-1][num_tiaochongsi_1][6][1]=j-1;
                    }
                }
            }
            //PLAYER2的跳四
            if(j+4<col && this_board[i][j]==PLAYER2 && this_board[i][j+1]==0 && this_board[i][j+2]==PLAYER2 && this_board[i][j+3]==PLAYER2 && this_board[i][j+4]==PLAYER2)
            {
                if(j-1>=0 && j+5<col && this_board[i][j-1]==0 && this_board[i][j+5]==0)
                {
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j+1;
                    num_tiaosi_2++;
                }
                else 
                {
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][1]=j+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][1]=j+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][1]=j+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][1]=j+1;
                    num_tiaochongsi_2++;
                    if(j-1>=0 && this_board[i][j-1]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][0]=i;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][1]=j-1;
                    }
                    if(j+5<col && this_board[i][j+5]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][0]=i;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][1]=j+5;
                    }
                }
            }
            if(j+4<col && this_board[i][j]==PLAYER2 && this_board[i][j+1]==PLAYER2 && this_board[i][j+2]==0 && this_board[i][j+3]==PLAYER2 && this_board[i][j+4]==PLAYER2)
            {
                if(j-1>=0 && j+5<col && this_board[i][j-1]==0 && this_board[i][j+5]==0)
                {
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j+2;
                    num_tiaosi_2++;
                }
                else 
                {
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][1]=j+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][1]=j+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][1]=j+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][1]=j+2;
                    num_tiaochongsi_2++;
                    if(j-1>=0 && this_board[i][j-1]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][0]=i;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][1]=j-1;
                    }
                    if(j+5<col && this_board[i][j+5]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][0]=i;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][1]=j+5;
                    }
                }
            }
            if(j+4<col && this_board[i][j]==PLAYER2 && this_board[i][j+1]==PLAYER2 && this_board[i][j+2]==PLAYER2 && this_board[i][j+3]==0 && this_board[i][j+4]==PLAYER2)
            {
                if(j-1>=0 && j+5<col && this_board[i][j-1]==0 && this_board[i][j+5]==0)
                {
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j+3;
                    num_tiaosi_2++;
                }
                else 
                {
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][1]=j+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][1]=j+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][1]=j+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][1]=j+3;
                    num_tiaochongsi_2++;
                    if(j-1>=0 && this_board[i][j-1]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][0]=i;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][1]=j-1;
                    }
                    if(j+5<col && this_board[i][j+5]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][0]=i;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][1]=j+5;
                    }
                }
            }
            if(i+4<row && this_board[i][j]==PLAYER2 && this_board[i+1][j]==0 && this_board[i+2][j]==PLAYER2 && this_board[i+3][j]==PLAYER2 && this_board[i+4][j]==PLAYER2)
            {
                if(i-1>=0 && i+5<row && this_board[i-1][j]==0 && this_board[i+5][j]==0)
                {
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j;
                    num_tiaosi_2++;
                }
                else
                {
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][0]=i+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][0]=i+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][0]=i+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][0]=i+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][1]=j;
                    num_tiaochongsi_2++;
                    if(i-1>=0 && this_board[i-1][j]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][0]=i-1;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][1]=j;
                    }
                    if(i+5<row && this_board[i+5][j]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][0]=i+5;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][1]=j;
                    }
                }
            }
            if(i+4<row && this_board[i][j]==PLAYER2 && this_board[i+1][j]==PLAYER2 && this_board[i+2][j]==0 && this_board[i+3][j]==PLAYER2 && this_board[i+4][j]==PLAYER2)
            {
                tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i+1;
                tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i+3;
                tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i+4;
                tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i+2;
                tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j;
                tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j;
                tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j;
                tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j;
                num_tiaosi_2++;
                if(i-1>=0 && i+5<row && this_board[i-1][j]==0 && this_board[i+5][j]==0)
                {
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j;
                    num_tiaosi_2++;
                }
                else
                {
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][0]=i+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][0]=i+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][0]=i+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][0]=i+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][1]=j;
                    num_tiaochongsi_2++;
                    if(i-1>=0 && this_board[i-1][j]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][0]=i-1;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][1]=j;
                    }
                    if(i+5<row && this_board[i+5][j]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][0]=i+5;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][1]=j;
                    }
                }
            }
            if(i+4<row && this_board[i][j]==PLAYER2 && this_board[i+1][j]==PLAYER2 && this_board[i+2][j]==PLAYER2 && this_board[i+3][j]==0 && this_board[i+4][j]==PLAYER2)
            {
                if(i-1>=0 && i+5<row && this_board[i-1][j]==0 && this_board[i+5][j]==0)
                {
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j;
                    num_tiaosi_2++;
                }
                else
                {
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][0]=i+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][0]=i+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][0]=i+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][0]=i+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][1]=j;
                    num_tiaochongsi_2++;
                    if(i-1>=0 && this_board[i-1][j]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][0]=i-1;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][1]=j;
                    }
                    if(i+5<row && this_board[i+5][j]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][0]=i+5;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][1]=j;
                    }
                }
            }
            if(i+4<row && j+4<col && this_board[i][j]==PLAYER2 && this_board[i+1][j+1]==0 && this_board[i+2][j+2]==PLAYER2 && this_board[i+3][j+3]==PLAYER2 && this_board[i+4][j+4]==PLAYER2)
            {
                if(i-1>=0 && j-1>=0 && i+5<row && j+5<col && this_board[i-1][j-1]==0 && this_board[i+5][j+5]==0)
                {
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j+1;
                    num_tiaosi_2++;
                }
                else
                {
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][0]=i+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][0]=i+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][0]=i+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][0]=i+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][1]=j+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][1]=j+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][1]=j+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][1]=j+1;
                    num_tiaochongsi_2++;
                    if(i-1>=0 && j-1>=0 && this_board[i-1][j-1]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][0]=i-1;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][1]=j-1;
                    }
                    if(i+5<row && j+5<col && this_board[i+5][j+5]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][0]=i+5;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][1]=j+5;
                    }
                }
            }
            if(i+4<row && j+4<col && this_board[i][j]==PLAYER2 && this_board[i+1][j+1]==PLAYER2 && this_board[i+2][j+2]==0 && this_board[i+3][j+3]==PLAYER2 && this_board[i+4][j+4]==PLAYER2)
            {
                if(i-1>=0 && j-1>=0 && i+5<row && j+5<col && this_board[i-1][j-1]==0 && this_board[i+5][j+5]==0)
                {
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j+2;
                    num_tiaosi_2++;
                }
                else
                {
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][0]=i+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][0]=i+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][0]=i+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][0]=i+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][1]=j+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][1]=j+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][1]=j+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][1]=j+2;
                    num_tiaochongsi_2++;
                    if(i-1>=0 && j-1>=0 && this_board[i-1][j-1]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][0]=i-1;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][1]=j-1;
                    }
                    if(i+5<row && j+5<col && this_board[i+5][j+5]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][0]=i+5;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][1]=j+5;
                    }
                }
            }
            if(i+4<row && j+4<col && this_board[i][j]==PLAYER2 && this_board[i+1][j+1]==PLAYER2 && this_board[i+2][j+2]==PLAYER2 && this_board[i+3][j+3]==0 && this_board[i+4][j+4]==PLAYER2)
            {
                if(i-1>=0 && j-1>=0 && i+5<row && j+5<col && this_board[i-1][j-1]==0 && this_board[i+5][j+5]==0)
                {
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j+3;
                    num_tiaosi_2++;
                }
                else
                {
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][0]=i+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][0]=i+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][0]=i+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][0]=i+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][1]=j+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][1]=j+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][1]=j+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][1]=j+3;
                    num_tiaochongsi_2++;
                    if(i-1>=0 && j-1>=0 && this_board[i-1][j-1]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][0]=i-1;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][1]=j-1;
                    }
                    if(i+5<row && j+5<col && this_board[i+5][j+5]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][0]=i+5;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][1]=j+5;
                    }
                }
            }
            if(i+4<row && j-4>=0 && this_board[i][j]==PLAYER2 && this_board[i+1][j-1]==0 && this_board[i+2][j-2]==PLAYER2 && this_board[i+3][j-3]==PLAYER2 && this_board[i+4][j-4]==PLAYER2)
            {
                if(i-1>=0 && j+5<col && i+5<row && j-1>=0 && this_board[i-1][j+5]==0 && this_board[i+5][j-1]==0)
                {
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j-2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j-3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j-4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j-1;
                    num_tiaosi_2++;
                }
                else
                {
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][0]=i+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][0]=i+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][0]=i+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][0]=i+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][1]=j-2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][1]=j-3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][1]=j-4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][1]=j-1;
                    num_tiaochongsi_2++;
                    if(i-1>=0 && j+5<col && this_board[i-1][j+5]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][0]=i-1;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][1]=j+5;
                    }
                    if(i+5<row && j-1>=0 && this_board[i+5][j-1]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][0]=i+5;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][1]=j-1;
                    }
                }
            }
            if(i+4<row && j-4>=0 && this_board[i][j]==PLAYER2 && this_board[i+1][j-1]==PLAYER2 && this_board[i+2][j-2]==0 && this_board[i+3][j-3]==PLAYER2 && this_board[i+4][j-4]==PLAYER2)
            {
                if(i-1>=0 && j+5<col && i+5<row && j-1>=0 && this_board[i-1][j+5]==0 && this_board[i+5][j-1]==0)
                {
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j-1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j-3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j-4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j-2;
                    num_tiaosi_2++;
                }
                else
                {
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][0]=i+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][0]=i+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][0]=i+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][0]=i+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][1]=j-1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][1]=j-3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][1]=j-4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][1]=j-2;
                    num_tiaochongsi_2++;
                    if(i-1>=0 && j+5<col && this_board[i-1][j+5]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][0]=i-1;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][1]=j+5;
                    }
                    if(i+5<row && j-1>=0 && this_board[i+5][j-1]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][0]=i+5;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][1]=j-1;
                    }
                }
            }
            if(i+4<row && j-4>=0 && this_board[i][j]==PLAYER2 && this_board[i+1][j-1]==PLAYER2 && this_board[i+2][j-2]==PLAYER2 && this_board[i+3][j-3]==0 && this_board[i+4][j-4]==PLAYER2)
            {
                if(i-1>=0 && j+5<col && i+5<row && j-1>=0 && this_board[i-1][j+5]==0 && this_board[i+5][j-1]==0)
                {
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][0]=i;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][0]=i+1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][0]=i+2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][0]=i+4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][0]=i+3;
                    tiaosi[PLAYER2-1][num_tiaosi_2][0][1]=j;
                    tiaosi[PLAYER2-1][num_tiaosi_2][1][1]=j-1;
                    tiaosi[PLAYER2-1][num_tiaosi_2][2][1]=j-2;
                    tiaosi[PLAYER2-1][num_tiaosi_2][3][1]=j-4;
                    tiaosi[PLAYER2-1][num_tiaosi_2][4][1]=j-3;
                    num_tiaosi_2++;
                }
                else
                {
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][0]=i;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][0]=i+1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][0]=i+2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][0]=i+4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][0]=i+3;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][0][1]=j;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][1][1]=j-1;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][2][1]=j-2;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][3][1]=j-4;
                    tiaochongsi[PLAYER2-1][num_tiaochongsi_2][4][1]=j-3;
                    num_tiaochongsi_2++;
                    if(i-1>=0 && j+5<col && this_board[i-1][j+5]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][0]=i-1;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][5][1]=j+5;
                    }
                    if(i+5<row && j-1>=0 && this_board[i+5][j-1]==0)
                    {
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][0]=i+5;
                        tiaochongsi[PLAYER2-1][num_tiaochongsi_2][6][1]=j-1;
                    }
                }
            }


        }
    }
}

void find_huoer(int this_board[][COL],const int row,const int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //PLAYER1的活二
            if(j+3<col && this_board[i][j]==0 && this_board[i][j+1]==PLAYER1 && this_board[i][j+2]==PLAYER1 && this_board[i][j+3]==0 &&((j>0 && this_board[i][j-1]==0)||(j+4<col && this_board[i][j+4]==0)))
            {
                huoer[PLAYER1-1][num_huoer_1][0][0]=i;
                huoer[PLAYER1-1][num_huoer_1][1][0]=i;
                huoer[PLAYER1-1][num_huoer_1][0][1]=j+1;
                huoer[PLAYER1-1][num_huoer_1][1][1]=j+2;
                num_huoer_1++;
            }
            if(i+3<row && this_board[i][j]==0 && this_board[i+1][j]==PLAYER1 && this_board[i+2][j]==PLAYER1 && this_board[i+3][j]==0 &&((i>0 && this_board[i-1][j]==0)||(i+4<row && this_board[i+4][j]==0)))
            {
                huoer[PLAYER1-1][num_huoer_1][0][0]=i+1;
                huoer[PLAYER1-1][num_huoer_1][1][0]=i+2;
                huoer[PLAYER1-1][num_huoer_1][0][1]=j;
                huoer[PLAYER1-1][num_huoer_1][1][1]=j;
                num_huoer_1++;
            }
            if(i+3<row && j+3<col && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER1 && this_board[i+2][j+2]==PLAYER1 && this_board[i+3][j+3]==0 &&((i>0 && j>0 && this_board[i-1][j-1]==0)||(i+4<row && j+4<col && this_board[i+4][j+4]==0)))
            {
                huoer[PLAYER1-1][num_huoer_1][0][0]=i+1;
                huoer[PLAYER1-1][num_huoer_1][1][0]=i+2;
                huoer[PLAYER1-1][num_huoer_1][0][1]=j+1;
                huoer[PLAYER1-1][num_huoer_1][1][1]=j+2;
                num_huoer_1++;
            }
            if(i+3<row && j-3>=0 && this_board[i][j]==0 && this_board[i+1][j-1]==PLAYER1 && this_board[i+2][j-2]==PLAYER1 && this_board[i+3][j-3]==0 &&((i>0 && j+4<col && this_board[i-1][j+4]==0)||(i+4<row && j>0 && this_board[i+4][j-1]==0)))
            {
                huoer[PLAYER1-1][num_huoer_1][0][0]=i+1;
                huoer[PLAYER1-1][num_huoer_1][1][0]=i+2;
                huoer[PLAYER1-1][num_huoer_1][0][1]=j-1;
                huoer[PLAYER1-1][num_huoer_1][1][1]=j-2;
                num_huoer_1++;
            }
            //PLAYER2的活二
            if(j+3<col && this_board[i][j]==0 && this_board[i][j+1]==PLAYER2 && this_board[i][j+2]==PLAYER2 && this_board[i][j+3]==0 &&((j>0 && this_board[i][j-1]==0)||(j+4<col && this_board[i][j+4]==0)))
            {
                huoer[PLAYER2-1][num_huoer_2][0][0]=i;
                huoer[PLAYER2-1][num_huoer_2][1][0]=i;
                huoer[PLAYER2-1][num_huoer_2][0][1]=j+1;
                huoer[PLAYER2-1][num_huoer_2][1][1]=j+2;
                num_huoer_2++;
            }
            if(i+3<row && this_board[i][j]==0 && this_board[i+1][j]==PLAYER2 && this_board[i+2][j]==PLAYER2 && this_board[i+3][j]==0 &&((i>0 && this_board[i-1][j]==0)||(i+4<row && this_board[i+4][j]==0)))
            {
                huoer[PLAYER2-1][num_huoer_2][0][0]=i+1;
                huoer[PLAYER2-1][num_huoer_2][1][0]=i+2;
                huoer[PLAYER2-1][num_huoer_2][0][1]=j;
                huoer[PLAYER2-1][num_huoer_2][1][1]=j;
                num_huoer_2++;
            }
            if(i+3<row && j+3<col && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER2 && this_board[i+2][j+2]==PLAYER2 && this_board[i+3][j+3]==0 &&((i>0 && j>0 && this_board[i-1][j-1]==0)||(i+4<row && j+4<col && this_board[i+4][j+4]==0)))
            {
                huoer[PLAYER2-1][num_huoer_2][0][0]=i+1;
                huoer[PLAYER2-1][num_huoer_2][1][0]=i+2;
                huoer[PLAYER2-1][num_huoer_2][0][1]=j+1;
                huoer[PLAYER2-1][num_huoer_2][1][1]=j+2;
                num_huoer_2++;
            }
            if(i+3<row && j-3>=0 && this_board[i][j]==0 && this_board[i+1][j-1]==PLAYER2 && this_board[i+2][j-2]==PLAYER2 && this_board[i+3][j-3]==0 &&((i>0 && j+4<col && this_board[i-1][j+4]==0)||(i+4<row && j>0 && this_board[i+4][j-1]==0)))
            {
                huoer[PLAYER2-1][num_huoer_2][0][0]=i+1;
                huoer[PLAYER2-1][num_huoer_2][1][0]=i+2;
                huoer[PLAYER2-1][num_huoer_2][0][1]=j-1;
                huoer[PLAYER2-1][num_huoer_2][1][1]=j-2;
                num_huoer_2++;
            }

        }
    }
}

void find_tiaohuoer(int this_board[][COL],const int row,const int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //PLAYER1的跳二
            if(j+4<col && this_board[i][j]==0 && this_board[i][j+1]==PLAYER1 && this_board[i][j+2]==0 && this_board[i][j+3]==PLAYER1 && this_board[i][j+4]==0)
            {
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][0][0]=i;
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][1][0]=i;
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][0][1]=j+1;
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][1][1]=j+3;
                num_tiaohuoer_1++;
            }
            if(i+4<row && this_board[i][j]==0 && this_board[i+1][j]==PLAYER1 && this_board[i+2][j]==0 && this_board[i+3][j]==PLAYER1 && this_board[i+4][j]==0)
            {
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][0][0]=i+1;
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][1][0]=i+3;
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][0][1]=j;
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][1][1]=j;
                num_tiaohuoer_1++;
            }
            if(i+4<row && j+4<col && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER1 && this_board[i+2][j+2]==0 && this_board[i+3][j+3]==PLAYER1 && this_board[i+4][j+4]==0)
            {
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][0][0]=i+1;
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][1][0]=i+3;
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][0][1]=j+1;
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][1][1]=j+3;
                num_tiaohuoer_1++;
            }
            if(i+4<row && j-4>=0 && this_board[i][j]==0 && this_board[i+1][j-1]==PLAYER1 && this_board[i+2][j-2]==0 && this_board[i+3][j-3]==PLAYER1 && this_board[i+4][j-4]==0)
            {
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][0][0]=i+1;
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][1][0]=i+3;
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][0][1]=j-1;
                tiaohuoer[PLAYER1-1][num_tiaohuoer_1][1][1]=j-3;
                num_tiaohuoer_1++;
            }
            //PLAYER2的跳二
            if(j+4<col && this_board[i][j]==0 && this_board[i][j+1]==PLAYER2 && this_board[i][j+2]==0 && this_board[i][j+3]==PLAYER2 && this_board[i][j+4]==0)
            {
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][0][0]=i;
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][1][0]=i;
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][0][1]=j+1;
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][1][1]=j+3;
                num_tiaohuoer_2++;
            }
            if(i+4<row && this_board[i][j]==0 && this_board[i+1][j]==PLAYER2 && this_board[i+2][j]==0 && this_board[i+3][j]==PLAYER2 && this_board[i+4][j]==0)
            {
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][0][0]=i+1;
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][1][0]=i+3;
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][0][1]=j;
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][1][1]=j;
                num_tiaohuoer_2++;
            }
            if(i+4<row && j+4<col && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER2 && this_board[i+2][j+2]==0 && this_board[i+3][j+3]==PLAYER2 && this_board[i+4][j+4]==0)
            {
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][0][0]=i+1;
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][1][0]=i+3;
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][0][1]=j+1;
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][1][1]=j+3;
                num_tiaohuoer_2++;
            }
            if(i+4<row && j-4>=0 && this_board[i][j]==0 && this_board[i+1][j-1]==PLAYER2 && this_board[i+2][j-2]==0 && this_board[i+3][j-3]==PLAYER2 && this_board[i+4][j-4]==0)
            {
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][0][0]=i+1;
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][1][0]=i+3;
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][0][1]=j-1;
                tiaohuoer[PLAYER2-1][num_tiaohuoer_2][1][1]=j-3;
                num_tiaohuoer_2++;
            }
        }
    }
}

void find_fakehuosan(int this_board[][COL],const int row,const int col)//找假活三
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //PLAYER1的活三
            if(j+4<col && this_board[i][j]==0 && this_board [i][j+1]==PLAYER1 && this_board[i][j+2]==PLAYER1 && this_board[i][j+3]==PLAYER1 && this_board[i][j+4]==0)
            {   
                fakehuosan[PLAYER1-1][num_fakehuosan_1][0][0]=i;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][1][0]=i;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][2][0]=i;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][0][1]=j+1;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][1][1]=j+2;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][2][1]=j+3;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][3][0]=i;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][3][1]=j;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][4][0]=i;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][4][1]=j+4;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][5][0]=i;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][5][1]=j-1;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][6][0]=i;
                fakehuosan[PLAYER1-1][num_fakehuosan_1][6][1]=j+5;
                num_fakehuosan_1++;
            }
            if(i+4<row && this_board[i][j]==0 && this_board[i+1][j]==PLAYER1 && this_board[i+2][j]==PLAYER1 && this_board[i+3][j]==PLAYER1 && this_board[i+4][j]==0)
            {
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][0][0]=i+1;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][1][0]=i+2;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][2][0]=i+3;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][0][1]=j;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][1][1]=j;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][2][1]=j;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][3][0]=i;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][3][1]=j;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][4][0]=i+4;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][4][1]=j;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][5][0]=i-1;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][5][1]=j;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][6][0]=i+5;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][6][1]=j;
                    num_fakehuosan_1++;
            }
            if(i+4<row && j+4<col && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER1 && 
            this_board[i+2][j+2]==PLAYER1 && this_board[i+3][j+3]==PLAYER1 && this_board[i+4][j+4]==0)
            {
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][0][0]=i+1;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][1][0]=i+2;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][2][0]=i+3;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][0][1]=j+1;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][1][1]=j+2;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][2][1]=j+3;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][3][0]=i;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][3][1]=j;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][4][0]=i+4;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][4][1]=j+4;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][5][0]=i-1;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][5][1]=j-1;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][6][0]=i+5;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][6][1]=j+5;
                    num_fakehuosan_1++;
            }
            if(i-4>=0 && j+4<col && this_board[i][j]==0 && this_board[i-1][j+1]==PLAYER1 && 
            this_board[i-2][j+2]==PLAYER1 && this_board[i-3][j+3]==PLAYER1 && this_board[i-4][j+4]==0 )
            {
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][0][0]=i-1;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][1][0]=i-2;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][2][0]=i-3;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][0][1]=j+1;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][1][1]=j+2;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][2][1]=j+3;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][3][0]=i;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][3][1]=j;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][4][0]=i-4;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][4][1]=j+4;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][5][0]=i+1;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][5][1]=j-1;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][6][0]=i-5;
                    fakehuosan[PLAYER1-1][num_fakehuosan_1][6][1]=j+5;
                    num_fakehuosan_1++;

            }
            //PLAYER2的活三
            if(j+4<col && this_board[i][j]==0 && this_board [i][j+1]==PLAYER2 && this_board[i][j+2]==PLAYER2 && this_board[i][j+3]==PLAYER2 && this_board[i][j+4]==0)
            {
                fakehuosan[PLAYER2-1][num_fakehuosan_2][0][0]=i;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][1][0]=i;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][2][0]=i;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][0][1]=j+1;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][1][1]=j+2;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][2][1]=j+3;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][3][0]=i;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][3][1]=j;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][4][0]=i;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][4][1]=j+4;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][5][0]=i;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][5][1]=j-1;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][6][0]=i;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][6][1]=j+5;
                num_fakehuosan_2++;
            }
            if(i+4<row && this_board[i][j]==0 && this_board[i+1][j]==PLAYER2 && this_board[i+2][j]==PLAYER2 && this_board[i+3][j]==PLAYER2 && this_board[i+4][j]==0)
            {
                fakehuosan[PLAYER2-1][num_fakehuosan_2][0][0]=i+1;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][1][0]=i+2;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][2][0]=i+3;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][0][1]=j;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][1][1]=j;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][2][1]=j;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][3][0]=i;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][3][1]=j;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][4][0]=i+4;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][4][1]=j;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][5][0]=i-1;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][5][1]=j;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][6][0]=i+5;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][6][1]=j;
                num_fakehuosan_2++;
            }
            if(i+4<row && j+4<col && this_board[i][j]==0 && this_board[i+1][j+1]==PLAYER2 && 
            this_board[i+2][j+2]==PLAYER2 && this_board[i+3][j+3]==PLAYER2 && this_board[i+4][j+4]==0)
            {
                fakehuosan[PLAYER2-1][num_fakehuosan_2][0][0]=i+1;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][1][0]=i+2;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][2][0]=i+3;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][0][1]=j+1;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][1][1]=j+2;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][2][1]=j+3;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][3][0]=i;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][3][1]=j;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][4][0]=i+4;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][4][1]=j+4;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][5][0]=i-1;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][5][1]=j-1;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][6][0]=i+5;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][6][1]=j+5;
                num_fakehuosan_2++;
            }
            if(i-4>=0 && j+4<col && this_board[i][j]==0 && this_board[i-1][j+1]==PLAYER2 && 
            this_board[i-2][j+2]==PLAYER2 && this_board[i-3][j+3]==PLAYER2 && this_board[i-4][j+4]==0)
            {
                fakehuosan[PLAYER2-1][num_fakehuosan_2][0][0]=i-1;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][1][0]=i-2;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][2][0]=i-3;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][0][1]=j+1;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][1][1]=j+2;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][2][1]=j+3;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][3][0]=i;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][3][1]=j;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][4][0]=i-4;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][4][1]=j+4;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][5][0]=i+1;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][5][1]=j-1;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][6][0]=i-5;
                fakehuosan[PLAYER2-1][num_fakehuosan_2][6][1]=j+5;
                num_fakehuosan_2++;
            }

        
        }
    }
}
