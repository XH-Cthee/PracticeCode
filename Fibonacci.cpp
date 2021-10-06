#include <iostream>
using namespace std;
/*
H-3
用递归和递推实现斐波那契数列
f(n)=f(n-1)+f(n-2);
并对递推实现的进行时间复杂度分析
*/
/*int Fibonacci(int n){
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
    cout<<"输出个数: "<<endl;
    cin>>l;
    for( i=0;i<l;++i){
        cout<<Fibonacci(i)<<" ";
    }
    return 0;
}*/

//递推解决
int Fibonacci(int n){ 
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
    //cout<<"输出个数: "<<endl;
    //cin>>n;
    cout<<Fibonacci(10)<<endl;
}
//时间复杂度为O(n);
//i循环n次结束
