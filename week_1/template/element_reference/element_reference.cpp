//============================================================================
// Name        : element_reference.cpp
// Author      : ArlenMor
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <iomanip>
#include <exception>
using namespace std;



template <typename Key, typename Value> Value& GetRefStrict (map<Key, Value>& m, Key key)
{
	if(m.count(key) == 0)
	{
		throw runtime_error("no such key in dictionary");
	}
	return m[key];
}

int main() {
	try{
		map<int, double> m_d = {{0, 3.3}};
		double& item_d = GetRefStrict(m_d, 0);
		item_d = 3.5;
		cout << m_d[0] << endl; // output:  3.5
	}catch (exception& ex){
		cout << ex.what() << endl;
	}

	return 0;
}
