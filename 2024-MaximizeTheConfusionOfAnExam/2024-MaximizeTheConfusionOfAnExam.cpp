// Last updated: 9/6/2026, 2:20:13 PM
class Solution {
public:
    int slidingWindow(string s, int k, char flag)
{
    int counter = 0;
    int size = s.size();
    int maxValue = 0;
    int i, j;
    for (i = 0, j = 0; i < size; i++)
    {
        // cout << i << "\t" << j << "\t" << maxValue << "\t" << counter << endl;

        if (s[i] == flag)
            counter++;
        if (counter == k + 1)
        {
            maxValue = max(maxValue, i - j);
            while (counter > k)
            {
                if (s[j++] == flag)
                    counter--;
            }
        }
        // cout << i << "\t" << j << "\t" << maxValue << "\t" << counter << endl;
    }
    if (j == 0)
    {
        return size;
    }
    maxValue = max(maxValue, i - j);
    return maxValue;
}
int maxConsecutiveAnswers(string answerKey, int k)
{
    return max(slidingWindow(answerKey, k, 'T'), slidingWindow(answerKey, k, 'F'));
}

};