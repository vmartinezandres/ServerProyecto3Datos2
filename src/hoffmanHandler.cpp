#include "../include/hoffmanHandler.h"

hoffmanHandler::hoffmanHandler(){
}

hoffmanHandler::~hoffmanHandler(){
}

struct hoffmanHandler::characterNode {
    char character = NULL;
    float probability = 0;
    characterNode* next = nullptr;
    characterNode* left = nullptr;
    characterNode* right = nullptr;

};

struct hoffmanHandler::dictionaryNode {
    char character = NULL;
    string direction;
    dictionaryNode* next = nullptr;

};


string hoffmanHandler::huffmanAlgorithm(string text){
    theText = text;
    
    createcCharList();
    
    createProbabilityCharList();
    
    createThree();
    
    createDicctionary(listRoot);
    
    convertTextToBytes();
    
    createJSONAnwser();
    
    deleteDictionary();
    
    return compressionAnswer;

}

void hoffmanHandler::createcCharList(){

    charList = "";
    bool isAdded = true;
    for (int i = 0; i < theText.length(); i++) {
        if (i == 0) {
            charList += theText[i];
        }
        else {
            for (int j = 0; j < i; j++) {
                if (theText[i] == charList[j]) {
                    isAdded = false;
                }
            }
            if (isAdded) {
                charList += theText[i];
            }
            else {
                isAdded = true;
            }
        }
    }

}

void hoffmanHandler::createProbabilityCharList(){

    for (int i = 0; i < charList.length(); i++) {
        charTimes = 0;
        for (int j = 0; j < theText.length(); j++) {
            if (theText[j] == charList[i]) {
                charTimes++;
            }
        }
        probability = (charTimes / (theText.length() + 1));
                
        addListNode(charList[i], probability, false);
        
    }
    
    probability = (1.0 / (theText.length() + 1));
    addListNode('$', probability, false);

}

void hoffmanHandler::createThree(){
    while (listRoot->next != nullptr) {
        probability = listRoot->probability + listRoot->next->probability;
        addListNode(NULL, probability, true);
    }
    
    binaryDirection = "";

}

void hoffmanHandler::addListNode(char character, float probability, bool isThreeNode){

    // New Node
    characterNode *newNode = new characterNode();
    newNode->character = character;
    newNode->probability = probability;
        
    if (listRoot == nullptr) {
        
        listRoot = newNode;
    }
    else if (listRoot->next == nullptr) {
        // Left
        if (newNode->probability < listRoot->probability) {
            newNode->next = listRoot;
            listRoot = newNode;
        }
        // Right
        else {
            listRoot->next = newNode;
        }
        
    }
    else {
        // At least 2 nodes
        leftNode = listRoot;
        rightNode = listRoot->next;
        
        // The new node has the lowest probability
        if (newNode->probability < leftNode->probability) {
            newNode->next = leftNode;
            listRoot = newNode;
        }
        else {
            // Right of the head
            while (rightNode != nullptr) {
                
                if (newNode->probability < rightNode->probability) {
                    newNode->next = rightNode;
                    leftNode->next = newNode;
                    break;
                }
                else {
                    leftNode = rightNode;
                    rightNode = rightNode->next;
                    if (rightNode == nullptr) {
                        leftNode->next = newNode;
                    }
                }
            }
        }
        
    }
        
    if (isThreeNode) {
        newNode->left = listRoot;
        newNode->right = listRoot->next;
        
        listRoot = listRoot->next->next;
        
        newNode->left->next = nullptr;
        newNode->right->next = nullptr;

    }
}

void hoffmanHandler::createDicctionary(characterNode *node){

    if(node == nullptr) {
        binaryDirection = binaryDirection.substr(0, binaryDirection.length() - 1);
        return;
    }
    else {
        binaryDirection.append("0");
        createDicctionary(node->left);
                
        binaryDirection.append("1");
        createDicctionary(node->right);
        
        // Add it to the dictionary
        addDictionaryNode(node->character, binaryDirection);
        binaryDirection = binaryDirection.substr(0, binaryDirection.length() - 1);

        //Delete the node
        delete node;
    }
}

void hoffmanHandler::addDictionaryNode(char character, string direction){

    if (character != NULL) {
        dictionaryNode *newNode = new dictionaryNode();
        newNode->character = character;
        newNode->direction = direction;

        newNode->next = dictionaryRoot;
        dictionaryRoot = newNode;
    }

}

void hoffmanHandler::convertTextToBytes(){

    listRoot = nullptr;
    binaryDirection = "1";
    for (int i = 0; i < theText.length(); i++) {
        binaryDirection.append(searchCharInDictionary(theText[i]));
        
    }
    binaryDirection.append(searchCharInDictionary('$'));

}

string hoffmanHandler::searchCharInDictionary(char character){

    dictionaryNode *aux = dictionaryRoot;
    while (aux != nullptr) {
        if (aux->character == character) {
            return aux->direction;
        }
        else {
            aux = aux->next;
        }
    }
    return NULL;
}

void hoffmanHandler::createJSONAnwser(){
    dictionaryNode *aux = dictionaryRoot;
    
    compressionAnswer = "{\"message\" : ";
    compressionAnswer.append(binaryDirection + ", ");
    compressionAnswer.append("\"dictionary\" : [");
    while (aux->next != nullptr ) {
        compressionAnswer.append("{\"letter\" : \"");
        compressionAnswer.push_back(aux->character);
        compressionAnswer.append("\", \"bytes\" : \"" + aux->direction + "\"}, ");
        
        aux = aux->next;
    }
    
    compressionAnswer.append("{\"letter\" : \"");
    compressionAnswer.push_back(aux->character);
    compressionAnswer.append("\", \"bytes\" : \"" + aux->direction + "\"}]}");
        
    binaryDirection = "";

}

void hoffmanHandler::deleteDictionary(){

    dictionaryNode *aux;
    while (dictionaryRoot != nullptr) {
        aux = dictionaryRoot;
        dictionaryRoot = dictionaryRoot->next;
        delete aux;
    }

}