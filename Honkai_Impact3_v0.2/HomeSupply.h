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
	// ���캯��
	HomeSupply();

	// ��д ���β���
	void singleSupply();

	// ��д ʮ�β���
	void tenSupply();
	
	// ���� ����������
	void showSupplyresult();
	// ���� �����ȡ��������
	void showRecordData();

	// ��������
	~HomeSupply();

private:
	// ��д ���������
	void makerRandomNumber();

	// ��д �ؼ������жϣ����ض�Ӧ��ID
	int keynumberJudeg();

	// ��д ���廯/��������(�Ǳ���UP and ����UP ���������S��)
	void supplyAdjustment(const int keyID);

	// ��д �����ж� 
	void mandatoryGain();

	Database*mdb; //���ݿ�

	// ȫ������
	// ������ȡ���ļ�¼�������
	void showanalyseRecordData();
	//���汣�׼�¼
	void HomeSupply_saveSupplyData();
	// ��ȡ���׼�¼
	void HomeSupply_readSupplyData();

	// ����Ԥ����
	void dataPrestrain();

	// keynumberJudeg����ר��
	vector<int>retID;
	vector<pair<double, double>>chance;
};