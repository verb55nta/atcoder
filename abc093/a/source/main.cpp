#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(void){

  vector<char> c(3);

  for(int i=0;i<3;i++){
    cin>>c[i];
  }

  sort(c.begin(),c.end());

  if(c[0]=='a' and c[1]=='b' and c[2]=='c') cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
