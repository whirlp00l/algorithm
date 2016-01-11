#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#define Min(x, y)   (x) < (y) ? (x) : (y)

using namespace std;
typedef long long ll;

int partition(vector<int>& nums, int start, int end) {
	int pvt = nums[start];
	start--;
	end++;
	while (1) {
		while (nums[++start] > pvt) cout << start << endl;
		while (nums[--end] < pvt) cout << end << endl;
		if (start < end)
			swap(nums[start], nums[end]);
		else
			return end;
	}
}
int helper(vector<int>& nums, int start, int end, int k) {
	if (start == end) return nums[start];
	auto pivot = partition(nums, start, end);
	if (pivot<k)
		return helper(nums, pivot + 1, end, k);
	else
		return helper(nums, start, pivot, k);
}
int findKthLargest(vector<int>& nums, int k) {
	return helper(nums, 0, nums.size() - 1, k - 1);
}
int test_findKthLargest() {
	vector<int> nums = { -10,-2,-2,-2,-2,-2,-2,-2,-2,-2 };
	return findKthLargest(nums, 6);
}
