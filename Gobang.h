//定义棋盘每个位置的状态白子、黑子、空白

#define WHITE -1
#define BLACK 1
#define BLANK 0

//定义棋盘的最大行数和最大列数
#define MAX_ROW 15
#define MAX_COL 15

//初始化菜单
void menu();
//初始化棋子
void draw_chessman(int type,char *tableline);
//初始化棋盘
void draw_chessboardn(int chessboard[MAX_ROW][MAX_COL],int row,int col);
//判断胜负
int is_win(int chessboard[MAX_ROW][MAX_COL],int row,int col);
//判断棋盘是否已经满了
int is_full(int chessboard[MAX_ROW][MAX_COL],int row,int col);
//人人对战
void person_person();
//人机对战
void person_computer_random();
