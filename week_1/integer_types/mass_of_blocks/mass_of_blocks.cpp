//============================================================================
// Name        : mass_of_blocks.cpp
// Author      : ArlenMor
// Вычислите суммарную массу имеющих форму прямоугольного параллелепипеда блоков одинаковой плотности,
// но разного размера.
//
// Считайте, что размеры блоков измеряются в сантиметрах, плотность — в
// граммах на кубический сантиметр, а итоговая масса — в граммах. Таким
// образом, массу блока можно вычислять как простое произведение плотности на объём.
//============================================================================

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
	int number_of_blocks, density;
	uint64_t sum = 0;
	cin >> number_of_blocks >> density;
	for(int i = 0; i < number_of_blocks; ++i)
	{
		int w, h, d;
		cin >> w >> h >> d;
		sum += static_cast<uint64_t>(w) * h * d;
	}
	sum *= density;
	cout << sum << endl;
	return 0;
}
