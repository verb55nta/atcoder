#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<cstdint>
#include<bits/stdc++.h>
#include<queue>
#include<set>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep_r(i, n) for(int i = n-1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((ll)(x).size())
#define bit(n) (1LL<<(n))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define INF bit(60)
#define pb push_back
#define mod 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using namespace std;
using uif=uint_fast64_t;
using ll=long long int;

int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;}while(b>>=1);return ans;}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct SegmentTree {
private:
    int n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, -INF);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }

  void update(int x, ll val) {
    // 最下段のノードにアクセスする
    x += (n - 1);

    // 最下段のノードを更新したら、あとは親に上って更新していく
    node[x] = val;
    while(x > 0) {
        x = (x - 1) / 2;
        node[x] = max(node[2*x+1], node[2*x+2]);
    }
  }
  ll getmax(int a, int b, int k=0, int l=0, int r=-1) {
    
    if(r < 0) r = n;

    if(r <= a || b <= l) return -INF;
    if(a <= l && r <= b) return node[k];

    ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
    ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
    return max(vl, vr);
  }

  ll getnode(int x){
    return node[n-1+x];
  }
  void shownode(int num){
    rep(i,num){
      cout << getnode(i+1) << endl;
    }
  }
};



int main(void){

  ll n;
  cin>>n;

  vector<ll> h(n);
  vector<ll> a(n);
  

  rep(i,n) cin>>h[i];

  rep(i,n) cin>>a[i];

  vector<ll> dp(200001,0LL);

  SegmentTree st(dp);

  rep(i,n){
    st.update(h[i],a[i]+st.getmax(1,h[i]+1));
    //st.update(h[i],a[i]);
    //cout << st.getnode(h[i]) << endl;

  }

  //st.shownode(n);

  cout << st.getmax(1,n+1) << endl;

  return 0;

}
