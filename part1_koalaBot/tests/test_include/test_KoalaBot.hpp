#ifndef     __TEST_KOALABOT__
#   define  __TEST_KOALABOT__

#include <string>


void    redirect_all_stdout(void);

#include "test_Parts.hpp"
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
        void            swapParts(Parts::Arms &arms);

        void            setParts(Parts::Legs &legs);
        Parts::Legs     getLegs(void);
        void            swapParts(Parts::Legs &legs);


        void            setParts(Parts::Head &head);
        Parts::Head     getHead(void);
        void            swapParts(Parts::Head &head);

        void            informations(void);

};

#endif //   !__TEST_KOALABOT__