#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include<map>
#include<Windows.h>
#include "config.h"


class Database
{
public:
	static Database* instance();
	// 读取文件
	void readFile();
	// 写入文件
	void writeFile(const string path);
	// 数据同步
	void syncData(const int supply_code, const int target); //参数一为补给代码   参数二为 若target==1表示同步一条数据，若target==10则同步十条信息

	// 测试函数
	void testFunction();

	// 从文件读取数据   key = ID  value = data （只负责读取文件数据，不提供增加或删除）
	vector<pair<int, string>> tempDateSave;				// 保存临时记录
	// 读取抽过的信息
	vector<pair<int, string>> read_HomeSupplyRecord_data;			
	vector<pair<int, string>> read_ExpandSupplyRecord_data;		

	map<int, string> read_SGrade_data;					// S角色
	map<int, string> read_AGrade_data;					// A角色
	map<int, string> read_BGrade_data;					// 读取B角色
	map<int, string> read_fourWeapon_data;				// 四星武器
	map<int, string> read_fourStigmata_data;			// 四星圣痕
	map<int, string> read_threeWeapon_data;				// 三星武器
	map<int, string> read_threeStigmata_data;			// 三星圣痕
	map<int, string> read_evolveMaterial_data;			// 进化材料
	map<int, string> read_experienceMaterial_data;		// 经验材料
	map<int, string> read_goldMaterial_data;			// 金币材料
	map<int, string> read_limitSGrade_data;				// 限定S角色
	map<int, string> read_limitFiveWeapon_data;			// 限定五星武器
	map<int, vector<string>> read_limitFiveStigmata_data;// 限定五星圣痕  vector 最大容量为3
	map<int, string> read_SPGrade_data;					// SP角色


private:
	Database();
	Database(const Database&) {};
	Database &operator= (const Database &);
	~Database();
private:
	vector<pair<int, string>>* all_read_record_data[2];
	string recordData_path[2];
	vector<int>code;
	static Database* m_instance;
};
