#include<stdio.h>
void Merge(int *arr, int *brr, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
			brr[k++] = arr[i++];
		else
			brr[k++] = arr[j++];
	}
	if (i > mid)
	{
		for (int q = i; q <= right; i++)
		{
			brr[k++] = arr[q++];
		}
	}
	else
	{
		for (int q = i; q <= mid; i++)
		{
			brr[k++] = arr[q++];
		}
	}
}
void MergePass(int *arr, int* brr, int len, int n)
{
	//�ϲ�����Ϊlen������
	int i = 0;
	while (i < n - 2 * len)
	{
		//�ϲ���СΪlen������������
		Merge(arr, brr, i, i + len - 1, i + 2 * len - 1);
		i += 2 * len;
	}
	//ʣ��Ԫ������2len
	if (i + len < n)
	{
		//Ԫ�ض���len
		Merge(arr, brr, i, i + len - 1, n - 1);
	}
	else
	{
		//Ԫ������len
		for (int j = i; j < n; j++)
			brr[j] = arr[j];
	}
}
void MergeSort_NR(int *arr, int n)
{
	int len = 1;
	int *brr = (int*)malloc(sizeof(int) * 6);
	while (len < n)
	{
		MergePass(arr, brr, len, n);//�ϲ�������brr
		len += len;
		MergePass(brr, arr, len, n);//�ϲ�������arr
		len += len;
	}
}
int main()
{
	int arr[5] = { 5,3,4,1,2 };
	MergeSort_NR(arr, 5);
	return 0;
}