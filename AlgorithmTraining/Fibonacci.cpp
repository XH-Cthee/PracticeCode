#include <iostream>
using namespace std;
/*
H-3
�ݹ������ʵ��쳲���������
f(n)=f(n-1)+f(n-2);

*/
int Fibonacci(int n){
    if(n<0){
        return 0;
    }
    else if(n == 1||n == 2){
        return 1;
    }
    else
    {
        return Fibonacci(n-2)+Fibonacci(n-1);
    }
}
int main(){
    int i,l;
    cout<<"�������: "<<endl;
    cin>>l;
    for( i=1;i<=l;++i){
        cout<<Fibonacci(i)<<" ";
    }
    return 0;
}

//����ʵ��
/*int Fibonacci(int n){ 
    if(n<0){
        return 0;
    }
    else if(n == 1||n == 2){
        return 1;
    }
    int a0=1,a1=1;
     int temp;

    for( int i=3;i<=n;++i){
        temp=a0;
        a0=a1;
        a1=temp+a0;
        cout<<a1<<" ";
    }
    return a1;
}
int main(){
    //int n;
    //cout<<"�������: "<<endl;
    //cin>>n;
    cout<<Fibonacci(8)<<endl;
}*/
//ʱ�临�Ӷ�O(2^n)
/*
����n=4������f(4)=f(3)+f(3),3�ֿ��Էֳ�f(2)+f(1);
����2^0+2^1+...���ȡ��ϵ����2^n
*/
//�ռ临�Ӷ�O(n)
