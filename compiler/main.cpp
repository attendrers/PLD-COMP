#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "generated/ifccLexer.h"
#include "generated/ifccParser.h"
#include "generated/ifccBaseVisitor.h"

#include "CodeGenVisitor.h"
#include "ReadVarsVisitor.h"

using namespace antlr4;
using namespace std;

int main(int argn, const char **argv)
{
  stringstream in;
  if (argn==2)
  {
     ifstream lecture(argv[1]);
     in << lecture.rdbuf();
  }
  else
  {
      cerr << "usage: ifcc path/to/file.c" << endl ;
      exit(1);
  }
  
  ANTLRInputStream input(in.str());

  ifccLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();

  ifccParser parser(&tokens);
  tree::ParseTree* tree = parser.axiom();

  if(parser.getNumberOfSyntaxErrors() != 0)
  {
      cerr << "error: syntax error during parsing" << endl;
      exit(1);
  }

  
  ReadVarsVisitor rv;
  rv.visit(tree);
  // unordered_map<string,int> offsets = rv.getOffsets();
  // int lastVarPosition  = rv.getLastVarPosition();
  // unordered_map<string,int> types = rv.getTypes();

  vector<FunctionData*> functionDatas = rv.getFunctionDatas();

  // CodeGenVisitor v(offsets,types,lastVarPosition);
  CodeGenVisitor v (functionDatas);
  v.visit(tree);
  // catch(const out_of_range& e ){
  //   cout <<"Error compiling"<<endl;
  //   cout <<e.what()<<endl;
  // }

  for(auto & f:functionDatas){
    delete f;
  }

  return 0;
}
