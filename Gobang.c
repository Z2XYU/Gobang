#include"Gobang.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//初始化菜单
void menu()
{
    printf("**************************\n");
    printf("******欢迎使用五子棋******\n");
    printf("**1.人-人对战            *\n");
    printf("**2.人-机对战(随机算法)  *\n");
    printf("**3.退出                 *\n");
    printf("**************************\n");
    printf("请选择:\n");

}
// 初始化棋子
void draw_chessman(int type,char *tableline)
{
    if(type == WHITE)
        printf(" ●");
    if(type == BLACK)
        printf(" ○");
    if(type == BLANK)
        printf("%s",tableline);
}
// 初始化棋盘
void draw_chessboardn(int chessboard[MAX_ROW][MAX_COL],int row, int col) 
{
    printf("   ");
    for(int i=0;i<col;i++)
    {
        printf("%2d",i);
    }
    printf("\n");
    for(int i=0;i<row;i++)
    {
        printf("%2d ",i);
        for(int j=0;j<col;j++)
        {
            if(chessboard[i][j] == BLANK)
                draw_chessman(chessboard[i][j]," ·");
            if(chessboard[i][j] == BLACK)
                draw_chessman(chessboard[i][j]," ");
            if(chessboard[i][j] == WHITE)
                draw_chessman(chessboard[i][j]," ");
        }
        printf("\n");
    }
}
int is_win(int chessboard[MAX_ROW][MAX_COL],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(chessboard[i][j] == BLANK)
                continue;
            //横线五个子
            if(j<col-4)
                if(chessboard[i][j] == chessboard[i][j+1] 
                    && chessboard[i][j] == chessboard[i][j+2] 
                    && chessboard[i][j] == chessboard[i][j+3] 
                    && chessboard[i][j] == chessboard[i][j+4])
                return chessboard[i][j];
            //竖线五个子
            if(i<row-4)
                if(chessboard[i][j] == chessboard[i+1][j] 
                    && chessboard[i][j] == chessboard[i+2][j] 
                    && chessboard[i][j] == chessboard[i+3][j] 
                    && chessboard[i][j] == chessboard[i+4][j])
                return chessboard[i][j];
            //左斜线五个子
            if(i<row-4 && j<col-4)
                if(chessboard[i][j] == chessboard[i+1][j+1] 
                    && chessboard[i][j] == chessboard[i+2][j+2] 
                    && chessboard[i][j] == chessboard[i+3][j+3] 
                    && chessboard[i][j] == chessboard[i+4][j+4])
                return chessboard[i][j];
            //右斜线五个子
            if(i<row-4 && j>4)
                if(chessboard[i][j] == chessboard[i-1][j+1] 
                    && chessboard[i][j] == chessboard[i-2][j+2] 
                    && chessboard[i][j] == chessboard[i-3][j+3] 
                    && chessboard[i][j] == chessboard[i-4][j+4])
                return chessboard[i][j]; 
        }
    }
    return BLANK;
}
//判断棋盘是否已经满了
int is_full(int chessboard[MAX_ROW][MAX_COL],int row,int col )
{
    //遍历数组，棋盘若下满了棋子，则表示平局
    int ret=1;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(chessboard[i][j] == BLANK)
                ret = 0;
                break;
        }
    }
    return ret;
}

//人人对战
void person_person()
{
    int chessboard[MAX_ROW][MAX_COL]={BLANK};
    int i,j;
    draw_chessboardn(chessboard,MAX_ROW,MAX_COL);
    for(int step=1;step<MAX_ROW*MAX_COL;step++)
    {
        if(step%2==1)
        {
            printf("请黑棋落子\n");
            //判断棋子输入是否有效
            while(1)
            {
                scanf("%d %d",&i,&j);
                if(chessboard[i][j] != BLANK)
                {
                    printf("该处已经有棋子，请重新输入。\n");
                    system("pause");
                    continue;
                }
                if(i>=MAX_ROW && j>=MAX_COL)
                {
                    printf("输入超出范围，请重新输入。\n"); 
                    system("pause");
                    continue;
                }
                break;
            }
            chessboard[i][j]= BLACK;
            system("cls");
            draw_chessboardn(chessboard,MAX_ROW,MAX_COL);
            if(is_win(chessboard,MAX_ROW,MAX_COL) == BLACK)
            {
                printf("黑棋获胜\n");
                exit(0);
            }
            
        }
        else if(step%2==0)
        {
            printf("请白棋落子。\n");
            //判断棋子输入是否有效
            while(1)
            {
                scanf("%d %d",&i,&j);
                if(chessboard[i][j] !=BLANK)
                {
                    printf("该处已经有棋子，请重新输入。\n");
                    system("pause");
                    continue;
                }
                if(i>MAX_ROW || j>MAX_COL)
                {
                    printf("输入超出范围，请重新输入。\n");
                    system("pause");
                    continue;
                }
                break;
            }
            chessboard[i][j]=WHITE;
            system("cls");
            draw_chessboardn(chessboard,MAX_ROW,MAX_COL);
            if(is_win(chessboard,MAX_ROW,MAX_COL) == WHITE)
            {
                printf("白棋获胜\n");
                exit(0);
            }
        }
    }
    if(is_full(chessboard,MAX_ROW,MAX_COL)==1)
    {
        printf("平局\n");
    }
}
//人机随机产生棋子
int random_create_point()
{
    int point;
    point = rand() % MAX_ROW;
    return point;
}
//人机对战
void person_computer_random()
{
    int chessboard[MAX_ROW][MAX_COL]={BLANK};
    int i,j;
    draw_chessboardn(chessboard,MAX_ROW,MAX_COL);
    for(int step=1;i<=MAX_ROW*MAX_COL;step++)
    {
        if(step%2 == 1)
        {
            printf("请输入黑棋\n");
            while (1)
            {
                scanf("%d %d",&i,&j);
                if(chessboard[i][j] !=BLANK)
                    {
                        printf("该处已经有棋子，请重新输入。\n");
                        system("pause");
                        continue;
                    }
                    if(i>MAX_ROW || j>MAX_COL)
                    {
                        printf("输入超出范围，请重新输入。\n");
                        system("pause");
                        continue;
                    }
                    break;
            }
            chessboard[i][j]=BLACK;
            system("cls");
            draw_chessboardn(chessboard,MAX_ROW,MAX_COL);
            if(is_win(chessboard,MAX_COL,MAX_COL) == BLACK)
            {
                printf("黑棋获胜\n");
                exit(0);
            }
        }
        else if(step%2 == 0)
        {
            while (1)       
            {
                i=random_create_point();
                j=random_create_point();
                if(chessboard[i][j] == BLANK)
                {
                    break;
                }
            }
            chessboard[i][j] = WHITE;
            system("cls");
            draw_chessboardn(chessboard,MAX_ROW, MAX_COL);
            if(is_win(chessboard,MAX_ROW, MAX_COL) == WHITE)
            {
                printf("白棋获胜\n");
                exit(0);
            }  
        }
        if(is_full(chessboard,MAX_ROW,MAX_COL) == 1)
        {
            printf("平局\n");
        }
    }
}