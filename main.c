#include <stdio.h>
#include "product.h"
#include "manager.h"

int NUM = 1;

int main(){
#ifdef DEBUG
	printf("You are running debugging mode now!\n You could find debug function at searchProduct function and load_product function.\n If you want to check, go to menu #4 or you would check when it run\n");
#endif
	struct Product* p[20];
	int count = 0, menu, type;
	int isLoaded;
    	int selectedNum;
    	int go;
    	char filename[100]="product.txt";

	count = load_product(p, filename);
#ifdef DEBUG
        printf("=>This is debugging mode for load_product function.\n");
        printf("=>user input file name is %s\n", filename);
#endif
	if (count != 0)
    	{
        	NUM = count + 1;
    	}
	
	while(1)
	{
		if (count ==20) break;
		menu = selectMenu();
		if (menu == 0) break;
		else if (menu == 1)
		{
            		isLoaded = listProduct(p, count);
        	}
        	else if (menu == 2)
		{
            		p[count] = get_product(count);
            		NUM++;
            		count++;
        	}
        	else if (menu == 3)
		{
			save_product(p, filename, count);
        	}
        	else if (menu == 4)
		{
            		printf("검색타입은?(1: 이름 검색 2:무게 검색  3:배송타입 검색) ");
    			scanf("%d", &type);
			while (getchar()!='\n');
			#ifdef DEBUG
                printf("=>This is a debugging mode of searchProduct function\n");
                printf("=>user input type is %d\n", type);
#endif
			searchProduct(p, count,type);
        	}
		else if (menu == 5)
		{
			printf("번호는 (취소 :0)?");
            		scanf("%d", &selectedNum);
            		if (selectedNum == 0) continue;
            		printf("정말로 삭제하시겠습니까?(삭제 :1) ");
            		scanf("%d", &go);
            		if (go != 1) continue;
            		deleteProduct(p, selectedNum-1);
		}
		else if (menu == 6)
		{
			printf("\n번호는 (취소 :0)?");
            		scanf("%d", &selectedNum);
            		while (getchar()!='\n');
            		if (selectedNum == 0) continue;
            		p[selectedNum-1] = updateProduct(selectedNum);
            		printf("=> 수정됨!\n");
		}
		else
		{
			printf("없는 메뉴입니다.\n");
		}
	}
    	printf("종료됨!\n");
	
	return 0;
}
