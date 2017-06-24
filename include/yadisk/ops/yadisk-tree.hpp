#ifndef TREE_HPP
#define TREE_HPP

#include "Client.hpp"
#include "Tree.hpp"

using na

using yadisk::Client;
using yadisk::ops::Tree;
 
namespace yadisk 
{
namespace ops {
 
/**
Получение слепка диска
\param[in] ссылка на client-yadisk
\param[in] путь
\return возвращает дерево - слепок диска
**/
  auto tree(Client& client, path home = ‘/’) -> Tree&;
 
 

  
}
}

#endif
