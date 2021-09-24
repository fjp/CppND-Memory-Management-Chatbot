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

    // A graphNode can own the ChatBot, so in my opinion it should be deleted here.
    // However, the following isn't working which is why I delete it in the (non-owning) ChatLogic
    // This is why we delete it here
    //if (_chatBot != nullptr)
    //{
    //    delete _chatBot;
    //    _chatBot = nullptr;
    //}
    

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
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////

// Task 5 : Moving the ChatBot
// create a local ChatBot instance on the stack
// use move semantics to pass the ChatBot instance into the root node
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // Task 5 : Moving the ChatBot
    // create a local ChatBot instance on the stack
    // use move semantics to pass the ChatBot instance into the root node
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // Task 4: Moving Smart Pointers
    // GraphEdge ownership belongs to GraphNodes not to ChatLogic.
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}