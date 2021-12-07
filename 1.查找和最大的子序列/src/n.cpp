#include "n.h"
#include <limits>

std::unique_ptr<Result> nsearch(std::vector<int> &num_list)
{
    std::vector<Result> r_list;
    int temp;
    int l = 0;
    int r = 0;
    int max_l = std::numeric_limits<int>::min();
    int max_r = std::numeric_limits<int>::min();
    int max = std::numeric_limits<int>::min();
    int list_sum = 0;
    int list_size = num_list.size();
    while (l < list_size)
    {
        // 抛弃小于0的元素
        while (l<list_size && num_list[l] < 0)
        {
            l++;
        }
        max = std::numeric_limits<int>::min();
        list_sum = 0;
        for (r = l;r<list_size;r++)
        {
            list_sum += num_list[r];
            if (max < list_sum)
            {
                max = list_sum;
                max_r = r;
            }
            // 反向查找
            if (r+1 == list_size || list_sum+num_list[r+1]<0)
            {
                temp = l;
                list_sum = 0;
                max = std::numeric_limits<int>::min();
                for (l = max_r;l>=temp;l--)
                {
                    list_sum += num_list[l];
                    if (list_sum > max)
                    {
                        max = list_sum;
                        max_l = l;
                    }
                }
                // 添加到候选列表中
                r_list.push_back(Result(max,max_l,max_r));
                l = r+1;
                break;
            }
        }
        
    }
    int ret_index = 0;
    // 找到最大的并返回
    for (int i = 0;i<r_list.size();i++)
    {
        if (r_list[ret_index].max < r_list[i].max)
        {
            ret_index = i;
        }
    }
    return std::make_unique<Result>(r_list[ret_index].max,r_list[ret_index].begin,r_list[ret_index].end);
}