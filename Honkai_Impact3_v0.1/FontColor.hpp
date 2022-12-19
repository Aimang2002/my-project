#pragma once
#include<iostream>
#include "config.h"


class FontColor
{
public:
	static void modifyColor(const std::pair<int, std::string>& p)
	{
		if (p.first > HOMESUUPLY_SGRADE_ID)	// һ��(����)
		{
			std::cout << "\t\t" << "\033[33m" << p.second << "\033[0m";
		}
		else if (p.first > AGRADE_ID)	// ����(����)
		{
			std::cout << "\t\t" << "\033[35m" << p.second << "\033[0m";
		}
		else if (p.first > BGRADE_ID)	// ����(���Ǽ�����)
		{
			std::cout << "\t\t" << p.second;
		}
		else
		{
			std::string str = __LINE__ + "��HomeSupply.cpp\tp.first = " + p.first;
			str += "\tp.first exception,Please check!";
			// Log::write(str);
			exit(COMMON_ERROR);
		}
	}
};