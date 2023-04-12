#include <GDSerial.hpp>
#include <string>

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

void GDSerial::setPort(String port){
    ser.setPort(port.ascii().get_data());
}

String GDSerial::getPort(){
    return String(ser.getPort().c_str());
}

void GDSerial::setBaudrate(int baudrate){
    ser.setBaudrate(baudrate);
}

int GDSerial::getBaudrate(){
    return ser.getBaudrate();
}

void GDSerial::setTimeout(PoolIntArray timeouts){
    tout = serial::Timeout(timeouts[0], timeouts[1], timeouts[2], timeouts[3], timeouts[4]);
    ser.setTimeout(tout);
}

PoolIntArray GDSerial::getTimeout(){
    PoolIntArray timeouts;
    timeouts.append(tout.inter_byte_timeout);
    timeouts.append(tout.read_timeout_constant);
    timeouts.append(tout.read_timeout_multiplier);
    timeouts.append(tout.write_timeout_constant);
    timeouts.append(tout.write_timeout_multiplier);
}

void GDSerial::setBytesize(int bytesize){
    ser.setBytesize(static_cast<serial::bytesize_t>(bytesize));
}

int GDSerial::getBytesize(){
    return static_cast<int>(ser.getBytesize());
}

void GDSerial::setParity(int parity){
    ser.setParity(static_cast<serial::parity_t>(parity));
}

int GDSerial::getParity(){
    return static_cast<int>(ser.getParity());
}

void GDSerial::setStopbits(int stopbits){
    ser.setStopbits(static_cast<serial::stopbits_t>(stopbits));
}

int GDSerial::getStopbits(){
    return static_cast<int>(ser.getStopbits());
}

void GDSerial::setFlowcontrol(int flowcontrol){
    ser.setFlowcontrol(static_cast<serial::flowcontrol_t>(flowcontrol));
}

int GDSerial::getFlowcontrol(){
    return static_cast<int>(ser.getFlowcontrol());
}

void GDSerial::flush(){
    ser.flush();
}

void GDSerial::flushInput(){
    ser.flushInput();
}

void GDSerial::flushOutput(){
    ser.flushOutput();
}

void GDSerial::sendBreak(int duration){
    ser.sendBreak(duration);
}

void GDSerial::setBreak(bool level){
    ser.setBreak(level);
}

void GDSerial::setRTS(bool level){
    ser.setRTS(level);
}

void GDSerial::setDTR(bool level){
    ser.setDTR(level);
}

bool GDSerial::waitForChange(){
    return ser.waitForChange();
}

bool GDSerial::getCTS(){
    return ser.getCTS();
}

bool GDSerial::getDSR(){
    return ser.getDSR();
}

bool GDSerial::getRI(){
    return ser.getRI();
}

bool GDSerial::getCD(){
    return ser.getCD();
}

void GDSerial::open(){
    ser.open();
}

bool GDSerial::isOpen(){
    return ser.isOpen();
}

void GDSerial::close(){
    ser.close();
}

int GDSerial::available(){
    return ser.available();
}

bool GDSerial::waitReadable(){
    return ser.waitReadable();
}

void GDSerial::waitByteTimes(int count){
    return ser.waitByteTimes(count);
}

PoolByteArray GDSerial::read(int size){
    PoolByteArray data;
    uint8_t *buffer = new uint8_t[size];
    size_t len = ser.read(buffer, size);
    for(int i = 0; i < len; ++i){
        data.append(buffer[i]);
    }
    return data;
}

String GDSerial::readString(int size){
    std::string buffer;
    ser.read(buffer, size);
    return String(buffer.c_str());
}

String GDSerial::readLine(int size, String eol);
PoolStringArray GDSerial::readLines(int size, String eol);

int GDSerial::write(PoolByteArray data);
int GDSerial::writeString(String data);
