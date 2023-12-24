#include "consts.h"
#include "structs.h"
int main(){
  setlocale(LC_ALL, "Russian");
  int g, k;
  vector <int> times, surnames;
  cout << "Variant 2. \nConference program. \nSivoldaev Nikita\n";
  cout << "1.Ïèðàìèäàëüíàÿ ñîðòèðîâêà (Heap sort)\n2.Ñîðòèðîâêà ñëèÿíèåì(Merge sort)\n";
  cin >> g;
  cout << "1.Ïî óáûâàíèþ äëèòåëüíîñòè äîêëàäà (ðàçíèöû ìåæäó âðåìåíåì îêîí÷àíèÿ è íà÷àëà äîêëàäà)\n2.Ïî âîçðàñòàíèþ ôàìèëèè àâòîðà äîêëàäà, à â ðàìêàõ îäíîãî àâòîðà ïî âîçðàñòàíèþ òåìû äîêëàäà\n";
  cin >> k;
  int i = 0;
  arr = new struct doclad[100];
  while (!fin.eof()) {
	  arr[i] = input();
	  i++;
  }
  for (int j = 0; j < i; j++)
	if ((arr[j].surname == "Èâàíîâ") && (arr[j].name == "Èâàí") && (arr[j].otchestvo == "Èâàíîâè÷"))
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
