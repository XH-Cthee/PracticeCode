#include <iostream>
#include <math.h>

using namespace std;

bool insertSort(int array[], size_t arrLen) {
    if (arrLen < 0) {//���鳤��С��0�ͷ��ش���
        cout << "Please check your input." << endl;
        return false;
    }
    //�ֵ�Ͱ�ڵ�����ѡ���������
    for (int orderedNum = 1; orderedNum < arrLen; ++orderedNum) {
        int insertValue = array[orderedNum];//��һ�������������
        int orderedIndex = orderedNum - 1;//��һ����������
        for (; orderedIndex >= 0; --orderedIndex) {//�����е����͵�һ���Ƚϡ���ľͷ��ұ�
            if (insertValue < array[orderedIndex]) {
                array[orderedIndex + 1] = array[orderedIndex];
            }
            else {//���С�ڵ�һ�����ݾ������
                break;
            }
        }
        array[orderedIndex+1] = insertValue;//���ѵ�һ�����ݲ��뵽ֹͣ�Ƚϵ�λ��
    }

    return true;
}

bool insertSort_Sen(int array[], size_t arrLen) {
     if (arrLen < 0) {//���鳤��С��0�ͷ��ش���
        cout << "Please check your input." << endl;
        return false;
    }
    //��������
    for (int orderedNum = 1; orderedNum < arrLen; ++orderedNum) {
        int insertValue = array[orderedNum];
        int orderedIndex = orderedNum - 1;
        while(orderedIndex >=0 && array[orderedIndex] > insertValue) {//�������Ҫ���ڵ��ڵ�һ��λ�ã������������Ҫ�Ƚϵ���λ����������
           array[orderedIndex + 1] = array[orderedIndex];
           --orderedIndex;
        }
        array[orderedIndex+1] = insertValue;
    }

    return true;
}
//ѭ����ӡ����
void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

bool buckertSort(int array[], size_t arrLen, size_t bucketSize) {
    const int DEFAULT_BUCKET_SIZE = 10;//Ĭ��Ͱ�Ĵ�СΪ10
    if(arrLen < 2) {//���鳤��С��2��Ϊ����
        return true;
    }

    if (bucketSize < 1) {
        bucketSize = DEFAULT_BUCKET_SIZE;
    }

    // Find the scope of the array
    int min = array[0];//Ĭ�������һ����λ��С����������
    int max = array[0];
    
    //�ҵ�������������С������ȷ�����ݷ�Χ
    for (size_t i = 1; i < arrLen; ++i)
    {
        if (min > array[i]) {
            min = array[i];
        }
        else if (max < array[i]) {
            max = array[i];
        }
    }

    // Create buckets
    int **buckets = new int*[bucketSize]();//����Ͱ�Ķ�ά����
    int *bucketLen = new int[bucketSize]();
    int bucketScope = floor((max - min)/bucketSize) + 1;//ÿһ��Ͱ�����ݷ�Χ

    for (size_t j = 0; j < bucketSize; j++)
    {
        buckets[j] = new int[arrLen]();//��ÿ��Ͱ�������ݷ�Χ�����ڴ�ռ�
    }

    int mapIndex = -1;

    // Put array value to buckets
    for (size_t k = 0; k < arrLen; ++k)
    {
        mapIndex = floor((array[k] - min)/bucketScope);//Ͱ�����ݷ�Χ
        buckets[mapIndex][bucketLen[mapIndex]++] = array[k];//������ŵ����ֵ�Ͱ����
    }

    // Sort value in bucket and put ordered value back to array
    int arrayIndex = 0;
    for (size_t l = 0; l < bucketSize; l++)
    {
        if (bucketLen[l] > 0) {
            insertSort(buckets[l], bucketLen[l]);//��Ͱ�ڵ����ݰ����������ź�
            for (size_t m = 0; m < bucketLen[l]; ++m) {
                array[arrayIndex++] = buckets[l][m];//Ͱ�ڵ������ź�˳��󷵻ظ�֮ǰ������
            }
        }
        delete [] buckets[l];//�ͷ�Ͱ�Ŀռ�
        buckets[l] = NULL;
    }

    delete [] buckets;//�ͷſռ�
    delete [] bucketLen;

    return true;

}

int main(){
    int array0[] = {};
    int arrayLen = sizeof(array0)/sizeof(int);

    printArray(array0, arrayLen);//ԭ����
    insertSort(array0, arrayLen);//���������
    printArray(array0, arrayLen);//��������������

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);//ԭ����
    buckertSort(array1, arrayLen, 1);//Ͱ�����������������顢���鳤�ȡ�Ͱ�Ĵ�С
    printArray(array1, arrayLen);//Ͱ����������

    cout << "=========================================" << endl;

    int array2[] = {2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    buckertSort(array2, arrayLen, 2);
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    int array3[] = {1, 5, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    buckertSort(array3, arrayLen, 2);
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    int array4[] = {9, 12, 8, 7};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    buckertSort(array4, arrayLen, 2);
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    int array5[] = {9, 12, 8, 7, 3};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    buckertSort(array5, arrayLen, 2);
    printArray(array5, arrayLen);
}