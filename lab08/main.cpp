#include <iostream>
#include <string>
using namespace std;

class Device {

protected:
    string name;
    int id;

public:
    Device() {
        name = "";
        id = 0;
    }

    Device(string _name) {
        name = _name;
        id = 0;
    }

    void rename(string _name) {
        name = _name;
    }

    virtual void mount(int _id) = 0;
    virtual void show() = 0;

};

class HardDisk : public Device {

public:
    HardDisk(string _name) : Device(_name) { }

    void mount(int _id) {
        id = _id;
    }

    void show() {
        cout << "Device<" << id << ">: " << "<HD>" << name << endl;
    }
};

class CdRom : public Device {

public:
    CdRom(string _name) : Device(_name) {}

    void mount(int _id) {
        id = _id;
    }

    void show() {
        cout << "Device<" << id << ">: " << "<CD>" << name << endl;
    }

};

class Host {

private:
    int device_count;
    Device *devices[10];

public:
    Host() {
        device_count = 1;
    }

    void showCount() {
        cout << "The number of mounted device is " << device_count << endl;
    }

    void mount(Device *device) {
        devices[device_count] = device;
        device->mount(device_count++);
        device->show();
    }

    void show() {
        for (int i = 1; i < device_count; ++i) {
            devices[i]->show();
        }
    }

};

int main() {
    HardDisk *hardDisks[3];
    CdRom *cdRoms[3];
    Host host;
    cout << "Part 1." << endl;
    host.showCount();
    hardDisks[0] = new HardDisk("Western Digital-750G");
    hardDisks[1] = new HardDisk("HITACHI-500G");
    hardDisks[2] = new HardDisk("SEAGATE-750G");
    cdRoms[0] = new CdRom("ASUS-E1818A");
    cdRoms[1] = new CdRom("SONY-1642");
    cdRoms[2] = new CdRom("PHILIPS-SPD2514");
    hardDisks[0]->show();
    hardDisks[1]->show();
    hardDisks[2]->show();
    cdRoms[0]->show();
    cdRoms[1]->show();
    cdRoms[2]->show();
    cout << "Part 2." << endl;
    host.mount(hardDisks[0]);
    host.mount(cdRoms[1]);
    host.mount(cdRoms[2]);
    host.mount(hardDisks[1]);
    host.mount(hardDisks[2]);
    host.mount(cdRoms[0]);
    cout << "Part 3." << endl;
    hardDisks[1]->rename("MAXTOR-160G");
    cdRoms[0]->rename("PHILIPS-SPD2514");
    host.show();
    return 0;
}
