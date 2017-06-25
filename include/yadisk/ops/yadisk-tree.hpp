#ifndef TREE_HPP
#define TREE_HPP

#include <yadisk/ops/Client.hpp>
#include <yadisk/ops/Tree.hpp>
#include <url/path.hpp>

//using yadisk::Client;
//using yadisk::ops::Tree;


 

using namespace yadisk; 
using namespace url;
 /**
 Получение слепка диска
 \param[in] ссылка на client-yadisk
 \param[in] путь
 \return возвращает дерево - слепок диска
 **/
  
  ops::Tree tree(Client& client, path home = (char)'/') ;

 /**
 Добавление данных
 \param[in] указатель на дерево
 \param[in] путь
 **/ 
  void recursive_add(ops::Tree& input, string path, ops::Node* parent = NULL);

#endif
