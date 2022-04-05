// A class that regroups important data for each function

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class FunctionData
{
protected:
    unordered_map<string, int> offsets;
    unordered_map<string, int> types;
    vector<string> vars;
    int lastVarPosition;

public:

    FunctionData() : lastVarPosition(0){};

    unordered_map<string, int> getOffsets(){
        return offsets;
    };

    int getLastVarPosition(){
        return lastVarPosition;
    }

    unordered_map<string, int> getTypes(){
        return types;
    };

    vector<string> getVars(){
        return vars;
    };
};