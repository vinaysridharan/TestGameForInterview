#include "stdafx.h"
#include<iostream>
#include<vector>
#include <chrono>
using namespace std;

void quickSort(std::vector<int> &arr, int start, int end){
	if (start < end){
		int large = start;
		int pivot = end;
		for (auto i = start; i < end; ++i){
			if (arr[i] < arr[pivot]){
				int t = arr[i];
				arr[i] = arr[large];
				arr[large] = t;
				large = large + 1<end ? large + 1 : end;
			}
			else{
			}
		}
		int t = arr[large];
		arr[large] = arr[pivot];
		arr[pivot] = t;

		for (auto i : arr){
			std::cout << i << " ";
		}
		std::cout << "\n";
		quickSort(arr, start, large - 1);
		quickSort(arr, large + 1, end);
	}
}

int main(){
	int n;
	std::cin >> n;
	std::vector<int> arr;
	for (auto i = 0; i<n; ++i){
		auto val = 0;
		std::cin >> val;
		arr.push_back(val);
	}
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	quickSort(arr, 0, arr.size() - 1);
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;
	cout << "Time difference = " << chrono::duration_cast<chrono::nanoseconds> (end - begin).count() << endl;

	return 0;

}