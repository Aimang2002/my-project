#pragma once

//************** error infomation **********************//
#define COMMON_ERROR							-1						// ����������Ϣ
#define FILEPATH_OPEN_ERROR						-2						// �ļ���ʧ��
#define PARAMETER_ERROR							-3						// �����������
#define INIT_ERROR								-4						// ��ʼ��������Ϣ
#define UNREALIZED								-5						// ����δʵ��

//************** HoemSupply probability **************//
// S��ɫ����
#define HOMESUPPLY_SGRADE_PROBABILITY_BEGIN					0.0
#define HOMESUPPLY_SGRADE_PROBABILITY_END					1.50	
#define SGRADE_ID											10001000

// S��Ƭ����(����ƫ��)
#define HOMESUPPLY_SGRADE_FRAGMENT_PROBABILITY_BEGIN		1.51		
#define HOMESUPPLY_SGRADE_FRAGMENT_PROBABILITY_END			2.78		
#define SGRADE_FRAGMENT_ID									10001100

// A��ɫ����
#define HOMESUPPLY_AGRADE_PROBABILITY_BEGIN					2.79				
#define HOMESUPPLY_AGRADE_PROBABILITY_END					16.29	
#define AGRADE_ID											10001200

// A��Ƭ����(����ƫ��)  ����һ��->B��ɫ��
#define HOMESUPPLY_AGRADE_FRAGMENT_PROBABILITY_BEGIN		16.30		
#define HOMESUPPLY_AGRADE_FRAGMENT_PROBABILITY_END			26.49
#define AGRADE_FRAGMENT_ID									10001300

// 4����������
#define HOMESUPPLY_FOURSTRARWEAPON_PROBABILITY_BEGIN		32.01		
#define HOMESUPPLY_FOURSTRARWEAPON_PROBABILITY_END			32.47
#define FURSTRARWEAPON_ID									10001400

// 4��ʥ�۸���
#define HOMESUPPLY_FOURSTRARSTIGMATA_PROBABILITY_BEGIN		32.48
#define HOMESUPPLY_FOURSTRARSTIGMATA_PROBABILITY_END		33.21
#define FOURSTRARSTIGMATA_ID								10001500

// B��ɫ����
#define HOMESUPPLY_BGRADE_PROBABILITY_BEGIN					26.50
#define HOMESUPPLY_BGRADE_PROBABILITY_END					32.00
#define BGRADE_ID											10001600

// 3����������
#define HOMESUPPLY_THREESTRARWEAPON_PROBABILITY_BEGIN		33.22	
#define HOMESUPPLY_THREESTRARWEAPON_PROBABILITY_END			40.72
#define THREESTRARWEAPON_ID									10001700

// 3��ʥ�۸���
#define HOMESUPPLY_THREESTRARSTIGMATA_PROBABILITY_BEGIN		40.73
#define HOMESUPPLY_THREESTRARSTIGMATA_PROBABILITY_END		63.23
#define THREESTRARSTIGMATA_ID								10001800

// ��������
#define HOMESUPPLY_EVOLVEMATERIAL_PROBABILITY_BEGIN			63.24
#define HOMESUPPLY_EVOLVEMATERIAL_PROBABILITY_END			77.99
#define EVOLVEMATERIAL_ID									10001900

// �������
#define HOMESUPPLY_EXPERIENCEMATERIAL_PROBABILITY_BEGIN		78.00
#define HOMESUPPLY_EXPERIENCEMATERIAL_PROBABILITY_END		92.74
#define EXPERIENCEMATERIAL_ID								10002000

// ��Ҳ���
#define HOMESUPPLY_GOLDMATERIAL_PROBABILITY_BEGIN			92.75
#define HOMESUPPLY_GOLDMATERIAL_PROBABILITY_END				100.00    // 100.12������ƫ����0.12��
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
