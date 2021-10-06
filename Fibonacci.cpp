#include <iostream>
using namespace std;
/*
H-3
递归与递推实现斐波那契数列
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
    cout<<"输出个数: "<<endl;
    cin>>l;
    for( i=1;i<=l;++i){
        cout<<Fibonacci(i)<<" ";
    }
    return 0;
}

//递推实现
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
    //cout<<"输出个数: "<<endl;
    //cin>>n;
    cout<<Fibonacci(8)<<endl;
}*/
//时间复杂度O(2^n)
/*
假设n=4，就有f(4)=f(3)+f(3),3又可以分成f(2)+f(1);
就有2^0+2^1+...最后取关系最大的2^n
*/
//空间复杂度O(n)
