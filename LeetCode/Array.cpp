#include "stdafx.h"
#include "Array.h"

Array::Array()
{
}

Array::~Array()
{
}

int Array::removeElement(std::vector<int>& nums, int val)
{
    //������Ŀ��û��Ҫ��Ԫ��˳�������á�ǰ��ָ�롱��������������������ȫ��Ų������ĩ����
    int first = 0;
    int last = nums.size() - 1;
    int length = nums.size();

    while (first <= last) {
        if (nums.at(first) == val) {
            if (nums.at(last) == val)
                last--;
            else {
                int temp = nums.at(first);
                nums.at(first) = nums.at(last);
                nums.at(last) = temp;
                first++;
                last--;
            }
            length--;
        }
        else {
            first++;
        }
    }

    return length;
}

int Array::searchInsert(std::vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums.at(mid) > target)
            right = mid - 1;
        else if (nums.at(mid) < target)
            left = mid + 1;
        else
            return mid;
    }

    return left;
}
