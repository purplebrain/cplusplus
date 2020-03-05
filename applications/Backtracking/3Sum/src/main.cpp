/*
 *	[ PROBLEM STATEMENT ]
 *
 *	Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
		Note:
			The solution set must not contain duplicate triplets.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int gInputSize;
vector<int> gInputVec;
vector<vector<int> > vecResult;

void
init (void)
{
	if (gInputVec.size()) {
		gInputVec.clear();
	}

	if (vecResult.size()) {
		vecResult.clear();
	}
}

bool
checkUniqueness (vector<int> vecResultPartial, vector<int> vecPartial) 
{
	unordered_map<int,int> HashMap;
	for (auto itrA : vecResultPartial) {
		HashMap[(itrA)]++;
	}

	for (auto itrB : vecPartial) {
		if (HashMap.find(itrB) == HashMap.end()) {
			// Not found, so 'true'
			return (true);
		} else {
			if (HashMap[itrB] == 0) {
				// Not found, but in higher quantity
				return (true);
			}
			HashMap[itrB]--;
		}
	}
	return (false);
}

bool
isConstraintSatisfied (vector<int>& vecPartial) 
{
	int sum = 0;

	if (vecPartial.size() != 3) {
		return (false);
	} else {
		for (auto itr : vecPartial) {
			sum += itr;
		}
		if (sum) {
			return (false);
		} else {
			for (auto itr : vecResult) {
				if (!checkUniqueness(itr, vecPartial)) {
					return (false);
				}
			}
			vecResult.push_back(vecPartial);
			return (true);
		}    
	}
}

void
ThreeSum (int cur_idx, vector<int> vecPartial) 
{
	// Exit Condition
	if (cur_idx >= gInputSize) {
		return;
	}

	// Update Partials
	vecPartial.push_back(gInputVec[cur_idx]);

	// Constraint Check
	if (isConstraintSatisfied(vecPartial)) {
		return;
	}

	// Constraint Check failed, so check next_states of cur_states
	for (int next_idx = cur_idx; next_idx < gInputSize; next_idx++) {
		ThreeSum(next_idx+1, vecPartial);
	}

	// All next_states failed for cur_state. 
	// So BACKTRACK
	vecPartial.pop_back();
}

void
ThreeSum (void) 
{
	vector<int> vecPartial = vector<int>();
	for (int base_idx = 0; base_idx < gInputSize; base_idx++) {
		ThreeSum(base_idx, vecPartial);
	}
}

int
main (int argc, char *argv[]) 
{
	cout << "\n\n========================";
	cout << "\nEnter array size : ";
	cin >> gInputSize;
	init();
	cout << "\nEnter the array contents : \n";
	int x;
	for (int i = 0; i < gInputSize; i++) {
		cout << "element-" << i << " : ";
		cin >> x;
		gInputVec.push_back(x);
	}

	ThreeSum();

	for (auto itrA : vecResult) {
		cout << "[";
		for (auto itrB : itrA) {
			cout << itrB << " ";
		}
		cout << "], ";
	}
	cout << endl;

	return (0);
}
