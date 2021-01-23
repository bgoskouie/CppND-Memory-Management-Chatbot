#include "graphnode.h"
#include "graphedge.h"

GraphEdge::GraphEdge(int id)
{
    _id = id;
}

void GraphEdge::SetChildNode(GraphNode *childNode)
{
    _childNode = childNode;
}

void GraphEdge::SetParentNode(GraphNode *parentNode)
{
    _parentNode = parentNode;
}

void GraphEdge::AddToken(std::string token)
{
    _keywords.push_back(token);
}

GraphEdge::GraphEdge(const GraphEdge& source) {
    std::cout << "GraphEdge copy constructor" << std::endl;
    _childNode = source._childNode;
    _parentNode = source._parentNode;
    _id = source._id;
    for (std::string kw : source._keywords) {
        _keywords.push_back(kw);
    }
}

GraphEdge& GraphEdge::operator=(const GraphEdge& source) {
    std::cout << "GraphEdge copy Assignment Operator" << std::endl;
    if (this == &source) {
        return *this;
    }
    _childNode = source._childNode;
    _parentNode = source._parentNode;
    _id = source._id;
    _keywords.clear();
    for (std::string kw : source._keywords) {
        _keywords.push_back(kw);
    }
    return *this;
}

GraphEdge::GraphEdge(GraphEdge&& source) {
    std::cout << "GraphEdge Move constructor" << std::endl;
    _childNode = source._childNode;
    _parentNode = source._parentNode;
    _id = source._id;
    for (std::string kw : source._keywords) {
        _keywords.push_back(kw);
    }
    source._childNode = nullptr;
    source._parentNode = nullptr;
    source._id = 0;
    source._keywords.clear();
}

GraphEdge& GraphEdge::operator=(GraphEdge&& source) {
    std::cout << "GraphEdge Move Assignment Operator" << std::endl;
    if (this == &source) {
        return *this;
    }
    _childNode = source._childNode;
    _parentNode = source._parentNode;
    _id = source._id;
    _keywords.clear();
    for (std::string kw : source._keywords) {
        _keywords.push_back(kw);
    }
    source._childNode = nullptr;
    source._parentNode = nullptr;
    source._id = 0;
    source._keywords.clear();
    return *this;
}