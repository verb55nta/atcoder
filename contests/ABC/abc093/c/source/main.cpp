#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>

using namespace std;

int main(void){

  int a,b,c;

  vector<int> num(3);
  
  int n1,n2;

  cin>>num[0];
  cin>>num[1];
  cin>>num[2];

  sort(num.begin(),num.end());
  
  n1=num[1]-num[0];
  n2=num[2]-num[0];

  if(n1%2==0){
    cout << n2 - n1/2 << endl;
  }
  else{
    cout << n2 - n1/2 + 3/2 << endl;
  }
  
  return 0;
}
