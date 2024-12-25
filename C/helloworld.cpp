#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

void printReport(int* data)
{
    std::cout << "Report: " << *data << "\n";
}

void printReport2(std::shared_ptr<int> data)
{
    std::cout << "Report: " << data.use_count() << " " << *data << "\n";
}

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    //msg.
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    try
    {
        int* ptr;
        ptr = new int();
        *ptr = 25;
        printReport(ptr);
        delete ptr;
        ptr = 0;
        //return 0;
    }
    catch (std::bad_alloc& ba)
    {
        std::cout << "ERROR: Out of memory\n";
        return 1;
    }

    try
    {
        std::shared_ptr<int> ptr2(new int());
        *ptr2 = 25;
        printReport2(ptr2);
        return 0;
    }
    catch (std::bad_alloc& ba)
    {
        std::cout << "ERROR: Out of memory\n";
        return 1;
    }
}
