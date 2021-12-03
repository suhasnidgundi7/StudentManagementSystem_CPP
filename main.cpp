#include <iostream>
#include <stdlib.h>
using namespace std;

class Student
{
    // Variables
    int STUDENT_ROLL;
    char STUDENT_NAME[20];
    char STUDENT_DEPARTMENT[20];
    int STUDENT_MARKS;

public:
    // Add Student Function
    int Add_Student(Student *p, int n)
    {
        cout << "Enter Student Roll No. : ";
        cin >> p[n].STUDENT_ROLL;
        cout << "Enter Student Name : ";
        cin >> p[n].STUDENT_NAME;
        cout << "Enter Student Department : ";
        cin >> p[n].STUDENT_DEPARTMENT;
        cout << "Enter Student Marks : ";
        cin >> p[n].STUDENT_MARKS;

        cout << "\n !!! SUCCESS !!! RECORD INSERTED !!!\n";

        n++;

        return n;
    }

    // Delete Student Function
    int Delete_Student(Student *p, int roll, int n)
    {
        int j = 0, k, flag = 0;
        for (j = 0; j < n; j++)
        {
            if (p[j].STUDENT_ROLL == roll)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            for (k = 0; k < n; k++)
            {
                p[k] = p[k + 1];
                cout << "\n!!!SUCCESS !!! RECORD DELETED !!!\n";
                return n - 1;
            }
        }

        else
        {
            cout << "\n!!! ERROR !!! RECORD NOT FOUND !!!\n";
            return n;
        }
        
    }

    // Update Student Function
    int Update_Student(Student *p, int roll, int n)
    {
        int i, ch1;
        for (i = 0; i < n; i++)
        {
            if (p[i].STUDENT_ROLL == roll)
            {
                while (1)
                {
                    cout << "\n!!! === OPTIONS IN UPDATE === !!!\n";
                    cout << "\n 1. UPDATE NAME";
                    cout << "\n 2. UPDATE MARKS";
                    cout << "\n 3. Update Deptarment";
                    cout << "\n 4. UPDATE ALL";
                    cout << "\n 5. RETURN TO MAIN MENU";
                    cout << "\n\n ENTER YOUR CHOICE : ";
                    cin >> ch1;
                    cout << "\n";

                    switch (ch1)
                    {
                    case 1:
                        cout << "New Name : ";
                        cin >> p[i].STUDENT_NAME;
                        cout << "\n!!! SUCCESS !!! Name UPDATED !!!\n";
                        break;
                    case 2:
                        cout << "New Marks : ";
                        cin >> p[i].STUDENT_MARKS;
                        cout << "\n!!! SUCCESS !!! Marks UPDATED !!!\n";
                        break;
                    case 3:
                        cout << "New Department : ";
                        cin >> p[i].STUDENT_DEPARTMENT;
                        cout << "\n!!! SUCCESS !!! Department UPDATED !!!\n";
                        break;
                    case 4:
                        cout << "New Name : ";
                        cin >> p[i].STUDENT_NAME;
                        cout << "New Marks : ";
                        cin >> p[i].STUDENT_MARKS;
                        cout << "New Department : ";
                        cin >> p[i].STUDENT_DEPARTMENT;
                        cout << "\n!!! SUCCESS !!! RECORD UPDATED !!!\n";
                        break;
                    case 5:
                        return n;
                    default:
                        cout << "!!! ERROR !!! WRONG KEY !!!\n";
                        break;
                    }
                }
                break;
            }
        }
        if (p[i].STUDENT_ROLL != roll)
        {
            cout << "\n!!! ERROR !!! RECORD NOT FOUND !!!\n\n";
        }
    }

    // Display Student List
    void Display_Student()
    {
        cout << STUDENT_ROLL << "\t\t" << STUDENT_NAME << "\t\t\t" << STUDENT_DEPARTMENT << "\t" << STUDENT_MARKS << endl;
    }

    // Search Student Function
    void Search_Student(Student *p, int roll, int n)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            if (p[i].STUDENT_ROLL == roll)
            {
                cout << "ROLL NO.\tNAME\t\t\tDEPARTMENT\tMARKS\n=============================================================\n";
                cout << STUDENT_ROLL << "\t\t" << STUDENT_NAME << "\t\t\t" << STUDENT_DEPARTMENT << "\t" << STUDENT_MARKS << endl;
                break;
            }
        }
        if (p[i].STUDENT_ROLL != roll)
        {
            cout << "\n!!! ERROR !!! RECORD NOT FOUND !!!" << endl;
        }
    }
};

int main()
{
    Student o[10];
    int i = 0, ch, j, roll;

    while (1)
    {
        cout << "\n!!! === STUDENT MANAGMENT SYSTEM === !!!";
        cout << "\n";
        cout << "\n1. ADD STUDENT";
        cout << "\n2. DELETE STUDENT";
        cout << "\n3. UPDATE STUDENT";
        cout << "\n4. LIST STUDENT";
        cout << "\n5. SEARCH STUDENT";
        cout << "\n6. EXIT";
        cout << "\n\nENTER YOUR CHOICE : ";
        cin >> ch;
        cout << "\n";

        switch (ch)
        {
        case 1:
            i = o[0].Add_Student(o, i);
            break;

        case 2:
            cout << "Enter The Roll No. To Delete Record : ";
            cin >> roll;
            i = o[0].Delete_Student(o, i, roll);
            break;

        case 3:
            cout << "Enter The Roll No. To Update Data : ";
            cin >> roll;
            i = o[0].Update_Student(o, roll, i);
            break;

        case 4:
            cout << "ROLL NO.\tNAME\t\t\tDEPARTMENT\tMARKS\n=============================================================\n";
            for (j = 0; j < i; j++)
            {
                o[j].Display_Student();
            }
            break;

        case 5:
            cout << "Enter The Roll No. To Search : ";
            cin >> roll;
            cout << "\n";
            o[0].Search_Student(o, roll, i);
            break;

        case 6:
            exit(0);

        default:
            cout << "!!! ERROR !!! WRONG KEY !!!\n";
            break;
        }
    }
}
