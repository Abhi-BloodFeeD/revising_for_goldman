#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair

//max_activity selection//
bool conv(pair<int,int>&a,pair<int,int>&b){
  if(a.second==b.second)return a.first<b.first;
  return a.second<b.second;
}
void max_activity(vector<pair<int,int>>&activitySet,vector<pair<int,int>>&resultSet)
{
  sort(activitySet.begin(),activitySet.end(),conv);
  resultSet.push_back(activitySet[0]);
  for(int i=1;i<(int)activitySet.size();i++)
  {
      int last = resultSet.size()-1;
      if(resultSet[last].second<=activitySet[i].first){
        resultSet.push_back(activitySet[i]);
      }
  }
}
int main() {

  //1----------4
  //   2---3
  //1-------------5
  //            4-----------8
vector<pair<int,int>>v;
v.pb({1,4});
v.pb({2,3});
v.pb({1,5});
v.pb({4,8});
vector<pair<int,int>>result;
max_activity(v,result);
for(auto x:result)cout<<x.first<<" "<<x.second<<endl;
return 0; 
} 

