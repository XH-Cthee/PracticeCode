/*
汉诺塔问题
n=0时不需要操作
n>=0时
①把n-1个盘子移到C柱
②把n个盘子中最大的移动到B柱
③把n-1个盘子从C柱移到B柱
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
        num++;//移动次数加一
        Hannota(n-1,c,b,a);
    }
    return 0;
}
int main(){
    int n;
    cout<<"汉诺塔层数: "<<endl;
    cin>>n;
    Hannota(n,'A','B','C');
    cout<<"移动了"<<num<<"次"<<endl;
    return 0;
}