#pragma once
#include"doctor.h"
#include"medical_record.h"
#include"patient.h"
#include"treatment_method.h"


patient make_patient(const char name[21], int age, int id, int userid);
//ok
doctor * make_doctor(const char name[21], const char level[21], const char room[21], int id, int work_time, int work_day, list_of_doctor * list_);
//ok
treatment_method make_treatment_method(body_check * bc, used_medicine * um, being_hospitalized * bh);
//ok
body_check * make_check(body_check * previous, const char name[21], int price);
//ok
void add_for_medicine_list(list_of_medince * list_, const char name[21], int price);
//ok
used_medicine * make_used_medicine(used_medicine * p, medicine * m, int amount);
//ok
being_hospitalized make_being_hospitalized(int in_month, int in_day, int in_hour, int in_minute, int out_month, int out_day, int out_hour, int out_minute);
//ok
bool add_record(int flag ,list_of_record * list, patient pa, doctor doc, treatment_method tm, struct time_ guahao_time);
//ok
bool delete_record(list_of_record * list, int id);
//yes
void Doctor_busy_check(Record head,Doctor dp);
//yes
int Turnover_check(list_of_record * list);
//ok
time_ create_time(int month, int day, int hour, int minute);
void show_exchanged_money(int m);
//ok
int calculus_turnover_from_being_hospitalized(list_of_record * list, time_ now);
//ok
void  print_current_doctor(Doctor head);
//ok
void print_current_medicine(Medicine head);
//ok




//添加

int change_timetoint(struct time_* p);//把时间结构体换成一个长数

void printrecord(Record p);//打印给定记录（1个）
//ok
void save(Record head);//把当前链表保存到文件；


void print_timerecord(Record head, int mo, int da, int ho, int mi, int mo1, int da1, int ho1, int mi1); //打印某时间段内的时间信息；前四个参为开始时间，后四个参为截止时间//打印某时间段内的时间信息

void print_historyrecord(Record head, int uid);//查询某患者历史信息
//ok
void printdoctor(Record head, int iddoc);//查询某医生的诊疗信息
//ok
void printroom(Record head, const char* r);//打印科室
//ok


void fanhuituxing();
void fanhui();
void shuru();
void biaoge();
void xiayiye();


