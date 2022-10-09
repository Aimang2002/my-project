#pragma once
#include<iostream>
#include<vector>
#include "DataSave.h"
#include "config.h"
#include"Arms.h"

using namespace std;

class TrueRandom
{
public:
	//构造函数
	TrueRandom();

	//十连抽
	void tenContinu();

	//单抽
	void onceExtract();

private:

	// 数据恢复
	void recoveryData();

	//随机数
	double setRandom();

	// 四星补偿
	void fourStars_compensation(const double num);

	// 五星补偿
	void fiveStars_compensation(const double num);

	//判断稀有度
	void Rarity(const double num);

	//显示容器后十个数据
	void printTenVector();

	//显示容器最后一个数据
	void printSingleData();

	//清除容器数据
	void clearVector();

	//属性
	int fourguaranteed; //四星保底
	int record_fiveStars_position; //记录五星出现的位置
	vector<int>v; //保存记录
	vector<int>data; //存储当前十个结果
	DataSave DS;
	Arms AM;
};