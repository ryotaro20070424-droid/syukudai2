#include <iostream>
using namespace std;

void EnterScore(int* p, int size)
{
	for (int i = 0;i < size;i++)
	{
		cout << i + 1 << "人目の点数を入力して＞";
		cin >> p[i];
	}
}

void SumAve(int* p, int size)
{
	int sum = 0;
	for (int i = 0;i < size;i++)
	{
		sum += p[i];
	}
	cout << "合計値は" << sum << endl;
	cout << "平均値は" << sum / size;
}

int main()
{
	int num = 0;
	cout << "何人分の点数を入れますか？＞";
	cin >> num;

	int* p = new int[num];
	EnterScore(p, num);
	SumAve(p, num);
	delete[] p;
	p = nullptr;
}