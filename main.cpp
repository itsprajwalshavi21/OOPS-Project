//C++ CODE TO DEMONSTRATE THERMAL POWERPLANT MANAGEMENT

// INCLUDING REQUIRED HEADER FILES
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

// USER DEFINED EXCEPTION HANDLING CLASS
class MyException
{
public:
    int errNo;
    string errMsg;
    MyException(int errNo, string errMsg)
    {
        this->errNo = errNo;
        this->errMsg = errMsg;
    }
    void showMsg()
    {
        cout << "Error:" << errNo << " " << errMsg << endl;
    }
};

class Dealer
{
public:
    ifstream fin;
    string PId[20];
    int DId[20];
    string DName[20];
    string DAddress[20];
    long long int DPhoneNo[20];
    Dealer()
    {
        int n;
        n = noOfLines();
        fin.open("Dealer.txt");
        while (fin.good())
        {
            for (int i = 0; i < n; i++)
            {
                fin >> PId[i] >> DId[i] >> DName[i] >> DAddress[i] >> DPhoneNo[i];
            }
        }
        fin.close();
        // Display(n);
    }

    virtual int noOfLines()
    {
        fin.open("Dealer.txt");
        int count = 0;
        string line;
        while (fin.peek() != EOF)
        {
            getline(fin, line);
            count++;
        }
        fin.close();
        return (count);
    }

    virtual void Display(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Power Plant ID:" << PId[i] << endl;
            cout << "Dealer Id: " << DId[i] << endl;
            cout << "Dealer Name: " << DName[i] << endl;
            cout << "Dealer Address: " << DAddress[i] << endl;
            cout << "Dealer Phone No: " << DPhoneNo[i] << endl;
            cout << endl;
        }
    }
};

class CoalSupplier : Dealer
{
public:
    string coalSource[10];
    string vehType[10];
    string vehNo[10];
    float coalQuantity[10];

    CoalSupplier()
    {
        int n;
        fin.open("CoalSupplier.txt");
        while (fin.good())
        {
            for (int i = 0; i < n; i++)
            {
                fin >> coalSource[i] >> vehType[i] >> vehNo[i] >> coalQuantity[i];
            }
        }
        fin.close();
        cout << "File Dealer.txt read successfully." << endl;
        cout << "File CoalSupplier.txt read successfully." << endl;
        // Display(n);
    }

    int noOfLines()
    {
        fin.open("CoalSupplier.txt");
        int count = 0;
        string line;
        while (fin.peek() != EOF)
        {
            getline(fin, line);
            count++;
        }
        fin.close();
        return (count);
    }

    void Display(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Coal Source:" << coalSource[i] << endl;
            cout << "Vehicle Type: " << vehType[i] << endl;
            cout << "Vehicle No: " << vehNo[i] << endl;
            cout << "Coal Quantity: " << coalQuantity[i] << endl;
            cout << endl;
        }
    }
};

class AshManager : Dealer
{
public:
    int Pid[10];
    string ashDest[10];
    string vehType[10];
    string vehNo[10];
    float ashQuantity[10];

    AshManager()
    {
        int n;
        n = noOfLines();
        fin.open("AshManager.txt");
        while (fin.good())
        {
            for (int i = 0; i < n; i++)
            {
                fin >> ashDest[i] >> vehType[i] >> vehNo[i] >> ashQuantity[i];
            }
        }
        fin.close();
        cout << "File AshManager.txt read successfully." << endl;
        // Display(n);
    }

    int noOfLines()
    {
        fin.open("AshManager.txt");
        int count = 0;
        string line;
        while (fin.peek() != EOF)
        {
            getline(fin, line);
            count++;
        }
        fin.close();
        return (count);
    }

    void Display(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Fly Ash Destination:" << ashDest[i] << endl;
            cout << "Fly Vehicle Type: " << vehType[i] << endl;
            cout << "Vehicle No: " << vehNo[i] << endl;
            cout << "Ash Quantity: " << ashQuantity[i] << endl;
            cout << endl;
        }
    }
};

class Employee
{
public:
    ifstream fin;
    int EmpId[50];
    string EmpName[50];
    string DOB[50];
    string DOJ[50];
    char sex[50];
    string role[50];
    float salary[50];
    string address[50];
    // bool ismanager[50];

    Employee()
    {
        int n;
        n = noOfLines();
        fin.open("Employee.txt");
        while (fin.good())
        {
            for (int i = 0; i < n; i++)
            {
                fin >> EmpId[i] >> EmpName[i] >> DOB[i] >> DOJ[i] >> sex[i] >> role[i] >> salary[i] >> address[i];
            }
        }
        fin.close();
        cout << "File Employee.txt read successfully." << endl;
        // Display(n);
    }

    int noOfLines()
    {
        fin.open("Employee.txt");
        int count = 0;
        string line;
        while (fin.peek() != EOF)
        {
            getline(fin, line);
            count++;
        }
        fin.close();
        return (count);
    }

    void Display(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Employee ID: " << EmpId[i] << endl;
            cout << "Employee Name: " << EmpName[i] << endl;
            cout << "Date of Birth: " << DOB[i] << endl;
            cout << "Date of Joining: " << DOJ[i] << endl;
            cout << "Sex: " << sex[i] << endl;
            cout << "Role: " << role[i] << endl;
            cout << "Salary: " << salary[i] << endl;
            cout << "Address: " << address[i] << endl;
            cout << endl;
        }
    }

    void update()
    {
        int EId;
        string EName;
        string DOb;
        string DOj;
        char s;
        string erole;
        float sal;
        string add;
        int n = noOfLines();
        cout << "\nEnter the following details:" << endl;
        cout << "Employee ID: ";
        EId =  n + 1;
        cout << EId << endl;
        cout << "Employee Name : ";
        cin >> EName;
        cout << "Employee DOB: ";
        cin >> DOb;
        cout << "Employee DOJ: ";
        cin >> DOj;
        cout << "Employee sex: ";
        cin >> s;
        cout << "Employee Role: ";
        cin >> erole;
        cout << "Employee salary: ";
        cin >> sal;
        if (sal < 0)
        {
            throw MyException(404, "Salary Cannot Be Negative");
        }
        cout << "Employee address: ";
        cin >> add;
        ifstream fin;
        ofstream fout;
        fin.open("Employee.txt");
        fout.open("Employee.txt", ios::app);
        fout << endl;
        fout << EId << "    ";
        fout << EName << "    ";
        fout << DOb << "    ";
        fout << DOj << "    ";
        fout << s << "    ";
        fout << erole << "    ";
        fout << sal << "    ";
        fout << add << "    ";
        fin.close();
        fout.close();
        cout << "Database Updated Successfully" << endl;
    }
};

class PowerPlant
{
public:
    Dealer *Deal;
    ifstream fin;
    string plantId[10];
    string plantName[10];
    string location[10];
    string sector[10];
    string owner[10];
    PowerPlant()
    {
        int n;
        n = noOfLines();
        fin.open("PowerPlant.txt");
        while (fin.good())
        {
            for (int i = 0; i < n; i++)
            {
                fin >> plantId[i] >> plantName[i] >> location[i] >> sector[i] >> owner[i];
            }
        }
        fin.close();
        // Display(n);
    }

    virtual int noOfLines()
    {
        fin.open("PowerPlant.txt");
        int count = 0;
        string line;
        while (fin.peek() != EOF)
        {
            getline(fin, line);
            count++;
        }
        fin.close();
        return (count);
    }

    virtual void Display(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Plant Details:" << endl;
            cout << "Plant ID: " << plantId[i] << endl;
            cout << "Plant Name: " << plantName[i] << endl;
            cout << "Plant location: " << location[i] << endl;
            cout << "Sector: " << sector[i] << endl;
            cout << "Plant Owner: " << owner[i] << endl;
            cout << endl;
        }
    }
};

class Units : PowerPlant
{
public:
    Employee *e1;
    ifstream fin;
    int unitNo[10];
    string commissionedOn[10];
    float maxCapacity[10];
    Units()
    {
        int n;
        n = noOfLines();
        fin.open("Units.txt");
        while (fin.good())
        {
            for (int i = 0; i < n; i++)
            {
                fin >> unitNo[i] >> commissionedOn[i] >> maxCapacity[i];
            }
        }
        fin.close();
        cout << "File PowerPlant.txt read successfully." << endl;
        cout << "File Units.txt read successfully." << endl;
        // Display(n);
    }

    int noOfLines()
    {
        fin.open("Units.txt");
        int count = 0;
        string line;
        while (fin.peek() != EOF)
        {
            getline(fin, line);
            count++;
        }
        fin.close();
        return (count);
    }
    void Display(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Unit ID: " << unitNo[i] << endl;
            cout << "Commissioned On: " << commissionedOn[i] << endl;
            cout << "Max Capacity: " << maxCapacity[i] << endl;
            cout << endl;
        }
    }
};

template <class T>
class PowerTransmission
{
public:
    ifstream fin;
    int Unitno;
    string Date;
    string Time;
    T InpPower;
    T OutPower;

    PowerTransmission()
    {
        InpPower = 0;
        OutPower = 0;
    }
    void setValue(int Unitno, string Date, string Time, T InpPower, T OutPower)
    {
        this->Unitno = Unitno;
        this->Date = Date;
        this->Time = Time;
        this->InpPower = InpPower;
        this->OutPower = OutPower;
    }

    friend int operator+(PowerTransmission Ta, T temp)
    {
        temp = temp + Ta.InpPower;
        return temp;
    }
    void Update()
    {
        cout << "Enter the following details:" << endl;
        cout << "Unit No: ";
        cin >> Unitno;
        if (Unitno > 8)
        {
            throw MyException(456,"Please select from the available 8 units");
        }
        cout << "Date ";
        cin >> Date;
        cout << "Time: ";
        cin >> Time;
        cout << "Input Power: ";
        cin >> InpPower;
        cout << "Output Power: ";
        cin >> OutPower;
        if (OutPower > InpPower)
        {
            throw MyException(123, "Output power cannote be more than Input power");
        }

        ifstream fin;
        ofstream fout;
        fin.open("PowerTransmission.txt");
        fout.open("PowerTransmission.txt", ios::app);
        fout << endl;
        fout << Unitno << "    ";
        fout << Date << "    ";
        fout << Time << "    ";
        fout << InpPower << "    ";
        fout << OutPower << "    ";
        fin.close();
        fout.close();
    }

    void Display()
    {
        cout << "Unit No: " << Unitno << endl;
        cout << "Date: " << Date << endl;
        cout << "Time: " << Time << endl;
        cout << "Input Power: " << InpPower << endl;
        cout << "Output Power: " << OutPower << endl;
        cout << endl;
    }
};

int noOfLines(string file)
{
    ifstream fin;
    fin.open(file);
    int count = 0;
    string line;
    while (fin.peek() != EOF)
    {
        getline(fin, line);
        count++;
    }
    fin.close();
    cout << "File PowerTransmission.txt read successfully." << endl;
    return (count);
}

//DRIVER CODE TO RUN THE PROGRAM
int main()
{
    system("CLS");
    cout << "*****************************************************************" << endl;
    cout << "                THERMAL POWERPLANT MANAGEMENT" << endl;
    cout << "*****************************************************************" << endl;
    cout << endl;
    cout << endl;

    int ch;
    int n, num;
    int sum;

    // CREATING OBJECTS OF CLASSES
    PowerPlant Pp;
    Units Unit;
    Dealer Deal;
    CoalSupplier Coal;
    AshManager Ash;
    Employee Emp;
    PowerTransmission<int> PT[15];
    ifstream fin;
    int Unitno;
    string Date;
    string Time;
    int InpPower;
    int OutPower;
    string file = "PowerTransmission.txt";
    num = noOfLines(file);
    // cout << "File PowerTransmission.txt read successfully." << endl;
    for (int i = 0; i < num; i++)
    {
        fin.open("PowerTransmission.txt");
        while (fin.good())
        {
            for (int i = 0; i < num; i++)
            {
                fin >> Unitno >> Date >> Time >> InpPower >> OutPower;
                PT[i].setValue(Unitno, Date, Time, InpPower, OutPower);
            }
        }
        fin.close();
    }

    cout << endl;
    cout << endl;
    cout << endl;
    while (1)
    {
        cout << "-------------------MENU-----------------------" << endl;
        cout << "1. Display no. of lines in all the files." << endl;
        cout << "2. Display PowerPlant database." << endl;
        cout << "3. Display Units database." << endl;
        cout << "4. Display PowerTransmission database." << endl;
        cout << "5. Display Dealer database." << endl;
        cout << "6. Display Coal Supplier database." << endl;
        cout << "7. Display Ash Manager database." << endl;
        cout << "8. Display Employee database." << endl;
        cout << "9. Update Employee database(Add a new Employee)." << endl;
        cout << "10. Update the database(refresh after update)." << endl;
        cout << "11. Update PowerTransmission database(Add a new entry)." << endl;
        cout << "12. Total input power produced." << endl;
        cout << "13. Total power sent as output." << endl;
        cout << "0. Exit" << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        cout << "Enter your choice:";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            n = Pp.noOfLines();
            cout << "Number of lines in the PowerPlant.txt file are: " << n << endl;
            n = Unit.noOfLines();
            cout << "Number of lines in the Units.txt file are: " << n << endl;

            cout << "Number of lines in the PowerTransmission.txt file are: " << num << endl;
            n = Deal.noOfLines();
            cout << "Number of lines in the Dealer.txt file are: " << n << endl;
            n = Coal.noOfLines();
            cout << "Number of lines in the CoalSupplier.txt file are: " << n << endl;
            n = Ash.noOfLines();
            cout << "Number of lines in the AshManager.txt file are: " << n << endl;
            n = Emp.noOfLines();
            cout << "Number of lines in the Employee.txt file are: " << n << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 2:
            Pp.Display(Pp.noOfLines());
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 3:
            Unit.Display(Unit.noOfLines());
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 4:
            for (int i = 0; i < num; i++)
            {
                PT[i].Display();
            }

            break;
        case 5:
            Deal.Display(Deal.noOfLines());
            cout << endl;
            cout << endl;
            cout << endl;

            break;
        case 6:
            Coal.Display(Coal.noOfLines());
            cout << endl;
            cout << endl;
            cout << endl;

            break;
        case 7:
            Ash.Display(Ash.noOfLines());
            cout << endl;
            cout << endl;
            cout << endl;

            break;
        case 8:
            Emp.Display(Emp.noOfLines());
            cout << endl;
            cout << endl;
            cout << endl;

            break;
        case 9:
            try
            {
                Emp.update();
            }
            catch (MyException &e)
            {
                e.showMsg();
            }
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 10:
            n = Pp.noOfLines();
            cout << "Number of lines in the PowerPlant.txt file are: " << n << endl;
            n = Unit.noOfLines();
            cout << "Number of lines in the Units.txt file are: " << n << endl;

            cout << "Number of lines in the PowerTransmission.txt file are: " << num << endl;
            n = Deal.noOfLines();
            cout << "Number of lines in the Dealer.txt file are: " << n << endl;
            n = Coal.noOfLines();
            cout << "Number of lines in the CoalSupplier.txt file are: " << n << endl;
            n = Ash.noOfLines();
            cout << "Number of lines in the AshManager.txt file are: " << n << endl;
            n = Emp.noOfLines();
            cout << "Number of lines in the Employee.txt file are: " << n << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 11:
            try
            {
                num++;
                PT[num].Update();
            }
            catch (MyException &e)
            {
                e.showMsg();
            }
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 12:
            sum = 0;
            for (int i = 0; i < num; i++)
            {
                sum = sum + PT[i].InpPower;
            }
            cout << "Total Input Power Transmission Per Day:" << sum << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 13:
            sum = 0;
            for (int i = 0; i < num; i++)
            {
                sum = sum + PT[i].OutPower;
            }
            cout << "Total OutPut Power Transmission Per Day:" << sum << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 0:
            cout << "Thank You!!!";
            exit(0);
            break;
        default:
            cout << "Please Enter a valid choice" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        }
    }
    return 0;
}