#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int gNumCourses;

bool
dfs (vector<bool>& vecPicker, vector<vector<int>>& vecCourses, int course)
{
  cout << "\nCOURSE = " << course;
  if (vecPicker[course] == true) {
    cout << "\nReturn-A";
    return (false);
  }
  cout << "\nChecking neighbors";
  for (int prereq = 0; prereq < gNumCourses; prereq++) {
    if (vecCourses[course][prereq] == 1) {
      cout << "\nMarking";
      vecPicker[course] = true;
      cout << "\nCOURSE= " << course << ",PREREQ= " << prereq;
      if (!dfs(vecPicker, vecCourses, prereq)) {
        cout << "\nReturn-B";
        return (false);
      }
    }
  }

  return (true);
}


bool
canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
  gNumCourses = numCourses;
  if (!gNumCourses) {
    return (false);
  }
  if (!prerequisites.size()) {
    return (true);
  }
  vector<vector<int>> vecCourses(numCourses, vector<int>(numCourses,0));
  vector<bool> vecPicker(numCourses, false);

  for (auto pair : prerequisites) {
    vecCourses[pair[0]][pair[1]] = 1;
  }

  cout << "\nGrid";
  for (int i = 0; i < vecCourses.size(); i++) {
    cout << "\n";
    for (int j = 0; j < vecCourses.size(); j++) {
      cout << "(" << vecCourses[i][j] << ") ";
    }
  }

  for (int i = 0; i < gNumCourses; i++) {
    if (vecPicker[i]) {
      continue;
    }
    if (!dfs(vecPicker, vecCourses, prerequisites[i][0])) {
      cout << "\nReturn-C";
      return (false);
    }
  }

  return (true);
}

int
main (int argc, char *argv[])
{
  vector<vector<int>> prerequisites;

  prerequisites[0] = vector<int>({0,1});
  prerequisites[1] = vector<int>({0,0});

  if (canFinish(2, prerequisites)) {
    cout << "\nSuccess";
    return (0);
  }

  cout << "\nFailure";
  return (0);
}
