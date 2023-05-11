#include <iostream>
using namespace std;

int arr[20];
int set_lowerbound = 0;
int set_upperbound = - 1;
int n;

void input() {
	while (true)
	{
		cout << "Masukan element : ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}
	cout << "\n________________" << endl;
	cout << "\nEnter Element" << endl;


	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}

void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)
		return;

	pivot = arr[low];

	i = low + 1;
	j = high;

	while (i <= j)
	{
		while ((arr[i] <= pivot) && (i <= high))
		{
			i++;
			set_lowerbound++;
		}
		set_lowerbound++;

		while ((arr[j] > pivot) && (j >= low))
		{
			j--;
			set_upperbound++;
		}
		set_upperbound++;


		if (i < j)
		{
			swap(i, j);
			set_upperbound++;
		}
	}
	if (low < j)
	{
		swap(low, j);
		set_lowerbound++;
	}
	q_short(low, j - 1);

	q_short(j + 1, high);
}

void display() {
	cout << "\n--------------------" << endl;
	cout << "Sorted Array" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	input();
	q_short(0, n - 1);
	display();
	return 0;
}