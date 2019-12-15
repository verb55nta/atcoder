#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){
  string c;
  int num=0;
  cin>>c;
  for(int i=0;i<4;i++){
    if(c[i]=='+') num++;
    else num--;
  }
  cout << num << endl;
  return 0;
}
