//��������ÿ��λ�õ�״̬���ӡ����ӡ��հ�

#define WHITE -1
#define BLACK 1
#define BLANK 0

//�������̵�����������������
#define MAX_ROW 15
#define MAX_COL 15

//��ʼ���˵�
void menu();
//��ʼ������
void draw_chessman(int type,char *tableline);
//��ʼ������
void draw_chessboardn(int chessboard[MAX_ROW][MAX_COL],int row,int col);
//�ж�ʤ��
int is_win(int chessboard[MAX_ROW][MAX_COL],int row,int col);
//�ж������Ƿ��Ѿ�����
int is_full(int chessboard[MAX_ROW][MAX_COL],int row,int col);
//���˶�ս
void person_person();
//�˻���ս
void person_computer_random();
