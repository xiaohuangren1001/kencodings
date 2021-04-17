#include<iostream>
#include <cmath>
#include<algorithm>
using namespace std;
struct zhiyuanzhe{
	int num;
	int chengji;
};
int cmp(zhiyuanzhe p1,zhiyuanzhe p2){
	if(p1.chengji>p2.chengji){
		return true;
	}
	else if(p1.chengji==p2.chengji){
		if(p1.num<p2.num)return true;
		else return false;
	}
	else return false;
}
int main(){
	int n,m;
	cin>>n>>m;
	m=floor(m*1.5);
	zhiyuanzhe people[n];
	for(int i=0;i<n;i++){
		cin>>people[i].num>>people[i].chengji;
	}
	sort(people,people+n,cmp);
	int fenshuxian=people[m-1].chengji;
	int renshu=m;
	for(int i=m;i<n;i++){
		if(people[i].chengji==fenshuxian)renshu+=1;
		else if(people[i].chengji<fenshuxian)break;
	}
	cout<<fenshuxian<<" "<<renshu<<endl;
	for(int i=0;i<renshu;i++){
		cout<<people[i].num<<" "<<people[i].chengji<<endl;
	}
	return 0;
} 
