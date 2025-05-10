#include "Sorting.h"

namespace Sorting
{
    void bubbleSort(std::vector<int>& vec)
    {
        for (size_t i = 0; i < vec.size() - 1; i++)
        {
            for (size_t j = 0; j < ( (vec.size() - 1) - i ); j++)
            {
                if (vec[j] > vec[j + 1])
                {
                    int temp = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = temp;
                }
            }
        }
    }
}