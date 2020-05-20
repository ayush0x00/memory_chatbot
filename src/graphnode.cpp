#include "graphedge.h"
#include "graphnode.h"
#include <iostream>


GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

//     delete _chatBot;

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

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
//     std::unique_ptr<GraphEdge> edge1(std::move(edge));
//     std::unique_ptr<GraphEdge>* temp = new std::unique_ptr<GraphEdge>(edge);
//     _childEdges.push_back(std::move(*temp));
  _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
//   std::cout << "Here1\n";
    _chatBot = std::move(chatbot);
//   _chatBot.getChatLogic()->SetChatbotHandle(&_chatBot);
    _chatBot.SetCurrentNode(this);
//   std::cout << "Here10\n";
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
//   ChatBot _chatBot = ChatBot("../images/chatbot.png");
//   std::cout << "Here5\n";
    newNode->MoveChatbotHere(std::move(_chatBot));
//     _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}
