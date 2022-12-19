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

	// ���β���
	void singleSupply();

	// ʮ�β���
	void tenSupply();

	// ����������
	void showSupplyresult();

	// �����ȡ��������
	void showRecordData();

	~ExpandSupply();
private:
	// ���������
	void makerRandomNumber();

	// ���汣����ֵ
	void ExpandSupply_saveSupplyData();

	// �ؼ������ж�,���ض�Ӧ��ID
	int keynumberJudeg();

	// ��ȡ����
	void supplyAdjustment(const int keyID);

	// �����ж�
	void mandatoryGain();

	// ɸѡ������UP��ɫ��A��ɫ
	void presentSupply_role();

	// ��������
	void showanalyseRecordData();

	// Ԥ���غ���
	void dataPrestrain();

	Database* mdb; // ���ݿ�
	pair<int, string>SRole; //��ɫ  key=��ɫID		value=��ɫ��
	vector<pair<int, string>>ARoleGroup; //A��ϵ�н�ɫ��

	// Ԥ����  keynumberJudeg()����
	vector<int>KJ_ID;
	vector<pair<float, float>>KJ_chance;
};
