#include<iostream>
#include<fstream>
#include<string>
#include"DLinkedList.h"
using namespace std;
int main() {
	DLinkedList<int>list;
	ifstream fin;
	fin.open("IntegerData.txt");
	string text;
	while (getline(fin, text))
	{
		for (int i = 0;i < 10;i++)
			if (text[0] == i + 2)
			{
				for (int j = 0;j < 20;j++)
					if (text[j] == ':') {
						list.insertAsLast(text[j + 1]);
					}
			}
	}
	fin.close();
	cout << "������:";
	list.size();
	cout << "lsit:";
	list.show();
	DLinkedList<int>list2;
	ifstream fin2;
	fin.open("Merge.txt");
	string text2;
	while (getline(fin2, text2))
	{
		for (int i = 0;i < 5;i++)
			if (text2[0] == i + 2)
			{
				for (int j = 0;j < 20;j++)
					if (text2[j] == ':') {
						list2.insertAsLast(text2[j + 1]);
					}
			}
	}
	fin2.close();
	cout << "lsit2:";
	list2.show();
	list.merge(list2);
	cout << "������;";
	list.size();
	cout << "�ϲ��������:";
	list.show();
	return 0;
}