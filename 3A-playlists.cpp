#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
    int users;
    int songs;
    std::map<std::string, int> playlist;
    std::cin >> users;
    for (int i = 0; i < users; i++)
    {
        std::cin >> songs;
        while (songs--)
        {
            std::string song;
            std::cin >> song;
            playlist[song]++;
        }
    }

    std::map<std::string, int> filteredPlaylist;
    for (auto& pair : playlist)
    {
        if (pair.second == users)
        {
            filteredPlaylist[pair.first] = pair.second;
        }
    }

    std::cout << filteredPlaylist.size() << '\n';
    for (auto& pair : filteredPlaylist)
    {
        std::cout << pair.first << ' ';
    }

    return 0;
}