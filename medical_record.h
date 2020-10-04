#pragma once
#include "patient.h"
#include "doctor.h"
#include "treatment_method.h"
/*
医疗记录单类

不在一个结构体里写太多，而是include上面3个文件，这样符合多文件规则

*/

struct time_ 
{ //时间
	int month;
	int day;
	int hour;
	int minute;
};

struct medical_record {
	struct patient Patient;
	struct doctor Doc;
	struct treatment_method T_m;

	struct medical_record *next;//指针域
	struct time_ current_time;

};

typedef struct  medical_record * Record; //方便之后，可以直接Record p




struct money_ {

	int  a;//元
	int  b;//角
	int  c;//分
	
};




struct list_of_doctor
{
	Doctor head;
};

struct list_of_medince { //记录药品目录
	
	Medicine head;
};

struct list_of_record
{
	Record head;
};

/*

输错了要提示






*/