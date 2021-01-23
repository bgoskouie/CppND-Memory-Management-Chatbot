#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_
#include <memory>       // BO3
#include <vector>
#include <string>
#include "chatgui.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    // std::vector<GraphNode *> _nodes;  // BO: chatlogic owns nodes
    std::vector<std::unique_ptr<GraphNode>> _nodes;    // BO3
    std::vector<GraphEdge *> _edges;  // BO: you will have to change the ownership of edges from chatLogic to the nodes

    ////
    //// EOF STUDENT CODE

    // data handles (not owned)     // BO: chatlogic has a handle to this
    // GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    // constructor / destructor
    ChatLogic();
    ~ChatLogic();

    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatbotHandle(ChatBot *chatbot);

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap *GetImageFromChatbot();        // BO: this retrieves the image of chatbot so it can be displaed by GUI
};

#endif /* CHATLOGIC_H_ */