#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
int login();
int  menu(float grand_total);
int m_menu();
int go_to();
struct customer
{
	int id[3];
	char name[10];
	char add[4];
	int mo[12];
	char help[30];
	int payment[4];
}cs[100];
int bill(float grand_total)
{
	int id,product;
	long int mo;
	char name[20],add[20],p[20];
	float total;
	total=grand_total;
	FILE *f;
	time_t mytime;
	mytime = time(NULL);
	printf("\n\n\t\t===> this is the customer bill field area: ==>>");
	id:
	fflush(stdin);
	printf("\n\n\t\tId:-:");
	if(scanf("%d",&id)==1);
	else{
		printf("give the right type of the id");
		goto id;
	}
	fflush(stdin);
	printf("\n\n\t\tName-:");
	scanf("%s",name);
	fflush(stdin);
	printf("\n\n\t\tAddress:-:");
	scanf("%s",add);
	
	mo_n:
	fflush(stdin);
	printf("\n\n\t\tMobile_no-:");
	if(scanf("%d",&mo)==1);
	else
	{
		printf("give the nomber of the mobile");
		goto mo_n;
	}
	fflush(stdin);
	printf("\n\n\t\tProducts-:");
	fflush(stdin);
	scanf("%d",&product);
	fflush(stdin);
	printf("\n\n\t\tProducts name:-");
	
	scanf("%s",p);
	total:
	fflush(stdin);
	printf("\n\n\t\tTotal (Rs)-:%f",total);
	f=fopen("bill.rtf","w");
	fprintf(f,"Nerolac Product Management System\n\n");
	fflush(stdin);
	fprintf(f,"%s",ctime(&mytime));
	fflush(stdin);
	fprintf(f,"\n\nId:-%d \nName-:%s\nAddress:-:%s\nMobile_no-: %d\nProduct_Name:-%s\nProducts-:%d\nTotal (Rs)-:%.2f\n",id,name,add,mo,p,product,total);
	fprintf(f,"\n\nThanks for buying !!!");
	fclose(f);
	printf("\n\t\tyour bill is ready to print");
	m_menu();
	
}
void help()
{       int i;
	char fd[1000],b[201];
	FILE *f;
	f=fopen("help.txt","r");
	for(i=0;i<=200;i++)
	{
	fflush(stdin);
	fscanf(f,"%c",&b[i]);
	}
	printf("\n\n\t\tthis help is about the my system and how to use it ?\n\n");
	for(i=0;i<=200;i++)
	{
	fflush(stdin);
	printf("%c",b[i]);
	}
	printf("\n\nare you happy with this help ? give your feedback:");
	scanf("%s",fd);
	printf("\n\n\t\t thanks for your feedback");
	go_to();

}

int nnew()
{
	int i=0;
	char c_ch='y';
	int j,n;
	FILE *f;
	//clrscr();
	while(c_ch=='y')
	{
	//clrscr();
	printf("\n\n\t\t===>>this is the form of the new customer here<=== \n\n");
	printf("\n\n\t\tFill up the detail of the customer here:\n\n");
			printf("\n\t\tId of customer:");
		c_id:
			fflush(stdin);
			if(scanf("%d",&cs[i].id)==1);
			else
			{
				printf("\n\t\tgive the right type of th id:\n\t\t");
				goto c_id;
			}
			fflush(stdin);
			printf("\n\t\tName:");
			scanf("%s",cs[i].name);
			fflush(stdin);
			mo_no:
			printf("\n\t\tMobile_no:");
			fflush(stdin);
			//scanf("%d",&cs[i].mo);
			if(scanf("%d",&cs[i].mo)==1);
			else 
			{
				printf("\n\t\twrong formate of mobile no: type again\n\t\t");
			goto mo_no;
			}
			fflush(stdin);
			printf("\n\t\t How much he/she have to paying:");
			scanf("%s",&cs[i].payment);
			fflush(stdin);
	printf("\n\t\twant to add another new user? (y or n):\n");
	scanf("%c",&c_ch);
	i++;

}
	n=i;
	f=fopen("custo.csv","a+");
	for(j=0;j<n;j++)
	{
	fprintf(f,"%d,%d,%s,%s\n",cs[j].id,cs[j].mo,cs[j].payment,cs[j].name);
	}
	fclose(f);
	go_to();
}
/*int c_display()
{ 	int i;
	FILE *f;
	//clrscr();
	f=fopen("custo.csv","r");
	printf("\n\n\t\t===>>display the customer record here<<=== ");
	printf("\n\n\n\n\n\t\tId,Mo,Payment,Name,Address\n");
	for(i=0;i<=4;i++)
	{   fflush(stdin);
		fscanf(f,"%s\n",cs[i].name);
	}
	for(i=1;i<=4;i++)
	{
		fflush(stdin);
		printf("\n\t\t%s",cs[i].name);
	}
	go_to();


}*/
int want_bye(float total,float grand_total)
{  	char a,b;
	grand_total=total+grand_total;
	printf("grand total=%f",grand_total);
	fflush(stdin);
	printf("\n\n Do you want to bye anything else ? (y or n) ");
	scanf("%c",&a);
	switch(a)
	{
	case 'y':
		menu(grand_total);
		break;
	case 'n':
		fflush(stdin);
		 printf("\n do you want to print bill ?");
		 scanf("%c",&b);
		 if(b=='y')
		 bill(grand_total);
		 else
		 m_menu();
		 break;
	default:
		printf(" \n\nwrong choice..!!!");
		m_menu();
	
	}
}
float total1(int m,int j)
{

	return(m*j);
};

int login()
{
	char id[5],v_id[6]="patel",v_password[6]="gecse",password[6];
	int host;
	int i,c=1;
	//clrscr();
	printf("\n\n\n\n\n\n\t\t\t**==Nerolac Products Management System==**\n\n");
	printf("\n\n\n\n\n\n\t\t\tlogin id:");
	//this section for the login_id

	scanf("%s",id);
	c=strcmp(id,v_id);

	// this section will provide the password;
	printf("\n\t\t\tpassword:");
	i=0;
	for(i=0;i<5;i++)
	{
		password[i]=getch();
		printf("*");
	}
	password[i]='\0';
	i=0;
	while(password[i] == v_password[i]  && password[i] != '\0' && v_password[i] != '\0' )
	i++;
	if( password[i] == '\0' && v_password[i] == '\0')
	{
	 host=1;

	}
	else
	{
		host=0;
	}
	if( c==0 && host ==1)
	{
		m_menu();
	}
	else
	{
		 char ch;
	 printf(" \n\t\t\tsorry wrong password or login id !!\n");
	 printf("\n\t\t\twant to try again ?\n");
	 printf("\n\t\t\ty or n\n ");
	 fflush(stdin);
	 scanf("%c",&ch);
	 if(ch == 'y')
	 {
	 login();
	 }

	 else
	 {
	 return 0;
	 }

	}

}
int customer_menu()
{
	int ch_c;
	//clrscr();
	printf("\n\n\t\t===>this is the cusomer menu <===");
	printf("\n\n\n\n\t\t1.New\n\t\t2.Main menu");
	scanf("\n%d",&ch_c);
	switch(ch_c)
	{
		case 1:nnew();
			break;
		/*case 2:
			c_display();
			break;*/
		case 2:m_menu();
			break;
		default:printf("give the right choice");
			go_to();
	}
}
int m_menu()
{   	int m_ch;
	char ch;
	//clrscr();
	printf("\n\n\n\n\t\tWelcome to nerolac management system: !!!!\n\n");
	printf("\n\n\t\tMain Menu:-\n");
	printf("\t\t1.Products\n\t\t2.Customer\n\t\t3.Help\n\t\t4.Exit\n");
	scanf("%d",&m_ch);
	switch(m_ch)
	{
		case 1:menu(0.0);
				break;
		case 2:customer_menu();
				break;
		case 3:help();
				break;
		case 4:printf("\n\n\n\n\n\n\n\n\t\t\t Good bye & Thanks\n\n\t\t\t From Amul & niki ");
			return 0;
			break;
		default:
			printf(" \n\n\t\tsoooo soorry pls try again" );
			fflush(stdin);
			printf("\n\t\twant to try again ? (y or n)\n");
			scanf("%c",&ch);
			if(ch=='y')
			m_menu();
			else
			return 0;
	}
}
int go_to()
{
 int ch;
 char n;
 printf("\n\n\t\t===>go to any where in the system<===");
 printf("\n\t\t1.Main_menu\n\t\t2.exit");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: m_menu();
	break;
 case 2: return 0;
	break;
 default:
	printf("\n\t\t wrong choice..want to try again ? (y or n)");
	scanf("%c",&n);
	if(n=='y')
	go_to();
	else
	return 0;
 }
}
int menu(float grand_total)
{
	int product_name;
	int i=10,j,p[10],c,m,price;
	float total;
	int id[10],pr[10],quan[10],qual[10],Altra,Stainer,Wood_Primer,Nerolac_Surksha;
	char a;
	grand_total=grand_total;
	//clrscr();
	printf("\n\t\tMenu of Product_name\n");
	printf("\t\t=================================================\n");
	printf("\t\t|| 1. Nerolac Synthetic Enemal                 ||\n");
	printf("\t\t|| 2. Nerolac Highpower Universal Stainer      ||\n");
	printf("\t\t|| 3. Nerolac Wood Primer White                ||\n");
	printf("\t\t|| 4. Nerolac Surksha                          ||\n");
	printf("\t\t|| 5. Nerolac Wall putty                       ||\n");
	printf("\t\t=================================================\n");
	//it start about the products...

	printf("\nwhich product to buy ??\n");
	scanf("%d",&c);
	switch(c)
	{
	case 1:
			printf("\nNerolac Synthenthic Enemal\n");
			printf("\n||====================================");
			printf("\n||1.Altra White                       ||");
			printf("\n||2.Nile Blue                         ||");
			printf("\n||3.Remain all Colors                 ||");
			printf("\nWhich Altra product do u buy??\n");
			scanf("%d",&Altra);
	switch(Altra)
	{
	case 1:
				printf("\nAltra White");
				printf("\n==========================================");
				printf("\nChoose qauntity 100ml,500ml,1litre,5litre if u want to buy??\n");
				fflush(stdin);
				scanf("%d",&quan[i]);
				if(quan[i]==100)
				{
				printf("\nid=1 price=65Rs. quality=Altra quantity=100ml\n",id[i],pr[i],quan[i],qual[i]);
				price=65;
				}
				else if(quan[i]==500)
				{
				printf("\nid=1 price=146Rs. quality=Altra quantity=500ml\n",id[i],pr[i],quan[i],qual[i]);
				price=146;
				}
				else if(quan[i]==1)
				{
				printf("\nid=1 price=276Rs. quality=Altra quantity=1litre\n",id[i],pr[i],quan[i],qual[i]);
				price=276;
				}
				else if(quan[i]==5)
				{
				printf("\nid=1 price=1000Rs. quality=Altra quantity=5litre\n",id[i],pr[i],quan[i],qual[i]);
				price=1000;
				}
				else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
				break;
	case 2:
				printf("\nNile blue");
				printf("\n==========================================");
				printf("\nChoose quantity 100ml,500ml,1litre,5litre if u want to buy??\n");
				fflush(stdin);
				scanf("%d",&quan[i]);
				if(quan[i]==100)
				{
				printf("\nid=1 price=30Rs. quality=Altra quantity=100ml\n",id[i],pr[i],quan[i],qual[i]);
				price=30;
				}
				else if(quan[i]==500)
				{
				printf("\nid=1 price=120Rs. quality=Altra quantity=500ml\n",id[i],pr[i],quan[i],qual[i]);
				price=120;
				}
				else if(quan[i]==1)
				{
				printf("\nid=1 price=240Rs. quality=Altra quantity=1litre\n",id[i],pr[i],quan[i],qual[i]);
				price=240;
				}
				else if(quan[i]==5)
				{
				printf("\nid=1 price=1000Rs. quality=Altra quantity=5litre\n",id[i],pr[i],quan[i],qual[i]);
				price=1000;
				}
				else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
				break;
	case 3:
				printf("\nRemain All Colors");
				printf("\n==========================================");
				printf("\nChoose qauntity 100ml,500ml,1litre,5litre if u want to buy??\n");
				fflush(stdin);
				scanf("%d",&quan[i]);
				if(quan[i]==100)
				{
				printf("\nid=1 price=34Rs. quality=Altra quantity=100ml\n",id[i],pr[i],quan[i],qual[i]);
				price=34;
				}
				else if(quan[i]==500)
				{
				printf("\nid=1 price=127Rs. quality=Altra quantity=500ml\n",id[i],pr[i],quan[i],qual[i]);
				price=127;
				}
				else if(quan[i]==1)
				{
				printf("\nid=1 price=246Rs. quality=Altra quantity=1litre\n",id[i],pr[i],quan[i],qual[i]);
				price=246;
				}
				else if(quan[i]==5)
				{
				printf("\nid=1 price=930Rs. quality=Altra quantity=5litre\n",id[i],pr[i],quan[i],qual[i]);
				price=930;
				}
				else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
				break;
	default:
				printf("wrong choice..!!");
				want_bye(0,grand_total);

	} 		
			how_many:
				fflush(stdin);
			printf("\nhow many product do u want buy?\n");
			if(scanf("%d",&m)==1);
			else
			{
				printf("please give the right nomber value");
				goto how_many;
			}
			//scanf("%d",&price);
			total=total1(m,price);
			printf("\ntotal1=%.2f Rs.",total);
			want_bye(total,grand_total);
			break;
	case 2:
			printf("\nNerolac Highpower Universal Stainer");
			printf("\n||=================================");
			printf("\n||1.Bantsena                       ||");
			printf("\n||2.Orange                         ||");
			printf("\n||3.Remain All Colors              ||");
			printf("\nWhich Stainer product do u buy??\n");
			scanf("%d",&Stainer);
	switch(Stainer)
	{
	case 1:
				printf("\nBantsena");
				printf("\n==========================================");
				printf("\nChoose qauntity 100ml,500ml,1litre,5litre if u want to buy??\n");
				fflush(stdin);
				scanf("%d",&quan[i]);
				if(quan[i]==100)
				{
				printf("\nid=2 price=63Rs. quality=Stainer quantity=100ml\n",id[i],pr[i],quan[i],qual[i]);
				price=63;
				}
				else if(quan[i]==500)
				{
				printf("\nid=2 price=150Rs. quality=Stainer quantity=500ml\n",id[i],pr[i],quan[i],qual[i]);
				price=150;
				}
				else if(quan[i]==1)
				{
				printf("\nid=2 price=270Rs. quality=Stainer quantity=1litre\n",id[i],pr[i],quan[i],qual[i]);
				price=270;
				}
				else if(quan[i]==5)
				{
				printf("\nid=2 price=950Rs. quality=Stainer quantity=5litre\n",id[i],pr[i],quan[i],qual[i]);
				price=950;
				}
				else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
				break;
	case 2:
				printf("\nOrange");
				printf("\n==========================================");
				printf("\nChoose qauntity 100ml,500ml,1litre,5litre if u want to buy??\n");
				fflush(stdin);
				scanf("%d",&quan[i]);
				if(quan[i]==100)
				{
				printf("\nid=2 price=33Rs. quality=Stainer quantity=100ml\n",id[i],pr[i],quan[i],qual[i]);
				price=33;
				}
				else if(quan[i]==500)
				{
				printf("\nid=2 price=150Rs. quality=Stainer quantity=500ml\n",id[i],pr[i],quan[i],qual[i]);
				price=150;
				}
				else if(quan[i]==1)
				{
				printf("\nid=2 price=270Rs. quality=Stainer quantity=1litre\n",id[i],pr[i],quan[i],qual[i]);
				price=270;
				}
				else if(quan[i]==5)
				{
				printf("\nid=2 price=950Rs. quality=Stainer quantity=5litre\n",id[i],pr[i],quan[i],qual[i]);
				price=950;
				}
				else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
				break;
	case 3:
				printf("\nRemain All Colors");
				printf("\n==========================================");
				printf("\nChoose qauntity 100ml,500ml,1litre,5litre if u want to buy??\n");
				fflush(stdin);
				scanf("%d",&quan[i]);
				if(quan[i]==100)
				{
				printf("\nid=2 price=25Rs. quality=Stainer quantity=100ml\n",id[i],pr[i],quan[i],qual[i]);
				price=25;
				}
				else if(quan[i]==500)
				{
				printf("\nid=2 price=45Rs. quality=Stainer quantity=500ml\n",id[i],pr[i],quan[i],qual[i]);
				price=45;
				}
				else if(quan[i]==1)
				{
				printf("\nid=2 price=70Rs. quality=Stainer quantity=1litre\n",id[i],pr[i],quan[i],qual[i]);
				price=70;
				}
				else if(quan[i]==5)
				{
				printf("\nid=2 price=95Rs. quality=Stainer quantity=5litre\n",id[i],pr[i],quan[i],qual[i]);
				price=95;
				}
					else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
				break;
	default:
				printf("wrong choice..!!");
				want_bye(0,grand_total);


	}
			how_many1:
				fflush(stdin);
				
			printf("\nhow many product do u want buy?\n");
			if(scanf("%d",&m)==1);
			else
			{
				printf("please give the right nomber value");
				goto how_many1;
			}
			//total= m*price;
			total=total1(m,price);
			printf("total =%.2f Rs.",total);
			want_bye(total,grand_total);
			break;
	case 3:
			printf("\nNerolac Wood Primer White");
			printf("\n||====================================");
			printf("\n||1.Oilbase                           ||");
			printf("\n||2.waterbase                         ||");
			printf("\n||3.Metalprimer                       ||");
			printf("\nWhich Wood Primer product do u buy??\n");
			scanf("%d",&Wood_Primer);
	switch(Wood_Primer)
	{
	case 1:
				printf("\nOilbase");
				printf("\n==========================================");
				printf("\nChoose qauntity 100ml,500ml,1litre,5litre if u want to buy??\n");
				fflush(stdin);
				scanf("%d",&quan[i]);
				if(quan[i]==100)
				{
				printf("\nid=3 price=55Rs. quality=Wood_Primer quantity=100ml\n",id[i],pr[i],quan[i],qual[i]);
				price=55;
				}
				else if(quan[i]==500)
				{
				printf("\nid=3 price=99Rs. quality=Wood_Primer quantity=500ml\n",id[i],pr[i],quan[i],qual[i]);
				price=99;
				}
				else if(quan[i]==1)
				{
				printf("\nid=3 price=170Rs. quality=Wood_Primer quantity=1litre\n",id[i],pr[i],quan[i],qual[i]);
				price=170;
				}
				else if(quan[i]==5)
				{
				printf("\nid=3 price=665Rs. quality=Wood_Primer quantity=5litre\n",id[i],pr[i],quan[i],qual[i]);
				price=665;
				}
					else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
				break;
	case 2:
				printf("\nWaterbase");
				printf("\n==========================================");
				printf("\nChoose qauntity 100ml,500ml,1litre,5litre if u want to buy??\n");
				fflush(stdin);
				scanf("%d",&quan[i]);
				if(quan[i]==100)
				{
				printf("\nid=3 price=45Rs. quality=Wood_Primer quantity=100ml\n",id[i],pr[i],quan[i],qual[i]);
				price=45;
				}
				else if(quan[i]==500)
				{
				printf("\nid=3 price=95Rs. quality=Wood_Primer quantity=500ml\n",id[i],pr[i],quan[i],qual[i]);
				price=95;
				}
				else if(quan[i]==1)
				{
				printf("\nid=3 price=170Rs. quality=Wood_Primer quantity=1litre\n",id[i],pr[i],quan[i],qual[i]);
				price=170;
				}
				else if(quan[i]==5)
				{
				printf("\nid=3 price=665Rs. quality=Wood_Primer quantity=5litre\n",id[i],pr[i],quan[i],qual[i]);
				price=665;
				}
					else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
				break;
	case 3:
				printf("\nMetal Primer");
				printf("\n==========================================");
				printf("\nChoose qauntity 100ml,500ml,1litre,5litre if u want to buy??\n");
				fflush(stdin);
				scanf("%d",&quan[i]);
				if(quan[i]==100)
				{
				printf("\nid=3 price=55Rs. quality=Wood_Primer quantity=100ml\n",id[i],pr[i],quan[i],qual[i]);
				price=55;
				}
				else if(quan[i]==500)
				{
				printf("\nid=3 price=72Rs. quality=Wood_Primer quantity=500ml\n",id[i],pr[i],quan[i],qual[i]);
				price=72;
				}
				else if(quan[i]==1)
				{
				printf("\nid=3 price=170Rs. quality=Wood_Primer quantity=1litre\n",id[i],pr[i],quan[i],qual[i]);
				price=170;
				}
				else if(quan[i]==5)
				{
				printf("\nid=3 price=501Rs. quality=Wood_Primer quantity=5litre\n",id[i],pr[i],quan[i],qual[i]);
				price=501;
				}
					else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
				break;
	default:
				printf("wrong choice..!!");
				want_bye(0,grand_total);

	}
			how_many2:
				fflush(stdin);
			printf("\nhow many product do u want buy?\n");
			if(scanf("%d",&m)==1);
			else
			{
				printf("please give the right nomber value");
				goto how_many2;
			}
			total= m*price;
			printf("total =%10.2f Rs.",total);
			want_bye(total,grand_total);
			break;
	case 4:
			printf("\nNerolac Surksha");
			printf("\n||====================================");
			printf("\n||1.White                             ||");
			printf("\n||2.Rodeas                            ||");
			printf("\n||3.Remain All Colors                 ||");
			printf("\nWhich Nerolac_Surksha product do u buy??\n");
			scanf("%d",&Nerolac_Surksha);
	switch(Nerolac_Surksha)
	{
	case 1:
				printf("\nWhite");
				printf("\n==========================================");
				printf("\nChoose qauntity 1kg.,2kg.,5kg.,10kg. if u want to buy??\n");
				fflush(stdin);
				scanf("%d",&quan[i]);
				if(quan[i]==1)
				{
				printf("\nid=4 price=118Rs. quality=Nerolac_Surksha quantity=1kg.\n",id[i],pr[i],quan[i],qual[i]);
				price=118;
				}
				else if(quan[i]==2)
				{
				printf("\nid=4 price=233Rs. quality=Nerolac_Surksha quantity=2kg.\n",id[i],pr[i],quan[i],qual[i]);
				price=233;
				}
				else if(quan[i]==5)
				{
				printf("\nid=4 price=530Rs. quality=Nerolac_Surksha quantity=5kg.\n",id[i],pr[i],quan[i],qual[i]);
				price=530;
				}
				else if(quan[i]==10)
				{
				printf("\nid=4 price=1033Rs. quality=Nerolac_Surksha quantity=10kg.\n",id[i],pr[i],quan[i],qual[i]);
				price=1033;
				}
					else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
				break;
	case 2:
				printf("\nRodeas");
				printf("\n==========================================");
				printf("\nChoose qauntity 1kg.,2kg.,5kg.,10kg. if u want to buy??\n");
				fflush(stdin);
				scanf("%d",&quan[i]);
				if(quan[i]==1)
				{
				printf("\nid=4 price=122Rs. quality=Nerolac_Surksha quantity=1kg.\n",id[i],pr[i],quan[i],qual[i]);
				price=122;
				}
				else if(quan[i]==2)
				{
				printf("\nid=4 price=241Rs. quality=Nerolac_Surksha quantity=2kg.\n",id[i],pr[i],quan[i],qual[i]);
				price=241;
				}
				else if(quan[i]==5)
				{
				printf("\nid=4 price=548Rs. quality=Nerolac_Surksha quantity=5kg.\n",id[i],pr[i],quan[i],qual[i]);
				price=548;
				}
				else if(quan[i]==10)
				{
				printf("\nid=4 price=1033Rs. quality=Nerolac_Surksha quantity=5kg.\n",id[i],pr[i],quan[i],qual[i]);
				price=1033;
				}
				else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
				break;
	case 3:
				printf("\nRemain All Colors");
				printf("\n==========================================");
				printf("\nChoose qauntity 1kg.,2kg.,5kg.,10kg. if u want to buy??\n");
				fflush(stdin);
				scanf("%d",&quan[i]);
				if(quan[i]==1)
				{
				printf("\nid=4 price=127Rs. quality=Nerolac_Surksha quantity=1kg.\n",id[i],pr[i],quan[i],qual[i]);
				price=127;
				}
				else if(quan[i]==2)
				{
				printf("\nid=4 price=246Rs. quality=Nerolac_Surksha quantity=2kg.\n",id[i],pr[i],quan[i],qual[i]);
				price=246;
				}
				else if(quan[i]==5)
				{
				printf("\nid=4 price=548Rs. quality=Nerolac_Surksha quantity=5kg.\n",id[i],pr[i],quan[i],qual[i]);
				price=548;
				}
				else if(quan[i]==10)
				{
				printf("\nid=4 price=1133Rs. quality=Nerolac_Surksha quantity=10kg.\n",id[i],pr[i],quan[i],qual[i]);
				price=1133;
				}
					else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
				break;
	default:
				printf("wrong choice..!!");
				want_bye(0,grand_total);
	}	
			how_many3:
				fflush(stdin);
			printf("\nhow many product do u want buy?\n");
			if(scanf("%d",&m)==1);
			else
			{
				printf("please give the right nomber value");
				goto how_many3;
			}
			total= m*price;
			printf("total =%0.2f Rs.",total);
			want_bye(total,grand_total);
			break;
	case 5:
			printf("\nNerolac Wall Putty");
			printf("\n==========================================");
			printf("\nChoose qauntity 1kg.,2kg.,5kg.,10kg. if u want to buy??\n");
			fflush(stdin);
			scanf("%d",&quan[i]);
			if(quan[i]==1)
			{
			printf("\nid=5 price=66Rs. quality=Wall Putty quantity=1kg.\n",id[i],pr[i],quan[i],qual[i]);
			price=66;
			}
			else if(quan[i]==2)
			{
			printf("\nid=5 price=230Rs. quality=Wall Putty quantity=2kg.\n",id[i],pr[i],quan[i],qual[i]);
			price=230;
			}
			else if(quan[i]==5)
			{
			printf("\nid=5 price=66Rs. quality=Wall Putty quantity=5kg.\n",id[i],pr[i],quan[i],qual[i]);
			price=310;
			}
		       else if(quan[i]==10)
			{
			printf("\nid=5 price=560Rs. quality=Wall Putty quantity=10kg.\n",id[i],pr[i],quan[i],qual[i]);
			price=560;
			}
				else
				{
				printf("wrong choice..!!");
				want_bye(0,grand_total);	
				}
			how_many4:
				fflush(stdin);
			printf("\nhow many product do u want buy?\n");
			if(scanf("%d",&m)==1);
			else
			{
				printf("please give the right nomber value");
				goto how_many4;
			}
			total= m*price;
			printf("total  =%.2f Rs.",total);
			want_bye(total,grand_total);
			break;
default:
			printf("wrong choice..!!");
			want_bye(0,grand_total);
}
};
int main()
{
	//clrscr();
	login();
	getch();
}
