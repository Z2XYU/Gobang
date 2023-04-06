#include"Gobang.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//��ʼ���˵�
void menu()
{
    printf("**************************\n");
    printf("******��ӭʹ��������******\n");
    printf("**1.��-�˶�ս            *\n");
    printf("**2.��-����ս(����㷨)  *\n");
    printf("**3.�˳�                 *\n");
    printf("**************************\n");
    printf("��ѡ��:\n");

}
// ��ʼ������
void draw_chessman(int type,char *tableline)
{
    if(type == WHITE)
        printf(" ��");
    if(type == BLACK)
        printf(" ��");
    if(type == BLANK)
        printf("%s",tableline);
}
// ��ʼ������
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
                draw_chessman(chessboard[i][j]," ��");
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
            //���������
            if(j<col-4)
                if(chessboard[i][j] == chessboard[i][j+1] 
                    && chessboard[i][j] == chessboard[i][j+2] 
                    && chessboard[i][j] == chessboard[i][j+3] 
                    && chessboard[i][j] == chessboard[i][j+4])
                return chessboard[i][j];
            //���������
            if(i<row-4)
                if(chessboard[i][j] == chessboard[i+1][j] 
                    && chessboard[i][j] == chessboard[i+2][j] 
                    && chessboard[i][j] == chessboard[i+3][j] 
                    && chessboard[i][j] == chessboard[i+4][j])
                return chessboard[i][j];
            //��б�������
            if(i<row-4 && j<col-4)
                if(chessboard[i][j] == chessboard[i+1][j+1] 
                    && chessboard[i][j] == chessboard[i+2][j+2] 
                    && chessboard[i][j] == chessboard[i+3][j+3] 
                    && chessboard[i][j] == chessboard[i+4][j+4])
                return chessboard[i][j];
            //��б�������
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
//�ж������Ƿ��Ѿ�����
int is_full(int chessboard[MAX_ROW][MAX_COL],int row,int col )
{
    //�������飬���������������ӣ����ʾƽ��
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

//���˶�ս
void person_person()
{
    int chessboard[MAX_ROW][MAX_COL]={BLANK};
    int i,j;
    draw_chessboardn(chessboard,MAX_ROW,MAX_COL);
    for(int step=1;step<MAX_ROW*MAX_COL;step++)
    {
        if(step%2==1)
        {
            printf("���������\n");
            //�ж����������Ƿ���Ч
            while(1)
            {
                scanf("%d %d",&i,&j);
                if(chessboard[i][j] != BLANK)
                {
                    printf("�ô��Ѿ������ӣ����������롣\n");
                    system("pause");
                    continue;
                }
                if(i>=MAX_ROW && j>=MAX_COL)
                {
                    printf("���볬����Χ�����������롣\n"); 
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
                printf("�����ʤ\n");
                exit(0);
            }
            
        }
        else if(step%2==0)
        {
            printf("��������ӡ�\n");
            //�ж����������Ƿ���Ч
            while(1)
            {
                scanf("%d %d",&i,&j);
                if(chessboard[i][j] !=BLANK)
                {
                    printf("�ô��Ѿ������ӣ����������롣\n");
                    system("pause");
                    continue;
                }
                if(i>MAX_ROW || j>MAX_COL)
                {
                    printf("���볬����Χ�����������롣\n");
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
                printf("�����ʤ\n");
                exit(0);
            }
        }
    }
    if(is_full(chessboard,MAX_ROW,MAX_COL)==1)
    {
        printf("ƽ��\n");
    }
}
//�˻������������
int random_create_point()
{
    int point;
    point = rand() % MAX_ROW;
    return point;
}
//�˻���ս
void person_computer_random()
{
    int chessboard[MAX_ROW][MAX_COL]={BLANK};
    int i,j;
    draw_chessboardn(chessboard,MAX_ROW,MAX_COL);
    for(int step=1;i<=MAX_ROW*MAX_COL;step++)
    {
        if(step%2 == 1)
        {
            printf("���������\n");
            while (1)
            {
                scanf("%d %d",&i,&j);
                if(chessboard[i][j] !=BLANK)
                    {
                        printf("�ô��Ѿ������ӣ����������롣\n");
                        system("pause");
                        continue;
                    }
                    if(i>MAX_ROW || j>MAX_COL)
                    {
                        printf("���볬����Χ�����������롣\n");
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
                printf("�����ʤ\n");
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
                printf("�����ʤ\n");
                exit(0);
            }  
        }
        if(is_full(chessboard,MAX_ROW,MAX_COL) == 1)
        {
            printf("ƽ��\n");
        }
    }
}