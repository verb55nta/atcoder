/*Input Example

N
a1 b1
a2 b2
...
an-1 bn-1

N nodes, N-1 edges(because it is tree)
ak bk means make edges from ak to bk

*/

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


#define FACSIZE 2002

ll invfac[FACSIZE];
ll fac[FACSIZE];

ll mod_pow(ll ,ll );
ll mod_add(ll ,ll );
ll mod_mul(ll ,ll );
ll mod_div(ll ,ll );
void make_fact(ll );
void make_invfact(ll );


struct Tree{

  ll val;
  ll parent;
  unordered_set<Tree*> children;

};

vector< vector<ll> > edges;
void processInput();
Tree* initRoot(ll);
void make_tree(Tree*);
void bfs(Tree*);
void dfs(Tree*);


int main(void){

  processInput();
  auto root=initRoot(1);
  //cout << root->val << endl;
  make_tree(root);

  bfs(root);

  return 0;

}

void processInput(){
  ll n;
  cin>>n;

  edges.resize(n+1);

  rep(i,n-1){
    ll a,b;
    cin>>a>>b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
}

Tree* initRoot(ll x){
  Tree* root=new Tree;
  root->parent=0;
  root->val=x;

  return root;
}

void make_tree(Tree* root){

  queue<Tree*> que;
  que.push(root);

  //for(auto x:edges[]){}
  while(!que.empty()){
    auto node=que.front();
    que.pop();

    for(auto nextVal:edges[node->val]){
      if(nextVal!=node->parent){
        auto nextNode=new Tree;
        nextNode->val=nextVal;
        nextNode->parent=node->val;
        node->children.insert(nextNode);
        que.push(nextNode);
      }
    }

  }

}

void bfs( Tree* root ){
  using pa = pair<Tree*,ll>;
  queue<pa> que;
  que.push(make_pair(root,0));

  while(!que.empty()){
    auto node=que.front().first;
    auto depth=que.front().second;
    que.pop();
    cout << node->val <<","<< depth <<endl;
    for(auto n:node->children){
      que.push(make_pair(n,depth+1));
    }
  }

}