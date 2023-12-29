#include<iostream>
using namespace std;
int a[105][2];
int height[105];
/*
a[i][0]代表以第i个人为结尾的
最长上升子序列长度（合唱队形没有下降）
a[i][1] 代表以第i个人为结尾的最长
合唱队形，但至少有一个人的身高呈下降趋势
显然，max(a[i][0],a[i][1])代表前i个人的
最长合唱队形
*/
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>height[i];
    for(int i=1;i<=n;i++){
        // 递推求最长上升子序列
        a[i][0]=1;
        for(int j=1;j<i;j++){
            if(height[i]>height[j])
                a[i][0]=max(a[i][0],a[j][0]+1);
        }
    }
    for(int i=1;i<=n;i++){
        a[i][1]=1;
        for(int j=1;j<i;j++)
            if(height[i]<height[j])
                a[i][1]=max(a[i][1],max(a[j][0],a[j][1])+1);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,max(a[i][0],a[i][1]));
    cout<<n-ans<<endl;
    return 0;
}