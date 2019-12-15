#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<numeric>

using namespace std;

int main(void){

  string s;

  cin>>s;

  vector<unsigned long long> res_b(1);
  res_b[0]=0;
  unsigned long long tmp=0;
  unsigned long long val=0;
  for(int i=0;i<s.length();i++){
    if(s[i] == 'B'){
      tmp++;
    }
    else if(s[i] == 'W'){
      //res_b.push_back(tmp);
      val+=tmp;
    }
  }


  //cout << (unsigned long long)accumulate(res_b.begin(),res_b.end(),0) << endl;
  cout << val << endl;

  return 0;
}
