#ifndef GRAPHEDGE_H_
#define GRAPHEDGE_H_

#include <iostream>  // BO4 for std::cout
#include <vector>
#include <string>

class GraphNode; // forward declaration

class GraphEdge     // BO:  edges don't own any data. They are just intermediatary between two nodes (child node and parent node)
{
private:
    // data handles (not owned)
    GraphNode *_childNode;
    GraphNode *_parentNode;

    // proprietary members
    int _id;
    // BO: these are the _keywords associated with the current edge
    //     which help us decide whether we want to
    //     move along this edge or along another edge.
    //     Depending on the query which is posted by the user in the chatbot.
    std::vector<std::string> _keywords; // list of topics associated with this edge


public:
    // constructor / desctructor
    GraphEdge(int id);
    // BO4:
    ~GraphEdge() {};
    GraphEdge(const GraphEdge& source);
    GraphEdge& operator=(const GraphEdge& source);
    GraphEdge(GraphEdge&& source);
    GraphEdge& operator=(GraphEdge&& source);

    // getter / setter
    int GetID() { return _id; }
    void SetChildNode(GraphNode *childNode);
    void SetParentNode(GraphNode *parentNode);
    GraphNode *GetChildNode() { return _childNode; }
    std::vector<std::string> GetKeywords() { return _keywords; }

    // proprietary functions
    void AddToken(std::string token);
};

#endif /* GRAPHEDGE_H_ */