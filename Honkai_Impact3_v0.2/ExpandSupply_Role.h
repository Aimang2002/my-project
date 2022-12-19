#pragma once
#include<iostream>
#include "Supply.h"
#include "Database.h"
#include "FontColor.hpp"
#include <set>
using namespace std;

class ExpandSupply :public Supply
{
public:
	ExpandSupply();

	// 单次补给
	void singleSupply();

	// 十次补给
	void tenSupply();

	// 输出补给结果
	void showSupplyresult();

	// 输出抽取过的数据
	void showRecordData();

	~ExpandSupply();
private:
	// 生成随机数
	void makerRandomNumber();

	// 保存保底数值
	void ExpandSupply_saveSupplyData();

	// 关键数字判断,返回对应的ID
	int keynumberJudeg();

	// 获取补给
	void supplyAdjustment(const int keyID);

	// 保底判断
	void mandatoryGain();

	// 筛选出本期UP角色和A角色
	void presentSupply_role();

	// 分析卡池
	void showanalyseRecordData();

	// 预加载函数
	void dataPrestrain();

	Database* mdb; // 数据库
	pair<int, string>SRole; //角色  key=角色ID		value=角色名
	vector<pair<int, string>>ARoleGroup; //A级系列角色组

	// 预加载  keynumberJudeg()所用
	vector<int>KJ_ID;
	vector<pair<float, float>>KJ_chance;
};
