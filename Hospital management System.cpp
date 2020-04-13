//Hospital Management System 
#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include<string>
#include<Process.h>
#include<dos.h>
#include<stdlib.h>
using namespace std;
//for docter`s appointment
class appoint{
char name[30],n[30],i[50],r[42],d[50],pdov[20],t[20];
public:
void ainput()
{
cout<<"\n NAME OF PATIENT:-\n FIRST NAME- ";
cin>>name;
cout<<"LAST NAME-";
cin>>n;
cout<<"\n ENTER THE PHONE NUMBER :- ";
cin>>i;
cout<<"\n ENTER THE DISEASE:- ";
cin>>d;
cout<<"\n ENTER THE DATE OF APPOINTMENT IN HOSPITAL(DATE/MONTH/YEAR):- ";
cin>>pdov;
cout<<"\n ENTER THE TIME OF APPOINTMENT IN HOSPITAL(HH/MM):- ";
cin>>t;
cout<<"\n ENTER THE NAME OF DOCTOR IN-CHARGE:- ";
cin>>r;
}
void aoutput()
{
cout<<"\n\t\t\t\t PATIENT DETAILS \n";
cout<<"\n NAME OF PATIENT:- "<<name<<n;
cout<<"\n PHONE NUMBER:- "<<i;
cout<<"\n DATE OF VISIT TO THE HOSPITAL(DATE/MONTH/YEAR):- "<<pdov;
cout<<"\n TIME OF VISIT TO THE HOSPITAL(hh/mm):- "<<t;
cout<<"\n DOCTOR IN-CHARGE:- "<<r;
}
char *retpho()
{
return i;
}
char *retna(){
return name;
}
};
void awrite()
{
cout<<"\n\n\t\t\t\t  APPOINTMENT ADD MENU:-"<<"\n";
appoint a;
ofstream fout("a.dat",ios::app|ios::binary);
a.ainput();
fout.write((char*)&a,sizeof(appoint));
cout<<"\n\n-------------------------------------------------------------------------------";
cout<<"\n press enter to return back";
fout.close();
getch ();
}
void adisplay()
{
int c=0;
cout<<"\n\n\t\t\t\t !!!! DISPLAY !!!!"<<"\n\n";
appoint a;
ifstream fin("a.dat",ios::binary);
while(fin.read((char*)&a,sizeof(a)))
{
c++;
a.aoutput();
cout<<"\n\n-------------------------------------------------------------------------------";
}
fin.close();
if (c==0)
{
cout<<"\n\t you may have installed new software"<<"\n\t so you should first add some data to have a display";
}
cout<<"\n Press Enter To Continue..";
getch ();
}
void adel()
{

char kx;
appoint a;
ifstream fin("a.dat",ios::binary);
ofstream fout("e.dat",ios::app|ios::binary);
char m[40],x[40];
int flag=0,kshaz=0;
cout<<"PATIENT`APPOINTMENT DELETE MENU";
cout<<"~~~~~~~~~~~~~~~~~~";
cout<<"ENTER NAME OF PATIENT WHOSE APPOINTMENT IS TO BE DELETED(first name) space (last name) "<<"\n\n\t\t";
cin>>m>>x;
while(fin.read((char*)&a,sizeof(a)))
{
if(strcmpi(a.retna(),m)==0 )
{
flag=1;
cout<<"\n\t\t\t !!! RECORD FOUND !!! "<<"\n";
a.aoutput();
cout<<"\n\n\t\t WANT TO DELETE THIS RECORD ";
cout<<"\n\n\t\t WARNING : ONCE DELETED CANNOT BE RETRIEVED !!!";
cout<<"\n\n PLEASE PROVIDE INPUT (Y OR N)";
cout<<"\n\n\t\t\t\t";
cin>>kx;
if(kx=='y' || kx=='Y')
{
cout<<"\n\n\t DELETING . .";
cout<<"\n\n\t\t !!! DELETED  !!!";
cout<<"\n\n\t PRESS ENTER TO RETURN TO PREVIOUS MENU ";
getch ();
}
else
{
fout.write((char*)&a,sizeof(a));
kshaz++;
}
}
else
{
fout.write((char*)&a,sizeof(a));
}
}
fin.close();
fout.close();
if(flag==0)
{
cout<<"THERE IS NO patient`s appointment WITH THIS NAME";
cout<<"PRESS ENTER TO RETURN TO MENU";
getch();
}
if(kshaz==1)
{
cout<<"\n\t\t\t\t !!! NO CHANGES HAVE BEEN MADE";
getch ();
}
remove("a.dat");
rename("e.dat","a.dat");
}
void aupdate()
{
fstream f("a.dat",ios::in|ios::ate|ios::app|ios::binary);
ofstream fout("e.dat",ios::binary);
appoint a;
char s[40],z[40],flag=0;
cout<<"PATIENT`APPOINTMENT UPDATE MENU";
cout<<"~~~~~~~~~~~~~~~~~~";
cout<<"Enter The Name Of Patient Whose appointment Is To Be Updated (first name) space (last name) ";
cout<<"\n\t";
cin>>s>>z;
f.seekp(0,ios::beg);
while(f.read((char*)&a,sizeof (a)))
{
if(strcmpi(a.retna(),s)==0)
{
flag=1;
cout<<"\n RECORD FOUND!!";
a.aoutput();
cout<<"\n\n\t Press Enter To Add New Informaion";
getch();
cout<<"\n\t\t\t\t NEW INFOMATION";
cout<<"\n\t\t\t\t --------------";
cout<<"\n";
a.ainput();
cout<<"\n\t\t Updating....";
cout<<"\n\n\t\t !!UPDATED!!";
cout<<"\n\n press enter to return to menu";
getch();
}
fout.write((char*)&a,sizeof(a));
}
if(flag==0)
{
cout<<"\n\n\t\t\t\t There Is No Patient`appointment With This Name";
cout<<"press enter to return to menu";
getch();
}
f.close();
fout.close();
remove("a.dat");
rename("e.dat","a.dat");
}
void asearch()
{
char w[40],z[40],phone[12];
appoint a;
ifstream fin;
int ch,flag=0;
do
{
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  PATIENT`APPOINTMENT SEARCH SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> SEARCH BY NAME                                |\n";
cout<<"\t\t\t\t\t\t|             2  >> SEARCH BY NUMBER                              |\n";
cout<<"\t\t\t\t\t\t|             3  >> RETURN TO PREVIOUS PAGE                       |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>ch;
switch(ch)
{
case 1:
	cout<<"ENTER THE NAME- (first name) space (last name) ";
	cin>>w>>z;
	cout<<"SEARCHING";
	for(int kl=0;kl<=7;kl++)
	{
	cout<<" . " ;
	
	}
	fin.open("a.dat",ios::binary);
	while(fin.read((char*)&a,sizeof (a)))
	{
	if(strcmpi(a.retna(),w)==0)
	{
	flag=1;
	cout<<" !!FOUND!!";
	cout<<"Press Enter To See Record";
	getch();
	a.aoutput();
	getch();
	}
	}
	if(flag==0)
	{
	cout<<"There Is No Patient`appointment With This Name";
	cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
case 2:
	cout<<"ENTER THE PHONE NUMBER- ";
	cin>>phone;
	cout<<"SEARCHING....";
	
	fin.open("a.dat",ios::binary);
	while(fin.read((char*)&a,sizeof (a)))
	{
	if(strcmpi(a.retpho(),phone)==0)
	{
	flag=1;
	cout<<"FOUND!!";
	cout<<"Press Enter To See Record";
	getch();
	a.aoutput();
	getch();
	}
	}
	if(flag==0)
	{
	cout<<"There Is No Patient`appointment With This Phone Number";
	cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
}
}while(ch!=3);
}
void amenu()
{
int c;
appoint a;
do
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  APPOINTMENT MANAGEMENT SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Add Patient`s appointment Info                |\n";
cout<<"\t\t\t\t\t\t|             2  >> Display all appointment Info                  |\n";
cout<<"\t\t\t\t\t\t|             3  >> Delete Patient`appointment Info               |\n";
cout<<"\t\t\t\t\t\t|             4  >> Update Patient`s appointment Info             |\n";
cout<<"\t\t\t\t\t\t|             5  >> Search Particular Patient`s appointmemt Info  |\n";
cout<<"\t\t\t\t\t\t|             6  >> Exit the Program                              |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>c;
switch(c)
{
case 1:awrite();break;
case 2:adisplay();break;
case 3:adel();break;
case 4:aupdate();break;
case 5:asearch();break;
case 6:exit(0);break;
}
}while(c!=6);

}
//for bill and room reservation
//for bill
class bill{
char name[30],n[30],i[50],r[42];
char q,w,e,t,y,u,o,p,b,m;
int a,s,d,f,g,h,j,k,l,c,total;
public:
void binput()
{
	total=a+s+d+f+g+h+j+k+l+c;
cout<<"\n NAME OF PATIENT:-\n FIRST NAME- ";
cin>>name;
cout<<"LAST NAME-";
cin>>n;
cout<<"\n ENTER THE PHONE NUMBER :- ";
cin>>i;
cout<<"\n ENTER THE NAME OF DOCTOR IN-CHARGE:- ";
cin>>r;
cout<<"\n bill calculation-   (name of expences)    (amount)";
cout<<"\n                      1.";cin>>q;cout<<"\t\t\t\t\t";cin>>a;
cout<<"\n                      2.";cin>>w;cout<<"\t\t\t\t\t";cin>>s;
cout<<"\n                      3.";cin>>e;cout<<"\t\t\t\t\t";cin>>d;
cout<<"\n                      4.";cin>>t;cout<<"\t\t\t\t\t";cin>>f;
cout<<"\n                      5.";cin>>y;cout<<"\t\t\t\t\t";cin>>g;
cout<<"\n                      6.";cin>>u;cout<<"\t\t\t\t\t";cin>>h;
cout<<"\n                      7.";cin>>o;cout<<"\t\t\t\t\t";cin>>j;
cout<<"\n                      8.";cin>>p;cout<<"\t\t\t\t\t";cin>>k;
cout<<"\n                      9.";cin>>b;cout<<"\t\t\t\t\t";cin>>l;
cout<<"\n                     10.";cin>>m;cout<<"\t\t\t\t\t";cin>>c;
cout<<"\n                  total----";cin>>total;
}
void boutput()
{
cout<<"\n\t\t\t\t BILL DETAILS \n";
cout<<"\n NAME OF PATIENT:- "<<name<<n;
cout<<"\n PHONE NUMBER:- "<<i;
cout<<"\n DOCTOR IN-CHARGE:- "<<r;
cout<<"\n BILL CALCULATION-  (name of expenses)    (amount)";
cout<<"\n                      1."<<q<<"\t\t\t\t\t"<<a;
cout<<"\n                      2."<<w<<"\t\t\t\t\t"<<s;
cout<<"\n                      3."<<e<<"\t\t\t\t\t"<<d;
cout<<"\n                      4."<<t<<"\t\t\t\t\t"<<f;
cout<<"\n                      5."<<y<<"\t\t\t\t\t"<<g;
cout<<"\n                      6."<<u<<"\t\t\t\t\t"<<h;
cout<<"\n                      7."<<o<<"\t\t\t\t\t"<<j;
cout<<"\n                      8."<<p<<"\t\t\t\t\t"<<k;
cout<<"\n                      9."<<n<<"\t\t\t\t\t"<<l;
cout<<"\n                     10."<<m<<"\t\t\t\t\t"<<c;
cout<<"\n                  total----"<<total;
}
char *retpho()
{
return i;
}
char *retna(){
return name;
return n;
}
};
void bwrite()
{
cout<<"\n\n\t\t\t\t  BILL ADD MENU:-"<<"\n";
bill b;
ofstream fout("b.dat",ios::app|ios::binary);
b.binput();
fout.write((char*)&b,sizeof(bill));
cout<<"\n\n-------------------------------------------------------------------------------";
cout<<"\n press enter to return back";
fout.close();
getch ();
}
void bdisplay()
{
int c=0;
cout<<"\n\n\t\t\t\t !!!! DISPLAY !!!!"<<"\n\n";
bill b;
ifstream fin("b.dat",ios::binary);
while(fin.read((char*)&b,sizeof(b)))
{
c++;
b.boutput();
cout<<"\n\n-------------------------------------------------------------------------------";
}
fin.close();
if (c==0)
{
cout<<"\n\t you may have installed new software"<<"\n\t so you should first add some data to have a display";
}
cout<<"\n Press Enter To Continue..";
getch ();
}
void bdel()
{

char kx;
bill b;
ifstream fin("b.dat",ios::binary);
ofstream fout("c.dat",ios::app|ios::binary);
char m[40],x[40];
int flag=0,kshaz=0;
cout<<"PATIENT`BILL DELETE MENU";
cout<<"~~~~~~~~~~~~~~~~~~";
cout<<"ENTER NAME OF PATIENT WHOSE BILL IS TO BE DELETED(first name) space (last name) "<<"\n\n\t\t";
cin>>m>>x;
while(fin.read((char*)&b,sizeof(b)))
{
if(strcmpi(b.retna(),m)==0 )
{
flag=1;
cout<<"\n\t\t\t !!! RECORD FOUND !!! "<<"\n";
b.boutput();
cout<<"\n\n\t\t WANT TO DELETE THIS RECORD ";
cout<<"\n\n\t\t WARNING : ONCE DELETED CANNOT BE RETRIEVED !!!";
cout<<"\n\n PLEASE PROVIDE INPUT (Y OR N)";
cout<<"\n\n\t\t\t\t";
cin>>kx;
if(kx=='y' || kx=='Y')
{
cout<<"\n\n\t DELETING . .";
cout<<"\n\n\t\t !!! DELETED  !!!";
cout<<"\n\n\t PRESS ENTER TO RETURN TO PREVIOUS MENU ";
getch ();
}
else
{
fout.write((char*)&b,sizeof(b));
kshaz++;
}
}
else
{
fout.write((char*)&b,sizeof(b));
}
}
fin.close();
fout.close();
if(flag==0)
{
cout<<"THERE IS NO patient`bill WITH THIS NAME";
cout<<"PRESS ENTER TO RETURN TO MENU";
getch();
}
if(kshaz==1)
{
cout<<"\n\t\t\t\t !!! NO CHANGES HAVE BEEN MADE";
getch ();
}
remove("b.dat");
rename("c.dat","b.dat");
}
void bupdate()
{
fstream f("b.dat",ios::in|ios::ate|ios::app|ios::binary);
ofstream fout("c.dat",ios::binary);
bill b;
char s[40],z[40],flag=0;
cout<<"PATIENT`BILL UPDATE MENU";
cout<<"~~~~~~~~~~~~~~~~~~";
cout<<"Enter The Name Of Patient Whose BILL Is To Be Updated (first name) space (last name) ";
cout<<"\n\t";
cin>>s>>z;
f.seekp(0,ios::beg);
while(f.read((char*)&b,sizeof (b)))
{
if(strcmpi(b.retna(),s)==0)
{
flag=1;
cout<<"\n RECORD FOUND!!";
b.boutput();
cout<<"\n\n\t Press Enter To Add New Informaion";
getch();
cout<<"\n\t\t\t\t NEW INFOMATION";
cout<<"\n\t\t\t\t --------------";
cout<<"\n";
b.binput();
cout<<"\n\t\t Updating....";
cout<<"\n\n\t\t !!UPDATED!!";
cout<<"\n\n press enter to return to menu";
getch();
}
fout.write((char*)&b,sizeof(b));
}
if(flag==0)
{
cout<<"\n\n\t\t\t\t There Is No Patient`bill With This Name";
cout<<"press enter to return to menu";
getch();
}
f.close();
fout.close();
remove("b.dat");
rename("c.dat","b.dat");
}
void bsearch()
{
char w[40],z[40],phone[12];
bill b;
ifstream fin;
int ch,flag=0;
do
{
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  PATIENT`BILL SEARCH SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> SEARCH BY NAME                                |\n";
cout<<"\t\t\t\t\t\t|             2  >> SEARCH BY NUMBER                              |\n";
cout<<"\t\t\t\t\t\t|             3  >> RETURN TO PREVIOUS PAGE                       |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>ch;
switch(ch)
{
case 1:
	cout<<"ENTER THE NAME- (first name) space (last name) ";
	cin>>w>>z;
	cout<<"SEARCHING";
	for(int kl=0;kl<=7;kl++)
	{
	cout<<" . " ;
	
	}
	fin.open("b.dat",ios::binary);
	while(fin.read((char*)&b,sizeof (b)))
	{
	if(strcmpi(b.retna(),w)==0)
	{
	flag=1;
	cout<<" !!FOUND!!";
	cout<<"Press Enter To See Record";
	getch();
	b.boutput();
	getch();
	}
	}
	if(flag==0)
	{
	cout<<"There Is No Patient`bill With This Name";
	cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
case 2:
	cout<<"ENTER THE PHONE NUMBER- ";
	cin>>phone;
	cout<<"SEARCHING....";
	
	fin.open("b.dat",ios::binary);
	while(fin.read((char*)&b,sizeof (b)))
	{
	if(strcmpi(b.retpho(),phone)==0)
	{
	flag=1;
	cout<<"FOUND!!";
	cout<<"Press Enter To See Record";
	getch();
	b.boutput();
	getch();
	}
	}
	if(flag==0)
	{
	cout<<"There Is No Patient`bill With This Phone Number";
	cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
}
}while(ch!=3);
}
void bmenu()
{
int c;
bill b;
do
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  PATIENT`BILL MANAGEMENT SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Add bill for patient                          |\n";
cout<<"\t\t\t\t\t\t|             2  >> Display all Patient`s bill Info               |\n";
cout<<"\t\t\t\t\t\t|             3  >> Delete Patient`s bill Info                    |\n";
cout<<"\t\t\t\t\t\t|             4  >> Update Patient`s bill Info                    |\n";
cout<<"\t\t\t\t\t\t|             5  >> Search Particular Patient`s bill Info         |\n";
cout<<"\t\t\t\t\t\t|             6  >> Exit the Program                              |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>c;
switch(c)
{
case 1:bwrite();break;
case 2:bdisplay();break;
case 3:bdel();break;
case 4:bupdate();break;
case 5:bsearch();break;
case 6:exit(0);break;
}
}while(c!=6);

}
//for room reservation
class room{
char id[10],name[30],n[30],a[20],r[100];
public:
void rinput()
{
cout<<"\n ROOM ID ";
cin>>id;
cout<<"\n NAME OF PATIENT:-\n FIRST NAME- ";
cin>>name;
cout<<"LAST NAME-";
cin>>n;
cout<<"\n TYPE OF ROOM(ac/nonac) ";
cin>>a;
cout<<"\n PRICE OF ROOM  ";
cin>>r;
}
void routput()
{
cout<<"\n\t\t\t\t LAB DETAILS \n";
cout<<"\n ID:- "<<id;
cout<<"\n NAME of PATIENT-"<<name<<n;
cout<<"\n TYPE OF ROOM :- "<<a;
cout<<"\n PRICE OF ROOM:- "<<r;

}

char *retna(){
return id;
}
};
void rwrite()
{
cout<<"\n\n\t\t\t\t  ROOM DETAIL ADD MENU:-"<<"\n";
room r;
ofstream fout("r.dat",ios::app|ios::binary);
r.rinput();
fout.write((char*)&r,sizeof(room));
cout<<"\n\n-------------------------------------------------------------------------------";
cout<<"\n press enter to return back";
fout.close();
getch ();
}
void rdisplay()
{
int c=0;
cout<<"\n\n\t\t\t\t !!!! DISPLAY !!!!"<<"\n\n";
room r;
ifstream fin("r.dat",ios::binary);
while(fin.read((char*)&r,sizeof(r)))
{
c++;
r.routput();
cout<<"\n\n-------------------------------------------------------------------------------";
}
fin.close();
if (c==0)
{
cout<<"\n\t you may have installed new software"<<"\n\t so you should first add some data to have a display";
}
cout<<"\n Press Enter To Continue..";
getch ();
}
void rdel()
{

char kx;
room r;
ifstream fin("r.dat",ios::binary);
ofstream fout("q.dat",ios::app|ios::binary);
char m[40];
int flag=0,kshaz=0;
cout<<"ROOM DETAIL DELETE MENU";
cout<<"~~~~~~~~~~~~~~~~~~";
cout<<"ENTER ID OF ROOM WHOSE RECORD IS TO BE DELETED "<<"\n\n\t\t";
cin>>m;
while(fin.read((char*)&r,sizeof(r)))
{
if(strcmpi(r.retna(),m)==0 )
{
flag=1;
cout<<"\n\t\t\t !!! RECORD FOUND !!! "<<"\n";
r.routput();
cout<<"\n\n\t\t WANT TO DELETE THIS RECORD ";
cout<<"\n\n\t\t WARNING : ONCE DELETED CANNOT BE RETRIEVED !!!";
cout<<"\n\n PLEASE PROVIDE INPUT (Y OR N)";
cout<<"\n\n\t\t\t\t";
cin>>kx;
if(kx=='y' || kx=='Y')
{
cout<<"\n\n\t DELETING . .";
cout<<"\n\n\t\t !!! DELETED  !!!";
cout<<"\n\n\t PRESS ENTER TO RETURN TO PREVIOUS MENU ";
getch ();
}
else
{
fout.write((char*)&r,sizeof(r));
kshaz++;
}
}
else
{
fout.write((char*)&r,sizeof(r));
}
}
fin.close();
fout.close();
if(flag==0)
{
cout<<"THERE IS NO ROOM WITH THIS id";
cout<<"PRESS ENTER TO RETURN TO MENU";
getch();
}
if(kshaz==1)
{
cout<<"\n\t\t\t\t !!! NO CHANGES HAVE BEEN MADE";
getch ();
}
remove("r.dat");
rename("q.dat","r.dat");
}
void rupdate()
{
fstream f("r.dat",ios::in|ios::ate|ios::app|ios::binary);
ofstream fout("q.dat",ios::binary);
room r;
char s[40],flag=0;
cout<<"ROOM DETAIL UPDATE MENU";
cout<<"~~~~~~~~~~~~~~~~~~";
cout<<"Enter The ID OF ROOM Whose Record Is To Be Updated";
cout<<"\n\t";
cin>>s;
f.seekp(0,ios::beg);
while(f.read((char*)&r,sizeof (r)))
{
if(strcmpi(r.retna(),s)==0)
{
flag=1;
cout<<"\n RECORD FOUND!!";
r.routput();
cout<<"\n\n\t Press Enter To Add New Informaion";
getch();
cout<<"\n\t\t\t\t NEW INFOMATION";
cout<<"\n\t\t\t\t --------------";
cout<<"\n";
r.rinput();
cout<<"\n\t\t Updating....";
cout<<"\n\n\t\t !!UPDATED!!";
cout<<"\n\n press enter to return to menu";
getch();
}
fout.write((char*)&r,sizeof(r));
}
if(flag==0)
{
cout<<"\n\n\t\t\t\t There Is No room With This id";
cout<<"press enter to return to menu";
getch();
}
f.close();
fout.close();
remove("r.dat");
rename("q.dat","r.dat");
}
void rsearch()
{
char w[40];
room r;
ifstream fin;
int ch,flag=0;
do
{
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ROOM DETAIL SEARCH SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> SEARCH BY ID                                  |\n";
cout<<"\t\t\t\t\t\t|             2  >> RETURN TO PREVIOUS PAGE                       |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>ch;
switch(ch)
{
case 1:
	cout<<"ENTER THE ID- ";
	cin>>w;
	cout<<"SEARCHING";
	for(int kl=0;kl<=7;kl++)
	{
	cout<<" . " ;
	
	}
	fin.open("r.dat",ios::binary);
	while(fin.read((char*)&r,sizeof (r)))
	{
	if(strcmpi(r.retna(),w)==0)
	{
	flag=1;
	cout<<" !!FOUND!!";
	cout<<"Press Enter To See Record";
	getch();
	r.routput();
	getch();
	}
	}
	if(flag==0)
	{
	cout<<"There Is No room With This id";
	cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
	
}
}while(ch!=2);
}
void rmenu(){
int c;
room r;
do
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  PATIENT`ROOM MANAGEMENT SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Add room Info                                 |\n";
cout<<"\t\t\t\t\t\t|             2  >> Display room Info                             |\n";
cout<<"\t\t\t\t\t\t|             3  >> Delete room Info                              |\n";
cout<<"\t\t\t\t\t\t|             4  >> Update room Info                              |\n";
cout<<"\t\t\t\t\t\t|             5  >> Search Particular room Info                   |\n";
cout<<"\t\t\t\t\t\t|             6  >> Exit the Program                              |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>c;
switch(c)
{
case 1:rwrite();break;
case 2:rdisplay();break;
case 3:rdel();break;
case 4:rupdate();break;
case 5:rsearch();break;
case 6:exit(0);break;
}
}while(c!=6);

}


void menu(){
int c;
bill b;
room r;
do
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t BILL AND ROOM MANAGEMENT SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Bill calculation                              |\n";
cout<<"\t\t\t\t\t\t|             2  >> room reservation                              |\n";
cout<<"\t\t\t\t\t\t|             3  >> Exit the Program                              |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>c;
switch(c)
{
case 1:bmenu();break;
case 2:rmenu();break;
case 3:exit(0);break;
}
}while(c!=6);

}

//for lab and operation theater management 
class lab{
char id[10],n[30],i[20],a[20],r[100];
public:
void linput()
{
cout<<"\n id ";
cin>>id;
cout<<"\n NAME of lab or theater-";
cin>>n;
cout<<"\n NAME of incharge- ";
cin>>i;
cout<<"\n ENTER THE AVILABILITY ";
cin>>a;
cout<<"\n REQIREMENTS WITH commas NO SPACES  ";
cin>>r;
}
void loutput()
{
cout<<"\n\t\t\t\t LAB DETAILS \n";
cout<<"\n ID:- "<<id;
cout<<"\n NAME of lab or theater-"<<n;
cout<<"\n INCHARGE:- "<<i;
cout<<"\n AVILABILITY:- "<<a;
cout<<"\n REQURIMENT:- "<<r;

}

char *retna(){
return id;
}
};
void lwrite()
{
cout<<"\n\n\t\t\t\t  LAB DETAIL ADD MENU:-"<<"\n";
lab l;
ofstream fout("l.dat",ios::app|ios::binary);
l.linput();
fout.write((char*)&l,sizeof(lab));
cout<<"\n\n-------------------------------------------------------------------------------";
cout<<"\n press enter to return back";
fout.close();
getch ();
}
void ldisplay()
{
int c=0;
cout<<"\n\n\t\t\t\t !!!! DISPLAY !!!!"<<"\n\n";
lab l;
ifstream fin("l.dat",ios::binary);
while(fin.read((char*)&l,sizeof(l)))
{
c++;
l.loutput();
cout<<"\n\n-------------------------------------------------------------------------------";
}
fin.close();
if (c==0)
{
cout<<"\n\t you may have installed new software"<<"\n\t so you should first add some data to have a display";
}
cout<<"\n Press Enter To Continue..";
getch ();
}
void ldel()
{

char kx;
lab l;
ifstream fin("l.dat",ios::binary);
ofstream fout("k.dat",ios::app|ios::binary);
char m[40];
int flag=0,kshaz=0;
cout<<"LAB DETAIL DELETE MENU";
cout<<"~~~~~~~~~~~~~~~~~~";
cout<<"ENTER ID OF LAB OR THEATER WHOSE RECORD IS TO BE DELETED "<<"\n\n\t\t";
cin>>m;
while(fin.read((char*)&l,sizeof(l)))
{
if(strcmpi(l.retna(),m)==0 )
{
flag=1;
cout<<"\n\t\t\t !!! RECORD FOUND !!! "<<"\n";
l.loutput();
cout<<"\n\n\t\t WANT TO DELETE THIS RECORD ";
cout<<"\n\n\t\t WARNING : ONCE DELETED CANNOT BE RETRIEVED !!!";
cout<<"\n\n PLEASE PROVIDE INPUT (Y OR N)";
cout<<"\n\n\t\t\t\t";
cin>>kx;
if(kx=='y' || kx=='Y')
{
cout<<"\n\n\t DELETING . .";
cout<<"\n\n\t\t !!! DELETED  !!!";
cout<<"\n\n\t PRESS ENTER TO RETURN TO PREVIOUS MENU ";
getch ();
}
else
{
fout.write((char*)&l,sizeof(l));
kshaz++;
}
}
else
{
fout.write((char*)&l,sizeof(l));
}
}
fin.close();
fout.close();
if(flag==0)
{
cout<<"THERE IS NO lab WITH THIS id";
cout<<"PRESS ENTER TO RETURN TO MENU";
getch();
}
if(kshaz==1)
{
cout<<"\n\t\t\t\t !!! NO CHANGES HAVE BEEN MADE";
getch ();
}
remove("l.dat");
rename("k.dat","l.dat");
}
void lupdate()
{
fstream f("l.dat",ios::in|ios::ate|ios::app|ios::binary);
ofstream fout("k.dat",ios::binary);
lab l;
char s[40],flag=0;
cout<<"LAB DETAIL UPDATE MENU";
cout<<"~~~~~~~~~~~~~~~~~~";
cout<<"Enter The ID Of LAB OR TEATER Whose Record Is To Be Updated";
cout<<"\n\t";
cin>>s;
f.seekp(0,ios::beg);
while(f.read((char*)&l,sizeof (l)))
{
if(strcmpi(l.retna(),s)==0)
{
flag=1;
cout<<"\n RECORD FOUND!!";
l.loutput();
cout<<"\n\n\t Press Enter To Add New Informaion";
getch();
cout<<"\n\t\t\t\t NEW INFOMATION";
cout<<"\n\t\t\t\t --------------";
cout<<"\n";
l.linput();
cout<<"\n\t\t Updating....";
cout<<"\n\n\t\t !!UPDATED!!";
cout<<"\n\n press enter to return to menu";
getch();
}
fout.write((char*)&l,sizeof(l));
}
if(flag==0)
{
cout<<"\n\n\t\t\t\t There Is No lab With This id";
cout<<"press enter to return to menu";
getch();
}
f.close();
fout.close();
remove("l.dat");
rename("k.dat","l.dat");
}
void lsearch()
{
char w[40];
lab l;
ifstream fin;
int ch,flag=0;
do
{
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  LAB DETAIL SEARCH SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> SEARCH BY ID                                |\n";
cout<<"\t\t\t\t\t\t|             2  >> RETURN TO PREVIOUS PAGE                       |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>ch;
switch(ch)
{
case 1:
	cout<<"ENTER THE ID- ";
	cin>>w;
	cout<<"SEARCHING";
	for(int kl=0;kl<=7;kl++)
	{
	cout<<" . " ;
	
	}
	fin.open("l.dat",ios::binary);
	while(fin.read((char*)&l,sizeof (l)))
	{
	if(strcmpi(l.retna(),w)==0)
	{
	flag=1;
	cout<<" !!FOUND!!";
	cout<<"Press Enter To See Record";
	getch();
	l.loutput();
	getch();
	}
	}
	if(flag==0)
	{
	cout<<"There Is No lab With This id";
	cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
	
}
}while(ch!=2);
}
void lmenu(){
int c;
lab l;
do
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  PATIENT MANAGEMENT SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Add lab Info                                  |\n";
cout<<"\t\t\t\t\t\t|             2  >> Display lab Info                              |\n";
cout<<"\t\t\t\t\t\t|             3  >> Delete lab Info                               |\n";
cout<<"\t\t\t\t\t\t|             4  >> Update lab Info                               |\n";
cout<<"\t\t\t\t\t\t|             5  >> Search Particular lab Info                    |\n";
cout<<"\t\t\t\t\t\t|             6  >> Exit the Program                              |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>c;
switch(c)
{
case 1:lwrite();break;
case 2:ldisplay();break;
case 3:ldel();break;
case 4:lupdate();break;
case 5:lsearch();break;
case 6:exit(0);break;
}
}while(c!=6);

}

//for patient management
class patient{
char name[30],n[30],g[20],a[20],i[50],r[42],d[50],pdob[20],pdov[20];
public:
void pinput()
{
cout<<"\n NAME OF PATIENT:-\n FIRST NAME- ";
cin>>name;
cout<<"LAST NAME-";
cin>>n;
cout<<"\n ENTER THE GENDER:- ";
cin>>g;
cout<<"\n ENTER THE AGE:- ";
cin>>a;
cout<<"\n ENTER DATE OF BIRTH (DATE/MONTH/YEAR):-  ";
cin>>pdob;
cout<<"\n ENTER THE DISEASE:- ";
cin>>d;
cout<<"\n ENTER THE DATE OF VISIT TO THE HOSPITAL(DATE/MONTH/YEAR):- ";
cin>>pdov;
cout<<"\n ENTER THE PHONE NUMBER :- ";
cin>>i;
cout<<"\n ENTER THE NAME OF DOCTOR IN-CHARGE:- ";
cin>>r;
}
void poutput()
{
cout<<"\n\t\t\t\t PATIENT DETAILS \n";
cout<<"\n NAME OF PATIENT:- "<<name<<n;
cout<<"\n GENDER:- "<<g;
cout<<"\n AGE:- "<<a;
cout<<"\n DATE OF BIRTH (DATE/MONTH/YEAR):- "<<pdob;
cout<<"\n DISEASE:- "<<d;
cout<<"\n DATE OF VISIT TO THE HOSPITAL(DATE/MONTH/YEAR):- "<<pdov;
cout<<"\n PHONE NUMBER:- "<<i;
cout<<"\n DOCTOR IN-CHARGE:- "<<r;
}
char *retpho()
{
return i;
}
char *retna(){
return name;
}
};
void pwrite()
{
cout<<"\n\n\t\t\t\t  PATIENT ADD MENU:-"<<"\n";
patient p;
ofstream fout("p.dat",ios::app|ios::binary);
p.pinput();
fout.write((char*)&p,sizeof(patient));
cout<<"\n\n-------------------------------------------------------------------------------";
cout<<"\n press enter to return back";
fout.close();
getch ();
}
void pdisplay()
{
int c=0;
cout<<"\n\n\t\t\t\t !!!! DISPLAY !!!!"<<"\n\n";
patient p;
ifstream fin("p.dat",ios::binary);
while(fin.read((char*)&p,sizeof(p)))
{
c++;
p.poutput();
cout<<"\n\n-------------------------------------------------------------------------------";
}
fin.close();
if (c==0)
{
cout<<"\n\t you may have installed new software"<<"\n\t so you should first add some data to have a display";
}
cout<<"\n Press Enter To Continue..";
getch ();
}
void pdel()
{

char kx;
patient p;
ifstream fin("p.dat",ios::binary);
ofstream fout("s.dat",ios::app|ios::binary);
char m[40],x[40];
int flag=0,kshaz=0;
cout<<"PATIENT DELETE MENU";
cout<<"~~~~~~~~~~~~~~~~~~";
cout<<"ENTER NAME OF PATIENT WHOSE RECORD IS TO BE DELETED(first name) space (last name) "<<"\n\n\t\t";
cin>>m>>x;
while(fin.read((char*)&p,sizeof(p)))
{
if(strcmpi(p.retna(),m)==0 )
{
flag=1;
cout<<"\n\t\t\t !!! RECORD FOUND !!! "<<"\n";
p.poutput();
cout<<"\n\n\t\t WANT TO DELETE THIS RECORD ";
cout<<"\n\n\t\t WARNING : ONCE DELETED CANNOT BE RETRIEVED !!!";
cout<<"\n\n PLEASE PROVIDE INPUT (Y OR N)";
cout<<"\n\n\t\t\t\t";
cin>>kx;
if(kx=='y' || kx=='Y')
{
cout<<"\n\n\t DELETING . .";
cout<<"\n\n\t\t !!! DELETED  !!!";
cout<<"\n\n\t PRESS ENTER TO RETURN TO PREVIOUS MENU ";
getch ();
}
else
{
fout.write((char*)&p,sizeof(p));
kshaz++;
}
}
else
{
fout.write((char*)&p,sizeof(p));
}
}
fin.close();
fout.close();
if(flag==0)
{
cout<<"THERE IS NO patient WITH THIS NAME";
cout<<"PRESS ENTER TO RETURN TO MENU";
getch();
}
if(kshaz==1)
{
cout<<"\n\t\t\t\t !!! NO CHANGES HAVE BEEN MADE";
getch ();
}
remove("p.dat");
rename("s.dat","p.dat");
}
void pupdate()
{
fstream f("p.dat",ios::in|ios::ate|ios::app|ios::binary);
ofstream fout("t.dat",ios::binary);
patient p;
char s[40],z[40],flag=0;
cout<<"PATIENT UPDATE MENU";
cout<<"~~~~~~~~~~~~~~~~~~";
cout<<"Enter The Name Of Patient Whose Record Is To Be Updated (first name) space (last name) ";
cout<<"\n\t";
cin>>s>>z;
f.seekp(0,ios::beg);
while(f.read((char*)&p,sizeof (p)))
{
if(strcmpi(p.retna(),s)==0)
{
flag=1;
cout<<"\n RECORD FOUND!!";
p.poutput();
cout<<"\n\n\t Press Enter To Add New Informaion";
getch();
cout<<"\n\t\t\t\t NEW INFOMATION";
cout<<"\n\t\t\t\t --------------";
cout<<"\n";
p.pinput();
cout<<"\n\t\t Updating....";
cout<<"\n\n\t\t !!UPDATED!!";
cout<<"\n\n press enter to return to menu";
getch();
}
fout.write((char*)&p,sizeof(p));
}
if(flag==0)
{
cout<<"\n\n\t\t\t\t There Is No Patient With This Name";
cout<<"press enter to return to menu";
getch();
}
f.close();
fout.close();
remove("p.dat");
rename("s.dat","p.dat");
}
void psearch()
{
char w[40],z[40],phone[12];
patient p;
ifstream fin;
int ch,flag=0;
do
{
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  PATIENT SEARCH SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> SEARCH BY NAME                                |\n";
cout<<"\t\t\t\t\t\t|             2  >> SEARCH BY NUMBER                              |\n";
cout<<"\t\t\t\t\t\t|             3  >> RETURN TO PREVIOUS PAGE                       |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>ch;
switch(ch)
{
case 1:
	cout<<"ENTER THE NAME- (first name) space (last name) ";
	cin>>w>>z;
	cout<<"SEARCHING";
	for(int kl=0;kl<=7;kl++)
	{
	cout<<" . " ;
	
	}
	fin.open("p.dat",ios::binary);
	while(fin.read((char*)&p,sizeof (p)))
	{
	if(strcmpi(p.retna(),w)==0)
	{
	flag=1;
	cout<<" !!FOUND!!";
	cout<<"Press Enter To See Record";
	getch();
	p.poutput();
	getch();
	}
	}
	if(flag==0)
	{
	cout<<"There Is No Patient With This Name";
	cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
case 2:
	cout<<"ENTER THE PHONE NUMBER- ";
	cin>>phone;
	cout<<"SEARCHING....";
	
	fin.open("p.dat",ios::binary);
	while(fin.read((char*)&p,sizeof (p)))
	{
	if(strcmpi(p.retpho(),phone)==0)
	{
	flag=1;
	cout<<"FOUND!!";
	cout<<"Press Enter To See Record";
	getch();
	p.poutput();
	getch();
	}
	}
	if(flag==0)
	{
	cout<<"There Is No Patient With This Phone Number";
	cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
}
}while(ch!=3);
}
void pmenu()
{
int c;
patient p;
do
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  PATIENT MANAGEMENT SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Add Patient Info                              |\n";
cout<<"\t\t\t\t\t\t|             2  >> Display Patient Info                          |\n";
cout<<"\t\t\t\t\t\t|             3  >> Delete Patient Info                           |\n";
cout<<"\t\t\t\t\t\t|             4  >> Update Patient Info                           |\n";
cout<<"\t\t\t\t\t\t|             5  >> Search Particular Patient Info                |\n";
cout<<"\t\t\t\t\t\t|             6  >> Exit the Program                              |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>c;
switch(c)
{
case 1:pwrite();break;
case 2:pdisplay();break;
case 3:pdel();break;
case 4:pupdate();break;
case 5:psearch();break;
case 6:exit(0);break;
}
}while(c!=6);

}
//for staff manegement
class staff{
	char name[20],n[20],q[20],s[20],a[50],p[12],dob[20],doj[20];
public:
void input()
{
cout<<"\n NAME OF STAFF MEMBER:- ";
cout<<"first name-";
cin>>name;
cout<<"last name-";
cin>>n;
cout<<"\n ENTER DATE OF BIRTH (DATE/MONTH/YEAR):- ";
cin>>dob;
cout<<"\n ENTER THE PHONE NUMBER:- ";
cin>>p;
cout<<"\n ENTER THE ADDRESS:- ";
cin>>a;
cout<<"\n ENTER THE QUALIFICATION:- ";
cin>>q;
cout<<"\n ENTER THE PROFESSION(IF DR. THEN SPECIALIZATION):- ";
cin>>s;
cout<<"\n ENTER THE DATE OF JOINING THE HOSPITAL(DATE/MONTH/YEAR) :- ";
cin>>doj;
} 
void output()
{
cout<<"\n\t\t\t STAFF DETAILS"<<"\n";
cout<<"\n NAME OF DOCTOR :-"<<name<<n;
cout<<"\n DATE OF BIRTH:- "<<dob;
cout<<"\n PHONE NUMBER:- "<<p;
cout<<"\n ADDRESS:- "<<a;
cout<<"\n QUALIFICATION:- "<<q;
cout<<"\n SPECIALISATION:- "<<s;
cout<<"\n DATE OF JOINING THE HOSPITAL:- "<<doj;
}
char *retph()
{
return p;
}
char *retn()
{
return n;
}
};
void drwrite()
{
cout<<"\n\t\t\t\t STAFF MEMBER ADD MENU:-";
staff d;
ofstream fout("d.dat",ios::app|ios::binary);
d.input();
fout.write((char*)&d,sizeof(staff));
fout.close();
cout<<"\n\n-------------------------------------------------------------------------------";
cout<<"\n press enter to return back";
getch();
}
void drdisplay()
{
int c=0;
cout<<"\n\n\t\t\t\t !!!! DISPLAY !!!!"<<"\n\n";
staff d;
ifstream fin("d.dat",ios::binary);
while(fin.read((char*)&d,sizeof(staff)))
{
c++;
d.output();
cout<<"\n\n-------------------------------------------------------------------------------";
}
fin.close();
if (c==0)
{
cout<<"\n\t you may have installed new software"<<"\n\t so you should first add some data to have a display";
}
cout<<"\n Press Enter To Continue..";
getch ();
}

 void drdel()
{
char k;
staff d;
int ml=0;
ifstream fin("d.dat",ios::app|ios::binary);
ofstream fout("t.dat",ios::app|ios::binary);
char m[40],x[40];
int flag=0;
cout<<"STAFF DELETE MENU";
cout<<"~~~~~~~~~~~~~~~~~~";

cout<<"ENTER NAME OF THE STAFF MEMBER WHOSE0 RECORD IS TO BE DELETED(firstname)space(lastname):- "<<"\n\n\t";
cin>>m>>x;
while(fin.read((char*)&d,sizeof(d)))
{
if(strcmp(d.retn(),m)==0 )
{
cout<<"\n\t\t !!! RECORD FOUND !!!"<<"\n";
flag=1;
d.output();
cout<<"\n\n\t\t WANT TO DELETE THIS RECORD "<<"\n";
cout<<"\n\t\t WARNING: THIS CANT BE UNDONE ";
cout<<"\n\n\t PLEASE PROVIDE INPUT (Y OR N) ";
cin>>k;
if(k=='y' || k=='Y')
{
cout<<"\n\n\t DELETING...";
cout<<"\n\n\t DELETED :D";
cout<<"\n\n\t PRESS ENTER TO RETURN TO PREVOIUS MENU";
getch();
}
else
{
fout.write((char*)&d,sizeof(d));
ml++;
}
}
else
fout.write((char*)&d,sizeof(d));
}
fin.close();
fout.close();
if(flag==0)
{
cout<<"THERE IS NO STAFF MEMBER WITH THIS NAME";
cout<<"PRESS ENTER TO RETURN TO MENU";
getch();
}
if (ml==1)
{
cout<<"\n\n\t\t !!!! NO CHANGES HAVE BEEN MADE !!!!";
getch ();
}
remove("d.dat");
rename("t.dat","d.dat");
}
void drupdate()
{
fstream f("d.dat",ios::in|ios::ate|ios::app|ios::binary);
ofstream fout("k.dat",ios::ate|ios::binary);
staff d;
char s[40],y[40],flag=0;
cout<<"STAFF UPDATE MENU";
cout<<"~~~~~~~~~~~~~~~~~~";
cout<<"Enter The Name Of STAFF MEMBER Whose Record Is To Be Updated(firstname)space(lastname):- ";
cout<<"\n\t";
cin>>s>>y;
f.seekp(0,ios::beg);
while(f.read((char*)&d,sizeof (d)))
{
if(strcmpi(d.retn(),s)==0)
{
flag=1;
cout<<"!!RECORD FOUND!!";

d.output();
cout<<"\n\n\t Press Enter To Add New Informaion";
getch();
cout<<"\n NEW INFOMATION";
cout<<"\n --------------"<<"\n";
d.input();
cout<<"\n\n\t\t Updating....";
cout<<"\n\n\t\t UPDATED!!";
}
fout.write((char*)&d,sizeof(d));
}
if(flag==0)
{
cout<<"There Is No STAFF MEMBER With This Name";
}
f.close();
fout.close();
remove("d.dat");
rename("t.dat","d.dat");
cout<<"\n\n\t\t press enter to return to menu";
getch();
}
void drsearch()
{
char p[40],z[40],phone[12];
staff d;
ifstream fin;
int ch,flag=0;
do
{
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  PATIENT SEARCH SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> SEARCH BY NAME                                |\n";
cout<<"\t\t\t\t\t\t|             2  >> SEARCH BY NUMBER                              |\n";
cout<<"\t\t\t\t\t\t|             3  >> RETURN TO PREVIOUS PAGE                       |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>ch;
switch(ch)
{
case 1:
	cout<<"ENTER THE NAME:- ";
	cin>>p>>z;
	cout<<"SEARCHING....";
	fin.open("d.dat",ios::binary);
	while(fin.read((char*)&d,sizeof (d)))
	{
	if(strcmpi(d.retn(),p)==0)
	{
	flag=1;
	cout<<"FOUND!!";
	cout<<"Press Enter To See Record";
	getch();
	d.output();
	getch();
	}
	}
	if(flag==0)
	{
	cout<<"There Is No staff member With This Name";
	cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
case 2:
	cout<<"ENTER THE PHONE NUMBER:-";
	cin>>phone;
	cout<<"SEARCHING....";
	fin.open("d.dat",ios::binary);
	while(fin.read((char*)&d,sizeof (d)))
	{
	if(strcmpi(d.retph(),phone)==0)
	{
	flag=1;
    cout<<"\n !!FOUND!!";
	cout<<"\n Press Enter To See Record"<<"\n\t\n";
	getch();
	d.output();
	getch();
	}
	}
	if(flag==0)
	{
	cout<<"There Is No Staff member With This Phone Number";
	cout<<"press enter to return to menu";
	getch();
	}
	fin.close();
	break;
}
}while(ch!=3);
}
void drmenu()
{
int c;
staff d;
do
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  STAFF MANAGEMENT SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Add Staff Info                                |\n";
cout<<"\t\t\t\t\t\t|             2  >> Display Staff Info                            |\n";
cout<<"\t\t\t\t\t\t|             3  >> Delete Staff Info                             |\n";
cout<<"\t\t\t\t\t\t|             4  >> Update Staff Info                             |\n";
cout<<"\t\t\t\t\t\t|             5  >> Search Staff Member                           |\n";
cout<<"\t\t\t\t\t\t|             6  >> Exit the Program                              |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>c;
system("cls");
switch(c)
{
case 1:drwrite();break;
case 2:drdisplay();break;
case 3:drdel();break;
case 4:drupdate();break;
case 5:drsearch();break;
case 6:getch();break;
}
}while(c!=6);
}
int main()
{

cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                           HOSPITAL MANAGEMENT SYSTEM                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
system("pause");
system("cls");



int i;
int login();
login();
b:
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> docters appointment module                    |\n";
cout<<"\t\t\t\t\t\t|             2  >> Patient profile and admission module          |\n";
cout<<"\t\t\t\t\t\t|             3  >> bill calculation and room reservation         |\n";
cout<<"\t\t\t\t\t\t|             4  >> labs,wards and Operation theaters             |\n";
cout<<"\t\t\t\t\t\t|             5  >> staff manegement                              |\n";
cout<<"\t\t\t\t\t\t|             6  >> Exit the Program                              |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>i;
if(i>6||i<1){cout<<"\n\n\t\t\t\t\t\tInvalid Choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto a;} //if inputed choice is other than given choice



system("cls");
if(i==1)
{
  amenu();
}
if(i==2)
{
  pmenu();	
   }

if(i==3)
{
  menu();
}
if(i==4)
{
  lmenu();
}
if(i==5){
  drmenu();	
}

if(i==6)
{
system("cls");
int a;
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                            HOSPITAL MANAGEMENT SYSTEM                                 |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
cout<<"\t\t\t\t\t press 0 key to exit and other to return back";cin>>a;
if(a==0){
	exit(0);
} 
else{
	goto b;
}
}



cout<<"\n";
return 0;

}

int login(){
   string pass ="";
   char ch;
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
   cout<<"\t\t\t\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t\t\t\t\t     LOGIN \n";	
   cout<<"\t\t\t\t\t\t\t\t------------------------------\n\n";	
   cout << "\t\t\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted! \n";
      system("PAUSE");
      system ("CLS");
   }else{
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}

