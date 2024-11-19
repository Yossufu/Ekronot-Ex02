#pragma once
#include "DeviceList.h"

class User
{
private:
	std::string username;
	unsigned int age;
	unsigned int id;
	DevicesList lst;
public:
	void init(const unsigned int id, const std::string& username, unsigned int age);
	void clear();
	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices();
	void addDevice(Device newDevice);
	bool checkIfDevicesAreOn() const;
};

