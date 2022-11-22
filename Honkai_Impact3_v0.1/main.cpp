#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Supply.h"
#include "HomeSupply.h"
#include "HomeSupplyDatabase.h"
#include "InteractiveUI.hpp"
#include"log.h"
#include<ctime>
using namespace std;

void init()
{
	Supply* supply = nullptr; 
	int select = 1;

	while (true)
	{
		supply = (Supply*)InteractiveUI::mainInteractiveUI();
		if (supply == nullptr)
		{
			system("pause");
			system("cls");
			continue;
		}

		while (select)
		{
			system("cls");
			InteractiveUI::SupplyInteractiveUI();
			cout << "请输入您的选项：";
			cin >> select;

			system("cls");

			switch (select)
			{
			case 1:
				supply->singleSupply();
				break;
			case 2:
				supply->tenSupply();
				break;
			case 3:
				supply->showRecordData();
				break;
			case 0:
				system("cls");
				break;
			default:
				select = 0;
				break;
			}

			system("pause");
		}

	} 
	
}


int main() {
	srand((unsigned int)time(NULL));
	
	init();  //SupplySelectUI出现问题

	system("pause");
	return 0;
}
