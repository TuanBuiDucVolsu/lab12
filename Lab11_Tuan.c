#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
struct AEROFLOT
{
	char kuda[30];
    int num,t;
    char type[15];
} FLY,FLY1;
void Read1(FILE *f);
void xuat();
void Wrire(FILE *out);
void Read(FILE *out);
void Search(FILE *out);
void exportdata(FILE *out);
int main(int argc, char *argv[]) {
	int i,choose;
	FILE *out;
    do
    {
    	printf("=============== MENU ===============");
    	printf("\n1.Write file.");
    	printf("\n2.Read file.");
    	printf("\n3.Find.");
    	printf("\n4.Xuat du lieu.");
    	printf("\n0.Exit.");
    	printf("\nYou choose :");
    	scanf("%d",&choose);
    	switch(choose)
    	{
    		case 0: break;
    		case 1: Wrire(out);
    		break;
    		case 2: Read(out);
	    	        break;
	    	case 3:Search(out);
	               break;
	        case 4:exportdata(out);
	               break;
	        default:
	        	    printf("Wrong, please choose again!\n");
	        	    break;
	}
	}while(choose);
/*	FILE *f = fopen("Structures.TXT","r");
	while(!feof(f)){ //feof(tenfile)
		Read1(f);
		output();	
	}  */
	
	return 0;
}
void Wrire(FILE *out){
	int i;
	if ((out = fopen("binary.dat","wb")) == NULL)
	{
		printf("Cann't write'");
	}
	for(i = 1;i <= 7;i++)
	{
	printf("\nSerial: ");
	scanf("%d",&FLY.t);
	printf("\nEnter destination: "); 
	fflush(stdin); 
	gets(FLY.kuda);
	printf("\nEnter aircraft type: "); 
	fflush(stdin); 
	gets(FLY.type);
	fflush(stdin);
	printf("\nEnter the aircraft number: ");
    scanf("%d",&FLY.num);
	fwrite(&FLY,sizeof(FLY),1,out);
    }
	fclose(out); 
}
void Read(FILE *out)
{
	out = fopen("binary.dat","rb");
	fread(&FLY, sizeof(FLY), 1, out);
	while(!feof(out))
	{
    printf("\n%d %s %d %s\n ",FLY.t,FLY.kuda,FLY.num,FLY.type);
    fread(&FLY, sizeof(FLY), 1, out);
    }
    fclose(out);
}
void Search(FILE *out)
{
	int i;
	char tmp[15];
    printf("\n+Enter the type of aircraft to search: ");
    fflush(stdin);
	gets(tmp);
	printf("\n");
	int count = 0;
	out = fopen("binary.dat","rb");
	while(!feof(out) && count == 0 )  
	{  
		fread(&FLY, sizeof(FLY), 1, out); 
		if (strcmp(FLY.type , tmp) == 0) 
			count = 1;
	}  
	fclose(out);
	if(count == 1 )
	{
		printf("\n%s %d \n",FLY.kuda,FLY.num);
	}
    else
        {
        printf("\nThere is no such flight !!!\n");
        }  
}
void exportdata(FILE *out)
{
	out = fopen("binary.dat","rb");
	fseek(out,3*sizeof(FLY),SEEK_SET);
    fread(&FLY, sizeof(FLY), 1, out);
	while(!feof(out))
	{
    printf("\n%d %s %d %s\n ",FLY.t,FLY.kuda,FLY.num,FLY.type);
    fread(&FLY,sizeof(FLY), 1, out);
    }
	fclose(out);
}
/*void Read1(FILE *f)
{
	char tx[10];	
	fscanf(f,"%s",&FLY1.kuda);
	fscanf(f,"%d",&FLY1.num);
	fgets(tx,10,f);
	fgets(FLY1.type,20,f);
}
void output(){
		printf("\n%-30s %-10d %-10s ",FLY1.kuda,FLY1.num,FLY1.type);
}*/


