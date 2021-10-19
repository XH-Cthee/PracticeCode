/*
N=a[1]+a[2]+a[3]+...+a[m];
a[i]>0,1<=m<=N;
对于一个正整数，求解满足上面公式的所有算式组合
*/

//着实没看懂
#include<iostream>
using namespace std;
 
int sum = 0;
 
/**
m=1,交换加数的位置视为不同的分解方案
调用时，count = 0
*/
void dfs1(int n,int count,int*p)
{
	if(n==0){ //得到一组解
		cout<<sum<<"=";
		for(int i=0;i<count;i++)
			if(i==count-1)
				cout<<p[i]<<endl;
			else
				cout<<p[i]<<"+";
		return;//返回上一层
	}
	for(int i=1;i<=n;i++){
		p[count]=i;
		dfs1(n-i,count+1,p);
	}
	return;
}
 
/*
m=2,交换加数的位置视为相同的分解方案
调用时，count = 0 得到解的次数
*/
void dfs2(int n,int count,int*p)
{
	if(n==0){ 
		cout<<sum<<"=";
		for(int i=0;i<count;i++)
			if(i==count-1)
				cout<<p[i]<<endl;//试探数组
			else
				cout<<p[i]<<"+";
		return;
	}
	int k = count>0 ? p[count-1] : 1; //数组中的数应该非递减的顺序
	for(int i=k;i<=n;i++){
		p[count] = i;
		dfs2(n-i,count+1,p);
	}
}
 
 
 
int main()
{
	int n,m;
	cin>>n>>m;
	sum = n;
	int* p = new int[n];
	if(m==1)
		dfs1(n,0,p);
	else if(m==2)
		dfs2(n,0,p);
	return 0;
}
