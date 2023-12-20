#include "consts.h"
#include "structs.h"
int main(){
  setlocale(LC_ALL, "Russian");
  int g, k;
  vector <int> times, surnames;
  cout << "Variant 2. \nConference program. \nZalesski Ivan\n";
  cout << "1.Пирамидальная сортировка (Heap sort)\n2.Сортировка слиянием(Merge sort)\n";
  cin >> g;
  cout << "1.По убыванию длительности доклада (разницы между временем окончания и начала доклада)\n2.По возрастанию фамилии автора доклада, а в рамках одного автора по возрастанию темы доклада\n";
  cin >> k;
  int i = 0;
  arr = new struct doclad[100];
  while (!fin.eof()) {
	  arr[i] = input();
	  i++;
  }
  for (int j = 0; j < i; j++)
	if ((arr[j].surname == "Иванов") && (arr[j].name == "Иван") && (arr[j].otchestvo == "Иванович"))
	  output (arr[j]);
  fout << endl;
  for (int j = 0; j < i; j++) {
	  times.push_back(arr[j].longer = (arr[j].end.hours - arr[j].start.hours) * 60 - arr[j].start.minutes + arr[j].end.minutes);
	  if (arr[j].longer > 15)
		  output(arr[j]);
  }
  fout << endl;
  if (g == 1)
  {
	  heapSort(arr, i, k);
		  for (int h = 0; h < i; h++)
				  output(arr[h]);
  }

  if (g == 2)
  {
	  mergeSort(arr, 0, i - 1, k);
	  for (int h = 0; h < i; h++)
		  output(arr[h]);
  }
  return 0;
}
