#include <GDSerial.hpp>

void GDSerial::_init(){

}

void GDSerial::_register_methods() {
    // register_method("method", &SimpleClass::method);
    // register_property<SimpleClass, String>("base/name", &SimpleClass::_name, String("SimpleClass"));
    // register_property<SimpleClass, int>("base/value", &SimpleClass::set_value, &SimpleClass::get_value, 0);
}

PoolStringArray GDSerial::list_ports(){
    PoolStringArray arr;
    for(const auto &port : serial::list_ports()){
        arr.append(String(port.port.c_str()));
    }
    return arr;
}

void GDSerial::setPort(String port);
String GDSerial::getPort();
void GDSerial::setBaudrate(int baudrate);
int GDSerial::getBaudrate();
void GDSerial::setTimeout(PoolIntArray timeouts);
PoolIntArray GDSerial::getTimeout();
void GDSerial::setBytesize(int bytesize);
int GDSerial::getBytesize();
void GDSerial::setParity(int parity);
int GDSerial::getParity();
void GDSerial::setStopbits(int stopbits);
int GDSerial::getStopbits();
void GDSerial::setFlowcontrol(int flowcontrol);
int GDSerial::getFlowcontrol();

void GDSerial::flush();
void GDSerial::flushInput();
void GDSerial::flushOutput();
void GDSerial::sendBreak(int duration);
void GDSerial::setBreak(bool level);
void GDSerial::setRTS(bool level);
void GDSerial::setDTR(bool level);
bool GDSerial::waitForChange();
bool GDSerial::getCTS();
bool GDSerial::getDSR();
bool GDSerial::getRI();
bool GDSerial::getCD();

void GDSerial::open();
bool GDSerial::isOpen();
void GDSerial::close();

int GDSerial::available();

bool GDSerial::waitReadable();
void GDSerial::waitByteTimes(int count);

PoolByteArray GDSerial::read(int size);
String GDSerial::readString();
String GDSerial::readLine(int size, String eol);
PoolStringArray GDSerial::readLines(int size, String eol);

int GDSerial::write(PoolByteArray data);
int GDSerial::writeString(String data);
