#include "ProxyMessageServer.h"
#include "RealMessageServer.h"
#include <string>

int main () {
    ProxyMessageServer pms = new ProxyMessageServer();
    pms.connect();
    std::string s = "Hello world";
    pms.message(s);
    pms.disconnect();
    return 0;
}
