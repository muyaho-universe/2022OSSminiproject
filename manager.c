#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"
#include "product.h"

void searchProduct(struct Product *p[], int count, int type)
{
	char n_data[20], w_data[10];
    	int t_data, go = 0;





	if(type == 1 )
	{
    		printf("찾는 물건이름은? ");
		fgets(n_data, 20, stdin);
    		n_data[strlen(n_data)-1] = '\0';
    		
    		printf("*****************\n");
    		for (int i = 0; i < count; i++)
    		{
        		if (strstr(p[i]->name, n_data) != NULL)
        		{
            			printf("%d %d %s: %s %s %d\n", p[i]->num, p[i]->price, p[i]->name,p[i]->description, p[i]->weight, p[i]->type);
        		}
    		}
	}
	
	else if(type == 2) 
	{
		printf(" 찾는 물건 무게는?(단위까지 입력) ");
		fgets(w_data, 10, stdin);
    		w_data[strlen(w_data)-1] = '\0';
		printf("*****************\n");
    		for (int i = 0; i < count; i++)
    		{
        		if (strstr(p[i]->weight, w_data) != NULL)
        		{
            			readProduct(p[i]);
        		}
    		}		
	}

	else if(type == 3)
	{
		printf("찾는 물건의 배송 방법은?(1:새벽배송 /2:택배배송) ");
    		scanf("%d", &t_data);
    		printf("*****************\n");
    		for (int i = 0; i < count; i++)
    		{
        		if (p[i]->type == t_data) 
        		{
            			readProduct(p[i]);
        		}
    		}
	}

	else
	{
		printf("잘못된 검색타입입니다.\n");
	}	
}	// 제품이름 검색
int load_product(struct Product* p[], char* filename){
	FILE * fp;
    	int i = 0;




    	if(fp = fopen(filename, "r"))
    	{
        	while (!feof(fp)){
            	int t_price, t_num;     //temporary variable for reading from file
            	char t_name[20], t_des[100],t_weight[10] ;
            	int t_type;
            	int t = fscanf(fp,"%d",  &t_num);
		if (t<=0) break;
		fscanf(fp, "%d", &t_price);
		fgetc(fp);
		fgets(t_name, 20, fp);
		t_name[strlen(t_name)-1]='\0';
		fgets(t_des, 100, fp);
		t_des[strlen(t_des)-1]='\0';
		fgets(t_weight, 10, fp);
		t_weight[strlen(t_weight)-1] = '\0';
		fscanf(fp, "%d", &t_type);
            	p[i] = (struct Product*) malloc(sizeof(struct Product));
            	strcpy(p[i]->name, t_name);
	    	strcpy(p[i]->description, t_des);
	    	strcpy(p[i]->weight, t_weight);
            	p[i]->num = t_num;
            	p[i]->price = t_price;
            	p[i]->type = t_type;
            	i++;
        	}
        printf("=> 로딩성공!\n");
        fclose(fp);
    	}
    	else
	{
        	printf("\n=> 파일이 없습니다!\n");
    	}
    
    	return i;      
}	// 제품정보가 저장된 파일 읽기/ type에 따라 검색의 내용이 달라짐
void save_product(struct Product* p[], char* filename, int count){
	FILE * fp;
   	fp = fopen(filename, "w");
    	for ( int i = 0; i < count; i++){
		if (p[i]->isDel == 'Y') continue;
        	fprintf(fp,"%d\n %d\n %s\n %s\n %s\n %d\n \n", i + 1, p[i]->price, p[i]->name, p[i]->description, p[i]->weight, p[i]->type);
    	}
    	fclose(fp);
    	printf("저장완료!\n");      
}	// 파일에 제품 정보 저장


   




       


















