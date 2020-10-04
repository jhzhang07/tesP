#pragma once
#include<stdio.h>


struct doctor
{
	char name_of_doctor[21];
	char level[21];//级别
	char room[21]; //科室
	//char Doctor_id[5];//科室（2位）级别（1位）四个级别  序 （2位） 
	int id_of_doctor;
	int work_time; //一周出诊天数
	int work_day;//周一到周日 出诊为1不出诊为0  例如1100000表示周一周二上班
	struct doctor * next;//为医生创建链表，因为要用到医生的操作很多
};

typedef struct doctor * Doctor; //方便之后，可以直接Doctor p

