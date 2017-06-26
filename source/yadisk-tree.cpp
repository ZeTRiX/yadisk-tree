#include "yadisk/ops/yadisk-tree.hpp"

namespace yadisk
{
	namespace ops
	{	
		Tree tree(Client& client, path home)
		{
			Tree client_tree = new Tree;
			json data = client.info();

			recursive_add(client_tree, data, "/");
			return client_tree;
		}

		void recursive_add(Tree& input, json& data, std::string path, Node* parent)
		{
			Resource rsc(data);

			Node* node = input.add_child(rsc, parent);

			for (int32_t i = 0; i < data["_embedded"]["total"].get<int32_t>(); i++)
				if (data["_embedded"]["items"][i]["type"].get<string>() == "dir") {
					if (path[path.size() - 1] == '/')
						recursive_add(input, path + data["_embedded"]["items"][i]["name"].get<string>(), node);
					else
						recursive_add(input, path + "/" + data["_embedded"]["items"][i]["name"].get<string>(), node);
				}
		}
	}
}
