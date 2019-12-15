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

  vector<uif> a(4);
  for(uif i=0;i<4;i++){
    cin>>a[i];
  }

  sort(a.begin(),a.end());

  if(a[0]==1 && a[1] == 4 && a[2] == 7 && a[3] == 9){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;

  }

  return 0;
}
