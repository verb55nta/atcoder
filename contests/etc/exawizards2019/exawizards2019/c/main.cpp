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


int main(void){

  ll n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  vector<char> t(q);
  vector<char> d(q);

  rep(i,q) {cin>>t[i]; cin>>d[i];}
  
  vector< vector<ll> > num_pos(26,vector<ll>(0));

  map<ll,ll> uni;
  rep(i,n){
    //uni.insert( make_pair(i,1) );
    uni[i]=1;
  }

  ll ans=0;

  
  rep(lr,2){
    //cout << "lr:" << lr << endl;
    ll l,r;
    l=0;
    r=n-1;
    ll cand;
    ll last;
    last=0;

    if(lr==0) cand=-1;
    else cand=n;
    
    while(l<=r && !last){
      //cout << l << "," << r << endl;
      ll comp;
      ll piv;

      if(l==r) last=1;
      
      comp=0;
      piv=(l+r)/2;

      ll cur;
      cur=piv;

      rep(i,q){

        if( t[i] == s[cur] ){

          if( d[i]=='L' ){
            if(cur==0){
              if(lr==0) comp=1;
              break;
            }
            else{
              cur--;
            }
          }
          else{
            if(cur==n-1){
              if(lr==1) comp=1;
              break;
            }
            else{
              cur++;
            }
          }

        }

      }
      if(lr==0){
        if(comp==1){
          //cout<< "0:" << piv << ",Hit!" << endl;
          cand=piv;
          l=piv+1;
        }
        else{
          //cout<< "0:" << piv << ",No hit" << endl;
          r=piv;
        }
      }
      else{
        if(comp==1){
          //cout<< "1:" << piv << ",Hit!" << endl;
          cand=piv;
          r=piv;
        }
        else{
          //cout<< "1:" << piv << ",No hit" << endl;
          l=piv+1;
        }
      }
      

    }
    //cout<< "cand:" << cand << endl;
    if(lr==0) ans+=cand+1;
    else ans+=n-cand;
    
  }
  //ans+=l;

  cout << n-ans << endl;

  return 0;

}
