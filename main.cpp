#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>
using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "Nobita@123";
const char* DB = "student";

class Database {
protected:
    MYSQL* conn;

public:
    Database() {
        conn = mysql_init(NULL);
        if (!mysql_real_connect(conn, HOST, USER, PW, DB, 3306, NULL, 0)) {
            cout << "ERROR: " << mysql_error(conn) << endl;
        } else {
            cout << "LOGGED IN !!!" << endl;
        }
        Sleep(3000);
    }

    virtual ~Database() {
        mysql_close(conn);
    }
};

class StudentDatabase : public Database {
public:
    void insertData() {
        system("cls");
        string ID, NAME, CONTACT, GRADE, ADDRESS;
        cout << endl << endl;
        cout << "ENTER ID: ";
        cin >> ID;
        cout << endl;
        cout << "ENTER NAME: ";
        cin >> NAME;
        cout << endl;
        cout << "ENTER CONTACT: ";
        cin >> CONTACT;
        cout << endl;
        cout << "ENTER GRADE: ";
        cin >> GRADE;
        cout << endl;
        cout << "ENTER ADDRESS: ";
        cin >> ADDRESS;

        string ins = "INSERT INTO student(ID, NAME, CONTACT, GRADE, ADDRESS) values('" + ID + "','" + NAME + "','" + CONTACT + "','" + GRADE + "','" + ADDRESS + "')";
        if (mysql_query(conn, ins.c_str())) {
            cout << endl;
            cout << mysql_error(conn) << endl;
        } else {
            cout << "DATA INSERTED SUCCESSFULLY" << endl;
        }
        Sleep(3000);
    }

    void deleteData() {
        system("cls");
        string id;
        cout << "ENTER ID: ";
        cin >> id;
        string del = "DELETE FROM student WHERE ID='" + id + "'";
        if (mysql_query(conn, del.c_str())) {
            cout << "ERROR: " << mysql_error(conn);
        } else {
            cout << "DATA DELETED SUCCESSFULLY";
        }
        Sleep(3000);
    }

    void updateData() {
        system("cls");
        string id, grade;
        cout << "ENTER ID: ";
        cin >> id;
        cout << "ENTER NEW GRADE: ";
        cin >> grade;
        string upd = "UPDATE student SET GRADE='" + grade + "' WHERE ID= '" + id + "'";
        if (mysql_query(conn, upd.c_str())) {
            cout << "ERROR: " << mysql_error(conn);
        } else {
            cout << "DATA UPDATED SUCCESSFULLY";
        }
        Sleep(3000);
    }

    void readData() {
        system("cls");
        string get = "SELECT * FROM student";
        if (mysql_query(conn, get.c_str())) {
            cout << "ERROR: " << mysql_error(conn);
        } else {
            MYSQL_RES* result = mysql_store_result(conn);
            if (result) {
                int num = mysql_num_fields(result);
                MYSQL_ROW row;
                cout << "ID \t\t NAME \t\t CONTACT \t\t GRADE \t\t ADDRESS" << endl;
                cout << "-----------------------------------------------------" << endl;
                while ((row = mysql_fetch_row(result))) {
                    for (int i = 0; i < num; i++) {
                        cout << row[i] << "\t\t";
                    }
                    cout << endl;
                }
                mysql_free_result(result);
            }
            Sleep(10000);
        }
    }
};

int main() {
    StudentDatabase db;
    bool exit = false;
    while (!exit) {
        system("cls");
        int val;
        cout << endl;
        cout << "WELCOME TO MYSQL DATABASE" << endl;
        cout << "*************************" << endl;
        cout << "1. INSERT DATA" << endl;
        cout << "2. DELETE DATA" << endl;
        cout << "3. UPDATE DATA" << endl;
        cout << "4. READ DATA" << endl;
        cout << "5. EXIT" << endl;
        cout << "ENTER CHOICE: ";
        cin >> val;

        switch (val) {
            case 1:
                db.insertData();
                break;
            case 2:
                db.deleteData();
                break;
            case 3:
                db.updateData();
                break;
            case 4:
                db.readData();
                break;
            case 5:
                system("cls");
                exit = true;
                cout << "BYE..";
                Sleep(3000);
                break;
            default:
                cout << "INVALID OUTPUT";
                Sleep(3000);
                break;
        }
    }
    return 0;
}
