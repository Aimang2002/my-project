#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include"config.h"
#include"Arms.h"


class DataSave
{
public:
	//构造函数
	DataSave();

	//保存数据
	void saveTenData(const vector<int>&v);

	//保存单个数据
	void saveSingleDate(const vector<int>& v);

	//输出数据
	void printRecord();

	//获取最后一个五星出现的位置
	int getLastFiveStarsPosition();

	//获取最后一个四星出现的位置
	int getLastFourStarsPosition();

	//销毁记录
	void destroyRecord();

private:
	int fourStarsSum; //四星总数
	int fiveStarsSum; //五星总数
	int fiveStarsLastPosition; //五星最后一次出现的位置
	int fourStarsLasePosition; //四星最后一次出现的位置
	vector<int>save_V;
	Arms AM;
};