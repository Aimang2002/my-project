#include "log.h"
#include "HomeSupply.h"
#include<string>

#define tlag "_"

void Log::write(const string &str)
{
	/*
	����BUG����ǰ�汾���������´ΰ汾��Ҫ������־����*/

	/*
	time_t now = time(nullptr);
	tm* nowTime = localtime(&now);
	// ��ȡ��ǰʱ��
	string fileName = "log\\" + to_string(nowTime->tm_year + 1900) + "��" + to_string(nowTime->tm_mon + 1) + "��" + to_string(nowTime->tm_mday) +
		"�� " + to_string(nowTime->tm_hour) + "��" + to_string(nowTime->tm_min) + "��" + to_string(nowTime->tm_sec) + "��.txt";

	ofstream ofs(fileName, ios::ate | ios::out);
	if (!ofs.is_open())
	{
		cout << "��־��ʧ��" << endl;
		return;
	}

	ofs << str << endl;
	ofs.close();
	*/
}