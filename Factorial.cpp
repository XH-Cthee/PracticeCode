#include <iostream>
using namespace std;
/*
H-2
�õݹ�͵���ʵ�ֽ׳�
����������ʵ�ֵ�ʱ�临�Ӷ�
*/
//�ݹ�ʵ��
/*int Factorial(int n){
    if(n<1){
        return 1;
    }
    else
    return Factorial(n-1)*n;
}
int main(){
    cout<<"�ݹ�ʵ�ֵĽ׳˽��:"<<Factorial(3)<<endl;
    return 0;
}*/

//����ʵ��

long factorial(int n)
{
	long factorial= 1;         
	for(int i = 2; i <= n; i++){
	 factorial *= i;
    }
    return factorial;
}
 
int main()
{
	int n;
	cin >> n;
	cout << "���ƵĽ��Ϊ:" << factorial(n) <<endl;
	return 0;
}
/*
ʱ�临�Ӷȷ���O(n^2)
��Ϊ�ݹ����ȥ�л�
����forѭ����i���ѭ��n�ν���
�ռ临�Ӷ�O(n)
*/