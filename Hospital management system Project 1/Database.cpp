#include "Database.h"
using namespace std;

Database::Database() {
    conn = mysql_init(NULL);
}

Database::~Database() {
    mysql_close(conn);
}

bool Database::connect() {
    if (mysql_real_connect(conn, "localhost", "root", "*Nov@2003", "hospital_db", 3306, NULL, 0)) {
        cout << "Connected to MySQL successfully!\n";
        return true;
    } else {
        cerr << "Connection failed: " << mysql_error(conn) << "\n";
        return false;
    }
}

void Database::savePatient(int id, string name, int age, string disease, string contact) {
    string query = "INSERT INTO patients (id, name, age, disease, contact) VALUES (" +
                   to_string(id) + ", '" + name + "', " + to_string(age) +
                   ", '" + disease + "', '" + contact + "')";

    if (mysql_query(conn, query.c_str())) {
        cerr << "Insert Error: " << mysql_error(conn) << "\n";
    }
}
