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

struct Tree{

  ll val;
  ll par;
  //ll col;
  vector<Tree*> child;
  //map<>

};


int main(void){

  ll n;
  cin>>n;
  vector<ll> u(n);
  vector<ll> v(n);
  vector<ll> w(n);

  UnionFind uf(n+1);

  auto pripare = [](const pair<ll,ll> x){
    cout << x.first << "," << x.second << endl;
  };

  //map(ll,vector<pair<ll,ll>>) m;

  //map(ll,vector<ll>)

  //vector<map<ll,ll>> next_map(n+1,map<ll,ll>());
  map<ll,map<ll,ll>> next_map;

  rep(i,n){
    cin>>u[i];
    cin>>v[i];
    cin>>w[i];

    //cout << u[i] << "," << v[i] << "," << w[i] << endl;

    next_map[ u[i] ][v[i]]=w[i];
    next_map[ v[i] ][u[i]]=w[i];

    /*
    if(w[i]%2==0){
      uf.unite( u[i],v[i] );
    }    

    else{
      m[i]=make_pair(u[i],v[i]);
    }
    */

  }
  //cout << "debug" << endl;

  vector<ll> ans(n+1);

  auto root = new Tree;
  root->val=1;
  root->par=0;

  queue<Tree*> que;
  que.push(root);
  ans[1]=0;

  while(que.size()>0){
    auto node=que.front();
    que.pop();
    //cout << node->val << endl;
    //cout << next_map[1].size() << endl;
    for(auto x: next_map[ node->val ]){
      //pripare(x);
      if(x.first==node->par) continue;
      else{
        
        auto tmp= new Tree;
        tmp->val=x.first;
        tmp->par=node->val;
        if(x.second%2!=0) tmp->col = 1-node->col;
        else tmp->col = node->col;
        ans[tmp->val]=tmp->col;
        node->child.push_back(tmp);

        que.push(tmp);

      }
    }

  }

  rep1(i,n) cout << ans[i] << endl;

  return 0;

}
