//============================================================================
// Name        : average_temperature_v2.cpp
// Author      : ArlenMor
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> temp_in_day(n);
	int64_t sum = 0;
	for(int& temperature : temp_in_day)
	{
		cin >> temperature;
		sum += temperature;
	}
	int avg = sum / n;
	vector<int> above_average_indices;
	for(int i = 0; i < n; ++i)
	{
		if(temp_in_day[i] > avg)
			above_average_indices.push_back(i);
	}
	cout << above_average_indices.size() << endl;
	for(int day : above_average_indices)
		cout << day << " ";
	return 0;
}
