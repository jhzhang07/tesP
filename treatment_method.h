#pragma once
#include"medical_record.h"
struct time_;
struct body_check;
struct used_medicine;
struct being_hospitalized;

struct treatment_method {
	
	struct body_check * a;//体检
	
	int number_of_body_check; //检查了几项
	
	int total_price_of_body_check; //检查总价格
	
	
	
	struct used_medicine * b;//开药
	
	int number_of_medicine; //药品种类数
	
	int total_price_of_medicine; //药品总价格
	
	
	struct being_hospitalized  * c;//住院

};


struct body_check{ //体检
	char name[21];
	int price;//每项体检费用
	struct body_check * next;//一堆体检项目
};
typedef struct body_check * Body_check;

typedef struct medicine * Medicine;

struct medicine { //药
	char name[21];
	int price; //每种药价格
	struct medicine * next;//一堆药
};


struct used_medicine { //用药
	//struct medicine * used_m;
	char name[21];
	int amount;
	int price;
	struct used_medicine * next;
};



struct being_hospitalized{
	struct time_ * time_bein; //住院日期
	struct time_ * time_beout; //预计出院日期
	int expecting_days; //拟住院天数
	int pledge;//押金
};
