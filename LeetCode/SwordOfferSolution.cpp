#include "stdafx.h"
#include "SwordOfferSolution.h"


SwordOfferSolution::SwordOfferSolution()
{
}


SwordOfferSolution::~SwordOfferSolution()
{
}

int SwordOfferSolution::findRepeatNumber(vector<int>& nums)
{
    //ע�⣺��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ��
    int length = nums.size();
    int i = 0;

    while (i < length) {
        if (nums[i] == i) {
            i++;
            continue;
        }

        if (nums[i] == nums[nums[i]])
            return nums[i];

        int temp = nums[i];
        nums[i] = nums[temp];
        nums[temp] = temp;
    }

    return -1;
}
