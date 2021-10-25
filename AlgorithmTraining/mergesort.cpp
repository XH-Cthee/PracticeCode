#include <iostream>
#include <math.h>

using namespace std;

bool merge(int array[], size_t arrStart, size_t arrMiddle, size_t arrEnd) {
    int arrLen = arrEnd - arrStart;//���鳤�ȵ��ڵ�һ������λ�ü�ȥ���һ������λ��
    if (arrLen < 2) {
        cout << "Please check your implementation." << endl;
        return false;
    }
    //�鲢
    int *temp = new int(arrLen);
    int i = arrStart;//�������һ����ֵ��i
    int j = arrMiddle;//�������м������ֵ��j
    int tempIndex = 0;

    while (i < arrMiddle && j < arrEnd) {//��i��λ��С�������м��λ�ò���jС����������λ��
        if (array[i] > array[j]) {//��ǰ�벿�ֵ������ڵ�Ԫ�ش��ں�벿��
            temp[tempIndex] = array[j];//�Ѻ�벿�ֵ������ֵ��ֵ����ʱ����
            ++j;//Ȼ��j��λ��������
        }
        else {
            temp[tempIndex] = array[i];//����Ͱ�ǰ�벿�ֵ�����ֵ��ֵ����ʱ����
            ++i;//i��λ��Ҳ������
        }
        ++tempIndex;//��ʱ�����ڵ��±���������
    }

    while (i < arrMiddle) {//ǰ�벿�ֵ�����ŵ���ʱ������
        temp[tempIndex++] = array[i++];
    }

    while (j < arrEnd) {//��벿�ֵ�����Ҳ�ŵ���ʱ������
        temp[tempIndex++] = array[j++];
    }

    for ((tempIndex = 0, i = arrStart); (tempIndex < arrLen && i < arrEnd); (++tempIndex, ++i)) {
        array[i] = temp[tempIndex];//�鲢�귵�ظ�֮ǰ������
    }

    delete []temp;
    temp = NULL;

    return true;
}
bool mergeSort(int array[], size_t arrStart, size_t arrEnd) {
    int arrLen = arrEnd - arrStart;//���鳤��
    if (arrLen < 0) {
        cout << "Please check your input." << endl;
        return false;
    }

    if (arrLen == 0 || arrLen == 1){//�ݹ��˳�����
        return true;
    } 

    int middle = arrStart + floor(arrLen / 2);//���������м��λ��

    mergeSort(array, arrStart, middle);//�ݹ���ã�ǰ�벿������
    mergeSort(array, middle, arrEnd);//��벿������
    return merge(array, arrStart, middle, arrEnd);
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

    printArray(array0, arrayLen);//ԭ����
    mergeSort(array0, 0, arrayLen);//�鲢����
    printArray(array0, arrayLen);//�鲢����������

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    mergeSort(array1, 0, arrayLen);
    printArray(array1, arrayLen);

    cout << "=========================================" << endl;

    int array2[] = {2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    mergeSort(array2, 0, arrayLen);
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    int array3[] = {1, 5, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    mergeSort(array3, 0, arrayLen);
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    int array4[] = {9, 12, 8, 7};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    mergeSort(array4, 0, arrayLen);
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    int array5[] = {9, 12, 8, 7, 3};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    mergeSort(array5, 0, arrayLen);
    printArray(array5, arrayLen);


}