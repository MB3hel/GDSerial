#pragma once

#include <Godot.hpp>
#include <Reference.hpp>

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
    String readString();
    String readLine(int size, String eol);
    PoolStringArray readLines(int size, String eol);

    int write(PoolByteArray data);
    int writeString(String data);
    // -------------------------------------------------------------------------

private:
    serial::Serial ser;
};