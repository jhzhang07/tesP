#include<stdlib.h>
#include<stdio.h>
#include"medical_record.h"
#include"doctor.h"
#include"f.h"
#include"patient.h"
#include"treatment_method.h"
#include"���ļ���������.h"
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;



int main1() {

	
	
	/*
	int day[7] = { 1,1 };
	Doctor p11 = make_doctor("��ΰ", "����ҽʦ", "������", 01100, 2, day, &o);
	Doctor p22 = make_doctor("���", "����ҽʦ", "������", 01101, 2, day, &o); 
	Doctor p33 = make_doctor("�", "����ҽʦ", "������", 01102, 2, day, &o);

	//print_current_doctor(o.head);

	
	Medicine *m1;

	struct list_of_medince *m_list;

	m_list = (struct list_of_medince *)malloc(sizeof(struct list_of_medince));
	
	m_list->head = NULL;
	
	add_for_medicine_list(m_list, "��ҩ", 3);
	add_for_medicine_list(m_list, "��ҩ", 111110);
	add_for_medicine_list(m_list, "Aҩ", 8040);
	add_for_medicine_list(m_list, "Bҩ", 7000);
	add_for_medicine_list(m_list, "CҩƬ", 100000);

	//print_current_medicine(m_list->head);
	*/
	
	
	list_of_record * p1 = (struct list_of_record *)malloc(sizeof(struct list_of_record));
	list_of_medince * m_list = (struct list_of_medince *)malloc(sizeof(struct list_of_medince));
	list_of_doctor * d_list = (struct list_of_doctor *)malloc(sizeof(struct list_of_doctor));
	f1(d_list);
	f2(m_list);
	printf("\n");
	
	
	f3(p1);

	Record ppp = p1->head;
	
	while (ppp->next != NULL) {

		printrecord(ppp);
		printf("\n\n");
		ppp = ppp->next;

	}

	Turnover_check(p1);
	printf("\n\n");
	
	//print_historyrecord(p1->head, 1001);
	save(p1->head);
	
	
	
	free(p1);
	free(m_list);
	free(d_list);
	return 0;
	/*
	//int guahao_number = 1924;
	//delete_record(p1, guahao_number);

	Doctor_busy_check(p1,d_list);
	time_ timmmmm;
	time_t rawtime;
	struct tm *info;
	//char buffer[80];

	time(&rawtime);

	info = localtime(&rawtime);

	timmmmm.hour = info->tm_hour;
	timmmmm.minute = info->tm_min;
	timmmmm.day = info->tm_mday;
	timmmmm.month = info->tm_mon;

	
	int xxl=0;
	
	
	xxl = calculus_turnover_from_being_hospitalized(p1,timmmmm);//�ӻ���סԺ����Ǯ�����ݵ�ǰʱ��۳���ǰסԺ���ߵķ���
	
	
	Turnover_check(p1, xxl);
	printf("\n");
	print_historyrecord(p1->head, 101);
	printdoctor(p1->head, 11111);//��ҽ������
	printf("*******\n");
	printroom(p1->head, "������");
	save(p1->head);
	
	*/
	

}

