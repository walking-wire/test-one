int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    int x = 0;
    int i = 0;
    for( i = 0; i< numsSize; i++)
    {
        x ^= nums[i];//���ҳ������������Ľ�� 
    }
    int n = 0;//�ٷ��� 
    while(n<32)
    {
        if(((x>>n) & 1) %2 == 1)//ȷ��x�ĵڼ�λΪ1����ɸ�λΪ1�������ز�ͬ 
        {
            break;
        }
        else
        {
            n++;
        }
    }
    int y = 0;
    int z = 0;
    for( i = 0; i< numsSize; i++)
    {
        if((nums[i]>>n) % 2 == 1)
        {
            y ^= nums[i];
        }
        else
        {
            z ^= nums[i];
        }
    }
    int* ret = (int*)malloc(sizeof(int)*2);
    ret[0] = y;
    ret[1] = z;
    *returnSize = 2;
    return ret;
}
