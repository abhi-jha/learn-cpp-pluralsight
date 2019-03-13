#include <iostream>
#include "sqlite3.h"
#include "Handle.h"
#include "SQLite.h"

int test_sqlite_with_classes();
int test1(){
    ConnectionHandle connection;
    int result = sqlite3_open(":memory:", connection.Set());

    if (SQLITE_OK != result)
    {
        printf("%s\n", sqlite3_errmsg(connection.Get()));
        return result;
    }
}
int test2(){
    try
    {
        ConnectionHandle connection;

        if (SQLITE_OK != sqlite3_open(":memory:", connection.Set()))
        {
            throw Exception(connection.Get());
        }
    }
    catch (Exception const & e)
    {
        printf("%s (%d)\n", e.Message.c_str(), e.Result);
    }
}

int main() {

    sqlite3* connenction = nullptr;

    int result = sqlite3_open(":memory:", &connenction);

    std::cout<<result<<std::endl;

    if(SQLITE_OK != result){
        std::cout<<sqlite3_errmsg(connenction)<<"\n";
        sqlite3_close(connenction);
        return  result;
    }

    sqlite3_stmt* query = nullptr;

    result = sqlite3_prepare_v2(connenction, "select 'Hello World!'", -1, &query, nullptr);

    std::cout<<result<<std::endl;


    if(SQLITE_OK != result){
        std::cout<<sqlite3_errmsg(connenction)<<"\n";
        sqlite3_close(connenction);
        return  result;
    }

    while(SQLITE_ROW == sqlite3_step(query)){
        std::cout<<sqlite3_column_text(query,0);
    }

    sqlite3_finalize(query);
    sqlite3_close(connenction);

    test_sqlite_with_classes();
    test1();
    test2();
    return 0;
}

int test_sqlite_with_classes(){
    sqlite3* connection = nullptr;

    int result = sqlite3_open(":memory:", &connection);

    if(SQLITE_OK != result){
        std::cout<<sqlite3_errmsg(connection);
        sqlite3_close(connection);
        return result;
    }

    sqlite3_close(connection);
}