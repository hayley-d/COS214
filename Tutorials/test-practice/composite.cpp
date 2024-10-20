/**
* Component class that defines common methods that the composite and leaf share.
*/
class FileSystemObjects {
public:
    virtual void open() = 0;
    virtual void move() = 0;
    virtual void deleteObject() = 0;
};

/**
* Leaf of the file system comonents is the file, a single file.
*/
class File : public FileSystemObjects {
public:
    void open() override {
        std::cout << "Opening file\n";
    }

    void move() override {
        std::cout << "Moving file\n";
    }

    void deleteObject() override {
        std::cout << "Deleting file\n";
    }
};

class Directory : public FileSystemObject {
private:
    std::vector<FileSystemObjects*> files;
public:
    void open() override {
        std::cout << "Opening directory\n";
        for(FileSystemObjects* obj : files) {
            obj->open();
        }
    }

    void move() override {
        std::cout << "Moving directory\n";
        for(FileSystemObjects* obj : files) {
            obj->move();
        }
    }

    void deleteObject() override {
        std::cout << "Deleting directory\n";
        for(FileSystemObjects* obj : files) {
            obj->deleteObject();
        }
    }

};

int main() {

    return 0;
}
