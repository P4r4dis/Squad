#ifndef     __SKAT__
#   define  __SKAT__

#include <string>
#include "KreogCom.hpp"
#include "Phaser.hpp"
class   Skat
{
    private:
        std::string             _name;
        int                     _stimPaks;
        KreogCom                _kreogCom;
        Phaser                  _phaser;
    public:
        Skat(const std::string& name = "bob",
            int stimPaks = 15, int serial = 0,
            int x = 0, int y = 0,
            Phaser::AmmoType type = Phaser::REGULAR);
        ~Skat();

        const std::string&      getName(void);
        int                     getStimPaks(void);

        int&                    stimPaks(void);
        const std::string       &name(void);
        void                    shareStimPaks(int number, int &stock);
        void                    addStimPaks(unsigned int number);
        void                    useStimPaks(void);
        void                    status(void) const;

        KreogCom                getKreogCom(void);
        Phaser                  getPhaser(void);

        void                    fire(void);
        void                    locate(void) const;
        void                    reload(void);
        KreogCom&               com(void);

};


#endif //   !__SKAT__