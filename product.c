#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"

struct Product* get_product(int count){
	struct Product* p = (struct Product*)malloc(sizeof(struct Product));
	char temp_name[20];
	char temp_des[100];
    	p->num = count+1;
    	printf("제품명을 적어주세요 :  ");
	fgets(temp_name, 20, stdin);
    	temp_name[strlen(temp_name)-1] = '\0';
	strcpy(p->name, temp_name);
	printf("제품 설명을 적어주세요 : ");
	fgets(temp_des, 100, stdin);
    	temp_des[strlen(temp_des)-1] = '\0';
	strcpy(p->description, temp_des);
	printf("제품의 무게를 적어주세요 : ");
    	scanf("%s", p->weight);
    	printf("제품의 가격을 적어주세요 :  ");
    	scanf("%d", &p->price);
    	printf("제품의 배송방법을 적어주세요 : ");
	scanf("%d", &p->type);
  	p->isDel = 'N';
    	printf("=> 저장완료!!\n");
    	return p;

}	// 제품을 추가하는 함수
void readProduct(struct Product* p){
	printf("%d %d %s: %s %s %d\n", p->num, p->price, p->name, p->description, p->weight, p->type);      
}	// 하나의 제품 출력 함수
int listProduct(struct Product* p[], int count){
	printf("*****************\n");
    	for (int i = 0; i < count; i++)
    	{
        	if(p[i]->isDel == 'Y') continue;
		readProduct(p[i]);
    	}
	return 1;
} // 전체 등록된 제품 리스트 출력
int selectMenu(){
    	int menu;
    	printf("\n*** Product Menu Select ***\n");
    	printf("1. 제품조회\n");
    	printf("2. 제품추가\n");
    	printf("3. 파일저장\n");
    	printf("4. 제품검색\n"); 
    	printf("5. 제품삭제\n"); 
	printf("6. 제품수정\n");
    	printf("0. 종료\n\n");
    	printf("=> 원하는 메뉴는? ");
    	scanf("%d", &menu);
    	while (getchar()!='\n');
    	return menu;
}
void deleteProduct(struct Product *p[], int i){
	p[i]->isDel = 'Y';
}
struct Product* updateProduct(int selectNum){
    
    struct Product* p = (struct Product*)malloc(sizeof(struct Product));
    p->num = selectNum ;
     char temp_name[20];
        char temp_des[100];
       
        printf("제품명을 적어주세요 :  ");
        fgets(temp_name, 20, stdin);
        temp_name[strlen(temp_name)-1] = '\0';
        strcpy(p->name, temp_name);
        printf("제품 설명을 적어주세요 : ");
        fgets(temp_des, 100, stdin);
        temp_des[strlen(temp_des)-1] = '\0';
        strcpy(p->description, temp_des);
        printf("제품의 무게를 적어주세요 : ");
        scanf("%s", p->weight);
        printf("제품의 가격을 적어주세요 :  ");
        scanf("%d", &p->price);
        printf("제품의 배송방법을 적어주세요 : ");
        scanf("%d", &p->type);

        printf("=> 저장완료!!\n");
    return p;
}
