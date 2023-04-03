#include<stdio.h>
#include"Gobang.h"
#include<stdlib.h>

int main()
{
    //初始化菜单
    menu();
    int choice;
    while(1)
    {
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            system("cls");
            person_person();
            break;
        case 2:
            system("cls");
            person_computer_random();
            break;
        case 3:
            exit(0);          
            break;
        default:
            printf("输入错误请重新选择\n");
            break;
        }   
    }
    return 0;
}