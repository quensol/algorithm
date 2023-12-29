#include<bits/stdc++.h>
using namespace std;
class Flowshop
{
    friend int Flow(int **, int);
    private:
        void Backtrack(int i);
        void Show();
        int **M,        //各作业所需的处理时间
            *x,         //当前作业调度
            *bestx,     //当前最优作业调度
            *f2,        //机器2完成处理时间
            f1,         //机器1完成处理时间
            f,          //当前完成时间和
            bestf,      //当前最优值
            n;          //作业数
};
void Flowshop::Backtrack(int i)
{
    static int k = 1;
    if(i > n)  //能够到达叶结点的,都是已经经过限界函数的考验,所以可以直接更新答案
    {
        for(int j=1; j<=n; j++)
        {
            bestx[j] = x[j];
            cout<<x[j]<<" ";
        }
        bestf = f;
        cout<<"第"<<k++<<"可行解"<<endl;
    }
    else
    {
        for(int j=i; j<=n; j++)
        {
            cout<<"当前元素为"<<x[j]<<" ";
            f1 += M[x[j]][1];  //f1直接相加
            f2[i] = (f2[i-1]>f1 ? f2[i-1]:f1) + M[x[j]][2];  //f2需要考虑是f1大,还是f2[i-1]大 参考图如上
            f += f2[i];   //作业调度的完成时间和f的定义,是 Σf2[i], 1<=j<=n
            if(f < bestf)  //如果当前完成时间和f小于最优值,可以往下深入一层,否则直接剪枝
            {
                swap(x[i], x[j]);
                cout<<"递归深入一层,将到达第"<<i+1<<"层"<<endl;
                Backtrack(i+1);     //递归下一层
                cout<<"递归回退一层,将到达第"<<i<<"层"<<endl;
                swap(x[i], x[j]);
            }
            f1 -= M[x[j]][1];  //递归回来需要撤销操作
            f -= f2[i];
        }
    }
}
void Flowshop::Show()
{
    cout<<"最小完成时间和为: "<<bestf<<endl;
    cout<<"最优批处理作业调度为: ";
    for(int i=1; i<=n; i++) cout<<bestx[i]<<" ";
    cout<<endl;
}
int Flow(int **M, int n)
{
    int ub = INT_MAX;
    Flowshop X;
    X.x = new int[n+1];
    X.f2 = new int[n+1];
    X.M = M;
    X.n = n;
    X.bestx = new int[n+1];
    X.bestf = ub;
    X.f1 = 0;
    X.f = 0;
    for(int i=0; i<=n; i++)
        X.f2[i] = 0, X.x[i] = i;    //x表示编号
    X.Backtrack(1);
    X.Show();
    delete[] X.x;
    delete[] X.f2;
    return X.bestf;
}
int main()
{
    cout<<"请输入作业个数:";
    int n;
    while(cin>>n && n)
    {
        int **M = new int*[n+1];
        for(int i=0; i<=n; i++) M[i] = new int[3];
        int time1, time2;
        for(int i=1; i<=n; i++)
        {
            cout<<"请输入作业"<<i<<"在机器1以及机器2上的工作时间:";
            cin>>time1>>time2;
            M[i][1] = time1;
            M[i][2] = time2;
        }
        Flow(M, n);
    }
    system("pause");
    return 0;
}
