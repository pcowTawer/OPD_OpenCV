#include <queue>
#include <string>
#include "database.h"
#include "sqlite-amalgamation-3400000/sqlite3.h"

//shared buffer+++++++++++++++++++++++++++++++++
static std::queue<string>shared_buffer_ColName;
static std::queue<string>shared_buffer_argv;
//shared buffer---------------------------------


bool DBase::empty(){
    return shared_buffer_argv.empty();
}

static int callback(void * data, int argc, char ** argv, char ** azColName)
{
    //argc = The number of columns in a row.
    //argv = Array of rows representing fields in a row.
    //azColName = Array of rows representing column names.

    for (int i = 0; i < argc; ++i) {
        shared_buffer_ColName.push(azColName[i]);
        shared_buffer_argv.push(argv[i]);
    }
    return 0;
}

DBase::DBase(const std::string& dataBasePath)
{
    if(sqlite3_open(dataBasePath.c_str() , &DB)){
        throw "ERROR SQLITE_IS_NOT_OK";
    }

}

DBase::~DBase(){
    sqlite3_close(DB);
}

bool DBase::execute(const DBase& targetDB, const std::string& command)
{
    if(sqlite3_exec(targetDB.DB, command.c_str(), callback, nullptr, nullptr)){
        return -1;
    }
     return 0;
}

pair<std::string, std::string> DBase::get_the_first_response_received()
{
    pair<std::string, std::string> result;
    if(shared_buffer_ColName.empty()||shared_buffer_argv.empty()){
        return result = {"NULL", "NULL"};
    }
    result = {shared_buffer_ColName.front(), shared_buffer_argv.front()};
    shared_buffer_ColName.pop();
    shared_buffer_argv.pop();
    return result;
}

bool DBase::clearbus(){
    while(!shared_buffer_ColName.empty()){
        shared_buffer_ColName.pop();
        shared_buffer_argv.pop();
    }
    return true;
}
