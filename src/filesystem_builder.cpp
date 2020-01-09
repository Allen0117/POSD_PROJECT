#include "../inc/filesystem_builder.h"
#include "../inc/folder.h"
#include "../inc/file.h"
#include "../inc/link.h"
FileSystemBuilder* FileSystemBuilder::_instance = nullptr;
FileSystemBuilder::FileSystemBuilder(){}
FileSystemBuilder* FileSystemBuilder::instance()
{
    if(_instance == nullptr) _instance = new FileSystemBuilder();
    return _instance;
}
Node* FileSystemBuilder::getRoot()
{
    return _root;
}
void FileSystemBuilder::build(std::string path )
{
    DIR* root;
    struct dirent* dp;
    root = opendir(path.c_str());
    if (root == nullptr)
    {
        struct stat st;
        if(!(lstat(path.c_str(), &st)))
        {
            if(S_ISREG(st.st_mode))
            _root = new File(std::string(path));
            else if(S_ISLNK(st.st_mode))
            _root = new Link(std::string(path));
        }
        else
        {
            throw std::string("Node is not exist!");
        }
        
    }
    else
    {
        _root = new Folder(path);
        while((dp = readdir(root)) != NULL)
        {
                if(dp->d_type == DT_REG)
                _root->addChild(new File(std::string(path) + "/" + std::string(dp->d_name)));
                else if(dp->d_type == DT_DIR)
                {
                    if (std::string(dp->d_name) == "." || std::string(dp->d_name) == ".." );//delete . and .. 
                    else
                    {
                        Node* temp = _root;
                        build(std::string(path) + "/" + std::string(dp->d_name));
                        temp->addChild(_root);
                        _root = temp;
                    }
                    
                }
                else if(dp->d_type == DT_LNK)
                _root->addChild(new Link(std::string(path) + "/" + std::string(dp->d_name)));
        }

    }
    closedir(root);
}
