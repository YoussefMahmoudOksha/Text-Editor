// FCAI � Programming 1 � 2022 - Assignment 4
// Program Name: Text Editor .
// Last Modification Date: 5/8/2022
// Author1 and ID and Group: Moaz Alaa Eldin Megahed - 20210587
// Author2 and ID and Group: Mariam Ramadan Abd El-Hameed - 20210381
// Author3 and ID and Group: Youssef Mahmoud Okasha Mahmoud - 20210486

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void Add(string name);
void Display(string name);
void Empty(string name);
void Encrypt(string name);
void Decrypt(string name);
int main() {
    int option;
    bool flag= true;
    string To_continue;
    fstream FILE;
    char F_name[81];
    cout<<"Please Enter File name : ";
    cin.getline(F_name,81);
    FILE.open(F_name,ios::in);
    if (!FILE)
    {
        FILE.open(F_name,ios::app);
        cout<<"\n This is a new file. I created it for you \n";
    }
    else
    {
        cout<<"\n This File Already Exists \n";
    }
    while (flag) {
        cout<<"1. Add new text to the end of the file \n"
              "2. Display the content of the file\n"
              "3. Empty the file\n"
              "4. Encrypt the file content \n"
              "5. Decrypt the file content\n"
              "6. Merge another file\n"
              "7. Count the number of words in the file.\n"
              "8. Count the number of characters in the file\n"
              "9. Count the number of lines in the file\n"
              "10. Search for a word in the file\n"
              "11. Count the number of times a word exists in the file\n"
              "12. Turn the file content to upper case.\n"
              "13. Turn the file content to lower case.\n"
              "14. Turn file content to 1st caps (1st char of each word is capital) \n"
              "15. Save\n"
              "16. Exit \n ";
        cout<<" choose an option to apply \n";
        cin>>option;
        switch (option) {
            case 1:
                Add(F_name);
                break;
            case 2:
                Display(F_name);
                break;
            case 3:
                Empty(F_name);
                break;
            case 4:
                Encrypt(F_name);
                break;
            case 5:
                Decrypt(F_name);
                break;
            default:
                cout<<"choose correct number \n";
        }
        cout<<"\n If you want to continue press 'yes' else press 'no' \n";
        cin>>To_continue;
        if(To_continue!="yes")
        {
            flag= false;
        }
    }
    return 0;
}
void Add(string name) {
    string Append;
    ofstream FILE;
    FILE.open(name,ios::app);
    if (FILE.is_open()) {
        cout << "Please Enter your text to append : \n";
        getline(cin >> ws, Append);
        FILE << Append;
    }
    FILE.close();
}
void Display(string name)
{
    string display;
    ifstream FILE;
    FILE.open(name, ios::in);
    if (FILE.is_open()) {
        getline(FILE, display);
        cout << display;
    }
    FILE.close();
}
void Empty(string name)
{
    ofstream FILE;
    FILE.open(name, ios::trunc);
    FILE.close();
}
void Encrypt(string name)
{
    string Encryption;
    string Encrypt;
    fstream FILE;
    FILE.open(name,ios::in);
    if (FILE.is_open()) {
        getline(FILE, Encrypt);
    }
    FILE.close();
    if (!FILE.is_open()) {
        for (int i = 0; i < Encrypt.size(); i++) {
            if (Encrypt[i] == ' ') {
                Encrypt[i] = '!';
                Encryption += Encrypt[i];
            } else if (Encrypt[i] == '.') {
                Encrypt[i] = '/';
                Encryption += Encrypt[i];
            }
            if (islower(Encrypt[i])) {

                int result = int(Encrypt[i]) - 97 + 1;
                if (result < 26) {
                    Encryption += char(result + 97);
                } else {
                    result %= 26;
                    Encryption += char(result + 97);
                }
            } else if (isupper(Encrypt[i])) {
                int result = int(Encrypt[i]) - 65 + 1;
                if (result < 26) {
                    Encryption += char(result + 65);
                } else {
                    result %= 26;
                    Encryption += char(result + 65);
                }
            }
        }
        FILE.open(name,ios::out);
        FILE <<Encryption;
    }
}
void Decrypt(string name)
{
    string Decryption;
    string Decrypt;
    fstream FILE;
    FILE.open(name,ios::in);
    if (FILE.is_open()) {
        getline(FILE, Decrypt);
    }
    FILE.close();
    if(!FILE.is_open()) {
        for (int i = 0; i < Decrypt.size(); i++) {
            if (Decrypt[i] == '!') {
                Decrypt[i] = ' ';
                Decryption += Decrypt[i];

            } else if (Decrypt[i] == '/') {
                Decrypt[i] = '.';
                Decryption += Decrypt[i];

            }
            if (islower(Decrypt[i])) {

                int result = int(Decrypt[i]) - 97 - 1;
                if (result < 26) {
                    Decryption += char(result + 97);
                } else {
                    result %= 26;
                    Decryption += char(result + 97);
                }
            } else if (isupper(Decrypt[i])) {
                int result = int(Decrypt[i]) - 65 - 1;
                if (result < 26) {
                    Decryption += char(result + 65);
                } else {
                    result %= 26;
                    Decryption += char(result + 65);
                }
            }
        }
    }
    FILE.open(name,ios::out);
    FILE<<Decryption;
}



