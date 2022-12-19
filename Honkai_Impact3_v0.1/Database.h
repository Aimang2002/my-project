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
	// ��ȡ�ļ�
	void readFile();
	// д���ļ�
	void writeFile(const string path);
	// ����ͬ��
	void syncData(const int supply_code, const int target); //����һΪ��������   ������Ϊ ��target==1��ʾͬ��һ�����ݣ���target==10��ͬ��ʮ����Ϣ

	// ���Ժ���
	void testFunction();

	// ���ļ���ȡ����   key = ID  value = data ��ֻ�����ȡ�ļ����ݣ����ṩ���ӻ�ɾ����
	vector<pair<int, string>> tempDateSave;				// ������ʱ��¼
	// ��ȡ�������Ϣ
	vector<pair<int, string>> read_HomeSupplyRecord_data;			
	vector<pair<int, string>> read_ExpandSupplyRecord_data;		

	map<int, string> read_SGrade_data;					// S��ɫ
	map<int, string> read_AGrade_data;					// A��ɫ
	map<int, string> read_BGrade_data;					// ��ȡB��ɫ
	map<int, string> read_fourWeapon_data;				// ��������
	map<int, string> read_fourStigmata_data;			// ����ʥ��
	map<int, string> read_threeWeapon_data;				// ��������
	map<int, string> read_threeStigmata_data;			// ����ʥ��
	map<int, string> read_evolveMaterial_data;			// ��������
	map<int, string> read_experienceMaterial_data;		// �������
	map<int, string> read_goldMaterial_data;			// ��Ҳ���
	map<int, string> read_limitSGrade_data;				// �޶�S��ɫ
	map<int, string> read_limitFiveWeapon_data;			// �޶���������
	map<int, vector<string>> read_limitFiveStigmata_data;// �޶�����ʥ��  vector �������Ϊ3
	map<int, string> read_SPGrade_data;					// SP��ɫ


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
