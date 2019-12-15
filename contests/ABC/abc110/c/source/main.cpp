#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){
  string s,t;
  cin >> s;
  cin >> t;

  vector<char> h_s(26,-1);
  vector<char> h_t(26,-1);
  //cout << s << endl;
  //cout << t << endl;

  for(int i=0;i<s.size();i++){
    int ss=s[i]-'a';
    int tt=t[i]-'a';
    if(h_s[ss] >= 0){
      if(h_s[ss] != t[i]){
        cout << "No" <<endl;
        return 0;
      }
    }
    else if(h_t[tt] >= 0){
      if(h_t[tt] != s[i]){
        cout << "No" <<endl;
        return 0;
      }
    }
    else{
      h_s[ss] = t[i];
      h_t[tt] = s[i];
    }
    //if(s[i] == t[i]) continue;
    //else{
      /*
      if( h[s[i]-'a'] ){
        cout << "No" << endl;
        return 0;
      }

      else{
        h[s[i]-'a']=1;
      }
      */
      //char c1=s[i];
      //char c2=t[i];
      //cout << c1 << " " << c2 << endl;
      /*
      for(int j=0;j<s.size();j++){

        if(s[j] == c1) s[j]=c2;
        else if(s[j] == c2) s[j]=c1;

      }
      */
      //replace(s.begin(),s.end(),c1,c2);
      //replace(s.begin(),s.end(),c2,c1);
    //}


  }
  //if(s==t) cout << "Yes" << endl;
  //else cout << "No" << endl;
  cout << "Yes" << endl;
  //cout << s << endl;
  //cout << "Yes" << endl;

  return 0;
}
