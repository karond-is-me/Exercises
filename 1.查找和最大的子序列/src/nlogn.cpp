#include "nlogn.h"
#include <iostream>

std::unique_ptr<Result> do_search(std::vector<int> &num_list, int index_l, int index_r)
{
    if ( index_l == index_r )
    {
        return std::make_unique<Result>(num_list[index_l],index_l,index_l);
    } 
    else
    {
        std::unique_ptr<Result> iret_f = do_search(num_list,index_l,index_l+(index_r-index_l)/2);
        std::unique_ptr<Result> iret_e = do_search(num_list,index_l+(index_r-index_l)/2+1,index_r);
        // std::cout << index_l<<"<==>"<< index_l+(index_r-index_l)/2 <<" || "<<index_l+(index_r-index_l)/2+1<<"<==>"<< index_r << std::endl;
        // std::cout << iret_f->max << " " << iret_e->max <<std::endl;

        if ( iret_f->end+1 == iret_e->begin)
        {
            int max = iret_e->max + iret_f->max;
            if (max > iret_e->max && max > iret_f->max)
            {
                iret_f->max += iret_e->max;
                iret_f->end = iret_e->end;
                return std::move(iret_f);
            }
            else
            {
                return iret_f->max > iret_e->max ? std::move(iret_f) : std::move(iret_e);
            }

        }
        else    
        {
            int m_sum = 0; 
            for (int i = iret_f->end+1;i<iret_e->begin;i++)
            {
                m_sum += num_list[i];
            }
            m_sum += iret_f->max;
            m_sum += iret_e->max;
            if (m_sum > iret_f->max && m_sum > iret_e->max)
            {
                iret_f->max = m_sum;
                iret_f->end = iret_e->end;
                return std::move(iret_f);
            }
            else
            {
                // [31][-40][39]合并的时候很尴尬，如果返回和为39的段，以后跟前面的段合并的时候就会比直接用31的段少1
                return iret_f->max>iret_e->max?std::move(iret_f):std::move(iret_e);
            }

        }
    }
}

std::unique_ptr<Result> nlognsearch(std::vector<int> &num_list)
{
    std::unique_ptr<Result> iret = do_search(num_list,0,num_list.size()-1);
    return std::move(iret);
}