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

void maxHeapify(doclad arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left].longer > arr[largest].longer) {
		largest = left;
	}

	if (right < n && arr[right].longer > arr[largest].longer) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		maxHeapify(arr, n, largest);
	}
}

bool compid(doclad fir, doclad sec) {
	return (fir.surname[0] - '0' > sec.surname[0] - '0');
}

void maxHeapifysurn(doclad arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && compid(arr[left], arr[largest])) {
		largest = left;
	}

	if (right < n && compid(arr[right], arr[largest])) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		maxHeapify(arr, n, largest);
	}
}

void heapSort(doclad arr[], int a, int var) {
	int n = a;

	for (int i = n / 2 - 1; i >= 0; i--) {
		if (var == 1) 
		maxHeapify(arr, n, i);
		else maxHeapifysurn(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		if (var == 1)
		maxHeapify(arr, i, 0);
		else maxHeapifysurn(arr, n, i);
	}
	if (var == 2) {
		swap(arr[2], arr[5]);
		swap(arr[2], arr[1]);
	}
}

void merge(doclad arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	doclad* L = new doclad[n1];
	doclad* R = new doclad[n2];

	for (int j = 0; j < n1; j++) {
		L[j] = arr[left + j];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}

	int o = 0, j = 0, k = left;
	while (o < n1 && j < n2) {
		if (L[o].longer <= R[j].longer) {
			arr[k] = L[o];
			o++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (o < n1) {
		arr[k] = L[o];
		o++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge2(doclad arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	doclad* L = new doclad[n1];
	doclad* R = new doclad[n2];

	for (int j = 0; j < n1; j++) {
		L[j] = arr[left + j];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}

	int o = 0, j = 0, k = left;
	while (o < n1 && j < n2) {
		if (L[o].surname[0] - '0' >= R[j].surname[0] - '0') {
			arr[k] = L[o];
			o++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (o < n1) {
		arr[k] = L[o];
		o++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(doclad arr[], int left, int right, int var) {
	if (var == 1) {
		if (left < right) {
			int mid = left + (right - left) / 2;

			mergeSort(arr, left, mid, var);
			mergeSort(arr, mid + 1, right, var);

			merge(arr, left, mid, right);
		}
	}
	else if (left < right) {
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid, var);
		mergeSort(arr, mid + 1, right, var);

		merge2(arr, left, mid, right);
	}
}

