#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(void){

  string str;
  int arr[26];
  char c=0;

  cin >> str;

  //cout << str.length() << endl;
  for(int i=0;i<26;i++){
    arr[i]=0;
  }

  for(int i=0;i<str.length();i++){
    //cout << str[i] << endl;
    arr[str[i]-'a']=1;
  }

  for(int i=0;i<26;i++){
    //cout << arr[i] << endl;
    if(arr[i] == 0){
      c='a'+i;
      break;
    }
  }

  if(c==0){
    //cout << "zero" << endl;
    if(str=="zyxwvutsrqponmlkjihgfedcba"){
      cout << -1 << endl;
    }
    else{
      char pre;
      pre=str[25];
      for(int i=24;i>=0;i--){
	//cout << pre << "," << str[i] << endl;	
	if(pre > str[i]){
	  char add_c=0;
	  //pre=str[i]+1;
	  ///*
	  //cout << i << endl;
	  //cout << str[i] << endl;
	  for(int j=0;j<26;j++){
	    if(j < str[i]+1-'a') arr[j]=1;
	    else arr[j]=0;
	  }
	  for(int j=0;j<i;j++){
	    //cout << str[j] << endl;
	    arr[str[j]-'a']=1;
	  }
	  for(int j=0;j<26;j++){
	    //cout <<j <<"," <<arr[j] << endl;
	  }	  
	  for(int j=0;j<26;j++){
	    //arr[str[j]-'a']=1;
	    //cout << arr[j] << endl;
	    if(arr[j] == 0){
	      add_c=j+'a';
	      //cout << add_c << endl;
	      break;
	    }
	  }
	  //*/	  
	  cout << str.substr(0,i)+add_c << endl;
	  break;
	}
	else pre=str[i];
      }
    }
  }
  else{
    //cout << c << endl;
    cout << str+c << endl;
    //for(int i=0;i<str.length();i++){
    //if(str[i])
    //}
  }
  
  return 0;
}
