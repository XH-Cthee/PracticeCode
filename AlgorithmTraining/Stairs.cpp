/*n
台阶问题
f(n)=f(n-1)+f(n-2)
*/
#include <iostream>
#include <cstdio>
using namespace std;
//递归实现
/*int Stairs(int n){
    if(n==1){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    else{
        return Stairs(n-1)+Stairs(n-2);
    }
}
int main(){
    cout<<"十阶楼梯的走法: "<<Stairs(10)<<endl;
    return 0;
}*/


//递推实现
int Stairs(int n){
int f[50];
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 2] + f[i - 1];
        
    }
    return f[n];
}

int main(){
    int n;
    cin >> n;
    cout << Stairs(n)<<endl;
    return 0;
}
//时间复杂度O(n)-当n=1/=2只有O(1),其他大于n>1时,都是循环了n次
//空间复杂度O(n)
//i循环到n次结束