#include <iostream>
#define N 30
using namespace std;
int n;double W; //n个数，W容量
double w[N];double v[N];  //物品重量和价值
bool x[N];
bool best_x[N]; //存储最优方案
double now_v;   //当前价值
double remain_v;    //剩余价值
double now_w;   //当前容量
double best_v;  //最优价值
double Bound(int k)     //计算分枝结点k的上界
{
    remain_v = 0;
    while (k <= n) {
        remain_v += v[k];
        k++;
    }
    return remain_v + now_v;
}
void Backtrack(int t)
{
    if (t > n) {  //是否到达叶节点
        for (int i = 1; i <= n; i++) {
            best_x[i] = x[i];   //记录回溯的最优情况
        }
        best_v = now_v; //记录回溯中的最优价值
        return;
    }
    if (now_w + w[t] <= W) {  //约束条件，是否放入。放入考虑左子树，否则考虑右子树
        x[t] = 1;
        now_w += w[t];
        now_v += v[t];
        Backtrack(t + 1); //进行下一个节点的分析
        now_w -= w[t];  //在到达叶节点后进行回溯
        now_v -= v[t];
    }
    if (Bound(t + 1) > best_v) {    //限界条件，是否剪枝。若放入t后不满足约束条件则进行到此处，然后判断若当前价值加剩余价值都达不到最优，则没必要进行下去
        x[t] = 0;
        Backtrack(t + 1);
    }
}
void Knapsack(double W, int n)
{
    double sum_w = 0;
    double sum_v = 0;
    best_v = 0;
    for (int i = 0; i < n; i++) {
        sum_w += w[i];
        sum_v += v[i];
    }
    Backtrack(1);
    cout << "放入购物车的物品最大价值为：" << best_v << endl;
    cout << "放入购物车的物品序号为：" << endl;
    for (int i = 1; i <= n; i++) {
        if(x[i] == 1)
            cout << i << " ";
    }
}
int main()
{
    cout << "输入物品个数n:"; cin >> n;
    cout << "输入购物车容量W:"; cin >> W;
    cout << "依次输入每个物品的重量w和价值v，用空格分开：\n";
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    Knapsack(W, n);
    return 0;
}