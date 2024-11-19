#include "Profile.h"

void Profile::init(User owner)
{
    this->owner = owner;
}

void Profile::clear()
{
    this->owner.clear();
    this->p.clearPage();
    this->lst.clear();
}

User Profile::getOwner() const
{
    return this->owner;
}

void Profile::setStatus(std::string new_status)
{
    this->p.setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
    this->p.addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
    this->lst.add(friend_to_add);
}

std::string Profile::getPage() const
{
    return "Status: " + this->p.getStatus() + "\n"
        + "*******************\n*******************\n"
        + this->p.getPosts();
}

std::string Profile::getFriends()
{
    std::string friends;
    UserNode* curr = this->lst.get_first();

    while (curr != nullptr)
    {
        friends += curr->get_data().getUserName() + ",";
        curr = curr->get_next();
    }
    // Remove the trailing comma if there are friends
    if (!friends.empty())
    {
        friends.pop_back();
    }
    return friends;
}

std::string Profile::getFriendsWithSameNameLength()
{
    std::string friends;
    UserNode* curr = this->lst.get_first();
    while (curr != nullptr)
    {
        if (curr->get_data().getUserName().length() == this->owner.getUserName().length())
        {
            friends += curr->get_data().getUserName() + ",";
        }
        curr = curr->get_next();
    }
    // Remove the trailing comma if there are friends
    if (!friends.empty())
    {
        friends.pop_back();
    }
    return friends;
}