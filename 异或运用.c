int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    int x = 0;
    int i = 0;
    for( i = 0; i< numsSize; i++)
    {
        x ^= nums[i];//先找出所有数字异或的结果 
    }
    int n = 0;//再分离 
    while(n<32)
    {
        if(((x>>n) & 1) %2 == 1)//确定x的第几位为1，组成该位为1的两数必不同 
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
