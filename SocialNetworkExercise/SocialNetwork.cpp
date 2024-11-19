#include "SocialNetwork.h"

void SocialNetwork::init(std::string networkName, int minAge)
{
	this->networkName = networkName;
	this->minAge = minAge;
	prLst.init();
}

void SocialNetwork::clear()
{
	this->prLst.clear();
	this->networkName = "";
}

std::string SocialNetwork::getNetworkName() const
{
	return this->networkName;
}

int SocialNetwork::getMinAge() const
{
	return this->minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < this->minAge)
	{
		return false;
	}
	prLst.add(profile_to_add);
	return true;
}

std::string SocialNetwork::getWindowsDevices()
{
    std::string windowsRegisteredDevices;
    ProfileNode* currProfile = this->prLst.get_first();
    while (currProfile != nullptr)//the ProfileNode list
    {
        DeviceNode* currDevice = currProfile->get_data().getOwner().getDevices().get_first();
        while (currDevice != nullptr)
        {
            if (currDevice->get_data().getOS().find("Windows") != std::string::npos)// Check if the device OS contains "WINDOWS"
            {
                windowsRegisteredDevices += "[" + std::to_string(currDevice->get_data().getID()) + ", " + currDevice->get_data().getOS() + "], ";
            }
            currDevice = currDevice->get_next();
        }
        currProfile = currProfile->get_next();
    }
    if (!windowsRegisteredDevices.empty())
    {
        windowsRegisteredDevices.pop_back();
        windowsRegisteredDevices.pop_back();
    }
    return windowsRegisteredDevices;
}
