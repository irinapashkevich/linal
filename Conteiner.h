#ifndef CONTEINER_H_INCLUDED
#define CONTEINER_H_INCLUDED

class Container
{
public:
    // Âèðòóàëüíûå ìåòîäû, äîëæíû áûòü ðåàëèçîâàíû âàøèì êîíòåéíåðîì
    virtual void insert(int value) = 0;
    virtual bool exists(int value) = 0;
    virtual void remove(int value) = 0;

    // È ýòîò òîæå, õîòÿ ê íåìó ïîòîì åù¸ âåðí¸ìñÿ
    virtual void print() = 0;

    // Âèðòóàëüíûé äåñòðóêòîð (ïîêà ïðîñòî ïîâåðüòå, ÷òî îí íóæåí)
    virtual ~Container() { };
};

#endif // CONTEINER_H_INCLUDED
