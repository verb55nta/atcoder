#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<cstdint>

using namespace std;

using uif=uint_fast64_t;

int main(void){

  string s;
  cin>>s;

  char name[]="keyence";

  //cout << s.substr(0,7) << endl;
  //cout << s.substr(s.size()-7,7) << endl;

  if( s.substr(0,7) == "keyence" || s.substr(s.size()-7,7) == "keyence" ){
    cout << "YES"<< endl;
    return 0;
  }
  else{
    uif f=0;
    uif b=0;

    for(uif i=0;i<7;i++){
      //cout << s[i] << "," << name[i] << endl;
      if( s[i] == name[i] ){
        f++;
      }
      else{
        break;
      }
    }
    //cout << f << endl;
    for(uif i=0;i<7;i++){
      //cout << s[s.size()-1-i] << "," << name[6-i] << endl;
      if( s[s.size()-1-i ] == name[6-i] ){
        b++;
      }
      else{
        break;
      }
    }
    //cout << b << endl;
    if(f+b>=7){
      cout << "YES"<< endl;
    }
    else{
      cout << "NO"<< endl;
    }

  }


  return 0;
}
