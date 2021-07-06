#include <stdio.h>
#include <sqlite3.h>

int my_sql_init (sqlite3 *db, sqlite3_stmt * stmt);

int main() {
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;
	const char * query = "SELECT * FROM student";
	
	result = sqlite3_open("test.db",&db);
	if (result != SQLITE_OK) {
		fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(db));
		return -1;
	}else {
		fprintf(stderr, "open database successful\n");
	}

	result = sqlite3_prepare(db, query, -1, &stmt, NULL);
	printf("result = %d\n", result);
	if (result != SQLITE_OK) {
		sqlite3_finalize(stmt);
		char * sql = "create TABLE student (id INT, name VARCHAR(128), password VARCHAR(128));";
		char * errmsg;
		sqlite3_exec(db, sql, NULL, NULL, &errmsg);
		fprintf(stderr, "create table successful\n");
	}else {
		sqlite3_finalize(stmt);
		char *sql = "INSERT INTO student (id,name,password) VALUES (2,'joy', 'asqw123');";
		char *errmsg;
		sqlite3_exec(db, sql, NULL, NULL, &errmsg);
		fprintf(stderr, "insert table successful\n");	
	}
			
	sqlite3_close(db);

	return 0;
}

int my_sql_init (sqlite3 *db, sqlite3_stmt * stmt){
	int result;
	result = sqlite3_open("base.db",&db);
	if (result != SQLITE_OK) {
		fprintf(stderr, "can't open database:%s\n", sqlite3_errmsg(db));
		return -1;
	}
	fprintf(stderr, "open database successful\n");
	return 0;
}

