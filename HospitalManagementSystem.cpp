#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct patientdata
{
    int wardno, bedno;
	string first_name;
	string last_name;
	int age;
    long long ID;
	char blood[100];
	char gender;
    patientdata*next;
};
class Hospital
{
	patientdata *head,*last;
	public:
	Hospital() //default constructor
	{
		head=NULL;
		last=NULL;
	}
    patientdata input();
    void insertatend();
    void insertatbeg();
    void getpatientoperate();
    void getpatienttoout();
    void listofpatients();
    int search(int);
    char departmentname[50];
};
int Hospital :: search(int item)
{
	 if(head==NULL)
     return false;
     else
     {
     int flag=0;
     patientdata*p=new patientdata();
     p=head;

     while( p->next!=NULL && p->ID!=item )
     {
        p=p->next;
     }
     if(p->ID==item)
     {
	 	flag=1;
	 	return true;
     }
     if(flag==0)
     return false;
     }
}

int readnumber()
{
   char b[20];
   cin.getline(b, sizeof(b));
   return atoi(b);
}

patientdata Hospital :: input()
{
    int flag=0;
   patientdata *p=new patientdata();
   cout << "\n   Please enter data for patient\n";
   cout<<"\n   First name     : ";
   getline(cin,p->first_name);
   cout << "   Last name      : ";
   getline(cin,p->last_name);
   again :
   cout << "   Blood Group    : ";
   cin>>p->blood;
   if((strcmp(p->blood,"A+")==0)||(strcmp(p->blood,"a+")==0)||(strcmp(p->blood,"A-")==0)||(strcmp(p->blood,"a-")==0)||
      (strcmp(p->blood,"B+")==0)||(strcmp(p->blood,"b+")==0)||(strcmp(p->blood,"B-")==0)||(strcmp(p->blood,"b-")==0)||
      (strcmp(p->blood,"O+")==0)||(strcmp(p->blood,"o+")==0)||(strcmp(p->blood,"O-")==0)||(strcmp(p->blood,"o-")==0)||
      (strcmp(p->blood,"AB+")==0)||(strcmp(p->blood,"ab+")==0)||(strcmp(p->blood,"AB-")==0)||(strcmp(p->blood,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        cout<<"\n   Invalid Blood Group Try Again..\n\n";
        goto again;

    }
   cout<<"   Gender(M/F)         :- ";
   cin>>p->gender;
   cout<<"   Age                 :- ";
   cin>>p->age;
   cout<<"   Mobile number       :- ";
   cin>>p->ID;
   cout<<" Enter the ward number :-";
   cin>>p->wardno;
   cout<<" Enter the bed number  :-";
   cin>>p->bedno;


	if(search(p->ID))
	{
		p->ID=0;
		cout << "\n   Data not valid. Operation cancelled.";
	}
	return *p;
}
void output(patientdata *p)
{
	cout<<"\n  *********************************************************";
	cout<<"\n   Patient data:\n";
	cout<<"\n   First Name         : "<<p->first_name;
	cout<<"\n   Last Name          : "<<p->last_name;
	cout<<"\n   Gender             : "<<p->gender;
	cout<<"\n   Age                : "<<p->age;
	cout<<"\n   Blood Group        : "<<p->blood;
	cout<<"\n   Mobile Number      : "<<p->ID;
    cout<<"\n   ward number      : "<<p->wardno;
	cout<<"\n   Bed number       : "<<p->bedno;
	cout<<"\n\n *********************************************************";
}