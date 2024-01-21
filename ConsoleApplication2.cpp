#include "stdafx.h"
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <mysql.h>
#include<stdio.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
	MYSQL* conn;

	conn = mysql_init(NULL);
	if (conn == NULL)
	{

		fprintf(stderr, "Error: can'tcreate MySQL-descriptor\n");

	}

	if (!mysql_real_connect(conn, "localhost", "root", "root", "test", NULL, NULL, 0))
	{

		fprintf(stderr, "Error: can'tconnecttodatabase %s\n", mysql_error(conn));
	}
	else
	{

		fprintf(stdout, "Success!\n");
	}

	mysql_close(conn);

	system("Pause");
	return 0;
}
#include"stdafx.h"
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<mysql.h>

usingnamespacestd;
int_tmain(intargc, _TCHAR* argv[])
{
	system("cls");
	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;
	int i = 0;
	conn = mysql_init(NULL);
	if (conn == NULL)
	{
		
		fprintf(stderr, "Error: can'tcreate MySQL-descriptor\n");
		
	}

	if (!mysql_real_connect(conn, "localhost", "root", "root", "test", NULL, NULL, 0))
	{

		fprintf(stderr, "Error: can'tconnecttodatabase %s\n", mysql_error(conn));
	}
	else
	{

		fprintf(stdout, "Success!\n");
	}
	mysql_set_character_set(conn, "utf8");
	cout << "connectioncharacterset: " << mysql_character_set_name(conn) << endl;

	mysql_query(conn, "SELECT id, text FROM mnu"); 

	if (res = mysql_store_result(conn)) {
		while (row = mysql_fetch_row(res)) {
			for (i = 0; i < mysql_num_fields(res); i++) {
				std::cout << row[i] << "\n"; 
			}
		}
	} elsefprintf(stderr, "%s\n", mysql_error(conn));

	mysql_close(conn);
	system("Pause");
	return 0;
}