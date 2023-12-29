/*
 * 01 背包问题求解，回溯法实现
 * 输入格式：
 * 第一行包含背包容量 c 和物品数量 n，以空格分隔；
 * 接下来 n 行，每行包含一个物品的重量和价值，以空格分隔。
 * 输出格式：
 * 最大总价值
 */
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
const int MAXN = 50;
 
struct Object {
    int w, v;  // 物品重量和价值
    double d;  // 单位价值
};
 
bool cmp(Object a, Object b) {
    return a.d > b.d;
}
 
int main() {
    int c, n;
    cout <<"请输入物品个数和背包容量（用空格分隔）：" << endl;
    cin >> n >> c;
    cout << "依次输入每个物品的重量w和价值v，用空格分开：" << endl;
    vector<Object> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].w >> items[i].v;
        if (items[i].w == 0) {
            items[i].d = 0;
        } else {
            items[i].d = 1.0 * items[i].v / items[i].w;
        }
    }
    sort(items.begin(), items.end(), cmp);  // 按单位价值排序
    int bestv = 0;  // 当前最优解
    vector<int> path(n);  // 存储当前搜索路径
    int i = 0;  // 当前搜索的物品编号
    int cw = 0;  // 当前背包中物品的总重量
    int cv = 0;  // 当前背包中物品的总价值
    while (true) {
        if (i >= n) {  // 遍历完了所有物品，回溯
            if (bestv < cv) {
                bestv = cv;
            }
            if (path.empty()) {
                break;  // 遍历完了所有状态，退出
            }
            i = path.back();  // 取出上一个搜索的物品
            path.pop_back();
            cw -= items[i].w;
            cv -= items[i].v;
            i++;  // 进入右子树搜索
        } else if (cw + items[i].w <= c) {  // 左子树搜索
            path.push_back(i);
            cw += items[i].w;
            cv += items[i].v;
            i++;  // 进入左子树搜索
        } else {  // 右子树搜索
            double bound = cv + (c - cw) * items[i].d;  // 计算上界
            if (bound < bestv) {
                if (path.empty()) {
                    break;  // 遍历完了所有状态，退出
                }
                i = path.back();  // 取出上一个搜索的物品
                path.pop_back();
                cw -= items[i].w;
                cv -= items[i].v;
                i++;  // 进入右子树搜索
            } else {
                i++;  // 进入左子树搜索
            }
        }
    }
    cout << "放入背包的物品最大价值为："<< bestv << endl;
    return 0;
}