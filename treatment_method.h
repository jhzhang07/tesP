#pragma once
#include"medical_record.h"
struct time_;
struct body_check;
struct used_medicine;
struct being_hospitalized;

struct treatment_method {
	
	struct body_check * a;//���
	
	int number_of_body_check; //����˼���
	
	int total_price_of_body_check; //����ܼ۸�
	
	
	
	struct used_medicine * b;//��ҩ
	
	int number_of_medicine; //ҩƷ������
	
	int total_price_of_medicine; //ҩƷ�ܼ۸�
	
	
	struct being_hospitalized  * c;//סԺ

};


struct body_check{ //���
	char name[21];
	int price;//ÿ��������
	struct body_check * next;//һ�������Ŀ
};
typedef struct body_check * Body_check;

typedef struct medicine * Medicine;

struct medicine { //ҩ
	char name[21];
	int price; //ÿ��ҩ�۸�
	struct medicine * next;//һ��ҩ
};


struct used_medicine { //��ҩ
	//struct medicine * used_m;
	char name[21];
	int amount;
	int price;
	struct used_medicine * next;
};



struct being_hospitalized{
	struct time_ * time_bein; //סԺ����
	struct time_ * time_beout; //Ԥ�Ƴ�Ժ����
	int expecting_days; //��סԺ����
	int pledge;//Ѻ��
};
