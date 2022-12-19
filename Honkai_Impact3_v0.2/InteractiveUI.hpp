#pragma once
#include<iostream>
#include "HomeSupply.h"
#include "ExpandSupply_Role.h"
#include <Windows.h>
using namespace std;

class InteractiveUI
{
public:
	InteractiveUI()
	{
		this->supply = nullptr;
	}

	// ��UI
	void mainInteractiveUI()
	{
		int  select = 0;
		bool flag = true;

		while (flag)
		{
			cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
			cout << "\t\t\t*                   \t\t*" << endl;
			cout << "\t\t\t* 1          ����ѡ��\t\t*" << endl;
			cout << "\t\t\t* 0          ��    ��\t\t*" << endl;
			cout << "\t\t\t*                   \t\t*" << endl;
			cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
			cout << "����������ѡ��";
			cin >> select;
			switch (select)
			{
			case 1:
				supplySelectUI();
				break;
			case 0:
				system("cls");
				flag = false;
				break;
			default:
				break;
			}
		}
		cout << "�ɹ��˳���\n\n" << endl;
	}
	
	// ����ѡ��  
	void supplySelectUI()
	{
		system("cls");
		bool flag = true;
		int select = 0;
		while (flag)
		{
			cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
			cout << "\t\t\t*                   \t\t*" << endl;
			cout << "\t\t\t* 1          ��԰����\t\t*" << endl;
			cout << "\t\t\t* 2          ��ɫ���䲹��\t*" << endl;
			cout << "\t\t\t* 3          �������䲹��\t*" << endl;
			cout << "\t\t\t* 4          ��׼����\t\t*" << endl;
			cout << "\t\t\t* 5          ���ײ���\t\t*" << endl;
			cout << "\t\t\t* 6          ��������\t\t*" << endl;
			cout << "\t\t\t* 7          ��װ����\t\t*" << endl;
			cout << "\t\t\t* 8          ����������\t\t*" << endl;
			cout << "\t\t\t* 9          ��ż����\t\t*" << endl;
			cout << "\t\t\t* 0          ��    ��\t\t*" << endl;
			cout << "\t\t\t*                   \t\t*" << endl;
			cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
			cout << "����������ѡ��";
			cin >> select;
			switch (select)
			{
			case 1:
				this->supply = new HomeSupply(); //��԰����
				break;
			case 2:
				this->supply = new ExpandSupply(); //���䲹��
				break;
			case 3:
				cout << "�ù������ڿ����������ڴ���" << endl;
				break;
			case 4:
				cout << "�ù������ڿ����������ڴ���" << endl;
				break;
			case 5:
				cout << "�ù������ڿ����������ڴ���" << endl;
				break;
			case 6:
				cout << "�ù������ڿ����������ڴ���" << endl;
				break;
			case 7:
				cout << "�ù������ڿ����������ڴ���" << endl;
				break;
			case 8:
				cout << "�ù������ڿ����������ڴ���" << endl;
				break;
			case 0:
				system("cls");
				flag = false;
				break;
			default:
				break;
			}
			// ��ʾUI
			SupplyInteractiveUI();
		}

	}

	// ����UI
	void SupplyInteractiveUI()
	{
		system("cls");
		bool flag = true;
		int select = 0;
		while (flag)
		{
			cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
			cout << "\t\t\t*                   \t\t*" << endl;
			cout << "\t\t\t* 1          һ    ��\t\t*" << endl;
			cout << "\t\t\t* 2          ʮ    ��\t\t*" << endl;
			cout << "\t\t\t* 3          �鿴��¼\t\t*" << endl;
			cout << "\t\t\t* 0          ��    ��\t\t*" << endl;
			cout << "\t\t\t*                   \t\t*" << endl;
			cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
			cout << "����������ѡ��";
			cin >> select;
			switch (select)
			{
			case 1:
				system("cls");
				this->supply->singleSupply();
				break;
			case 2:
			{
				system("cls");
				this->supply->tenSupply();
			}
				break;
			case 3:
				system("cls");
				this->supply->showRecordData();
				break;
			case 0:
				system("cls");
				flag = false;
				break;
			default:
				break;
			}
		}

		if (this->supply)
		{
			delete this->supply;
			this->supply = nullptr;
		}
	}

private:
	Supply* supply;
};
