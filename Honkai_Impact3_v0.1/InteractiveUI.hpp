#pragma once
#include<iostream>
#include "HomeSupply.h"
using namespace std;

class InteractiveUI
{
public:

	// 主UI
	static void* mainInteractiveUI()
	{
		cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
		cout << "\t\t\t*                   \t\t*" << endl;
		cout << "\t\t\t* 1          补给选择\t\t*" << endl;
		cout << "\t\t\t* 0          退    出\t\t*" << endl;
		cout << "\t\t\t*                   \t\t*" << endl;
		cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;

		int select = 0;
		cout << "请输入您的选项：";
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
			cout << "初始化失败" << endl;
			return nullptr;
			break;
		}
	}
	
	// 补给选择  初始化各个类且返回指针或引用（注意浅拷贝，我这里建议用智能指针或开辟到堆区）
	static void* supplySelectUI()
	{
		cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
		cout << "\t\t\t*                   \t\t*" << endl;
		cout << "\t\t\t* 1          家园补给\t\t*" << endl;
		cout << "\t\t\t* 2          扩充补给\t\t*" << endl;
		cout << "\t\t\t* 3          精准补给\t\t*" << endl;
		cout << "\t\t\t* 4          进阶补给\t\t*" << endl;
		cout << "\t\t\t* 5          火力补给\t\t*" << endl;
		cout << "\t\t\t* 6          服装补给\t\t*" << endl;
		cout << "\t\t\t* 7          天命武器库\t\t*" << endl;
		cout << "\t\t\t* 8          人偶补给\t\t*" << endl;
		cout << "\t\t\t* 0          返    回\t\t*" << endl;
		cout << "\t\t\t*                   \t\t*" << endl;
		cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;

		HomeSupply* HS = nullptr;
		int select = 0;
		cout << "请输入您的选项：";
		cin >> select;
		switch (select)
		{
		case 1:
			HS = new HomeSupply; //堆区开辟
			break;
		case 2:
			system("cls");
			cout << "该功能正在开发，尽情期待！" << endl;
			break;
		case 3:
			system("cls");
			cout << "该功能正在开发，尽情期待！" << endl;
			break;
		case 4:
			system("cls");
			cout << "该功能正在开发，尽情期待！" << endl;
			break;
		case 5:
			system("cls");
			cout << "该功能正在开发，尽情期待！" << endl;
			break;
		case 6:
			system("cls");
			cout << "该功能正在开发，尽情期待！" << endl;
			break;
		case 7:
			system("cls");
			cout << "该功能正在开发，尽情期待！" << endl;
			break;
		case 8:
			system("cls");
			cout << "该功能正在开发，尽情期待！" << endl;
			break;
		case 0:
			system("cls");
			break;
		default:
			string str = __LINE__ + "：InteractiveUI.hpp\tselect = "+select;
			Log::write(str+ "input error！");
			return nullptr;
		}

		return HS;
	}

	// 补给UI
	static void SupplyInteractiveUI()
	{
		cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
		cout << "\t\t\t*                   \t\t*" << endl;
		cout << "\t\t\t* 1          一    次\t\t*" << endl;
		cout << "\t\t\t* 2          十    次\t\t*" << endl;
		cout << "\t\t\t* 3          查看记录\t\t*" << endl;
		cout << "\t\t\t* 0          返    回\t\t*" << endl;
		cout << "\t\t\t*                   \t\t*" << endl;
		cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
	}
};
