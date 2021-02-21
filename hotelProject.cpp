#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <fstream>
// baraye print shodan struct ha dar file az menu ruye EXIT bzanid
// jahayi ke gote shode (press a key to ) lotfan char vared konid
using namespace std;
const int EmpNum = 100;       // saghfe karmandan
const int RoomNum = 100;      // saghfe otaghha
const int ReserveNum=100;     
const int MaxResident=8;      
int index;                   

void setColor(unsigned short color) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
}
void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;

    SetConsoleCursorPosition(
            GetStdHandle(STD_OUTPUT_HANDLE),
            coord
    );
}
struct hotel {
    string name = "Espinas Hotel";
    string phone = {"061-42420042-43-44"};
    string address = "Molasadra Blv,InFront Of FarhangShahr Blv ";
} h;
struct employees {
    string firstName;
    string lastName;
    int id;
    string user;
    string pass;
    string birthday;
    string jobTitle;
    double payments;

} e[EmpNum];
struct residents {

    string first_Name[MaxResident];
    string last_Name[MaxResident];
    int i_d[MaxResident];
    int flag=0;

}resident[ReserveNum];

struct reserve{
    int roomNum_reserve;
    int day_reserve;
    string ReserveStatus="Pending";
    long int ReserveCode;
    int Bed;
    int flag=0;

}re[ReserveNum];

struct reject{
	 int roomNum_reserve;
    int day_reserve;
    string ReserveStatus="Pending";
    long int ReserveCode;
    int Bed;
    int flag=0;
}rej[50];

struct property{
    string heater;
    string cooler;
    string window;
    string commode;
    string internet;
};
struct room {
    int roomNumber;
    int beds;
    string roomDes;
    double rent;
    string status;
    property p;

} r[RoomNum];
struct manager{
    string ManagerUser="matin";
    string ManagerPass="1234";
    string ManagerFirstName="Matin";
    string ManagerLastName="Zahedi";
    string Birthday="1/1/2000";
}m;

void ordinaryUser(); 
void menu();         
void Login();        
void ManagerMenu();  
void AddEmployees(); 
void AddRooms();     
void DeleteRooms();
void EditRooms();
void View_Rooms();
void View_Emp();
void ViewRooms();
void ViewEmployees();
void DeleteEmployees();
void EditEmployees();
void ReserveRoom();
void EmployeesMenu();
void requests();
void LoginEmp();
void EditEmployeesProfile(int );
void Manager();
void EditManagerProfile();
void CheckOut();
void ResidentsList();
void IncreasePayment();
void TrackingReserve();
void EmployeeMenuForManager();
void Employee(int);
void TrackingList();
void ReadFile();
void PrintFile();
void LoginManager();
double EmpCount = 0; // employees counter
double RoomCount = 0; // rooms counter
double ReserveCount = 0; //reserves counter
double RejectCount = 0;
int Ec = EmpCount; 
int Rc = RoomCount;
int ResC = ReserveCount;
int RejC=RejectCount;
int t;

int main() { 
    ReadFile(); 
    menu();
    while (1) {
        int row;
        cin >> row;
        switch (row) {
            case 1 :
                ordinaryUser();
                break;
            case 2 :
                Login();
                break;
            case 3 :
                TrackingReserve();
                break;
            case 4 : 
                TrackingList();
                break;
            case 5 : // close app
            	PrintFile();
                system("cls");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t";
                cout<<"GoodLock";
                break;         
        }
    }
   
    return 0;
}
void menu() {
 
    system("cls");
    gotoxy(35, 12);
    cout << "    ___________________________ *     *     *     *     * _________________________" << endl;
    gotoxy(35, 13);
    cout << "    |                           WELCOME TO ESPINAS HOTEL                          |" << endl;
    gotoxy(35, 14);
    cout << "    |_____________________________________________________________________________|" << endl;
    gotoxy(35, 15);
    cout << "    |                                                                             |" << endl;
    gotoxy(35, 16);
    cout << "    |                     1 .  RESERVATION                                        |" << endl;
    gotoxy(35, 17);
    cout << "    |                     2 .  LOGIN   ( MANAGER & EMPLOYEES )                    |" << endl;
    gotoxy(35, 18);
    cout << "    |                     3 .  TRACKING RESERVE                                   |" << endl;
    gotoxy(35, 19);
    cout << "    |                     4 .  TRACKING LIST                                      |" << endl;
    gotoxy(35, 20);
    cout << "    |                     5 .  EXIT                                               |" << endl;
    gotoxy(35, 21);
    cout << "    |                                                                             |" << endl;
    gotoxy(35, 22);
    cout << "    |_____________________________________________________________________________|" << endl;
    gotoxy(35, 23);
    cout << "    |                       ^ Select The Option You Want ^                        |" << endl;
    gotoxy(35, 24);
    cout << "    |_____________________________________________________________________________|" << endl;
    gotoxy(54, 26);
    cout << "ADDRESS : " << h.address << endl;        //
    gotoxy(54, 27);                                 // mojoodiat hotel
    cout << "PHONE NUMBERS : " << h.phone << endl;   //

}
// menuye marboot be karbarani ke mikhan otagh reserve konan
void ordinaryUser() {
    system("cls");
    gotoxy(35, 14);
    cout << "    _______________________________________________________________________________" << endl;
    gotoxy(35, 15);
    cout << "    |                                                                             | " << endl;
    gotoxy(35, 16);
    cout << "    |                          1 .  ROOMS RESERVATION                             |" << endl;
    gotoxy(35, 17);
    cout << "    |                          2 .  BACK TO HOME PAGE                             |" << endl;
    gotoxy(35, 18);
    cout << "    |_____________________________________________________________________________|" << endl;
    gotoxy(35, 19);
    cout << "    |                       ^ Select The Option You Want ^                        |" << endl;
    gotoxy(35, 20);
    cout << "    |_____________________________________________________________________________|" << endl;
    int y;
    cin >> y;
    switch (y) {
        case 1:
            system("cls");
            ReserveRoom();
            break;
        case 2 :
            menu();
            break;
    }
}
 // menuye hotel manager
void ManagerMenu() {
    int select;
    system("cls");

    gotoxy(35, 14);
    cout << "    _______________________________________________________________________________" << endl;
    gotoxy(35, 15);
    cout << "    |                                                                             | " << endl;
    gotoxy(35, 16);
    cout << "    |                          1 .  VIEW EMPLOYEES LIST                           |" << endl;
    gotoxy(35, 17);
    cout << "    |                          2 .  VIEW ROOMS LIST                               |" << endl;
    gotoxy(35, 18);
    cout << "    |                          3 .  ADD/REMOVE/EDIT EMPLOYEES                     |" << endl;
    gotoxy(35, 19);
    cout << "    |                          4 .  ADD/REMOVE/EDIT ROOMS                         |" << endl;
    gotoxy(35, 20);
    cout << "    |                          5 .  EMPLOYEE DASHBOARD                            |" << endl;
    gotoxy(35, 21);
    cout << "    |                          6 .  INCREASE EMPLOYEES PAYMENT                    |" << endl;
    gotoxy(35, 22);
    cout << "    |                          7 .  BACK                                          |" << endl;
    gotoxy(35, 23);
    cout << "    |_____________________________________________________________________________|" << endl;
    gotoxy(35, 24);
    cout << "    |                       ^ Select The Option You Want ^                        |" << endl;
    gotoxy(35, 25);
    cout << "    |_____________________________________________________________________________|" << endl;
    int x,y;
    cin >> x;
    switch (x) {
        case 1:
            system("cls");
            ViewEmployees();
            break;
        case 2:
            system("cls");
            ViewRooms();
            break;
        case 3:
            system("cls");

            gotoxy(35, 14);
            cout << "    _______________________________________________________________________________" << endl;
            gotoxy(35, 15);
            cout << "    |                                                                             | " << endl;
            gotoxy(35, 16);
            cout << "    |                          1 .  ADD EMPLOYEES                                 |" << endl;
            gotoxy(35, 17);
            cout << "    |                          2 .  REMOVE EMPLOYEES                              |" << endl;
            gotoxy(35, 18);
            cout << "    |                          3 .  EDIT EMPLOYEES                                |" << endl;
            gotoxy(35, 19);
            cout << "    |                          4 .  BACK                                          |" << endl;
            gotoxy(35, 20);
            cout << "    |_____________________________________________________________________________|" << endl;
            gotoxy(35, 21);
            cout << "    |                       ^ Select The Option You Want ^                        |" << endl;
            gotoxy(35, 22);
            cout << "    |_____________________________________________________________________________|" << endl;
            cin >> y;
            switch (y) {
                case 1:
                    AddEmployees();
                    break;
                case 2 :
                    DeleteEmployees();
                    break;
                case 3 :
                    EditEmployees();
                    break;
                case 4 :
                    ManagerMenu();
                    break;
            }
            break;
        case 4:
            system("cls");
            gotoxy(35, 14);
            cout << "    _______________________________________________________________________________" << endl;
            gotoxy(35, 15);
            cout << "    |                                                                             | " << endl;
            gotoxy(35, 16);
            cout << "    |                          1 .  ADD ROOMS                                     |" << endl;
            gotoxy(35, 17);
            cout << "    |                          2 .  REMOVE ROOMS                                  |" << endl;
            gotoxy(35, 18);
            cout << "    |                          3 .  EDIT ROOMS                                    |" << endl;
            gotoxy(35, 19);
            cout << "    |                          4 .  BACK                                          |" << endl;
            gotoxy(35, 20);
            cout << "    |_____________________________________________________________________________|" << endl;
            gotoxy(35, 21);
            cout << "    |                       ^ Select The Option You Want ^                        |" << endl;
            gotoxy(35, 22);
            cout << "    |_____________________________________________________________________________|" << endl;
            cin>>x;
            switch(x){
                case 1:

                    AddRooms();
                    break;
                case 2:
                    DeleteRooms();
                    break;
                case 3:
                    EditRooms();
                    break;
                case 4:
                    ManagerMenu();
                    break;
            }
            break;

        case 5 :
            EmployeeMenuForManager();
            break;
        case 6:
            IncreasePayment();
            break;
        case 7:
            Manager();
    }
}

void Login() { // login panel ebteda manager ya employee entekhab shavad
    system("cls");
//    string User;
//    string Pass;

    gotoxy(40, 14);
    cout << "    ___________________________________________________________________________" << endl;
    gotoxy(40, 15);
    cout << "    |                                                                         | " << endl;
    gotoxy(40, 16);
    cout << "    |                          1 .  MANAGER                                   |" << endl;
    gotoxy(40, 17);
    cout << "    |                          2 .  EMPLOYEES                                 |" << endl;
    gotoxy(40, 18);
    cout << "    |                          3 .  BACK TO HOMEPAGE                          |" << endl;
    gotoxy(40, 19);
    cout << "    |_________________________________________________________________________|" << endl;
    gotoxy(40, 20);
    cout << "    |                       ^ Select The Type Of User ^                       |" << endl;
    gotoxy(40, 21);
    cout << "    |_________________________________________________________________________|" << endl;
    int row;
    cin >> row;
    int i =0,k;
    switch (row) {
        case 1 :
//            system("cls");
         LoginManager();
            break;
        case 2:
            LoginEmp();
            break;
        case 3:
            menu();
            break;
    }
}
void AddEmployees() { // add a employee
    char ch;
    system("cls");
    cout << setw(84) << "Add A New Employees " << endl << endl;
    // vared kardan etelaate karmand
    cout << "                                                                First Name : ";
    cin >> e[Ec].firstName;
    cin.ignore();
    cout << "                                                                Last Name : ";
    getline(cin, e[Ec].lastName);
    srand(time(0));
    e[Ec].id = rand() % 90000 + 10000; // tolid id baraye har employee
    cout << "                                                                UserName : ";
    cin>>e[Ec].user;
    cout << "                                                                Password : ";
    cin>>e[Ec].pass;
    cout << "                                                                Job Title : ";
    cin >> e[Ec].jobTitle;
    cout << "                                                                Date OF Birth (Day/Month/Year) : ";
    cin >> e[Ec].birthday;
    cout << "                                                                Payment ( Per Dollar ) : ";
    cin >> e[Ec].payments;
    cout << endl << endl;
    cout << "                                                                New Employee Added " << endl << endl;
    cout << "                                                                Add The Next Emoloyee ? (y/n) " ;
    Ec++;
    cin >> ch;
    if (ch == 'y') {
        AddEmployees();
    } else {
        ManagerMenu();
    }
}

void ViewEmployees(){ // case 1 : manager
    char ch;
    View_Emp();
    cout << "                                                              Press A Key and back to Manager Menu ";
    cin >> ch;
    ManagerMenu();
}

void DeleteEmployees() { // delete employees ba vared kardan id 
    system("cls");
    int temp;
    char ch;
    int delete_id,flag=0;
    cout << "                                                                    DELETE A EMPLOYEE \n\n";
    View_Emp(); // namayesh list employees
    cout << "                                                                    Enter the Employee ID : ";
    cin >> delete_id;
    for (int i = 0; i <= Ec; i++) {
        if (delete_id == e[i].id ) { // peyda kardan id baraye delete kardan
        	temp=i;
            system("cls");
            cout << "                                                               First Name : " << e[i].firstName << endl;
            cout << "                                                               Last Name : " << e[i].lastName << endl;
            cout << "                                                               ID : " << e[i].id << endl;
            cout << "                                                               UserName : " << e[i].user<<endl;
            cout << "                                                               Password : " << e[i].pass<<endl;
            cout << "                                                               Birthday : " << e[i].birthday << endl;
            cout << "                                                               Job Title : " << e[i].jobTitle << endl;
            cout << "                                                               Payment : " << e[i].payments << endl << endl;
            cout << "                                                               User Deleted ? (y/n) ";
            cin >> ch;
            if (ch == 'y') {
                flag=1;
                // farayand hazfe employee
              for ( temp ; temp < Ec ; ++temp) {
                 e[temp] = e[temp+1];
                }
                Ec--;
                //
                cout<<"\n\n";
                cout << "                                                               User Deleted " << endl;
                cout << "                                                               Press A Key To Back Manager Menu ";
                cin >> ch;
                ManagerMenu();
            }
        }
    }
    if (flag==0){ // if employee peyda nashod
        cout<<"                                                                           USER NOT FOUND\n";
        cout << "                                                               Press A Key To Back Manager Menu ";
        cin >> ch;
        ManagerMenu();
    }
}
void EditEmployees() { // edit employee profile by manager 
    int Edit_id;
    int flag=0;
    char ch;
    system("cls");
    cout << "                                                                          Edit EMPLOYEE \n\n";
    View_Emp();
    cout << "                                                                         Enter The Employee ID : ";
    cin >> Edit_id;
    for (int i = 0; i < Ec; i++) { //search beine employee
        if (Edit_id == e[i].id) {
            system("cls");
            cout << "                                                               First Name : " << e[i].firstName << endl;
            cout << "                                                               Last Name : " << e[i].lastName << endl;
            cout << "                                                               ID : " << e[i].id << endl;
            cout << "                                                               UserName : " << e[i].user<<endl;
            cout << "                                                               Password : " << e[i].pass<<endl;
            cout << "                                                               Birthday : " << e[i].birthday << endl;
            cout << "                                                               Job Title : " << e[i].jobTitle << endl;
            cout << "                                                               Payment : " << e[i].payments << endl << endl;
            cout << "                                                               Employee Edite ? (y/n) ";
            cin>>ch;
            if (ch == 'y') {
                flag=1;
                // vared kardan etelaate jadid baraye employees
                cout << "                                                               First Name : ";
                cin >> e[i].firstName;
                cin.ignore();
                cout << "                                                               Last Name : ";
                getline(cin, e[i].lastName);
                cout << "                                                               UserName : ";
                cin>>e[i].user;
                cout << "                                                               Password : ";
                cin>>e[i].pass;
                cout << "                                                               Job Title : ";
                cin >> e[i].jobTitle;
                cout << "                                                               Date OF Birth (Day/Month/Year) : ";
                cin >> e[i].birthday;
                cout << "                                                               Payment ( Per Dollar ) : ";
                cin >> e[i].payments;
                cout << endl << endl;
                cout << "                                                                           User Edited " << endl;
                cout << "                                                                  Press A Key To Back Manager Menu ";
                cin >> ch;
                ManagerMenu();
            }
        }
    }
    if(flag==0){ // if no find employee
        cout<<"                                                                           USER NOT FOUND\n";
        cout << "                                                                  Press A Key To Back Manager Menu ";
        cin >> ch;
        ManagerMenu();
    }
}
void View_Emp() { // namayesh list employees
    cout << "                                                                          Employees List  " << endl;
    cout << "                                                          -----------------------------------------------" <<endl;
    for (int i = 0; i < Ec; i++) {
        {
            cout << "                                                               First Name : " << e[i].firstName << endl;
            cout << "                                                               Last Name : " << e[i].lastName << endl;
            cout << "                                                               ID : " << e[i].id << endl;
            cout << "                                                               Job Title : " << e[i].jobTitle << endl;
            cout << "                                                               Birthday : " << e[i].birthday << endl;
            cout << "                                                               Username : " << e[i].user<<endl;
            cout << "                                                               Password : " << e[i].pass<<endl;
            cout << "                                                               Payment : " << e[i].payments << endl;
            cout<< "                                                           -----------------------------------------------"<< endl;
        }
    }
}
void AddRooms(){ // add room 
    char ch;
    system("cls"); 
    // vared kardan moshakhasat new room
    cout << setw(79) << "Add A New Room " << endl << endl;
    cout << "                                                                Room Number : ";
    cin >> r[Rc].roomNumber;
    cout << "                                                                beds : ";
    cin>>r[Rc].beds;
    cin.ignore();
    cout << "                                                                Description : ";
    getline(cin, r[Rc].roomDes);
    r[Rc].status = "Empty";
    cout << "                                                                Heater : ";
    cin >> r[Rc].p.heater;
    cout << "                                                                Cooler : ";
    cin >> r[Rc].p.cooler;
    cout << "                                                                Window : ";
    cin >> r[Rc].p.window;
    cout << "                                                                Commode : ";
    cin >> r[Rc].p.commode;
    cout << "                                                                Internet : ";
    cin >>r[Rc].p.internet;
    cout << "                                                                Rent : ";
    cin>>r[Rc].rent;
    cout << endl << endl;
    cout << "                                                                New Room Added " << endl << endl;
    cout << "                                                                Add The Next Room ? (y/n) " ;
    Rc++;
// Rc = Room Counter
    cin >> ch;
    if (ch == 'y') {
        AddRooms();
    } else {
        ManagerMenu();
    }
}
void ViewRooms(){ //view room for manager (case 2)
    char ch;
    View_Rooms();
    cout << "                                                              Press A Key and back to Manager Menu ";
    cin >> ch;
    ManagerMenu();
}
void View_Rooms(){ //view rooms list
    cout << "                                                                          Rooms List  " << endl;
    cout << "                                                          -----------------------------------------------"<< endl;
    for (int j = 0; j < Rc; j++) { // print room list
        {
            cout << "                                                               Room Number : " << r[j].roomNumber << endl;
            cout << "                                                               Beds : " << r[j].beds << endl;
            cout << "                                                               Description : " << r[j].roomDes << endl;
            cout << "                                                               Status : " << r[j].status<< endl ;
            cout << "                                                               Heater : " << r[j].p.heater<<endl;
            cout << "                                                               Cooler : " << r[j].p.cooler<<endl;
            cout << "                                                               Window : " << r[j].p.window<<endl;
            cout << "                                                               Commode : " << r[j].p.commode<<endl;
            cout << "                                                               Internet : " << r[j].p.internet<<endl;
            cout << "                                                               Rent : " << r[j].rent <<" $" <<endl;
            cout << "                                                          -----------------------------------------------"<< endl;
        }
    }
}
void DeleteRooms(){ // delete a room ba vared kardan room  number
    system("cls");
    char ch;
    int temp;
    int delete_RoomNumber;
    cout << "                                                                    DELETE A Room \n\n";
    View_Rooms();
    cout << "                                                                    Enter the Room Number : ";
    cin >> delete_RoomNumber;
    for (int i = 0; i <= Rc; i++) { // search beyne rooms
        if (delete_RoomNumber == r[i].roomNumber) {
        	temp=i;
            system("cls");
            cout << "                                                               Room Number : " << r[i].roomNumber << endl;
            cout << "                                                               Bed : " << r[i].beds << endl;
            cout << "                                                               Description : " << r[i].roomDes << endl;
            cout << "                                                               Heater : " << r[i].p.heater <<endl;
            cout << "                                                               Cooler : " << r[i].p.heater <<endl;
            cout << "                                                               Window : " << r[i].p.heater <<endl;
            cout << "                                                               Commode : " << r[i].p.heater <<endl;
            cout << "                                                               Internet : " << r[i].p.heater <<endl;
            cout << "                                                               Rent : " << r[i].rent<<" $"<< endl<<endl;
            cout << "                                                               Room Deleted ? (y/n) ";
            cin >> ch;
            if (ch == 'y') { // farayand hazfe room
                for ( temp ; temp < Rc ; ++temp) {
                 r[temp] = r[temp+1];
                }
                Rc--;
                cout<<"\n\n";
                cout << "                                                               Room Deleted " << endl;
            } else {
                ManagerMenu();
            }
        }
    }
    cout << "                                                               Press A Key To Back Manager Menu ";
    cin >> ch;
    ManagerMenu();
}
void EditRooms(){ // edit rooms ba vared kardan room number

    int Edit_RoomNumber;
    char ch;
    system("cls");
    cout << "                                                                          Edit Rooms \n\n";
    View_Rooms();
    cout << "                                                                     Enter The Room Number : ";
    cin >> Edit_RoomNumber;
    for (int i = 0; i < Rc ; i++) { //search beine rooms
        if (Edit_RoomNumber == r[i].roomNumber && r[i].status=="Empty") {
            system("cls");
            cout << "                                                               Room Number : " << r[i].roomNumber << endl;
            cout << "                                                               Bed : " << r[i].beds << endl;
            cout << "                                                               Description : " << r[i].roomDes << endl;
            cout << "                                                               Heater : " << r[i].p.heater <<endl;
            cout << "                                                               Cooler : " << r[i].p.heater <<endl;
            cout << "                                                               Window : " << r[i].p.heater <<endl;
            cout << "                                                               Commode : " << r[i].p.heater <<endl;
            cout << "                                                               Internet : " << r[i].p.heater <<endl;
            cout << "                                                               Rent : " << r[i].rent<<" $"<< endl<<endl;
            cout << "                                                               Room Edite ? (y/n) ";
            cin>>ch;
            if (ch == 'y') { // daryaft etelaate jadid otagh
                cout<<endl<<endl;
                cout << "                                                               Room Number : ";
                cin >> r[i].roomNumber;
                cin.ignore();
                cout << "                                                               Beds : ";
                cin >> r[i].beds;
                cout << "                                                               Description : ";
                cin.ignore();
                getline(cin, r[i].roomDes);
                cout << "                                                               Heater : ";
                cin >> r[i].p.heater;
                cout << "                                                               Cooler : ";
                cin >> r[i].p.cooler;
                cout << "                                                               Window : ";
                cin >> r[i].p.window;
                cout << "                                                               Commode : ";
                cin >> r[i].p.commode;
                cout << "                                                               Internet : ";
                cin >> r[i].p.internet;
                cout << "                                                               Rent : ";
                cin >> r[i].rent;
				cout << "\n";
                cout << "                                                               Rome Edited " << endl;
                r[i].status="Empty";
            }
            else {
                ManagerMenu();
            }
        }
    }
    cout << "                                                               Press A Key To Back Manager Menu ";
    cin >> ch;
    ManagerMenu();
}

void EmployeesMenu(){
    int x ; // select option
    char ch ;
    system("cls");

    gotoxy(35, 14);
    cout << "    _______________________________________________________________________________" << endl;
    gotoxy(35, 15);
    cout << "    |                                                                             | " << endl;
    gotoxy(35, 16);
    cout << "    |                          1 .  VIEW ROOMS                                    |" << endl;
    gotoxy(35, 17);
    cout << "    |                          2 .  REQUESTS                                      |" << endl;
    gotoxy(35, 18);
    cout << "    |                          3 .  HOTEL RESIDENTS                               |" << endl;
    gotoxy(35, 19);
    cout << "    |                          4 .  RESERVATION                                   |" << endl;
    gotoxy(35, 20);
    cout << "    |                          5 .  CHECK OUT                                     |" << endl;
    gotoxy(35, 21);
    cout << "    |                          6 .  BACK                                          |" << endl;
    gotoxy(35, 22);
    cout << "    |_____________________________________________________________________________|" << endl;
    gotoxy(35, 23);
    cout << "    |                       ^ Select The Option You Want ^                        |" << endl;
    gotoxy(35, 24);
    cout << "    |_____________________________________________________________________________|" << endl;
    cin>>x;
    switch(x){
        case 1 :
            system("cls");
            View_Rooms();
            cout<<"                                                             Enter The Key To Back To Employees Menu : ";
            cin>> ch;
            EmployeesMenu();
            break;
        case 2 :
            requests();
            break;
        case 3 :
            ResidentsList();
            break;
        case 4 :
            system("cls");
            ReserveRoom();
            break;
        case 5 :
            CheckOut();
            break;
        case 6 :
            if(t==1){
                Employee(index);
                break;
            }
            if(t==0){
                ManagerMenu();
            }
    }
}
// room haye khali (status==empty) be karbar neshan dade mishavad va ba vared kardan shomare otagh delkhah
// anra reserve mikonad
void ReserveRoom(){
    char ch;
    int flag=0;
    cout << "                                                                          Reservation "<<endl<<endl;
    cout << "                                                                          Rooms List  " << endl;
    cout << "                                                          -----------------------------------------------"<< endl;
    for (int j = 0; j < Rc; j++) {
        if ( r[j].status == "Empty" ) {
            cout << "                                                               Room Number : " << r[j].roomNumber << endl;
            cout << "                                                               Beds : " << r[j].beds << endl;
            cout << "                                                               Description : " << r[j].roomDes << endl;
            cout << "                                                               Heater : " << r[j].p.heater << endl ;
            cout << "                                                               Coller : " << r[j].p.cooler << endl ;
            cout << "                                                               Window : " << r[j].p.window << endl ;
            cout << "                                                               Commode : " << r[j].p.commode << endl ;
            cout << "                                                               Internet : " << r[j].p.internet << endl;
            cout << "                                                               Rent : " << r[j].rent <<" $" << endl;
            cout << "                                                          -----------------------------------------------"<< endl;
        }
    }
            cout << "                                                                      Enter The Room Number : ";
    cin >> re[ResC].roomNum_reserve;
    for(int i=0;i<Rc;i++){
        if(re[ResC].roomNum_reserve == r[i].roomNumber && r[i].status=="Empty"){ //agar otagh khali bood 
        // daryaft etelaate sefaresh az moshtari
            cout << "                                                                      Number OF Booking Days : ";
            cin >> re[ResC].day_reserve;
            cout << "                                                                      Residents Information"<<endl;
            for(int k=0;k<r[i].beds;k++){
            cout << "                                                                      First Name "<<k+1<<" : ";
            cin >> resident[ResC].first_Name[k];
            cout << "                                                                      Last Name "<<k+1<<" : ";
            cin>> resident[ResC].last_Name[k];
                srand(time(0));
                resident[ResC].i_d[k]=rand()% 500000 + 100000; //tolid tracking code baraye har shakhs
                re[ResC].Bed=r[i].beds;
            }
            srand(time(0));
            re[ResC].ReserveCode=rand() % 900000 + 100000 ; // tolid tracking code baraye reserve
            cout<<endl;
            cout << "                                                             Your Request Has Been Successfully Submitted\n";
            cout << "                                                      Write Down The Tracking Code To Follow Up On Your Request\n";
            cout << "                                                                     Reservation Code : ";
            cout << re[ResC].ReserveCode;
            ResC++;
            flag=1;
            r[i].status = "Pending";

            cout << "\n\n                                                                   Press A Key To back To Menu ";
            cin>>ch;
            menu();
        }
    }
    if(flag==0){ // agar otaghi ba shomare vared shode nabood ya full ya pending bood -> not found
    	cout<<endl;
        cout<<"                                                                         ROOM NOT FOUND\n"<<endl;
        cout<<"                                                                   PRESS A KEY TO BACK TO MENU ";
        cin>>ch;
        menu();
    }
}
void requests(){
	// accept ya reject requests
    int flag=0,temp;
    int confirm ; // shomare otagh baraye confirm kardan
    char ch;
    system("cls");
    cout <<"                                                                            REQUESTS\n";
    cout <<"                                                       -----------------------------------------------------"<<endl;
    for(int i=0;i<ResC;i++){
        if(re[i].flag == 0 ){
            cout<<"                                                          Room Number : "<<re[i].roomNum_reserve<<endl;
            cout<<"                                                          Booking Days : "<<re[i].day_reserve<<endl;
            cout<<"                                                          Residents : "<<endl;
            for(int h=0;h<re[i].Bed;h++){
            cout<<"                                                          Name "<<h+1<<" : "<<resident[i].first_Name[h]<<" "<<resident[i].last_Name[h]<<endl;
            }
            cout<<"                                                          Tracking Code : "<<re[i].ReserveCode<<endl;
        }
        cout<<"                                                        ---------------------------------------------------\n";
    }
    cout<<"                                                                    ENTER ROOM NUMBER : ";
    cin>>confirm;
    for(int i=0;i<ResC;i++){
        if(confirm == re[i].roomNum_reserve){ // search shomare otagh dar bein darkhastha
        temp=i;
            for(int j=0;j<Rc;j++){
                if (re[i].roomNum_reserve==r[j].roomNumber && re[i].ReserveStatus=="Pending"){
                	// search baraye peyda kardan vaziat otagh ke hatman bayad pending bashad
                    cout<<endl;
                    flag=1;
    cout<<"                                                                    Reserve Room "<<re[i].roomNum_reserve<<" (y/n) ? ";
                    cin>>ch;
                    if(ch=='y'){// confirm request
                        r[j].status="Full"; 
                        re[i].ReserveStatus="Confirmed";
                        cout<<endl<<endl;
                        setColor(2);
                        cout<<"                                                                           CONFIRMED\n";
                        setColor(7);
                        resident[i].flag=1;
                        re[i].flag=1;
                        cout<<"                                                               Press A Key To Back To Dashboard ";
                        cin>>ch;
                        EmployeesMenu();
                    }
                    else if(ch=='n'){ // reject request
                    	rej[RejC].roomNum_reserve = re[i].roomNum_reserve;
                        rej[RejC].day_reserve=re[i].day_reserve;
                        rej[RejC].ReserveStatus="Rejected";
                        rej[RejC].ReserveCode=re[i].ReserveCode;
                        rej[RejC].Bed=re[i].Bed;
                        RejC++;
                    for(temp;temp<ResC;temp++){
                    	re[temp]=re[temp+1];
                    	resident[temp]=resident[temp+1];
					}
					ResC--;
    
                        r[j].status="Empty" ; 
//                        resident[i].flag=0 ; 
                        setColor(4);
                        cout<<"                                                                             REJECTED\n";
                        setColor(7);
                        cout<<"                                                               Press A key To Back To Dashboard ";

                        cin>>ch;
                        EmployeesMenu();
                    }

                }
            }
        }

    }
    if(flag==0){ // agar room peyda nashod
        cout<<"                                                                        THE ROOM NOT FOUND\n";
        cout<<"                                                                 PRESS A KEY TO BACK TO DASHBOARD ";
        cin>>ch;
        EmployeesMenu();
    }
}
void LoginEmp(){ // [anel login baraye employees
    string EmpUser;
    string EmpPass;
    char ch;

    int select,flag=0;
    system("cls");
    cout << endl << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << setw(85) << "USERNAME : ";
    cin >> EmpUser;
    cout << setw(85) << "PASSWORD : ";
    cin >> EmpPass;
    for(int i=0 ; i<Ec ; i++){ // search beine employees
        if(e[i].user==EmpUser && e[i].pass==EmpPass ){
            t=1;
            flag=1;
            index=i; // index baraye peida kardan moshkhasat karbari ke login mikone ta betune profilesho edit kone
            system("cls");
            Employee(index); 
        }
    }
    if(flag == 0){ // agar user or pass eshtebah bood
        cout<<"\n\n";
        setColor(4);
        cout<< "                                                                     Wrong UserName Or Password \n\n";
        setColor(7);
        cout<<"                                                    Press (n) And Back To Menu Or Press (y) To Go To Login Panel ";
        cin>>ch;
        if(ch=='y'){
        LoginEmp();	
		}
        else if(ch=='n'){
        menu();	
		}
    }
}
void Manager(){ //safhe bad az login kardan manager
    int select;
    system("cls");
    gotoxy(72, 10);
    cout <<"Welcome "<<m.ManagerFirstName<<" "<<m.ManagerLastName<<"\n\n";
    gotoxy(40, 14);
    cout << "    ___________________________________________________________________________" << endl;
    gotoxy(40, 15);
    cout << "    |                                                                         | " << endl;
    gotoxy(40, 16);
    cout << "    |                          1 .  DASHBOARD                                 |" << endl;
    gotoxy(40, 17);
    cout << "    |                          2 .  MY PROFILE                                |" << endl;
    gotoxy(40, 18);
    cout << "    |                          3 .  LOGOUT                                    |" << endl;
    gotoxy(40, 19);
    cout << "    |_________________________________________________________________________|" << endl;
    gotoxy(40, 20);
    cout << "    |                       ^ Select The Type Of User ^                       |" << endl;
    gotoxy(40, 21);
    cout << "    |_________________________________________________________________________|" << endl;

    cin>>select;
    switch(select){
        case 1 :
            ManagerMenu(); // mize kar modir
            break;
        case 2 :
            EditManagerProfile(); 
            break;
        case 3 :
            menu();
            break ;

    }
}

void EditManagerProfile(){ // edit manager profile
    int flag=0;
    char ch;
    system("cls");
    cout<<"                                                               First Name : "<<m.ManagerFirstName<<endl;
    cout<<"                                                               Last Name : "<<m.ManagerLastName<<endl;
    cout<<"                                                               UserName : "<<m.ManagerUser<<endl;
    cout<<"                                                               Password : "<<m.ManagerPass<<endl;
    cout<<"                                                               Date OF Birth : "<<m.Birthday<<endl;
    cout<<"                                                               Do You Want Edit Your Profile ? (y/n) ";
    cin>>ch;
    cout<<endl;
    if(ch=='y'){
        flag=1;
        cout<<"                                                               New First Name : ";
        cin>>m.ManagerFirstName;
        cout<<"                                                               New Last Name : ";
        cin>>m.ManagerLastName;
        cout<<"                                                               New UserName : ";
        cin>>m.ManagerUser;
        cout<<"                                                               New Password : ";
        cin>>m.ManagerPass;
        cout<<"                                                               Date OF Birth : ";
        cin>>m.Birthday;
        cout<<"                                                               Your Profile Updated\n";
        cout<<"                                                               Press A Key TO Back To Main Menu : ";
        cin>>ch;
        Manager();
    }
    if(flag==0){
        cout<<"                                                               Press A Key TO Back To Main Menu : ";
        cin>>ch;
        Manager();
    }
}
void CheckOut(){
// khali kardan room haye full ba vared kardan tracking code 
    system("cls");
    int out,temp,flag=0; // int out baraye tracking code ke mikhaim check out she
    char ch;
    cout<<setw(86)<<"CHECK OUT\n\n";
    cout << "                                                                          Rooms List  " << endl;
    cout << "                                                          -----------------------------------------------"<< endl;
    if(ResC>0){
	
    for (int j = 0; j < Rc; j++) {
        if (r[j].status=="Full"){ // faghat otaghhaie ke full hastan ro mishe check out kard
    cout << "                                                               Room Number : " << r[j].roomNumber << endl;
    cout << "                                                               Beds : " << r[j].beds << endl;
    cout << "                                                               Status : " << r[j].status<< endl ;
    cout << "                                                               Heater : " << r[j].p.heater<<endl;
    cout << "                                                               Cooler : " << r[j].p.cooler<<endl;
    cout << "                                                               Window : " << r[j].p.window<<endl;
    cout << "                                                               Commode : " <<r[j].p.commode<<endl;
    cout << "                                                               Rent : " << r[j].rent <<" $" <<endl;
        for(int k=0;k<Rc;k++){
            if(r[j].roomNumber==re[k].roomNum_reserve){ 
    cout << "                                                               Tracking Code : "<<re[k].ReserveCode<<endl;

                }
            }
    cout << "                                                          -----------------------------------------------"<< endl;
        }
    }
    cout << "                                                             ENTER TRACKING CODE FOR CHECK OUT : ";
    cin>>out;
    for(int i=0;i<ResC;i++){
        if(out==re[i].ReserveCode){
        	temp=i; // ghrar dadan index reserve baraye delete kardan sefaresh 
    cout << "                                                                  CECK OUT ROOM "<<re[i].roomNum_reserve <<": (y/n)? ";
            cin>>ch;
            if(ch=='y'){
                flag=1; 
			 for(int h=0;h<Rc;h++){
                if(re[i].roomNum_reserve == r[h].roomNumber){
                        r[h].status = "Empty";
//                        resident[i].flag=0;
                        // vaghti otagh delete shod room status az full be empty taghir mikone
                    }
                }
                //**************************** farayand hazfe reserve
                for(temp;temp<ResC;temp++){ 
                	re[temp]=re[temp+1];
                	resident[temp]=resident[temp+1];
				}
				ResC--;
				//**************************** 
              
                cout << "                                                                          Done\n";
                cout << "                                                                PRESS A KEY TO BACK TO DASHBOARD ";
                cin>>ch;
                EmployeesMenu();
            }
        }
    }
}
    if(flag==0){ // agar tracking code peyda nashod
    cout << "                                                                          NOT FOUND\n: ";
    cout << "                                                                PRESS A KEY TO BACK TO DASHBOARD ";
        cin>>ch;
        EmployeesMenu();
    }

}
void ResidentsList(){ // list sakenin hotel
    int flag=0;
    char ch;
    system("cls");
    cout << "                                                                      Hotel Residents "<<endl;
    cout << "                                                         -------------------------------------------"<<endl;
    for(int i=0;i<ResC;i++){
        if(resident[i].flag==1){
    cout << "                                                                         Room : " <<re[i].roomNum_reserve<<endl;
            flag=1;
            for(int j=0;j<re[i].Bed;j++){ // print afrad dakhel har otagh  
    cout << "                                                          Name : "<<resident[i].first_Name[j]<<" "<<resident[i].last_Name[j]<<endl;
    cout << "                                                          ID : "<<resident[i].i_d[j]<<endl;
            }
			}
    cout << "                                                         -------------------------------------------"<<endl;
	}
    cout<<endl;
    cout<< "                                                               Press A Key To Back To Dashboard ";
            cin>>ch;
            EmployeesMenu();
        
    
    if(flag==0){ // agar hotel bedune residents bood
        cout<<"                                                                      NO FIND RESIDENT\n";
        cout<<"                                                               PRESS A KEY TO BACK TO DASHBOARD ";
        cin>>ch;
        EmployeesMenu();
    }
}
void IncreasePayment(){ // increase employee payment
    int flag=0;
    char ch;
    system("cls");
    int increase_id;
    double increase_amount;
    View_Emp();
    cout<< "                                                                  Enter The Employee ID : ";
    cin>>increase_id;
    cout<<endl;
    for(int i=0;i<Ec;i++){ // search beyne karmanda
        if(increase_id==e[i].id){
            flag=1;
            cout<<"                                                                   Current Payment : "<<e[i].payments<<endl;
            cout<<"                                                      Enter The Amount You Want To Add The "<<e[i].id<<" Payment : ";
            cin>>increase_amount; // meghdari ke mikhaym be payment ezafe she
            e[i].payments+=increase_amount; 
            cout<<endl;
            cout<<"                                                                   New Payment : "<<e[i].payments <<endl;
            cout<<"                                                                           Done\n";
            cout<<"                                                            Press A Key To Back To DASHBOARD";
            cin>>ch;
            ManagerMenu();
        }
    }
    if(flag==0){ // agar karbar yaft nashod
        cout<<"                                                                       EMPLOYEE NOT FOUND\n";
        cout<<"                                                                 PRESS A KEY TO BACK TO DASHBOARD";
        cin>>ch;
        ManagerMenu();
    }
}
void TrackingReserve(){ // tracking requests ba vared kardan tracking code baraye har otagh
    int flag=0;
    char ch;
    system("cls");
    int TrackingCode;
    cout << "                                                                TRACKING RESERVE\n\n";
    cout << "                                                           ENTER TRACKING CODE : ";
    cin >> TrackingCode;
    cout<<"\n\n";
    for(int i=0;i<ResC;i++){ // search beine sefareshat
        if(TrackingCode==re[i].ReserveCode){
            flag=1;
            cout<<"                                                                    Your Request " <<endl ;
            cout<<"                                                          ------------------------------------"<<endl;
            cout<<"                                                              Room Number : "<<re[i].roomNum_reserve<<endl;
            cout<<"                                                              Booking Day : "<<re[i].day_reserve<<endl;
            cout<<"                                                              Number OF Beds : "<< re[i].Bed << endl;
            cout<<"                                                              Status : " << re[i].ReserveStatus<<endl;
            cout<<"                                                          ------------------------------------"<<endl;
            cout<<"                                                              PRESS A KEY TO BACK TO MENU ";
            cin>>ch;
            menu();
        }
    }
     for(int i=0;i<RejC;i++){ // search beine sefareshat rej
        if(TrackingCode==rej[i].ReserveCode){
            flag=1;
            cout<<"                                                                    Your Request " <<endl ;
            cout<<"                                                          ------------------------------------"<<endl;
            cout<<"                                                              Room Number : "<<rej[i].roomNum_reserve<<endl;
            cout<<"                                                              Booking Day : "<<rej[i].day_reserve<<endl;
            cout<<"                                                              Number OF Beds : "<< rej[i].Bed << endl;
            cout<<"                                                              Status : " << rej[i].ReserveStatus<<endl;
            cout<<"                                                          ------------------------------------"<<endl;
            cout<<"                                                              PRESS A KEY TO BACK TO MENU ";
            cin>>ch;
            menu();
        }
    }
    
    
    
    
    
    
    
    
    
    
    if(flag==0){ // agar sefareshi yaft nashod
        cout<<"                                                                  No Find Request\n";
        cout<<"                                                             PRESS A KEY TO BACK TO MENU";
        cin>>ch;
        menu();
    }
}
void EditEmployeesProfile(int indexEmp){ // edit employee profile by employee
//    int flag=0;
    char ch;
    system("cls");
    cout<<"                                                               First Name : "<<e[indexEmp].firstName<<endl;
    cout<<"                                                               Last Name : "<<e[indexEmp].lastName<<endl;
    cout<<"                                                               UserName : "<<e[indexEmp].user<<endl;
    cout<<"                                                               Password : "<<e[indexEmp].pass<<endl;
    cout<<"                                                               Date OF Birth : "<<e[indexEmp].birthday<<endl;
    cout<<"                                                       Do You Want Edit Your Profile ? (y/n) ";
    cin>>ch;
    cout<<endl;
    if(ch=='y'){ // daryaft moshakhasat jadid
//        flag=1;
        cout<<"                                                               New First Name : ";
        cin>>e[indexEmp].firstName;
        cout<<"                                                               New Last Name : ";
        cin>>e[indexEmp].lastName;
        cout<<"                                                               New UserName : ";
        cin>>e[indexEmp].user;
        cout<<"                                                               New Password : ";
        cin>>e[indexEmp].pass;
        cout<<"                                                               Date OF Birth : ";
        cin>>e[indexEmp].birthday;
        cout<<endl;
        cout<<"                                                               Your Profile Updated\n\n";
        cout<<"                                                          Press A Key TO Back To Main Menu : ";
        cin>>ch;
        Employee(index);
    }
    else if(ch=='n'){
    	Employee(index);
	}
//    if(flag==0){
//        LoginEmp();
//    }

}
void EmployeeMenuForManager(){ // employee options for manager
    int x ; // select option
    char ch ;
    system("cls");

    gotoxy(35, 14);
    cout << "    _______________________________________________________________________________" << endl;
    gotoxy(35, 15);
    cout << "    |                                                                             | " << endl;
    gotoxy(35, 16);
    cout << "    |                          1 .  VIEW ROOMS                                    |" << endl;
    gotoxy(35, 17);
    cout << "    |                          2 .  REQUESTS                                      |" << endl;
    gotoxy(35, 18);
    cout << "    |                          3 .  HOTEL RESIDENTS                               |" << endl;
    gotoxy(35, 19);
    cout << "    |                          4 .  RESERVATION                                   |" << endl;
    gotoxy(35, 20);
    cout << "    |                          5 .  CHECK OUT                                     |" << endl;
    gotoxy(35, 21);
    cout << "    |                          6 .  BACK                                          |" << endl;
    gotoxy(35, 22);
    cout << "    |_____________________________________________________________________________|" << endl;
    gotoxy(35, 23);
    cout << "    |                       ^ Select The Option You Want ^                        |" << endl;
    gotoxy(35, 24);
    cout << "    |_____________________________________________________________________________|" << endl;
    cin>>x;
    switch(x){
        case 1 :
            system("cls");
            View_Rooms();
            cout<<"                                                             Enter The Key To Back To Employees Menu : ";
            cin>> ch;
            EmployeesMenu();
            break;
        case 2 :
            requests();
            break;
        case 3 :
            ResidentsList();
            break;
        case 4 :
            system("cls");
            ReserveRoom();
            break;
        case 5 :
            CheckOut();
            break;
        case 6 :
            ManagerMenu();
            break;
    }
}
void Employee(int index){ // safhe baz az login employees
    system("cls");
    int select;
    gotoxy(72, 10);
    cout <<"Welcome "<<e[index].firstName<<" "<<e[index].lastName<<"\n\n";
    gotoxy(40, 14);
    cout << "    ___________________________________________________________________________" << endl;
    gotoxy(40, 15);
    cout << "    |                                                                         | " << endl;
    gotoxy(40, 16);
    cout << "    |                          1 .  DASHBOARD                                 |" << endl;
    gotoxy(40, 17);
    cout << "    |                          2 .  MY PROFILE                                |" << endl;
    gotoxy(40, 18);
    cout << "    |                          3 .  LOGOUT                                    |" << endl;
    gotoxy(40, 19);
    cout << "    |_________________________________________________________________________|" << endl;
    gotoxy(40, 20);
    cout << "    |                       ^ Select The Type Of User ^                       |" << endl;
    gotoxy(40, 21);
    cout << "    |_________________________________________________________________________|" << endl;
    cin>>select;
    switch(select){
        case 1 :
            EmployeesMenu(); // mize kar employees
            break;
        case 2 :
            EditEmployeesProfile(index); // edit employees profile
            break;
        case 3 :
            menu();
            break ;
    }
}
void TrackingList(){ // list hame darkhast ha 
    char ch;
    int CancelCode;
    int flag=0,temp;
    system("cls");
    cout<<"                                                                       Your Request List: " <<endl ;
    cout<<"                                                            ---------------------------------------------"<<endl;
    for(int i=0;i<ResC;i++){
    cout<<"                                                              Room Number : "<<re[i].roomNum_reserve<<endl;
    cout<<"                                                              Booking Day : "<<re[i].day_reserve<<endl;
    cout<<"                                                              Number OF Beds : "<< re[i].Bed << endl;
    cout<<"                                                              Status : " << re[i].ReserveStatus<<endl;
    cout<<"                                                              Tracking Code : " <<re[i].ReserveCode << endl;
    cout<<"                                                            ---------------------------------------------"<<endl;
    }
    for(int i=0;i<RejC;i++){
    cout<<"                                                              Room Number : "<<rej[i].roomNum_reserve<<endl;
    cout<<"                                                              Booking Day : "<<rej[i].day_reserve<<endl;
    cout<<"                                                              Number OF Beds : "<< re[i].Bed << endl;
    cout<<"                                                              Status : " << rej[i].ReserveStatus<<endl;
    cout<<"                                                              Tracking Code : " <<rej[i].ReserveCode << endl;
    cout<<"                                                            ---------------------------------------------"<<endl;
    }
    cout<<"                                                             You Can Cancel Your Request By Entering The "<<endl; 
	cout<<"                                                             Tracking Code For Unconfirmed Requests (y/n) ";
    cin>>ch;
    if(ch=='y'){ // ba zadan 'y' karbar mitune sefareshi ke hanooz accept ya reject nashode ro cancel kone
    cout<<"                                                          Entre The Tracking Code For Cancel Request : ";
    	cin>>CancelCode;
    	cout<<endl;
    for(int i=0;i<ResC;i++){
    	if (CancelCode==re[i].ReserveCode && re[i].ReserveStatus=="Pending"){ // peyda kardan sefareshi ke mikhaym cancel 
    	// she va hatman bayad pending bashe
    		re[i].ReserveStatus="Canceled";  
    		flag=1;
            cout<<"                                                                    Yor Request Canceled "<<endl;
            cout<<"                                                                 Press A Key To Back To Menu ";
            for(int j=0;j<Rc;j++){
            	if(re[i].roomNum_reserve==r[j].roomNumber){
            		r[j].status="Empty";
            		// bad az cancel shodan sefaresh otagh dobare empty mishe az halat pending
				}
			}
			for(temp;temp<ResC;temp++){
				re[temp]=re[temp+1]; // delete request after cancle
				resident[temp]=resident[temp+1];
			}
			ResC--;
			
    		cin>>ch;
    		menu();
		}
	
	}
   
	}
	if(ch=='n'){ 
		flag=1;
	cout<<"                                                                    PRESS A KEY TO BACK TO MENU  ";
    cin>>ch;
    menu();	
	}
    
 if(flag==0){// agar request peyda nashod
         	cout<<"                                                                         No Find Request "<<endl;
            cout<<"                                                                   Press A Key To Back To Menu ";
    		cin>>ch;
    		
    		menu();	
		}
}
void ReadFile(){
	
	
//	read file
	
	
    ifstream file1;  // employee
    file1.open("Employees.txt", ios::in);
    file1 >> Ec ;
    for (int i = 0; i < Ec; ++i) {

        file1 >> e[i].firstName >> e[i].lastName >> e[i].user >> e[i].pass >> e[i].id >>
		e[i].jobTitle>>e[i].payments>>e[i].birthday;

    }
    file1.close(); // end employee
    
    
    
    ifstream file2;  //room
    file2.open("Rooms.txt", ios::in);
    file2 >> Rc ;
    for (int i = 0; i < Rc; ++i) {

       file2 >> r[i].roomNumber >> r[i].beds>> r[i].rent>> r[i].roomDes>> r[i].p.heater>>
		r[i].p.cooler>> r[i].p.window>> r[i].p.commode>> r[i].p.internet>>r[i].status;

    }
    file1.close(); // end room
    
     
    ifstream file3;  //Reserve
    file3.open("Reserves.txt", ios::in);
    file3 >> ResC ;
    for (int i = 0; i < ResC; ++i) {

        file3 >> re[i].roomNum_reserve >> re[i].Bed >> re[i].day_reserve >> re[i].ReserveStatus >> re[i].ReserveCode 
        >> re[i].flag ;
        for(int j=0;j<re[i].Bed;j++){
        file3 >> resident[i].first_Name[j] >>resident[i].last_Name[j] >>resident[i].i_d[j]>>resident[i].flag;	
		}
    }
    file3.close(); // end Reserve
   
}

void PrintFile() {
    
    // print file

    ofstream file1;   // employee
    file1.open("Employees.txt", ios::out);
    file1 << Ec;
    for (int i = 0; i < Ec; ++i) {
      	
     file1<<"  " << e[i].firstName<<"  "<< e[i].lastName<<"  " << e[i].user<<"  " << e[i].pass<<"  " << e[i].id<<"  " <<
		e[i].jobTitle<<"  " << e[i].payments<<"  " << e[i].birthday  << endl;
    }
    file1.close(); // end employee
    
    
   ofstream file2;   // room
    file2.open("Rooms.txt", ios::out);
    file2 << Rc;
    for (int i = 0; i < Rc; ++i) {
    	
        file2<<"  " << r[i].roomNumber<<"  " << r[i].beds<<"  " << r[i].rent<<"  " << r[i].roomDes<<"  " << r[i].p.heater<<"  " <<
		r[i].p.cooler<<"  " << r[i].p.window<<"  " << r[i].p.commode<<"  " << r[i].p.internet<<"  "<<r[i].status <<endl;
    }
    file2.close();// end room
    
    
       ofstream file3;   // Reserve
    file3.open("Reserves.txt", ios::out);
    file3 << ResC;
    for (int i = 0; i < ResC; ++i) {
    file3<<"  " << re[i].roomNum_reserve<<"  " << re[i].Bed<<"  " << re[i].day_reserve<<"  " <<
	 re[i].ReserveStatus<<"  " << re[i].ReserveCode <<"  "<<re[i].flag<<endl;
	for(int j=0;j<re[i].Bed;j++){
        file3 <<"  "<< resident[i].first_Name[j] <<"  "<<resident[i].last_Name[j] <<"  "<<resident[i].i_d[j]<<"  "<<resident[i].flag<<endl;	
	}
	file3<<endl;
    }
    file3.close();//end reserve
    
    
}
void LoginManager(){ // panele login baraye modir
	string User;
    string Pass;
    char ch;

    int select,flag=0;
    
    system("cls");
    cout << endl << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << setw(85) << "USERNAME : ";
    cin >> User;
    cout << setw(85) << "PASSWORD : ";
    cin >> Pass;
   
        if(m.ManagerUser==User && m.ManagerPass==Pass ){
            t=0;
            flag=1;
            system("cls");
            Manager();
        }
    
    if(flag == 0){ // if user or pass eshtebah bood
            cout<<"\n\n";
            setColor(4);
        cout<< "                                                                     Wrong UserName Or Password \n\n";
            setColor(7);
        cout<<endl;
        cout<<"                                                    Press (n) And Back To Menu Or Press (y) To Go To Login Panel ";
        cin>>ch;
        if(ch=='y'){
        LoginManager();	
		}
        else if(ch=='n'){
        menu();	
		}
    }
}

