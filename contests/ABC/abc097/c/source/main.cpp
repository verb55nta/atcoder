#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;



int main(void){

  string s;
  cin >> s;
  int k;
  cin >> k;

  int k_cnt;

  int c[26][5001];

  for(int i=0;i<26;i++){
      for(int j=0;j<26;j++){
        c[i][j]=0;
      }
  }

  for(int i=0;i < s.size();i++){
    c[s[i]-'a'][0]++;
    c[s[i]-'a'][c[s[i]-'a'][0]]=i;
  }

  for(int i=0;i < 26;i++){
    if(c[s[i]-'a'][0] > 0){
      for(int j=0;j<c[s[i]-'a'][0];j++){



      }
    }
  }

  return 0;
}
