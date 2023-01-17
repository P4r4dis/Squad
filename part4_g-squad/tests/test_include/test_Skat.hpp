#ifndef     __TEST_SKAT__
#   define  __TEST_SKAT__

#include <string>
#include "../test_include/test_KreogCom.hpp"
#include "../test_include/test_Phaser.hpp"

void    redirect_all_stdout(void);

class   Skat
{
    private:
        std::string             _name;
        int                     _stimPaks;
        KreogCom                _kreogCom;
        Phaser                  _phaser;
    public:
        // Skat(const std::string& name = "bob", int stimPaks = 15);
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
};

#endif //   !__TEST_SKAT__