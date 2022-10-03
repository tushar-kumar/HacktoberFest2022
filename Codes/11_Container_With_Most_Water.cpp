/*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
Notice that you may not slant the container.*/

/*->Create variables start and end which stores with values 0 and height.size() - 1
->Create a variable ht that stores the minimum of arr[start] and arr[end](height of the water column)
->Create a variable res that stores start - end * ht (area of the water column)
->While start is smaller than end do the following
->While height[start] is smaller than or equal to ht and start is smaller than end do start++
->While height[end] is smaller than or equal to ht and start is smaller than end do end--
->Calculate ht
->Calculate the new area of the water column
->Check if it's greater than the current area
*/
#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int> &height)
{
    int start = 0, end = height.size() - 1, ht = std::min(height[start], height[end]);
    int res = (end - start) * ht;
    while (start < end)
    {
        while (height[start] <= ht && start < end)
        {
            start++;
        }
        while (height[end] <= ht && start < end)
        {
            end--;
        }
        ht = std::min(height[start], height[end]);
        res = max(res, (end - start) * ht);
    }
    return res;
}
int main()
{
return 0;
}
//https://leetcode.com/problems/container-with-most-water/