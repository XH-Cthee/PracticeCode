/*
��ŵ������
n=0ʱ����Ҫ����
n>=0ʱ
�ٰ�n-1�������Ƶ�C��
�ڰ�n�������������ƶ���B��
�۰�n-1�����Ӵ�C���Ƶ�B��
F(n)=F(n-1)+1+F(n-1)
*/
#include <iostream>
using namespace std;
int num=0;

int Hannota(int n,char a,char b,char c){
    if(n==0){
    }
    else{
        Hannota(n-1,a,c,b);
        num++;//�ƶ�������һ
        Hannota(n-1,c,b,a);
    }
    return 0;
}
int main(){
    int n;
    cout<<"��ŵ������: "<<endl;
    cin>>n;
    Hannota(n,'A','B','C');
    cout<<"�ƶ���"<<num<<"��"<<endl;
    return 0;
}