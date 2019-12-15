#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<cstdint>
#include<numeric>

using namespace std;

using uif=uint_fast64_t;
using ll=long long int;

int main(void){

  uif n;
  cin>>n;

  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);
  vector<ll> d(n);
  uif a_sum=0;
  uif b_sum=0;

  for(uif i=0;i<n;i++){
    cin>>a[i];
    a_sum+=a[i];
  }
  for(uif i=0;i<n;i++){
    cin>>b[i];
    b_sum+=b[i];
    c[i]=0;
    d[i] = a[i]-b[i];
  }
  //ll a_sum=accumulate(a.begin(),a.end(),0);
  //ll b_sum=accumulate(b.begin(),b.end(),0);
  //cout << a_sum << "," << b_sum << endl;
  if( a_sum < b_sum ){
    cout << -1 << endl;
    return 0;
  }
  else{
    sort(d.begin(),d.end());
    if(d[0] >= 0){
      cout << 0 << endl;
      return 0;
    }
    else{
      ll cnt=0;
      ll neg=0;
      for(uif i=0;i<n;i++){
        if(d[i]<0){
          neg+=d[i];
          cnt++;
        }
        else{
          break;
        }
      }
      for(uif i=d.size()-1;i>0;i--){
        if(neg<0){
          neg+=d[i];
          cnt++;
        }
        else{
          break;
        }
      }
      cout << cnt << endl;
    }
  }

  return 0;
}
