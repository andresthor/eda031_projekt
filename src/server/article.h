/* ---------------------------------------------------------------------------
** Project for the course EDA031 at Lunds University, spring 2016.
**
** article.h
**
** An article object contains an unique id, a title, an author and a text.
**
** Authors: Andres Saemundsson, Anton Friberg, Oscar Gunneson
** -------------------------------------------------------------------------*/
#ifndef ARTICLE_H
#define ARTICLE_H

/*-------------------------------------
    I N C L U D E S
-------------------------------------*/
#include <string>

/*-------------------------------------
    D E C L A R A T I O N S
-------------------------------------*/
// not recommended -> using namespace std;

/*-------------------------------------
    C L A S S   D E F
-------------------------------------*/
class Article {
public:
  Article ( unsigned int, std::string,
            std::string, std::string   );

  const unsigned int getId            ();
  const std::string getTitle          ();
  const std::string getAuthor         ();
  const std::string getText           ();

private:
  unsigned int id;
  std::string title;
  std::string author;
  std::string text;
};

#endif  // ARTICLE_H
