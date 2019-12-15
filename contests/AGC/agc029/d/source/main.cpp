#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){

  int h,w,n;
  cin>>h;
  cin>>w;
  cin>>n;
  //cout << h << w << n << endl;
  vector<pair<int,int> > pos(0);
  //vector<pair<int,int> > d(n);
  for(int i=0;i<n;i++){
    //cin >> pos[i].first;
    //cin >> pos[i].second;
    int x,y;
    //cin >> pos[i].second;
    cin >> x;
    cin >> y;
    if(x>=y) pos.push_back(make_pair(x,y));
    //cin >> pos[i].first;
    //d[i].first=pos[i].second;
    //d[i].second=pos[i].first;
    //cout << pos[i].first << "," << pos[i].second << endl;
  }
  if(n==0){
    cout << h << endl;
    return 0;
  }
  sort(pos.begin(),pos.end());
  //sort(d.begin(),d.end());

  for(int i=0;i<pos.size();i++){
    //cout << pos[i].first << "," << pos[i].second << endl;
  }

  int x=1,y=1;
  int ans=h;
  for(auto c:pos){
    if(c.first - x > c.second -y){
      ans=c.first -1;
      break;
    }
    else if(c.first -x == c.second -y){
      x=c.first;
      y=c.second-1;
    }
  }
  cout << ans << endl;

  return 0;
}
