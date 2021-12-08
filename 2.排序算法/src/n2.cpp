#include <memory>
#include <vector>
#include <deque>

bool bubble_sort(std::vector<int> &num_list)
{
    int list_size = num_list.size()-1;
    for (int n = list_size;n > 0;n--)
    {
        for (int m = 0;m < n;m++)
        {
            if (num_list[m] > num_list[m+1])
            {
                std::swap(num_list[m],num_list[m+1]);
            }
        }
    }
}

bool selection_sort(std::vector<int> &num_list)
{
    int list_size;
    int i,max_index;
    std::vector<int> result_list(num_list.size());
    list_size = num_list.size()-1;
    for (int n = list_size;n>=0;n--)
    {
        
        max_index = 0;
        for (i = 0;i <= n ; i++)
        {
            if (num_list[i]>num_list[max_index])
            {
                max_index = i;
            }
        }
        result_list[n] = num_list[max_index];
        num_list.erase(num_list.begin()+max_index);
    }
    num_list = std::move(result_list);
}
bool selection_sort2(std::vector<int> &num_list)
{
    std::deque<int> source_list(num_list.begin(),num_list.end());
    std::deque<int>::iterator max_p,iter;
    std::deque<int> result_list;
    while (!source_list.empty())
    {
        max_p = source_list.begin();
        for (iter = source_list.begin();iter!=source_list.end();iter++)
        {
            if (*iter > *max_p)
            {
                max_p = iter;
            }
        }
        result_list.push_front(*max_p);
        source_list.erase(max_p);
    }
    std::vector<int> temp_list;
    temp_list.insert(temp_list.begin(),result_list.begin(),result_list.end());
    num_list = std::move(temp_list);
}