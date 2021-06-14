#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Tele
{

public:
    string num;
    string name;
    Tele *next;
};

Tele *read()
{
    ifstream file;
    string word;

    int flag = 0;

    Tele *temp = new Tele;

    temp = NULL;

    file.open("Text.txt");

    if (file.fail())
    {
        return temp;
    }

    else
    {
        Tele *Head = new Tele();

        temp = Head;

        while (file >> word)
        {
            Tele *new_node = new Tele();

            temp->next = new_node;
            temp = new_node;

            new_node->name = word;

            file >> word;
            new_node->num = word;
        }

        file.close();
        return Head->next;
    }
}

void write(Tele *Head)
{
    ofstream File;

    File.open("Text.txt", ofstream::trunc);

    Tele *node = new Tele;

    node = Head->next;

    while (node != NULL)
    {
        File << node->name;
        File << " ";
        File << node->num;
        File << " ";

        node = node->next;
    }

    File.close();
}

int main()
{

    Tele *Head = new Tele();

    Head->next = read();

    char ch = 'y';

    int choice = 0;
    string name;
    string number;
    cout << "\t\t\t\tCONTACTS";

    Head->name = "DEVELOPER";
    Head->num = "8897694097";
    while (ch == 'y')
    {
        cout << "\n\n Choose one of the following functions to perform on the contacts : \n1.ADD A CONTACT\n2.DELETE A CONTACT\n3.SHOW CONTACTS\n4.SEARCH A CONTACT\n5.MODIFY A CONTACT\n6.EXIT\n>Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            cout << "\nEnter the contact name : ";
            cin >> name;
            cout << "\nEnter the number of the contact : ";
            cin >> number;

            Tele *Temp = Head;

            while (Temp->next != NULL)
            {
                Temp = Temp->next;
            }

            Tele *new_node = new Tele();

            new_node->name = name;
            new_node->num = number;

            Temp->next = new_node;
            new_node->next = NULL;

            break;
        }

        case 2:
        {
            cout << "\nEnter the contact name to delete the contact : ";
            cin >> name;

            if (Head == NULL)
            {
                cout << "\nERROR!! NO CONTACTS TO DELETE !!\n";
            }

            else
            {
                Tele *Temp = Head;
                Tele *Temp2 = Temp;
                while (Temp != NULL)
                {
                    Temp2 = Temp->next;

                    if (Temp2->name == name)
                    {
                        break;
                    }

                    else
                    {
                        Temp = Temp->next;
                    }
                }

                if (Temp == NULL)
                {
                    cout << "\n The Contact Doesn't Exist !!!!!";
                }

                else
                {
                    Temp->next = Temp2->next;

                    cout << "\n CONTACT DELETED !!!";
                }
            }

            break;
        }

        case 3:
        {

            Tele *Temp = Head->next;
            int j = 1;
            cout << "\n\t\tCONTACTS : \n";

            if (Temp == NULL)
            {
                cout << "\n NO CONTACTS TO DISPLAY\n";
            }

            else
            {

                while (Temp != NULL)
                {
                    cout << setw(12) << "\n"
                         << j << ". Name : " << Temp->name;
                    cout << setw(12) << "\tNumber : " << Temp->num;
                    j++;

                    Temp = Temp->next;
                }
            }

            break;
        }
        case 4:
        {

            int ans;
            cout << "Do you want to search with :\n1.Name\n2.Number\n>";
            cin >> ans;

            Tele *Temp = Head;

            if (ans == 1)
            {
                cout << "\nEnter the name you want to search : ";
                cin >> name;

                while (Temp != NULL)
                {
                    if (Temp->name == name)
                    {
                        break;
                    }

                    else
                    {
                        Temp = Temp->next;
                    }
                }

                if (Temp == NULL)
                {
                    cout << "\nCONTACT NOT FOUND\n";
                }

                else
                {
                    cout << "\nContact found";
                    cout << "\nContact Name : " << Temp->name << "\tNumber : " << Temp->num;
                }
            }

            else
            {

                cout << "\nEnter the number you want to search : ";
                cin >> number;

                while (Temp != NULL)
                {
                    if (Temp->num == number)
                    {
                        break;
                    }

                    else
                    {
                        Temp = Temp->next;
                    }
                }

                if (Temp == NULL)
                {
                    cout << "\nCONTACT NOT FOUND\n";
                }

                else
                {
                    cout << "\nContact found";
                    cout << "\nContact Name : " << Temp->name << "\tNumber : " << Temp->num;
                }
            }

            break;
        }
        case 5:
        {

            int x;
            char ans = 'y';
            cout << "\nEnter the contact name to modify : ";
            cin >> name;

            Tele *Temp = Head;

            while (Temp != NULL)
            {
                if (Temp->name == name)
                {
                    break;
                }

                else
                {
                    Temp = Temp->next;
                }
            }

            if (Temp == NULL)
            {
                cout << "\nContact doesn't exist\n";
                break;
            }

            while (ans == 'y' || ans == 'Y')
            {
                cout << "\nChoose what to modify : \n 1.Name \n 2.Contact\n>";
                cin >> x;
                if (x == 1)
                {
                    cout << "\nName :" << Temp->name << "\tNumber :" << Temp->num;
                    cout << "\n Enter the modified name : ";
                    cin >> name;

                    cout << "\n Modified Name : " << Temp->name << " to " << name;

                    Temp->name = name;
                }

                else
                {
                    cout << "\n Name :" << Temp->name << "\tNumber :" << Temp->num;
                    cout << "\n Enter the modified number : ";
                    cin >> number;

                    cout << "\n Modified Number : " << Temp->num << " to " << number;

                    Temp->num = number;
                }

                cout << "\nDo you want to modify more ? (y/n)";
                cin >> ans;
            }

            break;
        }

        case 6:
        {
            cout << "\n\t\t EXITING ......\n";

            write(Head);

            return 0;
        }

        default:
            cout << "\n\nWrong Option Selected !!!!!";
            break;
        }

        cout << "\n\nDo you wish to continue ? (y/n) : ";
        cin >> ch;
    }

    write(Head);

    return 0;
}
