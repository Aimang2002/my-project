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
	// ��ȡ�ļ�
	void readFile();
	// д���ļ�
	void writeFile();
	// ����ͬ��
	void syncData();
	// ���ļ���ȡ����   key = ID  value = data ��ֻ�����ȡ�ļ����ݣ����ṩ���ӻ�ɾ����
	multimap<int, string> tempDateSave;					// ������ʱ��¼
	vector<pair<int, string>> read_record_data;			// ��ȡ�������Ϣ

	map<int, string> read_SGrade_data;					// ��ȡS��ɫ
	map<int, string> read_AGrade_data;					// ��ȡA��ɫ
	map<int, string> read_BGrade_data;					// ��ȡB��ɫ
	map<int, string> read_fourWeapon_data;				// ��ȡ��������
	map<int, string> read_fourStigmata_data;			// ��ȡ����ʥ��
	map<int, string> read_threeWeapon_data;				// ��ȡ��������
	map<int, string> read_threeStigmata_data;			// ��ȡ����ʥ��
	map<int, string> read_evolveMaterial_data;			// ��ȡ��������
	map<int, string> read_experienceMaterial_data;		// ��ȡ�������
	map<int, string> read_goldMaterial_data;			// ��ȡ��Ҳ���
};