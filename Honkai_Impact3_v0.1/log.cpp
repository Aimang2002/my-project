#include "log.h"
#include "HomeSupply.h"
#include<string>

#define tlag "_"

void Log::write(const string &str)
{
	/*
	出现BUG，当前版本不发布，下次版本需要增加日志级别*/

	/*
	time_t now = time(nullptr);
	tm* nowTime = localtime(&now);
	// 获取当前时间
	string fileName = "log\\" + to_string(nowTime->tm_year + 1900) + "年" + to_string(nowTime->tm_mon + 1) + "月" + to_string(nowTime->tm_mday) +
		"日 " + to_string(nowTime->tm_hour) + "点" + to_string(nowTime->tm_min) + "分" + to_string(nowTime->tm_sec) + "秒.txt";

	ofstream ofs(fileName, ios::ate | ios::out);
	if (!ofs.is_open())
	{
		cout << "日志打开失败" << endl;
		return;
	}

	ofs << str << endl;
	ofs.close();
	*/
}