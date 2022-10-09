#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<map>
#include<vector>
#include<string>
#include"config.h"

class Arms
{
public:
	// 构造函数
	Arms();

	// 获取数据
	map<int, string>::iterator getArms(const int key);

	// 获取三星数量  从0开始
	int getThreeStarsNumber();

	// 获取四星数量  从0开始
	int getFourStarsNumber();

	// 获取五星数量  从0开始
	int getFiveStarsNumber();

private:
	
	map<int, string>weapon; // 存放武器的容器
	vector<string>filePath; // 保存文件路径

	int threeStars_number;	// 三星武器数量
	int fourStars_number;	// 四星武器数量
	int fiveStars_number;	// 五星武器数量

	// 读取硬盘文件
	void read_HD_File();
};
