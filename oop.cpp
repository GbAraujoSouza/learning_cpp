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
    int ContentQuality;
public:
    YouTubeChannel(string name, string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
        ContentQuality = 0;
    }

    void GetInfo() {
        cout << "Name: " << Name << endl;
        cout << "Owner: " << OwnerName << endl;
        cout << "Subscribers: " << SubscribersCount << endl;
        cout << "Content Quality: " << ContentQuality << endl;
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
        CookingLevel = 1;
    }
    void Practice() {
        cout << Name << " is practicing cooking, learning new recipes, experimenting with spices...\n";
        CookingLevel++;
        ContentQuality++;
    }
    void GetInfo() {
        YouTubeChannel::GetInfo();
        cout << "Cooking Level: " << CookingLevel << endl;
    }
};


class SingersYouTubeChannel:public YouTubeChannel
{
private:
    int musicLevel;

public:
    SingersYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName)
    {
        musicLevel = 1;
    }

    void GetInfo() {
        YouTubeChannel::GetInfo();
        cout << "Music Level: " << musicLevel << endl;
    }

    void Practice()
    {
        cout << OwnerName << " is taking singing classes, learning new songs, learning how to dance..." << endl;
        musicLevel++;
    }
};


int main()
{
    CookingYouTubeChannel cookingYtChannel("Amy Cooks", "Amy");
    SingersYouTubeChannel singersYtChannel("JohnSings", "John");

    cookingYtChannel.Practice();
    singersYtChannel.Practice();
    
    YouTubeChannel* yt1 = &cookingYtChannel;
    YouTubeChannel* yt2 = &singersYtChannel;

    yt1->GetInfo();
    yt2->GetInfo();

    return 0;
}