#pragma once
#include "patient.h"
#include "doctor.h"
#include "treatment_method.h"
/*
ҽ�Ƽ�¼����

����һ���ṹ����д̫�࣬����include����3���ļ����������϶��ļ�����

*/

struct time_ 
{ //ʱ��
	int month;
	int day;
	int hour;
	int minute;
};

struct medical_record {
	struct patient Patient;
	struct doctor Doc;
	struct treatment_method T_m;

	struct medical_record *next;//ָ����
	struct time_ current_time;

};

typedef struct  medical_record * Record; //����֮�󣬿���ֱ��Record p




struct money_ {

	int  a;//Ԫ
	int  b;//��
	int  c;//��
	
};




struct list_of_doctor
{
	Doctor head;
};

struct list_of_medince { //��¼ҩƷĿ¼
	
	Medicine head;
};

struct list_of_record
{
	Record head;
};

/*

�����Ҫ��ʾ






*/