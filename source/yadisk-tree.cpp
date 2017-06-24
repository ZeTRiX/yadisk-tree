#include "yadisk/ops/yadisk-tree.hpp"

auto ops::tree(Client& client, path home = ‘/’) -> Tree&
{
  Tree* client_tree = new Tree;
  
	json data = client.info();
  Resource rsc(data);
  
  yadisk::ops::Node* node = input.add_child(rsc, parent);
  
  for (int32_t i = 0; i < data["_embedded"]["total"].get<int32_t>(); i++)
		if (data["_embedded"]["items"][i]["type"].get<string>() == "dir") {
			if (path[path.size() - 1] == '/')
				tree(client, path + data["_embedded"]["items"][i]["name"].get<string>());
			else
				tree(client, path + "/" + data["_embedded"]["items"][i]["name"].get<string>());
  
	return *client_tree;
}
