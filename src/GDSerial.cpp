#include <GDSerial.hpp>
#include <string>

void GDSerial::_init(){

}

void GDSerial::_register_methods() {
    register_method("isError", &GDSerial::isError);
    register_method("errorMessage", &GDSerial::errorMessage);
    register_method("list_ports", &GDSerial::list_ports);
    register_method("setPort", &GDSerial::setPort);
    register_method("getPort", &GDSerial::getPort);
    register_method("setBaudrate", &GDSerial::setBaudrate);
    register_method("getBaudrate", &GDSerial::getBaudrate);
    register_method("setTimeout", &GDSerial::setTimeout);
    register_method("getTimeout", &GDSerial::getTimeout);
    register_method("simpleTimeout", &GDSerial::simpleTimeout);
    register_method("timeoutMax", &GDSerial::timeoutMax);
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

    // Enum nonsense
    godot_property_usage_flags no_editor_or_storage = static_cast<godot_property_usage_flags>(0);

    // bytesize_t
    register_property<GDSerial, int>("BYTESIZE_FIVEBITS", &GDSerial::enumReadonlySetter, &GDSerial::get_bytesize_fivebits, serial::bytesize_t::fivebits, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);
    register_property<GDSerial, int>("BYTESIZE_SIXBITS", &GDSerial::enumReadonlySetter, &GDSerial::get_bytesize_sixbits, serial::bytesize_t::sixbits, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);
    register_property<GDSerial, int>("BYTESIZE_SEVENBITS", &GDSerial::enumReadonlySetter, &GDSerial::get_bytesize_sevenbits, serial::bytesize_t::sevenbits, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);
    register_property<GDSerial, int>("BYTESIZE_EIGHTBITS", &GDSerial::enumReadonlySetter, &GDSerial::get_bytesize_eightbits, serial::bytesize_t::eightbits, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);

    // parity_t
    register_property<GDSerial, int>("PARITY_NONE", &GDSerial::enumReadonlySetter, &GDSerial::get_parity_none, serial::parity_t::parity_none, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);
    register_property<GDSerial, int>("PARITY_EVEN", &GDSerial::enumReadonlySetter, &GDSerial::get_parity_even, serial::parity_t::parity_even, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);
    register_property<GDSerial, int>("PARITY_ODD", &GDSerial::enumReadonlySetter, &GDSerial::get_parity_odd, serial::parity_t::parity_odd, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);
    register_property<GDSerial, int>("PARITY_MARK", &GDSerial::enumReadonlySetter, &GDSerial::get_parity_mark, serial::parity_t::parity_mark, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);
    register_property<GDSerial, int>("PARITY_SPACE", &GDSerial::enumReadonlySetter, &GDSerial::get_parity_space, serial::parity_t::parity_space, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);

    // stopbits_t
    register_property<GDSerial, int>("STOPBITS_ONE", &GDSerial::enumReadonlySetter, &GDSerial::get_stopbits_one, serial::stopbits_t::stopbits_one, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);
    register_property<GDSerial, int>("STOPBITS_TWO", &GDSerial::enumReadonlySetter, &GDSerial::get_stopbits_two, serial::stopbits_t::stopbits_two, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);
    register_property<GDSerial, int>("STOPBITS_ONE_POINT_FIVE", &GDSerial::enumReadonlySetter, &GDSerial::get_stopbits_one_point_five, serial::stopbits_t::stopbits_one_point_five, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);

    // flowcontrol_t
    register_property<GDSerial, int>("FLOWCONTROL_NONE", &GDSerial::enumReadonlySetter, &GDSerial::get_flowcontrol_none, serial::flowcontrol_t::flowcontrol_none, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);
    register_property<GDSerial, int>("FLOWCONTROL_HARDWARE", &GDSerial::enumReadonlySetter, &GDSerial::get_flowcontrol_hardware, serial::flowcontrol_t::flowcontrol_hardware, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);
    register_property<GDSerial, int>("FLOWCONTROL_SOFTWARE", &GDSerial::enumReadonlySetter, &GDSerial::get_flowcontrol_software, serial::flowcontrol_t::flowcontrol_software, GODOT_METHOD_RPC_MODE_DISABLED, no_editor_or_storage);
}

bool GDSerial::isError(){
    bool ret = _isError;
    _isError = false;
    return ret;
}

String GDSerial::errorMessage(){
    return _errorMessage;
}

PoolStringArray GDSerial::list_ports(){
    try{
        PoolStringArray arr;
        for(const auto &port : serial::list_ports()){
            arr.append(String(port.port.c_str()));
        }
        return arr;
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return PoolStringArray();
    }
}

void GDSerial::setPort(String port){
    try{
        ser.setPort(port.ascii().get_data());
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

String GDSerial::getPort(){
    try{
        return String(ser.getPort().c_str());
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return String();
    }
}

void GDSerial::setBaudrate(int baudrate){
    try{
        ser.setBaudrate(baudrate);
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

int GDSerial::getBaudrate(){
    try{
        return ser.getBaudrate();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return 0;
    }
}

void GDSerial::setTimeout(PoolIntArray timeouts){
    try{
        if(timeouts.size() < 5){
            return;
        }
        tout = serial::Timeout(timeouts[0], timeouts[1], timeouts[2], timeouts[3], timeouts[4]);
        ser.setTimeout(tout);
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

PoolIntArray GDSerial::getTimeout(){
    try{
        PoolIntArray timeouts;
        timeouts.append(tout.inter_byte_timeout);
        timeouts.append(tout.read_timeout_constant);
        timeouts.append(tout.read_timeout_multiplier);
        timeouts.append(tout.write_timeout_constant);
        timeouts.append(tout.write_timeout_multiplier);
        return timeouts;
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return PoolIntArray();
    }
}

PoolIntArray GDSerial::simpleTimeout(int timeout){
    try{
        auto t = serial::Timeout::simpleTimeout(timeout);
        PoolIntArray timeouts;
        timeouts.append(t.inter_byte_timeout);
        timeouts.append(t.read_timeout_constant);
        timeouts.append(t.read_timeout_multiplier);
        timeouts.append(t.write_timeout_constant);
        timeouts.append(t.write_timeout_multiplier);
        return timeouts;
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return PoolIntArray();
    }
}

int GDSerial::timeoutMax(){
    try{
        return serial::Timeout::max();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return 0;
    }
}

void GDSerial::setBytesize(int bytesize){
    try{
        ser.setBytesize(static_cast<serial::bytesize_t>(bytesize));
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

int GDSerial::getBytesize(){
    try{
        return static_cast<int>(ser.getBytesize());
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return 0;
    }
}

void GDSerial::setParity(int parity){
    try{
        ser.setParity(static_cast<serial::parity_t>(parity));
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

int GDSerial::getParity(){
    try{
        return static_cast<int>(ser.getParity());
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return 0;
    }
}

void GDSerial::setStopbits(int stopbits){
    try{
        ser.setStopbits(static_cast<serial::stopbits_t>(stopbits));
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

int GDSerial::getStopbits(){
    try{
        return static_cast<int>(ser.getStopbits());
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return 0;
    }
}

void GDSerial::setFlowcontrol(int flowcontrol){
    try{
        ser.setFlowcontrol(static_cast<serial::flowcontrol_t>(flowcontrol));
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

int GDSerial::getFlowcontrol(){
    try{
        return static_cast<int>(ser.getFlowcontrol());
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return 0;
    }
}

void GDSerial::flush(){
    try{
        ser.flush();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

void GDSerial::flushInput(){
    try{
        ser.flushInput();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

void GDSerial::flushOutput(){
    try{
        ser.flushOutput();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

void GDSerial::sendBreak(int duration){
    try{
        ser.sendBreak(duration);
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

void GDSerial::setBreak(bool level){
    try{
        ser.setBreak(level);
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

void GDSerial::setRTS(bool level){
    try{
        ser.setRTS(level);
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

void GDSerial::setDTR(bool level){
    try{
       ser.setDTR(level); 
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

bool GDSerial::waitForChange(){
    try{
        return ser.waitForChange();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return false;
    }
}

bool GDSerial::getCTS(){
    try{
        return ser.getCTS();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return false;
    }
}

bool GDSerial::getDSR(){
    try{
        return ser.getDSR();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return false;
    }
}

bool GDSerial::getRI(){
    try{
        return ser.getRI();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return false;
    }
}

bool GDSerial::getCD(){
    try{
        return ser.getCD();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return false;
    }
}

void GDSerial::open(){
    try{
        ser.open();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

bool GDSerial::isOpen(){
    try{
        return ser.isOpen();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return false;
    }
}

void GDSerial::close(){
    try{
        ser.close();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

int GDSerial::available(){
    try{
        return ser.available();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return 0;
    }
}

bool GDSerial::waitReadable(){
    try{
        return ser.waitReadable();
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return false;
    }
}

void GDSerial::waitByteTimes(int count){
    try{
        ser.waitByteTimes(count);
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
    }
}

PoolByteArray GDSerial::read(int size){
    try{
        PoolByteArray data;
        uint8_t *buffer = new uint8_t[size];
        size_t len = ser.read(buffer, size);
        for(size_t i = 0; i < len; ++i){
            data.append(buffer[i]);
        }
        delete[] buffer;
        return data;
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return PoolByteArray();
    }
}

String GDSerial::readString(int size){
    try{
        std::string buffer;
        ser.read(buffer, size);
        return String(buffer.c_str());
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return String();
    }
}

String GDSerial::readline(int size, String eol){
    try{
        auto str = ser.readline(size, eol.ascii().get_data());
        return String(str.c_str());
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return String();
    }
}

PoolStringArray GDSerial::readlines(int size, String eol){
    try{
        PoolStringArray lines;
        auto strs = ser.readlines(size, eol.ascii().get_data());
        for(const auto &str : strs){
            lines.append(String(str.c_str()));
        }
        return lines;
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return PoolStringArray();
    }
}

int GDSerial::write(PoolByteArray data){
    try{
        uint8_t *buffer = new uint8_t[data.size()];
        for(size_t i = 0; i < data.size(); ++i){
            buffer[i] = data[i];
        }
        int ret = ser.write(buffer, data.size());
        delete[] buffer;
        return ret;
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return 0;
    }
    
}

int GDSerial::writeString(String data){
    try{
        return ser.write(std::string(data.ascii().get_data()));
    }catch(const std::exception &e){
        _isError = true;
        _errorMessage = e.what();
        return 0;
    }
}




// Enum nonsense

// Used by all (since these are readonly properties)
void GDSerial::enumReadonlySetter(int value){
    // Do nothing. This is a fake setter.
    (void) value;
}

// bytesize_t
int GDSerial::get_bytesize_fivebits(){
    return static_cast<int>(serial::bytesize_t::fivebits);
}

int GDSerial::get_bytesize_sixbits(){
    return static_cast<int>(serial::bytesize_t::sixbits);
}

int GDSerial::get_bytesize_sevenbits(){
    return static_cast<int>(serial::bytesize_t::sevenbits);
}

int GDSerial::get_bytesize_eightbits(){
    return static_cast<int>(serial::bytesize_t::eightbits);
}

// parity_t
int GDSerial::get_parity_none(){
    return static_cast<int>(serial::parity_t::parity_none);
}

int GDSerial::get_parity_odd(){
    return static_cast<int>(serial::parity_t::parity_odd);
}

int GDSerial::get_parity_even(){
    return static_cast<int>(serial::parity_t::parity_even);
}

int GDSerial::get_parity_mark(){
    return static_cast<int>(serial::parity_t::parity_mark);
}

int GDSerial::get_parity_space(){
    return static_cast<int>(serial::parity_t::parity_space);
}

// stopbits_t
int GDSerial::get_stopbits_one(){
    return static_cast<int>(serial::stopbits_t::stopbits_one);
}

int GDSerial::get_stopbits_two(){
    return static_cast<int>(serial::stopbits_t::stopbits_two);
}

int GDSerial::get_stopbits_one_point_five(){
    return static_cast<int>(serial::stopbits_t::stopbits_one_point_five);
}

// flowcontrol_t
int GDSerial::get_flowcontrol_none(){
    return static_cast<int>(serial::flowcontrol_t::flowcontrol_none);
}

int GDSerial::get_flowcontrol_software(){
    return static_cast<int>(serial::flowcontrol_t::flowcontrol_software);
}

int GDSerial::get_flowcontrol_hardware(){
    return static_cast<int>(serial::flowcontrol_t::flowcontrol_hardware);
}
