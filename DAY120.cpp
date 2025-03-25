#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class person{
    public:
    int age;
    string name;
    //for sorting
    bool operator<(const person &other)const{
        return age<other.age;
    }
};
int main() {
   //pair<string,int>p;
   //   p=make_pair("rohit",30);
   //   cout<<p.first<<" "<<p.second<<end;
   //p.first="sahil;";
   //p.second=20;
   // cout<<p.first<<" "<<p.second<<endl;
   //NAME AGE WEIGHT
  // pair<string,pair<int,int>>p;
   //   p.first="rohit";
//   p.second.first=21;
//   p.second.second=60;
//   p=make_pair("rohit",make_pair(21,35));
//   cout<<p.first<<" "<<p.second.first<<" " <<p.second.second<<endl;
 //list<int>l;
  //5 10 20 30 
//   l.push_back(20);
//   l.push_back(30);
//   l.push_back(40);
//   l.push_front(10);
//   l.push_front(5);
//   l.pop_back();
//   cout<<l.front()<<" "<<l.back();
//   cout<<"\n"<<l.size()<<"\n";
//   //ITERATOR
//   for(auto it=l.begin();it!=l.end();it++){
//       cout<<*it<<" ";
//   }
//   cout<<endl;
//   for(auto it=l.rbegin();it!=l.rend();it++){
//       cout<<*it<<" ";
//   }
     //set<int>s;
    //  set<int,greater<int>>s;
    //  s.insert(10);
    //  s.insert(20);
    //  s.insert(30);
    //  s.insert(40);
    //  s.insert(50);
    //  s.insert(20);
    //  for(auto it=s.begin();it!=s.end();it++){
    //      cout<<*it<<" ";
    //  }
     //search e;ement
    //  if(s.find(20)!=s.end()){
    //      cout<<"found";
    //  }else{
    //      cout<<"not found";
    //  }
    //  if(s.count(200)){
    //      cout<<"present";
    //  }else{
    //      cout<<"not present";
    //  }
    //  s.erase(10);
    //  cout<<"\n"<<s.count(10);
    //  set<person>s;
    //  person p1,p2,p3;
    //  p1.age=10;
    //  p1.name="harsh";
    //  p2.age=20;
    //  p2.name="parsh";
    //  p3.age=30;
    //  p3.name="shivam";
    //  s.insert(p1);
    //  s.insert(p2);
    //  s.insert(p3);
    //  for(auto it=s.begin();it!=s.end();it++){
    //      cout<<(*it).age<<" "<<(*it).name<<endl;
    //  }
    // multiset<int>s;
    // s.insert(10);
    // s.insert(10);
    // s.insert(10);
    // s.insert(10);
    // s.insert(20);
    // s.erase(10);
    // for(auto it=s.begin();it!=s.end();it++){
    //      cout<<*it<<" ";
    //  }
    // unordered_set<int>s;
    // s.insert(10);
    // s.insert(10);
    // s.insert(20);
    // s.insert(30);
    // for(auto it=s.begin();it!=s.end();it++){
    //      cout<<*it<<" ";
    //  }
    // map<int,int>m;
    // m.insert(make_pair(20,30));
    // m.insert(make_pair(30,310));
    // m.insert(make_pair(40,230));
    // m.insert(make_pair(20,230));
    // m.insert(make_pair(50,30));
    // m[100]=60;
    // for(auto it=m.begin();it!=m.end();it++){
    //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // }
    // if(m.count(1000))
    // cout<<m[1000];
    // multimap<int,int>m;
    // m.insert(make_pair(20,30));
    // m.insert(make_pair(30,310));
    // m.insert(make_pair(40,230));
    // m.insert(make_pair(20,230));
    // m.insert(make_pair(50,30));
    // for(auto it=m.begin();it!=m.end();it++){
    //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // }
    // unordered_map<int,int>m;
    // m.insert(make_pair(20,30));
    // m.insert(make_pair(30,310));
    // m.insert(make_pair(40,230));
    // m.insert(make_pair(20,230));
    // m.insert(make_pair(50,30));
    // for(auto it=m.begin();it!=m.end();it++){
    //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // }
    unordered_multimap<int,int>m;
    m.insert(make_pair(20,30));
    m.insert(make_pair(30,310));
    m.insert(make_pair(40,230));
    m.insert(make_pair(20,230));
    m.insert(make_pair(50,30));
    for(auto it=m.begin();it!=m.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
   return 0;
}
