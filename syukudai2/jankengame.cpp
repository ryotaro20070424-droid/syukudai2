#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void Initrand()
{
	srand((unsigned int)time(NULL));
}

void Cpu(int& CpuHand)
{
	CpuHand = rand() % 3;
}

bool Judge(int Hand, int CpuHand)
{
	cout << "結果は";
	 if ((Hand == 0 && CpuHand == 1) || (Hand == 1 && CpuHand == 2) || (Hand == 2 && CpuHand == 0))
	{
		cout << "あなたの勝ち！" << endl;
		return true;
	}
	else
	{
		cout << "負けですね" << endl;
		return false;
	}
}

void FinalJudge(int winp, int losep)
{
	cout << "===========================" << endl;
	cout << "リザルトは、勝ちが「" << winp << "」回！" << endl
		<< "負けが「" << losep << "」回！" << endl;
	if (winp > losep)
	{
		cout << "あなたの勝ちです!!!" << endl;
	}
	else
	{
		cout << "あなたの負けですね　(*´Д｀)ハァ" << endl;
	}
}

void Play(int num)
{
	int Hand = 0;
	int CpuHand = 0;
	int winp = 0;
	int losep = 0;
	const char* str[] = { "グー","チョキ","パー" };
	for (int i = 0;i < num;i++)
	{
		cout << "===================" << endl;
		cout << i + 1 << "回目！" << endl
			<< "あなたの手は？グーなら「０」、チョキなら「１」、パーなら「２」を押してね♦＞";
		cin >> Hand;
		if (Hand < 0 || Hand>2)
			continue;
		Cpu(CpuHand);
		cout << "あなたの手は" << str[Hand] << "!" << endl
			<< "相手は" << str[CpuHand] << "!";
		if (Hand == CpuHand)
		{
			cout << "あいこ！" << endl;
			i--;  
			continue;
		}
		Judge(Hand, CpuHand) ? winp++ : losep++;
	}
	FinalJudge(winp, losep);
}

int main()
{
	Initrand();
	int check = 0;
	while (check == 0)
	{
		int num = 0;
		const char* str[] = { "1発","3回","5回" };
		const int a[] = { 1,3,5 };
		cout << "＝＝＝＝じゃんけんゲーム！＝＝＝＝" << endl
			<< "何回勝負でプレイする？" << endl
			<< "1発勝負は「0」を3回勝負は「1」を5回勝負は「2」を押してね☆" << endl
			<< "(引き分けはなしだよ)" << endl;
		cin >> num;
		if (num < 0 || num>2)
			continue;
			cout << str[num] << "勝負だね♧" << endl;
		num = a[num];
		Play(num);
		check++;
	}
}