#ifndef DATABASE_H
#define DATABASE_H

#include "sqlite-amalgamation-3400000/sqlite3.h"
#include <string>


using namespace std;


class DBase
{
    sqlite3* DB;//создание базы данных
public:

    /// Opening the database.
    /// If you have opened several databases,
    /// then do not forget that the response from the database comes in one common queue.
    DBase(const std::string& dataBasePath);

    /// Executes a query command to the specified database. Returns 0 if everything is fine.
    static bool execute(const DBase& targetDB, const std::string& command);

    /// Receives the first response received from the database, and then erases it.
    /// Returns a tuple of 2 elements. 1 - shared_buffer_ColName.  2 - shared_buffer_argv
    static pair<std::string, std::string> get_the_first_response_received();

    static bool empty();

    static bool clearbus();
    ~DBase();
};

#endif // DATABASE_H
