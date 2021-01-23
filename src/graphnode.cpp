#include <iostream>     // BO added for cout
#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    std::cout << "GraphNode Destructor id = " << _id << std::endl;
    // BO: BUG resolved: _chatBot is not owned by GraphNode so it should not get deleted here.
    // delete _chatBot;

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// BO4:
// void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)  // coming as a copy so taking transferring ownership here
                                                                    // it must be passed with std::move and move constructor of GraphEdge will be called.
{
    // _childEdges.push_back(edge);
    // BO4: unique_ptr guarantees that a single unique_ptr container has ownership of the held pointer!
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
// BO: This is called from another node. It should move the chatbot from another
// BO: node to this node.
// BO: and then set this node to be the current node.
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)    // BO: this node wants to move chatbot to another node (the function argument node)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source     // this node just lost the chatbot to another node.
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // BO4:
    // return _childEdges[index];
    return _childEdges[index].get();  // returning the raw pointer of the edge unique_ptr

    ////
    //// EOF STUDENT CODE
}