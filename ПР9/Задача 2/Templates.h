#pragma once

using namespace std;

template <class T> T* sort(T* list, int len)
{
	bool execution = true;
	for (int j = 0; j < len - 1; j++) {
		if (execution == true) {
			bool exchange = false;
			for (int i = 0; i < len - 1; i++) {
				if (list[i] > list[i + 1]) {
					swap(list[i], list[i + 1]);
					exchange = true;
				}
			}
			if (exchange == false) execution = false;
		}
	}
	return list;
}