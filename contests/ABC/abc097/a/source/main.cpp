#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){

  int a,b,c,d;
  cin>>a;
  cin>>b;
  cin>>c;
  cin>>d;

  if(abs(c-a) <= d){

    cout << "Yes" << endl;
  }
  else if(abs(b-a) <= d and abs(c-b) <= d){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

  return 0;
}
