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

typedef double DB;
typedef long long ll;
typedef pair<int, int> PII;

#define pb push_back
#define MP make_pair
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define ll long long
const DB eps = 1e-6;
const int inf = ~0U>>1;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int maxn = 1000000 + 10;
char ss[30033][50];
struct node {
    char c[50];
    int idx, p;
    int ans;
    bool operator < (const node& t) const {
        return idx < t.idx;
    }
} q[30033];
int chd[maxn][30], id[555], sz;
int cnt[maxn];
int n, Q;
map<string, int> mp;
map<string, int> ::iterator it;
string s;
bool cmp(node a, node b) {
    return a.p < b.p;
}
void init() {
    memset(chd, 0, sizeof(chd));
    memset(cnt, 0, sizeof(cnt));
    sz = 0;
    mp.clear();
}
void Insert(char *str) {
    int cur = 0;
    for(int i=0; str[i]; i++) {
        if(!chd[cur][id[str[i]]]) chd[cur][id[str[i]]] = ++sz;
        cur = chd[cur][id[str[i]]];
        cnt[cur]++;
    }
}
int Query(char *str, int x) {
    int ret = 0;
    int cur = 0;
    for(int i=0; str[i]; i++) {
        if(chd[cur][id[str[i]]]) {
            ret += x;
            //printf("x %d \n", x);
            x = cnt[chd[cur][id[str[i]]]];
        } else break;
        cur = chd[cur][id[str[i]]];
         //printf("%c %d\n", str[i], ret);
    }
    return (ret + x);
}
int main() {
  //freopen("in.txt", "r", stdin);
    for(int i='a'; i<='z'; i++) id[i] = i - 'a';
    while(scanf("%d", &n) == 1) {
        init();
        for(int i=1; i<=n; i++) {
            scanf("%s", ss[i]);
            s = ss[i];
            if(mp.find(s)==mp.end())
                mp[s] = i;
        }
        scanf("%d", &Q);
        for(int i=0; i<Q; i++) {
            scanf("%s", q[i].c);
            s = q[i].c;
            int d;
            if((it = mp.find(s)) == mp.end()) d = n;
            else d = it -> second;
            q[i].idx = d;
            q[i].p = i;
        }
        sort(q, q + Q);
        int cur = 1;
        for(int i=0; i<Q; i++) {
            while(q[i].idx >= cur && cur <= n) Insert(ss[cur++]);
            q[i].ans = Query(q[i].c, q[i].idx);
            //printf("%I64d\n", q[i].ans);

        }
        sort(q, q + Q, cmp);
        for(int i=0; i<Q; i++)
            printf("%d\n", q[i].ans);
    }
    return 0;
}

