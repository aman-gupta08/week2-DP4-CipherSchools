#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums)
     {
          stack<int> S;
          vector<int> nge(nums.size());
          nge[nums.size() - 1] = -1;
          for (int i = nums.size() - 2; i >= 0; i--)
          {
               while (!S.empty() && S.top() <= nums[i])
               {
                     S.pop();
               }
               
               if (S.empty())
               {
                    nge[i] = -1;
               }
               else
               {
                    nge[i] = nums[S.top()];
               }
              S.push(nums[i]);
          }
          return nge;
     }
};

int main() {

}