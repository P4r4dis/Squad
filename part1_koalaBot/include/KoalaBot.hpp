#ifndef     __KOALABOT__
#   define  __KOALABOT__

#include <string>
#include "Parts.hpp"
class   KoalaBot
{
    private:
        Parts::Arms     _arms;
        Parts::Legs     _legs;
        Parts::Head     _head;
        std::string     _serial;
    public:
        KoalaBot(   Parts::Arms arms = Parts::Arms(),
                    Parts::Legs legs = Parts::Legs(),
                    Parts::Head head = Parts::Head(),
                    std::string serial = "Bob-01");
        ~KoalaBot();

        std::string     getSerial(void);
        void            setParts(Parts::Arms &arms);
        Parts::Arms     getArms(void);

        void            setParts(Parts::Legs &legs);
        Parts::Legs     getLegs(void);

        void            setParts(Parts::Head &head);
        Parts::Head     getHead(void);

};


#endif //   !__KOALABOT__