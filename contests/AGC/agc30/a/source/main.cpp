#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){
  int a,b,c;
  cin>>a>>b>>c;
  //cout <<a<<b<<c<<endl;

  //cout << a+b+b
  //cout << min(a+b,c)+b << endl;
  if(a+b>=c) cout << b+c << endl;
  else{
    cout << a+2*b+1 << endl;
  }

  return 0;
}
