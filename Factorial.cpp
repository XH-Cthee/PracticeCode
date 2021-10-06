#include <iostream>
using namespace std;
/*
H-2
用递归和递推实现阶乘
并分析递推实现的时间复杂度
*/
//递归实现
/*int Factorial(int n){
    if(n<1){
        return 1;
    }
    else
    return Factorial(n-1)*n;
}
int main(){
    cout<<"递归实现的阶乘结果:"<<Factorial(3)<<endl;
    return 0;
}*/

//递推实现

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
	cout << "递推的结果为:" << factorial(n) <<endl;
	return 0;
}
/*
时间复杂度分析O(n^2)
因为递归得有去有回
看到for循环的i最多循环n次结束
空间复杂度O(n)
*/