#define _CRT_SECURE_NO_WARNINGS 1

//261 ֻ����һ�ε����� III
//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ�
//�ҳ�ֻ����һ�ε�������Ԫ�ء�����԰� ����˳�� ���ش�

int* singleNumber(int* nums, int numsSize, int* returnSize){
	int x = 0, y = 0;

	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}

	//�ӵ͵���ȥ��ret����һ��Ϊ1��λ
	int j = 0;
	for (j = 0; j < 32; j++)
	{
		if (ret >> j & 1)
			break;
	}

	//��ԭ�����Ϊ���飬��jλΪ1��Ϊһ�飬jλΪ0��Ϊһ��
	//int x = 0;
	//int y = 0;
	for (int k = 0; k < numsSize; k++)
	{
		if ((nums[k] >> j) & 1)   //�������ƣ��ᵽ����λ��
		{
			x ^= nums[k];
		}
		else
		{
			y ^= nums[k];
		}
	}
	int* arr = (int*)malloc(sizeof(int)* 2);
	arr[0] = x;
	arr[1] = y;
	*returnSize = 2;

	return arr;
}


//��ָ Offer 56 - I.���������ֳ��ֵĴ���
//һ���������� nums �����������֮�⣬�������ֶ����������Ρ�
//��д�����ҳ�������ֻ����һ�ε����֡�
//Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��

int* singleNumbers(int* nums, int numsSize, int* returnSize){
	int* arr = (int *)malloc(sizeof(int)* 2);
	*returnSize = 2;

	int n1 = 0;
	int n2 = 0;

	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];  //����������ͬ�����Ľ��
	}
	//�ҳ���һλΪ1 ��λ��
	int pos = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}

	//��arr������ÿ��Ԫ���ж����Ƶĵ�posλΪ1��ȫ�������һ��
	for (int i = 0; i < numsSize; i++)
	{
		if (((nums[i] >> pos) & 1) == 1)
		{
			n1 ^= nums[i];
		}
	}

	n2 = ret^n1;
	arr[0] = n1;
	arr[1] = n2;

	return arr;
}

//������ 17.04. ��ʧ������
//����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ��������
//���а취��O(n)ʱ���������

//�����������ķ���
int missingNumber(int* nums, int numsSize){
int n = numsSize + 1;
int ret1 = 0;
for(int i = 0; i < n; i++)
{
ret1 += i;
}

int ret2 = 0;
for(int j = 0; j < numsSize; j++)
{
ret2 += nums[j];
}

return ret1 - ret2;
}


//������򷽷�
int missingNumber(int* nums, int numsSize)
{
	int x = 0;
	for (int i = 0; i < numsSize + 1; ++i)
	{
		x ^= i;
	}
	for (int j = 0; j < numsSize; ++j)
	{
		x ^= nums[j];
	}

	return x;
}
