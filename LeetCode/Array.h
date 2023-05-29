#pragma once

#include <vector>
#include <string>

class Array
{
public:
    Array();
    ~Array();

    //Easy
    /*
    * 27. 移除元素
    * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
    * 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
    * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
    */
    int removeElement(std::vector<int>& nums, int val);

    /*
    * 35. 搜索插入位置
    * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
    * 请必须使用时间复杂度为 O(log n) 的算法。
    */
    int searchInsert(std::vector<int>& nums, int target);

    //~Easy
};

