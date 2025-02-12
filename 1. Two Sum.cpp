// https://leetcode.com/problems/two-sum/description/

// Hidden code
#include <vector>
#include <iostream>
using namespace std;

// My code
#include <unordered_map>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> complements = {};

        for (int i = 0; i < nums.size(); i++)
        {
            int current = nums.at(i);

            if (complements.count(current) > 0)
            {
                return {complements.at(current), i};
            }

            int complement = target - current;

            complements.insert({complement, i});
        }

        return {0, 0};
    }
};