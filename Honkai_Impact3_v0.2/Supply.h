#pragma once
#include<iostream>
using namespace std;

// Honkai_Impact3  calss
class Supply 
{
public:
	// ���β���
	virtual void singleSupply()=0;

	// ʮ�β���
	virtual void tenSupply()=0;

	// ����������
	virtual void showSupplyresult()=0;

	// �����ȡ��������
	virtual void showRecordData() = 0;

protected:
	// �����
	double m_random_number = 0;
	// ��ȡ��¼ 
	int m_minSupply_number = 0;  // max = 10
	int m_maxSupply_number = 0;  // max = 100

	// ���������
	virtual void makerRandomNumber() = 0;

	// �ؼ������ж�,���ض�Ӧ��ID
	virtual int keynumberJudeg() = 0;

	// ��ȡ����(�Ǳ���UP and ����UP ����)
	virtual void supplyAdjustment(const int keyID) = 0;

	// �����ж�
	virtual void mandatoryGain() = 0;
};
