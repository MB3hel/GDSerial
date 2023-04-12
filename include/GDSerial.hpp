#pragma once

#include <Godot.hpp>
#include <Reference.hpp>

#include <stdint.h>

#include <serial/serial.h>

using namespace godot;

class GDSerial : public Reference {
    GODOT_CLASS(GDSerial, Reference);
public:
    GDSerial() = default;

    // -------------------------------------------------------------------------
    // Godot / GDNative methods
    // -------------------------------------------------------------------------
    void _init();
    static void _register_methods();
    // -------------------------------------------------------------------------

    // -------------------------------------------------------------------------
    // GDSerial Instance functions (exposed to Godot)
    // -------------------------------------------------------------------------
    PoolStringArray list_ports();

    void setPort(String port);
    String getPort();
    void setBaudrate(int baudrate);
    int getBaudrate();
    void setTimeout(PoolIntArray timeouts);
    PoolIntArray getTimeout();
    PoolIntArray simpleTimeout(int timeout);
    int timeoutMax();
    void setBytesize(int bytesize);
    int getBytesize();
    void setParity(int parity);
    int getParity();
    void setStopbits(int stopbits);
    int getStopbits();
    void setFlowcontrol(int flowcontrol);
    int getFlowcontrol();

    void flush();
    void flushInput();
    void flushOutput();
    void sendBreak(int duration);
    void setBreak(bool level);
    void setRTS(bool level);
    void setDTR(bool level);
    bool waitForChange();
    bool getCTS();
    bool getDSR();
    bool getRI();
    bool getCD();

    void open();
    bool isOpen();
    void close();

    int available();

    bool waitReadable();
    void waitByteTimes(int count);

    PoolByteArray read(int size);
    String readString(int size);
    String readline(int size, String eol);
    PoolStringArray readlines(int size, String eol);

    int write(PoolByteArray data);
    int writeString(String data);

    // -------------------------------------------------------------------------

    // -------------------------------------------------------------------------
    // Enum stupidity
    // -------------------------------------------------------------------------
    // Used by all (since these are readonly properties)
    void enumReadonlySetter(int);

    // bytesize_t
    int get_bytesize_fivebits();
    int get_bytesize_sixbits();
    int get_bytesize_sevenbits();
    int get_bytesize_eightbits();

    // parity_t
    int get_parity_none();
    int get_parity_odd();
    int get_parity_even();
    int get_parity_mark();
    int get_parity_space();

    // stopbits_t
    int get_stopbits_one();
    int get_stopbits_two();
    int get_stopbits_one_point_five();

    // flowcontrol_t
    int get_flowcontrol_none();
    int get_flowcontrol_software();
    int get_flowcontrol_hardware();
    // -------------------------------------------------------------------------
    
private:
    serial::Serial ser;
    serial::Timeout tout;
};