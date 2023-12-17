#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ofstream fout("out.txt", ios::app);
ifstream fin("data.txt", ios::in);

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
		fout << work.start.minutes << "0 ";
	else 
		fout << work.start.minutes << " ";
	fout << work.end.hours << ":";
	if (work.end.minutes < 10)
		fout << work.end.minutes << "0 ";
	else
		fout << work.end.minutes << " ";
	fout << work.surname << " " << work.name << " " << work.otchestvo << " " << work.project << endl;
}

struct doclad first;