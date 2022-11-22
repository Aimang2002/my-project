#pragma once

//************** error infomation **********************//
#define COMMON_ERROR							-1						// 基本报错信息
#define FILEPATH_OPEN_ERROR						-2						// 文件打开失败
#define PARAMETER_ERROR							-3						// 参数传入错误
#define INIT_ERROR								-4						// 初始化错误信息
#define UNREALIZED								-5						// 功能未实现

//************** HoemSupply probability **************//
// S角色概率
#define HOMESUPPLY_SGRADE_PROBABILITY_BEGIN					0.0
#define HOMESUPPLY_SGRADE_PROBABILITY_END					1.50	
#define SGRADE_ID											10001000

// S碎片概率(概率偏移)
#define HOMESUPPLY_SGRADE_FRAGMENT_PROBABILITY_BEGIN		1.51		
#define HOMESUPPLY_SGRADE_FRAGMENT_PROBABILITY_END			2.78		
#define SGRADE_FRAGMENT_ID									10001100

// A角色概率
#define HOMESUPPLY_AGRADE_PROBABILITY_BEGIN					2.79				
#define HOMESUPPLY_AGRADE_PROBABILITY_END					16.29	
#define AGRADE_ID											10001200

// A碎片概率(概率偏移)  （下一个->B角色）
#define HOMESUPPLY_AGRADE_FRAGMENT_PROBABILITY_BEGIN		16.30		
#define HOMESUPPLY_AGRADE_FRAGMENT_PROBABILITY_END			26.49
#define AGRADE_FRAGMENT_ID									10001300

// 4星武器概率
#define HOMESUPPLY_FOURSTRARWEAPON_PROBABILITY_BEGIN		32.01		
#define HOMESUPPLY_FOURSTRARWEAPON_PROBABILITY_END			32.47
#define FURSTRARWEAPON_ID									10001400

// 4星圣痕概率
#define HOMESUPPLY_FOURSTRARSTIGMATA_PROBABILITY_BEGIN		32.48
#define HOMESUPPLY_FOURSTRARSTIGMATA_PROBABILITY_END		33.21
#define FOURSTRARSTIGMATA_ID								10001500

// B角色概率
#define HOMESUPPLY_BGRADE_PROBABILITY_BEGIN					26.50
#define HOMESUPPLY_BGRADE_PROBABILITY_END					32.00
#define BGRADE_ID											10001600

// 3星武器概率
#define HOMESUPPLY_THREESTRARWEAPON_PROBABILITY_BEGIN		33.22	
#define HOMESUPPLY_THREESTRARWEAPON_PROBABILITY_END			40.72
#define THREESTRARWEAPON_ID									10001700

// 3星圣痕概率
#define HOMESUPPLY_THREESTRARSTIGMATA_PROBABILITY_BEGIN		40.73
#define HOMESUPPLY_THREESTRARSTIGMATA_PROBABILITY_END		63.23
#define THREESTRARSTIGMATA_ID								10001800

// 进化材料
#define HOMESUPPLY_EVOLVEMATERIAL_PROBABILITY_BEGIN			63.24
#define HOMESUPPLY_EVOLVEMATERIAL_PROBABILITY_END			77.99
#define EVOLVEMATERIAL_ID									10001900

// 经验材料
#define HOMESUPPLY_EXPERIENCEMATERIAL_PROBABILITY_BEGIN		78.00
#define HOMESUPPLY_EXPERIENCEMATERIAL_PROBABILITY_END		92.74
#define EXPERIENCEMATERIAL_ID								10002000

// 金币材料
#define HOMESUPPLY_GOLDMATERIAL_PROBABILITY_BEGIN			92.75
#define HOMESUPPLY_GOLDMATERIAL_PROBABILITY_END				100.00    // 100.12（向左偏移了0.12）
#define GOLDMATERIAL_ID										10002100







//************** file path **************//

#define SUUPLYRECORDPATH					"HomeSupplyDatabase\\supplyRecord\\SupplyRecordFile.txt"

#define SGRADEPATH							"HomeSupplyDatabase\\SGrade\\SGrade.txt"
#define AGRADEPATH							"HomeSupplyDatabase\\AGrade\\AGrade.txt"
#define BGRADEPATH							"HomeSupplyDatabase\\BGrade\\BGrade.txt"

#define FOURWEAPONPATH						"HomeSupplyDatabase\\fourWeapon\\fourWeapon.txt"
#define FOURSTIGMATAPATH					"HomeSupplyDatabase\\fourStigmata\\fourStigmata.txt"

#define THREEWEAPONPATH						"HomeSupplyDatabase\\threeWeapon\\threeWeapon.txt"
#define THREESTIGMATAPATH					"HomeSupplyDatabase\\threeStigmata\\threeStigmata.txt"

#define EVOLVEMATERIALPATH					"HomeSupplyDatabase\\evolveMaterial\\evolveMaterial.txt"
#define EXPERIENCEMATERIALPATH				"HomeSupplyDatabase\\experienceMaterial\\experienceMaterial.txt"
#define GOLDMATERIALPATH					"HomeSupplyDatabase\\goldMaterial\\goldMaterial.txt"

#define SUPPLY_MINIMUM_RECORD				"SupplyminimumRecord\\SupplyMinimumRecod.txt"





//************** supply price **************//
#define HOMESUPPLY_PRICE						200 
