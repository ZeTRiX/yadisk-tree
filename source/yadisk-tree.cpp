#include "yadisk/ops/yadisk-tree.hpp"

namespace yadisk
{
	namespace ops
	{	
		Tree tree(Client& client, path home)
		{
			Tree* client_tree = new Tree;
			json data = client.info();

			recursive_add(client_tree, data, home.string());
			return *client_tree;
		}

		void recursive_add(Tree* input, const json& data, std::string path, Node* parent)
		{
			Resource rsc(data);
			Node* child_node = input.add_child(rsc, parent);

			for (int32_t i = 0; i < data["_embedded"]["total"].get<int32_t>(); i++)
				if (data["_embedded"]["items"][i]["type"].get<string>() == "dir") {
					if (path[path.size() - 1] == '/')
						recursive_add(input, data, path + data["_embedded"]["items"][i]["name"].get<string>(), child_node);
					else
						recursive_add(input, data, path + "/" + data["_embedded"]["items"][i]["name"].get<string>(), child_node);
				}
		}
	}
}
