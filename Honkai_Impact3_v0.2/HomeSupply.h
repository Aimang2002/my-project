#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<iomanip>
#include"config.h"
#include"Supply.h"
#include"Database.h"
#include "FontColor.hpp"

class HomeSupply:public Supply
{
public:
	// 构造函数
	HomeSupply();

	// 重写 单次补给
	void singleSupply();

	// 重写 十次补给
	void tenSupply();
	
	// 重载 输出补给结果
	void showSupplyresult();
	// 重载 输出抽取过的数据
	void showRecordData();

	// 析构函数
	~HomeSupply();

private:
	// 重写 随机数生成
	void makerRandomNumber();

	// 重写 关键数字判断，返回对应的ID
	int keynumberJudeg();

	// 重写 具体化/调整补给(非本期UP and 本期UP 调整，针对S级)
	void supplyAdjustment(const int keyID);

	// 重写 保底判断 
	void mandatoryGain();

	Database*mdb; //数据库

	// 全局属性
	// 分析抽取过的记录且输出来
	void showanalyseRecordData();
	//保存保底记录
	void HomeSupply_saveSupplyData();
	// 读取保底记录
	void HomeSupply_readSupplyData();

	// 数据预处理
	void dataPrestrain();

	// keynumberJudeg函数专用
	vector<int>retID;
	vector<pair<double, double>>chance;
};