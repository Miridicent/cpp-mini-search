#include <iostream>
#include <filesystem>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Mini Search Engine starting...\n";
    
    if (argc < 2)
    {
        cout << "Error: Please provide a directory path." << endl;
        return 1;
    }
    
    cout << "Searching directory : " << argv[1] << endl;

    filesystem::path directoryPath = argv[1];

    if (! filesystem::exists(directoryPath))
    {
        cout << "Error! Directory not found." << endl;
        return 1;
    }
    
    else if (! filesystem::is_directory(directoryPath))
    {
        cout << "Error! This is not a directory." << endl;
        return 1;
    }

    for (const auto& entry : filesystem::directory_iterator(directoryPath))
    {
        if (filesystem::is_directory(entry.path()))
        {
            cout << "Directory: " << entry.path() << endl;
        }
        else
        {
            cout << "File: " << entry.path() << endl;
        }
    }

    return 0;
}