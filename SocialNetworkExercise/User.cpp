#include "User.h"
#include <iostream>

void User::init(const unsigned int id, const std::string& username, unsigned int age)
{
    this->id = id;
    this->username = username;
    this->age = age;
    this->lst.init();
}

void User::clear()
{
    lst.clear();
}

unsigned int User::getID() const
{
    return this->id;
}

std::string User::getUserName() const
{
    return this->username;
}

unsigned int User::getAge() const
{
    return age;
}

DevicesList& User::getDevices()
{
    return this->lst;
}

void User::addDevice(Device newDevice)
{
    lst.add(newDevice);
}

bool User::checkIfDevicesAreOn() const
{
    DeviceNode* curr = lst.get_first();
    if (curr == nullptr)  // list is empty
    {
        return true;
    }
    while (curr != nullptr)
    {
        if (!curr->get_data().isActive())
        {
            return false;
        }
        curr = curr->get_next();
    }
    return true;
}
