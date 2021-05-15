#include <iostream>
#include <stack>
#include <set>
#include <string>
using namespace std;
#define MAXN 100000
struct timecomp{
    int c,k;
    char v;};
stack <timecomp>  ss;
set<char>  v;
timecomp ck;
int result;
int getcomp(string str)
{
    unsigned int i,j,num;
    num=i=0;
    while ( i< str.length() && str[i]!='O' )  i++;
    if(i<str.length()){
        if(str[i+1]=='('){
               j=i+2;
               if(str[j]!='1'){
                   j=j+2;
                  while( str[j]>='0'&&str[j]<='9'){
                     num = num*10 + str[j]-'0';
                     j++;
                  }
               }
               return num;
           }
    }
    return -1;
}
int getNumber(string str)
{
    unsigned int len,i,num;
    i=num=0;
    len=str.length();
    if(str[i]<='9'&&str[i]>='0')
       while(str[i]<='9'&&str[i]>='0'&&i < str.length())
           num= num*10+str[i]-'0',i++;
    else if(str[i]=='n')  num = MAXN;
    return num;
}
int checkStr(string str)
{
    int num1,num2;
    string s1;
    num1=num2=0;
    if( str[0]=='F' ){
        cin>>s1;
        if(s1[0]>='a'&&str[0]<='z')//判断变量名是否重名
           ck.v=s1[0],ck.k=0;
        cin>>s1;
        num1=getNumber(s1);
        cin>>s1;
        num2=getNumber(s1);
        if(num1>num2)  ck.c=-1;
        if(num1==num2)  ck.c=0;
        if(num1<num2){
            if ( num2-num1 > MAXN-1000 ) ck.c=1;
            else ck.c=0;
        }
        return 1;
    }
    if(str[0]=='E')  return 2;
    return 0;
}
int main()
{
    int t, row,ans;
    string str;
    cin>>t;
    for( ; t>0; t--) {
        while(!ss.empty())  ss.pop();
        v.clear();  cin>>row; cin>>str; result=0;
        ans = getcomp(str);
        if( ans==-1 ){
            cout<<"ERR 1" ;
            continue;
        }
        for(; row>0;row--){
            cin>>str;
            int x = checkStr(str);
            if(x==1) //1  F
            {
                if(v.count(ck.v)!=0)  result = -1;
               else v.insert(ck.v);
                ss.push(ck);
            }
            else  if(x==2)//2  E
            {
                if( ss.empty() ){
                    result=-1;
                    continue;
                }
                ck=ss.top();
                ss.pop();
                v.erase(ck.v);
                int y=ck.c+ck.k;
                if(!ss.empty())
                   { if( ( ck.c!=-1 )&& (ss.top().k<y))  ss.top().k=y;}
                else if((result !=-1)&&(result < y)&&(ck.c!=-1))  result = y;
            }
        }
        if(!ss.empty())  result = -1;
        if(result == -1 )  cout<<"ERR"<<endl;
        else if(result==ans)  cout<<"Yes"<<endl;
        else  cout<<"No"<<endl;
    }
    return 0;
}
