#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <filesystem>

std::mutex myMutex;         // Mutex for protecting shared data access
int myTotalFiles = 0;      // Total count of files
int myTotalDirectories = 0; // Total count of directories

void CountFilesAndDirectories(const std::filesystem::path& dirPath) {
    int localFiles = 0;          // Local count of files in this directory
    int localDirectories = 0;    // Local count of subdirectories in this directory

    // Iterate through the contents of the current directory
    for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
        if (entry.is_regular_file()) {
            localFiles++;
        } else if (entry.is_directory()) {
            localDirectories++;
            CountFilesAndDirectories(entry.path()); // Recursively count files and subdirectories
        }
    }

    // Update total counts using mutex to avoid data race
    std::lock_guard<std::mutex> myLock(myMutex);
    myTotalFiles += localFiles;
    myTotalDirectories += localDirectories;

    // Print counts for the current directory
    std::cout << "Directory: " << dirPath << "\n";
    std::cout << "Files: " << localFiles << ", Directories: " << localDirectories << "\n";
}

int main() {
    std::string myRootDirectory = "/path/to/your/directory"; // Replace with the actual directory path
    std::thread myThread(CountFilesAndDirectories, std::filesystem::path(myRootDirectory));

    myThread.join();

    // Print the total counts for the entire directory tree
    std::cout << "Total Files: " << myTotalFiles << ", Total Directories: " << myTotalDirectories << "\n";

    return 0;
}
