#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(void){

  int A,B,X;

  cin >> A;
  cin >> B;
  cin >> X;

  if(A+B-X >= 0 and X>=A ) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}
