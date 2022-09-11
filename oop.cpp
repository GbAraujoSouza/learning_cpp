#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
private:
    int SubscribersCount;
    list<string> PublishedVideoTitles;
    
protected:
    string Name;
    string OwnerName;

public:
    YouTubeChannel(string name, string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
    }

    void GetInfo() {
        cout << "Name: " << Name << endl;
        cout << "Owner: " << OwnerName << endl;
        cout << "Subscribers: " << SubscribersCount << endl;
        cout << "Videos: "  << endl;

        // NEW THING!
        for (string i : PublishedVideoTitles){
            cout << "> " << i << endl;
        }
    }

    void Subscribe() {
        SubscribersCount++;
    }

    void Unsubscribe() {
        if (SubscribersCount > 0)
            SubscribersCount--;
    }

    void PublishVideo(string title) {
        PublishedVideoTitles.push_back(title);
    }

    // Getters
    string GetName() {
        return Name;
    }
    string GetOwnerName() {
        return OwnerName;
    }
    int GetSubscribersCount() {
        return SubscribersCount;
    }
    list<string> GetPublishedVideosTitles() {
        return PublishedVideoTitles;
    }

    void SetName(string new_name) {
        Name = new_name;  
    }
};


class CookingYouTubeChannel:public YouTubeChannel
{
private:
    int CookingLevel;
public:
    CookingYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName) {
        CookingLevel = 0;
    }
    void Practice() {
        cout << Name << " is practicing cooking, learning new recipes, experimenting with spices...\n";
        CookingLevel++;
    }
    void GetInfo() {
        cout << "Name: " << Name << endl;
        cout << "Owner: " << OwnerName << endl;
        cout << "Subscribers: " << GetSubscribersCount() << endl;
        cout << "Videos: "  << endl;
        // NEW THING!
        for (string i : GetPublishedVideosTitles()){
            cout << "> " << i << endl;
        }
        cout << "Cooking Level: " << CookingLevel << endl;
    }
};


int main()
{
    CookingYouTubeChannel cookingYtChannel("Amy Cooks", "Amy");

    cookingYtChannel.PublishVideo("Rice With Beans");
    cookingYtChannel.PublishVideo("Carbonara");
    for (int user = 0; user < 100; user++) {
        cookingYtChannel.Subscribe();
    }
    cookingYtChannel.Practice();
    cookingYtChannel.GetInfo();


    return 0;
}