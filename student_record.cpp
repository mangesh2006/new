#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include <windows.h>
using namespace std;

class student_info
{
private:
    string name, mobileno, email, course, semester;
    long int rollno;

public:
    void menu();
    void getdata();
    void display();
    void search();
    void del();
    void update();
};

bool isValidEmail(string email)
{
    return (email.find('@') != string::npos && email.find('.') != string::npos);
}

void student_info::menu()
{
    char ch;
    do
    {
        system("cls");
        cout << "1. Enter Student Data" << endl;
        cout << "2. Display Student Data" << endl;
        cout << "3. Search Student Data" << endl;
        cout << "4. Update Student Data" << endl;
        cout << "5. Delete Student Data" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            getdata();
            break;
        case '2':
            display();
            break;
        case '3':
            search();
            break;
        case '4':
            update();
            break;
        case '5':
            del();
            break;
        case '6':
            exit(0);
        }
    } while (1);
    getch();
}

void student_info::getdata()
{
    fstream file;
    system("cls");
    cout << "Enter Student Roll No.: ";
    cin >> rollno;
    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter Student Mobile No.: ";
    cin >> mobileno;
    cout << "Enter Student Email-Id: ";
    cin >> email;
    cout << "Validating Email....." << endl;
    Sleep(1000);

    if (isValidEmail(email))
    {
        cout << "Email is Valid" << endl;
        cout << "Enter Student Course: ";
        cin >> course;
        cout << "Enter Student Semester: ";
        cin >> semester;

        file.open("student_record.txt", ios::app | ios::out);

        if (!file)
        {
            cout << "File Not Found" << endl;
        }
        else
        {
            file << "Roll No.: " << rollno << endl;
            file << "Name: " << name << endl;
            file << "Mobile No.: " << mobileno << endl;
            file << "Email: " << email << endl;
            file << "Course: " << course << endl;
            file << "Semester: " << semester << endl
                 << endl;
        }
    }
    else
    {
        cout << "Invalid Email Address" << endl;
    }

    getch();
}

void student_info::display()
{
    system("cls");
    fstream file;
    file.open("student_record.txt", ios::in);
    string line;

    if (!file)
    {
        cout << "File Not Found" << endl;
    }
    else
    {
        while (!file.eof())
        {
            getline(file, line);
            cout << line << endl;
        }
    }
    getch();
}

void student_info::search()
{
    system("cls");
    fstream file;
    file.open("student_record.txt", ios::in);
    string line;
    long int rno;

    bool found = false;

    if (!file)
    {
        cout << "File Not Found" << endl;
    }
    else
    {
        cout << "Enter Roll No. To Search: ";
        cin >> rno;

        while (getline(file, line))
        {
            if (line.find("Roll No.: " + to_string(rno)) != string::npos)
            {
                found = true;
                cout << line << endl;
                for (int i = 0; i < 5; ++i)
                {
                    getline(file, line);
                    cout << line << endl;
                }
                break;
            }
        }
        if (!found)
        {
            cout << "Student Roll No. Not Found" << endl;
        }
    }
    file.close();
    getch();
}

void student_info::update()
{
    system("cls");
    fstream file, file1;
    file.open("student_record.txt", ios::in);
    file1.open("student_record2.txt", ios::app | ios::out);

    string line;
    long int rno;
    bool found = false;

    if (!file1 || !file)
    {
        cout << "File Not Found" << endl;
    }
    else
    {
        cout << "Enter Roll No. To Update: ";
        cin >> rno;

        while (getline(file, line))
        {
            if (line.find("Roll No.: " + to_string(rno)) != string::npos)
            {
                found = true;
                cout << "Enter Student Roll No.: ";
                cin >> rollno;
                cout << "Enter Student Name: ";
                cin >> name;
                cout << "Enter Student Mobile No.: ";
                cin >> mobileno;
                cout << "Enter Student Email-Id: ";
                cin >> email;
                cout << "Validating Email....." << endl;
                Sleep(1000);

                if (isValidEmail(email))
                {
                    cout << "Email is Valid" << endl;
                    cout << "Enter Student Course: ";
                    cin >> course;
                    cout << "Enter Student Semester: ";
                    cin >> semester;

                    file1 << "Roll No.: " << rollno << endl;
                    file1 << "Name: " << name << endl;
                    file1 << "Mobile No.: " << mobileno << endl;
                    file1 << "Email: " << email << endl;
                    file1 << "Course: " << course << endl;
                    file1 << "Semester: " << semester << endl
                          << endl;

                    for (int i = 0; i < 5; ++i)
                    {
                        getline(file, line);
                    }
                }
                else
                {
                    cout << "Invalid Email Address" << endl;
                }
            }
            else
            {
                file1 << line << endl;
            }
        }
    }
    file.close();
    file1.close();
    if (!found)
    {
        cout << "Roll No. Not Found" << endl;
        remove("student_record2.txt");
    }
    else
    {
        cout << "Record Updated Successfully" << endl;
        remove("student_record.txt");
        rename("student_record2.txt", "student_record.txt");
    }
    getch();
}

void student_info::del()
{
    system("cls");
    fstream file, file1;

    file.open("student_record.txt", ios::in);
    file1.open("student_record2.txt", ios::app | ios::out);

    string line;
    long int rno;
    bool found = false;

    if (!file1 || !file)
    {
        cout << "File Not Found" << endl;
    }
    else
    {
        cout << "Enter Roll No. To Delete: ";
        cin >> rno;

        while (getline(file, line))
        {
            if (line.find("Roll No.: " + to_string(rno)) != string::npos)
            {
                found = true;

                for (int i = 0; i < 5; ++i)
                {
                    getline(file, line);
                }
            }
            else
            {
                file1 << line << endl;
            }
        }
    }
    file1.close();
    file.close();

    if (!found)
    {
        cout << "Roll No. Not Found" << endl;
    }
    else
    {
        cout << "Record Deleted" << endl;

        remove("student_record.txt");
        rename("student_record2.txt", "student_record.txt");
    }
    getch();
}

int main()
{
    student_info s;
    s.menu();
    return 0;
}