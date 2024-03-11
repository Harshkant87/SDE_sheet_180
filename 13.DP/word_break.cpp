#include<bits/stdc++.h>
int isPresent(string& subString,vector<string> &dict){

    if(find(dict.begin(),dict.end(),subString)!=dict.end()){
        return 1;
    }
    return 0;
}

void func(int startIndex,string subS,vector<string>&ans,string &s, vector<string> &dict){
       if(startIndex==s.size()){
           ans.push_back(subS);
           return ;
       }

    for(int i=startIndex;i<s.size();i++){
        string subString= s.substr(startIndex,i-startIndex+1);
        if(isPresent(subString,dict)){
            func(i+1,subS+subString+" ",ans,s,dict);
        }
    }
}

vector<string> getAllValidSentences(string &s, vector<string> &dict)
{
     string subS="";
     vector<string>ans;

     func(0,subS,ans,s,dict);

     return ans;

}