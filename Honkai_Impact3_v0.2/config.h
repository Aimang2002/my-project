#pragma once

//************** error infomation **********************//
#define COMMON_ERROR							-1						// ����������Ϣ
#define FILEPATH_OPEN_ERROR						-2						// �ļ���ʧ��
#define PARAMETER_ERROR							-3						// �����������
#define INIT_ERROR								-4						// ��ʼ��������Ϣ
#define UNREALIZED								-5						// ����δʵ��
#define	ID_SEARCH_ERROR							-6						// ID��ѯʧ��
#define VESSEL_EMPTY							-7						// ����Ϊ��


//************** HoemSupply probability **************//
#define HOMESUPPLY_CODE										101
// S��ɫ����
#define HOMESUPPLY_SGRADE_PROBABILITY_BEGIN					0.0F
#define HOMESUPPLY_SGRADE_PROBABILITY_END					1.50F	
#define HOMESUUPLY_SGRADE_ID								50001000

// S��Ƭ����(����ƫ��)
#define HOMESUPPLY_SGRADE_FRAGMENT_PROBABILITY_BEGIN		1.51F		
#define HOMESUPPLY_SGRADE_FRAGMENT_PROBABILITY_END			2.78F		
#define SGRADE_FRAGMENT_ID									50002000

// A��ɫ����
#define HOMESUPPLY_AGRADE_PROBABILITY_BEGIN					2.79F				
#define HOMESUPPLY_AGRADE_PROBABILITY_END					16.29F	
#define AGRADE_ID											40001000

// A��Ƭ����(����ƫ��)
#define HOMESUPPLY_AGRADE_FRAGMENT_PROBABILITY_BEGIN		16.30F		
#define HOMESUPPLY_AGRADE_FRAGMENT_PROBABILITY_END			26.49F
#define AGRADE_FRAGMENT_ID									40002000

// 4����������
#define HOMESUPPLY_FOURSTRARWEAPON_PROBABILITY_BEGIN		32.01F		
#define HOMESUPPLY_FOURSTRARWEAPON_PROBABILITY_END			32.47F
#define FURSTRARWEAPON_ID									40004000

// 4��ʥ�۸���
#define HOMESUPPLY_FOURSTRARSTIGMATA_PROBABILITY_BEGIN		32.48F
#define HOMESUPPLY_FOURSTRARSTIGMATA_PROBABILITY_END		33.21F
#define FOURSTRARSTIGMATA_ID								40005000

// B��ɫ����
#define HOMESUPPLY_BGRADE_PROBABILITY_BEGIN					26.50F
#define HOMESUPPLY_BGRADE_PROBABILITY_END					32.00F
#define BGRADE_ID											30001000

// 3����������
#define HOMESUPPLY_THREESTRARWEAPON_PROBABILITY_BEGIN		33.22F	
#define HOMESUPPLY_THREESTRARWEAPON_PROBABILITY_END			40.72F
#define THREESTRARWEAPON_ID									30002000

// 3��ʥ�۸���
#define HOMESUPPLY_THREESTRARSTIGMATA_PROBABILITY_BEGIN		40.73F
#define HOMESUPPLY_THREESTRARSTIGMATA_PROBABILITY_END		63.23F
#define THREESTRARSTIGMATA_ID								30003000

// ��������
#define HOMESUPPLY_EVOLVEMATERIAL_PROBABILITY_BEGIN			63.24F
#define HOMESUPPLY_EVOLVEMATERIAL_PROBABILITY_END			77.99F
#define EVOLVEMATERIAL_ID									30004000

// �������
#define HOMESUPPLY_EXPERIENCEMATERIAL_PROBABILITY_BEGIN		78.00F
#define HOMESUPPLY_EXPERIENCEMATERIAL_PROBABILITY_END		92.74F
#define EXPERIENCEMATERIAL_ID								30005000

// ��Ҳ���
#define HOMESUPPLY_GOLDMATERIAL_PROBABILITY_BEGIN			92.75F
#define HOMESUPPLY_GOLDMATERIAL_PROBABILITY_END				100.00F    // 100.12������ƫ����0.12��
#define GOLDMATERIAL_ID										30006000




//************** ExpandSupply probability **************//
#define EXPANDSUPPLY_CODE									102
// �޶�S��ɫ����
#define EXPANDSUPPLY_LIMITSGRADE_PROBABILITY_BEGIN			0.0F
#define EXPANDSUPPLY_LIMITSGRADE_PROBABILITY_END			1.50F	
#define LIMITSGRADE_ID										50003000

// SP��ɫ����
#define EXPANDSUPPLY_SPGRADE_PROBABILITY_BEGIN				1.51F				
#define EXPANDSUPPLY_SPGRADE_PROBABILITY_END				6.01F	
#define	SPGRADE_ID											40003000							

// A��ɫ���� ��3����ɫ��ӣ�Ӧ�õ�ʱ����Ҫ�ٴν��з��ࣩ
#define EXPANDSUPPLY_AGRADE_PROBABILITY_BEGIN				6.02F		
#define EXPANDSUPPLY_AGRADE_PROBABILITY_END					21.02F

// SP��ɫ��Ƭ����
#define EXPANDSUPPLY_SPGRADE_FRAGMENT_PROBABILITY_BEGIN		21.03F
#define EXPANDSUPPLY_SPGRADE_FRAGMENT_PROBABILITY_END		36.03F

// A��ɫ��Ƭ����	(ͬ����3����ɫ���)
#define EXPANDSUPPLY_AGRADE_FRAGMENT_PROBABILITY_BEGIN		36.04F
#define EXPANDSUPPLY_AGRADE_FRAGMENT_PROBABILITY_END		39.37F	

// ��������
#define EXPANDSUPPLY_EVOLVEMATERIAL_PROBABILITY_BEGIN		39.38F
#define EXPANDSUPPLY_EVOLVEMATERIAL_PROBABILITY_END			45.38F

// �������
#define EXPANDSUPPLY_EXPERIENCEMATERIAL_PROBABILITY_BEGIN	45.39F
#define EXPANDSUPPLY_EXPERIENCEMATERIAL_PROBABILITY_END		62.89F

// ��Ҳ���
#define EXPANDSUPPLY_GOLDMATERIAL_PROBABILITY_BEGIN			62.90F
#define EXPANDSUPPLY_GOLDMATERIAL_PROBABILITY_END			100.00F    // 99.4������ƫ����0.6��



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
