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

	// 主UI
	void mainInteractiveUI()
	{
		int  select = 0;
		bool flag = true;

		while (flag)
		{
			cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
			cout << "\t\t\t*                   \t\t*" << endl;
			cout << "\t\t\t* 1          补给选择\t\t*" << endl;
			cout << "\t\t\t* 0          退    出\t\t*" << endl;
			cout << "\t\t\t*                   \t\t*" << endl;
			cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
			cout << "请输入您的选择：";
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
		cout << "成功退出！\n\n" << endl;
	}
	
	// 补给选择  
	void supplySelectUI()
	{
		system("cls");
		bool flag = true;
		int select = 0;
		while (flag)
		{
			cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
			cout << "\t\t\t*                   \t\t*" << endl;
			cout << "\t\t\t* 1          家园补给\t\t*" << endl;
			cout << "\t\t\t* 2          角色扩充补给\t*" << endl;
			cout << "\t\t\t* 3          武器扩充补给\t*" << endl;
			cout << "\t\t\t* 4          精准补给\t\t*" << endl;
			cout << "\t\t\t* 5          进阶补给\t\t*" << endl;
			cout << "\t\t\t* 6          火力补给\t\t*" << endl;
			cout << "\t\t\t* 7          服装补给\t\t*" << endl;
			cout << "\t\t\t* 8          天命武器库\t\t*" << endl;
			cout << "\t\t\t* 9          人偶补给\t\t*" << endl;
			cout << "\t\t\t* 0          返    回\t\t*" << endl;
			cout << "\t\t\t*                   \t\t*" << endl;
			cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
			cout << "请输入您的选择：";
			cin >> select;
			switch (select)
			{
			case 1:
				this->supply = new HomeSupply(); //家园补给
				break;
			case 2:
				this->supply = new ExpandSupply(); //扩充补给
				break;
			case 3:
				cout << "该功能正在开发，尽情期待！" << endl;
				break;
			case 4:
				cout << "该功能正在开发，尽情期待！" << endl;
				break;
			case 5:
				cout << "该功能正在开发，尽情期待！" << endl;
				break;
			case 6:
				cout << "该功能正在开发，尽情期待！" << endl;
				break;
			case 7:
				cout << "该功能正在开发，尽情期待！" << endl;
				break;
			case 8:
				cout << "该功能正在开发，尽情期待！" << endl;
				break;
			case 0:
				system("cls");
				flag = false;
				break;
			default:
				break;
			}
			// 显示UI
			SupplyInteractiveUI();
		}

	}

	// 补给UI
	void SupplyInteractiveUI()
	{
		system("cls");
		bool flag = true;
		int select = 0;
		while (flag)
		{
			cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
			cout << "\t\t\t*                   \t\t*" << endl;
			cout << "\t\t\t* 1          一    次\t\t*" << endl;
			cout << "\t\t\t* 2          十    次\t\t*" << endl;
			cout << "\t\t\t* 3          查看记录\t\t*" << endl;
			cout << "\t\t\t* 0          返    回\t\t*" << endl;
			cout << "\t\t\t*                   \t\t*" << endl;
			cout << "\t\t\t* * * * * * * * * * * * * * * * *" << endl;
			cout << "请输入您的选择：";
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
