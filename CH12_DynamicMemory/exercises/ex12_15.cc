/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_15.cpp
 * Rewrite the first exercise to use a lambda (§ 10.3.2, p.388)
 * in place of the end_connection function.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std:: string;

#include <memory>
using std::shared_ptr;

struct Destination
{
	Destination(string _ip, short _port) : ip(_ip), port(_port) { }

	string ip;
	short port;
};

struct Connection
{
	Connection(string _ip, short _port) : ip(_ip), port(_port) { }

	string ip;
	short port;
};

Connection connect(Destination* pDest)
{
	shared_ptr<Connection> pConn(new Connection(pDest->ip, pDest->port));

	// ...

	cout << "Creat connection(" << pConn.use_count() << ")" << endl;

	return *pConn;
}

void disconnect(Connection pConn)
{
	// ...

	cout << "Close connection(" << pConn.ip << ":" << pConn.port << ")" << endl;
}


void f(Destination& d)
{
    Connection conn = connect(&d);
    shared_ptr<Connection> p(&conn, [](Connection* p) { disconnect(*p); });
    cout << "connecting now(" << p.use_count() << ")" << endl;
}

int main(int argc, char const *argv[])
{
	Destination dest("202.118.176.67", 3316);
    f(dest);

	return 0;
}
