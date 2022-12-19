#pragma once

//************** error infomation **********************//
#define COMMON_ERROR							-1						// 基本报错信息
#define FILEPATH_OPEN_ERROR						-2						// 文件打开失败
#define PARAMETER_ERROR							-3						// 参数传入错误
#define INIT_ERROR								-4						// 初始化错误信息
#define UNREALIZED								-5						// 功能未实现
#define	ID_SEARCH_ERROR							-6						// ID查询失败
#define VESSEL_EMPTY							-7						// 容器为空


//************** HoemSupply probability **************//
#define HOMESUPPLY_CODE										101
// S角色概率
#define HOMESUPPLY_SGRADE_PROBABILITY_BEGIN					0.0F
#define HOMESUPPLY_SGRADE_PROBABILITY_END					1.50F	
#define HOMESUUPLY_SGRADE_ID								50001000

// S碎片概率(概率偏移)
#define HOMESUPPLY_SGRADE_FRAGMENT_PROBABILITY_BEGIN		1.51F		
#define HOMESUPPLY_SGRADE_FRAGMENT_PROBABILITY_END			2.78F		
#define SGRADE_FRAGMENT_ID									50002000

// A角色概率
#define HOMESUPPLY_AGRADE_PROBABILITY_BEGIN					2.79F				
#define HOMESUPPLY_AGRADE_PROBABILITY_END					16.29F	
#define AGRADE_ID											40001000

// A碎片概率(概率偏移)
#define HOMESUPPLY_AGRADE_FRAGMENT_PROBABILITY_BEGIN		16.30F		
#define HOMESUPPLY_AGRADE_FRAGMENT_PROBABILITY_END			26.49F
#define AGRADE_FRAGMENT_ID									40002000

// 4星武器概率
#define HOMESUPPLY_FOURSTRARWEAPON_PROBABILITY_BEGIN		32.01F		
#define HOMESUPPLY_FOURSTRARWEAPON_PROBABILITY_END			32.47F
#define FURSTRARWEAPON_ID									40004000

// 4星圣痕概率
#define HOMESUPPLY_FOURSTRARSTIGMATA_PROBABILITY_BEGIN		32.48F
#define HOMESUPPLY_FOURSTRARSTIGMATA_PROBABILITY_END		33.21F
#define FOURSTRARSTIGMATA_ID								40005000

// B角色概率
#define HOMESUPPLY_BGRADE_PROBABILITY_BEGIN					26.50F
#define HOMESUPPLY_BGRADE_PROBABILITY_END					32.00F
#define BGRADE_ID											30001000

// 3星武器概率
#define HOMESUPPLY_THREESTRARWEAPON_PROBABILITY_BEGIN		33.22F	
#define HOMESUPPLY_THREESTRARWEAPON_PROBABILITY_END			40.72F
#define THREESTRARWEAPON_ID									30002000

// 3星圣痕概率
#define HOMESUPPLY_THREESTRARSTIGMATA_PROBABILITY_BEGIN		40.73F
#define HOMESUPPLY_THREESTRARSTIGMATA_PROBABILITY_END		63.23F
#define THREESTRARSTIGMATA_ID								30003000

// 进化材料
#define HOMESUPPLY_EVOLVEMATERIAL_PROBABILITY_BEGIN			63.24F
#define HOMESUPPLY_EVOLVEMATERIAL_PROBABILITY_END			77.99F
#define EVOLVEMATERIAL_ID									30004000

// 经验材料
#define HOMESUPPLY_EXPERIENCEMATERIAL_PROBABILITY_BEGIN		78.00F
#define HOMESUPPLY_EXPERIENCEMATERIAL_PROBABILITY_END		92.74F
#define EXPERIENCEMATERIAL_ID								30005000

// 金币材料
#define HOMESUPPLY_GOLDMATERIAL_PROBABILITY_BEGIN			92.75F
#define HOMESUPPLY_GOLDMATERIAL_PROBABILITY_END				100.00F    // 100.12（向左偏移了0.12）
#define GOLDMATERIAL_ID										30006000




//************** ExpandSupply probability **************//
#define EXPANDSUPPLY_CODE									102
// 限定S角色概率
#define EXPANDSUPPLY_LIMITSGRADE_PROBABILITY_BEGIN			0.0F
#define EXPANDSUPPLY_LIMITSGRADE_PROBABILITY_END			1.50F	
#define LIMITSGRADE_ID										50003000

// SP角色概率
#define EXPANDSUPPLY_SPGRADE_PROBABILITY_BEGIN				1.51F				
#define EXPANDSUPPLY_SPGRADE_PROBABILITY_END				6.01F	
#define	SPGRADE_ID											40003000							

// A角色概率 （3个角色相加，应用的时候需要再次进行分类）
#define EXPANDSUPPLY_AGRADE_PROBABILITY_BEGIN				6.02F		
#define EXPANDSUPPLY_AGRADE_PROBABILITY_END					21.02F

// SP角色碎片概率
#define EXPANDSUPPLY_SPGRADE_FRAGMENT_PROBABILITY_BEGIN		21.03F
#define EXPANDSUPPLY_SPGRADE_FRAGMENT_PROBABILITY_END		36.03F

// A角色碎片概率	(同样是3个角色相加)
#define EXPANDSUPPLY_AGRADE_FRAGMENT_PROBABILITY_BEGIN		36.04F
#define EXPANDSUPPLY_AGRADE_FRAGMENT_PROBABILITY_END		39.37F	

// 进化材料
#define EXPANDSUPPLY_EVOLVEMATERIAL_PROBABILITY_BEGIN		39.38F
#define EXPANDSUPPLY_EVOLVEMATERIAL_PROBABILITY_END			45.38F

// 经验材料
#define EXPANDSUPPLY_EXPERIENCEMATERIAL_PROBABILITY_BEGIN	45.39F
#define EXPANDSUPPLY_EXPERIENCEMATERIAL_PROBABILITY_END		62.89F

// 金币材料
#define EXPANDSUPPLY_GOLDMATERIAL_PROBABILITY_BEGIN			62.90F
#define EXPANDSUPPLY_GOLDMATERIAL_PROBABILITY_END			100.00F    // 99.4（向右偏移了0.6）



//************** file path **************//

#define HOMESUPPLYRECORDPATH				"Database/save/HomeSupplyRecord/HomeSupplyRecordFile.txt"
#define EXPANDSUPPLYRECORDPATH				"Database/save/ExpandSupply-RoleRecord/ExpandSupply-RoleRecord.txt"

#define SGRADEPATH							"Database/BasicDatabase/SGrade/SGrade.txt"
#define AGRADEPATH							"Database/BasicDatabase/AGrade/AGrade.txt"
#define BGRADEPATH							"Database/BasicDatabase/BGrade/BGrade.txt"

#define FOURWEAPONPATH						"Database/BasicDatabase/fourWeapon/fourWeapon.txt"
#define FOURSTIGMATAPATH					"Database/BasicDatabase/fourStigmata/fourStigmata.txt"

#define THREEWEAPONPATH						"Database/BasicDatabase/threeWeapon/threeWeapon.txt"
#define THREESTIGMATAPATH					"Database/BasicDatabase/threeStigmata/threeStigmata.txt"

#define EVOLVEMATERIALPATH					"Database/BasicDatabase/evolveMaterial/evolveMaterial.txt"
#define EXPERIENCEMATERIALPATH				"Database/BasicDatabase/experienceMaterial/experienceMaterial.txt"
#define GOLDMATERIALPATH					"Database/BasicDatabase/goldMaterial/goldMaterial.txt"

#define HOMESUPPLY_MINIMUM_RECORD			"Database/save/HomeSupplyRecord/HomeSupplyminimumRecord/SupplyMinimumRecod.txt"
#define EXPANDSUPPLY_MINIMUM_RECORD			"Database/save/ExpandSupply-RoleRecord/ExpandSupply-RoleMinimumRecord/ExpandSupply-RoleMinimumRecord.txt"


#define LIMITSGRADEPAHT						"Database/BasicDatabase/specialSGrade/specialSGrade.txt"
#define LIMITSPGRADEPAHT					"Database/BasicDatabase/SPGrade/SPGrade.txt"
#define LIMITFIVESTIGMATAPAHT				"Database/BasicDatabase/specialFiveStigmata/specialFiveStigmata.txt"
#define LIMITFIVEWEAPONPAHT					"Database/BasicDatabase/specialFiveWeapon/specialFiveWeapon.txt"




//************** supply price **************//
#define HOMESUPPLY_PRICE						200 
#define EXPANDSUPPLY_PRICE						280
