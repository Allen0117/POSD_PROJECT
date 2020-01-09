#include "../inc/update_path_visitor.h"
#include "../inc/folder.h"
#include "../inc/file.h"
#include "../inc/link.h"
#include "../inc/string_utility.h"
#include <iostream>
#include <regex>
UpdatePathVisitor::UpdatePathVisitor():_oldFolderPath(""),_newFolderPath(""){}
void UpdatePathVisitor::visitFolder(Folder * folder)
{
    StringUtility su;
    std::string oldPathGetName = su.splitString(folder->getFilePath(),"\\/","R");
    std::string newName = folder->getFileName();
    if(oldPathGetName != newName){// 代表只是一個資料夾單純拜訪但要記住舊的名字和新的名字因為有可能底下有別資料要去更新
        std::string  newPath;
        if(oldPathGetName == folder->getFilePath()){
            newPath = newName;
        }
        else{
             newPath = su.splitString(folder->getFilePath(),"\\/") + "/" + newName;
        }      
        _oldFolderPath = folder->getFilePath();
        _newFolderPath = newPath;
        folder->setPath(newPath);
    }else{// 代表是資料夾裡的資料夾呼叫的因為上層的資料夾改路徑所以也要更改
        folder->setPath(replacePath(folder->getFilePath()));
    }
    Iterator* iter_folder = folder->createIterator();
    for (iter_folder->first(); !iter_folder->isDone(); iter_folder->next()){
        iter_folder->currentItem()->accept(this);
    }
}
void UpdatePathVisitor::visitFile(File * file)
{    
    StringUtility su;
    std::string oldPathGetName = su.splitString(file->getFilePath(),"\\/","R");
    std::string newName = file->getFileName();
    if(oldPathGetName != newName){// 代表只是一個資料夾單純拜訪但要記住舊的名字和新的名字因為有可能底下有別資料要去更新
        std::string  newPath;
        if(oldPathGetName == file->getFilePath())
            newPath = newName;
        else
            newPath = su.splitString(file->getFilePath(),"\\/") + "/" + newName;     
        file->setPath(newPath);
    }else{// 代表是資料夾裡的資料夾呼叫的因為上層的資料夾改路徑所以也要更改
        file->setPath(replacePath(file->getFilePath()));
    }
}
void UpdatePathVisitor::visitLink(Link * link)
{   
    StringUtility su;
    std::string oldPathGetName = su.splitString( link->getFilePath(),"\\/","R");
    std::string newName =  link->getFileName();
    if(oldPathGetName != newName){// 代表只是一個資料夾單純拜訪但要記住舊的名字和新的名字因為有可能底下有別資料要去更新
        std::string  newPath;
        if(oldPathGetName ==  link->getFilePath())
            newPath = newName;
        else
            newPath = su.splitString( link->getFilePath(),"\\/") + "/" + newName;     
        link->setPath(newPath);
    }else{// 代表是資料夾裡的資料夾呼叫的因為上層的資料夾改路徑所以也要更改
        link->setPath(replacePath(link->getFilePath()));
    }
}
std::string UpdatePathVisitor::replacePath(std::string currentPath)
{
    std::string newPath  = _newFolderPath;
    std::regex pattern(_oldFolderPath);
    std::smatch result;
    if(regex_search(currentPath , result, pattern))
    {
        newPath += result.suffix();
    }
    return newPath;
}