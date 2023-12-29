# include <stdio.h>
# include <stdbool.h>     // 定义布尔类型 
 
// 全局变量
int place[8] = { 0 };     // 保存皇后的位置，下标为行，储存的数据为列。
bool flag[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };     // 用来保存哪一列已经存在皇后 
bool UpDiagonal[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };     // 从左上到右下的对角线为上对角线，每条上对角线上的行和列的差是一样的。
bool DownDiagonal[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };     // 从左下到右下的对角线为下对角线，每条下对角线上的行和列的和是一样的。
int key = 0;     // 用于统计解的数量
 
// 函数声明
void EightQueens(int);     // 八皇后问题
void OutputReasult(void);     // 输出打印棋盘 
 
// 主函数
int main(void)
{
    //OutputReasult();
	EightQueens(0);
	printf("有%d种放置方法\n", key);
 
	return 1;
}
 
void OutputReasult(void)
{
	printf("第%d种放置方法：\n", ++key);
	int row;
	for ( row = 0; row < 8; ++row)
	{
		int elem;
		for ( elem = 0; elem < 8; ++elem)
		{
			if (place[row] == elem)
			{
				printf("Q ");
			}
			else
			{
				printf("* ");
			}
		}
		printf("\n");
	}
	printf("\n");
}
 
void EightQueens(int queen)
{
	int col;
	for ( col = 0; col < 8; ++col)     // 计算第queen行皇后的位置
	{
		if ((flag[col] && UpDiagonal[queen - col + 7]) && DownDiagonal[queen + col])     // 判断第queen行第col列的位置是否危险
		{
			place[queen] = col;     // 记录皇后的位置 
			flag[col] = 0;     // 记录第col列已经有皇后了 
			UpDiagonal[queen - col + 7] = 0;     // 记录这条上对角线是危险的 
			DownDiagonal[queen + col] = 0;     // 记录这条下对角线是危险的
 
			if (queen < 7 )     // 判断八个皇后放完了没有 
			{
				EightQueens(queen + 1);
			}
			else
			{
				OutputReasult();     //输出打印棋盘 
			}
			// 回溯
			flag[col] = 1;
			UpDiagonal[queen - col + 7] = 1;
			DownDiagonal[queen + col] = 1;
		}
	}
}