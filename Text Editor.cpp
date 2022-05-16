// FCAI � Programming 1 � 2022 - Assignment 4
// Program Name: Text Editor .
// Last Modification Date: 5/8/2022
// Author1 and ID and Group: Moaz Alaa Eldin Megahed - 20210587
// Author2 and ID and Group: Mariam Ramadan Abd El-Hameed - 20210381
// Author3 and ID and Group: Youssef Mahmoud Okasha Mahmoud - 20210486

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>
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

void Merge(string F_name)
{
    string Append;
    ofstream FILE;
    ifstream M_FILE;
    char M_name[81] ;
    FILE.open(F_name,ios::app); //loding a new file to marge it
    cout<<"Please Enter M_File name : ";
    cin.getline(M_name,81);
    M_FILE.open(M_name);

    if (!M_FILE)
    {
        cout<<"\n Invalid File Name \n";
    }
    else
    {
        cout<<"\n This File Already Exists \n";
    }

    while (getline(M_FILE, Append))
    {
        FILE << Append;
    }

    M_FILE.close();
    FILE.close();
}

// Count the number of words in the file function.

void number_of_words(string F_name)
{
    ifstream FILE;
    FILE.open(F_name);
    char ch;
    int word =1;
    FILE.seekg(0,ios::beg);

    while(FILE)
    {
        FILE.get(ch);
        if(ch == ' ')
        {
           word++;
        }
        else if (ch == '\n')
        {
            word++;
        }

    }

    cout<< "The number of word  in the file: "<< word <<"\n";

    FILE.close();
}

// Count the number of characters in the file function.

void number_of_characters(string F_name)
{
    ifstream FILE;
    FILE.open(F_name);
    char ch;
    int characters = 0;

    FILE.seekg(0,ios::beg);
    while(FILE)
    {
        FILE.get(ch);
        if(ch == ' ' || ch == '\n')
        {
            characters += 0;
        }
        else
        {
            characters++;
        }

    }
    cout << "The number of characters  in the file: " << characters << "\n";

    FILE.close();
}

// Count the number of lines in the file function.

void number_of_lines(string F_name)
{
    ifstream FILE;
    FILE.open(F_name);
    int lines = 0 ;
    string curr;

    while(getline(FILE, curr))
    {
       for(int i = 0;i<curr.size();i++)
       {
           if(curr[i] =='.' || curr[i] =='?' || curr[i] =='!' || curr[i] =='\n')
           {
               lines++;
           }
       }

    }

    cout << "The number of lines in the file: " << lines << "\n";
    FILE.close();
}

// Search for a word in the file function.

void Search_for_a_word(string F_name)
{

    ifstream FILE;
    FILE.open(F_name);
    string str;
    string curr = "";
    bool isFound=0;

    cout << "Enter the word that you Searching on it: /n" ;
    getline(cin, str);
    transform(str.begin(), str.end(), str.begin(), ::toupper);
 //Convert the input and the file to the same size so that the comparison equation can be found if the required word is found
    while(getline(FILE, curr))
    {
        transform(curr.begin(), curr.end(), curr.begin(), ::toupper);
        if (curr.find(str) != string::npos)
        {
            cout << "word was found" << endl;
            isFound = 0;
            break;
        }
        else
        {
            isFound = 1;
        }
    }

    while(isFound)
    {
        cout << "word was not found" << endl;
        isFound = 0;
    }
    FILE.close();
}
   

