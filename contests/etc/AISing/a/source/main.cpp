#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){
  int n,h,w;
  cin>>n;
  cin>>h;
  cin>>w;

  cout << (n-h+1)*(n-w+1) << endl;

  return 0;
}
