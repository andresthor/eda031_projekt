/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** messagehandler.h
** Handles "low protocol level" communication. Used both by server and client.
**
** Authors: Andres Saemundsson, Anton Friberg, Oscar Gunneson
** -------------------------------------------------------------------------*/
#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

/*-------------------------------------
    I N C L U D E S
-------------------------------------*/
#include <string>
#include "connection.h"
#include "logger.h"
#include "protocol.h"


/*-------------------------------------
    D E C L A R A T I O N S
-------------------------------------*/
// namespace not recommended in header files
/*-------------------------------------
    C L A S S   D E F
-------------------------------------*/

class MessageHandler {
public:
  MessageHandler(Connection &c );
  ~MessageHandler();
  void sendInt(int value);
  void sendIntParameter(int param);
  void sendStringParameter(std::string param);
  int recvCode();
  int recvInt();
  int recvIntParameter();
  std::string recvStringParameter();
  void sendCode(int code);

protected:

private:
  Connection *conn;  // the connection
  void sendByte(int i);
  int recvByte();


};

#endif
