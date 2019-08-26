#include "utils.hpp"

void
processData(vector<DATA>& V)
{
  for_each(V.begin(), 
           V.end(),
           [](DATA& data) -> void
           { switch (data.m_op) {
             case ADD:
               cout << "sum = " << (data.m_x+data.m_y) << endl;
               break;
             case SUB:
               cout << "diff = " << (data.m_x-data.m_y) << endl;
               break;
             case MULT:
               cout << "prod = " << (data.m_x*data.m_y) << endl;
               break;
             case DIV:
               cout << "div = " << (data.m_x/data.m_y) << endl;
               break;
             default:
               cout << "none" << endl;
               break;
             }
           });

  return;
}

void 
findMeanAndMultiplyBy2(vector<DATA>& V)
{
  int N = 2;
  for_each(V.begin(), 
           V.end(),
           [N](DATA& data) -> void
           {
             cout << "[x,y,mean] = [" 
                  << data.m_x << "," << data.m_y 
                  << "," << ((data.m_x+data.m_y)/2)*N
                  << "]" << endl;
           });
}

DATA
findSumEqualTo(vector<DATA>& V, int N)
{
  vector<DATA>::iterator retVal;
  retVal = find_if(V.begin(),
                   V.end(),
                   [&V, N](DATA& data) -> bool
                   {
                      return((data.m_x + data.m_y) == N);
                   });
  return (*retVal);
}
