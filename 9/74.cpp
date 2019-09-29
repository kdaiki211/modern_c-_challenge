#include <iostream>
#include <libxml/xpath.h>

using namespace std;

xmlXPathObjectPtr evalXPath(xmlDocPtr doc, const char* xpathExpr);
void printXPathResult(xmlXPathObjectPtr xpathObj, const string attrName);

void printTitleOfMovies(xmlDocPtr doc, const unsigned th_year);
void printNameOfActors(xmlDocPtr doc);

/*
*** title of movies ***
The Matrix
Forrest Gump
*** name of actors ***
Hugo Weaving
Mykelti Williamson
*/

int main(void)
{
  xmlDocPtr doc = xmlParseFile("sample.xml");
  if (!doc) {
    cerr << "unable to parse file" << endl;
    exit(1);
  }

  cout << "*** title of movies ***" << endl;
  printTitleOfMovies(doc, 1994);

  cout << "*** name of actors ***" << endl;
  printNameOfActors(doc);

  xmlFreeDoc(doc);
  return 0;
}

void printTitleOfMovies(xmlDocPtr doc, const unsigned th_year)
{
  string xpathStr = "/movies/movie[@year>=" + to_string(th_year) + "]";
  auto xpathObj = evalXPath(doc, xpathStr.c_str());
  printXPathResult(xpathObj, "title");
}

void printNameOfActors(xmlDocPtr doc)
{
  auto xpathObj = evalXPath(doc, "/movies/movie/cast/role[last()]");
  printXPathResult(xpathObj, "star");
}

xmlXPathObjectPtr evalXPath(xmlDocPtr doc, const char* xpathExpr)
{
  xmlXPathContextPtr xpathCtx = xmlXPathNewContext(doc);
  if (!xpathCtx) {
    cerr << "unable to create new context"  << endl;
    return NULL;
  }

  xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)xpathExpr, xpathCtx);
  if (!xpathObj) {
    cerr << "unable to evaluate xpath expression" << endl;
    xmlXPathFreeContext(xpathCtx);
    return NULL;
  }

  return xpathObj;
}

void printXPathResult(xmlXPathObjectPtr xpathObj, const string attrName)
{
  if (xpathObj == NULL) {
    cerr << "xpath is null" << endl;
  }
  xmlNodeSetPtr nodes = xpathObj->nodesetval;
  if (!nodes) return;
  size_t size = nodes->nodeNr;
  for (int i = 0; i < size; i++) {
    const xmlNodePtr node =  nodes->nodeTab[i];
    if (node->type != XML_ELEMENT_NODE) continue;
    xmlChar *title = xmlGetProp(node, (xmlChar*)attrName.c_str());
    if (title) {
      cout << title << endl;
    } else {
      cerr << "attribute \"" + attrName  + "\" not found" << endl;
    }
  }
}

