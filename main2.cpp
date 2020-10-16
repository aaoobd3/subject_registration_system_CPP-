#include <iostream>
#include<string>
#include <fstream>
#include<conio.h>
#include <cstdio>
#include<iomanip>
#include<sstream>
#include <istream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
const int NO_STUDENTS = 100;

using namespace std;
struct subject{
string subject_code ;
string subject_name;
int credit_hour;
string day;
int day_n;
int time[2];
string venue;
struct subject * next;
};
class validate {
    struct idpass{
    string id;
    string password;
    struct idpass * next;
    }a[NO_STUDENTS];
    public:
validate(){
ifstream inFile;
int i =0;
string line;
inFile.open("encrypted.csv");
    while (getline(inFile,line)) {

           stringstream ss(line);
           getline(ss,a[i].id,',');
           getline(ss,a[i].password);
           i++;

}}




string encrypt(string message)

        {
            char ch;
        int i;
      int  key =4;
   for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];

		if(ch >= '0' && ch <= '9' ){
			ch = ch + key;

			if(ch > '9'){
				ch = ch - '9' + '0' - 1;
			}

			message[i] = ch;
		}

        }
        return message;
        }
 bool check(string id,string pass){
     int i ;
     string newpass = encrypt(pass);

 for (i=0;i<NO_STUDENTS;i++)
    if (a[i].id==id && a[i].password ==newpass )
    return true;

 return false;
 }
};














    subject *head = NULL ;
    subject *tail =NULL;


class subjects
{

public:

 void update (){
    ifstream inFile;
    map<string, int> daysmap;
daysmap["mon"] = 0;
daysmap["tue"] = 1;
daysmap["wed"] = 2;
daysmap["thu"] = 3;
daysmap["fri"] = 4;
    string line;
    string code = "";
    string name = "";
    string venue = "";
    string day = "";
    string str_time_s ;
    string str_time_e ;

    string str_hour ;
    int hour;



    inFile.open("subjects.csv");
    if (!inFile) {
        cout << "Unable to open file";
    }
    else{
    while (getline(inFile,line)) {
            cout<<endl<<line<<endl;
           stringstream ss(line);
           getline(ss,code,',');
           getline(ss,name,',');
           getline(ss,str_hour,',');
           getline(ss,day,',');
           getline(ss,str_time_s,',');
           getline(ss,str_time_e,',');
           getline(ss,venue);

           add_subjects(code ,name,venue,day ,daysmap[day],stoi(str_time_s), stoi(str_time_e),stoi(str_hour));

    }

    inFile.close();
    }}

      void display()
    {

subject *tmp = new subject;
tmp = head;
int mm = 1;
        while (tmp != NULL)
        {
cout<<"["<<mm++<<"]"<<"code : "<<tmp->subject_code<<"\n"<<"name : "<<tmp->subject_name<<"\n"<<"credit : "<<tmp->credit_hour<<"\n"<<"time: "<<tmp->time[0]<<"----->"<<tmp->time[1]<<"\n"<<"day: "<<tmp->day<<"   "<<tmp->day_n<<"\n"<<"venue : "<<tmp->venue<<"\n____________________________________________\n";
            tmp = tmp->next;
        }
    }

    void save()
{
ofstream listfile;
listfile.open("subjects.csv",ios::out|ios::trunc) ;
subject *temp;
temp=head;


if(!listfile){
 cout<<"\nError opening file";
 }
 else{
while(temp!=NULL)
{
    listfile<<temp->subject_code<<","<<
        temp->subject_name<<","<<
        temp->credit_hour <<","<<
        temp->day<<","<<
        temp->time[0] <<","<<
        temp->time[1] <<","<<

        temp->venue <<"\n";
        temp = temp->next;
}
}
listfile.close();
cout<<"\n\n\n\t\tLink list has been saved in file example.txt in current folder.";
cout<<"\n\n\t\tPress a key to continue ... ";
getch();
}


    void add_subjects(string code ,string name, string venue,string day ,int dayn,int time_s,int time_e ,int hour)
    {
subject *temp = new subject;
temp->subject_code = code;
temp->subject_name = name;
temp->venue = venue;
temp->day = day;
temp->day_n = dayn;
temp->time[0]  = time_s;
temp->time[1]  = time_e;

temp->credit_hour = hour;
temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {tail->next = temp;
        tail = tail->next;
        }


    }







};
class admin{
    public:
    void add(subjects a){
    map<string, int> daysmap;
daysmap.insert(make_pair("mon",0));
daysmap.insert(make_pair("tue",1));
daysmap.insert(make_pair("wed",2));
daysmap.insert(make_pair("thu",3));
daysmap.insert(make_pair("fri",4));


 subject *temp = new subject;
string code = "";
    string name = "";
    string venue = "";
    string day = "";
    int time_s =0;
    int time_e =0;

    int hour = 0;
    fflush(stdin);
    cout<<"enter code  ";
    getline(cin,code);
cout<<"enter name  ";
getline(cin,name);
    cout<<"enter venue  ";
    getline(cin,venue);
    cout<<"enter day  ";
    getline(cin,day);
        transform(day.begin(), day.end(),day.begin(), ::tolower);
        day = day.substr(0,3);

cout<<"enter time  ";
    cin>>time_s;
    cout<<"--->";
    cin>>time_e;

     cout<<"enter hour  ";
    cin>>hour;
    a.add_subjects(code ,name,venue,day ,daysmap.at(day), time_s,time_e ,hour);


    }



};

class student{
private:
    string id ;
    string pass;
    int hours = 0 ;
     string table[15][5];

public:


validate v;
bool password(){
     cout << "enter id:";
    cin>>id;
    cout << "enter password:";
    cin>>pass;
   return( v.check(id,pass));


}
subject * choose_sub(int n){
    int i;
    subject * temp = head;
    int len;
    while (temp !=NULL)
    {
        temp  = temp->next;
        len++;

    }
    temp = head;
    if (len<n)
        return NULL;

    for (i=0 ;i<n-1;i++){
            temp = temp->next;


    }

    return temp;
    }


int add_sub(subjects a)
{
    int n ;
    int ch;
    a.display();
    cout << "choose subject form the list to add :";
    cin >>n;
    subject * temp = choose_sub(n);
    int i;
    int j;
    int flag= 0;
 for (j=0;j<((temp->time[1]/100-8)-(temp->time[0]/100-8));j++){
              if(table[temp->time[0]/100-8+j][temp->day_n]=="")
                    flag  = 1;
            }

    if (flag ==1 && table[temp->time[0]/100-8][temp->day_n]== "" &&hours + temp->credit_hour<=20)
    {
        table[temp->time[0]/100-8][temp->day_n] = temp->subject_code;
        for (i=1;i<((temp->time[1]/100-8)-(temp->time[0]/100-8));i++)
         table[temp->time[0]/100-8+i][temp->day_n]  = "########";
         if (hours + temp->credit_hour<10){
         hours = hours + temp->credit_hour;
cout << "\n\n you need to add more subjects your current credit is "<<hours<<endl;
print_table();
getch();
        add_sub(a);}
    else if (hours + temp->credit_hour>10 &&hours + temp->credit_hour<20){
            print_table();
         hours = hours + temp->credit_hour;

        cout<<" your current credit is "<<hours<<"  do you want to add more subjects [1]yes [0]no \n\n----->";
        cin>>ch ;
        if (ch)
            add_sub(a);
        else
            return 0 ;
    }
    else if (hours + temp->credit_hour==20){
                 hours = hours + temp->credit_hour;

        print_table();

        cout<< "\n\n you reached 20 credit hour\n\n";
    getch();}
    return 0;



    }
    cout<< "\nchoose another subject\n";
    add_sub(a);
    }

    void print_table(){
                int i,k;

        ofstream tableout;
        tableout.open (id+".txt",ios::trunc);
        cout <<"   mon      tue      wed      thu      fri      \n";
                tableout<<"   mon      tue      wed      thu      fri      \n";

    for (i = 0 ; i<15;i++){
        printf("%2d ",i+8);
tableout.width(2);
        tableout <<(i+8);
        for (k = 0 ; k<5;k++){
            if (table[i][k]!=""){
        cout <<table[i][k]<<" ";
        tableout << table[i][k]<<" ";}

        else{

        cout<<"         ";
        tableout<<"         ";}

        }


   cout <<endl<<endl;
      tableout<<endl<<endl;

   }
    }







};



int main()
{int m = 1;
subjects a;
a.update();
admin admin1;
while(m){
int choice =0;
     cout<<"\n\n[1] student \n\n [2] admin\n----> ";
    cin>> choice;
     switch(choice){
 case 1:{
     student s;
    if( s.password()){
        system("cls");
        cout <<"\n --------------------------welcome------------------------------- \n";
        s.add_sub(a);
        cout <<"table";
        s.print_table();}
        else{
                    cout <<"\n id or password is wrong try again \n";
                    getch();}

    break;
 }
 case 2:

     cout<<"[1] add subject \n\n [2] show all\n----> ";
    cin>> choice;
    switch(choice){
case 1:
     admin1.add(a);
     a.save();

    break;
case 2:
    a.display();
    break;

    }

    break;
     }
cout<<"\n\n\n cont????";
cin>>m;


}
a.save();
return 0 ;}
