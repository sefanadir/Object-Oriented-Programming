#ifndef MULTIPLEOBJECT_H
#define MULTIPLEOBJECT_H
using namespace std;

class MultipleObject {
public:
    inline void setBoardName(const string & fileName){ boardFile=fileName;    }
    inline void setOption(char objOption)            { objectOption=objOption;}
   
    inline string getBoardFile() const { return boardFile;    }
    inline char   getOption()    const { return objectOption; }
private:
    string boardFile;
    char objectOption;
};
#endif /* MULTIPLEOBJECT_H */
