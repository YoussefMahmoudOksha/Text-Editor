#include <iostream>
#include <string>
#include "TextEditor.h"

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
