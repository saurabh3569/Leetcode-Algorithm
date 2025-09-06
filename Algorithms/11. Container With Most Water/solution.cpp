/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height)
{
    let ans = 0 let left = 0 let right = height.length - 1

                                         while (left < right)
    {
        let curr = (right - left) * Math.min(height[right], height[left])
                                        ans = Math.max(ans, curr) if (height[left] < height[right])
        {
            left++
        }
        else
        {
            right--
        }
    }

    return ans
};