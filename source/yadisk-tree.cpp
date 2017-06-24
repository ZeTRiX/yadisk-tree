using yadisk::ops::Resource;
using yadisk::ops::Tree;
using yadisk::Client;
using std::string;

#include "yadisk/ops/yadisk-tree.hpp"


auto ops::tree(Client& client, path home = ‘/’) -> Tree&
{
  Tree* client_tree = new Tree;
 
recursive_add(client_tree, "/");
return *client_tree;
}
	
void recursive_add(Tree& input, string path, yadisk::ops::Node* parent = NULL)
{
	json data = client.info();
	Resource rsc(data);

	yadisk::ops::Node* node = input.add_child(rsc, parent);

	for (int32_t i = 0; i < data["_embedded"]["total"].get<int32_t>(); i++)
		if (data["_embedded"]["items"][i]["type"].get<string>() == "dir") {
			if (path[path.size() - 1] == '/')
				recursive_add(input, path + data["_embedded"]["items"][i]["name"].get<string>(), node);
			else
				recursive_add(input, path + "/" + data["_embedded"]["items"][i]["name"].get<string>(), node);
		}

}
