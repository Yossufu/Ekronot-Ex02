#pragma once
#include "UserList.h"
#include "Page.h"

class Profile
{
private:
	Page p;
	User owner;
	UserList lst;
public:
	void init(User owner);
	void clear();
	User getOwner() const;
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);
	std::string getPage() const;
	std::string getFriends();
	std::string getFriendsWithSameNameLength();
};