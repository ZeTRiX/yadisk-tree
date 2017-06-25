#ifndef TREE_HPP
#define TREE_HPP

include "Client.hpp"
include "Tree.hpp"
#include "url/path.hpp"

//using yadisk::Client;
//using yadisk::ops::Tree;
 
namespace yadisk 
{
namespace ops {
 
/**
Ïîëó÷åíèå ñëåïêà äèñêà
\param[in] ññûëêà íà client-yadisk
\param[in] ïóòü
\return âîçâðàùàåò äåðåâî - ñëåïîê äèñêà
**/
  Tree tree(Client& client, path home = '/') ;
 
 /**
Äîáàâëåíèå äàííûõ
\param[in] óêàçàòåëü íà äåðåâî
\param[in] ïóòü
**/ 
 
 //void recursive_add(Tree& input, string path, yadisk::ops::Node* parent = NULL)
 
  
}
}

#endif
