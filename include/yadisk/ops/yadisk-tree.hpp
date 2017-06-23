#ifndef YADISK-TREE_HPP
#define YADISK-TREE_HPP

#include <yadisk/ops/Tree.hpp>
#include <yadisk/url/path.hpp>
#include <yadisk/Client.hpp>

using yadisk::Client;
using yadisk::path;
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
  Tree tree(Client& client, path home = ‘/’) ;
}
}

#endif
