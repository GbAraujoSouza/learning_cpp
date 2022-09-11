#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
    private:
        string Name;
        string OwnerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;

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

        string GetName() {
            return Name;
        }
        
        void SetName(string new_name) {
            Name = new_name;  
        }
};

int main()
{
    YouTubeChannel ytChannel("CodeBeauty", "Saldina");
    ytChannel.PublishVideo("C++ For Beginners");
    ytChannel.PublishVideo("C++ OOP Tutorial");
    YouTubeChannel ytChannel2("AmySings", "Amy");

    // Write out the object attributes
    ytChannel.Unsubscribe();
    cout << ytChannel.GetName() << endl;
    ytChannel.SetName("TrueCodeBeauty");
    cout << ytChannel.GetName() << endl;


    return 0;
}