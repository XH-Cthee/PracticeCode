/*
�õݹ�͵����жϻ����ַ���
��һ�������һ���ַ���ȣ���ȥ����ʣ����Ȼ�ǻ���
����ʣ��һ�����߸պ�û��
*/
#include <iostream>
#include <cstring>
using namespace std;
//�ݹ�ʵ��
/*int BackString(char *str,int first,int end,int length){
    if(length==1||length==0){
       cout<<"�ǻ����ַ���"<<endl;
       return 1;
    }
    else if(str[first]!=str[end]){
       cout<<"���ǻ����ַ���"<<endl;
       return 0;
    }
    else{
        return BackString(str,first+1,end-1,length-2);
    }
}
int main(){
    char str[]="aaabaaa";
    int  length = strlen(str);
    cout<<BackString(str,0,length-1,length)<<endl;
    return 0;
}*/

//����ʵ��
bool BackString(char *str){
    int i;
    int length = strlen(str);
    if(length%2==1){
        for(i=0;i<=(length-1)/2;++i){
            if(str[i]==str[length-1-i]){
            }
            else{
                return false;
            }
        }
    }
    else{
        for(i=0;i<=(length-1)/2;++i){
            if(str[i]==str[length-1-i]){
            }
            else{
                return false;
            }
        }
    }
    return true;
}
int main(){
    char str[]="ccbcc";
    if(BackString(str)==true){
        cout<<"�ǻ����ַ���"<<endl;
    }
    else{
        cout<<"���ǻ����ַ���"<<endl;
    }
    return 0;
}
//ʱ�临�Ӷ�o(n^2)
//�����ַ����ĳ���/2  �ٽ���ǰ���ж���