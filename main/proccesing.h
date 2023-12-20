#include "structs.h"
int process(doclad *arr, int ind) {
	struct time answer;
	vector <int> times;
	for (int j = 0; j < ind; j++)
		arr[j].longer = (arr[j].end.hours - arr[j].start.hours) * 60 - arr[j].start.minutes + arr[j].end.minutes;
	heapSort(arr, ind, 1);
	//answer.hours = times[times.size() - 1] / 60;
	//answer.minutes = times[times.size() - 1] % 60;
	return arr[ind - 1].longer;
}