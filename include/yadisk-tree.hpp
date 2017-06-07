using yadisk::Client;
using yadisk::path;
using yadisk::ops::Tree;
 
namespace yadisk 
{
	namespace ops 
	{
		Tree tree(Client& client, path home = ‘/’)
		{
			Tree resultTree;
			Resources  listAllFiles = client.list();
			
			Resources curEdges;
             			Resource curEdge = listAllFiles.first;	
    			for (int i = 0; i < listAllFiles.size(); ++i)
			{
             			                   curEdges.push_back(listAllFiles[i]);
			}
			for(int i = 0; i < curEdges.size(); ++i)
			{
          				resultFind[curEdges[i].path].insert(curEdges);
			}
            		}	
           	 }	
            	return resultFind;
}
