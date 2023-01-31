#include <iostream>
#include <cassert>
#include <map>
#include <vector>
using namespace std;
// formal test
bool A_test(string user_guess, int matched_count, string matched)
{
	map<int, vector<string> > mp;
	bool ret = false;
	mp[1] = {"1000", "0100", "0010", "0001"};
	mp[2] = {"1100", "1010", "1001", "0110", "0101", "0011"};
	mp[3] = {"1110", "0111", "1011", "1101"};
	for (int i = 0; i < mp[matched_count].size(); i++)
	{
		string r = mp[matched_count][i];
		bool check = true;
		for (int j = 0; i < 4; i++)
			check = check && (r[j] == '0' || r[j] == '1' || s[j] == t[j]);
		if (check)
			ret = true;
	}
	return ret;
}
bool B_test(string user_guess, int matched_count, string matched)
{
	int tmp = matched_count;
	bool ret = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (matched[i] == user_guess[j])
				tmp--;
			if (!tmp)
				ret = true;
		}
	}
	return ret;
} 
// assert test
void A_assert_test()
{
	assert(A_test("1234", 1, "1678"));
	assert(A_test("1234", 1, "5278"));
	assert(A_test("1234", 1, "5638"));
	assert(A_test("1234", 1, "5674"));
	assert(A_test("1234", 1, "1278"));
	assert(A_test("1234", 1, "5238"));
	assert(A_test("1234", 1, "5634"));
	assert(A_test("1234", 1, "1674"));
	assert(!A_test("1234", 1, "5178"));
	assert(!A_test("1234", 1, "5628"));
	assert(!A_test("1234", 1, "5673"));
	assert(!A_test("1234", 1, "4678"));
	assert(!A_test("1234", 1, "2678"));
	assert(!A_test("1234", 1, "5378"));
	assert(!A_test("1234", 1, "5648"));
	assert(!A_test("1234", 1, "5671"));
	cout << "A assert test PASSED." << endl;
}
void B_assert_test() {
	assert(B_test("1234", 4, "4312"));
	cout << "B assert test PASSED." << endl;
}