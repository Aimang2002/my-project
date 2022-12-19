#pragma once
#include<iostream>
using namespace std;

// Honkai_Impact3  calss
class Supply 
{
public:
	// 单次补给
	virtual void singleSupply()=0;

	// 十次补给
	virtual void tenSupply()=0;

	// 输出补给结果
	virtual void showSupplyresult()=0;

	// 输出抽取过的数据
	virtual void showRecordData() = 0;

protected:
	// 随机数
	double m_random_number = 0;
	// 抽取记录 
	int m_minSupply_number = 0;  // max = 10
	int m_maxSupply_number = 0;  // max = 100

	// 生成随机数
	virtual void makerRandomNumber() = 0;

	// 关键数字判断,返回对应的ID
	virtual int keynumberJudeg() = 0;

	// 获取补给(非本期UP and 本期UP 调整)
	virtual void supplyAdjustment(const int keyID) = 0;

	// 保底判断
	virtual void mandatoryGain() = 0;
};
