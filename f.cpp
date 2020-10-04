#include<stdio.h>
#include<malloc.h>


using namespace std;

struct list_ {

	int value;
	struct list_ *next;


};

typedef list_ * List;


void insert(List head, int a, int b) {//若a=0则从头插入

	List temp = head;
	for (int i = 0; i < a; i++) {
		if (temp == NULL) {
			return;
		}
		temp = temp->next;
	}
	List L = (List)malloc(sizeof(list_));
	L->value = b;
	L->next = temp->next;
	temp->next = L;

}
void delete_(List head, int a) {
	if (a == 0)return;
	List temp = head;
	for (int i = 1; i < a; i++) {
		if (temp == NULL) {
			return;
		}
		temp = temp->next;

	}
	List  del = temp->next;
	temp->next = temp->next->next;
	free(del);
}
int main() {

	int a = 0;
	scanf("%d", &a);

	List head_, p, q;
	head_ = NULL;//头指针初始为空 

	for (int i = 0; i < a; i++) {

		p = (struct list_ *)malloc(sizeof(struct list_));//创建一个新节点 
		scanf("%d", &p->value);
		p->next = NULL;//给新节点设置后继指针指向空 
		if (head_ == NULL) {
			head_ = p;//如果这是第一个创建的节点，则头指针指向这个节点 
		}
		else {
			q->next = p;//如果不是第一个创建的节点，则将上一个节点的后继指针指向当前节点 
		}
		q = p;//指针q也指向当前节点 
	}

	List head = (struct list_ *)malloc(sizeof(struct list_));//创建一个新节点 
	head->next = head_;//哨兵结点

	int b = 0;
	scanf("%d", &b);
	int temp1[2] = { 0 };
	int temp;
	for (int j = 0; j < b; j++) {

		scanf("%d", &temp);
		if (temp == 0) {
			scanf("%d", &temp1[0]);
			scanf("%d", &temp1[1]);
			insert(head, temp1[0], temp1[1]);
		}
		else if (temp == 1)
		{
			scanf("%d", &temp1[0]);
			delete_(head, temp1[0]);
		}


	}
	List p3 = head->next;
	while (p3)
	{
		printf("%d ", p3->value);
		p3 = p3->next;
	}







	return 0;
}