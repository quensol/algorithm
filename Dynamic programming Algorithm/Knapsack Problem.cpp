#include<stdio.h>
#define MAX_SIZE 5//物品数量
#define BAG_SIZE 10//背包容量
int main() {
	int w[MAX_SIZE] = {2,2,6,5,4 };//重量
	int v[MAX_SIZE ] = {6,3,5,4,6 };//价值
	int table[MAX_SIZE + 1][BAG_SIZE + 1];//table表定义  每个元素都是当前容量下背包的最优价值
	int yes[MAX_SIZE];		//选中的物品集
	int yes_size = 0;		//选中集大小

	//建立 表
	for (int i = 0; i <= MAX_SIZE; i++)//i是商品序号  从1开始
		for (int j = 0; j <= BAG_SIZE; j++) {//j是当前背包容量  从0开始
			if (i == 0 || j == 0) {
				table[i][j] = 0;//使第一行以及第一列全为0
				continue;
			}
			if (w[i-1] > j)
				table[i][j] = table[i - 1][j];//如果质量大于背包容量，则不放入。   现行背包总价值为之前的价值
			else
				table[i][j] = table[i - 1][j] > (table[i - 1][j - w[i-1]] + v[i-1]) ? 
                                    table[i - 1][j] : (table[i - 1][j - w[i - 1]] + v[i - 1]);
                //如果质量小于等于背包容量，则判断价值大小
                //（装自己的重量）的最优价值A 与 （不装自己的重量）的最优价值B
                //即A = （当前背包容量j减去当前物品重量（自重）的容量W）所对应价值，即上面表格那个容量W对应的价值 
                                              //再加上自己的价值。
                //即B = 不放自己的价值，即上面表格的价值。
		}
	//接下来回溯table表获取选中的物品
	int i = MAX_SIZE;//纵轴物品最下侧
	int j = BAG_SIZE;//横轴容量最右侧
	while (i > 0 && j > 0) {//如果定位点不在边界
		while (table[i][j] == table[i - 1][j])//如果该格 与 上面一格价值相同
			i--;//上移  一直到不相同
		yes[yes_size++] = --i;//将该物品（因为物品数组所以下标要-1）记录到选中的集合中
		j = j - w[i-1];//横向跳动，跳到减去刚才记录的物品的重量后的容量的横轴位置
	}
	printf("被选中的物品有：\n");
	for (int i = 0; i < yes_size; i++)
		printf("重量为%d，价值为%d的物品\n", w[yes[i]], v[yes[i]]);//循环输出刚才选中的物品
	return 0;//end main()
}
