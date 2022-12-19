#pragma once
#include<iostream>
#include "config.h"


class FontColor
{
public:
	static void modifyColor(const std::pair<int, std::string>& p)
	{
		if (p.first > HOMESUUPLY_SGRADE_ID)	// 一级(五星)
		{
			std::cout << "\t\t" << "\033[33m" << p.second << "\033[0m";
		}
		else if (p.first > AGRADE_ID)	// 二级(四星)
		{
			std::cout << "\t\t" << "\033[35m" << p.second << "\033[0m";
		}
		else if (p.first > BGRADE_ID)	// 三级(三星级以下)
		{
			std::cout << "\t\t" << p.second;
		}
		else
		{
			std::string str = __LINE__ + "：HomeSupply.cpp\tp.first = " + p.first;
			str += "\tp.first exception,Please check!";
			// Log::write(str);
			exit(COMMON_ERROR);
		}
	}
};