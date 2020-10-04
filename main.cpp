#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include"medical_record.h"
#include"doctor.h"
#include"f.h"
#include"patient.h"
#include"treatment_method.h"
#include"从文件读出函数.h"
#include"time.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;
MOUSEMSG m;//鼠标操作结构体
LOGFONT z;//字体操作结构体

struct list_of_record totalrecord;
struct list_of_doctor totaldoctor;
struct list_of_medince totalmedicine;
extern int iloveyou;//printrecord
extern int ihateyou;//doctorcheck
void loading();//进入动画
void luruhanshu();//录入图形函数
void xiugaihanshu();//修改图形函数
void shanchuhanshu();//删除图形函数
void keshizlhanshu();//科室诊疗图形函数
void yishengzlhanshu();//医生诊疗图形函数
void huanzhezlhanshu();//患者诊疗图形函数
void yingyeehanshu();//营业额图形函数
void huanzhebbhanshu();//患者报表图形函数
void shiduanzlhanshu();//时段诊疗图形函数
void yishengczfmhanshu();//医生出诊繁忙图形函数
void baocunhanshu();//保存图形函数
void loading() {
	int i;
	char cover[] = "软件八班第一组";
		outtextxy(200, 200, cover);//定位输出
	char load[] = "医院管理程序正在启动";
	outtextxy(80, 240,load);
	for(i=0;i<10;i++){
		outtextxy(250+10*i, 240, ".");
		Sleep(500);//延迟，单位MS
	}
}
void fanhuituxing() {//返回图案
	fillrectangle(605, 380, 730, 435);//左上右下
	char fanhui1[] = "返回主菜单";
	outtextxy(610, 400, fanhui1);
}
void fanhui() {//返回对应操作
	while (true) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (605 <= m.x&&m.x <= 730 && 380 <= m.y&&m.y <= 435) {
				FlushMouseMsgBuffer();
				break;
			}
		}
	}
	cleardevice();//清屏
}
void shuru() {//输入图案
	fillrectangle(620, 300, 715, 350);//画填充矩形
	outtextxy(640, 315, "输入");
}

void biaoge() {//表格
	int bb1;
	rectangle(10, 10, 580, 424);
	for (bb1 = 1; bb1 <= 8; (bb1)++) {
		line(10, 10 + 46 * bb1, 580, 10 + 46 * bb1);
	}
}
void xiayiye() {//下一页图案
	fillrectangle(620, 230, 715, 270);
	outtextxy(630, 240, "下一页");
}
void wenjianluru() {//文件录入图案
	fillrectangle(620, 70, 715, 110);
	outtextxy(630, 80, "txt输入");
}

int menu() {//主菜单
	kaishi:
	cleardevice();
	fillrectangle(25, 35, 173, 115);//左上右下//此处可增加功能
	char luru[] = "录入信息";
	outtextxy(50, 70, luru);
	fillrectangle(25, 145, 173, 225);//左上右下
	char xiugai[] = "修改信息";
	outtextxy(50, 180, xiugai);
	fillrectangle(25, 255, 173, 335);//左上右下
	char shanchu[] = "删除信息";
	outtextxy(50, 290, shanchu);
	fillrectangle(20, 365, 173, 445);//左上右下
	char keshizl[] = "科室诊疗信息";
	outtextxy(30, 400, keshizl);
	fillrectangle(223, 35, 371, 115);//左上右下
	char yishengzl[] = "医生诊疗信息";
	outtextxy(225, 70, yishengzl);
	fillrectangle(223, 145, 371, 225);//左上右下
	char huanzhezl[] = "患者诊疗记录";
	outtextxy(225, 180, huanzhezl);
	fillrectangle(225, 255, 371, 335);//左上右下
	char tongji[] = "营业额";
	outtextxy(260, 290, tongji);
	fillrectangle(223, 365, 371, 445);//左上右下
	char huanzhebb[] = "患者报表";
	outtextxy(240, 400, huanzhebb);
	fillrectangle(421, 35, 569, 115);//左上右下
	char tongji2[] = "时段诊疗记录";
	outtextxy(425, 70, tongji2);
	fillrectangle(421, 145, 569, 225);//左上右下
	char yishengcz[] = "医生出诊情况";
	outtextxy(425, 180, yishengcz);
	fillrectangle(421, 255, 569, 335);//左上右下
	char cunchu[] = "保存信息";
	outtextxy(450, 290, cunchu);
	outtextxy(450, 400, "软件八班zjh，zth，cw");


	while (true) {//保持鼠标点击一直可用
		m = GetMouseMsg();//获取鼠标点击信息
		if (m.uMsg == WM_LBUTTONDOWN) {//左键操作
			if (25 <= m.x&&m.x <= 173&& 35 <= m.y&&m.y <= 115) {//划定点击位置
				cleardevice();
				FlushMouseMsgBuffer();//刷新鼠标反馈信息
				luruhanshu();//录入函数
				goto kaishi;
			}
			else if (25 <= m.x&&m.x <= 173 && 145 <= m.y&&m.y <= 225) {
				cleardevice();
				FlushMouseMsgBuffer();
				xiugaihanshu();//修改函数
				goto kaishi;
			}
			else if (25 <= m.x&&m.x <= 173 && 255 <= m.y&&m.y <= 335) {
				cleardevice();
				FlushMouseMsgBuffer();
				shanchuhanshu();//删除函数
				goto kaishi;
			}
			else if (25 <= m.x&&m.x <= 173 && 365 <= m.y&&m.y <= 445) {
				cleardevice();
				FlushMouseMsgBuffer();
				keshizlhanshu();//科室诊疗查询函数
				goto kaishi;
			}
			else if (223<= m.x&&m.x <= 371 && 35 <= m.y&&m.y <= 115) {
				cleardevice();
				FlushMouseMsgBuffer();
				yishengzlhanshu();//医生诊疗查询函数
				goto kaishi;
			}
			else if (223 <= m.x&&m.x <= 371 && 145 <= m.y&&m.y <= 225) {
				cleardevice();
				FlushMouseMsgBuffer();
				huanzhezlhanshu();//患者诊疗查询函数
				goto kaishi;
			}
			else if (223 <= m.x&&m.x <= 371 && 255 <= m.y&&m.y <= 335) {
				cleardevice();
				FlushMouseMsgBuffer();
			    yingyeehanshu();//营业额函数
				goto kaishi;
			}
			else if (223 <= m.x&&m.x <= 371 && 365 <= m.y&&m.y <= 445) {
				cleardevice();
				FlushMouseMsgBuffer();
				huanzhebbhanshu();//患者报表函数
				goto kaishi;
			}
			else if (421<= m.x&&m.x <= 569 && 35 <= m.y&&m.y <= 115) {
				cleardevice();
				FlushMouseMsgBuffer();
				shiduanzlhanshu();//时段诊疗记录函数
				goto kaishi;
			}
			else if (421 <= m.x&&m.x <= 569 && 145<= m.y&&m.y <= 225) {
				cleardevice();
				FlushMouseMsgBuffer();
				yishengczfmhanshu();//医生出诊记录函数
				goto kaishi;
			}
			else if (421 <= m.x&&m.x <= 569 && 255 <= m.y&&m.y <= 335) {
				cleardevice();
				FlushMouseMsgBuffer();
				baocunhanshu();//保存函数
				goto kaishi;
			}
		}
	}

}
void luruhanshu() {
	wenjianluru();
	xiayiye();
	biaoge();
	shuru();
	fanhuituxing();

	//char han[] = "录入函数打开";//放函数
	//outtextxy(320, 100, han);//放函数
	//fillrectangle(240, 160, 480, 320);
	line(120, 10, 120, 424);//患者名
	outtextxy(15, 25, "患者姓名");
	line(200, 10, 200, 424);//患者挂号号码
	outtextxy(125, 25, "年龄");
	line(300, 10, 300, 424);//科室名
	outtextxy(205, 25, "挂号码");
	line(410, 10, 410, 424);//医生名
	outtextxy(305, 25, "挂医生名");
	line(490, 10, 490, 424);
	outtextxy(415, 25, "科室名");
	outtextxy(495, 25, "诊疗情况");

	//outtextxy(320,240,"输入");

	char luru1char[20];//患者名字
	char luru2char[20];//患者年龄
	char luru3char[20];//挂号ID
	char luru4char[20];//患者id


	char luru5char[20];//医生姓名
	char luru6char[20];//医生级别；
	char luru7char[20];//科室；
	char luru8char[20];//医生工号；转int
	char luru9char[20];//出诊天数；转int
	char luru10char[20];//哪天出诊1100110,转int


	/*char luru11char[5];//检查项数，转int*/
	char luru12char[20];//检查名称
	char luru13char[20];//检查单价,转int


	//char luru14char[20];//用药种类数，转int
	char luru15char[20];//用药名称
	char luru16char[20];//药品单价，转int
	//char luru17char[20];//此药品用量,转int

	char luru18char[20];//拟住院天数，转int
	char luru19char[20];//押金，转int
	char luru20char[20];//入院时间——月,转int
	char luru21char[20];//入院时间——天，转int
	char luru22char[20];//入院时间——时，转int
	char luru23char[20];//入院时间——分,转int

	char luru24char[20];//flag 1.代表后面输入检查  2.代表后面输入为用药 3.代表其后的诊疗信息为住院

	int luru2int,/*患者年龄*/ luru3int,/*挂号ID*/luru4int/*患者ID*/, luru8int/*医生工号*/, luru9int/*出诊天数*/, luru10int/*出诊数组*/;
	int luru11int/*检查项数*/, luru13int/*检查单价*/, luru14int/*用药种类数*/, luru16int/*药品单价*/;
	int luru18int/*拟住院天数*/, luru19int/*押金*/, luru20int/*入院时间月*/, luru21int/*入院时间天*/, luru22int/*入院时间时*/, luru23int/*入院时间分*/;
	int luru24int;/*flag*/
/*
	struct patient pa1;
	struct doctor doc1;
	struct treatment_method tm1;//ab完成，c指针没赋值（住院信息）
	tm1.total_price_of_body_check = 0;//总检查费用初始化为零
	tm1.total_price_of_medicine = 0;//总用药费用初始化为零


	tm1.a = (struct body_check *)malloc(sizeof(struct body_check));
	tm1.b = (struct used_medicine*)malloc(sizeof(struct used_medicine));
	tm1.c = (struct being_hospitalized *)malloc(sizeof(struct being_hospitalized));
	tm1.c->time_bein = (struct time_ *)malloc(sizeof(struct time_));
	tm1.c->time_beout = (struct time_ *)malloc(sizeof(struct time_));//内存泄漏问题
	tm1.a->next = NULL;
	tm1.b->next = NULL;
*/
	int i = 0;
	struct patient pa1;
	struct doctor doc1;
	struct treatment_method tm1;//ab完成，c指针没赋值（住院信息）
	tm1.total_price_of_body_check = 0;//总检查费用初始化为零
	tm1.total_price_of_medicine = 0;//总用药费用初始化为零



addstart:

	tm1.a = (struct body_check *)malloc(sizeof(struct body_check));
	tm1.b = (struct used_medicine*)malloc(sizeof(struct used_medicine));
	tm1.c = (struct being_hospitalized *)malloc(sizeof(struct being_hospitalized));
	tm1.c->time_bein = (struct time_ *)malloc(sizeof(struct time_));
	tm1.c->time_beout = (struct time_ *)malloc(sizeof(struct time_));//内存泄漏问题
	tm1.a->next = NULL;
	tm1.b->next = NULL;
	while (true) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (620 <= m.x&&m.x <= 715 && 70 <= m.y&&m.y <= 110) {
				outtextxy(610, 120, "txt已读取");//txt输入
			}//需要链表配合
			if (620 <= m.x&&m.x <= 715 && 230 <= m.y&&m.y <= 270) {//下一页
				i = 0;
				cleardevice();
				xiayiye();
				biaoge();
				shuru();
				fanhuituxing();
				line(120, 10, 120, 470);//患者名
				outtextxy(15, 25, "患者姓名");
				line(200, 10, 200, 470);//患者挂号号码
				outtextxy(125, 25, "年龄");
				line(300, 10, 300, 470);//科室名
				outtextxy(205, 25, "挂号码");
				line(410, 10, 410, 470);//医生名
				outtextxy(305, 25, "挂医生名");
				line(490, 10, 490, 470);
				outtextxy(415, 25, "科室名");
				outtextxy(495, 25, "诊疗情况");
				goto addstart;
			}
			if (620 <= m.x&&m.x <= 715 && 300 <= m.y&&m.y <= 350) {//手动输入
				FlushMouseMsgBuffer();
				InputBox(luru1char, 20, "请输入患者姓名");//文本输入框
				outtextxy(15, 70 + 45 * i, luru1char);//70+45

				InputBox(luru2char, 20, "请输入患者年龄");
				luru2int = atoi(luru2char);//luru2int
				outtextxy(125, 70 + 45 * i, luru2char);
				InputBox(luru3char, 20, "请输入挂号号码");
				outtextxy(205, 70 + 45 * i, luru3char);
				luru3int = atoi(luru3char);//luru3int

				InputBox(luru4char, 20, "请输入患者ID");
				luru4int = atoi(luru4char);//luru5int


				InputBox(luru5char, 20, "请输入医生姓名");
				outtextxy(305, 70 + 45 * i, luru5char);
				InputBox(luru6char, 20, "请输入医生级别");
				InputBox(luru7char, 20, "请输入医生所属科室");
				outtextxy(415, 70 + 45 * i, luru7char);
				InputBox(luru8char, 20, "请输入医生工号");
				luru8int = atoi(luru8char);//luru8int

				InputBox(luru9char, 20, "请输入医生出诊天数");
				luru9int = atoi(luru9char);

				InputBox(luru10char, 20, "请输入医生出诊日期为(7位1/0组成):");
				luru10int = atoi(luru10char);
				//判断输入正确性———————————————————
				while (luru10int < 1000000 || luru10int>1111111)
				{
					InputBox(luru10char, 20, "请重新输入医生出诊日期为(7位1/0组成):");
					luru10int = atoi(luru10char);
				};

				/*InputBox(luru11char, 20, "请输入需付款项");
				luru11int = atoi(luru11char);
				outtextxy(415, 70 + 45 * i, luru11char);*/
				/*InputBox(luru12char, 20, "请输入检查名称");

				InputBox(luru13char, 20, "请输入检查单价");
				luru13int = atoi(luru13char);*/

				/*InputBox(luru14char, 20, "请输入");
				luru14int = atoi(luru14char);
				outtextxy(495, 70 + 45 * i, luru14char);*/
				/*InputBox(luru15char, 20, "请输入用药名称");

				InputBox(luru16char, 20, "请输入用药单价");
				luru16int = atoi(luru16char);

				InputBox(luru17char, 20, "请输入用药量");
				luru17int = atoi(luru17char);*/
			zhenliaostart:
				InputBox(luru24char, 20, "诊疗情况（1-检查，2-用药，3-住院)");//选择错误需重选
				luru24int = atoi(luru24char);//luru24int 为flag
				if (luru24int == 1) {
					outtextxy(495, 70 + 45 * i, "检查");
				}
				else if (luru24int == 2) {
					outtextxy(495, 70 + 45 * i, "用药");
				}
				else if (luru24int == 3) {
					outtextxy(495, 70 + 45 * i, "住院");
				}
				else if (luru24int != 1 && luru24int != 2 && luru24int != 3) {
					goto zhenliaostart;
				}


				switch (luru24int)//switch执行过后成功建立了个tm1
				{

				case 1:
					/*InputBox(luru11char, 20, "请输入患者检查项数");
					luru11int = atoi(luru11char);*/
					luru11int = 1;                       //每次只检查一项
					tm1.number_of_body_check = luru11int;
					//建立检查链表表头，b_chead,赋值给tm1.a

					InputBox(luru12char, 20, "请输入检查名称");

					InputBox(luru13char, 20, "请输入检查单价");
					luru13int = atoi(luru13char);
					strcpy(tm1.a->name, luru12char);
					tm1.a->price = luru13int;

					tm1.total_price_of_body_check = luru13int;//首项检查费用

					free(tm1.b);
					tm1.b = NULL;
					free(tm1.c->time_bein);
					free(tm1.c->time_beout);
					free(tm1.c);
					tm1.c = NULL;//只有检查成立(a)另外两项指针(b.c)为NULL
					break;



				case 2:

					luru14int = 1;                            //每次只用一种药
					tm1.number_of_medicine = luru14int;

					InputBox(luru15char, 20, "请输入用药名称");

					InputBox(luru16char, 20, "请输入用药单价");
					luru16int = atoi(luru16char);


					strcpy(tm1.b->name, luru15char);
					tm1.b->price = luru16int;
					tm1.b->amount = 1;

					tm1.total_price_of_medicine = luru16int;//第一个药钱


					free(tm1.a);
					tm1.a = NULL;
					free(tm1.c->time_bein);
					free(tm1.c->time_beout);
					free(tm1.c);
					tm1.c = NULL;


					break;
					//——————————————————————————————————
				case 3:
					InputBox(luru18char, 20, "拟住院天数");
					luru18int = atoi(luru18char);

					InputBox(luru19char, 20, "押金");
					luru19int = atoi(luru19char);

					InputBox(luru20char, 20, "入院时间（）月");
					luru20int = atoi(luru20char);

					while (luru20int < 0 || luru20int>11)
					{

						InputBox(luru20char, 20, "输入有误，请重新输入入院时间（）月");
						luru20int = atoi(luru20char);
					};

					InputBox(luru21char, 20, "入院时间（）日");
					luru21int = atoi(luru21char);

					while (luru21int < 1 || luru21int>30)
					{
						InputBox(luru21char, 20, "输入有误请重新输入入院时间（）日");
						luru21int = atoi(luru21char);
					};

					InputBox(luru22char, 20, "入院时间（）时");
					luru22int = atoi(luru22char);

					while (luru22int < 0 || luru22int>24)
					{

						InputBox(luru22char, 20, "输入有误，请重新输入入院时间（）时");
						luru22int = atoi(luru22char);
					};

					InputBox(luru23char, 20, "入院时间（）分");
					luru23int = atoi(luru23char);

					while (luru23int < 0 || luru23int>60)
					{

						InputBox(luru23char, 20, "输入有误，请重新输入入院时间（）分");
						luru23int = atoi(luru23char);
					};

					tm1.c->expecting_days = luru18int;
					tm1.c->pledge = luru19int;

					tm1.c->time_bein->day = luru21int;//住院时间
					tm1.c->time_bein->hour = luru22int;
					tm1.c->time_bein->minute = luru23int;
					tm1.c->time_bein->month = luru20int;

					tm1.c->time_beout->day = luru21int + tm1.c->expecting_days;//出院时间
					tm1.c->time_beout->hour = luru22int;
					tm1.c->time_beout->minute = luru23int;
					tm1.c->time_beout->month = luru20int;

					free(tm1.a);
					tm1.a = NULL;
					free(tm1.b);
					tm1.b = NULL;//只有住院信息（c），其余两项（a.b）为null

					break;
				default:
					printf("error");

				}//switch 完成
				//建立一个patient
				strcpy(pa1.name_of_patient, luru1char);
				pa1.age_of_patient = luru2int;
				pa1.id_of_patient = luru3int;
				pa1.userid = luru4int;
				//patient 建立完成

				//建立一个医生
				strcpy(doc1.name_of_doctor, luru5char);
				strcpy(doc1.level, luru6char);
				strcpy(doc1.room, luru7char);
				doc1.id_of_doctor = luru8int;
				doc1.work_time = luru9int;
				doc1.work_day = luru10int;//不用数组了
				//一个医生建立完毕；

				time_  curtim1;
				time_t rawtime;
				struct tm* info;
				//char buffer[80];

				time(&rawtime);

				info = localtime(&rawtime);

				curtim1.hour = info->tm_hour;
				curtim1.minute = info->tm_min;
				curtim1.day = info->tm_mday;
				curtim1.month = info->tm_mon;
				//建立了一个time

				add_record(luru24int, &totalrecord, pa1, doc1, tm1, curtim1);
				/*
				free(tm1.c->time_bein);
				free(tm1.c->time_beout);
				free(tm1.a);
				free(tm1.b);
				free(tm1.c);
				*/
				i++;
				goto addstart;
			}
			else if (605 <= m.x&&m.x <= 730 && 380 <= m.y&&m.y <= 435) {//返回
				FlushMouseMsgBuffer();
				return;
			}
		}
	}

	fanhui();
}
//录入函数完成

void xiugaihanshu() {
	biaoge();
	line(120, 10, 120, 470);
	outtextxy(15, 25, "挂号号码");
	shuru();
	fanhuituxing();
	char xiugai1char[20];
	int xiugai1int;
xiugaistart:
	while (true) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (620 <= m.x&&m.x <= 715 && 300 <= m.y&&m.y <= 350) {
				FlushMouseMsgBuffer();
				InputBox(xiugai1char, 20, "请输入需要修改的挂号号码");
				xiugai1int = atoi(xiugai1char);//xiugai1int
				delete_record(&totalrecord, xiugai1int);//先删除待修改信息
				cleardevice();//清屏
				luruhanshu();//重新录入

				goto xiugaistart;
			}
			else if (605 <= m.x&&m.x <= 730 && 380 <= m.y&&m.y <= 435) {
				FlushMouseMsgBuffer();
				return;
			}
		}
	}
	fanhui();
}
void shanchuhanshu() {
	xiayiye();
	biaoge();
	line(120, 10, 120, 470);
	outtextxy(15, 25, "挂号号码");
	outtextxy(125, 25, "诊疗信息状态（存在或已删除）");
	shuru();
	fanhuituxing();
	char shanchu1char[20];
	int shanchu1int;
	int ii = 0;
shanchustart:
	while (true) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (620 <= m.x && m.x <= 715 && 230 <= m.y && m.y <= 270) {//下一页
				ii = 0;
				cleardevice();
				xiayiye();
				biaoge();
				line(120, 10, 120, 470);
				outtextxy(15, 25, "挂号号码");
				outtextxy(125, 25, "诊疗信息状态（存在或已删除）");
				shuru();
				fanhuituxing();
				goto shanchustart;
			}
			if (620 <= m.x&&m.x <= 715 && 300 <= m.y&&m.y <= 350) {
				FlushMouseMsgBuffer();
				InputBox(shanchu1char, 20, "请输入需要修改的挂号号码");
				outtextxy(15, 70 + 46 * ii, shanchu1char);
				outtextxy(140, 70 + 46 * ii, "删除成功");
				shanchu1int = atoi(shanchu1char);//shanchu1int
				delete_record(&totalrecord, shanchu1int);//调用删除
				//save(totalrecord.head);
				ii++;
				goto shanchustart;
			}
			else if (605 <= m.x&&m.x <= 730 && 380 <= m.y&&m.y <= 435) {
				FlushMouseMsgBuffer();
				return;
			}
		}
	}
	fanhui();
}
void keshizlhanshu() {
	biaoge();
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
	shuru();
	fanhuituxing();
	char keshizl1[20];
	iloveyou = 0;
keshizlstart:
	while (true) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (620 <= m.x&&m.x <= 715 && 300 <= m.y&&m.y <= 350) {
				FlushMouseMsgBuffer();
				InputBox(keshizl1, 20, "请输入需要查询的科室");//keshizl1
				printroom(totalrecord.head, keshizl1);//调用函数
				
				goto keshizlstart;
			}
			else if (605 <= m.x&&m.x <= 730 && 380 <= m.y&&m.y <= 435) {
				FlushMouseMsgBuffer();
				return;
			}
		}
	}
	fanhui();
}
void yishengzlhanshu() {
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
	biaoge();
	shuru();
	fanhuituxing();
	char yishengzl1char[20];
	int yishengzl1int;
	iloveyou = 0;
yishengzlstart:
	while (true) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (620 <= m.x&&m.x <= 715 && 300 <= m.y&&m.y <= 350) {
				FlushMouseMsgBuffer();
				InputBox(yishengzl1char, 20, "请输入需要查询的医生id");
				yishengzl1int = atoi(yishengzl1char);//yishengzlzl1
				printdoctor(totalrecord.head, yishengzl1int);//d调用医生打印
				goto yishengzlstart;
			}
			else if (605 <= m.x&&m.x <= 730 && 380 <= m.y&&m.y <= 435) {
				FlushMouseMsgBuffer();
				return;
			}
		}
	}
	fanhui();
}
void huanzhezlhanshu() {
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
	biaoge();
	shuru();
	fanhuituxing();
	char huanzhezl1char[20];
	int huanzhezl1int;
	iloveyou=0;
huanzhezlstart:
	while (true) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			 if (620 <= m.x&&m.x <= 715 && 300 <= m.y&&m.y <= 350) {
				FlushMouseMsgBuffer();
				InputBox(huanzhezl1char, 20, "请输入需要查询的患者ID");
				huanzhezl1int = atoi(huanzhezl1char);//yishengzlzl1
				print_historyrecord(totalrecord.head, huanzhezl1int);//打印某患者历史诊疗信息
				goto huanzhezlstart;
			}
			else if (605 <= m.x&&m.x <= 730 && 380 <= m.y&&m.y <= 435) {
				FlushMouseMsgBuffer();
				return;
			}
		}
	}
	fanhui();
}
void yingyeehanshu() {
	fillrectangle(620, 300, 715, 350);
	outtextxy(640, 315, "输出");
	fanhuituxing();
	while (true) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (620 <= m.x&&m.x <= 715 && 300 <= m.y&&m.y <= 350) {
				double i =Turnover_check(&totalrecord) / (double)100;
				char dou[30];
				sprintf(dou, "%.2f 元", i);
				outtextxy(300, 200, dou);//
			
			}
			else if (605 <= m.x&&m.x <= 730 && 380 <= m.y&&m.y <= 435) {
				FlushMouseMsgBuffer();
				return;
			}
		}
	}
	fanhui();

}
void huanzhebbhanshu() {
	fillrectangle(620, 300, 715, 350);
	outtextxy(640, 315, "输出");
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
	biaoge();
	fanhuituxing();
	/*char huanzhebb1char[20];
	int huanzhebb1int;*/
	iloveyou = 0;
	Record temp;
	temp = totalrecord.head;
huanzhebbstart:
	while (true) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (620 <= m.x && m.x <= 715 && 300 <= m.y && m.y <= 350) {
				FlushMouseMsgBuffer();
				while (temp != NULL)
				{
					printrecord(temp);
					temp = temp->next;

				}//函数
				goto huanzhebbstart;
			}

			else if (605 <= m.x && m.x <= 730 && 380 <= m.y && m.y <= 435) {
				FlushMouseMsgBuffer();
				return;
			}
		}
	}
	fanhui();
}
void shiduanzlhanshu() {
	biaoge();
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
	shuru();
	fanhuituxing();
	char shiduanzl1char[20];
	char shiduanzl2char[20];
	char shiduanzl3char[20];
	char shiduanzl4char[20];
	char shiduanzl5char[20];
	char shiduanzl6char[20];
	char shiduanzl7char[20];
	char shiduanzl8char[20];
	int shiduanzl1int;
	int shiduanzl2int;
	int shiduanzl3int;
	int shiduanzl4int;
	int shiduanzl5int;
	int shiduanzl6int;
	int shiduanzl7int;
	int shiduanzl8int;
	iloveyou = 0;
shiduanzlstart:
	while (true) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (620 <= m.x&&m.x <= 715 && 300 <= m.y&&m.y <= 350) {
				FlushMouseMsgBuffer();
				InputBox(shiduanzl1char, 20, "请输入查询开始月份");
				shiduanzl1int = atoi(shiduanzl1char);
				while (shiduanzl1int < 0 || shiduanzl1int>11)
				{
					InputBox(shiduanzl1char, 20, "输入错误，请输入查询开始月份");
					shiduanzl1int = atoi(shiduanzl1char);

				};
				InputBox(shiduanzl2char, 20, "请输入查询开始日");
				shiduanzl2int = atoi(shiduanzl2char);
				while (shiduanzl2int < 1 || shiduanzl2int>30)
				{
					InputBox(shiduanzl2char, 20, "输入错误，请输入查询开始日");
					shiduanzl2int = atoi(shiduanzl2char);

				};
				InputBox(shiduanzl3char, 20, "请输入查询开始小时");
				shiduanzl3int = atoi(shiduanzl3char);
				while (shiduanzl3int > 23 || shiduanzl3int < 0)
				{
					InputBox(shiduanzl3char, 20, "输入错误，请输入查询开始小时");
					shiduanzl3int = atoi(shiduanzl3char);

				}
				InputBox(shiduanzl4char, 20, "请输入查询开始分钟");
				shiduanzl4int = atoi(shiduanzl4char);
				while (shiduanzl4int < 1 || shiduanzl4int>59)
				{
					InputBox(shiduanzl4char, 20, "输入有误，请输入查询开始分钟");
					shiduanzl4int = atoi(shiduanzl4char);
				}
				InputBox(shiduanzl5char, 20, "请输入查询结束月份");
				shiduanzl5int = atoi(shiduanzl5char);
				while (shiduanzl5int < 0 || shiduanzl5int>11)
				{
					InputBox(shiduanzl5char, 20, "输入错误，请输入查询结束月份");
					shiduanzl5int = atoi(shiduanzl5char);

				}
				InputBox(shiduanzl6char, 20, "请输入查询结束日");
				shiduanzl6int = atoi(shiduanzl6char);
				while (shiduanzl6int < 1 || shiduanzl6int>30)
				{
					InputBox(shiduanzl6char, 20, "输入错误，请输入查询结束日");
					shiduanzl6int = atoi(shiduanzl6char);
				}
				InputBox(shiduanzl7char, 20, "请输入查询结束小时");
				shiduanzl7int = atoi(shiduanzl7char);
				while (shiduanzl7int > 23 || shiduanzl7int < 0)
				{
					InputBox(shiduanzl7char, 20, "输入错误，请输入查询结束小时");
					shiduanzl7int = atoi(shiduanzl7char);
				}
				InputBox(shiduanzl8char, 20, "请输入查询结束分钟");
				shiduanzl8int = atoi(shiduanzl8char);
				while (shiduanzl8int < 1 || shiduanzl8int>59)
				{
					InputBox(shiduanzl8char, 20, "输入错误，请输入查询结束分钟");
					shiduanzl8int = atoi(shiduanzl8char);
				}
				
				print_timerecord(totalrecord.head, shiduanzl1int, shiduanzl2int, shiduanzl3int, shiduanzl4int, shiduanzl5int, shiduanzl6int, shiduanzl7int, shiduanzl8int);
				//打印时间区间
				
				goto shiduanzlstart;
			}
			else if (605 <= m.x&&m.x <= 730 && 380 <= m.y&&m.y <= 435) {
				FlushMouseMsgBuffer();
				return;
			}
		}
	}
	fanhui();
}

void yishengczfmhanshu() {
	Doctor docp = totaldoctor.head;
	ihateyou = 0; 
	while (docp != NULL)
	{
		Doctor_busy_check(totalrecord.head,docp);//放函数
		docp = docp->next;
	}
	fanhuituxing();
	fanhui();
}
void baocunhanshu() {
	fillrectangle(620, 300, 715, 350);
	outtextxy(640, 315, "保存");
	fanhuituxing();
baocunstart:
	while (true) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (620 <= m.x&&m.x <= 715 && 300 <= m.y&&m.y <= 350) {
				FlushMouseMsgBuffer();
				save(totalrecord.head);
				outtextxy(20, 20, "保存成功");//放保存函数
				goto baocunstart;
			}
			else if (605 <= m.x&&m.x <= 730 && 380 <= m.y&&m.y <= 435) {
				FlushMouseMsgBuffer();
				return;
			}
		}
	}
	fanhui();
}

int main() {
	f3(&totalrecord);
	f1(&totaldoctor);
	initgraph(800, 480);//初始化绘图界面
	setbkcolor(BLUE);//设定背景颜色
	cleardevice();
	loading();
	setlinecolor(BLACK);//设置线条颜色
	setfillcolor(RGB(225, 165, 0));//设置填充颜色
	setbkmode(TRANSPARENT);//设置字体背景填充为透明
	settextstyle(25, 12, "黑体");//设置字体格式
	menu();
	_getch();
	return 0;
}


