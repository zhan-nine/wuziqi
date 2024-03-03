//made by 张欣培
#pragma GCC optimize(2) //O2优化氧气，实测没啥用
#include "myhead.h"
//编译前检查编码GBK
int board[ROW][COL] = { 0 }; //用来计算的棋盘
int newboard[ROW][COL] = { 0 }; //用来摆放出去的棋盘
//需要防止跳冲四过多出现，可能修好了
//现在还存在的bug：
//1.冲四优先度高于活四
//2.有时跳活三不被堵上
//在存在2这个严重bug情况下，能拿到wcg班第五的成绩。bug等待想copy的后人改吧，我不改了。
//在打人类的情况下有奇效
//在高分五子棋中，这个是搜索深度最低的，只有两层
//由于带有一部分随机化算法，能够给你惊喜，跟什么样强度的五子棋都有机会赢一把
//下面是所有用到的文件
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
