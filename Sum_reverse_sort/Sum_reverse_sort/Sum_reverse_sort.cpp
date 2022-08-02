#include "Sum_reverse_sort.h"

int Sum(int x, int y) {
	return x + y;
}
string Reverse(string s) {
	/*const size_t size = s.size();
	for (size_t i = 0; i < size/2; ++i){
		char c = s[i];
		s[i] = s[size - 1 - i];
		s[size - 1 - i] = c;
	}
	*/
	reverse(s.begin(), s.end());
	return s;
}
void Sort(vector<int>& nums) {
	sort(nums.begin(), nums.end());
}