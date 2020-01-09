#ifndef STRING_UTILITY
#define STRING_UTILITY
#include<string>
class StringUtility{
public:
    StringUtility(){}
    // default find symbol position return Left all  , if position is R return Right all
    std::string splitString(const std::string splitString , const std::string symbol , const std::string splitPosition = "L"){
        std::string result = "";
        std::size_t found = splitString.find_last_of(symbol);
        if(found!=std::string::npos){
            if(splitPosition!="L")
            result = splitString.substr(++found);
            else
            result = splitString.substr(0,found);
        }
        else
        result = splitString;
        return result;
    }
};
#endif