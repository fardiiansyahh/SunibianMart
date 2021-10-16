#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Item {
    char name[256] ;
    int price;
};

struct Item items[100];
void init_items(){

strcpy(items[0].name,"Shampoo"); items[0].price = 5000;
strcpy(items[1].name,"Soap"); items[1].price = 6000;
strcpy(items[2].name,"Toothpaste"); items[2].price = 15000;
strcpy(items[3].name,"Toothbrush"); items[3].price = 15000;
strcpy(items[4].name,"Milk"); items[4].price = 11000;
}

int main(){
	FILE *fp;
	fp = fopen("printout.txt","r+");
	
	init_items();
	
	int tc;
	struct Item cart[100];
	int cartcount = 0;
	while(1){
	printf("SUNIBIAN MART\n");
	printf("1.View Items\n"
	"2.Add to Cart\n"
	"3.Delete All Cart Items\n"
	"4.View Cart\n"
	"5.Print out Cart\n"
	"6.Exit\n");
	printf("Input Your Choice : ");
	scanf("%d",&tc);
	getchar();
	switch(tc){
		case(1):
			
			for(int i=1;i<=5;i++){
			
			printf("%d. %s @Rp.%d\n",i,items[i-1].name,items[i-1].price);
			}
			break;
			
		case(2):
			int choice;
			for(int i=1;i<=5;i++){
			
			printf("%d. %s @Rp.%d\n",i,items[i-1].name,items[i-1].price);
			}
			
			scanf("%d",&choice);
			printf("Item Number %d has been added to cart\n",choice);
			
			strcpy(cart[cartcount].name,items[choice].name);
			cart[cartcount].price = items[choice].price;
			cartcount++;
			break;
		
		case(3):
			printf("Cart is Cleared");
			cartcount =0;
			break;
		case(4):
			if(cartcount == 0){
				printf("Cart is currently empty\n");
				
			}else{
				for(int i=0;i<cartcount;i++){
					printf("%d. %s @Rp.%d\n",i+1,cart[i].name,cart[i].price);
				}
			}
			break;
		case(5):
			if(cartcount == 0){
				printf("Cart is currently empty\n");
				
			}else{
				for(int i=0;i<cartcount;i++){
					fprintf(fp,"%d. %s @Rp.%d\n",i+1,cart[i].name,cart[i].price);
					fprintf(fp,"===========================\n");
					printf("Printout has been created\n");
				}
			}
			break;
		case(6):
			return 0;	
	}
}
	
	fclose(fp);
	return 0;
}
