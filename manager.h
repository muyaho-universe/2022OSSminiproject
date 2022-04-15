#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

void searchProduct(struct Product *p[], int count, int type); // 제품이름 검색
int load_product(struct Product* p[], char* filename); //  파일 읽기
void save_product(struct Product* p[], char* filename, int count); //  제품 정보 저장


