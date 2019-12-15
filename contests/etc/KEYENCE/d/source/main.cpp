#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<cstdint>

using namespace std;

using uif=uint_fast64_t;

int main(void){

  uif n,m;
  cin>>n;
  cin>>m;
  vector<uif> a(n);
  vector<uif> b(m);
  for(uif i=0;i<n;i++){
    cin>>a[i];
  }
  for(uif i=0;i<m;i++){
    cin>>b[i];
  }



  return 0;
}
