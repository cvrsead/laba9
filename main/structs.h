#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ofstream fout("out.txt", ios::app);
ifstream fin("data.txt", ios::app);

struct time {
	int hours;
	int minutes;
};
struct doclad {
	struct time start;
	struct time end;
	string surname;
	string name;
	string otchestvo;
	string project;
	int longer;
};

struct doclad input() {
	struct doclad work;
	string a;
	getline(fin, a);
	int b = 12, i = 12;
	work.start.hours = (a[0]-'0') * 10 + (a[1]-'0');
	work.start.minutes = (a[3]-'0') * 10 + (a[4]-'0');
	work.end.hours = (a[6]-'0') * 10 + (a[7] - '0');
	work.end.minutes = (a[9]-'0') * 10 + (a[10]-'0');
	while (a[i] != ' ')
		i++;
	work.surname = a.substr(b, i-b);
	i++;
	b = i;
	while (a[i] != ' ')
		i++;
	work.name = a.substr(b, i-b);
	i++;
	b = i;
	while (a[i] != ' ')
		i++;
	work.otchestvo = a.substr(b, i-b);
	work.project = a.substr(i+1, a.back()-i-1);
	return work;
}

void output(struct doclad work) {
	
	fout << work.start.hours << ":";
	if (work.start.minutes<10)
		fout << "0" << work.start.minutes << " ";
	else 
		fout << work.start.minutes << " ";
	fout << work.end.hours << ":";
	if (work.end.minutes < 10)
		fout << "0" << work.end.minutes << " ";
	else
		fout << work.end.minutes << " ";
	fout << work.surname << " " << work.name << " " << work.otchestvo << " " << work.project << endl;
}

void maxHeapify(std::vector<int>& arr, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		maxHeapify(arr, n, largest);
	}
}

void heapSort(std::vector<int>& arr) {
	int n = arr.size();

	for (int i = n / 2 - 1; i >= 0; i--) {
		maxHeapify(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		maxHeapify(arr, i, 0);
	}
}

void removeDuplicates(vector<int>& arr) {
	int n = arr.size();
	if (n == 0 || n == 1) {
		return;
	}

	int j = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			arr[j++] = arr[i];
		}
	}
	arr[j++] = arr[n - 1];

	while (j < n) {
		arr.pop_back();
		j++;
	}
}
