#include <iostream>
#include <string>

 void processRow(int n)
 {
    int segmentsCount = 0;
    std::string resultString = "";

    int num;
    std::cin >> num;
    int minSegmentLength = num;
    int currentLength = 1;

    for (int i = 1; i < n; i++)
    {
        std::cin >> num;

        // If we're at max length, or the next num makes length too small 
        if (currentLength == minSegmentLength || num < currentLength + 1)
        {
            segmentsCount++;
            resultString += std::to_string(currentLength) + " ";
            currentLength = 1;
            minSegmentLength = num;
        }
        else
        {
            currentLength += 1;
            minSegmentLength = std::min(num, minSegmentLength);
        }
    }

    segmentsCount++;
    std::cout << segmentsCount << "\n";

    resultString += std::to_string(currentLength) + "\n";
    std::cout << resultString;
 }

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        processRow(n);
    }

    return 0;
}