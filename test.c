#include<stdio.h>
#include"Gobang.h"
#include<stdlib.h>

int main()
{
    //��ʼ���˵�
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
            printf("�������������ѡ��\n");
            break;
        }   
    }
    return 0;
}