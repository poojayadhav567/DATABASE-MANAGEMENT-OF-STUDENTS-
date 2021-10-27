#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
int main()
{
	FILE *fp,*ft;
	char another,choice;
	struct student
	{
		char first_name [50],lat_name[50];
		char course[100];
		int session;
	};
	struct student e;
	char xfirst_name[50],xlast_name[50];
	long int recsize;
	 fp = fopen("user's.txt"," rb+");
	 
	if(fp == NULL)
	{
		fp =fopen("user's.txt","wb+");
		if(fp==NULL)
		{
			puts("cannot open file");
			return 0;
		}
	}
	recsize = sizeof(e);
	while(1)
	{
		system("cls");
		
		cout << "\t\t========== STUDENT DATABASE MANAGEMENT SYSTEM =======" ;
		cout << "\n\n                                         ";
		cout << "\n\n";
		cout << "\n \t\t\t 1. ADD   RECORDS";
		cout<<"\n \t\t\t 2. LIST   RECORDS";
		cout<<"\n \t\t\t 3. MODIFY   RECORDS";
		cout<<"\n \t\t\t 4. DELETE   RECORDS";
		cout<<"\n \t\t\t 5.  EXIT   RECORDS";
		cout<<"\n\n";
		cout<<"\t\t\t  select your choice :=> ";
		fflush(stdin);
		choice = getche();
		switch(choice)
		{
			case '1':
				fseek(fp,0,SEEK_END);
				another ='Y';
				while(another == 'Y' || another == 'y')
				{
					system("cls");
					cout<<"enter the first name : ";
					cin>>e.first_name;
					cout<<"enter the last name : ";
					cin>>e.last_name;
					cout<<"enter the course : ";
					cin>>e.course;
					cout<<"enter the section : ";
					cin>>e.section;
					fwrite(&e,recsixe,1,fp);
					cout<<"\n add another record (Y/N)";
					fflush(stdin);
					another = getchar();
					
				}
			break;
			case '2':
				system("cls");
				rewind(fp);
				cout<<"===view the records in the database ==== ";
				cout<<"\n";
				while(fread(&e,recsize,1,fp)==1)
				{
					cout<<"\n";
					cout<<"\n"<<e.first_name<<setw(10)<<e.last_name;
					cout<<"\n";
					cout<<"\n"<<e.course<<setw(8)<<e.section;
					}
					cout<<"\n\n";
					system("pause");
					break;
				case '3';
				system("cls");
				another='Y'	;
				while(another=='Y' || another == 'y')
				{
					cout<<"\n enter the last name of the student : ";
					cin>>xlast_name;
					rewind(fp);
					while(fread(&e,recsize,1,fp)==1)
					{
						if(strcmp(e.last_name,xlast_name)==0)
						{
						cout<<"enter the first name : "	
						cin>>e.first_name;
						cout<<"enter the last name : ";
					    cin>>e.last_name;
					    cout<<"enter the course : ";
					    cin>>e.course;
					    cout<<"enter the section : ";
					     cin>>e.section;
						fseek(fp, recsize,SEEK_CUR);
						fwrite(&e,recsize,1,fp);
						break;
						}
					}
					else
					cout<<"record not found ";
				}
				cout<<"\n modify another record (Y/N)";
				fflush(stdin);
				another = getchar();
			}
			break;
			   case '4'	;
			   system("cls");
			   another='Y';
			   while(another =='Y'||another == 'y')	
			   {
			   	cout<<"\n enter the last name of the student to delete :";
			   	cin>>xlast_name;
			   	ft = fopen("temp.dat","wb");
			   	rewind(fp);
			   	while(fread(&e,recsize,1,fp)==1)
			   	if(strcmp(e.last_name,xlast_name)!=0)
			   	{
			   		fwrite(&e,recsize,1,ft);
				   }
				   fclose(fp);
				   fclose(ft);
				   remove("users.txt");
				   rename("temp.dat","users.txt");
				   fp=fpoen("users.txt","rb+");
				   cout<<"\n delete another record (Y/N)";
				   fflush(stdin);
				   another = getchar();
				   
				   }
				   break;
			  case '5':
			  	fclose(fp);
			  	cout<<"\n\n";
			  	cout<<"\t\t  thank you for using this software";
			  	cout<<"\n\n";
			  	exit(0);
	            	}
				  }
				  system("pause");
				  return 0;
			}
