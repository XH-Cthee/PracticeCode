#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

int partition(int array[], size_t arrStart, size_t pivot, size_t arrEnd) {
   int arrayLen = arrEnd - arrStart;

   if ( arrayLen < 1 || pivot < arrStart || pivot >= arrEnd) {
       cout << "Please check your implementation." << endl;
       return -1;//数组长度小于1或者pivot超出数组第一个位置和最后一个位置就返回错误
   }
   int pivotValue = array[pivot];//定义pviot的值
   array[pivot] = array[arrEnd - 1];//待排序的数组
   int pivotPos = arrStart;//定义数组第一个位置
   int temp;//临时变量

   for (int i = arrStart; i < arrEnd - 1; ++i)
   {
       if (array[i] < pivotValue) {//数组的值比pviot的值小就与其交换位置放到左边
          temp = array[pivotPos];
          array[pivotPos] = array[i];
          array[i] = temp;
          ++pivotPos;//pviot的位置往后移动
       }
   }
   array[arrEnd - 1] = array[pivotPos];//剩下pviot后面还没有比较的数组
   array[pivotPos] = pivotValue;//pviot的值不变

   return pivotPos;
}
bool quickSort(int array[], size_t arrStart, size_t arrEnd) {
    int arrLen = arrEnd - arrStart;//数组长度
    if (arrLen < 0) {
        cout << "Please check your input." << endl;
        return false;
    }

    if (arrLen == 0 || arrLen == 1) {//递归终止条件
        return true;
    } 

    srand(array[array[arrStart] + arrLen + array[arrEnd - 1]]);

    int pivot = arrStart + floor(((arrLen - 1) + (size_t)rand()) % (arrLen - 1));
    //pviot的值
    int pivotPos = partition(array, arrStart, pivot, arrEnd);
    //pviotPos的位置
    quickSort(array, arrStart, pivotPos);
    quickSort(array, pivotPos+1, arrEnd);

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
    int arrayLen = sizeof(array0)/sizeof(int);

    printArray(array0, arrayLen);//原数组
    quickSort(array0, 0, arrayLen);//快速排序
    printArray(array0, arrayLen);//快速排序后的数组

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    quickSort(array1, 0, arrayLen);
    printArray(array1, arrayLen);

    cout << "=========================================" << endl;

    int array2[] = {2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    quickSort(array2, 0, arrayLen);
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    int array3[] = {1, 5, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    quickSort(array3, 0, arrayLen);
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    int array4[] = {9, 12, 8, 7};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    quickSort(array4, 0, arrayLen);
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    int array5[] = {9, 12, 8, 7, 3};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    quickSort(array5, 0, arrayLen);
    printArray(array5, arrayLen);


}