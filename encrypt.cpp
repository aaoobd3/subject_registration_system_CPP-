#include <bits/stdc++.h>
#include <string>

using namespace std;

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





int main()


    {
        string id ;
        string password;
        string line;
ofstream listfile;
ifstream inFile;

inFile.open("password_database.csv");
           listfile.open("encrypted.csv",ios::out|ios::trunc) ;

    if (!inFile) {
        cout << "Unable to open file";
    }
    else{
    while (getline(inFile,line)) {

           stringstream ss(line);
           getline(ss,id,',');
           getline(ss,password);

           password = encrypt(password);

           listfile<<id<<","<<password<<"\n";




}}}

//Encrypt the text


//Decrypt the text
