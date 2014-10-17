#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(i=0;i<n;i++)
#define FOR(i,x,y) for(i=x;i<=y;i++)
#define mz(x) memset(x,0,sizeof(x))
#define re freopen("input.txt","r",stdin)
#define we freopen("output.txt","w",stdout)
#define pb push_back
#define ll long long
#define mod 1000000009
#define eps 1e-9
#define mod (1<<30)
#define maxn 1000005


int main(){
    int n;
    double ans=0;
    double pre=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        double x;
        cin>>x;
        ans+=x*(1+2*pre);
        pre=x*pre+x;
    }
    printf("%.10lf\n",ans);
    return 0;
}

/*
    给一个长度为n的01序列,其中每一位为0的概率是pi,是1的概率为1-pi;
    对于最后生成的序列,如果有连续的T个1存在,那么最终的score加T*T;
    可以很容易想到O(n*n)的解法,但是对于1e5的数据规明显不好使;
    有一个神奇的公式,2*C(n,2)+n=n*n
    那么对于每一段长度为k的(贡献为k*k),他的贡献可以分为两部分;
        一部分是每有一个1,分数加一;每有一对(i,j)满足i到j之间没有0,那么分数加2;
    那么问题就转换成了,求1的个数的期望和求(i,j)个数的期望。
    第一部分好算，将所有的p加起来就可以；
    第二部分设dp[j]为以j结尾的所有(i,j),(i<j)
    那么有dp[j]=(1+dp[j-1])*p[j];，然后再乘以2就是对答案的贡献。
    Orz……

*/












