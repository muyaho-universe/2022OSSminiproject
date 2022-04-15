#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//CRUD의 기능만을 가지고 있는 헤더 파일
#ifndef _PRODUCT_H_
#define _PRODUCT_H_
struct Product
{
        int num; // 번호
        char name[20]; //제품명
        char description[100]; // 설명
        char weight[10]; // 중량
        int price;  // 가격
        int type;   // 배송방법
	char isDel; // 삭제 여부
};

int selectMenu();
struct Product* get_product(int count); // 제품을 추가하는 함수
void readProduct(struct Product* p); // 하나의 제품 출력 함수
int listProduct(struct Product *p[], int count); // 전체 등록된 제품 리스트 출력
void deleteProduct(struct Product *p[], int i); // 원하는 번호의 상품을 삭제 가능 
struct Product* updateProduct(int selectNum); // 업데이트 하기
#endif
