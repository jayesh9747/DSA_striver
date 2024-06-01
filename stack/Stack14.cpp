// Largest Rectangular Area in histogram

// LeetCode link : https://leetcode.com/problems/largest-rectangle-in-histogram/

// BruteForce Solution
int largestRectangleArea(vector<int> &h)
{
    int maxi = INT_MIN;
    for (int i = 0; i < h.size(); i++)
    {
        int curr = h[i];
        int count = 1;
        for (int j = i + 1; j < h.size(); j++)
        {
            if (h[j] >= curr)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        for (int j = i - 1; j >= 0; j--)
        {
            if (h[j] >= curr)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        maxi = max(maxi, count * h[i]);
    }

    return maxi;
}

