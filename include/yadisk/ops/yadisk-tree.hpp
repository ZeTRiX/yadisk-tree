#ifndef TREE_HPP
#define TREE_HPP

#include <yadisk/ops/Client.hpp>
#include <yadisk/ops/Tree.hpp>
#include <url/path.hpp>

using yadisk::Client;
using url::path;
using yadisk::ops::Tree;

namespace yadisk 
{
    namespace ops 
    {
		/**
		Получение слепка диска
		\param[in] ссылка на client-yadisk
		\param[in] путь
		\return возвращает дерево - слепок диска
		**/
 	  	Tree tree(Client& client, path home = "/");

		/**
		Добавление данных
		\param[in] указатель на дерево
		 \param[in] путь
		 **/ 
		void recursive_add(Tree& input, json& data, std::string path, Node& parent = nullptr);
    }
}
#endif
