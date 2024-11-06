#include <iostream>
using namespace std;

void affiche(int* tabb) {
	cout << "{";
	for (int i = 0; i < 6; i++) {
		cout << tabb[i] << ";";
	};
	cout << tabb[6] << "}" << endl;
}

void tri_bulle(int* tabb) {
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 7;j++) {
			if (tabb[i] > tabb[j]) {
				int temp = tabb[i];
				tabb[i] = tabb[j];
				tabb[j] = temp;
			};
		};
	};
}

int main() {
	cout << "my sort algorithm" << endl;
	int tab[] = { 16, 50, 8, 3, 56, 23, 15 };

	cout << "unsorted tab : ";
	affiche(tab);

	tri_bulle(tab);

	cout << "sorted tab : ";
	affiche(tab);

	return 0;
}