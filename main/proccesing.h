#include "structs.h"
int process(struct doclad f,struct doclad s,struct doclad t) {
	struct time answer;
	vector <int> times;
	int i = 0;
	struct doclad* arr;
	arr = new struct doclad[100];
		arr[0] = f;
		arr[1] = s;
		arr[2] = t;
	for (int j = 0; j < 3; j++)
		times.push_back(arr[j].longer = (arr[j].end.hours - arr[j].start.hours) * 60 - arr[j].start.minutes + arr[j].end.minutes);
	heapSort(times);
	//answer.hours = times[times.size() - 1] / 60;
	//answer.minutes = times[times.size() - 1] % 60;
	return times[times.size() - 1];
}