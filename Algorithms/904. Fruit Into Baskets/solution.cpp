class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int lastFruit = -1, secondLastFruit = -1;
        int lastFruitCount = 0;
        int currMax = 0, maxFruits = 0;

        for (int fruit : fruits)
        {
            if (fruit == lastFruit || fruit == secondLastFruit)
            {
                currMax++;
            }
            else
            {
                currMax = lastFruitCount + 1;
            }

            if (fruit == lastFruit)
            {
                lastFruitCount++;
            }
            else
            {
                lastFruitCount = 1;
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }

            maxFruits = max(maxFruits, currMax);
        }

        return maxFruits;
    }
};