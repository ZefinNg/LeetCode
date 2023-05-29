#pragma once
#include <string>
#include <vector>

class LeetCode75
{
public:
    /*
    * 1768. 交替合并字符串
    * 给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。
    */
    std::string mergeAlternately(std::string word1, std::string word2);

    /*
    * 1071. 字符串的最大公因子
    * 对于字符串 s 和 t，只有在 s = t + ... + t（t 自身连接 1 次或多次）时，我们才认定 “t 能除尽 s”。
    * 给定两个字符串 str1 和 str2 。返回 最长字符串 x，要求满足 x 能除尽 str1 且 x 能除尽 str2 。
    */
    bool check(std::string dividend, std::string divisor);
    std::string gcdOfStrings(std::string str1, std::string str2);

    /*
    * 1431. 拥有最多糖果的孩子
    * 给你一个数组 candies 和一个整数 extraCandies ，其中 candies[i] 代表第 i 个孩子拥有的糖果数目。
    * 对每一个孩子，检查是否存在一种方案，将额外的 extraCandies 个糖果分配给孩子们之后，此孩子有 最多 的糖果。注意，允许有多个孩子同时拥有 最多 的糖果数目。
    */
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies);

    /*
    * 605. 种花问题
    * 假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
    * 给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。
    * 另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false 。
    */
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n);

    /*
    * 345. 反转字符串中的元音字母
    * 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
    * 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。
    */
    bool isVowels(const char& ch);
    std::string reverseVowels(std::string s);
};

