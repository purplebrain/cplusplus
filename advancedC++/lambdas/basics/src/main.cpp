#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory>
#include <vector>

#include "base.hpp"
#include "data.hpp"
#include "utils.hpp"

using namespace std;

int
main(int rgc, char *argv[])
{
  cout << endl;
  cout << "--- set #0 ---" << endl;
  vector<DATA> vecData0;
  vecData0.reserve(8);
  vecData0.push_back(DATA(1,2,ADD));
  vecData0.push_back(DATA(3,3,SUB));
  vecData0.push_back(DATA(4,5,MULT));
  vecData0.push_back(DATA(33,11,DIV));
  vecData0.push_back(DATA(-2,12,MULT));
  vecData0.push_back(DATA(0,11,DIV));
  cout << "size of vector = " << vecData0.size() << endl;
  cout << "printing vector" << endl;
  for_each(vecData0.begin(),
           vecData0.end(),
           [](DATA& tmpData) -> void
           {
              cout << "[x,y] = [" << tmpData.m_x << "," 
                   << tmpData.m_y << "]" << endl;  
           });
  cout << "processing vector elements" << endl;
  processData(vecData0);

  cout << endl;
  cout << "--- set #1 ---" << endl;
  vector<DATA> vecData1{ DATA(2,4), DATA(5,15), DATA(10,20) };
  findMeanAndMultiplyBy2(vecData1);

  cout << endl;
  cout << "--- set #2 ---" << endl;
  vector<DATA> vecData2;
  vecData2.reserve(8);
  vecData2.push_back(DATA(2,4));
  vecData2.push_back(DATA(5,15)); 
  vecData2.push_back(DATA(10,20));
  DATA tmpData = findSumEqualTo(vecData2, 7);
  cout << "[x,y] = [" << tmpData.m_x << "," << tmpData.m_y << "]" << endl;  

  cout << endl;
  return (0);
}
