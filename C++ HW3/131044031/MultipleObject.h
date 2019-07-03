#ifndef MULTIPLEOBJECT_H
#define MULTIPLEOBJECT_H

class MultipleObject {
public:
    void setHeight(int  objHeight){ objectHeight=objHeight;}
    void setWeight(int  objWeight){ objectWeight=objWeight;}
    void setOption(char objOption){ objectOption=objOption;}
    
    int  getHeight() const { return objectHeight; }
    int  getWeight() const { return objectWeight; }
    char getOption() const { return objectOption; }
private:
    int  objectHeight=0;
    int  objectWeight=0;
    char objectOption=0;
};
#endif /* MULTIPLEOBJECT_H */

