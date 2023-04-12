#include <GDSerial.hpp>
#include <string>

void GDSerial::_init(){

}

void GDSerial::_register_methods() {
    register_method("list_ports", &GDSerial::list_ports);
    register_method("setPort", &GDSerial::setPort);
    register_method("getPort", &GDSerial::getPort);
    register_method("setBaudrate", &GDSerial::setBaudrate);
    register_method("getBaudrate", &GDSerial::getBaudrate);
    register_method("setTimeout", &GDSerial::setTimeout);
    register_method("getTimeout", &GDSerial::getTimeout);
    register_method("setBytesize", &GDSerial::setBytesize);
    register_method("getBytesize", &GDSerial::getBytesize);
    register_method("setParity", &GDSerial::setParity);
    register_method("getParity", &GDSerial::getParity);
    register_method("setStopbits", &GDSerial::setStopbits);
    register_method("getStopbits", &GDSerial::getStopbits);
    register_method("setFlowcontrol", &GDSerial::setFlowcontrol);
    register_method("getFlowcontrol", &GDSerial::getFlowcontrol);
    register_method("flush", &GDSerial::flush);
    register_method("flushInput", &GDSerial::flushInput);
    register_method("flushOutput", &GDSerial::flushOutput);
    register_method("sendBreak", &GDSerial::sendBreak);
    register_method("setBreak", &GDSerial::setBreak);
    register_method("setRTS", &GDSerial::setRTS);
    register_method("setDTR", &GDSerial::setDTR);
    register_method("waitForChange", &GDSerial::waitForChange);
    register_method("getCTS", &GDSerial::getCTS);
    register_method("getDSR", &GDSerial::getDSR);
    register_method("getRI", &GDSerial::getRI);
    register_method("getCD", &GDSerial::getCD);
    register_method("open", &GDSerial::open);
    register_method("isOpen", &GDSerial::isOpen);
    register_method("close", &GDSerial::close);
    register_method("available", &GDSerial::available);
    register_method("waitReadable", &GDSerial::waitReadable);
    register_method("waitByteTimes", &GDSerial::waitByteTimes);
    register_method("read", &GDSerial::read);
    register_method("readString", &GDSerial::readString);
    register_method("readline", &GDSerial::readline);
    register_method("readlines", &GDSerial::readlines);
    register_method("write", &GDSerial::write);
    register_method("writeString", &GDSerial::writeString);
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
    return timeouts;
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
    for(size_t i = 0; i < len; ++i){
        data.append(buffer[i]);
    }
    delete[] buffer;
    return data;
}

String GDSerial::readString(int size){
    std::string buffer;
    ser.read(buffer, size);
    return String(buffer.c_str());
}

String GDSerial::readline(int size, String eol){
    auto str = ser.readline(size, eol.ascii().get_data());
    return String(str.c_str());
}

PoolStringArray GDSerial::readlines(int size, String eol){
    PoolStringArray lines;
    auto strs = ser.readlines(size, eol.ascii().get_data());
    for(const auto &str : strs){
        lines.append(String(str.c_str()));
    }
    return lines;
}

int GDSerial::write(PoolByteArray data){
    uint8_t *buffer = new uint8_t[data.size()];
    for(size_t i = 0; i < data.size(); ++i){
        buffer[i] = data[i];
    }
    int ret = ser.write(buffer, data.size());
    delete[] buffer;
    return ret;
}

int GDSerial::writeString(String data){
    return ser.write(std::string(data.ascii().get_data()));
}
