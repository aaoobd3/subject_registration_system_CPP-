#include <iostream>
#include<string>
#include <fstream>
#include<conio.h>
#include <cstdio>

using namespace std;
struct subject{
string subject_code ;
string subject_name;
int credit_hour;
string day;
int time;
string venue;
struct subject * next;
};

class admin
{
private:
    subject *head,*tail;
public:
    admin()
    {
        head = NULL;
        tail = NULL;
    }

    void add_subjects()
    {
         subject *temp = new subject;
string code = "";
    string name = "";
    string venue = "";
    string day = "";
    int time =0;
    int hour = 0;
    fflush(stdin);
    cout<<"enter code  ";
    getline(cin,temp->subject_code);
cout<<"enter name  ";
getline(cin,temp->subject_name);
    cout<<"enter venue  ";
    getline(cin,temp->venue);
    cout<<"enter day  ";
    getline(cin,temp->day);
cout<<"enter time  ";
    cin>>temp->time;
     cout<<"enter hour  ";
    cin>>temp->credit_hour;

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

    void display()
    {
        subject *tmp ;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->day << endl;
            tmp = tmp->next;
        }
    }

    void save()
{
ofstream listfile;
listfile.open("subjects.txt",ios::out|ios::app |ios::binary) ;
subject *temp;
temp=head;


if(!listfile){
 cout<<"\nError opening file";
 }
 else{
while(temp!=NULL)
{
    listfile<<
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

};

 void menu(admin a){
   int choice =0;
     cout<<"\n\n[1] student \n\n [2] admin\n----> ";
    cin>> choice;
     switch(choice){
 case 1:
    break;
 case 2:
     cout<<"[1] add subject \n\n [2] show all\n----> ";
    cin>> choice;
    switch(choice){
case 1:
     a.add_subjects();
    break;
case 2:
    a.display();
    break;

    }

    break;
     }
     menu(a);
 }

int main()
{
    admin a;


menu(a);



    return 0;
}
