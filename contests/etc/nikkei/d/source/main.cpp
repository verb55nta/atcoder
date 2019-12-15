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
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((ll)(x).size())
#define bit(n) (1LL<<(n))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

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

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(void){

  ll n,m;
  cin>>n>>m;
  vector<ll> a(n+m-1);
  vector<ll> b(n+m-1);

  vector< vector<ll> > node(n+1,vector<ll>(0));

  rep(i,n+m-1){
    cin>>a[i];
    cin>>b[i];
    node[b[i]].pb(a[i]);
  }
/*
  rep(i,n){
    if(i==0) continue;
    cout << "i:" << i << " " << endl;
    for(auto x:node[i]){
      cout << x << " ";
    }
    cout << endl;
  }
*/
  ll r=0;
  vector<ll> dup_l(0);
  rep(i,n+1){
    if(i==0) continue;
    //cout << node[i].size() << endl;
    if(node[i].size() == 0){
      r=i;
    }
    else if(node[i].size() >1){
      dup_l.pb(i);
    }
  }
  struct UnionFind t(n+1);
  rep(i,n+1){
    if(i==0) continue;
    cout << t.root(i) << endl;
  }
  rep(i,n+m-1){
    if(node[b[i]].size() == 1){
      //cout << a[i] << "," << b[i] << endl;
      t.unite(a[i],b[i]);
    }
  }
  cout << endl;
  cout << t.root(r) << endl;
  rep(i,dup_l.size()){
    cout << "dup_l[i]:" << dup_l[i] << "...";
    for(auto x: node[dup_l[i]]){
      cout << t.root(x) << "" ;
    }
    cout << endl;
  }

  //cout << endl;
  /*
  rep(i,n+1){
    if(i==0) continue;
    cout << t.root(i) << endl;
  }
  */
  /*
  cout << root << endl;
  for(auto x:dup_l){
    cout << x << endl;
  }
  */



  return 0;
}
