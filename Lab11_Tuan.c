#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
struct AEROFLOT               //3 объекта в структуре
{
    char kuda[30];             // Пункт назначения
    int num,t;                // Номер самолета
    char type[15];            // Tип самолета
} FLY,FLY1;
void Read1(FILE *f);                   //   функция чтения файла text
void output();                         //   Экспортируйте файл на экран (file txt)
void Wrire(FILE *out);                 //   функция записи двоичного файла
void Read(FILE *out);                   //  функция чтения файла binary
void Search(FILE *out);                 //  Поиск информации в файле
void exportdata(FILE *out);             //  Извлечь данные файла
int main(int argc, char *argv[]) {
	int i,choose;                     // Инициализировать значение для цикла
	FILE *out;                       // инициализация файла
    do                // Создать меню для выбора функции
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
/*	FILE *f = fopen("Structures.TXT","r");               // Откройте текстовый файл для чтения
	while(!feof(f)){            // Когда файл не закончен, прочитайте и экспортируйте файл на экран      
		Read1(f);
		output();	
	}  */
	
	return 0;
}
void Wrire(FILE *out){
	int i;
	if ((out = fopen("binary.dat","wb")) == NULL)              //Открыть файл для записи 
	{
		printf("Cann't write'");
	}
	for(i = 1;i <= 7;i++)                            //записать 7 значений в файл      
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
	fwrite(&FLY,sizeof(FLY),1,out);               // Функция записи файла
    }
	fclose(out);                   //Закройте файл после записи
}
void Read(FILE *out)
{
	out = fopen("binary.dat","rb");                               //Откройте файл для чтения
	fread(&FLY, sizeof(FLY), 1, out);                         // функция чтения файла
	while(!feof(out))
	{
         printf("\n%d %s %d %s\n ",FLY.t,FLY.kuda,FLY.num,FLY.type);
         fread(&FLY, sizeof(FLY), 1, out);
         }
    fclose(out);      
}
void Search(FILE *out)
{
	char tmp[15];      
        printf("\n+Enter the type of aircraft to search: ");   //// Введите тип самолета для поиска
        fflush(stdin);
	gets(tmp);
	printf("\n");
	int count = 0;
	out = fopen("binary.dat","rb");          // Откройте файл для поиска
	while(!feof(out) && count == 0 )  
	{  
		fread(&FLY, sizeof(FLY), 1, out); 
		if (strcmp(FLY.type , tmp) == 0)             // //Сравните данные в выводе с введенной строкой
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
	fseek(out,3*sizeof(FLY),SEEK_SET);          //файл экспорта стартовой позиции          
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
	char tx[10];	               // Создать массив для хранения избыточных элементов
	fscanf(f,"%s",&FLY1.kuda);     // Читать информацию о пункте назначения
	fscanf(f,"%d",&FLY1.num);      // Читайте информацию о номерах самолетов
	fgets(tx,10,f);                // Перенести избыточные элементы в массив
	fgets(FLY1.type,20,f);         // Читайте информацию о типе самолета
}
void output(){        
		printf("\n%-30s %-10d %-10s ",FLY1.kuda,FLY1.num,FLY1.type);
}*/


