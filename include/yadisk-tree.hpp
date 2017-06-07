using yadisk::ops::Resource;
using yadisk::ops::Predicate;
using yadisk::ops::Tree;
using yadisk::Client;
using std::string;
using std::map;
 
using Resources = std::vector<Resource>;
 
namespace yadisk 
{
  namespace ops 
  {
      map<string, Resources> find_tree(Client& client, Predicate pred = Hash);      
      void addCopiesInResult(Resources curEdgeCopies, map<string, Resources>& resultFind);      
  }
}
