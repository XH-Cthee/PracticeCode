/*n
̨������
f(n)=f(n-1)+f(n-2)
*/
#include <iostream>
#include <cstdio>
using namespace std;
//�ݹ�ʵ��
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
    cout<<"ʮ��¥�ݵ��߷�: "<<Stairs(10)<<endl;
    return 0;
}*/


//����ʵ��
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
//ʱ�临�Ӷ�O(n)-��n=1/=2ֻ��O(1),��������n>1ʱ,����ѭ����n��
//�ռ临�Ӷ�O(n)
//iѭ����n�ν���