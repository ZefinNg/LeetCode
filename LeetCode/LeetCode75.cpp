#include "stdafx.h"
#include "LeetCode75.h"
#include <algorithm>

std::string LeetCode75::mergeAlternately(std::string word1, std::string word2)
{
    int length1 = word1.size();
    int length2 = word2.size();
    int i1 = 0, i2 = 0;

    std::string result;
    result.reserve(length1 + length2);

    while (i1 < length1 || i2 < length2) {
        if (i1 < length1) {
            result += word1.at(i1);
            i1++;
        }

        if (i2 < length2) {
            result += word2.at(i2);
            i2++;
        }
    }

    return result;
}

bool LeetCode75::check(std::string dividend, std::string divisor)
{
    //被除数的长度大于等于除数的长度
    int count = dividend.length() / divisor.length();
    std::string tempStr;
    for (int i = 1; i <= count; i++) {
        tempStr += divisor;
    }

    return tempStr == dividend;
}

std::string LeetCode75::gcdOfStrings(std::string str1, std::string str2)
{
    //result 的长度势必是str1长度和str2长度的公约数
    int l1 = str1.length();
    int l2 = str2.length();

    //从最大长度开始找，结果求的是最大公约数字符串
    for (int i = std::min(l1, l2); i >= 1; i--) {
        if ((l1 % i == 0) && (l2 % i == 0)) {
            //截取出字符串
            std::string tempStr = str1.substr(0, i);
            //判断字符串是否可以给两个字符整除
            if (check(str1, tempStr) && check(str2, tempStr))
                return tempStr;
        }
    }

    return "";
}

std::vector<bool> LeetCode75::kidsWithCandies(std::vector<int>& candies, int extraCandies)
{
   std::vector<int>::iterator maxElement = std::max_element(candies.begin(), candies.end());
   if (maxElement == candies.end())
       return std::vector<bool>();

   std::vector<bool> result;

   for (std::vector<int>::iterator it = candies.begin(); it != candies.end(); it++) {
       if (*it + extraCandies >= *maxElement)
           result.push_back(true);
       else
           result.push_back(false);
   }

    return result;
}

bool LeetCode75::canPlaceFlowers(std::vector<int>& flowerbed, int n)
{
    int length = flowerbed.size();
    int i = 0;
    //从第 1 个开始遍历
    while (i < length && n >= 0) {
        if (flowerbed.at(i) == 1) {//当前已经种了花，左右都不能种，直接跳到i+2的位置
            i += 2;
        }
        else if (i == length - 1 || flowerbed.at(i+1) == 0) {//由于已经种花的位置，都是+2跳过来，说明当前位置的前面为0，所以需要判断下一个是否为0即可
            //如果是最后一个或者下一个位置为0，那么当前就可以种；
            n--;
            //当前种了，同样直接+2
            i += 2;
        }
        else {//不符合上面第二种情况，也就是当前为0，但下一个为1，直接+3
            i += 3;
        }

        if (n <= 0)
            return true;
    }

    return false;
}

bool LeetCode75::isVowels(const char& ch)
{
    if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E'
        || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O'
        || ch == 'u' || ch == 'U')
        return true;

    return false;
}

std::string LeetCode75::reverseVowels(std::string s)
{
    if (s.empty())
        return "";

    int i = 0;
    int j = s.size() - 1;

    while (i <= j) {
        while (!isVowels(s.at(i)) && i < j)
            i++;

        while (!isVowels(s.at(j)) && j > i)
            j--;

        if (i >= j)
            break;
#if 0
        auto ch = s.at(i);
        s.at(i) = s.at(j);
        s.at(j) = ch;
#else
        std::swap(s.at(i), s.at(j));
#endif
        i++;
        j--;
    }

    return s;
}
