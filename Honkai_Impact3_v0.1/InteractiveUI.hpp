#pragma once
#include<iostream>
#include "HomeSupply.h"
using namespace std;

class InteractiveUI
{
public:

	// ��UI
	static void* mainInteractiveUI()
	{
		cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
		cout << "\t\t\t*                   \t\t*" << endl;
		cout << "\t\t\t* 1          ����ѡ��\t\t*" << endl;
		cout << "\t\t\t* 0          ��    ��\t\t*" << endl;
		cout << "\t\t\t*                   \t\t*" << endl;
		cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;

		int select = 0;
		cout << "����������ѡ�";
		cin >> select;

		switch (select)
		{
		case 1:
			system("cls");
			return InteractiveUI::supplySelectUI();
			break;
		case 0:
			exit(0);
		default:
			cout << "��ʼ��ʧ��" << endl;
			return nullptr;
			break;
		}
	}
	
	// ����ѡ��  ��ʼ���������ҷ���ָ������ã�ע��ǳ�����������ｨ��������ָ��򿪱ٵ�������
	static void* supplySelectUI()
	{
		cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
		cout << "\t\t\t*                   \t\t*" << endl;
		cout << "\t\t\t* 1          ��԰����\t\t*" << endl;
		cout << "\t\t\t* 2          ���䲹��\t\t*" << endl;
		cout << "\t\t\t* 3          ��׼����\t\t*" << endl;
		cout << "\t\t\t* 4          ���ײ���\t\t*" << endl;
		cout << "\t\t\t* 5          ��������\t\t*" << endl;
		cout << "\t\t\t* 6          ��װ����\t\t*" << endl;
		cout << "\t\t\t* 7          ����������\t\t*" << endl;
		cout << "\t\t\t* 8          ��ż����\t\t*" << endl;
		cout << "\t\t\t* 0          ��    ��\t\t*" << endl;
		cout << "\t\t\t*                   \t\t*" << endl;
		cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;

		HomeSupply* HS = nullptr;
		int select = 0;
		cout << "����������ѡ�";
		cin >> select;
		switch (select)
		{
		case 1:
			HS = new HomeSupply; //��������
			break;
		case 2:
			system("cls");
			cout << "�ù������ڿ����������ڴ���" << endl;
			break;
		case 3:
			system("cls");
			cout << "�ù������ڿ����������ڴ���" << endl;
			break;
		case 4:
			system("cls");
			cout << "�ù������ڿ����������ڴ���" << endl;
			break;
		case 5:
			system("cls");
			cout << "�ù������ڿ����������ڴ���" << endl;
			break;
		case 6:
			system("cls");
			cout << "�ù������ڿ����������ڴ���" << endl;
			break;
		case 7:
			system("cls");
			cout << "�ù������ڿ����������ڴ���" << endl;
			break;
		case 8:
			system("cls");
			cout << "�ù������ڿ����������ڴ���" << endl;
			break;
		case 0:
			system("cls");
			break;
		default:
			string str = __LINE__ + "��InteractiveUI.hpp\tselect = "+select;
			Log::write(str+ "input error��");
			return nullptr;
		}

		return HS;
	}

	// ����UI
	static void SupplyInteractiveUI()
	{
		cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
		cout << "\t\t\t*                   \t\t*" << endl;
		cout << "\t\t\t* 1          һ    ��\t\t*" << endl;
		cout << "\t\t\t* 2          ʮ    ��\t\t*" << endl;
		cout << "\t\t\t* 3          �鿴��¼\t\t*" << endl;
		cout << "\t\t\t* 0          ��    ��\t\t*" << endl;
		cout << "\t\t\t*                   \t\t*" << endl;
		cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
	}
};
