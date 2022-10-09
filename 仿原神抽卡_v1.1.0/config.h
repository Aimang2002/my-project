#pragma once
#include<iostream>
using namespace std;


//						几率
// 五星
#define THREESTART_GOODS_BEGIN				5.9		//蓝色
#define THREESTART_GOODS_END				100		//蓝色 94.1  5.9~90

// 四星
#define FOURSTART_GOODS_BEGIN				0.7		//紫色
#define FOURSTART_GOODS_END					5.8	    //紫色  5.1  0.7~5.8

// 三星
#define FIVESTART_GOODS_BEGIN				0.0		//保底  
#define FIVESTART_GOODS_END					0.6		//保底 0.6   0~0.6



//						武器索引
// 三星
#define THREESTARS_KEY_BEGIN				0

// 四星
#define FOURSTARS_KEY_BEGIN					1000

// 五星
#define FIVESTARS_KEY_BEGIN					2000


//						路径
#define RETURNFILE_DATACARD_PATH			"./save/returnFile/DataCard.txt"			//抽卡记录 路径
#define RESOURCES_THREESTARS_PATH			"./save/resources/ThreeArms.txt"			//三星资源 路径
#define RESOURCES_FOURSTARS_PATH			"./save/resources/FourArms.txt"				//四星资源 路径
#define RESOURCES_FIVESTARS_PATH			"./save/resources/FiveArms.txt"				//五星资源 路径

