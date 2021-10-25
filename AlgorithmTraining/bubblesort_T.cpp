#include <iostream>
#include <math.h>

using namespace std;

bool bubbleSort(int array[], size_t arrLen) {
    if (arrLen < 0) {//数组长度小于0就返回错误
        cout << "Please check your input." << endl;
        return false;
    }


    for (int orderedNum = 0; orderedNum < arrLen; ++orderedNum) {
        bool isExchanged = false;
        for (int i = 0; i < arrLen - orderedNum -1; ++i) {//每排完一次最右边的就是最大的数 所有要减1
            if (array[i] > array[i+1]) {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;//把大的值往后面放
                isExchanged = true;//发生交换
            }
        }
        if (!isExchanged) {//如果没有发生数据交换就退出循环
            break;
        }
    }
    return true;
}

bool bubbleSort_Sheng(int array[], size_t arrLen) {
    if (arrLen < 0) {
        cout << "Please check your input." << endl;
        return false;
    }
    int orderedNum = 0;
    while (true) {
        bool isExchanged = false;
        for (int i = 0; i < arrLen - orderedNum -1; ++i) {
            if (array[i] > array[i+1]) {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;//把大的数往右边放
                isExchanged = true;//发生数据交换
            }
        }

        if (!isExchanged) {
            break;//没有交换就退出循环
        }

        ++orderedNum;//最左边的数
    }
    return true;
}

void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int array0[] = {};
    int arrayLen = sizeof(array0)/sizeof(int);//求数组长度

    printArray(array0, arrayLen);//原数组
    bubbleSort(array0, arrayLen);//冒泡排序
    printArray(array0, arrayLen);//排序后的数组

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    bubbleSort_Sheng(array1, arrayLen);
    printArray(array1, arrayLen);

    cout << "=========================================" << endl;

    int array2[] = {2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    bubbleSort(array2, arrayLen);
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    int array3[] = {1, 5, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    bubbleSort_Sheng(array3, arrayLen);
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    int array4[] = {9, 12, 8, 7};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    bubbleSort(array4, arrayLen);
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    int array5[] = {9, 12, 8, 7, 3};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    bubbleSort_Sheng(array5, arrayLen);
    printArray(array5, arrayLen);


}