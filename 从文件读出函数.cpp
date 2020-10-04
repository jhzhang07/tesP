#include <stdlib.h>
#include<stdio.h>
#include"medical_record.h"
#include"doctor.h"
#include"f.h"
#include"patient.h"
#include"treatment_method.h"
#include "从文件读出函数.h"
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS



using namespace std;

struct time_;

void f1(list_of_doctor * doc_in) { //读出医生信息
	
	//list_of_doctor o=*doc_in;

	doc_in->head = NULL;

	FILE * file = NULL;

	file = fopen("aaaaa.txt", "r");


	char p1[21];
	char p3[21];
	char p2[21];
	int temp_id, temp_work_time, work_day;

	if (file != NULL)
		printf("文件aaaaa.txt打开成功\n");
	while (!feof(file))
	{

		fscanf(file, "%s %s %s %d %d %d", p1, p2, p3, &temp_id, &temp_work_time,&work_day);
		/*int temp[7];
		for (int i = 6; i >= 0; i--)
		{
			temp[i] = p4_work_day_number % 10;
			p4_work_day_number = p4_work_day_number / 10;
		}
		*/
		Doctor kkk = make_doctor(p1, p2, p3, temp_id, temp_work_time,work_day, doc_in);

	}

	fclose(file);

	print_current_doctor(doc_in->head);



}



void f2(struct list_of_medince * m_list) { //读出药品信息
	

	//struct list_of_medince *m_list;

	//m_list = (struct list_of_medince *)malloc(sizeof(struct list_of_medince));

	m_list->head = NULL;
	

	FILE * file = NULL;

	file = fopen("bbbbb.txt", "r");


	char p[21];
	
	int temp;

	if (file != NULL)
		printf("文件bbbbb.txt打开成功\n");
	while (!feof(file))
	{

		fscanf(file, "%s %d", p,&temp);//输入时 金额全部以 分 为单位
		add_for_medicine_list(m_list, p, temp);

	}

	fclose(file);

	print_current_medicine(m_list->head);

}



void f3(list_of_record * lr_in) {

	//list_of_record lr=* lr_in;
	lr_in->head = NULL;

	FILE * file = NULL;

	file = fopen("jhzhang.txt", "r");

	struct patient jh1;
	struct doctor jh2;
	struct treatment_method jh3;
	//struct treatment_method *jh3;
	//jh3=(struct treatment_method *)malloc(sizeof(struct treatment_method));
	jh3.a = (struct body_check *)malloc(sizeof(struct body_check));
	jh3.b = (struct used_medicine*)malloc(sizeof(struct used_medicine));
	jh3.c = (struct being_hospitalized *)malloc(sizeof(struct being_hospitalized));
	jh3.c->time_bein = (struct time_ *)malloc(sizeof(struct time_));
	jh3.c->time_beout = (struct time_ *)malloc(sizeof(struct time_));//内存泄漏问题
	jh3.a->next = NULL;
	jh3.b->next = NULL;
	jh3.number_of_body_check = 1;
	jh3.number_of_medicine = 1;
	if (file != NULL)
		printf("文件jhzhang.txt打开成功\n");
	int month1, day1, hour1, minute1;
	struct time_ timmmmm;
	int flag = 0;
	int num=0;
	while ((fscanf(file, "%d", &num)) != EOF)
	{
		
		fscanf(file, "%s %d %d %d %s %s %s %d %d %d", jh1.name_of_patient, &jh1.age_of_patient, &jh1.id_of_patient, &jh1.userid, jh2.name_of_doctor, jh2.level, jh2.room, &jh2.id_of_doctor, &jh2.work_time, &jh2.work_day);
		fscanf(file, "%d", &flag);//检测flag
		switch (flag)
		{
		case 1:
			fscanf(file, "%s %d", jh3.a->name, &jh3.a->price);
			jh3.total_price_of_body_check = jh3.a->price;
			break;
		case 2:
			fscanf(file, "%s %d", jh3.b->name, &jh3.b->price);
			jh3.total_price_of_medicine = jh3.b->price;
			jh3.b->amount = 1;
			break;
		case 3:
			fscanf(file, "%d %d %d %d %d %d", &jh3.c->expecting_days, &jh3.c->pledge, &month1, &day1, &hour1, &minute1);
			jh3.c->time_bein->day = day1;//住院时间
			jh3.c->time_bein->hour = hour1;
			jh3.c->time_bein->minute = minute1;
			jh3.c->time_bein->month = month1;

			jh3.c->time_beout->day = day1 + jh3.c->expecting_days;//出院时间
			jh3.c->time_beout->hour = hour1;
			jh3.c->time_beout->minute = minute1;
			jh3.c->time_beout->month = month1;

			break;
		default:
			printf("输入有误");
			break;
		}
		//fscanf(file, "%s %d %d %d %s %s %s %d %d %d %d %s %d %d %s %d %d %d %d %d %d %d", jh1.name_of_patient, &jh1.age_of_patient, &jh1.id_of_patient, &jh1.userid, jh2.name_of_doctor, jh2.level, jh2.room, &jh2.id_of_doctor, &jh2.work_time, &jh2.work_day, &jh3.number_of_body_check, jh3.a->name, &jh3.a->price, &jh3.number_of_medicine, jh3.b->name, &jh3.b->price, &jh3.c->expecting_days, &jh3.c->pledge, &month1, &day1, &hour1, &minute1);
		time_t rawtime;
		struct tm *info;
		time(&rawtime);

		info = localtime(&rawtime);

		timmmmm.hour = info->tm_hour;
		timmmmm.minute = info->tm_min;
		timmmmm.day = info->tm_mday;
		timmmmm.month = info->tm_mon;

		add_record(flag, lr_in, jh1, jh2, jh3, timmmmm); //jh4是挂号时间
		
	}

	fclose(file);
	free(jh3.c->time_bein);
	free(jh3.c->time_beout);
	free(jh3.a);
	free(jh3.b);
	free(jh3.c);

}