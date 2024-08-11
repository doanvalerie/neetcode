#include <vector>

using namespace std;

void insertion_sort(vector<int> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        int j = i;

        while (j - 1 >= 0 && vec[j] < vec[j - 1])
        {
            int temp = vec[j];
            vec[j] = vec[j - 1];
            vec[j - 1] = temp;
            j--;
        }
    }
}