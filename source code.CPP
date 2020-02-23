
    #include<iostream.h>
    #include<graphics.h>
    #include<conio.h>
    #include<dos.h>
    #include<stdlib.h>
    #include<stdio.h>
    #include<ctype.h>
    #include<fstream.h>
    #include<process.h>
    #include<string.h>
    #include<iomanip.h>
    void gra1();
    void gra2();
class bank{char acc[10];
	   char ano[10],gen,genn[10];
	   char name[15],fname[15],mname[15],adr[30];
	   char ac;
	   unsigned long int amt;
	   char pno[10];
	public:
	   bank()
	   {                               //default contructor
	       amt=0;
	   }
	   char*getano(){ return ano; }         //accessor functions
	   char*getname(){return name;}
	   char*getacc(){return acc;}
	   char*getpno(){return pno;}
	   unsigned long int getamt(){return amt;}
	   void getdata();
	   void putdata();
	   void showdata();
	   void modify(char*,char*,unsigned long int,char*);
	   void add();
	   void withdraw();
	   int  check(char*);
	   void magic();
	  }rec,st;         //objects of classes declared
void bank::getdata()       //to get data from user
{       int q;
	ty:
	one:
	cout<<"\n ACCOUNT NO.(5 digit): ";
	cin>>ano;
	if(strlen(ano)!=5)
	{
		cout<<"\t5 digit required!! type again";
		goto one;
	}
	q=rec.check(ano);
	if(q==0)
	{ cout<<"\taccount no. preoccupied";
	goto ty; }
	cout<<"\n NAME : ";
	gets(name);
	again:
	cout<<"\n ACCOUNT TYPE(S:savings,C:current) : ";
	cin>>ac;
	if((ac!='s')&&(ac!='S')&&(ac!='c')&&(ac!='C'))
	{cout<<"\tWRONG OPERATION ;GIVE CORRECT INFO";
	goto again;}
	 if((ac=='s')||(ac=='S'))
	strcpy(acc,"savings");
	else   strcpy(acc,"current");
	again1:
	cout<<"\n GENDER(M:male,F:female) : ";
	cin>>gen;
	if((gen!='m')&&(gen!='M')&&(gen!='F')&&(gen!='f'))
	{cout<<"\tWRONG OPERATION ;GIVE CORRECT INFO";
	goto again1;}
       if((gen=='m')||(gen=='M'))
	strcpy(genn,"Male");
	else strcpy(genn,"Female");
	cout<<"\n PHONE NO. : ";
	cin>>pno;
	cout<<"\n Father's Name :";
	gets(fname);
	cout<<"\n Mother's Name :";
	gets(mname);
	cout<<"\n Address :";
	gets(adr);
	again2:
	cout<<"\n INITIAL DEPOSIT AMOUNT(Minimum Rs.1000) : ";
	cin>>amt;
	if((amt<=1000))
	{cout<<"\tBELOW REQUIRED AMMOUNT.TYPE AGAIN : ";
	goto again2;}
}

void bank::putdata()      //to view details of a particular record
{	cout<<"\n ACCOUNT NO.: "<<ano<<"\n NAME : "<<name
	<<"\n PHONE NO. :"<<pno<<"\n ACCOUNT TYPE : "<<acc
	<<"\n GENDER :"<<genn<<"\n FATHER'S NAME :"<<fname<<"\n MOTHER'S NAME :"<<mname
	<<"\n ADDRESS :"<<adr<<"\n AVAILABLE BALANCE : "<<amt<<"\n\n";
}
void bank::showdata()    //to view all records
{       cout<<"\n"<<ano<<setw(23)<<name
	<<setw(23)<<acc<<setw(23)<<amt;
}
//function to modify record
void bank::modify(char* namee,char* accc,unsigned long int amtt,char*pnoo)
{	strcpy(name,namee);
	strcpy(acc,accc);
	amt=amtt;
	strcpy(pno,pnoo);
}
void bank::add()           // to add amount
{	unsigned long int ammount;
	cout<<"\n\n\n  NAME : "<<name<<"\t\t Current balance : "<<amt;
	cout<<"\n\n\n  Enter ammount to deposit :";
	cin>>ammount;
	amt+=ammount;
	cout<<"\n  Ammount Deposited!! \n  Updated Balance : "<<amt;
}
void bank::withdraw()     //to withdraw amount
{	unsigned long int ammount;
	cout<<"\n\n\n NAME : "<<name<<"\t\t Available balance : "<<amt;
	ac1:
	cout<<"\n\n\n\n Enter ammount to withdraw : ";
	cin>>ammount;
	if(ammount<amt){
	amt-=ammount;
	cout<<"\n Ammount withdrawn!! \n Updated Balance : "<<amt;}
	else {cout<<"\n  ----------Insufficient Fund In Your Account-------";
	cout<<"\n  ----------Again provide withdrawal ammount------------";
	goto ac1;
	}
}


void bank::magic()   //moving arrows
{
	for(int i=1;i<=80;i++)
		{delay(6);gotoxy(i,30);cout<<">";}
	for(i=1;i<=80;i++)
		{delay(6);gotoxy(i,30);cout<<" ";}
}

void pass()        // asks for password in the begining
{ char pass[10],c1;
int i=0;
   while(1)
   {
       clrscr();
	gotoxy(33,7);
	cout<<"ENTER PASSWORD\n";
	gotoxy(30,8);
	cout<<"( type exit to exit )\n\t\t";
	   while(1)
       {
	  c1=getch();
	if(c1==13)               //13 is ascii value of enter key
	 {  pass[i]='\0';
	   break; }
	else if(c1==8)      //8 is ascii of backspace
	{ if(i>0)
		{i--;
		 cout<<"\b \b";  }
	   }

	    else
	    { pass[i]=c1;
	     i++;
	     cout<<"*";

	    }}

	cout<<"\n";
	rec.magic();
	gotoxy(1,10);
	if(strcmpi(pass,"123")==0)
	return;
	else{if(strcmpi(pass,"exit")==0)
		exit(0);
	else { cout<<"\n\t\t\a.........Sorry! Authentication Failed.............."
		   <<"\n\t\t..........Provide Right key next Time.......";
	       getch();
	       exit(0);
		}}
   }
}
int bank::check(char* ano)     //to check if a account no. exists or not
{
	fstream file("banknew.txt",ios::ate|ios::in|ios::out|ios::binary);
	file.seekg(0,ios::beg);
	while(file)
	{       file.read((char*)&st,sizeof(st));
		if(!file.eof())
		if(strcmp(ano,st.ano)==0)
		return 0;
	}
	return 1;
}


//*****************************************************************
//
//                   other class
//*****************************************************************
    class content
    {
    public:
    void start();
    void intro();


    };
    void content::start()
    {  system("cls");
    setbkcolor(DARKGRAY);
    pass();
	 fstream file;
   start:
    file.open("banknew.txt",ios::ate|ios::in|ios::out|ios::binary);

  //variables defination
  char c,account[5],anoo[5],namee[15],accc[10],pnoo[11];
  unsigned long int amtt,n;
  int found=0,cnt=0,ch=0;
	int num,n1;
    char pnum[11],numb[11];
    do
    { system("cls");            int op;
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode,"C:\\TURBOC3\\BGI");
    setcolor(GREEN);
    setbkcolor(YELLOW);
    settextstyle(3,0,3);
    line(30,30,600,30);
    line(30,65,600,65);
    setcolor(9);

    fillellipse(150,108,114,20);
    fillellipse(150,238,114,20);
    fillellipse(145,368,114,20);
    fillellipse(500,108,120,22);
    fillellipse(490,238,114,20);
    fillellipse(490,368,114,20);
    setcolor(RED);
    outtextxy(280,32,"BANKING");
    outtextxy(50,90,"1.OPEN ACCOUNT");
    outtextxy(50,220,"2.MINI STATEMENT");
    outtextxy(50,350,"3.WITHDRAW");
    outtextxy(400,90,"4.UPDATE ACCOUNT");
    outtextxy(400,220,"5.DEPOSIT");
    outtextxy(400,350,"6.EXIT");
    outtextxy(200,400,"Press Any Key..... ");
   outtextxy(50,450,"*Press 0 to view all accounts");
   gotoxy(250,400);   cin>>n;
   for (int i=25; i>=1; i--)
	{     setbkcolor(YELLOW);
		delay(10);
	    gotoxy(1,i) ; clreol() ;
	}
     system("cls");    switch(n)
    {case 1: setbkcolor(BROWN);
		       cout<<"\n Enter details of new account\n";
			rec.getdata();
			cin.get(c);
			file.write((char*)&rec,sizeof(rec));
			file.clear();
			rec.magic();
			cout<<"\n Account added succesfully!!\nPress any key to continue......";
			getch();
			break;
	case 2:        setbkcolor(5);
		      cout<<"\n\n========================= View Account Details Through =========================";
		      cout<<"\n   1.ACCOUNT NUMBER :";
		      cout<<"\n   2.MOBILE NUMBER :";
		      cout<<"\n   3.EXIT :\n   ->";
		      cin>>n1;
		      if(n1>=3)
		      {    if(n1==3)
			  break;
			  else
			   cout<<"\n Choose correct option( Only 1 to 3) ";


		     }
		     else if(n1==1)
		      { system("cls"); setbkcolor(5);
		      cout<<"\n======================================SEARCH====================================\n";
			cout<<"\n Enter account no. : ";
			cin>>account;
			rec.magic();
			gotoxy(1,6);
			file.seekg(0,ios::beg);
			while(file.read((char*)&rec,sizeof(rec)))
			{	if(strcmpi(account,rec.getano())==0)
				{
					found=1;
					rec.putdata();
				}
			}
			file.clear();
			if(found==0)
				cout<<"\n\n\a-----------Record Not Found-------------\n";
			cout<<"\n Press any key to continue.....";
			getch();
			break;
			 }
			else
		   {     system("cls");   setbkcolor(5);
		   cout<<"\n\n\n  Enter Registered Mobile Number :";
		   cin>>numb;
		   rec.magic();
			gotoxy(1,6);
			file.seekg(0,ios::beg);
			while(file.read((char*)&rec,sizeof(rec)))
			{	if(strcmpi(numb,rec.getpno())==0)
				{
					found=1;
					rec.putdata();
				}
			}
			file.clear();
			if(found==0)
				cout<<"\n\n\a-----------Record Not Found-------------\n";
			cout<<"\n Press any key to continue.....";
			getch();

			  }
			break;
       case 3:          setbkcolor(9);
			  cnt=0;
			found=0;
			cout<<"\n================================WITHDRAW AMOUNT=================================\n";
			cout<<"\n\n Enter account no. : ";
			cin>>account;
			rec.magic();
			gotoxy(1,6);
			file.seekg(0,ios::beg);
			while(file.read((char*)&rec,sizeof(rec)))
			{       cnt++;
				if(strcmpi(account,rec.getano())==0)
				{
					found=1;
					system("cls");
					setbkcolor(9);
					rec.withdraw();
					break;
				}
			}
			file.clear();
			if(found==0)
				cout<<"\n\n\a-----------Record Not Found-------------\n";
			else
			{	int location=(cnt-1)*sizeof(rec);
				cin.get(c);
				if(file.eof())
					file.clear();
				file.seekp(location);
				file.write((char*)&rec,sizeof(rec));
				file.flush();
			}
			cout<<"\n Press any key to continue.....";
			getch();
			break;

       case 4:           setbkcolor(DARKGRAY);
			cout<<"\n=============================== UPDATE ACCOUNT =================================\n";
			cout<<"\n\n   1.MODIFY ACCOUNT\n";
			cout<<"   2.CLOSE ACCOUNT\n";
			cout<<"   3.EXIT \n   ->";
			cin>>op;
			system("cls"); setbkcolor(DARKGRAY);
			  if(op>=3)
			   {    if(op==3)
				{getch(); break;}
				else
				cout<<"\n Choose correct option( Only 1 to 3) ";
			   }


			else if(op==2)
			{found=0;
			cout<<"\n======================== CLOSE ACCOUNT ========================\n";
			cout<<"\n Enter account no : ";
			cin>>anoo;
			rec.magic();
			gotoxy(1,6);
			fstream fin;
			fin.open("temp.txt",ios::in|ios::out|ios::binary);
			file.seekg(0,ios::beg);
			while(file.read((char*)&rec,sizeof(rec)))
			{
			 if(!file.eof())
				{
			      if(strcmpi(anoo,rec.getano())==0)
				{
				 rec.putdata();
					cout<<"\n\n\t\t\a sure to close account(y/n): ";
					cin>>c;
					if((c=='n')||(c=='N'))
					fin.write((char*)&rec,sizeof(rec));
					found=1;
				}
				else
				if(strcmpi(anoo,rec.getano())!=0)
				{  fin.write((char*)&rec,sizeof(rec)); }
				}

			} 		if(found!=1)
			cout<<"\n\n\a----------------Account not found----------------\n";
			else
			if((c=='y')||(c=='Y'))
			cout<<"\n\n\n-----------------------Account Closed-----------------------\n";
			if((c=='n')||(c=='N'))
			cout<<"\n\n-------------------Account is not closed-------------------\n";
			file.close();
			fin.close();
			remove("banknew.txt");
			rename("temp.txt","banknew.txt");
			cout<<"\n  Press any key to continue.....";
			getch();
			file.open("banknew.txt",ios::ate|ios::in|ios::out|ios::binary);
			break; }
			else if(op==1){cout<<"\n========================================= MODIFY ===============================\n";
			cout<<"\n\n Enter account no. : ";
			cin>>account;
			rec.magic();
			gotoxy(1,6);
			file.seekg(0,ios::beg);
			found=0;
			cnt=0;
			while(file.read((char*)&rec,sizeof(rec)))
			{       cnt++;
				if(strcmpi(account,rec.getano())==0)
				{
					found=1;
					break;
				}
			}
			file.clear();
			if(found!=1)
			{
				cout<<"\n\n\a-----------Record Not Found-------------\n"; }
			else
			{	int location=(cnt-1)*sizeof(rec);
				cin.get(c);
				if(file.eof())
					file.clear();
				system("cls"); setbkcolor(DARKGRAY);
				cout<<"\n************* PLEASE ENTER '0' FOR NO CHANGE *************";
				cout<<"\n\n ACCOUNT NO. : ";
				cout<<rec.getano();
				cout<<"\n Enter new name : ";
				gets(namee);
				if(strcmpi(namee,"0")==0)
				strcpy(namee,rec.getname());
				cout<<"\n Enter new phone no. : ";
				cin>>pnoo;
				if(strcmp(pnoo,"0")==0)
				strcpy(pnoo,rec.getpno());
				again:
				cout<<"\n Account type(S:savings,C:current) ";
				cin>>c;
				if(c=='0')
				strcpy(accc,rec.getacc());
				if((c!='s')&&(c!='S')&&(c!='c')&&(c!='C')&&(c!='0'))
				{cout<<"\tWRONG OPERATION ;GIVE CORRECT INFORMATION";
				goto again;}
				 if(c=='s'||c=='S') strcpy(accc,"savings");
				 else
					 if(c=='c'||c=='C')
					 strcpy(accc,"current");
					 else
					 strcpy(accc,rec.getacc());
				cout<<"\n Enter new ammount :";
				cin>>amtt;
				if(amtt==0)
				amtt=rec.getamt();
				file.seekp(location);
				rec.modify(namee,accc,amtt,pnoo);
				file.write((char*)&rec,sizeof(rec));
				file.flush();
			}
			if(found==1)
			cout<<"\n\n\n  Account edited!!";
			cout<<"\n  Press any key to continue.....";
			getch();
			break; }
  case 5:               setbkcolor(9);
			cnt=0;
			cout<<"\n=============================== DEPOSIT MONEY ==================================\n";
			cout<<"\n\n\n Enter account no. :";
			cin>>account;
			rec.magic();
			gotoxy(1,6);
			file.seekg(0,ios::beg);
			while(file.read((char*)&rec,sizeof(rec)))
			{       cnt++;
				if(strcmpi(account,rec.getano())==0)
				{
					found=1;
					system("cls"); setbkcolor(9);
					rec.add();
					break;
				}
			}
			file.clear();
			if(found==0)
				cout<<"\n\n\n\a----------- Record Not Found -------------\n";
			else
			{	int location=(cnt-1)*sizeof(rec);
				cin.get(c);
				if(file.eof())
					file.clear();
				file.seekp(location);

				file.write((char*)&rec,sizeof(rec));
				file.flush();
			}
			cout<<"\n  Press any key to continue.....";
			getch();
			break;
     case 6:
		     setbkcolor(RED);
		    file.close();

			cout<<"\n\n\n     I readily acknowledge my"
			    <<"\n     indebtedness to my Mentor"
			    <<"\n     Ms. Neelam Goel"
			    <<"\n     for her support"
			    <<"\n     dedication and honest efforts"
			    <<"\n     that has given us"
			    <<"\n     immense help in"
			    <<"\n     completing this project.";
			 textbackground(LIGHTBLUE);
		       textcolor(WHITE+BLINK);
		 cprintf("\n---------- CREDITS ----------- ");cout<<endl;
		 cprintf("\n  1.ABHISHEK KUMAR"); cout<<endl;
		 cprintf("\n  2.ABHISHEK DAYAL\n");cout<<endl;
		 cprintf("  3.ANAND KUMAR\n");  cout<<endl;
		 cprintf("  4.VISHU CHHABRA\n");


			cout<<"\n\n Press any key to exit.....";
			getch();
			exit(0);
   case 0:           setbkcolor(BLUE);
		       cout<<"\n============================VIEWING ALL THE ACCOUNTS============================";
			cout<<"________________________________________________________________________________";
			gotoxy(25,2);
			cout<<"\nACC. no."<<setw(18)<<"NAME"<<setw(23)
			    <<"ACC.TYPE"<<setw(23)<<"BALANCE";
			cout<<"\n================================================================================\n";
			file.seekg(0,ios::beg);
			while(file)
			{ file.read((char*)&rec,sizeof(rec));
			  if(!file.eof())
			  rec.showdata();
			}
			cout<<"\nPress any key to continue......";
			file.clear();
			getch();
			break;


		 default :

	      textcolor(RED+BLINK);
		 cprintf("\n\n\n\n\n\n            Please Press 1 to 6 Only....");
			  }
		cin.ignore();
		cin.get();
	}while(n!=6);

   }   //********************************************************
	//             MAIN START
     //********************************************************

void main(){
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode,"C:\\TURBOC3\\BGI");
gra1();
gra2();
content c;
c.intro();
c.start();
getch();
closegraph();
    }


void content::intro()
    {	clrscr() ;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setcolor(WHITE);
	settextstyle(1,0,2);
	outtextxy(150,30,"WELCOME TO INTEGRATED BANKING") ;
	line(40,55,550,55);
	    rectangle(34,138,600,300);

       outtextxy(40,70,"IN  THIS  PROJECT YOU CAN  KEEP  RECORD OF DAILY ");
       outtextxy(40,100,	"BANKING  TRANSACTIONS. 	     ") ;
	outtextxy(40,140,"Following functions of the system : ");
	outtextxy(40,160,"1.For creation of new account");
	outtextxy(40,180,"2.To view all transaction related to account") ;
	outtextxy(40,200,"3.Through third option you can withdraw amount") ;
	outtextxy(40,220,"4.To modify or delete an account use fourth option" );
	outtextxy(40,240,"5.In Fifth option you can deposit amount" );
	outtextxy(40,260,"6.This is the last option i.e., Quit (Exit to Dos).  ") ;
	setbkcolor(RED);
	settextstyle(8,0,2);
	outtextxy(100,400,"Press Key To Continue....");
	getch() ;
	for (int i=25; i>=1; i--)
	{
		delay(20) ;
		gotoxy(1,i) ; clreol() ;
	}
}


void gra1()		//Function definition #1
	{
	clrscr();
	int gd=DETECT,gm;
initgraph(&gd,&gm,"C://TURBOC3//BGI");
cleardevice();
setcolor(4);
line(165,125,350,90); line(350,90,450,160);line(450,160,420,350);
line(420,350,230,380);line(230,380,190,275);line(190,275,165,125);
setfillstyle(1,4); floodfill(166,126,4);
setcolor(15);           setfillstyle(1,15);
line(195,140,340,112); line(340,112,415,162); line(415,162,360,172);
line(360,172,318,140); line(318,140,205,164); line(205,164,195,140);
floodfill(196,141,15);
line(215,214,318,190); line(360,225,318,190); line(360,225,310,239);
line(310,239,295,224); line(295,224,225,240); line(225,240,215,214);
floodfill(216,215,15);
line(295,274,235,290); line(295,274,310,289);
line(310,289,245,308); line(245,308,235,290);
 floodfill(246,307,15);

	 settextstyle(10,0,2);
	 setcolor(5);
	outtextxy(65,40,"CHANDIGARH COOPERATIVE BANK");

	setcolor(15);
	line (320-150,420-13,320+150,420-13);
	line (320-150,420+12,320+150,420+12);
	line (320-150,420-13,320-150,420+12);
	line (320+150,420+12,320+150,420-13);
	int s=6,w;
  for (int
	x1=171,x2=171,y1=408,y2=431,y=1,S=0;x1<470;x1++,x2++,y++,S++)
		{
		settextstyle(8,0,2);
		setcolor(BLUE);
		line (x1,y1,x2,y2);
		w=(x1-169)/3;
		for (int i=34; i<=78; i++)
		{
			gotoxy(i,23) ;
			cout <<" " ;
		}
		setcolor(15);
		outtextxy(310,440,"LOADING....");
		if (x2>270) s=2; if (x2>370) s=2;
		if (x2==320) delay(2); else
		delay(s);
		}
		delay(2);
		for (int i=27; i<=78; i++)
		{
			gotoxy(i,23) ;
			cout <<" " ;
		}
	settextstyle(2,0,5);
	outtextxy(435,460,"PRESS ANY KEY TO CONTINUE.... ");
	getch(); }
	void gra2()        //Function definition *2
	{    clrscr();        //To make a designer ellipse
	int gd=DETECT,gm;
	initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");
	setcolor(8);
	ellipse(320,240,0,360,300,150);
	settextstyle(10,0,2);
	settextjustify(1,1);
	setcolor(5);
	outtextxy(320,170,"BANKING MANAGEMENT SYSTEM");
	delay(250);
	settextstyle(4,0,4);
	setcolor(20);
	outtextxy(320,220,"Presented By:");
	delay(250);
	setcolor(9);
	settextstyle(10,0,4);
	outtextxy(320,315,"ARYA , DAYAL");
	setcolor(2);
	delay(250);
	outtextxy(320,265,"ANAND , VISHU");
	for (int stangle=0;!kbhit();stangle++)
	{
		setcolor(7);
		ellipse(320,240,stangle,stangle+20,300,160);
		ellipse(320,240,stangle+180,stangle+200,300,160);
		delay(9);
		setcolor(8);
		ellipse(320,240,stangle-1,stangle+19,300,160);
		ellipse(320,240,stangle-1+180,stangle+199,300,160);
	}
	closegraph();
	getch();}