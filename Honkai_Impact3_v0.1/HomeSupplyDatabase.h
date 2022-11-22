#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include<map>
#include<Windows.h>
#include "config.h"
#include "log.h"

class HomeSupplyDatabase
{
public:
	HomeSupplyDatabase();
	// 读取文件
	void readFile();
	// 写入文件
	void writeFile();
	// 数据同步
	void syncData();
	// 从文件读取数据   key = ID  value = data （只负责读取文件数据，不提供增加或删除）
	multimap<int, string> tempDateSave;					// 保存临时记录
	vector<pair<int, string>> read_record_data;			// 读取抽过的信息

	map<int, string> read_SGrade_data;					// 读取S角色
	map<int, string> read_AGrade_data;					// 读取A角色
	map<int, string> read_BGrade_data;					// 读取B角色
	map<int, string> read_fourWeapon_data;				// 读取四星武器
	map<int, string> read_fourStigmata_data;			// 读取四星圣痕
	map<int, string> read_threeWeapon_data;				// 读取三星武器
	map<int, string> read_threeStigmata_data;			// 读取三星圣痕
	map<int, string> read_evolveMaterial_data;			// 读取进化材料
	map<int, string> read_experienceMaterial_data;		// 读取经验材料
	map<int, string> read_goldMaterial_data;			// 读取金币材料
};