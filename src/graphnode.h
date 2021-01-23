#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    std::vector<GraphEdge *> _childEdges;  // edges to subsequent nodes
                                // BO: student code needs to change ownership of childEdges from chatLogic to GraphNode
                                // BO: but in the starting code edges are all managed in chatLogic

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes
    ChatBot *_chatBot;          // BO: a handle to chatBot. It is nullptr if the chatbot is not currently residing in the current node.
                                // BO: when chatbot moves away from a node it will be invalidated again!

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;  // BO: currently there is only one answer for each node, but for future extension, you can have multiple answers
                                        // BO: and randomize the answer to one of the answers available in every node.
                                        // BO: For the fun of it try adding a few more answers to the .txt file and see what happens.
public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list    // BO: token is an answer
    void AddEdgeToParentNode(GraphEdge *edge);
    void AddEdgeToChildNode(GraphEdge *edge);

    //// STUDENT CODE
    ////

    void MoveChatbotHere(ChatBot *chatbot);     // BO: I think this should move the chatbot to this node.

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */