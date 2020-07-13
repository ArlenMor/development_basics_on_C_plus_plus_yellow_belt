//============================================================================
// Name        : everything_in_a_square.cpp
// Author      : ArlenMor
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

template <typename First, typename Second> pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2);

template <typename T> ostream& operator << (ostream& stream, const vector<T>& vi);

template <typename First, typename Second> ostream& operator << (ostream& stream, const pair<First, Second>& p1);

template <typename Key, typename Value> ostream& operator << (ostream& stream, const map<Key, Value>& m);

template <typename T> T Sqr(const T& x);

template <typename T> vector<T> Sqr(const vector<T> vi);

template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& p);

template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& m);


//===========!!!!!===========//

template <typename First, typename Second> pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2){
	pair<First, Second> answer;
	answer.first = p1.first * p2.first;
	answer.second = p1.second * p2.second;
	return answer;
}

template <typename T> ostream& operator << (ostream& stream, const vector<T>& vi){
	for(const T& v : vi)
	{
		stream << v << " ";
	}
	return stream;
}

template <typename First, typename Second> ostream& operator << (ostream& stream, const pair<First, Second>& p1){
	return stream << p1.first << "-" << p1.second;
}

template <typename Key, typename Value> ostream& operator << (ostream& stream, const map<Key, Value>& m){
	for(const auto& item : m)
		stream << item.first << " " << item.second << " ";
	return stream;
}

template <typename T> T Sqr(const T& x){
	return x * x;
}

template <typename T> vector<T> Sqr(const vector<T> vi)
{
	vector<T> answer;
	for(const T& v : vi)
	{
		answer.push_back(Sqr(v));
	}
	return answer;
}

template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& p)
{
	return {Sqr(p.first), Sqr(p.second)};
}

template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& m)
{
	map<Key, Value> answer;
	for(const auto& item : m)
	{
		answer[item.first] = Sqr(item.second);
	}
	return answer;
}

int main() {
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
