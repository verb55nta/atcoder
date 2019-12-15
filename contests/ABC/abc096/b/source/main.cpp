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
  int k;

  cin>>a;
  cin>>b;
  cin>>c;
  cin>>k;

  int sum=a+b+c;

  cout << (long long int)(max({a,b,c})*pow(2,k)+sum-max({a,b,c})) << endl;
  
  return 0;
}
