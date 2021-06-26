#ifndef SERVERPROYECTO3DATOS2_HOFFMANHANDLER_H
#define SERVERPROYECTO3DATOS2_HOFFMANHANDLER_H

#include <string>

using namespace std;

class hoffmanHandler {
private:

    struct characterNode;
    struct dictionaryNode;

    string theText;
    string charList;
    string compressionAnswer;
    string binaryDirection;
    float charTimes;
    float probability;

    characterNode *listRoot = nullptr;
    characterNode *leftNode;
    characterNode *rightNode;

    dictionaryNode *dictionaryRoot = nullptr;

    void createcCharList();

    void createProbabilityCharList();

    void createThree();

    void addListNode(char character, float probability, bool isThreeNode);

    void createDicctionary(characterNode *node);

    void addDictionaryNode(char character, string direction);

    void convertTextToBytes();

    string searchCharInDictionary(char character);

    void createJSONAnwser();

    void deleteDictionary();

    
public:
    hoffmanHandler();
    ~hoffmanHandler();

    string huffmanAlgorithm(string text);

};



#endif //SERVERPROYECTO3DATOS2_JSONHANDLER_H