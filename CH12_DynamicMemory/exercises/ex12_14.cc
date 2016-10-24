/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_14.cpp
 * Write your own version of a function that uses a shared_ptr
 * to manage a connection.
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

void end_connection(Connection* pConn)
{
	disconnect(*pConn);
}


void f(Destination& d)
{
    Connection conn = connect(&d);
    shared_ptr<Connection> p(&conn, end_connection);
    cout << "connecting now(" << p.use_count() << ")" << endl;
}

int main(int argc, char const *argv[])
{
	Destination dest("202.118.176.67", 3316);
    f(dest);

	return 0;
}
