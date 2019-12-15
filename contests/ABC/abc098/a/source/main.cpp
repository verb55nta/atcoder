#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){
  int A,B;
  cin>>A;
  cin>>B;
  cout << max({A+B,A-B,A*B}) << endl;
  return 0;
}
