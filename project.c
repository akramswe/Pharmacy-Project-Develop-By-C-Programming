#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#define RETURNTIME 15

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
char password[10]={"project"};
int i;
void Password();
void main_menu();
void project();
//function for all box
void main_box();
void box1();
void wbox();
//function for about menu
void about();
void customer();
void cust_entry();
void cust_list();
void choose();
// Function For medicine.
void medicine();
void medi_entry();
void medi_search();
void medi_sale();
void sale_rpt_daily();
void stock();
//function for registration.
void registar();
void Log_in();
//structure for customer.
struct customer
{
	char cust_id;
	char cust_name[30];
	char city[20];
	char mob_no[11];
	char email[50];
};
struct customer temp_c;
FILE *ptr1;

//structure for medicine.
struct medical
{
	char id[6];
	char medi_name[20];
	int rack;
	char cabnit[2];
	int quantity;
	float sale;
	float total;
	float unit;
	float cost;
	float profit;
	float bye;
	int qty;
	char pur_date[15];
	char exp_date[15];
	char manu_date[15];
	int bill_no;
	char comp_name[20];
	char supp_name[30];
 };

struct medical temp;
struct medical x[20];
FILE *ptr;

struct purchase_report
{
	char medi_id[6];
	char medir_name[20];
	char supp_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct purchase_report p_r;
FILE *ptrp_r;

struct bill
{
	char billno[6];
	char cname[30];
	char mediname[30];
	int medi_qty;
	float medi_rate;
	float total;
	int day;
	int month;
	int year;

};
struct bill bil;
FILE *ptrbill;

struct sales_report
{
	char medi_id[6];
	char medir_name[20];
	char cust_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct sales_report s_r;
FILE *ptrs_r;




//structure for registration.
struct reg
{
	char supp_name[25];
	char mob_no[11];
	char email[20];
	char pass[11];
	char name[20];

};
struct reg temp1;

//=========================Time & Date ====================
int t(void) //for time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}
//=========================FOR BOX ====================
void box()
{
   for(i=3;i<=79;i++)
	{
		gotoxy(i,3);
		printf("%c",219);
		gotoxy(78,45);
		printf("%c",219);
		gotoxy(i,45);
		printf("%c",219);
	}

	for(i=3;i<=45;i++)
	{
		gotoxy(3,i);
		printf("%c",219);
		gotoxy(79,i);
		printf("%c",219);
	}
}

//=========================W BOX ====================
void wbox()
{
	for(i=5;i<=75;i++)
	{
		gotoxy(i,5);
		printf("%c",219);
		gotoxy(74,40);
		printf("%c",219);
		gotoxy(i,40);
		printf("%c",219);
	}

	for(i=5;i<=40;i++)
	{
		gotoxy(5,i);
		printf("%c",219);
		gotoxy(75,i);
		printf("%c",219);
	}
}

//============================ box for label ==========
void lbox()
{
	gotoxy(25,6);
	printf("%c",201);
	for(i=26;i<55;i++)
	{
		gotoxy(i,6);
		printf("%c",205);
	}
	gotoxy(55,6);
	printf("%c",187);
	gotoxy(25,6);
	for(i=6;i<8;i++)
	{
		gotoxy(25,i+1);
		printf("%c",186);
	}
	gotoxy(25,9);
	printf("%c",200);
	for(i=26;i<55;i++)
	{
		gotoxy(i,9);
		printf("%c",205);
	}
	gotoxy(55,9);
	printf("%c",188);
	gotoxy(55,6);
	for(i=6;i<8;i++)
	{
		gotoxy(55,i+1);
		printf("%c",186);
	}

}
//============================small box ===============
void box1()
{
	gotoxy(1,3);
	printf("%c",201);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,3);
		printf("%c",205);
	}

	gotoxy(80,3);
	printf("%c",187);
	gotoxy(1,3);
	for(i=4;i<10;i++)
	{
		gotoxy(1,i);
		printf("%c",186);
	}
	gotoxy(1,9);
	for(i=4;i<8;i++)
	{
		gotoxy(80,i);
		printf("%c",186);
	}
}


void main_box()
{
	gotoxy(1,6);
	printf("%c",201);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,6);
		printf("%c",205);
	}

	gotoxy(80,6);
	printf("%c",187);
	gotoxy(1,6);
	for(i=5;i<35;i++)
	{
		gotoxy(1,2+i);
		printf("%c",186);
	}
	gotoxy(1,37);
	printf("%c",200);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,37);
		printf("%c",205);
	}
	gotoxy(80,37);
	printf("%c",188);
	gotoxy(80,6);
	for(i=5;i<35;i++)
	{
		gotoxy(80,2+i);
		printf("%c",186);
	}
}
//for password option
void Password(void)
{

   system("cls");
   system("color 0F");
   char d[25]="Password Protected";
   char ch,pass[10];
   int i=0,j;
    gotoxy(10,4);
    for(j=0;j<20;j++)
    {
    delay(50);
    printf("*");
    }
    for(j=0;j<20;j++)
   {
   delay(50);
   printf("%c",d[j]);
   }
   for(j=0;j<20;j++)
   {
   delay(50);
   printf("*");
   }
   gotoxy(10,10);
   gotoxy(15,7);
   printf("Enter Password:");

   while(ch!=13)
   {
	ch=getch();

	if(ch!=13 && ch!=8){
	putch('*');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {

	gotoxy(15,9);
	printf("Password match");
	gotoxy(17,10);
	printf("Press any key to countinue.....");
	getch();
	project();
   }
   else
   {
	 gotoxy(15,16);
	 printf("\aWarning!! Incorrect Password");
	 getch();
	 Password();
   }
}

//===========================main ===================
int main()
{

	system("cls");
	Password();
    project();

}

void project()
{
    system("cls");
    box();
    system("color F0");
    char w[20]=" WELLCOME ";
    char a[20]=" TO ";
    char m[20]=" MY PROJECT ";
    char s[25]=" PHARMACY SOFTWARE ";
    int j;
    gotoxy(35,8);
    for(j=0;j<9;j++)
    {
    delay(50);
    printf("%c",w[j]);
    }
    gotoxy(38,10);
    for(j=0;j<3;j++)
   {
   delay(50);
   printf("%c",a[j]);
   }
   gotoxy(34,12);
   for(j=0;j<13;j++)
   {
   delay(50);
   printf("%c",m[j]);
   }
    gotoxy(28,14);
   for(j=0;j<22;j++)
   {
   delay(50);
   printf("%c",s[j]);
   }


   gotoxy(49,21);
    printf(" Press ENTER to continue_");
    if(getch()==13) //allow only use of enter
    main_menu();

}

void main_menu()
{
 int ch,l,i=1;


		system("cls");
		box1();
		main_box();
    system("color 70");
    char a[40]=" ABOUT THIS PHARMACY SOFTWARE PROJECT ";
   int j;
   gotoxy(2,3);
    for(j=0;j<19;j++)
    {
    delay(20);
    printf("\xB2");
    }
    for(j=0;j<37;j++)
   {
   delay(60);
   printf("%c",a[j]);
   }
   for(j=0;j<21;j++)
   {
   delay(20);
   printf("\xB2");
   }
  gotoxy(21,8);
	     t();
	gotoxy(8,11);
	printf("=> This Project Is About Medical Store ");
	gotoxy(10,12);
	printf("=> In This Project we Can Add Medicine ,Customer,Supplier Details");
	gotoxy(10,13);
	printf("=> We Can Modified & Delete Existing Record");
	gotoxy(10,14);
	printf("=> We Can Also Search Medicine ,Customer,Supplier Details");
	gotoxy(10,15);
	printf("=> It's Helpful For Display Stock Of Medicine ");
	gotoxy(10,17);
		printf("Choose what you want to see??? ");
        gotoxy(10,19 );
        printf("\xDB\xDB\xDB\xDB\xB2 1. LOG IN");
        gotoxy(10,21 );
        printf("\xDB\xDB\xDB\xDB\xB2 2.REGISTRATION");
        gotoxy(10,23);
		printf("\xDB\xDB\xDB\xDB\xB2 3.About");
		gotoxy(10,25);
		printf("\xDB\xDB\xDB\xDB\xB2 4.Exit");
		gotoxy(10,27);
        gotoxy(10,29);
		for(i=1; i<=5; i++){
		ch=getche();
		  gotoxy(11,29);
		switch(ch)
		{
			case '1': Log_in();
			     break ;
			case '2': registar();
               break ;
			case '3':about();
				 break;
			case '4':gotoxy(18,34);
			printf("Do you want to exit now? Y/N :");
			Sleep(100);
			ch=(getche());
			ch=toupper(ch);
			if(ch=='Y')
			{
				system("cls");
				gotoxy(35,20);
				printf(" Please wait.....");
				Sleep(2000);
				exit(0);
			}
			else
			{
				main_menu();
			}
			default:
			gotoxy(10,28);
			printf("@@@<<<<YOU CAN TRY THREE TIMES>>>>@@@");
			gotoxy(10,30);
			printf("Plese Enter right character ONLY (1,2,3,4,5,6,7).");
		}
		}
		system("cls");
		gotoxy(40,20);
        printf("PLEASE TRY AGAIN LATER.");
        gotoxy(10,45);
    }


void choose()
{
         char ch;
         system("cls");
         box();
         system("color A0");
         gotoxy(8,5);
        printf("Choose what you want to see??? ");
        gotoxy(8,7 );
		printf("\xDB\xDB\xDB\xDB\xB2 1.Supplier Info");
		gotoxy(8,9);
		printf("\xDB\xDB\xDB\xDB\xB2 2.Customer Info");
		gotoxy(8,11);
		printf("\xDB\xDB\xDB\xDB\xB2 3.Medicine");
		gotoxy(8,13);
		printf("\xDB\xDB\xDB\xDB\xB2 4.Bill");
		gotoxy(8,15);
		printf("\xDB\xDB\xDB\xDB\xB2 6.Log Out");
		gotoxy(8,17);
		for(i=1; i<=5; i++){
		ch=toupper(getche());
		  gotoxy(8,21);
		switch(ch)
		{
            case '2':customer();
                 break;
            case '3':medicine();
                 break;
			case '6':gotoxy(10,28);
			printf("Do you want to exit now? Y/N :");
			Sleep(100);
			ch=(getche());
			ch=toupper(ch);
			if(ch=='Y')
			{
				system("cls");
				main_menu();
			}
			else
			{
				choose();
			}
			default:
			gotoxy(8,21);
			printf("@@@<<<<YOU CAN TRY THREE TIMES>>>>@@@");
			gotoxy(8,22);
			printf("Plese Enter right character ONLY (1,2,3,4,5,6,7).");
		}
		}
		system("cls");
		gotoxy(40,20);
        printf("PLEASE TRY AGAIN LATER.");
        gotoxy(10,45);
}

 // this function use for registration.

void registar()
{
 int id;
 char ch;
 FILE *fptr;
 system("cls");
    /*  open for writing */
     fptr = fopen("password.txt", "a");
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
	   system("cls");
	   ch='y';
	   do
        {
		system("cls");
		box();
		lbox();
		gotoxy(30,8);
		printf(" REGISTRATION FORM ");
		gotoxy(7,13);
        printf("\xDB\xDB\xB2 Full name:");
		scanf("%s", &temp1.name);
        gotoxy(40,13);
	    printf("\xDB\xDB\xB2  USER NAME:");
		scanf("%s", &temp1.supp_name);
   	    gotoxy(7,17);
        printf("\xDB\xDB\xB2 PASSWORD:");
		scanf("%s", &temp1.pass);
        gotoxy(40,17);
        printf("\xDB\xDB\xB2 Email:");
		scanf("%s", &temp1.email);
		gotoxy(7,20);
		 printf("\xDB\xDB\xB2 Mobile number:");
		scanf("%s", &temp1.mob_no);
		gotoxy(20,33);
		printf("Save");
		gotoxy(30,33);
		printf("Cancel");
		gotoxy(15,36);
		printf("Press First charecter for the operation : ");
		ch=getch();
		if(ch=='s' || ch=='S')
		{
			fprintf(fptr,"%s  %s  %s  %s  %s\n",temp1.supp_name,temp1.pass,temp1.name,temp1.email,temp1.mob_no);
			fprintf(fptr,"\n");
			system("cls");
			gotoxy(20,20);
			printf("Supplier Added successfully!!!!!");
			gotoxy(20,25);
			  system("cls");
	     }

printf("More entries  [y/n] ");
ch=getche();

}while(ch=='y');
main_menu();
fclose(fptr);
}

//this function check user name and password
void Log_in() //for password option
{

  char name[20];
char ch,pass[10];
   int i=0;
  system("cls");
  box();
	   ptr1=fopen("password.txt","rb");
	   gotoxy(12,8);
	    lbox();
		gotoxy(30,8);
		printf(" \xDB\xDB\xB2 LOG IN  \xDB\xDB\xB2");
		gotoxy(12,13);
	   printf("\xDB\xDB\xB2  USER NAME:");
	   scanf("%s",&name);
       gotoxy(12,15);
	   printf("\xDB\xDB\xB2 PASSWORD:");
   while(ch!=13)
   {
	ch=getch();
	if(ch!=13 && ch!=8){ //here is ENTER=13, BKSP=8
	putch('*');
	pass[i] = ch; //ch value assign into pass[i].
	i++;
	}
   }
   pass[i] = '\0';
	   i=18;
	   gotoxy(9,15);
	   while(fscanf(ptr1,"%s %s",temp1.supp_name,temp1.pass)!=EOF)
	   {
		if(strcmp(temp1.supp_name,name)== 0 && strcmp(temp1.pass,pass)==0  )
		{

			choose();
			break;
		}
	   }
	   if(strcmp(temp1.supp_name,name)!=0)
	   {

        system("cls");
		gotoxy(5,10);
		printf("ENTER PASSWORD WRONG");
	   }
	   fclose(ptr1);
	getche();
}

//this function for customer main menu.
void customer()
{
	char ch;
	do
	{
	  system("cls");
	  gotoxy(34,3);
	  printf("---------------");
	  gotoxy(35,4);
	  printf("Customer Menu.");
	  gotoxy(34,5);
	  printf("---------------");
	  gotoxy(26,11);
	  printf("Add New Customer");
	  gotoxy(26,15);
	  printf("Update Customer");
	  gotoxy(26,19);
	  printf("Search Customer");
	  gotoxy(26,23);
	  printf("List of Customer");
	  gotoxy(26,27);
	  printf("Main Menu");
	  main_box();
	  gotoxy(10,40);
	  printf("Press First Character for further Operations  ");
	  ch=toupper(getche());
	  switch(ch)
	  {
		case 'a':case 'A':cust_entry();
			 break;
		case 'l':case 'L': cust_list();
			 break;
		case 'm':case 'M':main_menu();
			 break;
		   default:
			gotoxy(11,34);
			printf("Plese Enter right character ONLY (A,L,U,S,M).");
			getch();
	  }
	}while(ch!='M');
   getch();
}
//========FOR CUSTOMER ENTRY=================
void cust_entry()
{
 char ch;

 FILE *fptr;
 system("cls");
	  fptr = fopen("customer.txt", "a");

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
	   system("cls");
	   ch='y';
	   while(ch=='y')
	   {
		system("cls");
		box();
		lbox();
		gotoxy(30,8);
		printf(" CUSTOMER ENTRY ");
		gotoxy(8,13);
		printf("CUSTOMER ID : ");
		scanf("%s",&temp_c.cust_id);
		gotoxy(39,13);
		printf("CUSTOMER NAME : ");
		scanf("%s",&temp_c.cust_name);
		gotoxy(8,18);
		printf("CITY        : ");
		scanf("%s",&temp_c.city);
		gotoxy(39,18);
		printf("CONTACT NO.   : ");
		scanf("%s",&temp_c.mob_no);
		gotoxy(8,23);
		printf("EMAIL ID    : ");
		scanf("%s",&temp_c.email);
		gotoxy(21,30);
		printf("Save");
		gotoxy(29,30);
		printf("Cancel");
		gotoxy(18,36);
		printf("Press First charecter for the operation : ");
		ch=getche();
		if(ch=='s' || ch=='S')
		{
			fprintf(fptr," %s %s %s %s\n",temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
			fprintf(fptr,"\n");
			system("cls");
			gotoxy(20,20);
			printf("Customer Added Successfully!!!!!");
			gotoxy(20,25);
			printf("More entries  [y/n] ");
			ch=getche();

		}
	   }
	   fclose(fptr);


}

//=========FOR CUSTOMER DISPLAY LIST ==========
void cust_list()
{
 char ch;
 int id;
 system("cls");
	   ptr1=fopen("customer.txt","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   box();
	   gotoxy(8,48);
	   printf("Press Anykey to go to CUSTOMER MENU!!!");
	   lbox();
	   gotoxy(30,8);
	   printf(" CUSTOMER LIST ");
	   i=14;
	   gotoxy(5,10);
	   printf(" ID. CUSTOMER NAME.    CITY.     MOBILE.NO.      EMAIL");
	   gotoxy(4,12);
	   printf("==============================================================");
	   while(fscanf(ptr1,"%s %s %s %s", temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
	   {

		gotoxy(4,i);
		gotoxy(11,i);
		printf(" %s",temp_c.cust_name);
		gotoxy(28,i);
		printf(" %s",temp_c.city);
		gotoxy(40,i);
		printf(" %s",temp_c.mob_no);
		gotoxy(53,i);
		printf(" %s",temp_c.email);
		i=i+2;
	   }
	   getche();
}


//=========================For Medicine ===========================
void medicine()
{
	char ch;
	do
	{
	  system("cls");
      system("color 1F");
	  gotoxy(34,3);
	  printf("---------------");
	  gotoxy(35,4);
	  printf("Medicine Menu.");
	  gotoxy(34,5);
	  printf("---------------");
	  gotoxy(8,10);
	  printf("\xDB\xDB\xDB\xDB\xB2 1. Purchase New Medicine");
	  gotoxy(8,13);
	  printf("\xDB\xDB\xDB\xDB\xB2 2. Sale Medicine");
	  gotoxy(8,16);
	  printf("\xDB\xDB\xDB\xDB\xB2 3. Stock of Medicine");
	  gotoxy(8,19);
	  printf("\xDB\xDB\xDB\xDB\xB2 4. Search Medicine");
	  gotoxy(8,21);
	  printf("\xDB\xDB\xDB\xDB\xB2 5. Sale report");
      gotoxy(8,23);
	  printf("\xDB\xDB\xDB\xDB\xB2 6. Main Menu");
	  main_box();
	  gotoxy(3,25);
	  printf("Press what you want to see??? {<<= Like as 1 for Purchase New Medicine =>>}");
	  ch=getche();
	  switch(ch)
	  {
		case '1':medi_entry();
			 break;
        case '2':medi_sale();
             break;
        case '3':stock();
             break;
        case '4':medi_search();
             break;
        case '5':sale_rpt_daily();
             break;
		case '6':choose();
			 break;
		default:
			gotoxy(11,35);
			printf("Plese Enter right character ONLY (P,S,C,M).");
			getch();
	  }
	}while(ch!='M');

}

//=========================For Medicine Entry ===========================
void medi_entry()
{
  char ch,id[6];
//  struct date d;
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
  int f;
  FILE *fp;
  system("cls");
  system("color 0A");
	  ptrp_r=fopen("purreport.txt","a");
	  ch='Y';
	  while(ch=='Y')
	  {
		system("cls");
		box();

		lbox();
		gotoxy(30,8);
		printf(" MEDICINE PURSHASE  ");
		{
			gotoxy(7,11);
			printf("MEDICINE ID    : ");
            scanf("%s",&temp.id);
            gotoxy(40,11);
			printf("MEDICINE NAME  : ");
            scanf("%s",&temp.medi_name);
			gotoxy(7,14);
			printf("ENTER RACK NO  : ");
            scanf("%d",&temp.rack);
			gotoxy(40,14);
			printf("CABNIT NO      : ");
            scanf("%s",&temp.cabnit);
			gotoxy(7,18);
			printf("COMPANY NAME   : ");
            scanf("%s",&temp.comp_name);
			gotoxy(40,18);
			printf("SUPPLIER NAME  : ");
            scanf("%s",&temp.supp_name);
			gotoxy(7,21);
			printf("UNIT COST   Rs.:  ");
            scanf("%f",&temp.unit);
			gotoxy(40,21);
			printf("SALE COST   Rs.: ");
            scanf("%f",&temp.sale);
			gotoxy(7,24);
			printf("QUANTITY       :  ");
            scanf("%d",&temp.quantity);
			gotoxy(7,27);
			printf("MFG.DATE(dd-mm-yyyy): ");
            scanf("%s",&temp.manu_date);
			gotoxy(7,29);
			printf("EXP.DATE(dd-mm-yyyy): ");
            scanf("%s",&temp.exp_date);
           strcpy(id,temp.id);
          fp=fopen("medical.dat","r");
			while((fread(&temp,sizeof(temp),1,fp))==1)
			{

			if(strcmp(id,temp.id)==0)
			{
				f=1;
				break;
			}
			}
			fclose(fp);
			if(f==1)
			{
				gotoxy(20,31);
				printf("ID Allready Exists");
				getche();
				system("cls");
				medi_entry();
			}
			else
			{
			ptr=fopen("medical.dat","a+b");
			strcpy(temp.id,id);
			strcpy(p_r.medi_id,temp.id);
			}
			strcpy(p_r.medir_name,temp.medi_name);
			strcpy(p_r.supp_name,temp.supp_name);
			p_r.rate=temp.unit;
			gotoxy(58,21);
			gotoxy(25,24);
			p_r.qty=temp.quantity;
			gotoxy(7,31);
			printf("==========================================================");
			temp.total=temp.quantity*temp.sale;

			//textcolor(10);
			gotoxy(10,33);
			printf("TOTAL SALE COST = Rs. %.2f",temp.total);
			temp.cost=(temp.unit*temp.quantity);
			gotoxy(40,33);
			printf("TOTAL UNIT COST = Rs. %.2f",temp.cost);
			p_r.total=temp.cost;
			p_r.sDay=now->tm_mday;
			p_r.sMonth=now->tm_mon;
			p_r.sYear=now->tm_year;
		 }
		gotoxy(20,35);
		gotoxy(21,35);
		printf("Save");
		gotoxy(28,35);
		gotoxy(29,35);
		printf("Cancel");
		gotoxy(18,38);
		printf("Press First charecter for the operation : ");
		ch=toupper(getche());

		if(ch=='S')
		{
			fwrite(&temp,sizeof(temp),1,ptr);
			fflush(stdin);
			//textcolor(10);
			fprintf(ptrp_r,"%s %s %s %d %.2f %.2f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,p_r.qty,p_r.rate,p_r.total,p_r.sDay,p_r.sMonth,p_r.sYear);
			system("cls");
			gotoxy(20,20);
			printf("Medicine Added sucessfully!!!!!!");
			gotoxy(20,25);
			printf("More entries  [y/n]");
			ch=toupper(getche());
		}

	   }
	   fclose(ptr);
	   fclose(ptrp_r);
}

//===========================MEDICINE STOCK=====================================
void stock()
{
  char ch;
  int i,c;
	   do
	   {
		system("cls");
		ptr1=fopen("medical.dat","r");
		if(ptr1==NULL)
		{
			printf("\n\t Can not open File! ");
			exit(1);
		}
		system("cls");
		box();
		lbox();
		gotoxy(30,8);
		printf(" STOCK OF MEDICINE ");
		i=14;
		gotoxy(9,10);
		printf("ID.   MEDICINE NAME.    QTY     Supplier Name     Exp.Date");
		gotoxy(9,12);
		printf("==================================================================\n");

		while((fread(&temp,sizeof(temp),1,ptr1))==1)
		{
			gotoxy(9,i);
			printf(" %s",temp.id);
			gotoxy(15,i);
			printf(" %s",temp.medi_name);
			gotoxy(32,i);
			printf(" %d",temp.quantity);
			gotoxy(43,i);
			printf(" %s",temp.supp_name);
			gotoxy(60,i);
			printf(" %s",temp.exp_date);
			i++;
		}
		gotoxy(10,42);
		printf("Press [1] for Medicine ");
		c = (getche());
		switch (c)
		{
			case '1':medicine();
				 break;
		}

	   }while(c != '1');
	   getche();
}

//=============================== FOR MEDICINE SEARCH ====================
void medi_search()
{
  char mid[6];
struct bill bil;
  //struct date d;
  time_t t = time(0);   // get time now
  struct tm * now = localtime( & t );
  int j,n,i,a,billno;
  int d1,m,y;
  float b,total,rate;
  char tar[30],ch,mediname[30],c_name[30],cname[30];
  FILE *fp;
  int count=0;
  system("cls");
	   ptr1=fopen("medical.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   box();
	   gotoxy(10,7);
	   printf("Enter Medicine Id to be searched : ");
	   scanf("%s",&mid);
	   system("cls");
	   box();
	   lbox();
	   gotoxy(30,8);
	   printf(" MEDICINE ");
	   i=14;
	   gotoxy(9,10);
	   printf("ID.   MEDICINE NAME.    QTY     Supplier Name     Exp.Date");
	   gotoxy(9,12);
	   printf("==================================================================\n");
	   while((fread(&temp,sizeof(temp),1,ptr1))==1)
	   {
		if(strcmp(mid,temp.id)==0)
		{
			gotoxy(9,i);
			printf(" %s",temp.id);
			gotoxy(15,i);
			printf(" %s",temp.medi_name);
			gotoxy(32,i);
			printf(" %d",temp.quantity);
			gotoxy(43,i);
			printf(" %s",temp.supp_name);
			gotoxy(60,i);
			printf(" %s",temp.exp_date);
			i++;
			break;
		}
    gotoxy(10,42);
	   }
	   if(strcmp(mid,temp.id)!=0)
	   {
		gotoxy(20,20);
		printf("Not in Stock.....");
	   }
	   getche();

}

//===========FOR MEDICINE SALE=========================
void medi_sale()
{
  struct bill bil;
  //struct date d;
  time_t t = time(0);   // get time now
  struct tm * now = localtime( & t );
  int j,n,i,a,billno;
  int d1,m,y;
  float b,total,rate;
  char tar[30],ch,mediname[30],c_name[30],cname[30];
  FILE *fp,*fpc;
  int count=0;
  //getdate(&d);
  d1=now->tm_mday;
  m=now->tm_mon;
  y=now->tm_year;
	   ch='y';
	   while(ch=='y')
	   {
		fp = fopen("dbbill.dat","a");
		ptr = fopen("medical.dat","r");
		ptrs_r=fopen("saleRpt.dat","a");
		system("cls");
		box();
		gotoxy(9,7);
		printf("ENTER MEDICINE ID TO BE SOLD  : ");
        scanf("%s",&tar);
		j=0;
		while((fread(&temp,sizeof(temp),1,ptr))==1)
		{
			if((strcmp(temp.id,tar)<0) || (strcmp(temp.id,tar)>0))
			{
				x[j] = temp;
				j++;
			}
			else if((strcmp(temp.id,tar)==0))
			{

				gotoxy(8,10);
				printf(" Medicine Name        : %s",temp.medi_name);
				gotoxy(8,12);
				printf(" Quantity in stock    : %d",temp.quantity);
				gotoxy(8,14);
				printf(" Sales price          : %.2f",temp.sale);
				gotoxy(8,16);
				printf("Enter bill number     : ");
				scanf("%s",&bil.billno);
				gotoxy(8,18);
				printf("Enter customer Name   : ");
				scanf("%s",&c_name);
				gotoxy(8,20);
				printf("Quantity want to sale : ");
				scanf("%d",&a);
				x[j]=temp;
				x[j].quantity=(x[j].quantity-a);
				x[j].total=(x[j].quantity*temp.sale);
				x[j].cost=(x[j].quantity*temp.unit);
				x[j].bye=(x[j].sale*a);
				b=x[j].bye;
				x[j].qty=a;
				j++;
				count++;
				strcpy(bil.cname,c_name);
                strcpy(s_r.cust_name,c_name);
				strcpy(bil.mediname,temp.medi_name);
				bil.medi_qty=a;
				bil.medi_rate=temp.sale;
				bil.total=temp.sale*a;
				bil.day=d1;
				bil.month=m;
				bil.year=y;
                //bill report
				fprintf(fp,"%s %s %s %d %.2f %.2f %d %d %d\n",bil.billno,bil.cname,bil.mediname,bil.medi_qty,bil.medi_rate,bil.total,bil.day,bil.month,bil.year);
				fflush(stdin);

				fclose(fp);

				s_r.sDay=d1;
				s_r.sMonth=m;
				s_r.sYear=y;
				strcpy(s_r.medi_id,tar);
				strcpy(s_r.medir_name,temp.medi_name);
				s_r.qty=a;
				s_r.rate=temp.sale;
				s_r.total=temp.sale*a;

				//sale report
				fprintf(ptrs_r,"%s %s %s %d %.2f %.2f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,s_r.qty,s_r.rate,s_r.total,s_r.sDay,s_r.sMonth,s_r.sYear);
				fflush(stdin);
				fclose(ptrs_r);
			}
		}
		if (count==0)
		{
			system("cls");
			gotoxy(33,10);
			printf("Not in stock!!!!!");
			getch();
			return;
		}
		fclose(ptr1);
		fclose(ptr);
		n = j;
		system("cls");
		ptr=fopen("medical.dat","wb");
		for(i=0; i<n; i++)
		fwrite(&x[i],sizeof(x[i]),1,ptr);
		fclose(ptr);
		system("cls");
		box();
		gotoxy(8,15);
		printf("* Price paid by customer = %.2f",b);
		gotoxy(8,17);
		printf("* Quantity sold          = %d",a);
		getch();
		gotoxy(10,20);
		printf("more enteries=(y/n) :");
		ch=getche();
	   }

}
//===========FOR MEDICINE DAILY SALE REPORT=========================
void sale_rpt_daily()
{
  char ch;
  int j,d,m,y;
  float total=0.00;
  system("cls");
	   ptrs_r=fopen("saleRpt.dat","r");
	   if(ptrs_r==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   gotoxy(15,10);
	   printf("Enter Date(dd-mm-yyyy):  ");
	   scanf("%d-%d-%d",&d,&m,&y);
	   system("cls");
	   gotoxy(20,50);
	   printf("Press any key to go to REPORT MENU ...........");
	   box();
	   lbox();
	   gotoxy(30,8);
	   printf("Sales Report");
	   gotoxy(7,10);
	   printf("ID. Medicine Name.  Customer Name.   Qty.  Rate.  Total.   Date");
	   gotoxy(7,12);
	   printf("===================================================================");
	   j=14;
     while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
	   {
		if(d==s_r.sDay &&m== s_r.sMonth && y==s_r.sYear)
		{
		gotoxy(6,j);
		printf("%s",s_r.medi_id);
		gotoxy(11,j);
		printf("%s",s_r.medir_name);
		gotoxy(28,j);
		printf("%s",s_r.cust_name);
		gotoxy(44,j);
		printf("%d",s_r.qty);
		gotoxy(50,j);
		printf("%.2f",s_r.rate);
		gotoxy(57,j);
		printf("%.2f",s_r.total);
		gotoxy(65,j);
		printf("%d-%d-%d",s_r.sDay,s_r.sMonth,s_r.sYear);
		j=j+2;
		total=total+s_r.total;
		}
	   }
	   gotoxy(7,42);
	   printf("-------------------------------------------------------------------");
	   gotoxy(45,43);
	   printf("Total:        %.2f",total);
	   getche();
}

//=============================== FOR About this project ====================
void about()
{  int c;
   system("cls");

   do
   {
	gotoxy(28,4);
char ch;
   FILE *fp;
   fp = fopen("info.txt","r"); // read mode
   while( ( ch = fgetc(fp) ) != EOF )
   printf("%c",ch); //print file information.
   fclose(fp);
    gotoxy(10,18);
	printf("<<<<-Press 1 for main menu->>>>\n");
	gotoxy(10,20);
	c = (getche());

	switch (c)
		{
			case '1':main_menu();
				break;
            default:
                gotoxy(26,24);
				puts("<<--ENTER FROM 1 PLEASE-->>");
				break;
				getch();
		}

}while(c != '1');
}
