#include "myhead.h"
//大猩猩人机
void add_domain(bool domain[][COL],int x,int y,int len)//有效区域扩展，有效区域为棋子周围+-2的区域，出了这个区域的落子一般没意义
{
    for(int i=0;i<=len;i++)
    {
        for(int j=0;j<=len;j++)
        {
            if(x-i>=0 && y-j>=0)domain[x-i][y-j]=true;
            if(x-i>=0 && y+j<COL)domain[x-i][y+j]=true;
            if(x+i<ROW && y-j>=0)domain[x+i][y-j]=true;
            if(x+i<ROW && y+j<COL)domain[x+i][y+j]=true;
        }
    }
}

void see_domain()//查看有效域，用于调试
{
    for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<COL;j++)
            {
                if(useful_domain[i][j])
                printf("1 ");
                else printf("  ");
            }
            putchar('\n');
        }
}

void Game_p2c()//人机主函数
{
    printf("building...\n");
    getchar();
    printf("选择黑棋还是白旗？黑棋输入1，白棋输入2\n");
    char c;
    static int check_ans=0;
    static bool check_forbid;
    static int position[2];
    check_ans=0;
    check_forbid=false;
    int sum_step=0;
    while((c=getchar())!='1' && c!='2')
    {
        Invalid_input();
    }
    int is_thistime_win=0;
    if(c=='1')//玩家选择先手时
    {
        printf("你选择了黑棋，你将先手，电脑将后手\n");
        printf("请输入%s的落子位置，如C4\n", playername[whoseturn-1]);
        //现在whoseturn==PLAYER1
        
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
            //whoseturn==PLAYER1时
            board[position[0]][position[1]] = PLAYER1;
            add_domain(useful_domain,position[0],position[1],2);
            newboard[position[0]][position[1]] = PLAYER1_new;
            ShowBoard(newboard, ROW, COL);
            sum_step++;
            find_2345(board,ROW,COL);
            check_forbid=isforbid34(board,PLAYER1);
            if(isforbid)printf("是否禁手：%s\n",check_forbid?"yes":"no");
            newboard[position[0]][position[1]] = PLAYER1;
            //
            check_ans=check(board, ROW, COL);
            if(check_ans==PLAYER1)
            {
                printf("你赢了！\n");
                printf("总步数为%d\n",sum_step);
                system("pause");
                return;
            }
            else if(check_forbid)
            {
                printf("你输了！\n");
                printf("总步数为%d\n",sum_step);
                system("pause");
                return;
            }
            whoseturn = PLAYER2;
            struct node chosen_step=ai_player2(board,0,sum_step);
            printf("value=%d\n",chosen_step.value);
            position[0]=chosen_step.x;
            position[1]=chosen_step.y;
            board[position[0]][position[1]] = PLAYER2;
            add_domain(useful_domain,position[0],position[1],2);
            newboard[position[0]][position[1]] = PLAYER2_new;
            ShowBoard(newboard, ROW, COL);
            sum_step++;
            find_2345(board,ROW,COL);
            check_forbid=isforbid34(board,PLAYER1);
            if(isforbid)printf("是否禁手：%s\n",check_forbid?"yes":"no");
            printf("电脑选择的落子是%c%d\n",position[0]+'A',position[1]+1);
            newboard[position[0]][position[1]] = PLAYER2;
            //ShowBoard(board, ROW, COL);
            check_ans=check(board, ROW, COL);
            //printf("check_ans=%d\n",check_ans);
            if((check_ans)==PLAYER2)
            {
                printf("你输了！\n");
                printf("总步数为%d\n",sum_step);
                system("pause");
                return;
            }
            else if(check_ans==PLAYER2)
            {
                printf("你赢了！\n");
                printf("总步数为%d\n",sum_step);
                system("pause");
                return;
            }
            whoseturn = PLAYER1;
        }
    }
    else//玩家选择后手时
    {
        
        board[7][7]=PLAYER1;
        add_domain(useful_domain,7,7,2);//先下H8不商量
        newboard[7][7]=PLAYER1_new;
        printf("\033c");
        ShowBoard(newboard,ROW,COL);
        sum_step++;
        newboard[7][7]=PLAYER1;
        whoseturn=PLAYER2;
        printf("你选择了白棋，你将后手，电脑将先手\n");
        printf("电脑选择的落子是H8\n");
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
            //whoseturn==PLAYER2时
            board[position[0]][position[1]] = PLAYER2;
            add_domain(useful_domain,position[0],position[1],2);
            newboard[position[0]][position[1]] = PLAYER2_new;
            ShowBoard(newboard, ROW, COL);
            sum_step++;
            find_2345(board,ROW,COL);
            if(isforbid)
            {
                check_forbid=isforbid34(board,PLAYER1);
                printf("是否禁手：%s\n",check_forbid?"yes":"no");
            }
            newboard[position[0]][position[1]] = PLAYER2;
            check_ans=check(board, ROW, COL);
            if(check_ans==PLAYER2)
            {
                printf("你赢了！\n");
                system("pause");
                return;
            }
            else if(check_forbid)
            {
                printf("你输了！\n");
                system("pause");
                return;
            }
            whoseturn = PLAYER1;
            struct node chosen_step=ai_player1(board,0,sum_step);
            printf("value=%d\n",chosen_step.value);
            position[0]=chosen_step.x;
            position[1]=chosen_step.y;
            board[position[0]][position[1]] = PLAYER1;
            add_domain(useful_domain,position[0],position[1],2);
            newboard[position[0]][position[1]] = PLAYER1_new;
            ShowBoard(newboard, ROW, COL);
            sum_step++;
            find_2345(board,ROW,COL);
            if(isforbid)
            {
                check_forbid=isforbid34(board,PLAYER1);
                printf("是否禁手：%s\n",check_forbid?"yes":"no");
            }
            printf("电脑选择的落子是%c%d\n",position[0]+'A',position[1]+1);
            newboard[position[0]][position[1]] = PLAYER1;
            check_ans=check(board, ROW, COL);
            if((check_ans)==PLAYER1)
            {
                printf("你输了！\n");
                system("pause");
                return;
            }
            else if(check_ans==PLAYER2)
            {
                printf("你赢了！\n");
                system("pause");
                return;
            }
            whoseturn = PLAYER2;
        }
    }


    //到此为止
}

struct node ai_player1(int this_board[][COL],int step,int sum_step)
{
    //printf("%d \n",step);

    //不要超过最大搜索深度
    if(step>=MAX_STEP)return (struct node){-1,-1,0};
    
    // if(step==0)
    // {
    //     see_domain();
    // }

    //第一步特判，在第一个字周围5*5区域随机下子
    if(sum_step<=2)
    {
        struct node last_step={-1,-1,-INFTY};
        for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<COL;j++)
            {
                if(this_board[i][j]==PLAYER1)
                {
                    last_step=(struct node){i,j,val_win};
                }
            }
            //if(last_step.value>=val_win)break;
        }
        struct node res_ans[50];
        int temp=0;
        for(int i=0;i<=2;i++)
        {
            for(int j=0;j<=2;j++)
            {
                if(last_step.x-i>=0 && last_step.y-j>=0 && !this_board[last_step.x-i][last_step.y-j])
                {
                    res_ans[temp++]=(struct node){last_step.x-i,last_step.y-j,val_win};
                }
                if(last_step.x-i>=0 && last_step.y+j<COL && !this_board[last_step.x-i][last_step.y+j])
                {
                    res_ans[temp++]=(struct node){last_step.x-i,last_step.y+j,val_win};
                }
                if(last_step.x+i<ROW && last_step.y-j>=0 && !this_board[last_step.x+i][last_step.y-j])
                {
                    res_ans[temp++]=(struct node){last_step.x+i,last_step.y-j,val_win};
                }
                if(last_step.x+i<ROW && last_step.y+j<COL && !this_board[last_step.x+i][last_step.y+j])
                {
                    res_ans[temp++]=(struct node){last_step.x+i,last_step.y+j,val_win};
                }
            }
        }
        srand(time(NULL));
        return res_ans[rand()%temp];
    }
    find_2345(this_board,ROW,COL);//判断当前局势
    //如果有必须防守的步，强制防守
    if(step==0 && !num_huosi_1 && !num_chongsi_1 && !num_tiaosi_1 && !num_tiaochongsi_1)
    {
        
        if(num_huosi_2)
        {
            //printf("活四\n");
            return (struct node){huosi[1][0][5][0],huosi[1][0][5][1],val_win};
        }
        if(num_chongsi_2)
        {
            //printf("冲四\n");
            return (struct node){chongsi[1][0][5][0],chongsi[1][0][5][1],val_win};
        }
        if(num_tiaosi_2)
        {
            //printf("跳四\n");
            return (struct node){tiaosi[1][0][4][0],tiaosi[1][0][4][1],val_win};
        }
        if(num_tiaochongsi_2)
        {
            //printf("跳冲四\n");
            return (struct node){tiaochongsi[1][0][4][0],tiaochongsi[1][0][4][1],val_win};
        }
    }
    //必胜步强攻
    if(step==0)
    {
        if(num_huosi_1) 
        {
            return (struct node){huosi[0][0][5][0],huosi[0][0][5][1],val_win};
        }
        if(num_chongsi_1)
        {
            return (struct node){chongsi[0][0][5][0],chongsi[0][0][5][1],val_win};
        }
        if(num_tiaosi_1)
        {
            return (struct node){tiaosi[0][0][4][0],tiaosi[0][0][4][1],val_win};
        }
        if(num_tiaochongsi_1)
        {
            return (struct node){tiaochongsi[0][0][4][0],tiaochongsi[0][0][4][1],val_win};
        }
    }
    int value_board[ROW][COL]={0},max_val=-INFTY;//value_board用来记录每一步的分数
    //防御点加分
    if(!num_huosi_1 && !num_chongsi_1 && !num_tiaosi_1 && !num_tiaochongsi_1)
    {
        for(int k=0;k<num_huosi_2;k++)
        {
            value_board[huosi[1][k][4][0]][huosi[1][k][4][1]]+=val_huosi;
            value_board[huosi[1][k][5][0]][huosi[1][k][5][1]]+=val_huosi;
        }
        for(int k=0;k<num_chongsi_2;k++)
        {
            value_board[chongsi[1][k][5][0]][chongsi[1][k][5][1]]+=val_huosi;
        }
        for(int k=0;k<num_tiaosi_2;k++)
        {
            value_board[tiaosi[1][k][4][0]][tiaosi[1][k][4][1]]+=val_huosi;
        }
        for(int k=0;k<num_tiaochongsi_2;k++)
        {
            value_board[tiaochongsi[1][k][4][0]][tiaochongsi[1][k][4][1]]+=val_huosi*0.8;
        }
        if(!num_huosan_1 && !num_tiaohuosan_1)
        {
            for(int k=0;k<num_huosan_2;k++)
            {
                value_board[huosan[1][k][3][0]][huosan[1][k][3][1]]+=val_huosi*0.7;
                value_board[huosan[1][k][4][0]][huosan[1][k][4][1]]+=val_huosi*0.7;
                value_board[huosan[1][k][5][0]][huosan[1][k][5][1]]+=val_huosi*0.01;
                value_board[huosan[1][k][6][0]][huosan[1][k][6][1]]+=val_huosi*0.01;
            }
            for(int k=0;k<num_tiaohuosan_2;k++)
            {
                value_board[tiaohuosan[1][k][3][0]][tiaohuosan[1][k][3][1]]+=val_huosi*0.7;
                value_board[tiaohuosan[1][k][4][0]][tiaohuosan[1][k][4][1]]+=val_huosi*0.01;
                value_board[tiaohuosan[1][k][5][0]][tiaohuosan[1][k][5][1]]+=val_huosi*0.01;
            }
            for(int k=0;k<num_fakehuosan_2;k++)
            {
                value_board[fakehuosan[1][k][3][0]][fakehuosan[1][k][3][1]]+=val_huosi*0.6;
                value_board[fakehuosan[1][k][4][0]][fakehuosan[1][k][4][1]]+=val_huosi*0.6;
                value_board[fakehuosan[1][k][5][0]][fakehuosan[1][k][5][1]]+=val_huosi*0.01;
                value_board[fakehuosan[1][k][6][0]][fakehuosan[1][k][6][1]]+=val_huosi*0.01;
            }

        }
    }
    
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            //printf("%d %d\n",i,j);
            if(useful_domain[i][j] && this_board[i][j]==0)//不要超过有效区域
            {
                //printf("%d %d %d\n",step,i,j);
                
                this_board[i][j]=PLAYER1;//修改一个棋子
                //测试行
                //ShowBoard(this_board,ROW,COL);
                //如果已经赢了或者输了，就不用继续搜索了
                bool check_win=0;
                if((check_win=check(this_board,ROW,COL))==PLAYER1)
                {
                    value_board[i][j]+=INFTY;
                    this_board[i][j]=0;
                    return (struct node){i,j,value_board[i][j]};
                }
                else if(check_win==PLAYER2)
                {
                    value_board[i][j]-=INFTY;
                    this_board[i][j]=0;
                    return (struct node){i,j,value_board[i][j]};
                }
                find_2345(this_board,ROW,COL);//判断修改一个棋子后的局势
                //这里优先防守
                if(isforbid && isforbid34(this_board,PLAYER1))//黑棋禁手的话不能下
                {
                    this_board[i][j]=0;
                    value_board[i][j]-=val_win;
                    continue;
                }
                //struct node defense_step={-1,-1,-INFTY};
                
                /*
                if(max_val>=val_win)
                {
                    struct node res_ans[105];
                    int temp=0;
                    for(int k=0;k<ROW;k++)
                    {
                        for(int l=0;l<COL;l++)
                        {
                            if(!this_board[k][l] && value_board[k][l]>=max_val)
                            {
                                res_ans[temp++]=(struct node){k,l,value_board[k][l]};
                            }
                        }
                    }
                    this_board[i][j]=0;
                    if(temp)
                    {
                        srand(time(NULL));
                        return res_ans[rand()%temp];
                    }
                }
                */
                
                //加分项
                value_board[i][j]+=(num_huosan_1*num_huosan_1)*val_huosan;
                value_board[i][j]+=(num_fakehuosan_1*num_fakehuosan_1)*val_fakehuosan;
                value_board[i][j]+=(num_tiaohuosan_1*num_tiaohuosan_1)*val_tiaohuosan;
                value_board[i][j]+=(num_huosan_1+num_fakehuosan_1+num_tiaohuosan_1)*(num_huosan_1+num_fakehuosan_1+num_tiaohuosan_1)*2*val_tiaohuosan;//双活三
                value_board[i][j]+=(num_chongsan_1*num_chongsan_1)*val_chongsan;
                value_board[i][j]+=((1<<num_huoer_1)-1)*val_huoer;
                value_board[i][j]+=((1<<num_tiaohuoer_1)-1)*val_tiaohuoer;
                value_board[i][j]+=(num_huosi_1*num_huosi_1)*val_huosi*3;
                value_board[i][j]+=(num_tiaosi_1*num_tiaosi_1)*val_tiaosi;
                value_board[i][j]+=(num_chongsi_1*num_chongsi_1)*val_chongsi;
                value_board[i][j]+=(num_tiaochongsi_1*num_tiaochongsi_1)*val_tiaochongsi;
                value_board[i][j]+=((num_tiaochongsi_1+num_chongsi_1+num_tiaosi_1+num_huosi_1)*(num_tiaochongsi_1+num_chongsi_1+num_tiaosi_1+num_huosi_1))*val_chongsi;//双冲四
                value_board[i][j]+=round_score(this_board,i,j,PLAYER1);
                value_board[i][j]+=(((num_huosi_1+num_tiaosi_1+num_chongsi_1+num_tiaochongsi_1)*(num_huosan_1+num_tiaohuosan_1+num_fakehuosan_1)))*val_huosi*2;//冲四活三


                //printf("%d %d\n",i,j);
                if(step+1<MAX_STEP && sum_step>3)
                {
                    struct node next_step=ai_player2(this_board,step+1,sum_step+1);
                    //一定要记得把修改的旗子改回去
                    value_board[i][j]-=next_step.value*COEFF;
                }
                //max_val=max(max_val,value_board[i][j]);
                //printf("%d %d %d %d\n",step,i,j,value_board[i][j]);
                this_board[i][j]=0;
            }
        }
    }
    //输出一下分数表，方便debug，也可以不输出
    if(step==0)
    {
        for(int i=ROW-1;i>=0;i--)
        {
            for(int j=0;j<COL;j++)
            {
                printf("%6d ",value_board[j][i]);
            }
            putchar('\n');
        }
    }
    // if(max_val<0)
    // { 
    //     printf("step=%d max_val=%d\n",step,max_val);
    // }
    max_val=-INFTY;
    //寻找最大值
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(this_board[i][j] || !useful_domain[i][j])continue;
            max_val=max(max_val,value_board[i][j]);
        }
    }
    
    if(step>=2)//取平均值时这样写
    {
        int avg=0,sum=0;
        for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<COL;j++)
            {
                if(useful_domain[i][j] && !this_board[i][j])
                {
                    sum++;
                    avg+=value_board[i][j];
                }
            }
        }
        return (struct node){-1,-1,avg/sum};
    }
    //取松弛化最大值时这样写
    struct node res_ans[226];
    int temp=0,flag=min(min(max_val*SCALE,max_val/SCALE),max_val-30);
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(!this_board[i][j] && useful_domain[i][j] && value_board[i][j]>= flag)
            {
                res_ans[temp++]=(struct node){i,j,value_board[i][j]};
            }
        }
    }
    //下面是测试行可以删掉
    printf("temp=%d max_val=%d FLAG%d\n",temp,max_val,flag);
    if(temp)//防止输出空的
    {
        srand(time(NULL));
        //printf("x=%d y=%d value=%d\n",res_ans[0].x,res_ans[0].y,res_ans[0].value);

        return res_ans[rand()%temp];
    }
    //防止输出空的
    return (struct node){-1,-1,0};
}


struct node ai_player2(int this_board[][COL],int step,int sum_step)//白棋ai，和黑棋差不多，不写注释了
{
    //printf("%d \n",step);
    if(step>=MAX_STEP)return (struct node){-1,-1,0};
    //第一步特判
    
    if(sum_step<=2)
    {
        struct node last_step={-1,-1,-INFTY};
        for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<COL;j++)
            {
                if(this_board[i][j]==PLAYER1)
                {
                    last_step=(struct node){i,j,val_win};
                }
            }
            if(last_step.value>=val_win)break;
        }
        printf("x=%d y=%d\n",last_step.x,last_step.y);
        struct node res_ans[10];
        int temp=0;
        if(last_step.x+1<ROW)
        {
            res_ans[temp++]=(struct node){last_step.x+1,last_step.y,val_win};
            if(last_step.y+1<COL)
            {
                res_ans[temp++]=(struct node){last_step.x+1,last_step.y+1,val_win};
                res_ans[temp++]=(struct node){last_step.x,last_step.y+1,val_win};
            }
            if(last_step.y-1>=0)
            {
                res_ans[temp++]=(struct node){last_step.x+1,last_step.y-1,val_win};
                res_ans[temp++]=(struct node){last_step.x,last_step.y-1,val_win};
            }
        }
        if(last_step.x-1>=0)
        {
            res_ans[temp++]=(struct node){last_step.x-1,last_step.y,val_win};
            if(last_step.y+1<COL)
            {
                res_ans[temp++]=(struct node){last_step.x-1,last_step.y+1,val_win};
                //res_ans[temp++]=(struct node){last_step.x,last_step.y+1,val_win};
            }
            if(last_step.y-1>=0)
            {
                res_ans[temp++]=(struct node){last_step.x-1,last_step.y-1,val_win};
                //res_ans[temp++]=(struct node){last_step.x,last_step.y-1,val_win};
            }
        }
        srand(time(NULL));
        return res_ans[rand()%temp];
    }
    find_2345(this_board,ROW,COL);
    if(step==0 && !num_huosi_2 && !num_chongsi_2 && !num_tiaosi_2 && !num_tiaochongsi_2)
    {
        if(num_huosi_1)
        {
            //printf("活四\n");
            return (struct node){huosi[0][0][5][0],huosi[0][0][5][1],val_win};
        }
        if(num_chongsi_1)
        {
            //printf("冲四\n");
            return (struct node){chongsi[0][0][5][0],chongsi[0][0][5][1],val_win};
        }
        if(num_tiaosi_1)
        {
            //printf("跳四\n");
            return (struct node){tiaosi[0][0][4][0],tiaosi[0][0][4][1],val_win};
        }
        if(num_tiaochongsi_1)
        {
            //printf("跳冲四\n");
            return (struct node){tiaochongsi[0][0][4][0],tiaochongsi[0][0][4][1],val_win};
        }
    }
    //必胜步强攻
    if(step==0)
    {
        if(num_huosi_2) 
        {
            return (struct node){huosi[1][0][5][0],huosi[1][0][5][1],val_win};
        }
        if(num_chongsi_2) 
        {
            return (struct node){chongsi[1][0][5][0],chongsi[1][0][5][1],val_win};
        }
        if(num_tiaosi_2) 
        {
            return (struct node){tiaosi[1][0][4][0],tiaosi[1][0][4][1],val_win};
        }
        if(num_tiaochongsi_2) 
        {
            return (struct node){tiaochongsi[1][0][4][0],tiaochongsi[1][0][4][1],val_win};
        }
    }
    int value_board[ROW][COL]={0},max_val=-INFTY;
    if(!num_huosi_2 && !num_chongsi_2 && !num_tiaosi_2 && !num_tiaochongsi_2)
    {
        for(int k=0;k<num_huosi_1;k++)
        {
            value_board[huosi[0][k][4][0]][huosi[0][k][4][1]]+=val_huosi;
            value_board[huosi[0][k][5][0]][huosi[0][k][5][1]]+=val_huosi;
        }
        for(int k=0;k<num_chongsi_1;k++)
        {
            value_board[chongsi[0][k][5][0]][chongsi[0][k][5][1]]+=val_huosi;
        }
        for(int k=0;k<num_tiaosi_1;k++)
        {
            value_board[tiaosi[0][k][4][0]][tiaosi[0][k][4][1]]+=val_huosi;
        }
        for(int k=0;k<num_tiaochongsi_1;k++)
        {
            value_board[tiaochongsi[0][k][4][0]][tiaochongsi[0][k][4][1]]+=val_huosi;
        }
        if(!num_huosan_2 && !num_tiaohuosan_2)
        {
            for(int k=0;k<num_huosan_1;k++)
            {
                value_board[huosan[0][k][3][0]][huosan[0][k][3][1]]+=val_huosi*0.7;
                value_board[huosan[0][k][4][0]][huosan[0][k][4][1]]+=val_huosi*0.7;
                value_board[huosan[0][k][5][0]][huosan[0][k][5][1]]+=val_huosi*0.01;
                value_board[huosan[0][k][6][0]][huosan[0][k][6][1]]+=val_huosi*0.01;
            }
            for(int k=0;k<num_tiaohuosan_1;k++)
            {
                value_board[tiaohuosan[0][k][3][0]][tiaohuosan[0][k][3][1]]+=val_huosi*0.7;
                value_board[tiaohuosan[0][k][4][0]][tiaohuosan[0][k][4][1]]+=val_huosi*0.01;
                value_board[tiaohuosan[0][k][5][0]][tiaohuosan[0][k][5][1]]+=val_huosi*0.01;
            }
            for(int k=0;k<num_fakehuosan_1;k++)
            {
                value_board[fakehuosan[0][k][3][0]][fakehuosan[0][k][3][1]]+=val_huosi*0.6;
                value_board[fakehuosan[0][k][4][0]][fakehuosan[0][k][4][1]]+=val_huosi*0.6;
                value_board[fakehuosan[0][k][5][0]][fakehuosan[0][k][5][1]]+=val_huosi*0.01;
                value_board[fakehuosan[0][k][6][0]][fakehuosan[0][k][6][1]]+=val_huosi*0.01;
            }

        }
    }
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(useful_domain[i][j] && !this_board[i][j])
            {
                this_board[i][j]=PLAYER2;
                if(check(this_board,ROW,COL)==PLAYER2)
                {
                    value_board[i][j]+=INFTY;
                    this_board[i][j]=0;
                    return (struct node){i,j,value_board[i][j]};
                }
                find_2345(this_board,ROW,COL);
                //ShowBoard(this_board,ROW,COL);
                //这里优先防守
                //struct node defense_step={-1,-1,-INFTY};
                
                
                
                
                /*
                if(max_val>=val_win)
                {
                    struct node res_ans[105];
                    int temp=0;
                    for(int k=0;k<ROW;k++)
                    {
                        for(int l=0;l<COL;l++)
                        {
                            if(!this_board[k][l] && value_board[k][l]>=max_val)
                            {
                                res_ans[temp++]=(struct node){k,l,value_board[k][l]};
                            }
                        }
                    }
                    this_board[i][j]=0;
                    if(temp)
                    {
                        srand(time(NULL));
                        return res_ans[rand()%temp];
                    }
                    return (struct node){-1,-1,max_val};
                }
                */
                if(isforbid34(this_board,PLAYER2))
                {
                    value_board[i][j]+=val_huosi*0.5;
                }

                value_board[i][j]+=(num_huosan_2*num_huosan_2)*val_huosan;
                value_board[i][j]+=(num_fakehuosan_2*num_fakehuosan_2)*val_fakehuosan;
                value_board[i][j]+=(num_tiaohuosan_2*num_tiaohuosan_2)*val_tiaohuosan;
                value_board[i][j]+=(num_huosan_2+num_fakehuosan_2+num_tiaohuosan_2)*(num_huosan_2+num_fakehuosan_2+num_tiaohuosan_2)*2*val_tiaohuosan;
                value_board[i][j]+=(num_chongsan_2*num_chongsan_2)*val_chongsan;
                value_board[i][j]+=((1<<num_huoer_2)-1)*val_huoer;
                value_board[i][j]+=((1<<num_tiaohuoer_2)-1)*val_tiaohuoer;
                //value_board[i][j]+=num_ri_1*val_ri;
                value_board[i][j]+=(num_huosi_2*num_huosi_2)*val_huosi*3;
                value_board[i][j]+=(num_tiaosi_2*num_tiaosi_2)*val_tiaosi;
                value_board[i][j]+=(num_chongsi_2*num_chongsi_2)*val_chongsi;
                value_board[i][j]+=(num_tiaochongsi_2*num_tiaochongsi_2)*val_tiaochongsi;
                value_board[i][j]+=((num_tiaochongsi_2+num_chongsi_2+num_tiaosi_2+num_huosi_2)*(num_tiaochongsi_2+num_chongsi_2+num_tiaosi_2+num_huosi_2))*val_chongsi;
                value_board[i][j]+=round_score(this_board,i,j,PLAYER2);
                value_board[i][j]+=(((num_huosi_2+num_tiaosi_2+num_chongsi_2+num_tiaochongsi_2)*(num_huosan_2+num_tiaohuosan_2+num_fakehuosan_2)))*val_huosi*2;


                //printf("%d %d\n",i,j);
                if(step+1<MAX_STEP && sum_step>3)
                {
                    struct node next_step=ai_player1(this_board,step+1,sum_step+1);
                    //一定要记得把修改的旗子改回去
                    value_board[i][j]-=next_step.value*COEFF;
                }
                //max_val=max(max_val,value_board[i][j]);
                //printf("%d %d %d %d\n",step,i,j,value_board[i][j]);
                this_board[i][j]=0;
            }
        }
    }
    // if(max_val<0)
    // {
    //     printf("step=%d max_val=%d\n",step,max_val);
    // }
    max_val=-INFTY;
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(this_board[i][j] || !useful_domain[i][j])continue;
            max_val=max(max_val,value_board[i][j]);
        }
    }
    if(step==0)
    {
        for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<COL;j++)
            {
                printf("%6d ",value_board[i][j]);
            }
            putchar('\n');
        }
    }
    if(step>=2)
    {
        int avg=0,sum=0;
        for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<COL;j++)
            {
                if(useful_domain[i][j] && !this_board[i][j])
                {
                    sum++;
                    avg+=value_board[i][j];
                }
            }
        }
        return (struct node){-1,-1,avg/sum};
    }
    struct node res_ans[226];
    int temp=0,flag=min(min(max_val*SCALE,max_val/SCALE),max_val-30);
    for(int i=ROW-1;i>=0;i--)
    {
        for(int j=0;j<COL;j++)
        {
            if(this_board[i][j]==0 && useful_domain[i][j] && value_board[i][j]>=flag)
            {
                res_ans[temp++]=(struct node){i,j,value_board[j][i]};
            }
        }
    }
    //srand(time(NULL));
    //printf("STEP=%d x=%d y=%d value=%d\n",step,res_ans[0].x,res_ans[0].y,res_ans[0].value);
    printf("temp=%d max_val=%d FLAG=%d\n",temp,max_val,flag);

    if(temp)
    {
        srand(time(NULL));
        return res_ans[rand()%temp];
    }
    return (struct node){-1,-1,max_val};
}

int round_score(int this_board[][COL],int x,int y,int color)//计算一个点的周围分数，日型分数也很重要，日型是防守步
{
    int sum=0,sum2=0;
    if(x-1>=0 && y-1>=0 && this_board[x-1][y-1])sum++;
    if(x-1>=0 && this_board[x-1][y])sum++;
    if(x-1>=0 && y+1<COL && this_board[x-1][y+1])sum++;
    if(y-1>=0 && this_board[x][y-1])sum++;
    if(y+1<COL && this_board[x][y+1])sum++;
    if(x+1<ROW && y-1>=0 && this_board[x+1][y-1])sum++;
    if(x+1<ROW && this_board[x+1][y])sum++;
    if(x+1<ROW && y+1<COL && this_board[x+1][y+1])sum++;
    if(x-2>=0)
    {
        if(y+1<COL && this_board[x-2][y+1]==color)sum2++;
        if(y-1>=0 && this_board[x-2][y-1]==color)sum2++;
    }
    if(x+2<ROW)
    {
        if(y+1<COL && this_board[x+2][y+1]==color)sum2++;
        if(y-1>=0 && this_board[x+2][y-1]==color)sum2++;
    }
    if(y-2>=0)
    {
        if(x+1<ROW && this_board[x+1][y-2]==color)sum2++;
        if(x-1>=0 && this_board[x-1][y-2]==color)sum2++;
    }
    if(y+2<COL)
    {
        if(x+1<ROW && this_board[x+1][y+2]==color)sum2++;
        if(x-1>=0 && this_board[x-1][y+2]==color)sum2++;
    }
    return sum2*val_ri+sum*val_round;
}