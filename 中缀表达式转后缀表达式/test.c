

#include"中缀转后缀.h"

int main()
{
	cell arr[] = { {Data,12},{Ope,'*'},{Left,'('},{Data,3},
	{Ope,'+'},{Data,4},{Right,')'},{Ope,'-'},{Data,6},{Ope,'+'},
	{Data,8},{Ope,'/'},{Data,2} };
	MidTurnBack(arr, sizeof(arr) / sizeof(arr[0]));
	system("pause");
}