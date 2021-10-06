/*
N=a[1]+a[2]+a[3]+...+a[m];
a[i]>0,1<=m<=N;
����һ��������������������湫ʽ��������ʽ���
*/

//��ʵû����
#include<iostream>
using namespace std;
 
int sum = 0;
 
/**
m=1,����������λ����Ϊ��ͬ�ķֽⷽ��
����ʱ��count = 0
*/
void dfs1(int n,int count,int*p)
{
	if(n==0){ //�õ�һ���
		cout<<sum<<"=";
		for(int i=0;i<count;i++)
			if(i==count-1)
				cout<<p[i]<<endl;
			else
				cout<<p[i]<<"+";
		return;//������һ��
	}
	for(int i=1;i<=n;i++){
		p[count]=i;
		dfs1(n-i,count+1,p);
	}
	return;
}
 
/*
m=2,����������λ����Ϊ��ͬ�ķֽⷽ��
����ʱ��count = 0 �õ���Ĵ���
*/
void dfs2(int n,int count,int*p)
{
	if(n==0){ 
		cout<<sum<<"=";
		for(int i=0;i<count;i++)
			if(i==count-1)
				cout<<p[i]<<endl;//��̽����
			else
				cout<<p[i]<<"+";
		return;
	}
	int k = count>0 ? p[count-1] : 1; //�����е���Ӧ�÷ǵݼ���˳��
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
