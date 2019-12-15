#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<cstdint>
#include<queue>
#include<set>
#include<map>

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

ll encode(ll a,ll b,ll c){
  return a+1001LL*b+1001LL*1001LL*c;
}

ll decode_a(ll num){

  return num%1001LL;

}

ll decode_b(ll num){

  return (num/1001LL)%1001LL;

}

ll decode_c(ll num){

  return (num/(1001LL*1001LL))%1001LL;

}

typedef pair<ll,ll> pi;

int main(void){

  ll x,y,z,k;
  cin>>x>>y>>z>>k;

  vector<ll> a(x);
  vector<ll> b(y);
  vector<ll> c(z);

  rep(i,x) cin>>a[i];
  rep(i,y) cin>>b[i];
  rep(i,z) cin>>c[i];

  sort(all(a),greater<ll>());
  sort(all(b),greater<ll>());
  sort(all(c),greater<ll>());

  set<pi,greater<pi>> sss;
  priority_queue<pi> que;
  
  pair<ll,ll> tmp;

  tmp.second=0;
  tmp.first=a[0]+b[0]+c[0];

  //sss.insert(tmp);
  que.push(tmp);
  map<ll,ll> check;

  rep(i,k){
    //pair<ll,ll> q=*(sss.begin());
    auto q=que.top();
    //sss.erase(q);
    que.pop();

    cout << q.first << endl;
    
    ll _a=decode_a(q.second);
    ll _b=decode_b(q.second);
    ll _c=decode_c(q.second);

    if(_a+1<x && check.count(encode(_a+1,_b,_c))==0){
      //sss.insert( make_pair( a[_a+1]+b[_b]+c[_c],encode(_a+1,_b,_c) ) );
      que.push( make_pair( a[_a+1]+b[_b]+c[_c],encode(_a+1,_b,_c) ) );
      check[encode(_a+1,_b,_c)]=1;
    }
    if(_b+1<y && check.count(encode(_a,_b+1,_c))==0){
      //sss.insert( make_pair( a[_a]+b[_b+1]+c[_c],encode(_a,_b+1,_c) ) );
      que.push( make_pair( a[_a]+b[_b+1]+c[_c],encode(_a,_b+1,_c) ) );
      check[encode(_a,_b+1,_c)]=1;
    } 
    if(_c+1<z && check.count(encode(_a,_b,_c+1))==0){
      //sss.insert( make_pair( a[_a]+b[_b]+c[_c+1],encode(_a,_b,_c+1) ) );
      que.push( make_pair( a[_a]+b[_b]+c[_c+1],encode(_a,_b,_c+1) ) );
      check[encode(_a,_b,_c+1)]=1;

    } 

  }


  return 0;

}
