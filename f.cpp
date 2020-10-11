#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f.h"
#include"medical_record.h"
#include<time.h>
#include<conio.h>
#include<graphics.h>
using namespace std;

struct time_ create_time(int month, int day, int hour, int minute)
{ //创建时刻
	struct time_ new_time;
	new_time.month = month;
	new_time.day = day;
	new_time.hour = hour;
	new_time.minute = minute;
	return new_time;
}

void show_exchanged_money(int m) {//内部均以分计算

	 struct money_ mon;
	 mon.a = m / 100;
	 mon.b = m / 10 % 10;
	 mon.c = m % 10;
	 if (mon.a == 0 && mon.b == 0) {
		 printf("%d 分", mon.c);
	 }
	 else if (mon.a == 0 && mon.b != 0 && mon.c == 0) {
		 printf("%d 角", mon.b);
	 }
	 else if (mon.a != 0 && mon.b== 0 && mon.c != 0) {
		 printf("%d 元 %d 分", mon.a, mon.c);
	 }
	 else if (mon.a != 0 && mon.b != 0 && mon.c == 0) {
		 printf("%d 元 %d 角", mon.a, mon.b);
	 }
	 else if (mon.a == 0 && mon.b != 0) {
		 printf("%d 角 %d 分", mon.b, mon.c);
	 }
	 else if (mon.a != 0 && mon.b != 0) {
		 printf("%d 元 %d 角 %d 分", mon.a, mon.b, mon.c);
	 }
	 else if (mon.a != 0 && mon.b == 0&&mon.c==0) {
		 printf("%d 元", mon.a);
	 }

 }


 patient make_patient(const char name[21], int age, int id,int userid)//存储患者信息
{
	struct patient temp;
	strcpy_s(temp.name_of_patient, name);
	temp.age_of_patient = age;
	temp.id_of_patient = id;
	temp.userid = userid;
	return temp;
}

  doctor * make_doctor(const char name[21], const char level[21], const char room[21], int id, int work_time , int work_day, struct list_of_doctor * list_)
 { //添加新医生
	Doctor dc;
	 Doctor temp;

	//生成新结点
	 dc = (struct doctor *)malloc(sizeof(struct doctor));
	 strcpy_s(dc->name_of_doctor, name);
	 strcpy_s(dc->level, level);
	 strcpy_s(dc->room, room);
	 dc->id_of_doctor = id;
	 dc->next = NULL;
	 dc->work_time = work_time;
	 dc->work_day = work_day;
	 /*for (i = 0; i < 7; i++)
	 {
		 dc->work_day[i] = work_day[i];
	 }
	 */
	 //添加到list_of_doctor
	 temp = list_->head;
	 if (temp == NULL)
	 {
		 list_->head = dc;
	 }
	 else
	 {
		 while (temp->next != NULL)
		 {
			 temp = temp->next;
		 }
		 temp->next = dc;
	 }
	 return dc;
 }

   treatment_method make_treatment_method(struct body_check *bc, struct used_medicine *um, struct  being_hospitalized *bh)
  { //体检、用药、住院
	  struct treatment_method tm;
	  struct body_check *temp1;
	  struct used_medicine *temp2;
	  int num_c = 0;//体检检查数量
	  int cost_c = 0;
	  int num_m = 0;//开药数量
	  int cost_m = 0;
	  tm.a = bc;
	  tm.b= um;
	  tm.c = bh;
	  temp1 = bc;
	  while (bc != NULL)
	  {
		  num_c++;
		  cost_c += bc->price;
		  bc = bc->next;
	  }
	  tm.number_of_body_check = num_c;
	  tm.total_price_of_body_check = cost_c;
	  temp2 = um;
	  while (um != NULL)
	  {
		  num_m++;
		  //cost_m += um->amount * um->used_m->price;
		  um = um->next;
	  }
	  tm.number_of_medicine = num_m;
	  tm.total_price_of_medicine= cost_m;
	  return tm;
  }




   struct body_check * make_check(struct body_check * p, const char name[21], int price)
   { //增加体检项目
	   struct body_check * temp;
	  temp = (struct body_check *)malloc(sizeof(struct body_check));
	   strcpy_s(temp->name, name);
	  temp->price = price;
	   temp->next = NULL;
	   if (p!= NULL)
		   p->next = temp;
	   return temp;
   }



   void add_for_medicine_list(struct list_of_medince * list_, const char name[21], int price)//增加药物种类
   { 
	   Medicine temp;
	   Medicine m;
	   m = (struct medicine *)malloc(sizeof(struct medicine));
	   strcpy_s(m->name,name);
	   m->price= price;
	   m->next = NULL;
	   temp = list_->head;
	   if (temp == NULL)
	   {
		   list_->head = m;
	   }
	   else
	   {
		   while (temp->next != NULL)
		   {
			   temp = temp->next;
		   }
		   temp->next = m;
	   }
   }


    used_medicine * make_used_medicine(struct used_medicine *p, struct medicine * m, int amount)
   { //增加使用的药
	   struct used_medicine * used;
	   used = (struct used_medicine *)malloc(sizeof(struct used_medicine));
	  // used->used_m = m;
	   used->amount = amount;
	   used->next = NULL;
	   if (p != NULL)
		   p->next = used;
	   return used;
   }


	struct  being_hospitalized  make_being_hospitalized(int in_month, int in_day, int in_hour, int in_minute, int out_month, int out_day, int out_hour, int out_minute)
	{ //添加住院信息
		struct  being_hospitalized new_in;
		struct time_ in_time;
		struct time_ out_time;
		in_time = create_time(in_month, in_day, in_hour, in_minute);
		out_time = create_time(out_month, out_day, out_hour, out_minute);
		new_in.time_bein= &in_time;//time_gai
		new_in.time_beout = &out_time;//time_gai
		new_in.expecting_days = ((out_month - in_month) * 30 + (out_day - in_day));//简化一下
		/*
		算钱
		*/


		if (out_hour > 8)
			new_in.expecting_days++;
		new_in.pledge = 20000 * new_in.expecting_days;//题目中暗示每天200元 200元=20000分 内部计算均以分为单位
		if (new_in.pledge < 100000)//押金一直不低于最低为1000元
			
			new_in.pledge = 100000;
		
		return new_in;
	}
	
	




	
	bool add_record(int flag, struct list_of_record *list, struct patient pa, struct doctor doc, struct treatment_method tm, struct time_ guahao_time)//添加一条记录
	{ 
		struct medical_record * temp;
		struct medical_record * new_record;
		//生成新结点
		new_record = (struct medical_record *)malloc(sizeof(struct medical_record));
		
		new_record->Patient = pa;
		new_record->Doc = doc;
		new_record->current_time = guahao_time;
		new_record->next = NULL;
		
		/*//new_record->T_m.a = (struct body_check *)malloc(sizeof(struct body_check));new_record->T_m.b = (struct used_medicine*)malloc(sizeof(struct used_medicine));new_record->T_m.c = (struct being_hospitalized *)malloc(sizeof(struct being_hospitalized));new_record->T_m.c->time_bein = (struct time_ *)malloc(sizeof(struct time_));new_record->T_m.c->time_beout = (struct time_ *)malloc(sizeof(struct time_));//内存泄漏问题
		*/
		switch (flag)
		{
		case 1:
			new_record->T_m.b = NULL;
			new_record->T_m.c = NULL;
			new_record->T_m.a = (struct body_check *)malloc(sizeof(struct body_check));
			strcpy(new_record->T_m.a->name, tm.a->name);
			new_record->T_m.a->next = NULL;
			new_record->T_m.a->price = tm.a->price;
			new_record->T_m.total_price_of_body_check = tm.a->price;
			new_record->T_m.number_of_body_check = 1;
			break;
		case 2:
			new_record->T_m.a = NULL;
			new_record->T_m.c = NULL;
			new_record->T_m.b = (struct used_medicine*)malloc(sizeof(struct used_medicine));
			strcpy(new_record->T_m.b->name, tm.b->name);
			new_record->T_m.b->next = NULL;
			new_record->T_m.b->price = tm.b->price;
			new_record->T_m.number_of_medicine = 1;
			new_record->T_m.total_price_of_medicine = tm.b->price;
			break;
		case 3:
			new_record->T_m.a = NULL;
			new_record->T_m.b = NULL;
			new_record->T_m.c = (struct being_hospitalized *)malloc(sizeof(struct being_hospitalized));
			new_record->T_m.c->time_bein = (struct time_ *)malloc(sizeof(struct time_));
			new_record->T_m.c->time_beout = (struct time_ *)malloc(sizeof(struct time_));//内存泄漏问题
			new_record->T_m.c->expecting_days = tm.c->expecting_days;
			new_record->T_m.c->pledge = tm.c->pledge;
			new_record->T_m.c->time_bein->day = tm.c->time_bein->day;
			new_record->T_m.c->time_bein->hour = tm.c->time_bein->hour;
			new_record->T_m.c->time_bein->minute = tm.c->time_bein->minute;
			new_record->T_m.c->time_bein->month = tm.c->time_bein->month;
			
			new_record->T_m.c->time_beout->day = tm.c->time_beout->day;
			new_record->T_m.c->time_beout->hour = tm.c->time_beout->hour;
			new_record->T_m.c->time_beout->minute = tm.c->time_beout->minute;
			new_record->T_m.c->time_beout->month = tm.c->time_beout->month;
			
			break;
		}
		
		//添加到record_list
		temp = list->head;
		if (temp == NULL)
		{
			list->head = new_record;
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_record;
		}
		return true;
	}

	bool delete_record(struct list_of_record * list, int id) { //删除挂号码为....的记录
		Record temp = NULL;
		Record previous = NULL;
		temp = list->head;
		if (temp == NULL)
			return true;
		while (temp != NULL) {
			if (temp->Patient.id_of_patient == id) { //发现要删除的记录
				if (temp == list->head) {
					list->head = list->head->next;
				
				}
				else {
					previous->next = temp->next;
				}
				//free(temp);//挂号号是唯一的
				return true;
			}
			previous = temp;
			temp = temp->next;
		}
		return 0;
	}

	extern int ihateyou=0;
	void Doctor_busy_check(Record head,Doctor dp)
	{
		int work_times[30]; //医生最多三十位
		memset(work_times, 0, sizeof(work_times));
		int i = 0;
		Record  temp_time=head;
		/*Doctor  temp_d;
		
		temp_d = d_list->head;*/
		/*char str[50];
		sprintf(str,"统计每位医生的出诊情况和工作繁忙程度：\n");
		outtextxy(100, 80, str);*/
	     
		
		while (temp_time != NULL)
		{
				if (temp_time->Doc.id_of_doctor == dp->id_of_doctor)
					work_times[i]++;
				temp_time = temp_time->next;
		}
			char str1[50];
			sprintf(str1,"我院%s%s（工号：%d）共出诊了%d次\n", dp->level, dp->name_of_doctor, dp->id_of_doctor, work_times[i]);
			outtextxy(100, 120+90*ihateyou, str1);
			ihateyou++;
			if (ihateyou == 4) {
				Sleep(2000);
				ihateyou = 0;
				cleardevice();
				fanhuituxing();
			}
		
	}
	
	

	
	int calculus_turnover_from_being_hospitalized(list_of_record * list, time_ now) { //从患者住院挣的钱，根据当前时间扣除当前住院患者的费用
		Record temp;
		struct time_ *temp_time;//time_gai
		int start_time;
		int end_time;
		int now_time;
		int earned_money = 0; //收的钱
		
		now_time = change_timetoint(&now);//转换成int长数，便于比较
		
		temp = list->head;
		
		while (temp != NULL) {
			if (temp->T_m.c != NULL) {
				temp_time = temp->T_m.c->time_bein;//time_gai
				start_time = change_timetoint(temp_time);
				int days = ((now.month - (*temp_time).month) * 30 + (now.day - (*temp_time).day));//
				temp_time = temp->T_m.c->time_beout;
				end_time = change_timetoint(temp_time);

				if (now_time >= start_time && now_time <= end_time) {
					if (temp->T_m.c->pledge >= 100000) {


						temp->T_m.c->pledge = temp->T_m.c->pledge - 20000 * days; //扣除押金
						if (temp->T_m.c->pledge < 100000) {
							temp->T_m.c->pledge = 100000;
						}

					}
					else if (temp->T_m.c->pledge < 100000) { //押金小于1000
						temp->T_m.c->pledge = 100000;
					}
					earned_money = earned_money + 20000 * days;//一天收200元
				}
			}
			temp = temp->next;
		}
		return earned_money;
	}
	
	
	
	int Turnover_check(struct list_of_record * list) { //医院的营业额
		
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
		
		int turnover_from_being_hospitalized = 0;
		turnover_from_being_hospitalized = calculus_turnover_from_being_hospitalized(list, timmmmm);//从患者住院挣的钱，根据当前时间扣除当前住院患者的费用

		Record temp;
		temp = list->head;
		int total = 0;
		while (temp != NULL) {
			if (temp->T_m.a != NULL) {
				total += temp->T_m.total_price_of_body_check;
			}
			else if(temp->T_m.b!=NULL)
			{
				total += temp->T_m.total_price_of_medicine;
			}
			temp = temp->next;
		}

		int sum = total+ turnover_from_being_hospitalized;
		return sum;
		printf("实时营业额：");
	//show_exchanged_money(sum);//以元角分形式展示
	
	}

	/*
	9.24 增加打印全部医生&药品 函数
	*/
	void print_current_doctor(Doctor head)
	{
		int j = 0;
		Doctor p = head;
		printf("每位医生：\n");

		while (p != NULL)
		{
			
			printf( "%s %s %s 工号: %d \n", p->name_of_doctor, p->level, p->room, p->id_of_doctor);
			
			p = p->next;
		}
		printf("\n");
		
	}

	void print_current_medicine(Medicine head)
	{
		Medicine p = head;
		printf("目前本医院药品信息如下:\n \n");
		while (p != NULL)
		{
			printf_s("%s ", p->name);
			show_exchanged_money(p->price);
			printf_s("\n");
			p = p->next;
		}

	}





		/*
		挂号时间

		一个患者挂多个医生问题
		
		挂号
	
		患者编号

		怎么读入？怎么交互？
	
		医院money 放全局里
		*/




	/*
	print print print print print print print print print print print print print print print

	*/

     extern int iloveyou = 0;//患者个数
	 void printrecord(Record p)
	 {

		 char str[200];
		 char str12[50];
		 sprintf(str12, "%s", (p->Patient).name_of_patient);
		 outtextxy(15, 70 + 92 * iloveyou, str12);
		 sprintf(str, " %d    %d   %s  %s %s",  (p->Patient).age_of_patient, (p->Patient).id_of_patient, p->Doc.name_of_doctor, p->Doc.level, p->Doc.room);
		 outtextxy(125, 70 + 92 * iloveyou, str);
		 //printf("%s %s %s %d ", p->Doc.name_of_doctor, p->Doc.level, p->Doc.room, p->Doc.id_of_doctor);
												   //输出基本信息名字等。。。
		 if (p->T_m.a != NULL)               //a为检查的结构体头指针，非空则输出身体检查信息
		 {
			 body_check* temp = p->T_m.a;//用一个临时的bodycheck指针表示当前记录的身体检查信息
			 while (temp != NULL)
			 {
				 char str1[30];
				 char str12[30];
				 sprintf(str1, "%s", temp->name);
				 sprintf(str12, "%d", temp->price);//打印检查名称
				 //printf("%d", );//打印检查单价
				 outtextxy(20, 116 + 92 * iloveyou, "检查");
				 outtextxy(125, 116 + 92 * iloveyou, str1);
				 outtextxy(225, 116 + 92 * iloveyou, "单价");
				 outtextxy(305, 116 + 92 * iloveyou, str12);

				 temp = temp->next;//检查信息链表后移到下一项检查

			 }
			 //printf("检查项数%d  ", p->T_m.number_of_body_check);
			 char str2[20];
			 sprintf(str2, "总费用： %d   ", p->T_m.total_price_of_body_check);
			 outtextxy(415, 116 + iloveyou * 92, str2);
			 iloveyou++;
		 }
		 if (p->T_m.b != NULL)//b为开药的结构体链表头指针，若不空则输出用药信息
		 {
			 used_medicine* temp = p->T_m.b;
			 while (temp != NULL)
			 {
				 char str3[50];
				 char str32[50];
				 sprintf(str3, "%s", temp->name);
				 sprintf(str32, "%d", temp->price);//打印用药名称
				 outtextxy(20, 116 + 92 * iloveyou, "用药");
				 outtextxy(225, 116 + 92 * iloveyou, "单价");
				 outtextxy(125, 116 + 92 * iloveyou, str3);
				 outtextxy(315, 116 + 92 * iloveyou, str32);

				 //printf("%d", );//打印用药单价
				 //printf("%d", temp->amount);//打印用药数量
				 temp = temp->next;//药品链表后移到下一项用药

			 }
			 char str4[20];
			 sprintf(str4, "总费用： %d", p->T_m.total_price_of_medicine);//打印总费用；
			 outtextxy(415, 116 + iloveyou * 92, str4);
			 iloveyou++;

		 }
		 if (p->T_m.c != NULL)//c为住院信息的结构体指针，若非空则输出住院信息；
		 {
			 being_hospitalized* temp = p->T_m.c;
			 //printf("入院时间： ");
			 char str5[100];
			 sprintf(str5, "住院时间%d.%d %d:%d", temp->time_bein->month, temp->time_bein->day, temp->time_bein->hour, temp->time_bein->minute);
			 outtextxy(20, 116 + iloveyou * 92, str5);
			 //printf("预计出院日期：");

			 char str6[100];
			 sprintf(str6, "-%d.%d %d：%d 住院押金：%d", temp->time_beout->month, temp->time_beout->day, temp->time_beout->hour, temp->time_beout->minute, temp->pledge);
			 outtextxy(225, 116 + 92 * iloveyou, str6);

			 /*printf("住院押金：");
			 printf("%d", temp->pledge);*/
			 iloveyou++;
		 }
		 //printf("\n");
		 if (iloveyou == 4) {
			 Sleep(4000);
			 iloveyou = 0;
			 cleardevice();
			 biaoge();
			 shuru();
			 fanhuituxing();
			 line(120, 10, 120, 424);//患者名
			 outtextxy(15, 25, "患者姓名");
			 line(200, 10, 200, 424);//患者挂号号码
			 outtextxy(125, 25, "年龄");
			 line(300, 10, 300, 424);//科室名
			 outtextxy(205, 25, "挂号码");
			 line(410, 10, 410, 424);//医生名
			 outtextxy(305, 25, "医生名");
			 line(510, 10, 510, 424);
			 outtextxy(415, 25, "医生等级");
			 outtextxy(512, 25, "科室名");
		 }

	 }
	
	
	/*
	换成一个八位数 月份（两位）+日期（两位）+小时（两位）+分钟（两位）
	*/
	

	void save(Record head)
	{
		if (head == NULL) return;
		Record p = head;
		FILE* fp= fopen("jhzhang.txt", "w");
		if (fp==NULL)
		{
			printf("打开文件失败\n");
			return;
		}
		int flag = 0;
		while (p)
		{
					
			//fprintf(fp, "%s %d %d %d %s %s %s %d %d %d %d %s %d %d %s %d %d %d %d %d %d %d", p->Patient.name_of_patient, p->Patient.age_of_patient, p->Patient.id_of_patient, p->Patient.userid, p->Doc.name_of_doctor, p->Doc.level, p->Doc.room, p->Doc.id_of_doctor, p->Doc.work_time, p->Doc.work_day, p->T_m.number_of_body_check, p->T_m.a->name, p->T_m.a->price, p->T_m.number_of_medicine, p->T_m.b->name, p->T_m.b->price, p->T_m.c->expecting_days, p->T_m.c->pledge, p->T_m.c->time_bein->month, p->T_m.c->time_bein->day, p->T_m.c->time_bein->hour, p->T_m.c->time_bein->minute);
			
			fprintf(fp, "%s %d %d %d %s %s %s %d %d %d", p->Patient.name_of_patient, p->Patient.age_of_patient, p->Patient.id_of_patient, p->Patient.userid, p->Doc.name_of_doctor, p->Doc.level, p->Doc.room, p->Doc.id_of_doctor, p->Doc.work_time, p->Doc.work_day);

			if (p->T_m.a != NULL)
			{
				flag = 1;
			}
			else if (p->T_m.b != NULL)
			{
				flag = 2;
			}
			else if (p->T_m.c != NULL)
			{
				flag = 3;
			}
			fprintf(fp, " %d ", flag);
			switch (flag)
			{
			case 1:
				fprintf(fp, "%s %d", p->T_m.a->name, p->T_m.a->price);
				fprintf(fp, "\n");
				break;
			case 2:
				fprintf(fp, "%s %d", p->T_m.b->name, p->T_m.b->price);
				fprintf(fp, "\n");
				break;
			case 3: //p->T_m.c->time_bein->month
				fprintf(fp, "%d %d %d %d %d %d", p->T_m.c->expecting_days, p->T_m.c->pledge, p->T_m.c->time_bein->month, p->T_m.c->time_bein->day, p->T_m.c->time_bein->hour, p->T_m.c->time_bein->minute);
				fprintf(fp, "\n");
				break;
			default:
				printf("错误");
				break;
			}
			//fprintf(fp,"\n");
			p = p->next;
		}
		fclose(fp);
		printf("保存成功！");
		/*
		p = head;
		Record curp = head;
		while (curp != NULL)
		{
			curp = p->next;
			free(p);
			p = curp;
			curp = curp->next;
		}
	   */
	}



	void printroom(Record head,const char *r)/*r为科室信息字符串首地址*/
	{
		int flag = 0;
		Record p = head;//诊疗信息链表头指针
		//char r[21];
		/*printf("请输入要查找的科室：");
		scanf("%s", r);*/
		while (p != NULL) //链表不为空则进行查找
		{
			if (strcmp((p->Doc).room, r) == 0) //比较所查科室字段与当前指针所指结点是否一致，一致则输出否则p=p->next；
			{
				printrecord(p);
				flag = 1;
			}

			p = p->next;
		}
		if (flag == 0)
			printf("不存在此科");//遍历了整个诊疗信息链表没有发现相对应的科室；
	}

	void printdoctor(Record head, int iddoc)//按医生查找
	{
		int flag = 0;
		Record p = head;
		/*int iddoc;
		printf("请输入要查询的医生id:");
		scanf_s("%d", &iddoc);*/
		while (p != NULL)
		{
			if (p->Doc.id_of_doctor == iddoc)
			{
				printrecord(p);
				printf("\n");
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0)
			printf("查无此人");


	}
	void print_historyrecord(Record head, int uid)//查询某患者历史信息
	{
		int flag = 0;
		/*uid*/ 
		/*printf("请输入患者id:");//user id；
		scanf_s("%d", &uid);*/
		Record p = head;
		while (p != NULL)
		{
			if (p->Patient.userid == uid)
			{
				printrecord(p);
				printf("\n\n");
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0)
			printf("无此患者历史信息");
		
	}

	int change_timetoint(struct time_* p) //把时间结构体换成一个长数
	{
		int sum = 0;
		sum = p->month * 1000000 + p->day * 10000 + p->hour * 100 + p->minute;
		return sum;
	}
	/*
	换成一个八位数 月份（两位）+日期（两位）+小时（两位）+分钟（两位）
	*/
	void print_timerecord(Record head, int mo, int da, int ho, int mi, int mo1, int da1, int ho1, int mi1) //打印某时间段内的时间信息；前四个参为开始时间，后四个参为截止时间
	{

		Record p = head;
		int sum1 = 0, sum2 = 0;
		/*int mo, da, ho, mi, sum1 = 0, sum2 = 0;
		printf("请输入月份：");
		scanf_s("%d", &mo);
		printf("\n请输入日期：");
		scanf_s("%d", &da);
		printf("\n请输入小时：");
		scanf_s("%d", &ho);
		printf("\n请输入分钟：");
		scanf_s("%d", &mi);*/
		sum1 = mo * 1000000 + da * 10000 + ho * 100 + mi;
		/*printf("请输入结束月份：");
		scanf_s("%d", &mo);
		printf("\n请输入结束日期：");
		scanf_s("%d", &da);
		printf("\n请输入小时：");
		scanf_s("%d", &ho);
		printf("\n请输入分钟：");
		scanf_s("%d", &mi);*/
		sum2 = mo1 * 1000000 + da1 * 10000 + ho1 * 100 + mi1;

		while (p != NULL)
		{
			if (change_timetoint(&(p->current_time)) >= sum1 && change_timetoint(&(p->current_time)) <= sum2)
				printrecord(p);
			p = p->next;
		}

	}

















