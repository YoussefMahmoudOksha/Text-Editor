// FCAI � Programming 1 � 2022 - Assignment 4
// Program Name: Text Editor .
// Last Modification Date: 5/8/2022
// Author1 and ID and Group: Moaz Alaa Eldin Megahed - 20210587
// Author2 and ID and Group: Mariam Ramadan Abd El-Hameed - 20210381
// Author3 and ID and Group: Youssef Mahmoud Okasha Mahmoud - 20210486

#include <iostream>
#include <fstream>
#include <string>
#include "TextEditor.h"
using namespace std;
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



