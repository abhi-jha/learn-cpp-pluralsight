#include <iostream>
#include "sqlite3.h"
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
    return 0;
}