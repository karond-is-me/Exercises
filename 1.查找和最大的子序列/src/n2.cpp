#include "n2.h"

std::unique_ptr<Result> n2search(std::vector<int> &num_list)
{
    int max = num_list[0];
    int max_l = 0;
    int max_r = 0;
    int list_size = num_list.size();
    int row_sum = 0;
    for (int l = 0; l < list_size; l++)
    {
        row_sum = 0;
        for (int r = l; r < list_size; r++)
        {
            row_sum += num_list[r];
            if ( row_sum > max )
            {
                max = row_sum;
                max_l = l;
                max_r = r;
            }
        }
    }
    std::unique_ptr<Result> iret = std::make_unique<Result>(max,max_l,max_r);
    return std::move(iret);
}